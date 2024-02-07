#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <NetworkScanner.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

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
    // QQuickWindow *window = qobject_cast<QQuickWindow*>(rootObject);
    NetworkScanner networkScanner;
    QObject::connect(rootObject, SIGNAL(scanNetworks()), &networkScanner, SLOT(scan()));

    return app.exec();
}
