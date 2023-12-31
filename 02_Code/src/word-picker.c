//
// Author: Neil Devlin
// Version 1.0
//

#include <stdio.h>
#include <sqlite3.h> 
#include <ctype.h> 
#include <string.h> 

// Global variables
int GLOBAL_MAX_TURNS = 5;


void getRandomNr( ) {
   	fprintf(stdout, "Random Nr is 1\n");
}

void getWord( ) {
   	fprintf(stdout, "Random word is boo! \n");
}

// 
// Args: none
// Returns: none
// Description: Propt the user to play, if the yes selects y then it will call other functions
//
void pickWord( ) {
   char *LOCAL_END_GAME = "false";
   char LOCAL_ARRAY_USER_INPUT[30];
   int LOCAL_CURRENT_TURN = 1;

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
	     getRandomNr();
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

