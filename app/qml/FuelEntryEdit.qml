import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import "components" as Components

ScrollView {
    id: root
    horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff

    property alias fuelQuantity: fuelQuantityInput.value
    property alias totalPrice: totalPriceInput.value
    property alias perUnitPrice: perUnitPriceInput.value
    property alias date: dateDialog.selectedDate
    property int currentCarMileage

    readonly property int fuelType: fuelTypeInput.model.get(fuelQuantityInput.currentIndex).value;
    readonly property int currencyType: currencySelectorInput.model.get(currencySelectorInput.currentIndex).value
    readonly property int liquidUnitType: liquidUnitInput.model.get(liquidUnitInput.currentIndex).value
    readonly property int distanceUnitType: distanceTypeInput.model.get(distanceTypeInput.currentIndex).value

    function setFuelType(type) {
        for (var i = 0; i < fuelTypeInput.model.count; ++i) {
            if (fuelTypeInput.model.get(i).value === type) {
                fuelTypeInput.currentIndex = i;
                break;
            }
        }
    }

    function setCurrencyType(type) {
        for (var i = 0; i < currencySelectorInput.model.count; ++i) {
            if (currencySelectorInput.model.get(i).value === type) {
                currencySelectorInput.currentIndex = i;
                break;
            }
        }
    }

    function setLiquidUnitType(type) {
        for (var i = 0; i < liquidUnitInput.model.count; ++i) {
            if (liquidUnitInput.model.get(i).value === type) {
                liquidUnitInput.currentIndex = i;
                break;
            }
        }
    }

    function setDistanceUnitType(type) {
        for (var i = 0; i < distanceTypeInput.model.count; ++i) {
            if (distanceTypeInput.model.get(i).value === type) {
                distanceTypeInput.currentIndex = i;
                break;
            }
        }
    }

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
                    columns: 3

                    Label {
                        text: qsTr("Date:")
                        Layout.fillWidth: true
                    }
                    Button {
                        Layout.fillWidth: true
                        text: root.date.toLocaleDateString()
                        onClicked: dateDialog.open()
                    }
                    Item {
                        // spacer
                        Layout.fillWidth: true
                    }

                    Label {
                        text: qsTr("Mileage:")
                    }
                    TextField {
                        inputMethodHints: Qt.ImhDigitsOnly
                        validator: IntValidator { bottom: currentCarMileage; top: currentCarMileage + 2000 }
                        Layout.fillWidth: true
                    }
                    Components.DistanceUnitComboxBox {
                        id: distanceTypeInput
                        Layout.fillWidth: true
                    }


                    Label {
                        text: qsTr("Type:")
                        Layout.fillWidth: true
                    }
                    Components.FuelTypesComboBox {
                        id: fuelTypeInput
                        Layout.fillWidth: true
                    }
                    Item {
                        // spacer
                        Layout.fillWidth: true
                    }

                    Label {
                        text: qsTr("Quantity:")
                        Layout.fillWidth: true
                    }
                    SpinBox {
                        id: fuelQuantityInput
                        decimals: 2
                        maximumValue: 999.99
                        minimumValue: 0.0
                        Layout.fillWidth: true
                    }
                    Components.LiquidUnitComboxBox {
                        id: liquidUnitInput
                        Layout.fillWidth: true
                    }

                    Label {
                        text: qsTr("Total Price:")
                        Layout.fillWidth: true
                    }
                    SpinBox {
                        id: totalPriceInput
                        decimals: 2
                        maximumValue: 999.99
                        minimumValue: 0.0
                        Layout.fillWidth: true
                        onEditingFinished: {
                            perUnitPriceInput.value = totalPriceInput.value / fuelQuantityInput.value
                        }
                    }
                    Components.CurrencyUnitComboxBox {
                        id: currencySelectorInput
                        Layout.rowSpan: 2
                    }

                    Label {
                        text: qsTr("Per Unit Price:")
                        Layout.fillWidth: true
                    }
                    SpinBox {
                        id: perUnitPriceInput
                        decimals: 2
                        maximumValue: 999.99
                        minimumValue: 0.0
                        Layout.fillWidth: true
                        Layout.columnSpan: 1
                        onEditingFinished: {
                            totalPriceInput.value = fuelQuantityInput.value * perUnitPriceInput.value
                        }
                    }
                }
            }
        }

        Components.DateDialog {
            id: dateDialog
        }
    }
}
