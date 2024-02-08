#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <NetworkScanner.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    NetworksModel model;
    model.scan();
    qDebug() << "now has " << model.rowCount() << Qt::endl;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/wifipicker/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("networksModel", &model);
    engine.load(url);

    QObject *rootObject = engine.rootObjects().first();
    if (!rootObject)
    {
        qDebug() << "Problem in finding root object" << Qt::endl;
        return -1;
    }

    QObject::connect(rootObject, SIGNAL(scanNetworks()), &model, SLOT(scan()));

    return app.exec();
}
