/**
 * @file section.h
 *
 * @brief This file describes the Section struct
 *
 */

#include <QString>
#include <QMetaType>
#pragma once

struct Section{
    int id;
    QString sectionName;
};Q_DECLARE_METATYPE(Section)
