///
/// @brief
/// @author Oleg Potkin <olpotkin@gmail.com>
///

#include "storyboard.h"


// Time complexity: O(1)
int Storyboard::addNote(const Note &note) {
  if (!checkNoteExists(note.getId())) {
    this->notes.push_back(note);
    std::cout << "SUCCESS: " << "Note with id=" << note.getId() << " successfully added!" << std::endl;
    return 0;
  }
  std::cout << "FAIL: " << "Note with id=" << note.getId() << " already exists!" << std::endl;
  return -1;
}

// Time complexity: O(N)
bool Storyboard::checkNoteExists(int id) {
  for (const auto& note : notes) {
    if (note.getId() == id) {
      std::cout << "SUCCESS: " << "Note with id=" << note.getId() << " successfully found!" << std::endl;
      return true;
    }
  }
  std::cout << "FAIL: " << "Note with id=" << id << " doesn't exist!" << std::endl;
  return false;
}

// Time complexity: O(N)
Note Storyboard::getNoteById(int id) {
  for (const auto& note : notes) {
    if (note.getId() == id) {
      std::cout << "SUCCESS: " << "Note with id=" << note.getId() << " successfully returned!" << std::endl;
      return note;
    }
  }
  std::cout << "FAIL: " << "Note with id=" << id << " doesn't exist! Note with ID=-1 returned." << std::endl;
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
    std::cout << "SUCCESS: " << "Note with id=" << id << " successfully deleted!" << std::endl;
  }
  else {
    std::cout << "FAIL: " << "Nothing to delete. Note with id=" << id << " doesn't exist!" << std::endl;
  }
}

// Time complexity: O(N)
std::vector<int> Storyboard::searchByTitle(const std::string &search_title) {
  std::vector<int> result;
  for (const auto& note : notes) {
    if (note.getTitle() == search_title) {
      std::cout << "SUCCESS: " << "Note with title=" << search_title << " founded!" << std::endl;
      result.push_back(note.getId());
    }
  }
  return result;
}


