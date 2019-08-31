///
/// @brief
/// @author Oleg Potkin <olpotkin@gmail.com>
///

#include "storyboard.h"


// Time complexity: O(1)
int Storyboard::addNote(const Note &note) {
  if (!checkNoteExists(note.getId())) {
    this->notes.push_back(note);
    //std::cout << "SUCCESS: " << "Note with id=" << note.getId() << " successfully added!" << std::endl;
    return 0;
  }
  //std::cout << "FAIL: " << "Note with id=" << note.getId() << " already exists!" << std::endl;
  return -1;
}

// Time complexity: O(N)
bool Storyboard::checkNoteExists(int id) {
  for (const auto& note : notes) {
    if (note.getId() == id) {
      //std::cout << "SUCCESS: " << "Note with id=" << note.getId() << " successfully found!" << std::endl;
      return true;
    }
  }
  //std::cout << "FAIL: " << "Note with id=" << id << " doesn't exist!" << std::endl;
  return false;
}

// Time complexity: O(N)
Note Storyboard::getNoteById(int id) {
  for (const auto& note : notes) {
    if (note.getId() == id) {
      //std::cout << "SUCCESS: " << "Note with id=" << note.getId() << " successfully returned!" << std::endl;
      return note;
    }
  }
  //std::cout << "FAIL: " << "Note with id=" << id << " doesn't exist! Note with ID=-1 returned." << std::endl;
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
    //std::cout << "SUCCESS: " << "Note with id=" << id << " successfully deleted!" << std::endl;
  }
  else {
    //std::cout << "FAIL: " << "Nothing to delete. Note with id=" << id << " doesn't exist!" << std::endl;
  }
}

// Time complexity: O(N)
std::vector<int> Storyboard::searchByTitle(const std::string &search_title) {
  std::vector<int> result;
  for (const auto& note : notes) {
    if (note.getTitle() == search_title) {
      //std::cout << "SUCCESS: " << "Note with title=" << search_title << " is found!" << std::endl;
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
      //std::cout << "SUCCESS: " << "Note with text=" << search_text << " is found!" << std::endl;
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
        //std::cout << "SUCCESS: " << "Note with tag=" << search_tag << " is found!" << std::endl;
        result.push_back(note.getId());
        break;  // preventing of searching same tags within one Note
      }
    }
  }
  return result;
}
