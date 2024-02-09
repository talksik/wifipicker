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
        id: layout
        property bool isLoading: false

        Button {
            id: scanbutton
            text: "Scan for networks"
            onClicked: {
                layout.isLoading = true;
                window.scanNetworks();
                layout.isLoading = false;
            }
        }

        Text {
            text: "Loading"
            visible: layout.isLoading
        }

        ListView {
            id: listview
            visible: !layout.isLoading
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
