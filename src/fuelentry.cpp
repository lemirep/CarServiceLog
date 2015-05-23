#include "fuelentry.h"

FuelEntry::FuelEntry()
{
}

FuelEntry::FuelEntry(int actualMileage, float quantity, float totalPrice)
    : m_actualMileage(actualMileage)
    , m_quantity(quantity)
    , m_totalPrice(totalPrice)
{
}

App::FuelType FuelEntry::fuelType() const
{
    return m_fuelType;
}

void FuelEntry::setFuelType(const App::FuelType &fuelType)
{
    m_fuelType = fuelType;
}
App::CurrencyType FuelEntry::currencyType() const
{
    return m_currencyType;
}

void FuelEntry::setCurrencyType(const App::CurrencyType &currencyType)
{
    m_currencyType = currencyType;
}

int FuelEntry::actualMileage() const
{
    return m_actualMileage;
}

void FuelEntry::setActualMileage(int actualMileage)
{
    m_actualMileage = actualMileage;
}

float FuelEntry::quantity() const
{
    return m_quantity;
}

void FuelEntry::setQuantity(float quantity)
{
    m_quantity = quantity;
}

QDateTime FuelEntry::date() const
{
    return m_date;
}

void FuelEntry::setDate(const QDateTime &date)
{
    m_date = date;
}

float FuelEntry::totalPrice() const
{
    return m_totalPrice;
}

void FuelEntry::setTotalPrice(float totalPrice)
{
    m_totalPrice = totalPrice;
}

float FuelEntry::perUnitPrice() const
{
    return m_perUnitPrice;
}

void FuelEntry::setPerUnitPrice(float perUnitPrice)
{
    m_perUnitPrice = perUnitPrice;
}
int FuelEntry::vehicleId() const
{
    return m_vehicleId;
}

void FuelEntry::setVehicleId(int vehicleId)
{
    m_vehicleId = vehicleId;
}
int FuelEntry::id() const
{
    return m_id;
}

void FuelEntry::setId(int id)
{
    m_id = id;
}











