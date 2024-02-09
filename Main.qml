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
                id: listItem
                height: 20
                width: 100

                property bool hovered: false
                required property string name

                Rectangle {
                    anchors.fill: parent
                    color: hovered ? "blue" : "transparent"

                    Text {
                        text: listItem.name
                        color: listItem.hovered ? "white" : "black"
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: listItem.hovered = true
                        onExited: listItem.hovered = false
                        onClicked: console.log("Clicked!")
                    }

                    transitions: Transition {
                        ColorAnimation { target: parent; property: "color"; duration: 200 }
                    }
                }
            }
        }
    }
}
