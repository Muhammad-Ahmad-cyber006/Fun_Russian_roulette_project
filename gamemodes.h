#ifndef GAMEMODES_H
#define GAMEMODES_H

#define MAX_LEADERBOARD 15
#define LEADERBOARD_FILE "roulette_leaderboard.txt"
#define NAME_LEN 50  

struct LeaderboardEntry {
    char name[NAME_LEN];
    int money;
    int rounds;
    char status[10];

};

 extern struct LeaderboardEntry leaderboard[MAX_LEADERBOARD];
extern int leaderboardCount;
extern int playerHasPlayed;

void playSolo(int mode);
void playMultiplayer(int playerCount);
void showHallOfShame();
void showInstructions();

void loadLeaderboard();
void sortLeaderboard();
void saveLeaderboard();
void saveToLeaderboard(char* name, int money, int rounds, char* status);

#endif