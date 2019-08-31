///
/// @brief
/// @author Oleg Potkin <olpotkin@gmail.com>
///

#include "note.h"


// Implementation of 4 versions of constructor
Note::Note(int id) : id(id) {}
Note::Note(int id, std::string title) : id(id), title(std::move(title)) {}
Note::Note(int id, std::string title, std::string text) : id(id), title(std::move(title)), text(std::move(text)) {}
Note::Note(int id, std::string title, std::string text, std::vector<std::string> tags) :
  id(id), title(std::move(title)), text(std::move(text)), tags(std::move(tags)) {}

// GET and SET methods for all data fields
// of the Note class

int Note::getId() const {
  return this->id;
}

void Note::setId(int id) {
  this->id = id;
}

std::string Note::getTitle() const {
  return this->title;
}

void Note::setTitle(const std::string& title) {
  this->title = title;
}

std::string Note::getText() const {
  return this->text;
}

void Note::setText(const std::string& text) {
  this->text = text;
}

std::vector<std::string> Note::getTags() const {
  return this->tags;
}

void Note::addTag(const std::string& tag) {
  this->tags.push_back(tag);
}
