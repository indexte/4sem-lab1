/**
 * @file unit_test.cpp
 *
 */

#include "unit_test.h"

UnitTest::UnitTest() {
    this->storage = new SqliteStorage();
    this->storage->Start("..\\data\\data.sqlite");
    this->storage->ClearData();
}

UnitTest::~UnitTest() {
    if(CONSOLE_OUTPUT)
        std::cout << "All test has been passed!" << std::endl;

    delete this->storage;
}

void UnitTest::test() {
    std::vector<Section> sections = this->storage->GetAllSections();
    std::vector<Text> texts;
    std::string text;

    if(CONSOLE_OUTPUT) {
        std::cout << "FOUND: " << sections.size() << " SECTIONS" << std::endl;
    }

    // inserting test data
    this->storage->InsertSection("test_section");
    this->storage->InsertSection("test_section_one");
    this->storage->InsertSection("test_section_two");
    this->storage->InsertSection("test_section_three");
    this->storage->InsertSection("test_section_four");

    sections = this->storage->GetAllSections();

    std::cout << std::endl;

    for (size_t i = 0; i < sections.size(); i++)
        std::cout << "FOUND: [" << sections[i].sectionName.toStdString() << "\t #id" << sections[i].id << "]\t SECTION" << std::endl;

    std::cout << std::endl;

    // ASSERTATIONS
    assert(sections[0].sectionName.toStdString() == "test_section");
    assert(sections[1].sectionName.toStdString() == "test_section_one");
    assert(sections[2].sectionName.toStdString() == "test_section_two");
    assert(sections[3].sectionName.toStdString() == "test_section_three");
    assert(sections[4].sectionName.toStdString() == "test_section_four");

    Text testText;
    testText.sectionId = sections[2].id;
    testText.name = "test_name";
    testText.string = "test_string";

    this->storage->InsertText(sections[2], testText);
    this->storage->InsertText(sections[2], testText);
    this->storage->InsertText(sections[2], testText);
    this->storage->InsertText(sections[2], testText);

    texts = this->storage->GetAllTextInSection(sections[2]);

    for(size_t i = 0; i < texts.size(); i++)
        std::cout << "FOUND: " << texts[i].string.toStdString() << "\t NAME: "  << texts[i].name.toStdString() << " \tTEXT" << std::endl;

    // ASSERTATIONS
    assert(texts.size() == 4);
    assert(texts[0].string.toStdString() == "test_string");
    assert(texts[1].string.toStdString() == "test_string");
    assert(texts[2].string.toStdString() == "test_string");
    assert(texts[3].string.toStdString() == "test_string");
    assert(texts[0].name.toStdString() == "test_name");
    assert(texts[1].name.toStdString() == "test_name");
    assert(texts[2].name.toStdString() == "test_name");
    assert(texts[3].name.toStdString() == "test_name");

    this->storage->ClearData();

    std::cout << "TEST DATA CLEARED";

    sections = this->storage->GetAllSections();

    std::cout << std::endl << sections.size() << " SECTIONS FOUND" << std::endl;
    if(sections.size() == 0)
        std::cout << "NO TEXTS FOUND AS THERE ARE NO SECTIONS" << std::endl;

    assert(sections.size() == 0);

    std::cout << "16 assertations passed" << std::endl;
}
