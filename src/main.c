#include "../include/main.h"

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    iocharmap(IOCHM_PETSCII_2);
    Game game;
    game.secret = rand() % 100;
    game.guess = -1;
    game.tries = 0;
    game.max_tries = 10;
    game.state = MAIN_MENU;
    bool valid = false;

    char *errMessage = mainLoop(&game);
    return 0;
}

MainMenuChoice processMainMenu(MainMenuChoice choice) {
    while (choice == 0) {
        switch (choice) {
            case PLAY:
                return PLAY;
            case DIFFICULTY:
                return DIFFICULTY;
            case QUIT:
                exit(0);
            default:
                printf("Invalid choice!\n");
                choice = 0;
        }
    }
    return choice;
}

DifficultyChoice processDifficultyMenu(DifficultyChoice choice) {
    while (choice == 0) {
        switch (choice) {
            case EASY:
                return EASY;
            case MEDIUM:
                return MEDIUM;
            case HARD:
                return HARD;
            default:
                printf("Invalid choice!\n");
                choice = 0;
        }
    }
    return choice;
}

char *mainLoop(Game *game) {
    MainMenuChoice mainMenuChoice;
    while (true) {
        switch (game->state) {
            case MAIN_MENU:
                mainMenuChoice = processMainMenu(mainMenu());
                switch (mainMenuChoice) {
                    case PLAY:
                        game->state = PLAYING;
                        break;
                    case DIFFICULTY:
                        game->state = DIFFICULTY_MENU;
                        break;
                    case QUIT:
                        exit(0);
                    default:
                        return "Invalid main menu choice!";
                }
                break;
            case DIFFICULTY_MENU:
                processDifficultyMenu(difficultyMenu(game));
                
                break;
            case PLAYING:
                play(game);
                game->state = MAIN_MENU;
                break;
            default:
                return "Invalid game state!";
        }
    }
}

MainMenuChoice mainMenu() {
    int choice;
    printf("1. Play\n");
    printf("2. Difficulty\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return (MainMenuChoice)choice;
}

DifficultyChoice difficultyMenu(Game *game) {
    int choice = 0;
    while (choice == 0) {
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case EASY:
                game->max_tries = 20;
                break;
            case MEDIUM:
                game->max_tries = 10;
                break;
            case HARD:
                game->max_tries = 5;
                break;
            default:
                printf("Invalid choice!\n");
                choice = 0;
        }
    }
    return (DifficultyChoice)choice;
}

void play(Game *game) {
    while (game->guess != game->secret && game->tries < game->max_tries) {
        printf("Enter your guess: ");
        scanf("%d", &game->guess);
        game->tries++;
        if (game->guess < game->secret) {
            printf("Too low!\n");
        } else if (game->guess > game->secret) {
            printf("Too high!\n");
        }
    }
    if (game->guess == game->secret) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}