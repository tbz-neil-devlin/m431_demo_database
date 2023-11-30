
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
* Made a sletch of how the directory structure should be
* ![Word picker][design2]



# Setup
## Setup github directories [issue 6]
* Cloned the repository to my laptop
* Using my design of the directory structure proceeded as follows: 
  * Created the directory structure with mkdir
  * Created empty files with touch
  * Copied some excels & screenshots that I had already prepared into the direcories
  * Committed my changes & pushed to github
* ![setup direcories][setup1]
* ![setup direcories][setup2]
* ![setup direcories][setup3]
* ![setup direcories][setup4]
* ![setup direcories][setup5]

## Setup github client
* Downloaded the esecutable from
* Created a personal token following the instructions on (_Managing your personal access tokens_)
* Added the token to my KeePass
* Started gh on my laptop
* ![github cli][setup6]

## Setup drawio
* Downloaded the executable from 
* Saved it to my local drive


# Downloads
* **Drawio**
  * https://github.com/jgraph/drawio-desktop/releases/download/v22.1.2/draw.io-22.1.2-windows-no-installer.exe
* **GitHub CLI**
  * https://github.com/cli/cli/releases/download/v2.39.1/gh_2.39.1_windows_386.msi

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
  * Retrieved November 28, 2023, 
  * from https://www.tutorialspoint.com/sqlite/sqlite_using_autoincrement.htm
* SQLite - Data Type. (n.d.). Tutorialspoint. 
  * Retrieved November 28, 2023, 
  * from https://www.tutorialspoint.com/sqlite/sqlite_data_types.htm

[design1]: ../02_resources/images/realize-design-database-schema.png
[design2]: ../02_resources/images/realize-design-flowchart-word-picker.png

[issue 4]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/4
[issue 5]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/5
[issue 6]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/6
[issue 19]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/19
[issue 21]: https://github.com/tbz-neil-devlin/m431_demo_database/issues/21

[setup1]: ../02_resources/images/realize-setup-git-clone.JPG
[setup2]: ../02_resources/images/realize-setup-git-directories-01.JPG
[setup3]: ../02_resources/images/realize-setup-git-directories-02.JPG
[setup4]: ../02_resources/images/realize-setup-git-directories-03.JPG
[setup5]: ../02_resources/images/realize-setup-git-directories-04.JPG
[setup6]: ../02_resources/images/realize-setup-github-cli-01.JPG

[sketch1]: ../02_resources/images/realize-design-sketch-directories.jpeg