#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "VlcPlayerEventHandler.h"

#include <3rdParty/qmlVlc/QmlVlc.h>

int main(int argc, char *argv[])
{
	RegisterQmlVlc();

	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;

	VlcPlayerEventHandler eventHandler;
	engine.rootContext()->setContextProperty("vlcPlayerEventHandler", &eventHandler);

	engine.load(QUrl(QLatin1String("qrc:/main.qml")));

	return app.exec();
}
