#include <QApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <qvector.h>
#include "../core/MagnasTareas.hpp"

extern "C"
{
#ifdef WIN32
#include <Rpc.h>
#else
#include <uuid/uuid.h>
#endif
}

std::string newUUID()
{
#ifdef WIN32
    UUID uuid;
    UuidCreate ( &uuid );

    unsigned char * str;
    UuidToStringA ( &uuid, &str );

    std::string s( ( char* ) str );

    RpcStringFreeA ( &str );
#else
    uuid_t uuid;
    uuid_generate_random ( uuid );
    char s[37];
    uuid_unparse ( uuid, s );
#endif
    return s;
}


#if defined(WIN32) && !defined(_DEBUG)
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#endif

QObject* window;

class MagnasTareasQt : public QObject, MagnasTareas
 {
     Q_OBJECT
 public:
	 MagnasTareasQt() : QObject(), MagnasTareas(){};
 public slots:
        void cppSlot(const QVariant &v) {
            QQuickItem *itemx = qobject_cast<QQuickItem*>(v.value<QObject*>());
            qDebug() << "Item dimensions:" << itemx->width() << itemx->height();
     }
		void selectTask(const int index) {
			QQuickItem* taskList=window->findChild<QQuickItem*>("tasks");
	}
	QString readTask(const QString& uuid){
			qDebug() << "UUID: " << uuid;
			return "Contenido de la tarea, implementar un Core Universal que sea posible usar con muchos drivers de APIs REST"; 
	}
	
	QString getVersion(void)
	{
		return QString::fromStdString(this->GetVersion());
	}
	
	void getCategories(void)
	{
		std::vector<Category> categories=this->GetCategories();
		QVector<Category> qvector=QVector<Category>::fromStdVector(categories);
		QList<Category> qlist=QList<Category>::fromVector(qvector);

		QVariant returnedValue;

		for( int i=0; i<qlist.count(); ++i )
		{
			QVariant name=QString::fromStdString(qlist[i].name);
			QVariant uuid=QString::fromStdString(qlist[i].uuid);
			QMetaObject::invokeMethod(window, "addVisualCategory",Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, name),Q_ARG(QVariant,uuid));
		}
	}
	
	QVariantList getCategoriesOnly(void){
		QVariantList list;
		std::vector<Category> categories=this->GetCategories();
		QVector<Category> qvector=QVector<Category>::fromStdVector(categories);
		QList<Category> qlist=QList<Category>::fromVector(qvector);
		for( int i=0; i<qlist.count(); ++i )
		{
			QVariantMap map;
			map.insert("name",QString::fromStdString(qlist[i].name));
			map.insert("uuid",QString::fromStdString(qlist[i].uuid));
			list << map;
		}
		return list;
	}
	
	void getTasksFor(const QString& uuid) {
		std::vector<Category> categories=this->GetCategories();

		std::vector<Category>::iterator it=categories.begin();
		while(it != categories.end())
		{
			if(QString::fromStdString(it->uuid)==uuid)
			{
				//READ AND SEND TASKS
				std::vector<Task> tasks=it->tasks;
				std::vector<Task>::iterator itr=tasks.begin();
				while(itr != tasks.end())
				{
					QVariant name=QString::fromStdString(itr->name);
					QVariant description=QString::fromStdString(itr->description);
					QVariant completed=itr->completed;
					QVariant uuid=QString::fromStdString(itr->uuid);
					QVariant rtn;
					QMetaObject::invokeMethod(window,"addVisualTask",Q_RETURN_ARG(QVariant, rtn),Q_ARG(QVariant,name),Q_ARG(QVariant,description),Q_ARG(QVariant,uuid),Q_ARG(QVariant,completed));
					itr++;
				}
			}
			it++;
		}
	}
	void addTask(const QString& title, const QString& description, const QString& category, const QString& categoryName){
		this->AddTask(title.toStdString(),description.toStdString(),category.toStdString(),categoryName.toStdString());
	}
		
 };

#include "main.moc"

int main(int argc, char *argv[]) {
     QApplication app(argc, argv);
     
     QQmlApplicationEngine engine;
     engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
     window = engine.rootObjects().first();
     QQuickItem* item = window->findChild<QQuickItem*>("MainItem");
	 engine.rootContext()->setContextProperty("MagnasTareas",new MagnasTareasQt);
	 QMetaObject::invokeMethod(window, "refresh");

     /*MagnasTareasQt myClass;
     QObject::connect(item, SIGNAL(selectTask(int)),
                      &myClass, SLOT(selectTask(int)));*/

     return app.exec();
 }
