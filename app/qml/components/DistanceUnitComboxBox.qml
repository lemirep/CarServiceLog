import QtQuick 2.4
import QtQuick.Controls 1.2
import CarServiceLog 1.0

ComboBox {
    editable: false
    currentIndex: 0
    model: ListModel {
        ListElement { text: "Km"; value: App.Km }
        ListElement { text: "Miles"; value: App.Mile }
    }
}

