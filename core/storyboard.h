///
/// @brief
/// @author Oleg Potkin <olpotkin@gmail.com>
///

#ifndef STORYBOARD_STORYBOARD_H
#define STORYBOARD_STORYBOARD_H

#include "note.h"


class Storyboard {
public:
  /// @brief To add Note into the Storyboard.
  ///        Returns 0 in case of success, otherwise -1
  /// @param note - Note object to be added
  int addNote(const Note& note);

  /// @brief To remove Note from the Storyboard by Note's ID
  /// @param id - id of the Note to be removed
  void deleteNote(int id);

  /// @brief To find all notes by given TITLE
  ///        Returns vector of IDs of notes where TITLE is matching
  /// @param search_title - string with title of the Note
  std::vector<int> searchByTitle(const std::string& search_title);

  /// @brief To find all notes by given TEXT
  ///        Returns vector of IDs of notes where TEXT is matching
  /// @param search_text - string with text of the Note
  std::vector<int> searchByText(const std::string& search_text);

  /// @brief To find all notes by given TAG
  ///        Returns vector of IDs of notes where TAG is matching
  /// @param search_tag - string with tag of the Note
  std::vector<int> searchByTag(const std::string& search_tag);

  // HELPERS
  /// @brief To check if Note with given ID already exists
  ///        Returns true if Note exists in the Storyboard, otherwise - false
  /// @param id - id of the Note to check
  bool checkNoteExists(int id);

  /// @brief To get the Note by given ID
  ///        Return Note from Storyboard if Note with given ID exists, otherwise - Note with ID=-1
  /// @param id - id of the Note to get
  Note getNoteById(int id);

  /// @brief To get the size of Storyboard
  ///        Return the size of notes vector
  int getSize();

private:
  std::vector<Note> notes;
};


#endif //STORYBOARD_STORYBOARD_H
