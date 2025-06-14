
#include "input.h"
#include "design.h"


int isOnlyDigits(const char* str) {
    if (str == NULL || *str == '\0') return 0;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

  int getValidInt(int min, int max, const char* errorMsg) {
    int value;
    char input[100];
    int validInput = 0;
    int attempts = 0;

    while (!validInput && attempts < MAX_INPUT_ATTEMPTS) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (input[0] == '\0') {
            printf(RED "\tAh, the sound of silence... but I asked for a number. %s\n" RESET "\tGive it another go: ", errorMsg);
            attempts++;
            continue;
        }

        int digitsOnly = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!isdigit(input[i])) {
                digitsOnly = 0;
                break;
            }
        }

        if (!digitsOnly) {
            printf(RED "\tUnless you're writing in ancient alien script, that's not a number. %s\n" RESET "\tTry again, earthling: ", errorMsg);
            attempts++;
            continue;
        }

        value = atoi(input);

        if (value >= min && value <= max) {
            validInput = 1;
        } else {
            printf(RED "\tWow. I literally said between %d and %d. %s\n" RESET "\tTry again before I cry in binary: ", min, max, errorMsg);
            attempts++;
        }
    }

    if (!validInput) {
        printf(YELLOW "\n\tYour input privileges have been revoked due to extreme confusion.\n" RESET);
        value = min + rand() % (max - min + 1);
        printf("\tI've picked " CYAN "%d" RESET " for you. May your randomly chosen fate be kind.\n", value);
        printf("\tHit ENTER to accept your new destiny...");
        getchar();
    }

    return value;

}

char getCharChoice(const char* validChars, const char* errorMsg) {

    char choice;
    char input[10];
    int valid = 0;
    int attempts = 0;
    
    while (!valid && attempts < MAX_INPUT_ATTEMPTS) {
        fgets(input, sizeof(input), stdin);
        
        if (input[0] == '\n' || input[0] == '\0') {
            printf(RED "Ah, the sound of silence...But don't worry, I won't tell anyone.. \n" RESET "Give it another go: ");
            attempts++;
            continue;
        }
        
        choice = toupper(input[0]);
        
        if (strchr(validChars, choice)) {
            valid = 1;
        } else {
            printf(RED "Nope. Not even close. '%c' wasn't invited to the party. %s\n" RESET, choice, errorMsg);
            attempts++;
        }
    }
    
    if (!valid) {
        int randIndex = rand() % strlen(validChars);
        choice = validChars[randIndex];
        printf(YELLOW "\nDecision-making not your strong suit? I'll choose '%c' for you.\n" RESET, choice);
        printf("Press ENTER to continue on your computer-guided journey to possible doom...");
        getchar();
    }
    
    return choice;
}


void generateRandomName(char* name) {
    const char* first[] = {
        "ChaiLover", "CodePagal", "Programmer", "ArchUser", "Disco", "Bullet",
        "Linkedin", "Failed", "Infinite", "Snake", "Sasta", "Paratha", 
        "Jotaro", "Statics", "Hitler", "Forgotten","Caffeine", "NullPointer", "DebugGod"
    };

    const char* last[] = {
        "Unemployment", "Error", "404", "Narcissistic", "Dancer", "Magnet",
        "Addict", "Experiment", "Looper", "Magnet", "Ishq", "Slayer",
        "Joestar", "Gambler", "Supporter", "One","Burnout", "Crybaby", "Dropout"
    };

    const char* firstName = first[rand() % (sizeof(first) / sizeof(first[0]))];
    const char* lastName  = last[rand() % (sizeof(last) / sizeof(last[0]))];

    sprintf(name, "%s_%s", firstName, lastName);
}

void processPlayerName(char* playerName) {
    int len = strlen(playerName);
    int identityModified = 0;
    if (strcasecmp(playerName, "admin") == 0) {
        printf(RED "\nOh no. 'Admin'? The illusion of power is... charming.\n" RESET);
        strncpy(playerName, "Powerless_One", NAME_LEN);
        identityModified = 1;
        } else if (strcasecmp(playerName, "death_himself") == 0) {
    printf(RED "\nNice try, impostor.\n" RESET);
    printf("'%s' is a sacred name ,Once whispered by survivors, never claimed.\n", playerName);
    printf("You are not Death_Himself. You're barely Alive_Probably... and clearly a fan of the legend.\n");
    strncpy(playerName, "Death_Fanboy", NAME_LEN);
    identityModified = 1;

    } else if (strcasecmp(playerName, "developer") == 0) {
        printf(MAGENTA "\nAh, the dev enters the chat. You break it, you buy it.\n" RESET);
        printf("Revoking your debug powers. You play like the rest.\n");
        strncpy(playerName, "CodeVictim", NAME_LEN);
        identityModified = 1;
    } else if (strcasecmp(playerName, "batman") == 0) {
        printf(YELLOW "\nBatman, huh? Tragic backstory won't stop the bullet.\n" RESET);
        strncpy(playerName, "Sad_Bruce", NAME_LEN);
        identityModified = 1;
    } else if (strcasecmp(playerName, "gigachad") == 0) {
        printf(GREEN "\nYou may lift, but can you dodge destiny?\n" RESET);
        strncpy(playerName, "GigaDead", NAME_LEN);
        identityModified = 1;
    } else if (strcasecmp(playerName, "player1") == 0) {
        printf(CYAN "\nAh yes, the messiah of mediocrity has arrived.\n" RESET);
        strncpy(playerName, "Totally_Unique", NAME_LEN);
        identityModified = 1;
    }

    if (identityModified) {
        printf(""BLUE"Your cursed identity: " CYAN "%s\n" RESET, playerName);
        printf(""GREEN"Press ENTER to continue your "BLUE"tragic destiny..."RESET"");
        while (getchar() != '\n');
        return;
    }

    if (len == 0) {
        generateRandomName(playerName);
        printf("  "BLUE"Using randomly generated name: " CYAN "%s\n" RESET, playerName);
        printf("  "WHITE"("RED"Silent type"WHITE","BLUE" huh? We gave your "WHITE"ghost"BLUE" a name."WHITE")"RESET"\n");
        identityModified = 1;
    }
    else if (isOnlyDigits(playerName)) {
        printf(YELLOW "\n'%s'? What is this, a license plate?\n" RESET, playerName);
        printf(""GREEN"Encoding you into something vaguely humanoid..."RESET"\n");
        char temp[NAME_LEN];
        snprintf(temp, NAME_LEN, "Prisoner_%s", playerName);
        strncpy(playerName, temp, NAME_LEN - 1);
        playerName[NAME_LEN - 1] = '\0';
        printf(""YELLOW"Your new inmate tag: " CYAN "%s\n" RESET, playerName);
        identityModified = 1;
    }
    else if (len > 20) {
        printf(YELLOW "\nWhoa there, %d characters? Your tombstone doesn't have that kind of space.\n" RESET, (int)len);
       printf(""GREEN"Display can't handle that ego. Shrinking it for safety...\n");
        playerName[20] = '\0';
        len = 20;
        printf(""BLUE"From now on, you're: " CYAN "%s\n" RESET, playerName);
        identityModified = 1;
    }
    for (int i = 0; i < len; i++) {
        char c = playerName[i];

        if (!isprint(c) || strchr("<>.&", c)) {
         printf(RED "\n"BLUE"Symbol '%c'? This isn't a coding contest, buddy.\n" RESET, c);
printf("Swapping it with '"RED"X"BLUE"' before the compiler cries..."RESET"\n");
            playerName[i] = 'X';
            identityModified = 1;
        } else if (c == ' ') {
            playerName[i] = '_';  
        }
    }

    if (identityModified) {
       printf(""GREEN"Press ENTER to proudly own this "BLUE"identity crisis..."RESET"\n");
        while (getchar() != '\n');
    }
}

char* MessageDisplayer(int situation, int round) {
    static char message[300];
    
    switch(situation) {
       case 0: { 
    const char* deaths[] = {
  "You died doing what you love: standing still and hoping for the best.",
"Guess dodging was optional, huh?",
"You had one job. You didnot do it.",
"Thanos saw that and whispered, \"Balanced, as all things should be.\"",
"You went full NPC and the bullet chose violence.",
"Game over, genius. Even a broken clock is right twice a day-too bad you were not one of those times."
    };
    strcpy(message, deaths[rand() % 6]);
    break;
}

     case 1: {
    const char* surviviMsg[] = {
     "You lived. Again. Even Death's starting to take it personally.",
"Congrats, you survived with pure vibes and mild facial confusion.",
"You just dodged a bullet using nothing but stubbornness and bad posture.",
"The chamber clicked... your brain didn't. Yet here you are.",
"You are somehow alive. The math department wants a word.",
"That was not survival. That was straight-up emotional damage to the gun."

    };
    strcpy(message, surviviMsg[rand() % 6]);
    break;
}

case 2:
        {
const char* starting[] = {
            "Your luck's faker than a Genjutsu. Time to wake up... permanently.",
            "Search history: \"win Russian Roulette\" 47 times. Spoiler: Nope.",
            "Congrats! You're the CEO of \"Bad Life Choices Inc.\"",
            "Your \"genius\" moment just turned into a headline disaster.",
            "If stupidity was lethal, you'd be a walking hazard sign.",
            "Congratulations! You're the star of \"How Not To Survive\".",
            "Fun fact: Everyone stops playing Russian Roulette. Eventually.",
            "All playing here was part of Azien's plan. Spoiler alert: your'e about to lose."     
};
            if (round > 10) {
                const char* upperRoundsMsg[] = {
                   "Round %d: You've outlived logic, reason, and basic math.",
                   "Round %d: You're basically cosplaying a Final Destination reject.",
                    "Round %d: You've officially outlived common sense.",
                    "Round %d: You and Death are in a very awkward staring contest.",
                    "Round %d: The gun is getting performance anxiety.",
                    "Round %d: You've become the tutorial boss of bad decisions."

                };
                sprintf(message, upperRoundsMsg[rand() % 6], round);
            } else {
                strcpy(message, starting[rand() % 8]);
            }
            break;
        }
        case 3:
        {
            const char* WinnerMsg[] = {
                "Your prize: Lifelong trust issues and a permanent spot on the FBI watchlist.",
                "Your survival story will make great prison conversation starter.",
                  "You've mastered the art of selective friendship termination. LinkedIn should add that skill!",
                "Breaking: Local psychopath wins murder lottery, more at 11.",
            "Hope your LinkedIn post gets likes - the ghosts of your friends are watching."
            };
            strcpy(message, WinnerMsg[rand() % 5]);
            break;
        }
        
    }
    
    return message;
}

