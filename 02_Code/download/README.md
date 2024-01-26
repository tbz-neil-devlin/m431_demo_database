# Installation
* Unzip word-picker.gz to a local directory

# Create a list of words
* Create a list of words in a text file and save it to the directory ./lists


# Create a database as follows
* If desired the word lenght can be adjusted
> export M431_MIN_WORD_LENGTH=3  
> export M431_MAX_WORD_LENGTH=10  
> 
> cd ./bin  
> ./create-word-database.exe  
> Please enter the full pathname of the database file: ../db/mydatabase  
> Please enter the full pathname of the text file: ../lists/myfile  

# Run word picker
* Setting this variable will open the database without asking  
> export M431_DATABASE_FILE="<mydatabase>"  
> 
> cd ./bin  
> ./word-picker.exe  
> Please enter the full pathname of the database file: ../db/mydatabase  

