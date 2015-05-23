import QtQuick 2.4
import QtQuick.Controls 1.2
import CarServiceLog 1.0

ComboBox {
    editable: false
    currentIndex: 0
    model: ListModel {
        ListElement { text: "SP95"; value: App.SP95 }
        ListElement { text: "SP98"; value: App.SP98 }
        ListElement { text: "SP95E10"; value: App.SP95E10 }
        ListElement { text: "U87"; value: App.U87 }
        ListElement { text: "U89"; value: App.U89 }
        ListElement { text: "U91"; value: App.U91 }
        ListElement { text: "U93"; value: App.U93 }
        ListElement { text: "Diesel"; value: App.Petrol }
    }
}

