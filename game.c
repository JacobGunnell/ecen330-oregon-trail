#include "board7.h"

#define NUM_QUESTIONS 10

uint8_t question_num;

char* question[NUM_QUESTIONS];
char* answer1[NUM_QUESTIONS];
char* answer2[NUM_QUESTIONS];
char* answer3[NUM_QUESTIONS];
char* result1[NUM_QUESTIONS];
char* result2[NUM_QUESTIONS];
char* result3[NUM_QUESTIONS];

uint8_t result_num = 1;

void print_question(char* question, char* answer1, char* answer2, char* answer3){
    //FOR HYRUM
}

void print_result(char* result){
    //FOR HYRUM
}

enum game7_st_t {
	init_st,                 // Start here, transition out of this state on the first tick.
	question,
    result,
};
static enum game7_st_t currentState;

void game_tick() {  
  // Process state transitions first.
  switch(currentState) {
    case init_st:
        currentState=question;
        break;
    case question:

        break;
    case result:
      break;
    default:
      // print an error message here.
      break;
  }
  
  // Process state actions next.
  switch(currentState) {
    case init_st:
      break;
    case question:
        print_question(question[question_num],answer1[question_num],answer2[question_num],answer3[question_num]);
        break;
    case result:
        switch(result_num) {
            case 1:
                print_result(result1[question_num]);
                break;
            case 2:
                print_result(result2[question_num]);
                break;
            case 3:
                print_result(result3[question_num]);
                break;
        }
        break;
    default:
      // print an error message here.
        break;
  }  
}