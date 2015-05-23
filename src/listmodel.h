#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QHash>
#include <QAbstractListModel>

#include "fuelentry.h"
#include "vehicle.h"

template <class T>
class ListModel : public QAbstractListModel
{
public:

    void setEditable(bool editable)
    {
        if (!m_isEditable != editable) {
            m_isEditable = editable;
        }
    }

    bool isEditable() const
    {
        return m_isEditable;
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_FINAL
    {
        Q_UNUSED(parent);
        return int(m_items.size());
    }

    bool insertRows(const std::vector<T> &data)
    {
        if (data.size() == 0)
            return false;
        beginInsertRows(QModelIndex(), m_items.size(), m_items.size() + data.size() - 1);
        m_items.insert(m_items.end(), data.begin(), data.end());
        endInsertRows();
        return true;
    }

    bool insertRow(const T &data)
    {
        beginInsertRows(QModelIndex(), m_items.size(), m_items.size());
        m_items.push_back(data);
        endInsertRows();
        return true;
    }

    bool removeRows(int row, int count = 0)
    {
        beginRemoveRows(QModelIndex(), row, row + count);
        m_items.erase(m_items.begin() + row, m_items.begin() + row + count + 1);
        endRemoveRows();
        return true;
    }

    Qt::ItemFlags flags(const QModelIndex &) const
    {
        Qt::ItemFlags f;

        if (m_isEditable)
            f = Qt::ItemIsEditable;

        return f;
    }

protected:
    std::vector<T> m_items;
    bool m_isEditable = true;
};

class FuelEntryModel : public ListModel<FuelEntry>
{
    Q_OBJECT
    Q_ENUMS(FuelEntryRoles)
public:

    enum FuelEntryRoles {
        FuelType = Qt::DisplayRole + 1,
        CurrencyType,
        ActualMileage,
        Quantity,
        TotalPrice,
        PerUnitPrice,
        Date,
        VehiculeId,
        Id
    };

    QHash<int, QByteArray> roleNames() const Q_DECL_FINAL
    {
        QHash<int, QByteArray> roles;

        roles.insert(FuelEntryRoles::FuelType, QByteArrayLiteral("fuelType"));
        roles.insert(FuelEntryRoles::CurrencyType, QByteArrayLiteral("currentyType"));
        roles.insert(FuelEntryRoles::ActualMileage, QByteArrayLiteral("actualMileage"));
        roles.insert(FuelEntryRoles::Quantity, QByteArrayLiteral("quantity"));
        roles.insert(FuelEntryRoles::TotalPrice, QByteArrayLiteral("totalPrice"));
        roles.insert(FuelEntryRoles::PerUnitPrice, QByteArrayLiteral("perUnitPrice"));
        roles.insert(FuelEntryRoles::Date, QByteArrayLiteral("date"));
        roles.insert(FuelEntryRoles::VehiculeId, QByteArrayLiteral("vehiculeId"));
        roles.insert(FuelEntryRoles::Id, QByteArrayLiteral("id"));

        return roles;
    }

    QVariant data(const QModelIndex &index, int role) const Q_DECL_FINAL
    {
        if (index.row() >= 0 && size_t(index.row()) < m_items.size()) {
            const FuelEntry &entry = m_items.at(index.row());
            switch (role) {
            case FuelEntryRoles::FuelType:
                return entry.fuelType();
            case FuelEntryRoles::CurrencyType:
                return entry.currencyType();
            case FuelEntryRoles::ActualMileage:
                return entry.actualMileage();
            case FuelEntryRoles::Quantity:
                return entry.quantity();
            case FuelEntryRoles::TotalPrice:
                return entry.totalPrice();
            case FuelEntryRoles::PerUnitPrice:
                return entry.perUnitPrice();
            case FuelEntryRoles::Date:
                return entry.date();
            case FuelEntryRoles::Id:
                return entry.id();
            case FuelEntryRoles::VehiculeId:
                return entry.vehicleId();
            }
        }
        return QVariant();
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_FINAL
    {
        if (index.row() >= 0 && size_t(index.row()) < m_items.size()) {
            FuelEntry &entry = m_items[index.row()];
            switch (role) {
            case FuelEntryRoles::FuelType:
                entry.setFuelType(static_cast<App::FuelType>(value.toInt()));
                return true;
            case FuelEntryRoles::CurrencyType:
                entry.setCurrencyType(static_cast<App::CurrencyType>(value.toInt()));
                return true;
            case FuelEntryRoles::ActualMileage:
                entry.setActualMileage(value.toInt());
                return true;
            case FuelEntryRoles::Quantity:
                entry.setQuantity(value.toFloat());
                return true;
            case FuelEntryRoles::TotalPrice:
                entry.setQuantity(value.toFloat());
                return true;
            case FuelEntryRoles::PerUnitPrice:
                entry.setPerUnitPrice(value.toFloat());
                return true;
            case FuelEntryRoles::Date:
                entry.setDate(value.toDateTime());
                return true;
            case FuelEntryRoles::Id:
                entry.setId(value.toInt());
                return true;
            case FuelEntryRoles::VehiculeId:
                entry.setVehicleId(value.toInt());
                return true;
            }
        }
        return false;
    }
};


class VehiculeModel : public ListModel<Vehicle>
{
    Q_OBJECT
    Q_ENUMS(VehicleRoles)
public:

    enum VehicleRoles {
        VehiculeType = Qt::DisplayRole + 1,
        Name,
        Id
    };

    QHash<int, QByteArray> roleNames() const Q_DECL_FINAL
    {
        QHash<int, QByteArray> roles;

        roles.insert(VehicleRoles::VehiculeType, QByteArrayLiteral("type"));
        roles.insert(VehicleRoles::Name, QByteArrayLiteral("name"));
        roles.insert(VehicleRoles::Id, QByteArrayLiteral("id"));

        return roles;
    }

    QVariant data(const QModelIndex &index, int role) const Q_DECL_FINAL
    {
        if (index.row() >= 0 && size_t(index.row()) < m_items.size()) {
            const Vehicle &entry = m_items.at(index.row());
            switch (role) {
            case VehicleRoles::VehiculeType:
                return entry.type();
            case VehicleRoles::Name:
                return entry.name();
            case VehicleRoles::Id:
                return entry.id();
            }
        }
        return QVariant();
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_FINAL
    {
        if (index.row() >= 0 && size_t(index.row()) < m_items.size()) {
            Vehicle &entry = m_items[index.row()];
            switch (role) {
            case VehicleRoles::VehiculeType:
                entry.setType(static_cast<App::VehicleType>(value.toInt()));
                return true;
            case VehicleRoles::Id:
                entry.setId(value.toInt());
                return true;
            case VehicleRoles::Name:
                entry.setName(value.toString());
                return true;
            }
        }
        return false;
    }
};


#endif // LISTMODEL_H

