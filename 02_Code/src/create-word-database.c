//
// Author: Neil Devlin
// Version 4.1
//
// Description: A program that creates a database using a text file as input
//              Asks the user for a database name and a test file.
//              It then reads the file and perfoms the following checks
//              Check that each word in the file only contains letters 8otherwise discard the word) 
//              Checks that each word is between the limits for minimum & maximum number of letters
//              Converts the word to lowercase
//              Inserts the word into a database
//
//         Args:  none
// Return codes:  0 success
//               10 Database already exists
//               11 Word file does not exist
//               12 Cannot create database
//               20 Cannot create table

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h> 
#include <sqlite3.h> 

// Global variables

char *GLOBAL_ENV_VARIABLE_MIN="M431_MIN_WORD_LENGTH";
char *GLOBAL_ENV_VARIABLE_MAX="M431_MAX_WORD_LENGTH";
int GLOBAL_DEFAULT_WORD_LENGTH_MIN = 4;
int GLOBAL_DEFAULT_WORD_LENGTH_MAX = 16;
int GLOBAL_WORD_LENGTH_MIN;
int GLOBAL_WORD_LENGTH_MAX;
int GLOBAL_INSERTED = 0;
int GLOBAL_DISCARDED_DUPLICATE = 0;
int GLOBAL_DISCARDED_OTHER = 0;
   
// Set some global variables
sqlite3 *GLOBAL_PTR_DATABASE;
FILE *GLOBAL_PTR_TEXT_FILE;

// The location for the word file
char *GLOBAL_DEFAULT_TEXT_FILE = "../lists/deadly-insects.txt";


// The query to be performed
char *GLOBAL_SQL_CREATE_TABLE = "create table T_WORDS ( id INTEGER, word TEXT NOT NULL UNIQUE, PRIMARY KEY(id AUTOINCREMENT) )";

static int callBack1(void *data, int argc, char **argv, char **azColName){
   int i;
 
   for(i = 0; i<argc; i++){
	  // printf("%s\n", argv[i]);
	  printf("%s\n", argv[i]);
     }
   
   return 0;
}

// 
//        Args: none
//     Returns: none
// Description: Run a query to count the number of rows in the db
//
void createTable() {
   int LOCAL_RETURN_CODE_QUERY;
   char *zErrMsg = 0;
   const char* data = " ";

   /* Execute SQL statement */
   LOCAL_RETURN_CODE_QUERY = sqlite3_exec(GLOBAL_PTR_DATABASE, GLOBAL_SQL_CREATE_TABLE, callBack1, (void*)data, &zErrMsg);

   if( LOCAL_RETURN_CODE_QUERY != 0 ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  fprintf(stderr, "SQLite exited with return code: %d\n", LOCAL_RETURN_CODE_QUERY);
      sqlite3_free(zErrMsg);
	  exit(20);
   }
}

// 
//        Args: the word to insert (char)
//     Returns: none
// Description: Inserts a word into the database
//              Checks the output of the insert statement & increments a counter
//
void insertWord( char LOCAL_WORD_TO_INSERT[32] ) {
   int LOCAL_RETURN_CODE_QUERY; 
   char LOCAL_SQL_INSERT_WORD[128]="INSERT INTO T_WORDS (word) VALUES ('";
   char *zErrMsg = 0;
   const char* data = " ";

   // Cocatenate the strings to make a query
   strcat(LOCAL_SQL_INSERT_WORD, LOCAL_WORD_TO_INSERT);
   strcat(LOCAL_SQL_INSERT_WORD, "')");  
  
   /* Execute SQL statement */
   LOCAL_RETURN_CODE_QUERY = sqlite3_exec(GLOBAL_PTR_DATABASE, LOCAL_SQL_INSERT_WORD, callBack1, (void*)data, &zErrMsg);

   if( LOCAL_RETURN_CODE_QUERY != 0 ) {
      if ( LOCAL_RETURN_CODE_QUERY != 19 ) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		fprintf(stderr, "Exited with return code: %d\n", LOCAL_RETURN_CODE_QUERY);
		sqlite3_free(zErrMsg);
		GLOBAL_DISCARDED_OTHER++;
		}
	  else {
		  GLOBAL_DISCARDED_DUPLICATE++;
	  }
   }
   else { 
	   GLOBAL_INSERTED++;
   }
}

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
		GLOBAL_WORD_LENGTH_MAX=strtol(LOCAL_ENV_VARIABLE_VALUE_MAX, &somePtr1, 10);
    } else {
        GLOBAL_WORD_LENGTH_MAX = GLOBAL_DEFAULT_WORD_LENGTH_MAX;
    }
	fprintf(stdout, "Maximum word length is set to: %d\n", GLOBAL_WORD_LENGTH_MAX);
		
    // Get the value of the environment variable  (it will be a string, so we need to convert it to an int later)
	LOCAL_ENV_VARIABLE_VALUE_MIN=getenv(GLOBAL_ENV_VARIABLE_MIN);

	if ( LOCAL_ENV_VARIABLE_VALUE_MIN != NULL ) {
		GLOBAL_WORD_LENGTH_MIN=strtol(LOCAL_ENV_VARIABLE_VALUE_MIN, &somePtr2, 10);
    } else {
        GLOBAL_WORD_LENGTH_MIN = GLOBAL_DEFAULT_WORD_LENGTH_MIN;
    }
	
	fprintf(stdout, "Minimum word length is set to: %d\n", GLOBAL_WORD_LENGTH_MIN);

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
    GLOBAL_PTR_TEXT_FILE = fopen(LOCAL_TEXT_FILE, "r");
    if (GLOBAL_PTR_TEXT_FILE != NULL) {
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
   
   createTable();
   
}	



// 
//        Args: none
//     Returns: none
// Description: Reads each line of the text file
//              Checks each character in the line 
//              to make sure it is an alpha
//              it convers the character to lowercase
//              if the character is a \n (end of line), then it checks the whith of the word
//              It either too short or too long then it is discarded
//              otherwise it is inserted into the database
//              Finally it provides a statistic on what it processed
//
void readAndInsert( ) {
    char LOCAL_LINE[255] = "";
	char LOCAL_WORD_TO_INSERT[32];
    char *LOCAL_END_OF_LINE;
	
	int LOCAL_LENGTH = 255;
	int LOCAL_NUMBER_LINES_TOTAL = 1;
	int LOCAL_NUMBER_LINES_VALID = 0;	
	int LOCAL_COUNTER = 0;
	int LOCAL_DISCARD_NOT_APLHA = 0;
	int LOCAL_DISCARD_TOO_SHORT = 0;
	int LOCAL_DISCARD_TOO_LONG = 0;
	int LOCAL_TMP = 32;

	
    while (	fgets(LOCAL_LINE, 255, GLOBAL_PTR_TEXT_FILE) ) {

       LOCAL_END_OF_LINE = "false";
	   
	   
//	   fprintf(stdout, "Line = %d String = %s Length = %d\n", LOCAL_NUMBER_LINES_TOTAL, LOCAL_LINE, LOCAL_LENGTH);

	   for ( LOCAL_COUNTER = 0; LOCAL_COUNTER < LOCAL_LENGTH; LOCAL_COUNTER++ ) {
            if ( LOCAL_LINE[LOCAL_COUNTER] == '\n' ) {
				if ( LOCAL_COUNTER >= GLOBAL_WORD_LENGTH_MIN ) {
				   LOCAL_END_OF_LINE = "true";
				}
				else {
					LOCAL_DISCARD_TOO_SHORT++;
                }    
				if ( LOCAL_COUNTER > GLOBAL_WORD_LENGTH_MAX ) {
				   LOCAL_END_OF_LINE = "false";
				   LOCAL_DISCARD_TOO_LONG++;
                } 
				LOCAL_COUNTER = 999;
            }				
		    else {
			   if ( isalpha( LOCAL_LINE[LOCAL_COUNTER] ) != 0 ) {
				   LOCAL_WORD_TO_INSERT[LOCAL_COUNTER] = tolower( LOCAL_LINE[LOCAL_COUNTER] );
			   }
			   else {
			       LOCAL_DISCARD_NOT_APLHA++;
				   LOCAL_COUNTER = 999;
			   }
			}
	   }
	
	   if ( strcmp(LOCAL_END_OF_LINE,  "true") == 0 ) {

		   insertWord( LOCAL_WORD_TO_INSERT );
		   LOCAL_NUMBER_LINES_VALID++;
	   }
	   
       for ( LOCAL_COUNTER = 0; LOCAL_COUNTER < LOCAL_TMP; LOCAL_COUNTER++ ) {
		   LOCAL_WORD_TO_INSERT[LOCAL_COUNTER] = '\0';
	   }
//			   
	   LOCAL_NUMBER_LINES_TOTAL++;  
	}
	
	fprintf(stdout, "SUMMARY: Lines processed            : %d\n", LOCAL_NUMBER_LINES_TOTAL);
	fprintf(stdout, "SUMMARY: Lines discarded (not alpha): %d\n", LOCAL_DISCARD_NOT_APLHA);
	fprintf(stdout, "SUMMARY: Lines discarded (too short): %d\n", LOCAL_DISCARD_TOO_SHORT);
	fprintf(stdout, "SUMMARY: Lines discarded (too long) : %d\n", LOCAL_DISCARD_TOO_LONG);
	
	fprintf(stdout, "SUMMARY: Lines valid                : %d\n", LOCAL_NUMBER_LINES_VALID);
	fprintf(stdout, "SUMMARY: Words discarded duplicate  : %d\n", GLOBAL_DISCARDED_DUPLICATE);
	fprintf(stdout, "SUMMARY: Words discarded other      : %d\n", GLOBAL_DISCARDED_OTHER);
	fprintf(stdout, "SUMMARY: Words inserted             : %d\n", GLOBAL_INSERTED);	
}	
	

//
// Args: none
// Return: none
//
void main( ) {
   
   setMeUp();
   readAndInsert();
   
}
