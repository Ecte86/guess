#ifndef MAIN
#define MAIN

typedef enum GameState_e {
    MAIN_MENU,
    DIFFICULTY_MENU,
    PLAYING,
} GameState;

typedef struct game_s {
    int secret;
    int guess;
    int tries;
    int max_tries;
    GameState state;
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

char *mainLoop(Game *game);
MainMenuChoice mainMenu();
DifficultyChoice difficultyMenu(Game *game);
void play(Game *game);

#endif /* MAIN */
