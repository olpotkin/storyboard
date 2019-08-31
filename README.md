# Storyboard
 Concept of the Storyboard

In this project simple Storyboard is designed. Initial version of the Storyboard contains arbitrary many notes (imagine it like putting sticky notes on a board).

Every note has a `title`, a `text` and a set of `tags`.
<br>
Example:
- `title`: "Test Traceplayer"
- `text`: "Implement a unit test for the class Traceplayer of the spark core framework."
- `tags`: {"unit test", "traceplayer", "testing", "spark core"}

Storyboard should enable to <b>search</b> for notes by `title`, `text` and `tags`.
<br>
Example:
- `searchByTitle("Test Traceplayer")`
- `searchByTag({"testing"})`
- `searchByText("Implement a unit test for the class Traceplayer of the spark core framework.")`

For the sake of simplicity no need to do any similiarity or prefix matching when searching for a title, tag or text. Only an exact match should give results.

Unit teast are also available.<br>
Performance analysis provided for Storyboard class methods.
