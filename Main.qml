import QtQuick
import QtQuick.Controls

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("WIFI picker")

    signal scanNetworks()

    Button {
        id: scanButton
        text: "Scan for networks"
        onClicked: window.scanNetworks()
    }
}
