#include <stdio.h>
#include <sqlite3.h> 
//
// Author: Neil Devlin
//

// Set some global variables
sqlite3 *GLOBAL_PTR_DATABASE;

// The location for the word database
char *GLOBAL_DB_FILE = "../db/hello-database.db";

// The query to be performed
char *GLOBAL_SQL_QUERY = "select * from T_HELLO";

static int callBack(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s ", (const char*)data);
 
   for(i = 0; i<argc; i++){
//      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	  printf("%s\n", argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

void openDatabase( ) {
   char *zErrMsg = 0;
   int LOCAL_RETURN_CODE_DB;
    
   LOCAL_RETURN_CODE_DB = sqlite3_open(GLOBAL_DB_FILE, &GLOBAL_PTR_DATABASE);

   printf("Database is %s \n", GLOBAL_DB_FILE);

   if( LOCAL_RETURN_CODE_DB != 0 ) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(GLOBAL_PTR_DATABASE));
	  fprintf(stderr, "Exited with return code: %d\n", LOCAL_RETURN_CODE_DB);
   }
}

void runQuery() {
   int LOCAL_RETURN_CODE_QUERY;
   char *zErrMsg = 0;
   const char* data = " ";

   /* Execute SQL statement */
   LOCAL_RETURN_CODE_QUERY = sqlite3_exec(GLOBAL_PTR_DATABASE, GLOBAL_SQL_QUERY, callBack, (void*)data, &zErrMsg);

   if( LOCAL_RETURN_CODE_QUERY != 0 ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  fprintf(stderr, "Exited with return code: %d\n", LOCAL_RETURN_CODE_QUERY);
      sqlite3_free(zErrMsg);
   }
}

int main( ) {
   openDatabase();
   runQuery();
   sqlite3_close(GLOBAL_PTR_DATABASE);
}