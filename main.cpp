#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <NetworkScanner.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    NetworksModel model;
    qDebug() << "now has " << model.rowCount() << Qt::endl;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/wifipicker/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);


    QObject *rootObject = engine.rootObjects().first();
    if (!rootObject)
    {
        qDebug() << "Problem in finding root object" << Qt::endl;
        return -1;
    }

    engine.setInitialProperties({{"model", QVariant::fromValue(&model)}});
    rootObject->setProperty("model", QVariant::fromValue(&model));

    QObject::connect(rootObject, SIGNAL(scanNetworks()), &model, SLOT(scan()));


    return app.exec();
}
