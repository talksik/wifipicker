#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <networksmodel.h>
#include <QQmlContext>
#include <QString>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    NetworksModel model;

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
    QObject::connect(rootObject, SIGNAL(connectToNetwork(QString, QString)), &model, SLOT(connectToNetwork(QString, QString)));

    return app.exec();
}
