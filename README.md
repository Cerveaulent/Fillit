# Fillit

An program that assembles ***a given Tetriminos set*** altogether in the ***smallest possible square***.

The goal is to familiarize ourselves with ***recurrence problematic*** in programming.

 Tetriminos are 4-blocks geometric figures from the game Tetris. 
 
 Here's an example of valid and invalid Tetriminos :

Valid Tetriminos | Invalid Tetriminos
------------ | -------------
![img](https://github.com/Cerveaulent/Fillit/blob/master/Valid_tetri.png)| ![img](https://github.com/Cerveaulent/Fillit/blob/master/Invalid_tetri.png)

A rotated tetrimino is considered as a different Tetrimino

The program *reads a text file* containning the set of tetriminos and put them together in order to make the ***smallest possible square*** using ***all the tetriminos***.

The specificities regarding the formatting rules for the text file can be found in the subject, [section V.1 Program Entry](https://github.com/Cerveaulent/Fillit/tree/master/subjects)

The program outputs a square filled with letters where every letter has been affected to a Tetrimino as such :

![img](https://github.com/Cerveaulent/Fillit/blob/master/fillit_output.png)

<h4> Launching the program
 
 ###
 
 - compile using ``make`` command in the fillit directory
 
 - then type ``./fillit the_text_file.txt``


[Fillit main page](https://github.com/Cerveaulent/Fillit) 

[42 Lyon School Projects](https://github.com/Cerveaulent/42_Lyon_School_Projects/blob/master/README.md)
