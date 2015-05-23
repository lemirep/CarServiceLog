import QtQuick 2.4
import QtQml 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import "components" as Components
import CarServiceLog 1.0

ScrollView {
    id: root
    horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff

    property int preferedFuelType: App.SP95;
    property int preferedCurrencyType: App.Euro
    property int preferedLiquidUnitType: App.Liter
    property int preferedDistanceUnitType: App.Km

    property alias name: nameText.text
    property alias brand: brandText.text
    property alias currentMileage: mileageText.value
    property alias vehicleType: vehicleTypeText.unit


    Item {
        id: content

        width: root.viewport.width
        height: root.viewport.height

        ColumnLayout {
            id: column

            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: column.spacing
            }

            GroupBox {
                title: "Vehicle"
                Layout.fillWidth: true
                GridLayout {
                    anchors.fill: parent
                    columns: 2



                    Label {
                        text: qsTr("Name:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: nameText
                    }

                    Label {
                        text: qsTr("Type:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: vehicleTypeText
                        property real value: 0
                        readonly property string unit: {
                            switch (vehicleType) {
                            case App.Car:
                                return "Car";
                            case App.Bike:
                                return "Bike";
                            case App.Truck:
                                return "Truck";
                            default:
                                return "Unknown";
                            }
                        }
                        text: unit
                    }

                    Label {
                        text: qsTr("Brand:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: brandText
                    }

                    Label {
                        text: qsTr("Actual Mileage:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: mileageText
                        property real value: 0
                        readonly property string unit: (preferedDistanceUnitType === App.Km) ? "Km" : "Miles"
                        text: Number(value).toLocaleString() + " " + unit
                    }

                }
            }
        }
    }
}
