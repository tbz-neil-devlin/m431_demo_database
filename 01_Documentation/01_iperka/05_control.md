# Control

# How I checked & controlled this assignment
## Highlevel steps
1. Review the product requirements
2. Design testcases to make sure each requirement is tested
3. Review the Documentation requirements

# Designing a tests
* Each requirement that I identified had to be tested, word-picker.c & create-word-database.c needed to be tested
* I using the requirements list I tried to identify a testcases that when executed would check as many of the requirements as possible in one go
* I identified three testcasea for word-picker.c
  * Testcase TC001: to test the main functions
  * Testcase TC002: test test error handling  
  * Testcase TC003: to test error handling when a worng file is pointed to
* I identified three testcasea for create-word-database.c
  * Testcase TC001: tests the handling of words that are too small ot big
  * Testcase TC002: test the handling of words that contain special characters  
  * Testcase TC003: ensures that all words are imported into the database  
![testcase][control01]  
![testcase][control02]  

# Test execution
## TC001 word-picker functionality
* I executed the testcase & gathered the result  
![execute][execute01]  
![execute][execute02]  

## TC002 - word-picker Error handling part 1
* I executed the testcase & gathered the result  
![execute][execute03]  

## TC002 - word-picker Error handling part 2
* I executed the testcase & encountered [issue50]   
![execute][execute05]  
![execute][execute06]  
 
## TC002 - Retest
* After resolving the issue 
* I commited the code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/8f1bfe582b79675c0a9ce2d575a2d8dc801e3011
* I retested
![execute][execute07]  
![execute][execute08] 

## TC003 create-word-database functionality
* I executed the testcase & gathered the result  
![execute][execute09]  
![execute][execute10]  

## TC004 - create-word-database Error handling part 1
* I executed the testcase & gathered the result  
![execute][execute11]  
![execute][execute12]  

[control01]: ../02_resources/images/control-testcase-tc001.JPG
[control02]: ../02_resources/images/control-testcase-tc002-tc003.JPG
  
[execute01]: ../02_resources/images/control-execute-tc001-01.JPG
[execute02]: ../02_resources/images/control-execute-tc001-02.JPG
[execute03]: ../02_resources/images/control-execute-tc002-01.JPG
[execute04]: ../02_resources/images/control-execute-tc002-02.JPG
[execute05]: ../02_resources/images/control-execute-tc003-01.JPG
[execute06]: ../02_resources/images/control-execute-tc003-02.JPG
[execute07]: ../02_resources/images/control-execute-tc003-03.JPG
[execute08]: ../02_resources/images/control-execute-tc003-04.JPG

[execute09]: ../02_resources/images/control-execute-tc003a-01.JPG
[execute10]: ../02_resources/images/control-execute-tc003b-02.JPG
[execute11]: ../02_resources/images/control-execute-tc004-01.JPG
[execute12]: ../02_resources/images/control-execute-tc004-02.JPG

 
[issue50]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/50

  