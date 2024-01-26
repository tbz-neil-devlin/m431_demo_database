# Implement

## High level
1. Implement the database with a limited amount of words
2. Implement word-picker.c
  * I decided to split the program into functions so it is manageable
  * Write the pickWord function
  * Write the getRandomNr function4. 
  * Write the getWord function
  * Write the setMeUp function
3. Implement create-word-database.c
  * I decided to split the program into functions so it is manageable
  * Write the setMeUp function
  * Write the readAndInser function
  * Write the insertWord function
4. Create a long list of words
5. Create testcases for word-picker
6. Create testcases for create-word-database


## Implement word-picker database [issue 40]
1. Start the DB Browser for SQLite
2. Create the database
3. Create the table. Note, because I selected autoincrement a second table "sqlite_sequence" was automatically created. 
4. Enter a number of words
![database][implement01]  
![database][implement02]  
![database][implement03]  
![database][implement04]  
![database][implement05]  

## Implement word-picker.c function pickWord [issue 41]
1. Using the flowchart from [issue 19] I began with coding.
2. Encountered [issue 42], there were two issues, one was a syntax and the other a logica issue. 
3. Encountered [issue 43], caused my referencing the wrong element in the array.
4. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/04fea157e097ec2f97a5b0c47c6d626b07df8983  
![pickword][implement06]  

## Implement word-picker.c function getRandomNr [issue 45]
1. Using the flowchart from [issue 19] I began with coding.
2. Encountered [issue 44], an endless loop caused by not resetting a flag. 
3. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/56b5130c1abdc078ac11ad155a464d2bc619bd49  
![pickword][implement07]  

## Implement word-picker.c function getRandomNr [issue 46]
1. Using the flowchart from [issue 19] I began with coding.
2. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/8662b494762551c7965af35b914d7a730cf3f09b  
![pickword][implement08]  

## Implement word-picker.c function setMeUp [issue 23]
1. Using the flowchart from [issue 19] I began with coding.
2. Merged the openDatabase function into the setMeUp
2. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/aabe1eaa0d3f83f5d3bca069e6b1576bdb04fb01   
![pickword][implement09]  

## Implement word-picker.c function setMeUp [issue 23]
1. Using the flowchart from [issue 19] I began with coding.
2. Merged the openDatabase function into the setMeUp
2. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/aabe1eaa0d3f83f5d3bca069e6b1576bdb04fb01   
![pickword][implement09]  

## Implement create-word-database.c function setMeUp [issue 22]
1. Using the flowchart from [issue 20] I began with coding.
2. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/73c52b62220d747bf9b05718e5fb6b622ed01e7a  
![pickword][implement10]  

## Implement create-word-database.c function readAndInsert [issue 22]
1. Using the flowchart from [issue 20] I began with coding.
2. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/73c52b62220d747bf9b05718e5fb6b622ed01e7a  
![pickword][implement11]  

## Implement create-word-database.c function createTable [issue 48]
1. Using the flowchart from [issue 20] I began with coding.
2. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/19f8d3a860442b71ef29812eed0bf9db02e93b7d  
![pickword][implement12]  

## Implement create-word-database.c function insertWord [issue 49]
1. Using the flowchart from [issue 20] I began with coding.
2. Commited code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/e48ffca1372c8446c3149ac05bf226a7397bc693  
![pickword][implement13]  

## Implement create a long list of words [issue 37]
1. I scanned a page from a book "Lawful Occasions", page 60.
2. Using Linux & a "sed* command I converted all spaces into newlines "\n" thus creating a long list [many-words.txt].
![pickword][implement14]  

## Implement testcases for word-picker [issue 32]
1. Using the flowchart, the requirements and my initial test matrix I wrote the testcases.   
![testcase][testcase01]  
![testcase][testcase02]  

## Implement testcases for create-word-database [issue 33]
1. Using the flowchart, the requirements and my initial test matrix I wrote the testcases.
![testcase][testcase03]  
![testcase][testcase04]  

## Implement testcases for create-word-database [issue 52]
1. Created a download directory
2. Created a directory structure in the download diretory (bin db lists)
3. Copied word-picker.exe & create-word-database.exe to the bin directory
4. Copied word-picker.db to the db directory
5. Copied many-words.txt and deadly-insects.txt to lists
6. Wrote the readme
7. Tarred up the file
![pickword][implement14]  


## Issues encountered
* [issue 39]  fatal error: sqlite3.h: No such file or directory 
* [issue 42] word-picker.c endless loop when the user tries to end the game
* [issue 43] word-picker.c - function pickWord - "Y" is not interpreted ay "y"
* [issue 44] Implement word-picker.c function - getRandomNr has an endless loop
* [issue 47] Entering yes terminates the game



# References
* How to compare strings in an "if" statement? (2011, November 22). 
  * Stack Overflow. 
  * Retrieved December 31, 2023, 
  * from https://stackoverflow.com/questions/8222495/how-to-compare-strings-in-an-if-statement
* C tolower() - C Standard Library. (n.d.). 
  * Programiz. 
  * Retrieved December 31, 2023, 
  * from https://www.programiz.com/c-programming/library-function/ctype.h/tolower
* C library function - strcat(). (n.d.). 
  * Tutorialspoint. 
  * Retrieved January 1, 2024, 
  * from https://www.tutorialspoint.com/c_standard_library/c_function_strcat.htm 
* How can I convert an int to a string in C? (2011, November 24). 
  * Stack Overflow. 
  * Retrieved January 1, 2024, 
  * from https://stackoverflow.com/questions/8257714/how-can-i-convert-an-int-to-a-string-in-c
* C library function - getenv(). (n.d.). 
  * Tutorialspoint. 
  * Retrieved January 2, 2024, 
  * from https://www.tutorialspoint.com/c_standard_library/c_function_getenv.htm
* c - Use of exit() function. (2010, March 11). 
  * Stack Overflow. 
  * Retrieved January 2, 2024, 
  * from https://stackoverflow.com/questions/2425167/use-of-exit-function
* C File Exists Function. (n.d.). 
  * Learn C Programming from Scratch. 
  * Retrieved January 2, 2024, 
  * from https://www.learnc.net/c-tutorial/c-file-exists/
* Williams, L. (2023, September 28). 10 deadliest insects: The most dangerous insects to humans - Discover Wildlife Deadliest insects in the world. 
  * BBC Wildlife. 
  * Retrieved January 4, 2024, 
  * from https://www.discoverwildlife.com/animal-facts/insects-invertebrates/deadliest-insects
* Mac Kenzie, P. (1991). 
  * Lawful Occasions. 
  * Dufour Editions.




[many-words.txt]: https://github.com/tbz-neil-devlin/m431_demo_database/blob/main/02_Code/db/many-words.txt




[issue 20]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/20
[issue 23]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/23
[issue 22]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/22
[issue 19]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/19
[issue 32]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/32
[issue 33]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/33
[issue 37]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/37
[issue 39]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/39
[issue 40]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/40
[issue 41]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/41
[issue 42]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/42
[issue 43]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/43
[issue 44]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/44
[issue 45]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/45
[issue 46]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/46
[issue 48]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/48
[issue 49]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/49

[implement01]: ../02_resources/images/realize-implement-wordpicker-database-01.jpg
[implement02]: ../02_resources/images/realize-implement-wordpicker-database-02.jpg
[implement03]: ../02_resources/images/realize-implement-wordpicker-database-03.jpg
[implement04]: ../02_resources/images/realize-implement-wordpicker-database-04.jpg
[implement05]: ../02_resources/images/realize-implement-wordpicker-database-05.jpg
[implement06]: ../02_resources/images/realize-implement-wordpicker-pickword-01.JPG
[implement07]: ../02_resources/images/realize-implement-wordpicker-gerrandomnr-01.JPG
[implement08]: ../02_resources/images/realize-implement-wordpicker-getword-01.JPG
[implement09]: ../02_resources/images/realize-implement-wordpicker-setmeup-01.JPG
[implement10]: ../02_resources/images/realize-implement-create-word-db-setmeup-01.JPG
[implement12]: ../02_resources/images/realize-implement-create-word-db-createtable-03.JPG
[implement13]: ../02_resources/images/realize-implement-create-word-db-insertword-01.JPG
[implement14]: ../02_resources/images/realize-implement-wordpicker-download-01.JPG

[testcase01]: ../02_resources/images/realize-implement-testcase-tc001.JPG
[testcase02]: ../02_resources/images/realize-implement-testcase-tc002.JPG
[testcase03]: ../02_resources/images/realize-implement-testcase-tc003.JPG
[testcase04]: ../02_resources/images/realize-implement-testcase-tc004.JPG