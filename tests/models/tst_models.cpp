#include <QtTest/QTest>
#include "listmodel.h"

Q_DECLARE_METATYPE(std::vector<FuelEntry>)

class tst_Models : public QObject
{
    Q_OBJECT
private slots:

    void insertRow_data();
    void insertRow();

    void removeRow_data();
    void removeRow();
};



void tst_Models::insertRow_data()
{
    QTest::addColumn<std::vector<FuelEntry> >("entries");
    QTest::addColumn<int>("rowCount");

    QTest::newRow("EmptyModel") << std::vector<FuelEntry>() << 0;
    QTest::newRow("SmallModel") << std::vector<FuelEntry>({
                                                              { },
                                                              { 39222, 34.0f, 50.0f },
                                                              { 39655, 18.0f, 35.0f }
                                                          }) << 3;
}

void tst_Models::insertRow()
{
    QFETCH(std::vector<FuelEntry>, entries);
    QFETCH(int, rowCount);

    //GIVEN
    FuelEntryModel model;

    // WHEN
    for (auto entry : entries) {
        // WHEN
        bool inserted = model.insertRow(entry);
        // THEN
        QVERIFY(inserted);
    }

    // THEN
    QCOMPARE(model.rowCount(), rowCount);

    for (int i = 0; i < model.rowCount(); ++i) {
        QCOMPARE(model.data(model.index(i), FuelEntryModel::FuelType).toInt(), static_cast<int>(entries.at(i).fuelType()));
        QCOMPARE(model.data(model.index(i), FuelEntryModel::CurrencyType).toInt(), static_cast<int>(entries.at(i).currencyType()));
        QCOMPARE(model.data(model.index(i), FuelEntryModel::ActualMileage).toInt(), entries.at(i).actualMileage());
        QCOMPARE(model.data(model.index(i), FuelEntryModel::Quantity).toFloat(), entries.at(i).quantity());
        QCOMPARE(model.data(model.index(i), FuelEntryModel::TotalPrice).toFloat(), entries.at(i).totalPrice());
        QCOMPARE(model.data(model.index(i), FuelEntryModel::PerUnitPrice).toFloat(), entries.at(i).perUnitPrice());
        QCOMPARE(model.data(model.index(i), FuelEntryModel::Date).toDateTime(), entries.at(i).date());
    }

    // GIVEN
    FuelEntryModel model2;

    // WHEN
    model2.insertRows(entries);

    // THEN
    QCOMPARE(model2.rowCount(), rowCount);

    for (int i = 0; i < model2.rowCount(); ++i) {
        QCOMPARE(model2.data(model2.index(i), FuelEntryModel::FuelType).toInt(), static_cast<int>(entries.at(i).fuelType()));
        QCOMPARE(model2.data(model2.index(i), FuelEntryModel::CurrencyType).toInt(), static_cast<int>(entries.at(i).currencyType()));
        QCOMPARE(model2.data(model2.index(i), FuelEntryModel::ActualMileage).toInt(), entries.at(i).actualMileage());
        QCOMPARE(model2.data(model2.index(i), FuelEntryModel::Quantity).toFloat(), entries.at(i).quantity());
        QCOMPARE(model2.data(model2.index(i), FuelEntryModel::TotalPrice).toFloat(), entries.at(i).totalPrice());
        QCOMPARE(model2.data(model2.index(i), FuelEntryModel::PerUnitPrice).toFloat(), entries.at(i).perUnitPrice());
        QCOMPARE(model2.data(model2.index(i), FuelEntryModel::Date).toDateTime(), entries.at(i).date());
    }
}

void tst_Models::removeRow_data()
{
    QTest::addColumn<std::vector<FuelEntry> >("entries");

    QTest::newRow("EmptyModel") << std::vector<FuelEntry>();
    QTest::newRow("SmallModel") << std::vector<FuelEntry>({
                                                              { },
                                                              { 39222, 34.0f, 50.0f },
                                                              { 39655, 18.0f, 35.0f }
                                                          });
}

void tst_Models::removeRow()
{
    QFETCH(std::vector<FuelEntry>, entries);

    //GIVEN
    FuelEntryModel model;
    model.insertRows(entries);

    // WHEN
    int rowCount = model.rowCount();
    for (int i = 0; i < rowCount; ++i) {
        // WHEN
        model.removeRows(0);
        entries.erase(entries.begin());

        // THEN
        QCOMPARE(size_t(model.rowCount()), entries.size());

        if (model.rowCount() == 0)
            continue;
        QCOMPARE(model.data(model.index(0), FuelEntryModel::FuelType).toInt(), static_cast<int>(entries.at(0).fuelType()));
        QCOMPARE(model.data(model.index(0), FuelEntryModel::CurrencyType).toInt(), static_cast<int>(entries.at(0).currencyType()));
        QCOMPARE(model.data(model.index(0), FuelEntryModel::ActualMileage).toInt(), entries.at(0).actualMileage());
        QCOMPARE(model.data(model.index(0), FuelEntryModel::Quantity).toFloat(), entries.at(0).quantity());
        QCOMPARE(model.data(model.index(0), FuelEntryModel::TotalPrice).toFloat(), entries.at(0).totalPrice());
        QCOMPARE(model.data(model.index(0), FuelEntryModel::PerUnitPrice).toFloat(), entries.at(0).perUnitPrice());
        QCOMPARE(model.data(model.index(0), FuelEntryModel::Date).toDateTime(), entries.at(0).date());
    }
    // THEN
    QVERIFY(model.rowCount() == 0);

}

QTEST_MAIN(tst_Models)

#include "tst_models.moc"
