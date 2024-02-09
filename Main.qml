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
    signal connectToNetwork(networkName: string, password: string)

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
            width: 100
            visible: layout.isLoading
        }

        TextInput {
            id: passwordInput
            text: "enter password"
            selectionColor: "blue"
            width: 500
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
                width: 400

                property bool hovered: false
                required property string name
                property bool isConnected: false

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        console.log("on hover")
                        listItem.hovered = true
                    }
                    onExited: listItem.hovered = false
                    onClicked: console.log("Clicked!")

                    Rectangle {
                        anchors.fill: parent
                        color: listItem.hovered ? "blue" : "transparent"

                        transitions: Transition {
                            ColorAnimation { target: parent; property: "color"; duration: 200 }
                        }

                        RowLayout {
                            anchors.fill: parent

                            Text {
                                Layout.fillWidth: true
                                text: listItem.name
                                color: listItem.hovered ? "white" : "black"
                            }
                            Button {
                                visible: !listItem.isConnected && listItem.hovered
                                text: "Connect"
                                onClicked: {
                                    console.log("connecting to " + listItem.name)
                                    window.connectToNetwork(listItem.name, passwordInput.text)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
