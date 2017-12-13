#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QObject>

class DataBaseManager: public QObject{
Q_OBJECT
public:
    DataBaseManager();
    QSqlDatabase database_interface;
public slots:
    void data_received(QString command, QString last_name, QString last_phone_number, QString name, QString phone_number);
signals:
    void database_updated();

};

#endif // DATABASEMANAGER_H
