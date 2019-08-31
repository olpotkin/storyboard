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

    BOOST_CHECK( sb.getSize() == 2);

    sb.deleteNote(1);
    BOOST_CHECK(sb.getSize() == 1);

    sb.deleteNote(1);
    BOOST_CHECK(sb.getSize() == 1);

    sb.deleteNote(2);
    BOOST_CHECK(sb.getSize() == 0);

    sb.deleteNote(2);
    BOOST_CHECK(sb.getSize() == 0);
  }


BOOST_AUTO_TEST_SUITE_END()
