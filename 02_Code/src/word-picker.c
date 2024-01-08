//
// Author: Neil Devlin
// Version 4.1
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
int GLOBAL_MAX_TURNS;
int GLOBAL_ARRAY_NUMBERS_USED[] = {};
char *GLOBAL_WORD;
char *GLOBAL_ENV_VARIABLE="M431_DATABASE_FILE";


// Set some global variables
sqlite3 *GLOBAL_PTR_DATABASE;

// The location for the word database
char *GLOBAL_DEFAULT_DATABASE_FILE = "../db/word-picker.db";


// The query to be performed
char *GLOBAL_SQL_QUERY_NUM_ROWS = "select count(*) from T_WORDS";

static int callBack(void *data, int argc, char **argv, char **azColName){
   int i, tmp;
   char *somePtr;
 
   for(i = 0; i<argc; i++){
	  GLOBAL_MAX_TURNS=strtol(argv[i], &somePtr, 10);
   }
   
   return 0;
}

static int callBack2(void *data, int argc, char **argv, char **azColName){
   int i;
 
   for(i = 0; i<argc; i++){
	  // printf("%s\n", argv[i]);
	  GLOBAL_WORD = argv[i];
	  printf("%s\n", GLOBAL_WORD);
     }
   
   return 0;
}

// 
//        Args: none
//     Returns: none
// Description: Run a query to count the number of rows in the db
//
void runQueryCountRows() {
   int LOCAL_RETURN_CODE_QUERY;
   char *zErrMsg = 0;
   const char* data = " ";

   /* Execute SQL statement */
   LOCAL_RETURN_CODE_QUERY = sqlite3_exec(GLOBAL_PTR_DATABASE, GLOBAL_SQL_QUERY_NUM_ROWS, callBack, (void*)data, &zErrMsg);

   if( LOCAL_RETURN_CODE_QUERY != 0 ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  fprintf(stderr, "Exited with return code: %d\n", LOCAL_RETURN_CODE_QUERY);
      sqlite3_free(zErrMsg);
   }
}

// 
//        Args: none
//     Returns: none
// Description: Checks if an environment variable (M431_DATABASE_FILE) has been set
//              If yes, then use the file that it points to as the database
//              If no, then ask the user to supply a filenemt
//              If no filename is provided, then assume a default
//              Try to open the file (to make sure it exists
//              Open the database
//
void setMeUp( ) {
	char *LOCAL_DATABASE_FILE;
	char *LOCAL_ENV_VARIABLE_VALUE;
  	char LOCAL_USER_INPUT[255];
	
	char *zErrMsg = 0;
    int LOCAL_RETURN_CODE_DB;
	
    // GGet the value of the environment variable
	LOCAL_ENV_VARIABLE_VALUE=getenv(GLOBAL_ENV_VARIABLE);

	if ( LOCAL_ENV_VARIABLE_VALUE != NULL ) {
		LOCAL_DATABASE_FILE = LOCAL_ENV_VARIABLE_VALUE;
    } else {
        // Ask the user to supply the name of the database
	    fprintf(stdout, "Please enter the full pathname of the database file (press enter to use the dfault database): ");
	    LOCAL_DATABASE_FILE=gets(LOCAL_USER_INPUT);

        // If the answer is empty (i.e. the user just pressed enter), then use a default database
	    if ( strcmp(LOCAL_DATABASE_FILE, "") == 0 ) {
		      LOCAL_DATABASE_FILE = GLOBAL_DEFAULT_DATABASE_FILE;
        }
	}
	
	// try to access the database file, if not successfull then exit
    FILE *LOCAL_PTR_DATABASE_FILE=fopen(LOCAL_DATABASE_FILE, "r");
    if (LOCAL_PTR_DATABASE_FILE != NULL) {
		fprintf(stdout, "Using database %s\n", LOCAL_DATABASE_FILE);
		fclose(LOCAL_PTR_DATABASE_FILE);
	} else {
		fprintf(stderr, "ERROR: Cannot access the file: %s\n", LOCAL_DATABASE_FILE);
        exit(10);
	}
		
  
   LOCAL_RETURN_CODE_DB = sqlite3_open(LOCAL_DATABASE_FILE, &GLOBAL_PTR_DATABASE);

   if( LOCAL_RETURN_CODE_DB != 0 ) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(GLOBAL_PTR_DATABASE));
	  fprintf(stderr, "Exited with return code: %d\n", LOCAL_RETURN_CODE_DB);
	  exit(20);
   }
}	
	
	

// 
//        Args: the current turn (integer)
//      Return: the random number (integer)
//
// Description: Generates a unique random number no higher than GLOBAL_MAX_TURNS
//              This number is then used to select the word from that database
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

// 
//        Args: the random number (integer)
//      Return: none
// Description: Use the random number to build a select statement (query)
//              Then execute the query and print it to stdout
//
void getWord(int LOCAL_RANDOM_NUMBER ) {
   int LOCAL_RETURN_CODE_QUERY;
   char *zErrMsg = 0;
   const char* data = " ";
   char LOCAL_SQL_QUERY_GET_WORD[128]="SELECT word FROM t_words WHERE id=";
   char LOCAL_RANDOM_NUMBER_STRING[4];
   
   // Convert the integer into a string
   itoa(LOCAL_RANDOM_NUMBER, LOCAL_RANDOM_NUMBER_STRING, 10);

   // Cocatenate the strings to make a query
   strcat(LOCAL_SQL_QUERY_GET_WORD, LOCAL_RANDOM_NUMBER_STRING);

   /* Execute SQL statement */
   LOCAL_RETURN_CODE_QUERY = sqlite3_exec(GLOBAL_PTR_DATABASE, LOCAL_SQL_QUERY_GET_WORD, callBack2, (void*)data, &zErrMsg);

   if( LOCAL_RETURN_CODE_QUERY != 0 ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  fprintf(stderr, "Exited with return code: %d\n", LOCAL_RETURN_CODE_QUERY);
      sqlite3_free(zErrMsg);
	  exit(30);
   }
}

// 
//        Args: none
//      Return: none
// Description: Prompt the user to play, if the answer is yes then it will call other functions
//
void pickWord( ) {
   char *LOCAL_END_GAME = "false";
   char LOCAL_ARRAY_USER_INPUT[30];
   char TMP;
   int LOCAL_CURRENT_TURN = 1;
   int LOCAL_RANDOM_NUMBER;
   int LOCAL_ELEMENT_IN_ARRAY;

   // Do a while loop as long as the LOCAL_END_GAME is false and the GLOBAL_MAX_TURNS is not exceeded
   // 
   while ( LOCAL_CURRENT_TURN <= GLOBAL_MAX_TURNS && strcmp(LOCAL_END_GAME, "false") == 0 ) {

      // Ask user if they want word, select only the first letter of their response
	  fprintf(stdout, "Would you like to pick a word (y/n):");
	  scanf("%s", LOCAL_ARRAY_USER_INPUT);
	  
	  // Convert the users reply into lowercase
	  LOCAL_ARRAY_USER_INPUT[0] = tolower(LOCAL_ARRAY_USER_INPUT[0]);
	  
	  // Check if it is "y"
	  if ( LOCAL_ARRAY_USER_INPUT[0] != 'y' ) {
	     // answer was not y, therefore end the game, decrease the number of turns taken
	     LOCAL_END_GAME = "true";
 		 LOCAL_CURRENT_TURN--;
	  }
      else {
		 // answer was y, therefore play the game & increment the number turns taken
	     LOCAL_RANDOM_NUMBER = getRandomNr(LOCAL_CURRENT_TURN);

		 getWord(LOCAL_RANDOM_NUMBER);

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
   
   setMeUp();
   runQueryCountRows();

   pickWord();
   sqlite3_close(GLOBAL_PTR_DATABASE);   
}

