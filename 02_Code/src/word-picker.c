//
// Author: Neil Devlin
// Version 2.0
//

#include <stdio.h>
#include <sqlite3.h> 
#include <ctype.h> 
#include <string.h> 
#include <time.h> 
#include <stdlib.h>
#include<windows.h>
#include<unistd.h>


// Global variables
int GLOBAL_MAX_TURNS = 5;
int GLOBAL_ARRAY_NUMBERS_USED[] = {};

// 
// Args: the current turn (integer)
// Returns: the random number (integer)
// Description: Propt the user to play, if the yes selects y then it will call other functions
//
int getRandomNr(int LOCAL_CURRENT_TURN1 ) {
   int LOCAL_RANDOM_NR;
   int LOCAL_COUNTER = 0;
   char *LOCAL_FOUND_NUMBER = "false";
   char *LOCAL_NUMBER_USED = "false";
   
   // Elements in the array start at 0, therefore we need to decrease this 
   int  LOCAL_ELEMENT_IN_ARRAY = LOCAL_CURRENT_TURN1 - 1;

   // Loop for as long as no unused number has been found
   while(strcmp(LOCAL_FOUND_NUMBER, "false") == 0 ) {
      // reset some variables
      LOCAL_RANDOM_NR = 99;
	  LOCAL_NUMBER_USED = "false";

	  // Generate a seed for the random number
	  time_t LOCAL_PTR_TIME;
	  srand( (unsigned) time(&LOCAL_PTR_TIME));
	  
	  // pick a random and add 1 to it so it is not 0
      LOCAL_RANDOM_NR = rand() % GLOBAL_MAX_TURNS + 1;
	  
	  // Loop through the array & check if the number has already been used
	  for ( LOCAL_COUNTER=0; LOCAL_COUNTER < LOCAL_ELEMENT_IN_ARRAY; LOCAL_COUNTER++) {
		  if ( LOCAL_RANDOM_NR == GLOBAL_ARRAY_NUMBERS_USED[LOCAL_COUNTER] ) {
			  // If it has already been used (in the array), then set this flag
			  LOCAL_NUMBER_USED = "true";
	  		  // fprintf(stdout, "GR1-ALREADY-USED: Array position: %d, id=%d\n", LOCAL_COUNTER, GLOBAL_ARRAY_NUMBERS_USED[LOCAL_COUNTER]);
			  sleep(5);
		  }
	  }
	  // Check if the flag has been set
	  if ( strcmp(LOCAL_NUMBER_USED, "false" ) == 0 ) {
		  // the flag was not set, therefore the number has not been used i.e. found
		  LOCAL_FOUND_NUMBER = "true";
	  }
   }
   // Append the array with the newly found number   
   GLOBAL_ARRAY_NUMBERS_USED[LOCAL_ELEMENT_IN_ARRAY] = LOCAL_RANDOM_NR;

   // Return this value
   return LOCAL_RANDOM_NR;
}

void getWord( ) {
   	fprintf(stdout, "Random word is boo! \n");
}

// 
// Args: none
// Returns: none
// Description: Prompt the user to play, if the answer is yes then it will call other functions
//
void pickWord( ) {
   char *LOCAL_END_GAME = "false";
   char LOCAL_ARRAY_USER_INPUT[30];
   int LOCAL_CURRENT_TURN = 1;
   int LOCAL_RANDOM_NUMBER;
   int LOCAL_ELEMENT_IN_ARRAY;

   // Do a while loop as long as the LOCAL_END_GAME is false and the GLOBAL_MAX_TURNS is not exceeded
   // 
   while ( LOCAL_CURRENT_TURN <= GLOBAL_MAX_TURNS && strcmp(LOCAL_END_GAME, "false") == 0 ) {

      // Ask user if they want word, select only the first letter of their response
	  fprintf(stdout, "Would you like to pick a word (y/n):");
	  scanf("%1s", LOCAL_ARRAY_USER_INPUT);
	  
	  // Convert the users reply into lowercase
	  LOCAL_ARRAY_USER_INPUT[0] = tolower(LOCAL_ARRAY_USER_INPUT[0]);
	  
	  // Check if it is "y"
	  if ( strcmp(LOCAL_ARRAY_USER_INPUT, "y") != 0 ) {
	     // answer was not y, therefore end the game, decrease the number of turns taken
	     LOCAL_END_GAME = "true";
 		 LOCAL_CURRENT_TURN--;
	  }
      else {
		 // answer was y, therefore play the game & increment the number turns taken
	     LOCAL_RANDOM_NUMBER = getRandomNr(LOCAL_CURRENT_TURN);
 		 fprintf(stdout, "Round: %d, id=%d\n", LOCAL_CURRENT_TURN,  LOCAL_RANDOM_NUMBER );

		 getWord();
		 LOCAL_CURRENT_TURN++;
      }
   }
   
   // The while loop has ended, evaluate the reason why it ended
   if ( LOCAL_CURRENT_TURN > GLOBAL_MAX_TURNS ) {
	  fprintf(stdout, "You have selected the maximum number of words (%d) possible, thanks for playing\n", GLOBAL_MAX_TURNS);
   }
   else {
 	  fprintf(stdout, "You have selected %d out of %d words, thanks for playing\n", LOCAL_CURRENT_TURN, GLOBAL_MAX_TURNS);
   }
}

//
// Args: none
// Return: none
//
void main( ) {
   
   pickWord();
   
}

