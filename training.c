#include "training.h"
#include "design.h"
#include "input.h"
#include <stdio.h>
#include <time.h>
#include<math.h>
#include <unistd.h>
#include <windows.h> 

void probabilityCalculator() {
    while (1) {
    clearScreen();
    printf("\n" CYAN "\t\t\t\t+================================================================+");
    printf("\n\t\t\t\t|                    PROBABILITY CALCULATOR                      |");
    printf("\n\t\t\t\t|                  (Learn the Math of Death)                     |");
    printf("\n\t\t\t\t+================================================================+\n" RESET);
    
    printf(YELLOW "\nWelcome to Probability Boot Camp!\n" RESET);
    printf("Here you'll learn why math is scarier than the gun itself.\n\n");
    
        printf(GREEN "\n=================== PROBABILITY LESSON ===================\n" RESET);
        printf("Enter number of bullets in gun (1-6, or 0 to return): ");
        
        int bullets = getValidInt(0, 6, "0-6 only! Even death follows rules!");
        
        if (bullets == 0) {
            printf(CYAN "\nReturning to main menu... Armed with knowledge!\n" RESET);
            printf("Press ENTER to continue...");
        while (getchar() != '\n');
            return;
        }
     
        double deathChance = (double)bullets / 6.0 * 100.0;
        double survivalChance = 100.0 - deathChance;
        double surviveNRounds = pow(survivalChance / 100.0, 5);
        
        printf("\n" RED "================= MATHEMATICAL REALITY =================\n" RESET);
        printf(RED "Death probability this round: %.2f%%\n" RESET, deathChance);
        printf(GREEN "Survival probability: %.2f%%\n" RESET, survivalChance);
        
        printf("\n" MAGENTA "============== EXTENDED SURVIVAL ANALYSIS ==============\n" RESET);
        for (int rounds = 1; rounds <= 10; rounds++) {
            double surviveNRounds = pow(survivalChance / 100.0, rounds);
            printf("Survive %2d rounds: " CYAN "%.4f%%" RESET " (1 in %.0f chance)\n", rounds, surviveNRounds * 100, 1.0 / surviveNRounds);
        }
        
        printf("\n" RED "================== HARSH REALITY CHECK =================\n" RESET);
        if (bullets == 1) {
            printf("16.67%% death rate - Russian Roulette for beginners\n");
        } else if (bullets == 2) {
            printf("33.33%% death rate - Feeling lucky, punk?\n");
        } else if (bullets == 3) {
            printf("50.00%% death rate - Coin flip with your life\n");
        } else if (bullets == 4) {
            printf("66.67%% death rate - Math says you're probably dead\n");
        } else if (bullets == 5) {
            printf("83.33%% death rate - Suicide with extra steps\n");
        } else if (bullets == 6) {
            printf("100.00%% death rate - That's not roulette, that's just murder\n");
        }
        
        printf("\n" YELLOW "Fun Fact: " RESET);
        if (bullets <= 2) {
            printf("You have better odds of surviving this than passing your next exam!\n");
        } else if (bullets <= 4) {
            printf("Your smartphone has better survival odds than you do!\n");
        } else {
            printf("Even your browser has better uptime than your life expectancy here!\n");
        }
        
        printf("\nPress ENTER for another calculation (or to question your life choices)...");
        while (getchar() != '\n');
    }
}

void reactionTraining() {
    clearScreen();
    printf("\n" RED "+================================================================+");
    printf("\n|                      REACTION TRAINING                         |");
    printf("\n|                (Speed vs. Stupidity Test)                      |");
    printf("\n+================================================================+\n" RESET);
    
    printf(YELLOW "\nWelcome to Reaction Training!\n" RESET);
    printf("Here we test if your reflexes are faster than your bad decisions.\n\n");
           printf("Warm up those fingers. You will need them. Press ENTER to begin.\n");
while (getchar() != '\n');
    
    int round = 1;
    double totalTime = 0;
    int correct = 0;
    while (round <= 5) {
        clearScreen();
            printf("\n" RED "+================================================================+");
    printf("\n|                      REACTION TRAINING                         |");
    printf("\n|                (Speed vs. Stupidity Test)                      |");
    printf("\n+================================================================+\n" RESET);
    switch (round) {
    case 1:
        printf(YELLOW "\nRound 1: Let's begin!\n" RESET);
        printf("Try not to embarrass yourself too early.\n\n");
        break;
    case 2:
        printf(YELLOW "\nStill here, huh?\n" RESET);
        printf("Maybe you will do better this time. But we doubt it.\n\n");
        break;
    case 3:
        printf(YELLOW "\nHalfway through!\n" RESET);
        printf("Statistically, this is when things fall apart.\n\n");
        break;
    case 4:
        printf(YELLOW "\nBack again?\n" RESET);
        printf("Bold move. Let's see if it pays off.\n\n");
        break;
    case 5:
        printf(YELLOW "\nFinal round!\n" RESET);
        printf("Time to redeem all those poor choices.. or not.\n\n");
        break;
}

        printf(GREEN "\n================= ROUND %d/5 =================\n" RESET, round);
        printf("I'll show you a scenario. React as fast as possible!\n");
        printf("Press ENTER when ready...");
        while (getchar() != '\n');
        
   
        const char* scenarios[] = {
            "REVOLVER CYLINDER SPINNING - Take Shot or Pass Turn?",
            "OPPONENT'S GUN MISFIRED - Grab Weapon or Run Away?", 
            "BULLET CHAMBER VISIBLE - Pull Trigger or Skip Round?",
            "LAST ROUND LOADED - Fire Now or Forfeit Game?",
            "ENEMY HESITATING - Attack First or Wait Patiently?",
            "CHAMBER CLICKING EMPTY - Continue Playing or Quit Immediately?",
            "DEALER OFFERING TRADE - Accept Deal or Keep Position?",
            "CROWD CHANTING YOUR NAME - Show Off or Play Safe?",
            "HANDS SHAKING BADLY - Push Through or Take Break?",
            "LUCKY STREAK CONTINUES - Press Advantage or Cash Out?",
            "OPPONENT SWEATING NERVOUSLY - Intimidate Further or Back Down?",
            "FINAL CHAMBER REMAINING - Risk Everything or Walk Away?"
        };
        
        int scenario_index = rand() % 12;
        printf("\n" RED "SCENARIO: %s\n" RESET, scenarios[scenario_index]);
        

        const char* choice1_labels[] = {
            "Take Shot", "Grab Weapon", "Pull Trigger", "Fire Now", "Attack First",
            "Continue Playing", "Accept Deal", "Show Off", "Push Through", 
            "Press Advantage", "Intimidate Further", "Risk Everything"
        };
        
        const char* choice2_labels[] = {
            "Pass Turn", "Run Away", "Skip Round", "Forfeit Game", "Wait Patiently",
            "Quit Immediately", "Keep Position", "Play Safe", "Take Break",
            "Cash Out", "Back Down", "Walk Away"
        };
        
        printf(RED "[1] " RESET "%s (DANGEROUS/GUTSY)\n", choice1_labels[scenario_index]);
        printf(GREEN "[2] " RESET "%s (SAFE/CAUTIOUS)\n", choice2_labels[scenario_index]);
        printf(CYAN "Enter your choice (1 or 2): " RESET);
        

        clock_t start = clock();
        
        char response = getValidInt(1,2, "1 or 2 only! Your indecision is showing!");

        clock_t end = clock();
        double reactionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        totalTime += reactionTime;
        
        int isCorrect;
        if (response == 1) {
            isCorrect = (rand() % 3 != 0) ? 1 : 0; 
            if (isCorrect) {
                printf(RED "\n BOLD MOVE! " RESET "Risk paid off this time!\n");
            } else {
                printf(RED "\n TOO RECKLESS! " RESET "Your gutsy choice backfired!\n");
            }
        } else {
            isCorrect = (rand() % 4 != 0) ? 1 : 0; 
            if (isCorrect) {
                printf(GREEN "\n SMART CHOICE! " RESET "Safety first approach worked!\n");
            } else {
                printf(YELLOW "\n TOO CAUTIOUS! " RESET "Sometimes you need to take risks!\n");
            }
        }
        
        if (isCorrect) correct++;
        
        printf("Reaction time: " CYAN "%.3f seconds\n" RESET, reactionTime);
        
        if (reactionTime < 0.5) {
            printf(YELLOW "Lightning fast! Your reflexes are sharper than your judgment!\n" RESET);
        } else if (reactionTime < 1.0) {
            printf(GREEN "Good speed! You might actually survive... maybe.\n" RESET);
        } else if (reactionTime < 2.0) {
            printf(MAGENTA "Decent reaction time. Not great, not terrible.\n" RESET);
        } else {
            printf(RED "Slow as molasses! Death will arrive before your decision!\n" RESET);
        }
        
        round++;
        printf("\nPress ENTER for next round...");
        while (getchar() != '\n');
    }
    clearScreen();
    printf("\n" RED "+================================================================+");
    printf("\n|                      REACTION TRAINING                         |");
    printf("\n|                (Speed vs. Stupidity Test)                      |");
    printf("\n+================================================================+\n" RESET);
    
    double avgTime = totalTime / 5.0;
    printf("\n" BLUE "================== FINAL RESULTS ==================\n" RESET);
    printf("Correct decisions: " GREEN "%d/5\n" RESET, correct);
    printf("Average reaction time: " CYAN "%.3f seconds\n" RESET, avgTime);
    printf("Accuracy: " YELLOW "%.1f%%\n" RESET, (correct / 5.0) * 100);
    
    printf("\n" MAGENTA "================ PERFORMANCE ANALYSIS ================\n" RESET);
    if (correct >= 4 && avgTime < 1.0) {
        printf(GREEN "EXCELLENT! You're a natural-born survivor with perfect timing!\n" RESET);
    } else if (correct >= 3 && avgTime < 1.5) {
        printf(YELLOW "GOOD! You balance risk and caution like a true player!\n" RESET);
    } else if (correct >= 2) {
        printf(MAGENTA "AVERAGE! Your survival depends on pure luck!\n" RESET);
    } else {
        printf(RED "POOR! Natural selection has marked you for elimination!\n" RESET);
    }
    
    printf("\nPress ENTER to return to main menu...");
        while (getchar() != '\n');
}


void courageTest() {
    clearScreen();
    printf("\n" MAGENTA "+================================================================+");
    printf("\n|                        COURAGE TEST                            |");
    printf("\n|                  (Face Your Fears, Coward)                     |");
    printf("\n+================================================================+\n" RESET);
    
    printf(YELLOW "\nWelcome to the Courage Test!\n" RESET);
    printf("We'll see if you have the guts to face digital death.\n\n");
    
    int courageScore = 0;
    int maxScore = 0;
    
    printf(GREEN "================= TEST 1: BASIC FEAR =================\n" RESET);
    printf("Imagine you're holding a loaded gun with " RED "5 bullets" RESET ".\n");
    printf("Your finger is on the trigger. Your heart is pounding.\n");
    printf("What do you do?\n\n");
    printf("A) Pull the trigger immediately\n");
    printf("B) Think about it for a moment\n");
    printf("C) Put the gun down and walk away\n");
    printf("D) Start crying uncontrollably\n\n");
    printf("Your choice (A-D): ");
    
    char choice1 = getCharChoice("ABCD", "A, B, C, or D! Fear is making you illiterate!");
    maxScore += 3;
    
    switch(choice1) {
        case 'A':
            printf(RED "\nPure recklessness! +3 courage points (and -100 intelligence)\n" RESET);
            courageScore += 3;
            break;
        case 'B':
            printf(YELLOW "\nCalculated bravery! +2 courage points\n" RESET);
            courageScore += 2;
            break;
        case 'C':
            printf(GREEN "\nWisdom over courage! +1 courage point\n" RESET);
            courageScore += 1;
            break;
        case 'D':
            printf(CYAN "\nHonest coward! +0 courage points but full marks for honesty!\n" RESET);
            break;
    }
  
    printf(GREEN "\n================= TEST 2: PEER PRESSURE =================\n" RESET);
    printf("Your friends are watching. They're calling you a coward.\n");
    printf("The gun has " RED "3 bullets" RESET ". Everyone's staring.\n");
    printf("Social media is recording. Your reputation is at stake.\n\n");
    printf("A) Show them who's boss - pull the trigger\n");
    printf("B) Make a joke and deflect\n");
    printf("C) Tell them this is stupid and leave\n");
    printf("D) Suggest playing video games instead\n\n");
    printf("Your choice (A-D): ");
    
    char choice2 = getCharChoice("ABCD", "Social pressure got you confused? A-D only!");
    maxScore += 3;
    
    switch(choice2) {
        case 'A':
            printf(RED "\nDangerous bravado! +3 courage, -1000 brain cells\n" RESET);
            courageScore += 3;
            break;
        case 'B':
            printf(YELLOW "\nClever deflection! +2 courage points\n" RESET);
            courageScore += 2;
            break;
        case 'C':
            printf(GREEN "\nTrue courage! Standing up to peer pressure! +3 courage points!\n" RESET);
            courageScore += 3;
            break;
        case 'D':
            printf(CYAN "\nPacifist approach! +1 courage point for trying\n" RESET);
            courageScore += 1;
            break;
    }
    
   
    printf(GREEN "\n================= TEST 3: THE FINAL MOMENT =================\n" RESET);
    printf("It's down to you and one other person.\n");
    printf("There's " RED "1 bullet" RESET " left in 6 chambers.\n");
    printf("It's your turn. Everyone's silent.\n");
    printf("Time slows down. This is it.\n\n");
    printf("A) Pull the trigger without hesitation\n");
    printf("B) Take a deep breath, then pull\n");
    printf("C) Offer to split any winnings and both walk away\n");
    printf("D) Admit you're too scared to continue\n\n");
    printf("Your final choice (A-D): ");
    
    char choice3 = getCharChoice("ABCD", "Final moment and you're confused? A-D!");
    maxScore += 4;
    
    switch(choice3) {
        case 'A':
            printf(RED "\nIce-cold courage! +4 courage points!\n" RESET);
            courageScore += 4;
            break;
        case 'B':
            printf(YELLOW "\nControlled bravery! +3 courage points!\n" RESET);
            courageScore += 3;
            break;
        case 'C':
            printf(GREEN "\nMoral courage! The hardest kind! +4 courage points!\n" RESET);
            courageScore += 4;
            break;
        case 'D':
            printf(CYAN "\nHonest self-awareness! +2 courage points!\n" RESET);
            courageScore += 2;
            break;
    }

    printf("\n" BLUE "================== COURAGE ANALYSIS ==================\n" RESET);
    printf("Your courage score: " CYAN "%d/%d\n" RESET, courageScore, maxScore);
    double percentage = ((double)courageScore / maxScore) * 100;
    printf("Courage percentage: " YELLOW "%.1f%%\n" RESET, percentage);
    
    printf("\n" MAGENTA "================ COURAGE EVALUATION ================\n" RESET);
    if (percentage >= 90) {
        printf(RED "FEARLESS WARRIOR! You fear nothing... which is terrifying!\n" RESET);
    } else if (percentage >= 70) {
        printf(GREEN "BRAVE SOUL! You've got guts, but hopefully some brains too!\n" RESET);
    } else if (percentage >= 50) {
        printf(YELLOW "AVERAGE COURAGE! You're human, which is perfectly fine!\n" RESET);
    } else if (percentage >= 30) {
        printf(CYAN "CAUTIOUS TYPE! Your survival instincts work properly!\n" RESET);
    } else {
        printf(MAGENTA "WISE COWARD! Cowardice has kept humanity alive for millennia!\n" RESET);
    }
    
    printf("\nPress ENTER to return to main menu...");
        while (getchar() != '\n');
}


void meditationMode() {
    clearScreen();
    printf("\n" CYAN "+================================================================+");
    printf("\n|                      MEDITATION MODE                           |");
    printf("\n|                    (Calm Your Nerves)                          |");
    printf("\n+================================================================+\n" RESET);
    
    printf(YELLOW "\nWelcome to Digital Zen!\n" RESET);
    printf("Let's find your inner peace before you potentially lose your outer life.\n\n");
    
    printf("Choose your meditation session:\n");
    printf(GREEN "1." RESET " Quick Breathing (1 minute)\n");
    printf(BLUE "2." RESET " Mindfulness Session (2 minutes)\n");
    printf(MAGENTA "3." RESET " Fear Confrontation (3 minutes)\n");
    printf(RED "4." RESET " Death Acceptance (5 minutes)\n");
    printf(WHITE "5." RESET " Return to main menu\n\n");
    
    printf("Choose your path to enlightenment (1-5): ");
    int choice = getValidInt(1, 5, "1-5 only! Even meditation has rules!");
    
    switch(choice) {
        case 1: {
            printf("\n" GREEN "================ BREATHING EXERCISE ================\n" RESET);
            printf("Follow the breathing pattern. In... and out...\n");
            printf("This will take exactly 1 minute (60 seconds)...\n\n");
            
          
            for(int cycle = 1; cycle <= 4; cycle++) {
                printf(CYAN "Cycle %d/4:\n" RESET, cycle);
           
                printf(GREEN "Breathe IN... " RESET);
                for(int i = 0; i < 4; i++) {
                    printf("O ");
                    fflush(stdout);
                    Beep(528, 300);  
                    Sleep(1000);     
                }
                
                printf(BLUE "\nHold... " RESET);
                for(int i = 0; i < 4; i++) {
                    printf("- ");
                    fflush(stdout);
                    Beep(440, 200); 
                    Sleep(1000);   
                }
                
                printf(YELLOW "\nBreathe OUT..." RESET);
                for(int i = 0; i < 7; i++) {
                    printf("o ");
                    fflush(stdout);
                    Beep(396, 200);  
                    Sleep(1000);    
                }
                printf("\n\n");
             
            }
            
            printf(GREEN "Breathing complete! You're now 0.01%% calmer!\n" RESET);
            break;
        }
        
        case 2: {
            printf("\n" BLUE "================ MINDFULNESS SESSION ================\n" RESET);
            printf("Close your eyes and focus on the present moment...\n");
            printf("Notice your thoughts without judgment...\n");
            printf("This will take exactly 2 minutes (120 seconds)...\n\n");
            
            const char* mindfullMsg[] = {
                "Feel your feet on the ground...",
                "Notice the air entering your lungs...",
                "Acknowledge any fear without resistance...",
                "Your heartbeat is the rhythm of life...",
                "Thoughts come and go like clouds...",
                "You are more than your fears..."
            };
            
         
            for(int i = 0; i < 6; i++) {
                printf(CYAN "%s\n" RESET, mindfullMsg[i]);
                
  
                Beep(852, 300);  
                Sleep(500);
                
                printf("(Reflecting for 20 seconds...)\n");
                for(int j = 0; j < 20; j++) {
                    printf(". ");
                    fflush(stdout);
                    Sleep(1000); 
                    
                 
                    if(j == 9 || j == 19) {
                        Beep(639, 200); 
                    }
                }
                printf("\n");
                
                if(i < 5) {
                    printf(YELLOW "Continue with next reflection? (Y/N): " RESET);
                    char continueChoice = getCharChoice("YN", "Y or N only! Indecision defeats mindfulness!");
                    
                    if(continueChoice == 'N') {
                        printf(RED "\nGiving up already? Your attention span is shorter than a goldfish! :-P\n" RESET);
                        printf(CYAN "Well... at least you tried. That's... something, I guess.\n" RESET);
                        printf("Press ENTER to return...");
                        while (getchar() != '\n');
                        return;
                    } else {
                        printf(GREEN "\nExcellent! Your persistence is growing stronger! ^_^\n" RESET);
                        printf(BLUE "The path to enlightenment requires dedication!\n\n" RESET);
                        Beep(741, 400); 
                    }
                }
            }
            
            
            printf(BLUE "Mindfulness complete! Your inner wisdom has increased by 0.05%%!\n" RESET);
            printf(GREEN "    /\\_/\\  \n" RESET);
            printf(GREEN "   ( o.o ) Congratulations, grasshopper!\n" RESET);
            printf(GREEN "    > ^ <  \n" RESET);
            
            Beep(523, 300);
            Sleep(200);
            Beep(659, 300);
            Sleep(200);
            Beep(784, 500);
            break;
        }
        
        case 3: {
            printf("\n" MAGENTA "================ FEAR CONFRONTATION ================\n" RESET);
            printf("Let's face your fears directly...\n");
            printf("This will take exactly 3 minutes (180 seconds)...\n\n");
            
            const char* fears[] = {
                "The fear of death is natural...",
                "What would you do if you knew you couldn't fail?",
                "Fear is just excitement without breath...",
                "You've survived 100% of your worst days so far...",
                "Courage isn't the absence of fear...",
                "What's the worst that could REALLY happen?",
                "Death gives life meaning...",
                "You are braver than you believe...",
                "Fear is a compass pointing to what matters..."
            };
            
           
            for(int i = 0; i < 9; i++) {
                printf(YELLOW "Confrontation %d/9:\n" RESET, i+1);
                printf(WHITE "%s\n" RESET, fears[i]);
                
               
                Beep(330, 400);  
                Sleep(300);
                Beep(392, 300);  
                Sleep(200);
                
                printf("(Sit with this thought for 20 seconds...)\n");
                for(int j = 0; j < 20; j++) {
                    printf("~ ");
                    fflush(stdout);
                    Sleep(1000); 
                    
                
                    if(j == 9 || j == 19) {
                        Beep(440 + (j * 2), 150); 
                    }
                }
                printf("\n");
                
                if(i < 8) {
                    printf(YELLOW "Ready for the next fear? (Y/N): " RESET);
                    char continueChoice = getCharChoice("YN", "Y or N only! Fear doesn't accept maybe!");
                    
                    if(continueChoice == 'N') {
                        printf(RED "\nRunning away from your fears? How... predictable! >:(\n" RESET);
                        printf(MAGENTA "At least you faced " RESET);
                        printf(CYAN "%d" RESET, i+1);
                        printf(MAGENTA " fear(s). Baby steps, right?\n" RESET);
                        printf("Press ENTER to return...");
                        while (getchar() != '\n');
                        return;
                    } else {
                        printf(GREEN "\nBrave soul! You're growing stronger with each fear faced! :)\n" RESET);
                        printf(YELLOW "Courage is built one fear at a time!\n\n" RESET);
                    
                        Beep(523, 300);
                        Sleep(100);
                        Beep(659, 400);
                    }
                }
            }
            
            
            printf(MAGENTA "Fear confrontation complete! You're now 2%% more courageous!\n" RESET);
            printf(RED "    ^   ^\n" RESET);
            printf(RED "   (0) (0)  Fear Conqueror!\n" RESET);
            printf(RED "      >\n" RESET);
            
           
            Beep(523, 200);
            Sleep(100);
            Beep(659, 200);
            Sleep(100);
            Beep(784, 200);
            Sleep(100);
            Beep(1047, 500);
            break;
        }
        
        case 4: {
            printf("\n" RED "================ DEATH ACCEPTANCE ================\n" RESET);
            printf("The ultimate meditation... accepting mortality...\n");
            printf("This will take exactly 5 minutes (300 seconds)...\n\n");
            
            printf(WHITE "This is a deep session. Are you ready? (Y/N): " RESET);
            char ready = getCharChoice("YN", "Y or N only! Death doesn't accept maybe!");
            
            if(ready == 'N') {
                printf(CYAN "\nWisdom in knowing your limits. Returning to menu...\n" RESET);
                printf("Press ENTER to continue...");
                while (getchar() != '\n');
                return;
            }
            
            const char* deathReflections[] = {
                "All things must pass...",
                "Death is not the opposite of life, but part of it...",
                "What legacy will you leave?",
                "Every ending is also a beginning...",
                "You are stardust contemplating stars..."
            };
            
           
            for(int i = 0; i < 5; i++) {
                printf(MAGENTA "Reflection %d/5:\n" RESET, i+1);
                printf(WHITE "%s\n" RESET, deathReflections[i]);
                
        
                Beep(256, 600);  
                Sleep(400);
                Beep(288, 400);  
                
                printf("(Deep contemplation for 60 seconds...)\n");
                for(int j = 0; j < 60; j++) {
                    printf("+ ");
                    fflush(stdout);
                    Sleep(1000); 
                    
            
                    if(j == 19 || j == 39 || j == 59) {
                        Beep(432, 250); 
                    }
                }
                printf("\n");
                
                if(i < 4) {
                    printf(YELLOW "Continue this profound journey? (Y/N): " RESET);
                    char continueChoice = getCharChoice("YN", "Y or N only! Even death requires commitment!");
                    
                    if(continueChoice == 'N') {
                        printf(RED "\nToo deep for you, eh? Death is the ultimate commitment-phobe's nightmare! X_X\n" RESET);
                        printf(YELLOW "You managed " RESET);
                        printf(CYAN "%d" RESET, i+1);
                        printf(YELLOW " reflection(s). Not bad for a mortal!\n" RESET);
                        printf("Press ENTER to return to the land of the living...");
                        while (getchar() != '\n');
                        return;
                    } else {
                        printf(GREEN "\nYour spiritual strength is remarkable! You face the ultimate truth! :D\n" RESET);
                        printf(MAGENTA "Each reflection brings you closer to enlightenment!\n\n" RESET);
                 
                        Beep(396, 300);
                        Sleep(200);
                        Beep(528, 400);
                    }
                }
            }
       
            
            printf(RED "Death acceptance meditation complete.\n" RESET);
            printf(YELLOW "You have achieved 5%% more inner peace!\n" RESET);
            printf(GREEN "Congratulations on facing the ultimate truth!\n" RESET);
            printf(WHITE "       ___\n" RESET);
            printf(WHITE "      (o o)   Enlightened One!\n" RESET);
            printf(WHITE "   ooO-(_)-Ooo\n" RESET);
            
            Beep(256, 300);
            Sleep(200);
            Beep(288, 300);
            Sleep(200);
            Beep(324, 300);
            Sleep(200);
            Beep(432, 300);
            Sleep(200);
            Beep(528, 800); 
            break;
        }
        
        case 5:
            return;
    }
    
    printf("\n" CYAN "================ MEDITATION COMPLETE ================\n" RESET);
    printf("Remember: A calm mind makes better decisions!\n");
    printf("May your newfound peace serve you well in digital combat!\n");
    printf("\nPress ENTER to return to main menu...");
    while (getchar() != '\n');
}


void showTrainingMenu() {
    while(1) {
        clearScreen();
        showWelcomeScreen();
        
        printf("\n\n" YELLOW "\t\t\t\t+================================================================+");
        printf("\n\t\t\t\t|                      TRAINING MODES                            |");
        printf("\n\t\t\t\t|                 (Prepare for Digital Death)                    |");
        printf("\n\t\t\t\t+================================================================+\n" RESET);
        
        printf(GREEN "\t\t\t\t1." RESET " Probability Calculator - Learn the math of doom\n");
        printf(BLUE "\t\t\t\t2." RESET " Reaction Training - Speed vs. stupidity test\n");
        printf(MAGENTA "\t\t\t\t3." RESET " Courage Test - Face your fears (digitally)\n");
        printf(CYAN "\t\t\t\t4." RESET " Meditation Mode - Calm your nerves before dying\n");
        printf(WHITE "\t\t\t\t5." RESET " Return to Main Menu\n");
        
        printf("\n\t\t\t\tChoose your training (1-5): ");
        
        int choice = getValidInt(1, 5, "1-5 only! Training requires basic counting!");
        
        switch(choice) {
            case 1:
                probabilityCalculator();
                break;
            case 2:
                reactionTraining();
                break;
            case 3:
                courageTest();
                break;
            case 4:
                meditationMode();
                break;
            case 5:
                return;
        }
    }
}

