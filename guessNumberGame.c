#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
#define MAX_ATTEMPTS 10

void playGame();
int getRandomNumber(int max);

int main() {
    srand(time(0)); // Seed the random number generator

    printf("Welcome to the Guess the Number game!\n");
    printf("I have chosen a number between 1 and %d. You have %d attempts to guess it.\n", MAX_NUMBER, MAX_ATTEMPTS);
    
    playGame();

    printf("Game over. Thanks for playing!\n");

    return 0;
}

void playGame() {
    int randomNumber = getRandomNumber(MAX_NUMBER);
    int guess;
    int attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        printf("\nEnter your guess (between 1 and %d): ", MAX_NUMBER);
        if (scanf("%d", &guess) != 1 || guess < 1 || guess > MAX_NUMBER) {
            printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUMBER);
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        attempts++;
        
        if (guess < randomNumber) {
            printf("Too low. Try again!\n");
        } else if (guess > randomNumber) {
            printf("Too high. Try again!\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", randomNumber, attempts);
            return;
        }
    }
    
    printf("Sorry, you've run out of attempts. The number was %d.\n", randomNumber);
}

int getRandomNumber(int max) {
    return rand() % max + 1; // Generates a random number between 1 and max
}
