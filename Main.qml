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

    ColumnLayout {
        Button {
            id: scanbutton
            text: "Scan for networks"
            onClicked: window.scanNetworks()
        }

        ListView {
            id: listview
            model: networksModel
            width: 100
            height: 1000

            delegate: Item {
                height: 20
                required property string name

                Text {
                    text: parent.name
                }
            }
        }
    }
}
