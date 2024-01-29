# Design

# High Level
1. Define the naming conventions
2. Design the Github directory structure
3. Design the database schema 
4. Draw word-picker flowchart
5. Draw create-word-database flowchart
6. Design testcases


## Naming conventions [issue 5]
### Filenames
* all lowercase
* spaces represented by a hyphen "-"
### Directories
* All lowercase
* spaces represented by an underscore "_"
### Variables
* All uppercase
* Global prefixed with GLOBAL
* Local prefixed with LOCAL
### Functions
* Camel case
### Environment Variables
* All uppercase
* All prefixed with "M431_"
* Spaces with underscore "_"
### Database
* tables
  * all UPPERCASE
  * Prefixed with "T_" 
* colums
  * All lowercase

## Github directory structure [issue 4]
* Made a sketch of how the directory structure should be
* ![sketch direcories][sketch1]

## Database schema design [issue 21]
* As there was only one table in the schema, this was quite easy
* ![schema][design1]

## Flowchart word picker [issue 19]
* Flowchart was made with drawio  
* 3 functions were identified
  * pickWord: this is the main functions
  * getRandomNr: this will generate a random number
  * getWord: will fetch the word from the database  
![Word picker][design2]

## Flowchart create word database [issue 20]
* Flowchart was made with drawio
* 2 functions were identified:
  * createTable: creates the table  
  * readAndInsert: reads the files, checks the word before inserting it into the database  
![Word picker][design3]

## Making sure no requirement has been forgotten
* I reviewed the requirements again
* I added a column "Implemented by" where I wrote how (or where) each requirement would be fulfilled  

## Design testcases [issue 30] & [issue 31]
* I reviewed the requirements that I made for the application (again)
* based on the review I identified 3 testcases that could be used to test that the requirements had been implemented    
![test Matrix][design4]

[design1]: ../02_resources/images/realize-design-database-schema.png
[design2]: ../02_resources/images/realize-design-flowchart-word-picker.png
[design3]: ../02_resources/images/realize-design-flowchart-create-word-database.png
[design4]: ../02_resources/images/realize-design-testcases.JPG


[issue 4]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/4
[issue 5]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/5
[issue 6]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/6
[issue 7]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/7
[issue 8]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/8
[issue 9]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/9
[issue 13]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/13

[issue 17]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/17
[issue 18]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/18
[issue 19]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/19
[issue 20]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/20
[issue 21]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/21
[issue 30]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/30
[issue 31]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/31
[issue 39]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/39

[setup1]: ../02_resources/images/realize-setup-git-clone.JPG
[setup2]: ../02_resources/images/realize-setup-git-directories-01.JPG
[setup3]: ../02_resources/images/realize-setup-git-directories-02.JPG
[setup4]: ../02_resources/images/realize-setup-git-directories-03.JPG
[setup5]: ../02_resources/images/realize-setup-git-directories-04.JPG
[setup6]: ../02_resources/images/realize-setup-github-cli-01.JPG
[setup7]: ../02_resources/images/realize-setup-codeblocks01.JPG
[setup8]: ../02_resources/images/realize-setup-codeblocks02.JPG
[setup9]: ../02_resources/images/realize-setup-codeblocks03.JPG
[setup10]: ../02_resources/images/realize-setup-codeblocks-path-03.JPG
[setup11]: ../02_resources/images/realize-setup-codeblocks-path-02.JPG
[setup12]: ../02_resources/images/realize-setup-codeblocks-path-03.JPG
[setup13]: ../02_resources/images/realize-setup-codeblocks-path-04.JPG
[setup14]: ../02_resources/images/realize-setup-sqlite-db-browser-01.JPG
[setup15]: ../02_resources/images/realize-setup-sqlite-db-browser-02.JPG
[setup16]: ../02_resources/images/realize-setup-sqlite-db-browser-03.JPG
[setup17]: ../02_resources/images/realize-setup-hello-database-01.JPG
[setup18]: ../02_resources/images/realize-setup-hello-database-02.JPG
[setup19]: ../02_resources/images/realize-setup-hello-database-03.JPG
[setup20]: ../02_resources/images/realize-implement-hello-database-01.JPG


[sketch1]: ../02_resources/images/realize-design-sketch-directories.jpeg