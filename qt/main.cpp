#include <QApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include <QVector.h>
#include "../core/MagnasTareas.hpp"

#ifdef WIN32
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
