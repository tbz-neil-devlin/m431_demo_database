
# Design
## Naming conventions [issue 5]
### Filenames
* all lowercase
* spaces represented by a hyphen "-"
### Directories
* All lower case
* spaces represented by an underscore "_"
### Variables
* All uppercase
* Global prdxided with GLOBAL
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

## Directory structure [issue 4]
* Made a sletch of how the directory structure should be
* ![sketch direcories][sketch1]

## Database design [issue 21]
* ![schema][design1]

## Flowchart word picker [issue 19]
* Flowchart was made with drawio  
![Word picker][design2]
## Flowchart create word database [issue 20]
* Flowchart was made with drawio  
![Word picker][design3]
## Design testcases [issue 7] & [issue 8]
* I review the requirements that I made for the application
* based on the review I identified 3 testcases that could be used to test that the requirements had been implemented    
![test Matrix][design4]


# Setup
## Setup github directories [issue 6]
* Cloned the repository to my laptop
* Using my design of the directory structure proceeded as follows: 
  * Created the directory structure with mkdir
  * Created empty files with touch
  * Copied some excels & screenshots that I had already prepared into the direcories
  * Committed my changes & pushed to github  
![setup direcories][setup1]
![setup direcories][setup2]
![setup direcories][setup3]
![setup direcories][setup4]
![setup direcories][setup5]

## Setup github client
* Downloaded the esecutable from
* Created a personal token following the instructions on (_Managing your personal access tokens_)
* Added the token to my KeePass
* Started gh on my laptop
* ![github cli][setup6]

## Setup drawio
* Downloaded the executable from 
* Saved it to my local drive

## Setup Download & install codeblocks [issue 9]
* Downloaded the executable from 
* Saved it to my local drive & pressed execute
* Once it finished I need to add its directory to the PATH environment variable. Doing this allows me to execute the binary E.g. gcc.exe without havibg ti specifiy it's directory location.  
![codeblocks][setup7]
![codeblocks][setup8]
![codeblocks][setup9]
![codeblocks][setup10]
![codeblocks][setup11]
![codeblocks][setup12]
![codeblocks][setup13]  
 
## Setup Download & install Sqlite [issue 13]
* Downloaded the executable from 
* Saved it to my local drive in "/c/local/sqlite"  
![sqlite][setup14]
![sqlite][setup15]
![sqlite][setup16]

# Downloads
* **Drawio**
  * https://github.com/jgraph/drawio-desktop/releases/download/v22.1.2/draw.io-22.1.2-windows-no-installer.exe
* **GitHub CLI**
  * https://github.com/cli/cli/releases/download/v2.39.1/gh_2.39.1_windows_386.msi
* **CodeBlocks**
  * https://www.fosshub.com/Code-Blocks.html?dwl=codeblocks-20.03mingw-setup.exe#
* **SQLite Download Page** 
  * https://www.sqlite.org/download.html
* **SQLite DB Browser Download Page** 
  * https://sqlitebrowser.org/dl/

# References
* How can I export GitHub issues to Excel? (2016, December 28). Stack Overflow. 
  * Retrieved November 25, 2023, from 
  * https://stackoverflow.com/questions/41369365/how-can-i-export-github-issues-to-excel
* Managing your personal access tokens. (n.d.). GitHub Docs. 
  * Retrieved November 25, 2023, from 
  * https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens#creating-a-personal-access-token-classic
* (n.d.). draw.io. 
  * Retrieved November 26, 2023, from 
  * https://www.drawio.com/
* SQLite - AUTOINCREMENT. (n.d.). Tutorialspoint. 
  * Retrieved November 28, 2023, from
  * https://www.tutorialspoint.com/sqlite/sqlite_using_autoincrement.htm
* SQLite - Data Type. (n.d.). Tutorialspoint. 
  * Retrieved November 28, 2023, from
  * https://www.tutorialspoint.com/sqlite/sqlite_data_types.htm
*  SQLite - C/C++. (n.d.). Tutorialspoint. 
  * Retrieved December 5, 2023, from 
  * https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
* Install C/GCC Compiler for Windows. (2022, August 3). DigitalOcean. 
  * Retrieved December 3, 2023, from
  * https://www.digitalocean.com/community/tutorials/c-compiler-windows-gcc


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

[issue 19]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/19
[issue 20]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/20
[issue 21]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/21

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

[sketch1]: ../02_resources/images/realize-design-sketch-directories.jpeg