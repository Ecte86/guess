#ifndef MAIN
#define MAIN

typedef struct {
    int secret;
    int guess;
    int tries;
    int max_tries;
} Game;

typedef enum difficultyChoice_e {
    EASY,
    MEDIUM,
    HARD
} DifficultyChoice;

typedef enum mainMenuChoice_e {
    PLAY,
    DIFFICULTY,
    QUIT
} MainMenuChoice;

MainMenuChoice mainMenu();
DifficultyChoice difficultyMenu(Game *game);
void play(Game *game);

#endif /* MAIN */
