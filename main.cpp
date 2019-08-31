/* In this exercise we want to design a Storyboard. Our version of the Storyboard
 * contains arbitrary many notes (imagine it like putting sticky notes on a board).
 * Every note has a title, a text and a set of tags. E.g.
 * 	- title: "Test Traceplayer"
 * 	- text: "Implement a unit test for the class Traceplayer of the spark core framework."
 * 	- tags: {"unit test", "traceplayer", "testing", "spark core"}
 *
 * Our Storyboard should enable us to search for notes by title, text and tags.
 * E.g.:
 *      searchByTitle("Test Traceplayer")
 *      searchByTag({"testing", "unit test"})
 *   	searchByText("Implement a unit test for the class Traceplayer of the spark core framework.")
 * For the sake of simplicity we don't want to do any similiarity or prefix matching when
 * searching for a title, tag or text. Only an exact match should give results.
 *
 * The skeleton code below can be used as a starting point but doesn't have to.
 * The comments "fill in" are placeholders where you definitely have to put in some code when
 * you use this skeleton code. But this doesn't mean that you shouldn't or can't put code anywhere else.
 *
 * Also write some simple unit tests to show how you would test the functionality of the Storyboard.
 * Don't use any testing framework. Simple if-statements are sufficient for this exercise.
 *
 * Hint: Think about performance versus memory tradeoffs in your design, so you can give good
 *       reasons for your decision.
 */
///
/// @brief
/// @author Oleg Potkin <olpotkin@gmail.com>
///



#include "core/storyboard.h"

int main() {

  Note note_1{1, "Note 1", "Some text #", {"tag1", "tag2"} };
  Note note_2{2, "Note 2", "Some text #", {"tag2", "tag3"} };
  Note note_3{3, "Note 3", "Some text #", {"tag1", "tag5"} };
  Note note_4{4, "Note 4", "Some text #", {"tag1", "tag5"} };

  Storyboard sb{};
  sb.addNote(note_1);
  sb.addNote(note_2);
  sb.addNote(note_3);
  sb.addNote(note_4);
  std::cout << "Initial size of storyboard = " << sb.getSize() << std::endl;

  sb.deleteNote(4);
  std::cout << "Size of storyboard after deletion of 1 note = " << sb.getSize() << std::endl;
  std::cout << std::endl;

  auto search_1 = sb.searchByTitle("Note 1");
  for (const auto& s : search_1) {
    auto n = sb.getNoteById(s);
    std::cout << "search by title:"
              << " ID=" << n.getId()
              << " Title=" << n.getTitle()
              << std::endl;
  }
  std::cout << std::endl;

  auto search_2 = sb.searchByText("Some text #");
  for (const auto& s : search_2) {
    auto n = sb.getNoteById(s);
    std::cout << "search by text:"
              << " ID=" << n.getId()
              << " Title=" << n.getTitle()
              << std::endl;
  }
  std::cout << std::endl;

  auto search_3 = sb.searchByTag("tag5");
  for (const auto& s : search_3) {
    auto n = sb.getNoteById(s);
    std::cout << "search by tag " << "'#tag5': "
              << " ID=" << n.getId()
              << " Title=" << n.getTitle()
              << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
