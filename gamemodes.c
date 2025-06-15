#include "gamemodes.h"
#include "design.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LEADERBOARD 15
#define LEADERBOARD_FILE "roulette_leaderboard.txt"
#define MAX_PLAYERS 6
#define NAME_LEN 50
void loadLeaderboard() {
    FILE *file = fopen(LEADERBOARD_FILE, "r");
    if (file == NULL) {
        leaderboardCount = 0;
        return;
    }
    
    leaderboardCount = 0;
    while (leaderboardCount < MAX_LEADERBOARD && 
 fscanf(file, "%50s %d %d %9s", leaderboard[leaderboardCount].name, &leaderboard[leaderboardCount].money,
&leaderboard[leaderboardCount].rounds,
leaderboard[leaderboardCount].status) == 4)
 {
        leaderboardCount++; }
    
    fclose(file);
    sortLeaderboard();
}

void sortLeaderboard() {
    for (int i = 0; i < leaderboardCount - 1; i++) {
        for (int j = 0; j < leaderboardCount - i - 1; j++) {
            if (leaderboard[j].money < leaderboard[j+1].money || 
                (leaderboard[j].money == leaderboard[j+1].money && 
                 leaderboard[j].rounds < leaderboard[j+1].rounds)) {
                struct LeaderboardEntry temp = leaderboard[j];
                leaderboard[j] = leaderboard[j+1];
                leaderboard[j+1] = temp;
            }
        }
    }
    

    for (int i = 0; i < leaderboardCount; i++) {
        leaderboard[i].position = i + 1;
    }
}

void saveLeaderboard() {
    FILE *file = fopen(LEADERBOARD_FILE, "w");
    if (file == NULL) {
        printf("Error: Could not save leaderboard data. Even our filing system is broken.\n");
        return;
    }
    
    for (int i = 0; i < leaderboardCount; i++) {
        fprintf(file, "%s %d %d %s\n", 
                leaderboard[i].name, 
                leaderboard[i].money,
                leaderboard[i].rounds,
                leaderboard[i].status);
    }
    
    fclose(file);
}

void saveToLeaderboard(char* name, int money, int rounds, char* status) {
    loadLeaderboard(); 
    
    for (int i = 0; i < leaderboardCount; i++) {
        if (strcmp(leaderboard[i].name, name) == 0) {
          
            if (money > leaderboard[i].money || 
                (money == leaderboard[i].money && rounds > leaderboard[i].rounds)) {
                leaderboard[i].money = money;
                leaderboard[i].rounds = rounds;
                strcpy(leaderboard[i].status, status);
            }
            sortLeaderboard();
            saveLeaderboard();
            return;
        }
    }
    
    
    if (leaderboardCount < MAX_LEADERBOARD) {
        strcpy(leaderboard[leaderboardCount].name, name);
        leaderboard[leaderboardCount].money = money;
        leaderboard[leaderboardCount].rounds = rounds;
        strcpy(leaderboard[leaderboardCount].status, status);
        leaderboardCount++;
    } else {
     
        int loserBahi = 0;
        for (int i = 1; i < MAX_LEADERBOARD; i++) {
            if (leaderboard[i].money < leaderboard[loserBahi].money ||
                (leaderboard[i].money == leaderboard[loserBahi].money && 
                 leaderboard[i].rounds < leaderboard[loserBahi].rounds)) {
                loserBahi = i;
            }
        }
        
        if (money > leaderboard[loserBahi].money ||
            (money == leaderboard[loserBahi].money && rounds > leaderboard[loserBahi].rounds)) {
            strcpy(leaderboard[loserBahi].name, name);
            leaderboard[loserBahi].money = money;
            leaderboard[loserBahi].rounds = rounds;
            strcpy(leaderboard[loserBahi].status, status);
        }
    }
    
    sortLeaderboard();
    saveLeaderboard();
}


void showHallOfShame() {
    loadLeaderboard();
    
    if (!playerHasPlayed) {
        showLoadingScreen("\t\t\tAccessing the Hall of Fame... where dreams come to die a digital death.");
        printf("\t\t\t\tPress ENTER to witness the legends of legendary stupidity.\n");
        getchar();
    } else {
showLoadingScreen("\t\t\tUpdating the Hall of Fame with your latest contribution to human nonsense...");
        printf("\t\t\t\tPress ENTER to see how your failure ranks among the elite disasters.");
        getchar();
    }
    
    clearScreen();
    printf("\n" YELLOW "\t\t+================================================================+");
    printf("\n\t\t|                    HALL OF FAME                                |");
    printf("\n\t\t|           Where Free Will Pulls the Trigger                    |");
    printf("\n\t\t+================================================================+\n" RESET);
    
    if (!playerHasPlayed) {
        printf(RED "\n\t\tAh, a tourist in the graveyard of shattered dreams and broken logic.\n" RESET);
        printf(YELLOW "\t\tYou want to see the Hall of Fame without earning your place?\n" RESET);
        printf(CYAN "\t\tThat's like reading restaurant reviews without ever eating there.\n" RESET);
        printf(MAGENTA "\t\tCome back when you have properly traumatized yourself like a true champion.\n\n" RESET);
        printf(WHITE "\t\tThis hall is reserved for those who have danced with death and lived to regret it.\n\n" RESET);
        printf("\t\tPress ENTER to retreat to your safe space...");
        getchar();
        return;
    }
    
    printf(MAGENTA "\n\t\tSo... you played Russian Roulette. How did that work out for you?\n" RESET);
    printf(RED "\t\tJudging by the fact you're reading this, either very well or very badly.\n" RESET);
    printf(YELLOW "\t\tEither way, welcome to the Hall of Fame - where every entry tells a story.\n" RESET);
    printf(CYAN "\t\tSome stories are inspiring. Others are cautionary tales. Yours is probably both.\n\n" RESET);
    
    if (leaderboardCount == 0) {
        printf(GREEN "\n\t\tWell, this is awkward. You're literally the first person to play this game.\n" RESET);
        printf(YELLOW "\t\tCongratulations on being Patient Zero of this particular brand of digital insanity.\n" RESET);
        printf(CYAN "\t\tYour name will be forever etched in history as the pioneer of poor decisions.\n" RESET);
        printf(WHITE "\t\tPlay a few more times and maybe you'll have some company in here.\n\n" RESET);
    } else {
        printf(GREEN "\t\tBehold, the current roster of legends, lunatics, and lottery winners:\n\n" RESET);
        
        printf(CYAN "\t\t+------+-------------------------+----------+--------+------------+\n");
        printf("\t\t| Rank | Name                    | Money    | Rounds | Status     |\n");
        printf("\t\t+------+-------------------------+----------+--------+------------+\n" RESET);
        
        for (int i = 0; i < leaderboardCount; i++) {
            char* color = WHITE;
            
            if (i == 0) color = MAGENTA;           
            else if (i < 3) color = RED;     
            else if (i < 8) color = YELLOW;      
            else color = BLUE;                 
            
            printf("%s\t\t| #%-3d | %-23s | $%-7d | %-6d | %-10s |\n" RESET,
                   color, i + 1, leaderboard[i].name, leaderboard[i].money, 
                   leaderboard[i].rounds, leaderboard[i].status);
        }
        
        printf(CYAN "\t\t+------+-------------------------+----------+--------+------------+\n\n" RESET);
        
       
    if (leaderboardCount > 0) {
    printf(MAGENTA "\n\t\tCurrent Hall of Fame Champion: " RED "%s\n" RESET, leaderboard[0].name);

    if (strcmp(leaderboard[0].name, "Death_Himself") == 0) {
        printf(RED "\t\tStatus: Literally unbeatable (Death doesnot play fair)\n" RESET);
        printf(YELLOW "\t\tTip: Do not bother chasing the throne. He already dug your grave.\n" RESET);
    } else if (strcmp(leaderboard[0].status, "ALIVE") == 0) {
        printf(CYAN "\t\tStatus: Still breathing (Smart enough to quit while ahead)\n" RESET);
    } else {
        printf(RED "\t\tStatus: Digitally deceased (Went out in spectacular fashion)\n" RESET);
  
    }
}
    }
    
    printf(YELLOW "\n\t\t" "================================\n" RESET);
    printf(MAGENTA "\t\tRemember: Every name on this list represents a story.\n" RESET);
    printf(WHITE "\t\tSome stories have happy endings. Others... well, let's just say they end.\n" RESET);
    printf(CYAN "\t\tThe question is: What kind of story do you want yours to be?\n" RESET);
    printf(RED "\t\tBecause once you are in this hall, you are here forever.\n\n" RESET);
    
    printf(GREEN "\t\tPress ENTER to return to reality...\n" RESET);
    printf(BLUE "\t\t(Where the bullets are digital and the regret is real)\n" RESET);
    
    getchar();
}


void playSolo(int mode) {
    char playerName[NAME_LEN];
    int money = 0, round = 1;
    int cashPerRound = (mode == 1) ? 100 : 100000;
    char modeName[20] = {0};
    
    strcpy(modeName, (mode == 1) ? "Simple" : "Suicide");
    
    clearScreen();
    showWelcomeScreen();
   printf("\n\n" CYAN "+==============================================+");
printf("\n|                SOLO MODE - %-9s         |", modeName);
printf("\n+==============================================+\n" RESET);

    
    printf("\n"YELLOW"Enter your name (or leave blank for random name):"RESET" ");
    fgets(playerName, NAME_LEN, stdin);
    playerName[strcspn(playerName, "\n")] = 0; 
    
    processPlayerName(playerName);
    
    srand(time(NULL));

    while (1) {
        clearScreen();
        showWelcomeScreen();
        
   printf("\n\n" CYAN "+==============================================+");
printf("\n|                SOLO MODE - %-9s         |", modeName);
printf("\n+==============================================+\n" RESET);
        

        int bulletCount;
        if (mode == 1) {
            bulletCount = ((round - 1) / 5) + 1;
            if (bulletCount > 5) bulletCount = 5;
        } else {

            bulletCount = 5;
        }
        
       printf("\nPlayer: " CYAN "%s" RESET, playerName);

printf("\n" BLUE "Round: " WHITE "%d" RESET " | " YELLOW "Money: " GREEN "$%d" RESET " | "MAGENTA "Bullets in Gun: " RED "%d/6" RESET,round, money, bulletCount);

if (mode == 1) {
    printf("\n" BLUE "Difficulty: ");
    if (bulletCount <= 1)
        printf(GREEN "Beginner's Luck");
    else if (bulletCount <= 2)
        printf(YELLOW "Getting Serious");
    else if (bulletCount <= 4)
        printf(RED "Death Wishes");
    else
        printf(MAGENTA "Suicidal Tendencies");
    printf(RESET);
}

printf("\n\n" YELLOW "%s\n" RESET, MessageDisplayer(2, round));
printf("\n" GREEN "Feeling lucky, " CYAN "%s" GREEN "?", playerName);
printf("\n" WHITE "Press ENTER to pull the trigger (" BLUE "and possibly end your " RED "misery" BLUE ")" WHITE "..." RESET);

        while (getchar() != '\n'); 

        int deathChance = (bulletCount * 100) / 6; 
        int randomRoll = rand() % 100 + 1;
        
        if (randomRoll <= deathChance) {
            printf("\n\n" YELLOW "WARNING: EXPLICIT CONTENT AHEAD" RESET);
printf(RED "\n+=================================================+\n");
printf("|                  B A N G ! ! !                  |\n");
printf("|            GAME OVER, HOTSHOT.                  |\n");
printf("|         "MAGENTA"THE ODDS WERE NEVER IN YOUR FAVOR."RED"      |\n");
printf("+=================================================+\n" RESET);

            
            printf("\n" RED "FATALITY!" RESET);
            printf("\n" CYAN "%s" RESET " "BLUE"has permanently left the chat (and this plane of existence)!", playerName);
            printf("\n"WHITE"You died in round "BLUE"%d"WHITE" with a whopping "GREEN"$%d "WHITE"to your name.", round, money);
            printf("\n"MAGENTA"Your final score: " RED "%d rounds survived" RESET " "GREEN"before natural selection kicked in.", round - 1);
            printf("\n"BLUE"Death probability this round was: " RED "%d%%" RESET, deathChance);
            
            printf(YELLOW "\n%s" RESET, MessageDisplayer(0, round));
            if (round == 1) {
    printf(RED "\n\nRound 1? That's not even a warm-up. Were you aiming to die?!" RESET); } 
    else if (round <= 3) {
    printf(YELLOW "\n\nYou came, you saw, you immediately died. Nice speedrun!" RESET);}
             else if (round <= 5) {
    printf(GREEN "\n\nRespectable-ish. You died just before things got interesting." RESET);}
            else if (round <= 10) {
    printf(CYAN "\n\nHey, you lasted longer than most horror movie side characters!" RESET);}
             else {
    printf(YELLOW "\n\nYou're like that cockroach that refuses to die. Impressive... and concerning." RESET);}
                 playerHasPlayed = 1;
            saveToLeaderboard(playerName, money, round - 1, "DEAD");
 printf("\n\n"GREEN"Press ENTER to return to the main menu "BLUE"(if your soul can find its way back)..."RESET"");
            getchar();
            return;
        } else {
           printf("\n\n" GREEN "+==============================================+");
           printf("\n|                  C L I C K !                 |");
           printf("\n|            LUCKY BASTARD LIVES!              |");
           printf("\n+==============================================+\n" RESET);

            money += cashPerRound;
            printf("\n" GREEN "MIRACLE!" RESET);
            printf("\n" CYAN "%s" RESET " "YELLOW"somehow survived round "BLUE"%d "YELLOW"and earned "GREEN"$%d"BLUE"!", playerName, round, cashPerRound);
            printf("\n"BLUE"Total cash: " GREEN "$%d" RED " (blood money, essentially)"RED"", money);
            printf("\n"MAGENTA"Survival odds were: " GREEN "%d%%" GREEN " (you got lucky!)"RESET"", 100 - deathChance);
            
            printf(YELLOW "\n%s" RESET, MessageDisplayer(1, round));
      
            if (round % 5 == 0) {
                printf(MAGENTA "\n\nRound %d milestone! Bullets increased! Death is taking notes!" RESET, round);
            }
            if (round % 10 == 0) {
                printf(CYAN "\n\nRound %d! You're either incredibly lucky or incredibly stupid!" RESET, round);
            }
        }

        printf("\n\n"BLUE"Continue to round %d "WHITE"or "GREEN"leave with your money (and remaining brain cells)?"RESET"", round + 1);
        printf("\n"WHITE"(Enter " MAGENTA "C"WHITE " to continue tempting fate or " MAGENTA "L" WHITE " to leave while you still have a functioning brain):"RESET" ");
        
        char choice = getCharChoice("CL",  ""RED"Is 'C' or 'L' really rocket science? Your brain damage is showing!"RESET"");

        if (choice == 'L') {
            printf("\n" GREEN "SMART MOVE!" RESET);
            printf("\n"WHITE"You walked away with " GREEN "$%d" RESET " "WHITE"and most of your "GREEN"dignity "WHITE"intact.", money);
            printf("\n"BLUE"Rounds survived: " CYAN "%d" RESET " "GREEN"(a personal record, probably)", round);
            printf(YELLOW "\n%s" RESET, MessageDisplayer(1, round));
            
            printf(BLUE "\n\nFinal words of wisdom: "RED"Greed kills"WHITE", but you already knew that." RESET);
            
            playerHasPlayed = 1;
            saveToLeaderboard(playerName, money, round, "ALIVE");

            printf("\n\n"WHITE"Press ENTER to return to less "RED"suicidal activities..."RESET"");
        while (getchar() != '\n');
            return;
        }

        round++;
    }
}


void playMultiplayer(int playerCount) {
    char names[MAX_PLAYERS][NAME_LEN];
    int alive[MAX_PLAYERS];
    int aliveCount = playerCount;
    int round = 1;

    srand(time(NULL));

    clearScreen();
    showWelcomeScreen();

    printf("\n\n" BLUE "+==================================================+" RESET);
    printf("\n" BLUE "|                  MULTIPLAYER MODE                |" RESET);
    printf("\n" BLUE "+==================================================+\n" RESET);

    printf("\n"WHITE"Enter player names (or leave blank for random names):"RESET"\n");

    for (int i = 0; i < playerCount; i++) {
        printf("Player %d: ", i + 1);
        fgets(names[i], NAME_LEN, stdin);
        names[i][strcspn(names[i], "\n")] = 0;

        processPlayerName(names[i]);

        for (int j = 0; j < i; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                printf(YELLOW "\nDuplicate name detected. How unoriginal.\n" RESET);
                printf("Adding a number so we know which corpse is which.\n");
                char temp[NAME_LEN];
                sprintf(temp, "%s_%d", names[i], i + 1);
                strncpy(names[i], temp, NAME_LEN - 1);
                names[i][NAME_LEN - 1] = '\0';
                printf(""WHITE"New name: " CYAN "%s\n" RESET, names[i]);
                printf(""WHITE"Press ENTER to continue with your non-confusing identity..."RESET"");
                getchar();
            }
        }

        alive[i] = 1;
    }

    while (aliveCount > 1) {
        clearScreen();
        showWelcomeScreen();

        printf("\n\n" BLUE "+======================= ROUND %-2d =======================+" RESET, round);

        int bulletsThisRound = 1;
        if (round >= 3) {
            bulletsThisRound = ((round - 1) / 2) + 1;
            if (bulletsThisRound > 5) bulletsThisRound = 5;
        }

        printf("\n| Bullets this round: " RED "%d/6" RESET, bulletsThisRound);
        printf("\n| Surviving players: ");
        for (int i = 0; i < playerCount; i++) {
            if (alive[i]) {
                printf(CYAN " |%s| " RESET, names[i]);
            }
        }
        printf("(%d left)\n", aliveCount);

        printf(YELLOW "\n%s\n" RESET, MessageDisplayer(2, round));

        for (int player = 0; player < playerCount; player++) {
            if (!alive[player]) continue;

            printf("\n" BLUE "+===================== "MAGENTA"%s's Turn"BLUE" =====================+" RESET, names[player]);

            int deathChance = (bulletsThisRound * 100) / 6;
            printf("\n| Death probability: " RED "%d%%" RESET, deathChance);
            printf("\n| It's your turn, " CYAN "%s" RESET ".", names[player]);
            printf("\n| Press ENTER to pull the trigger (and hope for the best)...");
            getchar();

            int randomRoll = rand() % 100 + 1;

            if (randomRoll <= deathChance) {
                printf("\n" RED "+==================================================+" RESET);
                printf("\n" RED "|                     B A N G !                    |" RESET);
                printf("\n" RED "|            ANOTHER PLAYER IS GONE!               |" RESET);
                printf("\n" RED "|               BLOOD HAS BEEN SHED!               |" RESET);
                printf("\n" RED "+==================================================+\n" RESET);

                printf("\n" RED "FATALITY!" RESET);
                printf("\n" CYAN "%s" RESET " has been permanently removed from the gene pool!", names[player]);
                printf(YELLOW "\n%s" RESET, MessageDisplayer(0, round));

                alive[player] = 0;
                aliveCount--;

                if (round == 1) {
                    printf(RED "\n\nEliminated in round 1? That's a special kind of unlucky!" RESET);
                } else if (round <= 3) {
                    printf(YELLOW "\n\nAt least they made it past the tutorial phase!" RESET);
                } else {
                    printf(GREEN "\n\nRespectable performance before meeting their maker!" RESET);
                }

                printf("\n\n"WHITE"Press ENTER to continue the carnage..."RESET"");
                getchar();

                if (aliveCount == 1) {
                    for (int winner = 0; winner < playerCount; winner++) {
                        if (alive[winner]) {
                            clearScreen();
                            printf("\n" GREEN "\t\t\t\t+==================================================+" RESET);
                            printf("\n" GREEN "\t\t\t\t|                 CONGRATULATIONS!                 |" RESET);
                            printf("\n" GREEN "\t\t\t\t|           YOU ARE THE LAST ONE STANDING!         |" RESET);
                            printf("\n" GREEN "\t\t\t\t|               GLORY IS YOURS TODAY!              |" RESET);
                            printf("\n" GREEN "\t\t\t\t+==================================================+\n" RESET);

                            printf("\n" MAGENTA "\t\t\t\tVICTORY!" RESET);
                            printf("\n\t\t\t\t" CYAN "%s" RESET " is the sole survivor!", names[winner]);
                            printf("\n\t\t\t\tRounds survived: " GREEN "%d" RESET, round);
                            printf("\n\t\t\t\tCompetitors eliminated: " RED "%d" RESET, playerCount - 1);

                            printf(YELLOW "\n\t\t\t\t%s" RESET, MessageDisplayer(3, round));

                            playerHasPlayed = 1;
                        saveToLeaderboard(names[winner], round * 1000, round, "ALIVE");

                            printf("\n\n"WHITE"Press ENTER to return to the main menu..."RESET"");
                            getchar();
                            return;
                        }
                    }
                }
            } else {
                printf("\n" GREEN "+==================================================+" RESET);
                printf("\n" GREEN "|                   C L I C K !                    |" RESET);
                printf("\n" GREEN "|            THE FOOL GOT LUCKY!                   |" RESET);
                printf("\n" GREEN "|         DEATH MISSED... FOR NOW.                 |" RESET);
                printf("\n" GREEN "+==================================================+\n" RESET);

                printf("\n" GREEN "LUCKY!" RESET);
                printf("\n" CYAN "%s" RESET " lives to see another round!", names[player]);
                printf("\nSurvival odds were: " GREEN "%d%%" RESET, 100 - deathChance);

                printf(YELLOW "\n%s" RESET, MessageDisplayer(1, round));

                printf("\n\n"WHITE"Press ENTER for the next player..."RESET"");
                getchar();
            }
        }

        if (aliveCount > 1) {
            clearScreen();
            printf("\n" BLUE "\t\t\t\t+==================================================+" RESET);
            printf("\n" BLUE "\t\t\t\t|                END OF ROUND %-2d                   |" RESET, round);
            printf("\n" BLUE "\t\t\t\t|          SURVIVORS: %2d out of %2d                 |" RESET, aliveCount, playerCount);
            printf("\n" BLUE "\t\t\t\t+==================================================+\n" RESET);

            if (aliveCount == 1) {
                printf(MAGENTA "\n\t\t\t\tOnly one remains... The silence is deafening.\n" RESET);
            } else if (aliveCount <= 3) {
                printf(YELLOW "\n\t\t\t\tSurvivors clinging on like a plot twist nobody asked for.\n" RESET);
            } else {
                printf(CYAN "\n\t\t\t\tTension builds. Luck won't last forever...\n" RESET);
            }

            printf("\n"WHITE"\t\t\t\tPress ENTER to continue to Round %d..."RESET"", round + 1);
            getchar();
            round++;
        }
    }
}

void showInstructions() {
    clearScreen();
printf("\n\n");
    printf(BLUE "        +===========================================================+\n");
    printf("        |                  GAME INSTRUCTIONS                        |\n");
    printf("        |                (Read Before You Bleed)                    |\n");
    printf("        +===========================================================+\n" RESET);
    printf(YELLOW "\n        ============ HOW TO PLAY (And Hopefully Survive) ============\n\n" RESET);
    printf(GREEN "        [1] SOLO MODE:\n" RESET);
    printf("        " WHITE "    * Choose between Simple Mode (1-5 bullets) or Suicide Mode\n");
    printf("            * Each round, you pull the trigger and pray to RNG gods\n");
    printf("            * Survive = Earn money  |  Die = Game over (obviously)\n");
    printf("            * You can quit and keep winnings... if you're wise\n" RESET);
    printf(GREEN "\n        [2] MULTIPLAYER MODE:\n" RESET);
    printf("        " WHITE "    * 2-6 players take turns pulling the trigger\n");
    printf("            * Bullets increase as rounds progress (more fun!)\n");
    printf("            * Last player standing wins (and needs therapy)\n");
    printf("            * Dead players become ghosts... I mean spectators\n" RESET);
    printf(RED "\n        ======================== WARNING ========================\n");
    printf("        " WHITE "    >>> This is a SIMULATION - Don't try this at home! <<<\n");
    printf(RED "        =========================================================\n" RESET);
    printf(CYAN "\n        =================== DIFFICULTY LEVELS ===================\n" RESET);
    printf(GREEN "            Beginner's Luck     : 1 bullets (You might survive)\n" RESET);
    printf(YELLOW "            Getting Serious     : 2-3 bullets   (50/50 chance)\n" RESET);
    printf(MAGENTA "            Death Wishes        : 4 bullets   (Probably dead)\n" RESET);
    printf(RED "            Suicidal Tendencies  : 5 bullets   (Write your will)\n" RESET);
    printf(MAGENTA "\n        =================== SURVIVAL TIPS ===================\n" RESET);
    printf(WHITE "            > Quit while you're ahead (and breathing)\n");
    printf("            > Luck runs out faster than your patience\n");
    printf("            > Math doesn't care about your feelings\n");
    printf("            > The house always wins... Death is the house\n" RESET);
    
    printf(CYAN "\n        ========================================================\n");
    printf("                    Press ENTER to return to safety...\n");
    printf("        ========================================================\n" RESET);
    
    getchar();
}

