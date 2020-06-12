/**
 * @file sqlite_storage.cpp
 *
 */

#include "sqlite_storage.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include "section.h"
#include "text.h"

using namespace std;

void SqliteStorage::Start(QString name_){
    db = QSqlDatabase::addDatabase("QSQLITE");
    name=name_;
    db.setDatabaseName(name);
}

void SqliteStorage::ClearData(){
    bool connected = db.open();  // open db connection
    if (!connected) {
       qDebug() << "open database error:"
                << db.lastError();
       exit(1);
    }

    QSqlQuery query;
    if (!query.prepare("DELETE FROM sections"))
    {
       qDebug() << "Clear query prepare error:"
                << query.lastError();
       // return or throw or do smth else
    }


    if (!query.exec())
    {
       qDebug() << "Clear query  exec error:"
                << query.lastError();
       exit(1);
    }

    if (!query.prepare("DELETE FROM texts"))
    {
       qDebug() << "Clear query prepare error:"
                << query.lastError();
       // return or throw or do smth else
    }


    if (!query.exec())
    {
       qDebug() << "Clear query  exec error:"
                << query.lastError();
       exit(1);
    }

    db.close();
}

int SqliteStorage::InsertSection(QString sectName){
    bool connected = db.open();  // open db connection
    if (!connected) {
       qDebug() << "open database error:"
                << db.lastError();
       exit(1);
    }

    QSqlQuery query;
    if (!query.prepare("INSERT INTO sections (name)"
                       " VALUES (:name)"))
    {
       qDebug() << "addCar query prepare error:"
                << query.lastError();
       // return or throw or do smth else
    }

    query.bindValue(":name", sectName);

    if (!query.exec())
    {
       qDebug() << "addCar query exec error:"
                << query.lastError();
       exit(1);
    }
    QVariant var = query.lastInsertId();

    db.close();
    return var.toInt();
}

Section getSectionFromQuery(const QSqlQuery &query){
    Section newSect;
    newSect.id = query.value("id").toInt();
    newSect.sectionName = query.value("name").toString();
    return newSect;
}

vector<struct Section> SqliteStorage::GetAllSections(){
    vector<struct Section> newSections;

    bool connected = db.open();  // open db connection
    if (!connected) {
       qDebug() << "open database error:"
                << db.lastError();
       exit(1);
    }
    qDebug() << "database opened";

    QSqlQuery query;
    if (!query.prepare("SELECT * FROM sections")){
        qDebug() << "getAllSections query prepare error:" << query.lastError();
    }

    if (!query.exec()){
        qDebug() << "getAllSections query exec error:" << query.lastError();
    }
    else{
        while (query.next())
        {
            Section tempSect = getSectionFromQuery(query);
            newSections.push_back(tempSect);
        }
    }

    return newSections;
}

bool SqliteStorage::RemoveSection(Section sect){
    db.open();

    QSqlQuery query;
    if (!query.prepare("DELETE FROM sections WHERE id = :id")){
        qDebug() << "deleteSect query prepare error:" << query.lastError();
        exit(1);

    }
    query.bindValue(":id", sect.id);
    if (!query.exec()){
        qDebug() << "deleteSect query exec error:" << query.lastError();
        exit(1);
    }

    if(query.numRowsAffected()==0){
        db.close();
        return false;
    }

    if (!query.prepare("DELETE FROM texts WHERE section_id = :section_id")){
        qDebug() << "deleteTextsInSection query prepare error:" << query.lastError();
        exit(1);

    }
    query.bindValue(":section_id", sect.id);
    if (!query.exec()){
        qDebug() << "deleteTextsInSection query exec error:" << query.lastError();
        exit(1);
    }

    db.close();
    return true;
}

int SqliteStorage::InsertText(Section sect, Text text){
    bool connected = db.open();  // open db connection
    if (!connected) {
       qDebug() << "open database error:"
                << db.lastError();
       exit(1);
    }

    QSqlQuery query;
    if (!query.prepare("INSERT INTO texts (bold, italic, string, time, name, section_id)"
                       " VALUES (:bold, :italic, :string, :time, :name, :section_id)"))
    {
       qDebug() << "addText query prepare error:"
                << query.lastError();
       // return or throw or do smth else
    }

    query.bindValue(":bold", text.font.bold());
    query.bindValue(":italic", text.font.italic());
    query.bindValue(":string", text.string);
    query.bindValue(":time", text.time.toString());
    query.bindValue(":name", text.name);
    query.bindValue(":section_id", sect.id);

    if (!query.exec())
    {
       qDebug() << "addText query exec error:"
                << query.lastError();
       exit(1);
    }
    QVariant var = query.lastInsertId();

    db.close();
    return var.toInt();
}

Text getTextFromQuery(const QSqlQuery &query){
    Text newText;
    newText.id = query.value("id").toInt();
    newText.string = query.value("string").toString();
    newText.time = QDateTime::fromString(query.value("time").toString());

    if(query.value("bold").toInt()==1){
        newText.font.setBold(true);
    }
    else{
        newText.font.setBold(false);
    }

    if(query.value("italic").toInt()==1){
        newText.font.setItalic(true);
    }
    else{
        newText.font.setItalic(false);
    }

    newText.sectionId = query.value("section_id").toInt();
    newText.name = query.value("name").toString();

    return newText;
}

vector<struct Text> SqliteStorage::GetAllTextInSection(Section sect){
    vector<struct Text> newTexts;

    bool connected = db.open();  // open db connection
    if (!connected) {
       qDebug() << "open database error:"
                << db.lastError();
       exit(1);
    }
    qDebug() << "database opened";

    QSqlQuery query;
    if (!query.prepare("SELECT * FROM texts WHERE section_id=:section_id")){
        qDebug() << "GetAllTextInSection query prepare error:" << query.lastError();
    }

    query.bindValue(":section_id", sect.id);

    if (!query.exec()){
        qDebug() << "GetAllTextInSection query exec error:" << query.lastError();
    }
    else{
        while (query.next())
        {
            Text tempText = getTextFromQuery(query);
            newTexts.push_back(tempText);
        }
    }

    return newTexts;
}

bool SqliteStorage::RemoveText(Text text){
    db.open();

    QSqlQuery query;
    if (!query.prepare("DELETE FROM texts WHERE id = :id")){
        qDebug() << "deleteText query prepare error:" << query.lastError();
        exit(1);

    }
    query.bindValue(":id", text.id);
    if (!query.exec()){
        qDebug() << "deleteText query exec error:" << query.lastError();
        exit(1);
    }

    if(query.numRowsAffected()==0){
        db.close();
        return false;
    }
    db.close();
    return true;
}

bool SqliteStorage::UpdateText(Text text){
    db.open();

    QSqlQuery query;
    if (!query.prepare("UPDATE texts SET bold=:bold, italic=:italic, string=:string WHERE id=:id")){
        qDebug() << "deleteText query prepare error:" << query.lastError();
    }

    query.bindValue(":id", text.id);
    query.bindValue(":bold", text.font.bold());
    query.bindValue(":italic", text.font.italic());
    query.bindValue(":string", text.string);

    if (!query.exec()){
        qDebug() << "deleteText query exec error:" << query.lastError();
    }

    if(query.numRowsAffected()==0){
        db.close();
        return false;
    }
    db.close();
    return true;
}
