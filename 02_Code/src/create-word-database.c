//
// Author: Neil Devlin
// Version 1.0
//

#include <stdio.h>
#include <sqlite3.h> 
#include <ctype.h> 
#include <string.h> 
#include <stdlib.h>



// Global variables

char *GLOBAL_ENV_VARIABLE_MIN="M431_MIN_WORD_LENGTH";
char *GLOBAL_ENV_VARIABLE_MAX="M431_MAX_WORD_LENGTH";
int GLOBAL_DEFAULT_WORD_LENGTH_MIN = 4;
int GLOBAL_DEFAULT_WORD_LENGTH_MAX = 32;


// Set some global variables
sqlite3 *GLOBAL_PTR_DATABASE;

// The location for the word file
char *GLOBAL_DEFAULT_TEXT_FILE = "../db/deadly-insects.txt";


// The query to be performed
char *GLOBAL_SQL_CREATE_TABLE = "create table T_WORDS {id INTEGER, word TEXT NOT NULL UNIQUE, PRIMARY KEY(id) AUTOINCREMENT}";


// 
//        Args: none
//     Returns: none
// Description: Checks if an environment variable (M431_MIN_WORD_LENGTH) has been set
//              If yes, then use the value that it is set to
//              If no, then use a default value
//              Checks if an environment variable (M431_MIN_WORD_LENGTH) has been set
//              If yes, then use the value that it is set to
//              If no, then use a default value
//              If no filename is provided, then assume a default
//              Try to open the file (to make sure it exists
//              Open the database
//
void setMeUp( ) {
	
	// char *LOCAL_PTR_DATABASE_FILE;
	char *LOCAL_DATABASE_FILE;

	// char *LOCAL_PTR_TEXT_FILE;
	char *LOCAL_TEXT_FILE;


	char *LOCAL_ENV_VARIABLE_VALUE_MAX;
	char *LOCAL_ENV_VARIABLE_VALUE_MIN;
  	char LOCAL_USER_INPUT1[255];
	char LOCAL_USER_INPUT2[255];
	
	int LOCAL_WORD_LENGTH_MIN;
	int LOCAL_WORD_LENGTH_MAX;
	
	int LOCAL_RETURN_CODE_DB;
	char *somePtr1;
	char *somePtr2;
	
	
    // Get the value of the environment variable (it will be a string, so we need to convert it to an int later)
	LOCAL_ENV_VARIABLE_VALUE_MAX=getenv(GLOBAL_ENV_VARIABLE_MAX);

	if ( LOCAL_ENV_VARIABLE_VALUE_MAX != NULL ) {
		LOCAL_WORD_LENGTH_MAX=strtol(LOCAL_ENV_VARIABLE_VALUE_MAX, &somePtr1, 10);
    } else {
        LOCAL_WORD_LENGTH_MAX = GLOBAL_DEFAULT_WORD_LENGTH_MAX;
    }
	fprintf(stdout, "Maximum word length is set to: %d\n", LOCAL_WORD_LENGTH_MAX);
		
    // Get the value of the environment variable  (it will be a string, so we need to convert it to an int later)
	LOCAL_ENV_VARIABLE_VALUE_MIN=getenv(GLOBAL_ENV_VARIABLE_MIN);

	if ( LOCAL_ENV_VARIABLE_VALUE_MIN != NULL ) {
		LOCAL_WORD_LENGTH_MIN=strtol(LOCAL_ENV_VARIABLE_VALUE_MIN, &somePtr2, 10);
    } else {
        LOCAL_WORD_LENGTH_MIN = GLOBAL_DEFAULT_WORD_LENGTH_MIN;
    }
	
	fprintf(stdout, "Minimum word length is set to: %d\n", LOCAL_WORD_LENGTH_MIN);

	// Ask the user to supply the name of the database
	fprintf(stdout, "Please enter the full pathname of the database file: ");
	LOCAL_DATABASE_FILE=gets(LOCAL_USER_INPUT1);

	// try to access the database file, if successfull then exit
    FILE *LOCAL_PTR_DATABASE_FILE=fopen(LOCAL_DATABASE_FILE, "r");
    if (LOCAL_PTR_DATABASE_FILE == NULL) {
		fprintf(stdout, "Using database %s\n", LOCAL_DATABASE_FILE);
	} else {
		fprintf(stderr, "ERROR: The database file %s already exists, please use a different name\n", LOCAL_DATABASE_FILE);
        exit(10);
	}
	
	// Ask the user to supply the name of the text file
	fprintf(stdout, "Please enter the full pathname of the text file: ");
	LOCAL_TEXT_FILE=gets(LOCAL_USER_INPUT2);
	
	// If the answer is empty (i.e. the user just pressed enter), then use a default file
	if ( strcmp(LOCAL_TEXT_FILE, "") == 0 ) {
		      LOCAL_TEXT_FILE = GLOBAL_DEFAULT_TEXT_FILE;
	}

	// try to access the text file, if not successfull then exit
    FILE *LOCAL_PTR_TEXT_FILE=fopen(LOCAL_TEXT_FILE, "r");
    if (LOCAL_PTR_TEXT_FILE != NULL) {
		fprintf(stdout, "Using text %s\n", LOCAL_TEXT_FILE);
	} else {
		fprintf(stderr, "ERROR: The text file %s already does not exist, please use a different name\n", LOCAL_TEXT_FILE);
        exit(11);
	}
		
   LOCAL_RETURN_CODE_DB = sqlite3_open(LOCAL_DATABASE_FILE, &GLOBAL_PTR_DATABASE);

   if( LOCAL_RETURN_CODE_DB != 0 ) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(GLOBAL_PTR_DATABASE));
	  fprintf(stderr, "Exited with return code: %d\n", LOCAL_RETURN_CODE_DB);
	  exit(12);
   }
}	

//
// Args: none
// Return: none
//
void main( ) {
   
   setMeUp();
   
}
