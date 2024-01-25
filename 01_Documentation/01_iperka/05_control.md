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
  * Testcase TC002: test test error handling & error handling when a worng file is pointed to   
![testcase][control01]  
![testcase][control02]  
* I identified three testcasea for create-word-database.c
  * Testcase TC003 tests:
    * the handling of words that are too small ot big, 
	* words that contain special characters and 
	* ensures that all words are imported into the database  
 * Testcase TC004 tests error handling:
 
![testcase][control03]  
![testcase][control04] 

# Test execution
## Testing word-picker [issue34]
### TC001 word-picker functionality
* I executed the testcase & gathered the result  
![execute][execute01]  
![execute][execute02]  

### TC002 - word-picker Error handling part 1
* I executed the testcase & gathered the result  
![execute][execute03]  

### TC002 - word-picker Error handling part 2
* I executed the testcase & encountered [issue50]   
![execute][execute05]  
![execute][execute06]  
 
### TC002 - Retest
* After resolving the issue 
* I commited the code: https://github.com/tbz-neil-devlin/m431_demo_database/commit/8f1bfe582b79675c0a9ce2d575a2d8dc801e3011
* I retested
![execute][execute07]  
![execute][execute08] 

## Testing create-word-database [issue35]
### TC003 create-word-database functionality
* I executed the testcase & gathered the result  
![execute][execute09]  
![execute][execute10]  

### TC004 - create-word-database Error handling part 1
* I executed the testcase & gathered the result  
![execute][execute11]  
![execute][execute12]  

## Testprotpcol
* The tests went smoothly and only one issue was found [issue50] 
* The testprotocol is shown below
![execute][protocol] 

## Known issues - open
* [issue50] Known issue - create-word-database.c no checks performed on min / max word length

# Checking the documentation
* I revisited the documentation requirements
* Beside each requirement I marked off what was done & where it could be found
![protocol][documentation]
 


[control01]: ../02_resources/images/control-testcase-tc001.JPG
[control02]: ../02_resources/images/control-testcase-tc002-tc003.JPG
[control03]: ../02_resources/images/realize-implement-testcase-tc003.JPG
[control04]: ../02_resources/images/realize-implement-testcase-tc004.JPG
  

  
[execute01]: ../02_resources/images/control-execute-tc001-01.jpg
[execute02]: ../02_resources/images/control-execute-tc001-02.JPG
[execute03]: ../02_resources/images/control-execute-tc002-01.JPG
[execute04]: ../02_resources/images/control-execute-tc002-02.JPG
[execute05]: ../02_resources/images/control-execute-tc003-01.JPG
[execute06]: ../02_resources/images/control-execute-tc003-02.JPG
[execute07]: ../02_resources/images/control-execute-tc003-03.JPG
[execute08]: ../02_resources/images/control-execute-tc003-04.JPG
[execute09]: ../02_resources/images/control-execute-tc003a-01.JPG
[execute10]: ../02_resources/images/control-execute-tc003a-02.JPG
[execute11]: ../02_resources/images/control-execute-tc004-01.JPG
[execute12]: ../02_resources/images/control-execute-tc004-02.JPG

[protocol]: ../02_resources/images/control-testprotocol-01.JPG
[documentation]: ../02_resources/images/control-documentation-01.JPG

[issue34]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/34
[issue35]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/35
[issue50]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/50

  