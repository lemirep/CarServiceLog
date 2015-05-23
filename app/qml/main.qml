import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

ApplicationWindow {
    id: appWindow
    visible: true
    title: qsTr("Car Service Logger")

    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem {
                text: "E&xit"
                onTriggered: Qt.quit()
            }
        }
    }

    TabView {
        id: tabView
        anchors.fill: parent
        Layout.minimumWidth: 360
        Layout.minimumHeight: 360
        Layout.preferredWidth: Screen.width
        Layout.preferredHeight: Screen.height


        Tab {
            title: "Fuel Entry Details"
            FuelEntryDetail {
                anchors.fill: parent
            }
        }
        Tab {
            title: "Delegate"
            ListView {
                anchors.fill: parent
                delegate: FuelEntryDelegate {
                    width: ListView.view.width
                    height: ListView.view.height * 0.25
                }
            }
        }
        Tab {
            title: "FuelEntry Input"
            FuelEntryEdit {
                anchors.fill: parent
            }
        }
        Tab {
            title: "Car Detail"
            VehicleEntryDetail {
                anchors.fill: parent
            }
        }
    }

}

