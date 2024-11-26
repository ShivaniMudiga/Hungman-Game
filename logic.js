let word = "";
let hint = "";
let guessedWord = [];
let wrongGuesses = 0;
let maxChances = 6;

const startGameButton = document.getElementById("startGame");
const submitGuessButton = document.getElementById("submitGuess");
const player1Section = document.getElementById("player1");
const player2Section = document.getElementById("player2");
const wordDisplay = document.getElementById("wordDisplay");
const hintElement = document.getElementById("hint");
const guessInput = document.getElementById("guessInput");
const chancesElement = document.getElementById("chances");
const hangmanElement = document.getElementById("hangman");
const messageElement = document.getElementById("message");

startGameButton.addEventListener("click", () => {
    word = document.getElementById("wordInput").value.toLowerCase();
    hint = document.getElementById("hintInput").value;

    if (word && hint) {
        guessedWord = Array(word.length).fill("_");
        player1Section.classList.add("hidden");
        player2Section.classList.remove("hidden");
        updateDisplay();
    } else {
        alert("Please enter both a word and a hint.");
    }
});

submitGuessButton.addEventListener("click", () => {
    const guess = guessInput.value.toLowerCase();
    guessInput.value = "";
    messageElement.textContent = "";

    if (guess && guess.length === 1) {
        if (word.includes(guess)) {
            messageElement.textContent = "Correct guess!";
            for (let i = 0; i < word.length; i++) {
                if (word[i] === guess) {
                    guessedWord[i] = guess;
                }
            }
        } else {
            messageElement.textContent = "Wrong guess!";
            wrongGuesses++;
        }

        updateDisplay();
        checkGameStatus();
    } else {
        messageElement.textContent = "Please enter a valid letter.";
    }
});

function updateDisplay() {
    hintElement.textContent = `Hint: ${hint}`;
    wordDisplay.textContent = guessedWord.join(" ");
    chancesElement.textContent = `Chances left: ${maxChances - wrongGuesses}`;
    hangmanElement.textContent = getHangmanArt();
}

function checkGameStatus() {
    if (!guessedWord.includes("_")) {
        messageElement.textContent = "Congratulations! Player 2 won!";
        endGame();
    } else if (wrongGuesses === maxChances) {
        messageElement.textContent = `Game over! The word was: ${word}`;
        endGame();
    }
}

function endGame() {
    guessInput.disabled = true;
    submitGuessButton.disabled = true;
}

function getHangmanArt() {
    const hangmanStages = [
        `
         _ _ _ _ _ _ _ 
         |              
         |              
         |              
         |              
        `,
        `
         _ _ _ _ _ _ _ 
         |        O     
         |              
         |              
         |              
        `,
        `
         _ _ _ _ _ _ _ 
         |        O     
         |        |     
         |              
         |              
        `,
        `
         _ _ _ _ _ _ _ 
         |        O     
         |       /|     
         |              
         |              
        `,
        `
         _ _ _ _ _ _ _ 
         |        O     
         |       /|\\   
         |              
         |              
        `,
        `
         _ _ _ _ _ _ _ 
         |        O     
         |       /|\\   
         |       /      
         |              
        `,
        `
         _ _ _ _ _ _ _ 
         |        O     
         |       /|\\   
         |       / \\   
         |              
        `
    ];
    return hangmanStages[wrongGuesses];
}
