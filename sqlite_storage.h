/**
 * @file sqlite_storage.h
 *
 * @brief This file describes the SqliteStorage class
 *
 */

#pragma once
#include <QSqlDatabase>
#include <QString>
#include <vector>
#include "text.h"
#include "section.h"

using namespace std;

class SqliteStorage
{
private:
    QString name;
    QSqlDatabase db;

public:
    SqliteStorage(QString name_=""){
        name=name_;
    }

    void Start(QString name_);

    void ClearData();

    int InsertSection(QString sectName);

    vector<struct Section> GetAllSections();

    bool RemoveSection(Section sect);

    int InsertText(Section sect, Text text);

    vector<struct Text> GetAllTextInSection(Section sect);

    bool RemoveText(Text text);

    bool UpdateText(Text text);

};

