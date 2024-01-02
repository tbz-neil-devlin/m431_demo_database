# Implement

## High level
1. Implement the database with a limited amount of words
2. Implement word-picker.c
  * I decided to split the program into functions so it is manageable
  * Write the pickWord function
  * Write the getRandomNr function4. 
  * Write the getWord function
  * Write the setMeUp function


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

[issue 23]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/23
[issue 19]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/19
[issue 40]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/40
[issue 41]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/41
[issue 42]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/42
[issue 43]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/43
[issue 44]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/44
[issue 45]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/45
[issue 46]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/46


[implement01]: ../02_resources/images/realize-implement-wordpicker-database-01.jpg
[implement02]: ../02_resources/images/realize-implement-wordpicker-database-02.jpg
[implement03]: ../02_resources/images/realize-implement-wordpicker-database-03.jpg
[implement04]: ../02_resources/images/realize-implement-wordpicker-database-04.jpg
[implement05]: ../02_resources/images/realize-implement-wordpicker-database-05.jpg
[implement06]: ../02_resources/images/realize-implement-wordpicker-pickword-01.JPG
[implement07]: ../02_resources/images/realize-implement-wordpicker-gerrandomnr-01.JPG
[implement08]: ../02_resources/images/realize-implement-wordpicker-getword-01.JPG
[implement09]: ../02_resources/images/realize-implement-wordpicker-setmeup-01.JPG