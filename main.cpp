#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <NetworkScanner.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    //view.setInitialProperties({{"model", QVariant::fromValue(&model)}});
    view.setSource(QUrl("qrc:/qt/qml/abstractitemmodel/view.qml"));
    view.show();

    QQuickItem *rootObject = view.rootObject();
    // QQuickWindow *window = qobject_cast<QQuickWindow*>(rootObject);
    NetworkScanner networkScanner;
    QObject::connect(rootObject, SIGNAL(scanNetworks()), &networkScanner, SLOT(scan()));

    return app.exec();
}
