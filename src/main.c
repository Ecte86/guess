#include "../include/main.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    iocharmap(IOCHM_PETSCII_2);
    Game game;
    game.secret = rand() % 100;
    game.guess = -1;
    game.tries = 0;
    game.max_tries = 10;

    MainMenuChoice main_menu_choice = mainMenu();
    while (main_menu_choice == 0) {
        switch (main_menu_choice) {
            case PLAY:
                play(&game);
                break;
            case DIFFICULTY:
                difficultyMenu(&game);
                break;
            case QUIT:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                main_menu_choice = 0;
                break;
        }
    }

    if (main_menu_choice != QUIT) {
        main();
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
    int choice;
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