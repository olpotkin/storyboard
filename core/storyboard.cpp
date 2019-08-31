///
/// @brief
/// @author Oleg Potkin <olpotkin@gmail.com>
///

#include "storyboard.h"


// Time complexity: O(1)
int Storyboard::addNote(const Note &note) {
  if (!checkNoteExists(note.getId())) {
    this->notes.push_back(note);
    return 0;
  }
  return -1;
}

// Time complexity: O(N)
bool Storyboard::checkNoteExists(int id) {
  for (const auto& note : notes) {
    if (note.getId() == id) {
      return true;
    }
  }
  return false;
}

// Time complexity: O(N)
Note Storyboard::getNoteById(int id) {
  for (const auto& note : notes) {
    if (note.getId() == id) {
      return note;
    }
  }
  return Note(-1);
}

// Time complexity: O(1)
int Storyboard::getSize() {
  return this->notes.size();
}

// Time complexity: O(N)
void Storyboard::deleteNote(int id) {
  if (this->checkNoteExists(id)) {
    // Find matching index
    for (size_t i = 0; i < this->notes.size(); ++i) {
      if (this->notes[i].getId() == id) {
        // Erase element
        this->notes.erase(this->notes.begin() + i);
        break;
      }
    }
  }
}

// Time complexity: O(N)
std::vector<int> Storyboard::searchByTitle(const std::string &search_title) {
  std::vector<int> result;
  for (const auto& note : notes) {
    if (note.getTitle() == search_title) {
      result.push_back(note.getId());
    }
  }
  return result;
}

// Time complexity: O(N)
std::vector<int> Storyboard::searchByText(const std::string &search_text) {
  std::vector<int> result;
  for (const auto& note : notes) {
    if (note.getText() == search_text) {
      result.push_back(note.getId());
    }
  }
  return result;
}

// Time complexity: O(N*M), where
// N - number of Notes in the storyboard
// M - number of tags inside given Note
std::vector<int> Storyboard::searchByTag(const std::string &search_tag) {
  std::vector<int> result;
  for (const auto &note : notes) {
    auto tags = note.getTags();
    for (const auto &tag : tags) {
      if (tag == search_tag) {
        result.push_back(note.getId());
        // Preventing of searching same tags within one Note
        break;
      }
    }
  }
  return result;
}
