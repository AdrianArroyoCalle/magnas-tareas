#include <QApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickItem>
#include <QQmlContext>
#include "../core/MagnasTareas.hpp"

#ifdef WIN32
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#endif

QQuickItem* item;

class MagnasTareasQt : public QObject, MagnasTareas
 {
     Q_OBJECT
 public slots:
        void cppSlot(const QVariant &v) {
            QQuickItem *itemx = qobject_cast<QQuickItem*>(v.value<QObject*>());
            qDebug() << "Item dimensions:" << itemx->width() << itemx->height();
     }
		void selectTask(const int index) {
			QQuickItem* taskList=item->findChild<QQuickItem*>("tasks");
	}
	QString readTask(const QString& uuid){
			qDebug() << "UUID: " << uuid;
			return "Contenido de la tarea, implementar un Core Universal que sea posible usar con muchos drivers de APIs REST"; 
	}
	QString getVersion(void)
	{
		return QString::fromStdString(this->GetVersion());
	}
		
 };

#include "main.moc"

int main(int argc, char *argv[]) {
     QApplication app(argc, argv);
     
     QQmlApplicationEngine engine;
     engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
     QObject* window = engine.rootObjects().first();
     item = window->findChild<QQuickItem*>("MainItem");
	 engine.rootContext()->setContextProperty("MagnasTareas",new MagnasTareasQt);

     MagnasTareasQt myClass;
     QObject::connect(item, SIGNAL(selectTask(int)),
                      &myClass, SLOT(selectTask(int)));

     return app.exec();
 }
