/**
 * @file text.h
 *
 * @brief This file describes the Text struct
 *
 */

#include <QString>
#include <QFont>
#include <QTime>
#include <QMetaType>

#pragma once

struct Text{
    QString name;
    int id;
    int sectionId;
    QFont font;
    QString string;
    QDateTime time;
};Q_DECLARE_METATYPE(Text)
