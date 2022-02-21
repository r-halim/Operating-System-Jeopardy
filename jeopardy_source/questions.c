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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array

    
    for (int i=0; i<12; i++){

        // set all questions to unanswered
        questions[i].answered = false;

        // set categories for each question
        /*
        if(i%3==0){
            strcpy(questions[i].category, "programming");
        }
        
        else if (i%3==1){
            strcpy(questions[i].category, "algorithms");
        }

        else if (i%3==2){
            strcpy(questions[i].category, "databases");
        }

        */
    }

    // programming questions
    questions[0].value=200;
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "A data type of an ordered sequence of characters");
    strcpy(questions[0].answer, "string");

    questions[3].value=400;
    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "A control flow statement that allows code to be executed repeatedly based on a boolean condition");
    strcpy(questions[3].answer, "while loop");

    questions[6].value=600;
    strcpy(questions[6].category, "programming");
    strcpy(questions[6].question, "A special program that processes statements in a programming language and converts it to machine language");
    strcpy(questions[6].answer, "compiler");

    questions[9].value=800;
    strcpy(questions[9].category, "programming");
    strcpy(questions[9].question, "Linux was written in ___ Language");
    strcpy(questions[9].answer, "c");


    // algorithm questions
    questions[1].value=200;
    strcpy(questions[1].category, "algorithms");
    strcpy(questions[1].question, "The time complexity of hash maps");
    strcpy(questions[1].answer, "o(1)");

    questions[4].value=400;
    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "A data structure where elements are added or removed from the top in LIFO order");
    strcpy(questions[4].answer, "stack");

    questions[7].value=600;
    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "A tree in which the value in each internal node is greater or equal to the values in the children of that node");
    strcpy(questions[7].answer, "max heap");

    questions[10].value=800;
    strcpy(questions[10].category, "algorithms");
    strcpy(questions[10].question, "The type of algorithm that follows the problem-solving heuristic of making the locally optimal choice at each stage");
    strcpy(questions[10].answer, "greedy algorithm");


    // database questions
    questions[2].value=200;
    strcpy(questions[2].category, "databases");
    strcpy(questions[2].question, "The standard language for storing, manipulating, and retrieving data in databases");
    strcpy(questions[2].answer, "SQL");

    questions[5].value=400;
    strcpy(questions[5].category, "databases");
    strcpy(questions[5].question, "The SQL command to remove named schema elements, such as tables, domains, or constraint");
    strcpy(questions[5].answer, "drop");

    questions[8].value=600;
    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "Non-tabular databases that store data differently than relational tables");
    strcpy(questions[8].answer, "nosql");

    questions[11].value=800;
    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "The representational data model used most frequently in traditional commercial DBMSs");
    strcpy(questions[11].answer, "relational data model");


}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array

    int column_size = 15;


    // print categories
    for(int i=0; i < 3; i++){
        printf("%-*s", column_size, categories[i]);
    }

    for(int i=0; i < 12; i++){

        if(i % 3 == 0){
            printf("\n");
        }

        //print questions if not answered yet
        if(!questions[i].answered){
            printf("%-*d", column_size, questions[i].value);
        }

        else{
            printf("%-*s", column_size, " --- ");
        }

    }

    printf("\n");

}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

    for(int i=0; i < 12; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            printf("%s\n", questions[i].question);
        }
    }

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions

    for(int i = 0; i < 12; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            if(strcasecmp(questions[i].answer, answer)){
                questions[i].answered = true;

                return true;
            }

        }
    }

    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i=0; i<12; i++){
        if(strcmp(questions[i].category, category) && questions[i].value == value){
            if (questions[i].answered){
                printf("Question has already been answered");
                return true;
            }

            else {
                return false;
            }

        }


    }


    return false;
}
