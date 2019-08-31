///
/// @brief
/// @author Oleg Potkin <olpotkin@gmail.com>
///

#ifndef STORYBOARD_NOTE_H
#define STORYBOARD_NOTE_H

#include <iostream>
#include <string>
#include <vector>

class Note {
public:
  /// @brief Default constructor
  explicit Note(int id);
  /// @brief Ctor with 2 parameters
  Note(int id,  std::string title);
  /// @brief Ctor with 3 parameters
  Note(int id,  std::string title, std::string text);
  /// @brief Ctor with 4 parameters
  Note(int id,  std::string title, std::string text, std::vector<std::string> tags);
  /// @brief Default dtor
  ~Note() = default;

  int getId() const;
  void setId(int id);

  std::string getTitle() const;
  void setTitle(const std::string& title);

  std::string getText() const;
  void setText(const std::string& text);

  std::vector<std::string> getTags() const;
  void addTag(const std::string& tag);

private:
  int id;                                // ID of the Note
  std::string title;                     // Title of the Note
  std::string text;                      // Text in the Note
  std::vector<std::string> tags;         // Tags of the Note
};

#endif //STORYBOARD_NOTE_H
