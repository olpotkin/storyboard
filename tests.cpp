//
// Created by Oleg Potkin on 2019-08-30.
//

#define BOOST_TEST_MODULE storyboard_test_module

#include <boost/test/unit_test.hpp>
#include "core/note.h"
#include "core/storyboard.h"


BOOST_AUTO_TEST_SUITE(storyboard_test_suite)

  // Test 01:
  // Check if Note ctor works as expected
  BOOST_AUTO_TEST_CASE(test_01_note_ctor) {
    Note note_1{1,
                "Note 1",
                "Some text",
                {"tag1", "tag2"} };

    BOOST_CHECK(note_1.getId() == 1);
    BOOST_CHECK(note_1.getTitle() == "Note 1");
    BOOST_CHECK(note_1.getText() == "Some text");
    BOOST_CHECK(note_1.getTags().size() == 2);
  }

  // Test 02:
  // Check if checkNoteExists works as expected
  BOOST_AUTO_TEST_CASE(test_02_checkNoteExists) {
    Note note_1{1,
                "Note 1",
                "Some text",
                {"tag1", "tag2"} };

    Storyboard sb{};
    sb.addNote(note_1);

    BOOST_CHECK(sb.checkNoteExists(1) == true);
    BOOST_CHECK(sb.checkNoteExists(2) == false);
  }

  // Test 03:
  // Check if addNote works as expected
  BOOST_AUTO_TEST_CASE(test_03_addNote) {
    Note note_1{1,
                "Note 1",
                "Some text",
                {"tag1", "tag2"} };
    Storyboard sb{};

    BOOST_CHECK(sb.addNote(note_1) == 0);        // Add original Note
    BOOST_CHECK(sb.addNote(note_1) == -1);       // Add duplicate
    BOOST_CHECK(sb.checkNoteExists(1) == true);
  }

  // Test 04:
  // Check if getNoteById works as expected
  BOOST_AUTO_TEST_CASE(test_04_getNoteById) {
    Note note_1{1,
                "Note 1",
                "Some text",
                {"tag1", "tag2"} };
    Note note_2{2,
                "Note 2",
                "Some text",
                {"tag3", "tag4"} };
    Storyboard sb{};
    sb.addNote(note_1);
    sb.addNote(note_2);

    auto test_note_1 = sb.getNoteById(1);
    BOOST_CHECK(test_note_1.getId() == 1);
    BOOST_CHECK(test_note_1.getTitle() == "Note 1");

    auto test_note_2 = sb.getNoteById(2);
    BOOST_CHECK(test_note_2.getId() == 2);
    BOOST_CHECK(test_note_2.getTitle() == "Note 2");

    auto test_note_3 = sb.getNoteById(3);
    BOOST_CHECK(test_note_3.getId() == -1);
  }

  // Test 05:
  // Check if deleteNote works as expected
  BOOST_AUTO_TEST_CASE(test_05_deleteNote) {
    Note note_1{1,
                "Note 1",
                "Some text",
                {"tag1", "tag2"} };
    Note note_2{2,
                "Note 2",
                "Some text",
                {"tag3", "tag4"} };
    Storyboard sb{};
    sb.addNote(note_1);
    sb.addNote(note_2);

    BOOST_CHECK(sb.getSize() == 2);

    sb.deleteNote(1);
    BOOST_CHECK(sb.getSize() == 1);

    sb.deleteNote(1);
    BOOST_CHECK(sb.getSize() == 1);

    sb.deleteNote(2);
    BOOST_CHECK(sb.getSize() == 0);

    sb.deleteNote(2);
    BOOST_CHECK(sb.getSize() == 0);
  }

  // Test 06:
  // Check if searchByTitle works as expected
  BOOST_AUTO_TEST_CASE(test_06_searchByTitle) {
    Note note_1{1,
                "Note",
                "Some text",
                {"tag1", "tag2"} };
    Note note_2{2,
                "Note",
                "Some text",
                {"tag3", "tag4"} };
    Note note_3{3,
                "Note 3",
                "Some text",
                {"tag5", "tag6"} };
    Storyboard sb{};
    sb.addNote(note_1);
    sb.addNote(note_2);
    sb.addNote(note_3);

    auto result_1 = sb.searchByTitle("Note");
    BOOST_CHECK(result_1.size() == 2);

    auto result_2 = sb.searchByTitle("Note 3");
    BOOST_CHECK(result_2.size() == 1);
    auto note = sb.getNoteById(result_2[0]);
    BOOST_CHECK(note.getId() == 3);
    BOOST_CHECK(note.getTitle() == "Note 3");

    auto result_3 = sb.searchByTitle("Doesn't exist");
    BOOST_CHECK(result_3.size() == 0);
  }

  // Test 07:
  // Check if searchByText works as expected
  BOOST_AUTO_TEST_CASE(test_07_searchByText) {
    Note note_1{1,
                "Note 1",
                "Some text #",
                {"tag1", "tag2"} };
    Note note_2{2,
                "Note 2",
                "Some text #",
                {"tag3", "tag4"} };
    Note note_3{3,
                "Note 3",
                "Some text #3",
                {"tag5", "tag6"} };
    Storyboard sb{};
    sb.addNote(note_1);
    sb.addNote(note_2);
    sb.addNote(note_3);

    auto result_1 = sb.searchByText("Some text #");
    BOOST_CHECK(result_1.size() == 2);

    auto result_2 = sb.searchByText("Some text #3");
    BOOST_CHECK(result_2.size() == 1);
    auto note = sb.getNoteById(result_2[0]);
    BOOST_CHECK(note.getId() == 3);
    BOOST_CHECK(note.getText() == "Some text #3");

    auto result_3 = sb.searchByText("Doesn't exist");
    BOOST_CHECK(result_3.size() == 0);
  }

  // Test 08:
  // Check if searchByTag works as expected
  BOOST_AUTO_TEST_CASE(test_08_searchByTag) {
    Note note_1{1,
                "Note 1",
                "Some text #",
                {"tag1", "tag2"} };
    Note note_2{2,
                "Note 2",
                "Some text #",
                {"tag2", "tag3"} };
    Note note_3{3,
                "Note 3",
                "Some text #3",
                {"tag1", "tag5"} };
    Note note_4{4,
                "Note 4",
                "Some text #3",
                {"tag1", "tag5"} };
    Storyboard sb{};
    sb.addNote(note_1);
    sb.addNote(note_2);
    sb.addNote(note_3);
    sb.addNote(note_4);

    auto result_1 = sb.searchByTag("tag1");
    BOOST_CHECK(result_1.size() == 3);

    auto result_2 = sb.searchByTag("tag5");
    BOOST_CHECK(result_2.size() == 2);

    auto result_3 = sb.searchByTag("tag3");
    BOOST_CHECK(result_3.size() == 1);
    auto note = sb.getNoteById(result_3[0]);
    BOOST_CHECK(note.getId() == 2);
    BOOST_CHECK(note.getTitle() == "Note 2");

    auto result_4 = sb.searchByTag("tagX");
    BOOST_CHECK(result_4.size() == 0);
  }

BOOST_AUTO_TEST_SUITE_END()
