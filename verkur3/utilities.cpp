#include "utilities.h"


namespace utils {
    string str2upper(string str)
    {
        transform(str.begin(), str.end(), str.begin(),::toupper);

        return str;
    }

    string str2lower(string str)
    {
        transform(str.begin(), str.end(), str.begin(),::tolower);

        return str;
    }

    string int2str(const int& a)
    {
        stringstream ss;
        ss << a;
        string str;
        ss >> str;

        return str;
    }

    void trimeWS(string& str)
    {
        stringstream ss;
        ss << str;
        char nextin;
        char last;
        string input, output;
        getline(ss, input);

        for (int i = 0; i < strlen(input.c_str()); i++)
        {
            if(input[i] != ' ')
            {
                if(input[i-1] == ' ')
                    output += " ";
                output += input[i];
            }
        }

        str = output;
    }

    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "PersonConnection";

        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName("verkur.sqlite");

            if(db.open())
            {
                qDebug() << "Fer inn i gagnagrunninn baby" << endl;
            }
        }

        return db;
    }
}

