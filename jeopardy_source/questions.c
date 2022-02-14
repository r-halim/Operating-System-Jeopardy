/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
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
        if(i%3==0){
            strcpy(question[i].category, "programming");
        }
        
        else if (i%3==1){
            strcpy(question[i].category, "algorithms");
        }

        else if (i%3==2){
            strcpy(question[i].category, "databases");
        }
    }

    // programming questions
    questions[0].value=200;
    strcpy(questions[0].question, "A data type of an ordered sequence of characters");
    strcpy(questons[0].question, "string");

    questions[3].value=400;
    strcpy(questions[3].question, "A control flow statement that allows code to be executed repeatedly based on a boolean condition");
    strcpy(questons[3].question, "while loop");

    questions[6].value=600;
    strcpy(questions[6].question, "A special program that processes statements in a programming language and converts it to machine language");
    strcpy(questons[6].question, "compiler");

    questions[0].value=800;
    strcpy(questions[0].question, "");
    strcpy(questons[0].question, "");


}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
