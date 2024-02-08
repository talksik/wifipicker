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

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setInitialProperties({{"networksModel", QVariant::fromValue(&model)}});
    view.setSource(QUrl("qrc:/wifipicker/Main.qml"));
    view.show();

    if (!view.rootObject())
    {
        qDebug() << "No root object found" << Qt::endl;
        return -1;
    }

    QObject *rootObject = view.rootObject();
    QObject::connect(rootObject, SIGNAL(scanNetworks()), &model, SLOT(scan()));


    return app.exec();
}
