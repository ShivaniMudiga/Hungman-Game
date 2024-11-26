"Hungman-Game" 
Features
Interactive Gameplay:

Player 1 inputs a secret word and a hint letter.
Player 2 guesses the letters in the word within six attempts.
Dynamic Word Display:

The word is represented by underscores (_), which are replaced by correctly guessed letters.
Graphical Representation:

A simple ASCII art hangman is displayed to visualize wrong guesses.
Win/Loss Conditions:

Player 2 wins if they guess all letters correctly before running out of attempts.
Player 1 wins if Player 2 fails within six chances.
Hint System:

Player 1 provides one letter from the word as a hint for Player 2.
Error Handling:

Tracks incorrect guesses and decreases the number of remaining attempts.
Game Rules
Player 1 enters the secret word and a hint letter.
Player 2 has six chances to guess the letters in the word.
Correct guesses fill in the corresponding underscores.
Incorrect guesses update the hangman diagram and reduce the available chances.
The game ends when Player 2 guesses the entire word or exhausts all chances.
Technology Stack
Language: C
Standard Libraries Used:
stdio.h for input/output operations.
string.h for string manipulation functions.
stdlib.h for using system("cls") to clear the console.
How the Game Works
Initialization:

Player 1 provides a secret word.
A blank representation (_) of the word is displayed.
Player 2 is given a hint and starts guessing.
Gameplay Loop:

Player 2 enters a letter.
If the guess is correct, the blanks are updated.
If incorrect, a part of the hangman is drawn, and remaining chances are decremented.
Ending the Game:

Player 2 wins by guessing all letters before exhausting chances.
Player 1 wins if Player 2 uses all chances without guessing the word.
Display Results:

Shows the winner, the complete hangman diagram (if Player 1 wins), and the word.
Potential Enhancements
Add support for longer words and phrases.
Implement case insensitivity for guessing.
Introduce a scoring system based on correct guesses and attempts left.
Provide a replay option at the end of the game.
Enable multiplayer mode with alternating turns.
