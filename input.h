#ifndef INPUT_H
#define INPUT_H

#define MAX_PLAYERS 6
#define NAME_LEN 50

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_ATTEMPTS 3
int getValidInt(int min, int max, const char* errorMsg);
char getCharChoice(const char* validChars, const char* errorMsg);
int isOnlyDigits(const char* str);
char* MessageDisplayer(int situation, int round);
void processPlayerName(char* playerName);
void generateRandomName(char* name) ;
#endif