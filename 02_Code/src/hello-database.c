#include <stdio.h>
#include <sqlite3.h> 

sqlite3 *GLOBAL_PTR_DATABASE;

char *GLOBAL_DB_FILE = "../db/hello-database.db";
char *GLOBAL_SQL_QUERY = "select * from T_HELLO";

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "What is this? %s: ", (const char*)data);
 
   for(i = 0; i<argc; i++){
//      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	  printf("ARGV %d is %s\n", i, argv[i]);

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

   if( LOCAL_RETURN_CODE_DB ) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(GLOBAL_PTR_DATABASE));
   } else {
	  fprintf(stdout, "Opened database successfully\n");
   }
}

void runQuery() {
   int LOCAL_RETURN_CODE_QUERY;
   char *zErrMsg = 0;
   const char* data = "Callback function called";

   /* Execute SQL statement */
   LOCAL_RETURN_CODE_QUERY = sqlite3_exec(GLOBAL_PTR_DATABASE, GLOBAL_SQL_QUERY, callback, (void*)data, &zErrMsg);
   
   if( LOCAL_RETURN_CODE_QUERY != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
}

int main( ) {
   openDatabase();
   runQuery();
   sqlite3_close(GLOBAL_PTR_DATABASE);
}