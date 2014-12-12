#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QDebug>

class Database
{
public:
    Database();
    QSqlDatabase m_db;
    QSqlDatabase db();
    ~Database();
    bool open();
    void close();
};

#endif // DATABASE_H
