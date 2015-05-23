#ifndef APP_H
#define APP_H

#include <QObject>

class VehiculeModel;
class FuelEntryModel;

class App : public QObject
{
    Q_OBJECT
    Q_ENUMS(VehicleType)
    Q_ENUMS(FuelType)
    Q_ENUMS(LiquidUnits)
    Q_ENUMS(DistanceUnits)
    Q_ENUMS(CurrencyType)
    // Could use Q_ENUM when switching to 5.5

public:
    explicit App(QObject *parent = nullptr);

    enum VehicleType {
        Car = 0,
        Bike,
        Entry
    };

    enum FuelType {
        Gas = 0,
        SP95,
        SP98,
        SP95E10,
        U87,
        U89,
        U91,
        U93,
        Petrol,
        Diesel,
    };

    enum LiquidUnits {
        Liter = 1,
        Gallon
    };

    enum DistanceUnits {
        Km = 0,
        Mile
    };

    enum CurrencyType {
        Euro = 0,
        Dollar,
        GBP
    };

private:
    // Vehicule Model
    // Fuel Entry Model
    // Fuel Entry Proxy Model

    VehiculeModel *m_vehiculeModel;
    FuelEntryModel *m_fuelEntryModel;
};

#endif // APP_H
