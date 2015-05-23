import QtQuick 2.4
import QtQml 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import "components" as Components
import CarServiceLog 1.0

ScrollView {
    id: root
    horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
    property alias fuelQuantity: fuelQuantityText.value
    property alias totalPrice: totalPriceText.value
    property alias perUnitPrice: perUnitPriceText.value
    property alias mileage: mileageText.value;
    property date selectedDate: new Date()

    property int fuelType: App.SP95;
    property int currencyType: App.Euro
    property int liquidUnitType: App.Liter
    property int distanceUnitType: App.Km

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
                title: "Fuel"
                Layout.fillWidth: true
                GridLayout {
                    anchors.fill: parent
                    columns: 2


                    Label {
                        text: qsTr("Date:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: dateText
                        text: root.selectedDate.toLocaleDateString()
                    }


                    Label {
                        text: qsTr("Mileage:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: mileageText
                        property real value: 0
                        readonly property string unit: (distanceUnitType === App.Km) ? "Km" : "Miles"
                        text: Number(value).toLocaleString() + " " + unit
                    }


                    Label {
                        text: qsTr("Type:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: fuelTypeText
                        readonly property string unit: {
                            switch (fuelType) {
                            case App.SP95:
                                return "SP95";
                            case App.SP98:
                                return "SP98";
                            case App.SP95E10:
                                return "SP95E10";
                            case App.U87:
                                return "U87";
                            case App.U89:
                                return "U89";
                            case App.U91:
                                return "U91";
                            case App.U93:
                                return "U93";
                            case App.Diesel:
                                return "Diesel";
                            default:
                                return "Unknown"
                            }
                        }
                        text: unit
                    }

                    Label {
                        text: qsTr("Quantity:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: fuelQuantityText
                        property real value: 0
                        readonly property string unit: (liquidUnitType === App.Liter) ? "Liters" : "Gals"
                        text: Number(value).toLocaleString() + " " + unit
                    }

                    Label {
                        text: qsTr("Total Price:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: totalPriceText
                        property real value: 0
                        readonly property string unit: (currencyType === App.Euro) ? "€" : (currencyType === App.Dollar) ? "$" : "£"
                        text: Number(value).toLocaleString() + " " + unit
                    }

                    Label {
                        text: qsTr("Per Unit Price:")
                        Layout.fillWidth: true
                    }
                    Text {
                        id: perUnitPriceText
                        property real value: 0
                        readonly property string unit: (currencyType === App.Euro) ? "€" : (currencyType === App.Dollar) ? "$" : "£"
                        text: Number(value).toLocaleString() + " " + unit
                    }
                }
            }
        }
    }
}
