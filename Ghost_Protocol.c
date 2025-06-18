#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "design.h"
#include "input.h"
#include "gamemodes.h"
#include "training.h"

struct LeaderboardEntry leaderboard[MAX_LEADERBOARD];
int leaderboardCount = 0;
int playerHasPlayed = 0;
int playcount = 0;

void displaySafetyReminder() {
    clearScreen();
    printf("%s",RED);
    printf("\t\t\t+==============================================================================+\n");
    printf("\t\t\t|                                                                              |\n");
    printf("\t\t\t|                        RUSSIAN ROULETTE SIMULATOR                            |\n");
    printf("\t\t\t|                      (Digital Version - Safe and Legal)                      |\n");
    printf("\t\t\t|                                                                              |\n");
    printf("\t\t\t+==============================================================================+\n" RESET);
    
    printf(YELLOW "\n         \t\t\t\t          Welcome to Digital Darwinism!\n" RESET);
    printf(CYAN "             \t\t\t\t  Where stupidity meets its maker... virtually.\n" RESET);
    printf(MAGENTA "          \t\t\t\t       Play smart, or become a statistic.\n\n" RESET);
    printf(RED "\t\t\t+=============================================================================+\n");
    printf("\t\t\t|                               SAFETY REMINDER                               |\n");
    printf("\t\t\t+=============================================================================+\n" RESET);
    printf(YELLOW "\n          \t\t\t\t  *** ABSURDLY SERIOUS SAFETY ANNOUNCEMENT ***\n\n" RESET);
    printf("\t\t\t"WHITE"> "RED"Warning:"BLUE" This is a FICTIONAL SIMULATION - scripted by the "GREEN"mentally unstable,\n");
    printf("\t\t\t"WHITE">"GREEN" Performed by "MAGENTA"virtual idiots"WHITE", and approved by absolutely no one qualified.\n");
    printf("\t\t\t> "GREEN"Do NOT try this at home. Or anywhere. Or even in your imagination.\n\n");
    
    printf(""WHITE"\t\t\t> "RED"DO NOT - and I repeat - DO NOT try Russian Roulette in real life!\n");
    printf(""WHITE"\t\t\t> "RED"This isn't Jackass. This isn't TikTok. This is your life.\n");
    printf(""WHITE"\t\t\t> "RED"And I kinda want you to keep it.\n\n" RESET);
    
 printf("\t\t\t"MAGENTA"What real Russian Roulette actually is:\n");
    printf(" \t\t\t"WHITE"> A game invented by people who clearly lost at "GREEN"chess"WHITE" first\n");
    printf(" \t\t\t> A game played by someone who looked at a gun and said, 'Trust fall?'\n");
    printf(" \t\t\t> Still legal in "RED"4 "WHITE"countries (and somehow one of them has tourism ads)\n");
    printf(" \t\t\t> One spin away from starring in a documentary called "RED"'Why You Shouldn't'\n\n" RESET);


    printf(WHITE "\t\t\t> "CYAN"But relax! This game is just a harmless probability experiment.\n");
    printf(WHITE"\t\t\t> "CYAN"Like flipping a coin... that insults you when you lose.\n\n" RESET);

    printf(BLUE "\t\t\t\t\t>>>>>>By continuing, you agree<<<<<<<\n");
    printf(" \t\t\t"WHITE">"GREEN" This is FICTION\n");
    printf(WHITE" \t\t\t> "GREEN"You have at least one working brain cell\n");
    printf(WHITE" \t\t\t> "RED"Hopefully You're not loading a real revolver while reading this\n" RESET);

    printf("\n\t\t\tPress ENTER to continue to the game (and to life)...");
    getchar();

}

void showMainMenu() {
    clearScreen();
    showWelcomeScreen();
    
    printf("\n\n" BLUE "\t\t\t\t+============================================================+");
    printf("\n\t\t\t\t|                        MAIN MENU                           |");
    printf("\n\t\t\t\t+============================================================+\n" RESET);
    
    printf(WHITE "\n\t\t\t\t[1] " GREEN "Simple Mode (1-5 bullets) - For the cautious\n" RESET);
    printf(WHITE "\t\t\t\t[2] " RED "Suicide Mode (5 bullets) - For the brave\n" RESET);
    printf(WHITE "\t\t\t\t[3] " BLUE "Multiplayer Mode - Share the thrill\n" RESET);
    printf(WHITE "\t\t\t\t[4] " YELLOW "Training Mode - Practice makes... less dead\n" RESET);
    printf(WHITE "\t\t\t\t[5] " CYAN "Instructions - Read if you value your life\n" RESET);
    printf(WHITE "\t\t\t\t[6] " MAGENTA "Hall of Fame - Where legends go to die\n" RESET);
    printf(WHITE "\t\t\t\t[7] " GREEN "Exit - The smartest choice\n" RESET);
    
    printf(YELLOW "\n\t\t\t\tChoose your fate (1-7): " RESET);
}

int main() {
    srand(time(NULL));
    showLoadingScreen("Loading Important Message from the Developer : Heroes read safety tips. Legends ignore them. Choose wisely.");

    printf("\t\t\t "BLUE"Press ENTER to read or ignore the message... I mean, look at you - you are here, playing Russian Roulette.");
    while (getchar() != '\n');
    displaySafetyReminder();
    showLoadingScreen("\t\tInitializing game for the first time... because what could possibly go wrong?");
    printf("\t\t\t\t  "BLUE"\tPress ENTER to begin your glorious journey into very poor decision-making.");
    while (getchar() != '\n');

    while (1) {
        showMainMenu();
        int choice = getValidInt(1, 7, "Numbers 1-7 only!");
        
        switch (choice) {
            case 1: {
                showLoadingScreen("\t\t   Preparing Solo Mode... because talking to people is hard, we get it.");
                printf("\t\t\t\t\t "BLUE"   Press ENTER to face the only person who truly wants you dead: you.");
                while (getchar() != '\n');
                playSolo(1);
                playerHasPlayed = 1;
                playcount++;
                break;
            }
            case 2: {
               showLoadingScreen("\t\t   Engaging 5-Bullet Madness... sounds like a retirement plan for daredevils.");
                printf("\t\t\t\t\t"BLUE"\t      Press ENTER to prove that "GREEN"cash "CYAN"> "RED"caution.");
                while (getchar() != '\n');
                playSolo(2);
                playerHasPlayed = 1;
                playcount++;
                break;
            }
            case 3: {
                showLoadingScreen("\t\t\tLoading Multiplayer Mode... because bad decisions are better with friends.");
                printf("\t\t\t\t\t "BLUE"     Press ENTER to test the strength of your friendships - and your aim.\n");
                while (getchar() != '\n');
                playcount++;
                printf("\nHow many players? (2-6): ");
                int playerCount = getValidInt(2, MAX_PLAYERS, "2-6 players only!");
                playMultiplayer(playerCount);
                playerHasPlayed = 1;
                break;
            }
            case 4: {
                showLoadingScreen("\t\t\tLoading Training Mode... practice makes survival a bit more likely.");
                printf("\t\t\t\t\t"BLUE"Press ENTER to sharpen your skills - because luck favors the prepared!\n");
                while (getchar() != '\n');
                showTrainingMenu();
                break;
            }
            case 5: {
                showLoadingScreen("\t\t\tPulling up Instructions... yes, some players actually read these.");
                printf("\t\t\t\t\t"BLUE"\t\t     Press ENTER to pretend this will help you survive.\n");
                while (getchar() != '\n');
                showInstructions();
                break;
            }
            case 6: {
                showHallOfShame();
                break;
            }
            case 7: {
                clearScreen();
                printf("\n" GREEN "\t\t\t\t+============================================================+");
                printf("\n\t\t\t\t|                        WISE DECISION!                      |");
                printf("\n\t\t\t\t|               You chose life = Excellent choice.           |");
                printf("\n\t\t\t\t+============================================================+\n" RESET);

                if (playcount) {
                    printf(CYAN "\n\t\t\t\tThanks for playing Russian Roulette = Chaotic Edition!\n" RESET);
                    printf(YELLOW "\t\t\t\tReminder: Real guns = real consequences. No extra lives.\n" RESET);
                    printf(MAGENTA "\t\t\t\tYou survived digital chaos. Now go touch grass.\n" RESET);
                } else {
                    printf(YELLOW "\n\t\t\t\tYou exited before playing = Smartest move of the day!\n" RESET);
                    printf(GREEN "\t\t\t\tSurvival instincts = fully operational.\n" RESET);
                    printf(CYAN "\t\t\t\tDarwin Award = successfully avoided. Nice work!\n" RESET);
                }

                printf(WHITE "\n\t\t\t\tStay sharp, stay sane, and remember: statistics are people too.\n" RESET);
                printf(RED " \t\t\t\tIf the real version ever tempts you... slam the brakes. HARD.\n" RESET);

                printf("\n\t\t\t\tPress ENTER to exit safely...");
                while (getchar() != '\n');

                printf(BLUE "\n\t\t\t\tGoodbye! Final tip: In Russian Roulette, the last laugh = the one who never played.\n" RESET);
                exit(0);
            }
        }
    }
    return 0;
}