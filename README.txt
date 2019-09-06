This program reads a file containing a square matrix representing a kiwi farm.
The program will read the matrix 7 times (each time representing a new day of harvest)
and then once more to represent one more harvest at the end of the 7th day.

The numbers in the matrix represent the ripeness of the kiwis (1-5 being underripe, 6-8 being ripe, and 9+ being rotten).

If at least 50% of a given row in the matrix is "ripe", the entire row will be harvested.
The program then counts the total number of ripe kiwis and the total number of rotten kiwis. Underripe kiwis are ignored.

This information, along with the state of the matrix after the final harvest, will be recorded in a new file.

The names of the files to be used as input and output must be announced in the command line.
There is a class within the program that will parse the information.
The format must be: "input=[filename].txt output=[filename].txt"
for example: "input=farm1.txt output=result1.txt"

The input file must be in the following format:

[positive integer representing the size of the matrix]\n
MATRIX

an example of the contents of a file may be:
4
1 2 3 4
4 3 2 1
5 6 7 8
8 7 6 5