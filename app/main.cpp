#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "app.h"

int main(int ac, char *av[])
{
    QGuiApplication app(ac, av);
    QScopedPointer<QQmlApplicationEngine> view(new QQmlApplicationEngine());

    qmlRegisterSingletonType<App>("CarServiceLog", 1, 0, "App", [] (QQmlEngine *, QJSEngine *) -> QObject *
    {
       return new App();
    });

    view->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
