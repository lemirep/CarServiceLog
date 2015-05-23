import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

Dialog {
    id: dialog
    title: qsTr("Date Selector")
    standardButtons: StandardButton.Save|StandardButton.Cancel
    property alias selectedDate: calendar.selectedDate

    contentItem: Calendar {
        id: calendar
        onClicked: dialog.click(StandardButton.Save)
    }
}

