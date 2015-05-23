TEMPLATE = app

QT += quick

TARGET = CarServiceLog

include(../src/src.pri)
  

SOURCES += \
    main.cpp

RESOURCES += \
    app.qrc

DISTFILES += \
    qml/components/FuelTypesComboBox.qml \
    qml/components/CurrencyUnitComboxBox.qml
