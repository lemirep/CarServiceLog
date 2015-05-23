#ifndef FUELENTRY_H
#define FUELENTRY_H

#include "app.h"
#include <QDateTime>

class FuelEntry
{
public:
    FuelEntry();
    FuelEntry(int actualMileage, float quantity, float totalPrice);

    App::FuelType fuelType() const;
    void setFuelType(const App::FuelType &fuelType);

    App::CurrencyType currencyType() const;
    void setCurrencyType(const App::CurrencyType &currencyType);

    int actualMileage() const;
    void setActualMileage(int actualMileage);

    float quantity() const;
    void setQuantity(float quantity);

    QDateTime date() const;
    void setDate(const QDateTime &date);

    float totalPrice() const;
    void setTotalPrice(float totalPrice);

    float perUnitPrice() const;
    void setPerUnitPrice(float perUnitPrice);

    int vehicleId() const;
    void setVehicleId(int vehicleId);

    int id() const;
    void setId(int id);

private:
    int m_actualMileage = -1;
    float m_quantity = 0.0f;
    float m_totalPrice = 0.0f;
    float m_perUnitPrice = 0.0f;
    QDateTime m_date = QDateTime::currentDateTime();

    int m_id = -1;
    int m_vehicleId = -1;
    App::FuelType m_fuelType = App::SP95;
    App::CurrencyType m_currencyType = App::Euro;
};

#endif // FUELENTRY_H
