/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <David Fung 100767734, Anish Patel 100751489, Raphaiel Halim 100700318>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
//void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
//void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    //Starting message
    printf("Welcome to Jeopardy!\n");

    // Prompt for players names and initialize each of the players in the array
    for(int i = 0; i < NUM_PLAYERS; i++){
         printf("Enter your name Player %d: ", (i+1));
         scanf("%s", players[i].name);

    //Sets score to 0
        players[i].score = 0; 
            
    }

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {

        //clears the command line
        system("clear");

        char chosenCategory[MAX_LEN] = "";
        char currentPlayer[MAX_LEN] = "";
        int questionValue;


        // Call functions from the questions and players source files

        //loop gets the current player
        while(!player_exists(players, 4, currentPlayer)){
            if(strcmp(currentPlayer, "") != 0) {
                printf("Player %s was not found.", currentPlayer);
            }
            //gets player 1s name since it was not found
            printf("Enter Player 1's Name: ");
            scanf("%s", (char *) &currentPlayer);
        }

        //Clears the screen and displays the categories
        system("clear");
        display_categories();


        //loop gets the chosen category
            do{
                if(questionValue != 0) {
                    printf("No Category chosen!");
                }
                printf("Enter a category: ");
                getchar();
                fgets((char*) chosenCategory, MAX_LEN, stdin);
                strtok(chosenCategory, "\n");

                printf("Enter a value: ");
                scanf("%d", (int *) &questionValue);
            } while(already_answered(chosenCategory,questionValue));

        //clears the display of categories and shows the question

        system("clear");
        display_question(chosenCategory, questionValue);

        char *answer[MAX_LEN] = {0};
        getchar();
        fgets((char *) answer, MAX_LEN, stdin);

        char *tokenize_answer;
        tokenize((char *) answer, &tokenize_answer);

        if(tokenize_answer == NULL){
            printf("Please try again and enter a valid answer.");
        } else if(valid_answer(chosenCategory, questionValue, tokenize_answer)) {
            printf("You are CORRECT!!");
            printf("Player %s gets %d points \n", currentPlayer, questionValue);
            update_score(players, 4, currentPlayer, questionValue);
        } else {
            printf("You are WRONG!!!");
            // print_answer(chosenCategory, questionValue);
        }

        show_results(players, 4);
        getchar();

    }
    return 0;
}



// tokenize function to get a valid answer
void tokenize(char *input, char **tokens) {
    const char delimiter = " ";

    char *stringTokens = strtok(input, delimiter);

    if (stringTokens != NULL){
        if (strcmp(stringTokens, "who") != 0 || strcmp(stringTokens, "what") != 0) {
            return;
        }
        if (strcmp(stringTokens, "is") != 0) {
            return;
        }
    }

    *stringTokens = strtok(NULL, delimiter);
}


//Gets the results and exits successfully
void show_results(player *players, int numPlayers) {
    int playerName = 0;
    int playerScore = 0;
    int winner = 0;

    for(int i = 0; i < numPlayers; i++) {
        if((int) strlen(players[i].name) > playerName)
            playerName = strlen(players[i].name);

        if(players[i].score > playerScore) {
            playerScore = players[i].score;
            winner = i;
        }
    }

    // prints the final scores of players
    printf("The final scores are: \n");
    for(int i = 0; i < numPlayers; i++)
        printf("%*s: %d\n", playerName + 1, players[i].name, players[i].score);

    printf("The winner is: %s", players[winner].name);
    printf("Congrats!!!");

    return EXIT_SUCCESS;
}
