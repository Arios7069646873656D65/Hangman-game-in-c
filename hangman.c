#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char word[] = ""; // The hidden word
    int attempts = 6; // Total attempts
    int wordLength = strlen(word);
    char masked[wordLength + 1]; // Masked version of the word
    char guess[100]; // User's inputm

    printf("Welcome to the hangman game created by arios\n");
    printf("You have 6 total attempts to find the hidden word\n");
    printf("The game is not case sensitive\n");

    // Initialize the masked word
    for (int i = 0; i < wordLength; i++) {
        masked[i] = '_';
    }
    masked[wordLength] = '\0'; // the 0 basiclly is the null terminator why we set the masked word arryay length to the null terminator

    printf("%s\n", masked); // Show the masked word

    while (attempts > 0) {
        printf("Please enter a character or a word: \n");
        scanf("%s", guess);

        // Convert input to lowercase
        for (int i = 0; guess[i]; i++) {
            guess[i] = tolower(guess[i]);
        }

        int inputLength = strlen(guess);

        if (inputLength > 1) {
            // User guesses the whole word
            if (strcmp(guess, word) == 0) {
                printf("Congratulations! You guessed the word correctly: %s\n", word);
                return 0; // End the game
            } else {
                attempts--;
                printf("Incorrect word. You have %d attempts left.\n", attempts);
            }
        } else {
            // User guesses a single character
            int correctGuess = 0;
            for (int i = 0; i < wordLength; i++) {
                if (word[i] == guess[0]) {
                    masked[i] = word[i];
                    correctGuess = 1;
                }
            }

            if (correctGuess) {
                printf("Good guess! Current word: %s\n", masked);
            } else {
                attempts--;
                printf("Incorrect character. You have %d attempts left.\n", attempts);
            }

            // Checks if the user has guessed the entire word
            if (strcmp(masked, word) == 0) {
                printf("Congratulations! You guessed the word: %s\n", word);
                return 0; // End the game
            }
        }
    }

    printf("Game over! The word was: %s\n", word);
    return 0;
}


