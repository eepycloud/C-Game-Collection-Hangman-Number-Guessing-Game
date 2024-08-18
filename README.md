# C Game Collection: Hangman & Number Guessing Game:

This repository contains two classic console games implemented in C:

1. **Guess the Number**: The computer will try to guess a number that you think of, using a binary search strategy.
2. **Hangman**: Guess the letters of a hidden word before running out of attempts. You can choose from categories like food, objects, names, and colors.

## Features:

- **Multiple Games**: Users can choose to play either Hangman or Guess the Number.
- **Simple UI**: Text-based interface that guides users through the game.
- **Category Selection**: Choose from different categories for the Hangman game.
- **Graphical Representation**: Visual representation of guess attempts in Guess the Number.

## Getting Started:

### Prerequisites

To run this project, you need:
- A C compiler (e.g., GCC)
- Basic knowledge of C programming

### Game Instructions:

#### Guess the Number

1. The game starts by prompting you to think of a number between 1 and 10,000.
2. The computer will make guesses and you provide feedback whether the number is correct, higher, or lower.
3. The game continues until the correct number is guessed.

#### Hangman

1. Select a category: Food, Objects, Names, or Colors.
2. The game will randomly pick a word from the selected category.
3. Guess letters to uncover the word. You have a limited number of attempts.

## Files

- **main.c**: Contains the main program logic and game functions.
- **products.txt**: A text file used for storing product information for the additional store-related functionality.
- **foc_fa22.h**: Header file containing utility functions and array handling used in the games.
