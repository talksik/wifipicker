import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: "WIFI Picker"

    signal scanNetworks()

        Button {
            id: scanbutton
            text: "Scan for networks"
            onClicked: window.scanNetworks()
        }

        ListView {
            id: listview
            model: networksModel
            anchors.fill: parent
            // model: ListModel {
            //             ListElement { name: "Item 1"; value: 10 }
            //             ListElement { name: "Item 2"; value: 20 }
            //             ListElement { name: "Item 3"; value: 30 }
            //         }

            delegate: Item {
                height: 20
                required property string name

                Text {
                text: parent.name
                }
            }
        }
}
