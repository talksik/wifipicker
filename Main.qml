import QtQuick
import QtQuick.Controls

Rectangle {
    id: window
    width: 640
    height: 480
    visible: true

    required property var networksModel

    signal scanNetworks()

    Button {
        id: scanbutton
        text: "Scan for networks"
        onClicked: window.scanNetworks()
    }

    ListView {
        id: listview
        objectName: "listview"
        model: parent.networksModel
        delegate: Rectangle {
            required property string name

            Text {
                text: parent.name
            }
        }
    }
}
