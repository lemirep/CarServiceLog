#ifndef VEHICLE_H
#define VEHICLE_H

#include "app.h"

class Vehicle
{
public:
    Vehicle();
    Vehicle(const QString &name);

    App::VehicleType type() const;
    void setType(const App::VehicleType &type);

    QString name() const;
    void setName(const QString &name);

    int id() const;
    void setId(int value);

private:
    App::VehicleType m_type = App::Car;
    QString m_name;
    int m_id = -1;
    // Year
    // Brand
    // FuelType
    // Favorite Currency
    // Favority Distance
    // Actual Mileage
};

#endif // VEHICLE_H
