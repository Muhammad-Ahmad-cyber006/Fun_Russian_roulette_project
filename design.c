#include <stdlib.h>
#include "design.h"
#include <stdio.h>
#include <time.h>
#include<conio.h>
#include <windows.h>
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showWelcomeScreen() {

    printf("\n");
    printf(RED "\t\t\t\t\t +------------------------------------------------+        " WHITE "(                                 _\n");
    printf(BLUE "\t\t\t\t\t |       RUSSIAN ROULETTE - CHAOTIC EDITION       |         " WHITE ")                               /=>\n");
    printf(RED "\t\t\t\t\t +------------------------------------------------+       " WHITE "(  +____________________/\\/\\___ / /|\n");
    printf(WHITE "\t\t\t\t\t                                                            .''._____________'._____      / /|/\\\n");
    printf(WHITE "\t\t\t\t\t                                                           : " RED "()" WHITE " :              :\\ ----\\|    \\ )\n");
    printf(WHITE "\t\t\t\t\t                                                            '..'______________.'0|----|      \\\n");
    printf(YELLOW "\t\t\t\t\t      Death is just a click away!                               " WHITE "               0_0/____/        \\\n");
    printf(YELLOW "\t\t\t\t\t      Who needs retirement anyway?                                " WHITE "                |----    /----\\\n");
    printf(WHITE "\t\t\t\t\t                                                                               || -\\\\ --|      \\\n");
    printf(WHITE "\t\t\t\t\t                                                                                ||   || ||\\      \\\n");
    printf(WHITE "\t\t\t\t\t                                                                                \\\\____// '|      \\\n");
    printf(RED "\t\t\t\t\t                                         BANG! BANG!                " WHITE "                    .'/       |\n");
    printf(WHITE "\t\t\t\t\t                                                                                       .:/        |\n");
    printf(WHITE "\t\t\t\t\t                                                                                       :/_________|\n" RESET);
}


void showLoadingScreen(const char* msg) {
    const int BAR_LENGTH = 40;
    const int TOTAL_STEPS = 7;
    const int DELAY_MS = 150;

    const char* tip[] = {
    " Pro tip: Luck is just probability with a bad attitude.",
    " Remember: The house always wins... except when it doesn't.",
    " Fun fact: Courage is just stupidity with better marketing.",
    "  Tip: If you're feeling lucky, you're probably not.",
    " Reminder: Positive thinking won't improve your odds.",
    " Note: 50% skill, 50% luck, 100% questionable choices.",
    "Wisdom:The only winning move is not to play,but that's no fun.",
    "     Fact: Statistically, you're already dead inside.",
    "Hint: Confidence helps... with really bad decisions.",
    "Truth: Odds aren't in your favor, but snacks are free.",
    "           Advice: Fail once? Just blame the RNG.",
    "  Warning: Side effects include dread and empty pockets.",
    "    Reminder: Even a broken clock is right twice a day.",
    "    Tip: The best strategy is no strategy... maybe.",
    "   Fact: 73% of stats are made up, including this one.",
    "         Note: Your mom called. She's disappointed.",
    "       Truth: The game was probably rigged from the start.",
};
    const int num_of_tips = sizeof(tip) / sizeof(tip[0]);

    srand(time(NULL));
    const char* get_tip = tip[rand() % num_of_tips];

    int user_interfering = 0;

    for (int step = 0; step <= TOTAL_STEPS; step++) {
        clearScreen();

        int progress = (step * 100) / TOTAL_STEPS;
        int bars_to_show = (step * BAR_LENGTH) / TOTAL_STEPS;

        printf("" CYAN "\n\n\n\n\t\t\t%s\n\n", msg);

        printf("" GREEN "\t\t\t\t\t\t\t[");
        for (int i = 0; i < BAR_LENGTH; i++) {
            if (i < bars_to_show) {
                printf("=");
            } else if (i == bars_to_show && step < TOTAL_STEPS) {
                printf(">");
            } else {
                printf(" ");
            }
        }
        printf("] %d%%\n", progress);

        printf("\t\t\t\t\t\t\t\t\tLoading");
        for (int i = 0; i < (step % 4); i++) {
            printf(".");
        }
        printf("\n");

        printf("" YELLOW "\n\t\t\t\t\t          %s\n", get_tip);

        if (_kbhit()) {
            user_interfering = 1;
            while (_kbhit()) _getch(); 
        }

        Sleep(DELAY_MS);
    }

    clearScreen();
    printf("" CYAN "\n\n\n\n\t\t\t%s\n\n", msg);
    printf("\t\t\t\t\t\t\t" GREEN "[========================================] 100%%\n");
    printf("\t\t\t\t\t\t\t\t\tComplete!\n");
    printf("" YELLOW "\n\t\t\t\t\t          %s\n\n" RESET "", get_tip);
    Sleep(500);

    fflush(stdin);
    if (user_interfering) {
printf("" RED "\n\t\t\t\tWow... patience is not your strong suite, is it?\n");
        printf("\t\t\t\tYou're that person, huh?\n\n" RESET);
        Sleep(700);
            while (_kbhit()) _getch();
    }
}



