#include "vehicle.h"

Vehicle::Vehicle()
{
}

App::VehicleType Vehicle::type() const
{
    return m_type;
}

void Vehicle::setType(const App::VehicleType &type)
{
    m_type = type;
}
QString Vehicle::name() const
{
    return m_name;
}

void Vehicle::setName(const QString &name)
{
    m_name = name;
}
int Vehicle::id() const
{
    return m_id;
}

void Vehicle::setId(int value)
{
    m_id = value;
}







