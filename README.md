#Wireframe model

A program that represents a landscape as a 3D object in which all surfaces are outlined in lines. You can read the subject [here](00_Projects/03_Graphic/fdf.pdf).

This project uses 42 graphical library, **Minilibx**, and is entirely written in C. It takes a .txt file as an input. The file has to respect the following format :

Numbers represent the height of the "hills" and can be negative. The number of columns and the number of lines can be different.

To run the program :
* run make
* ./fdf name_of_map.txt

Pressing Z button increases the heights
Pressing -> and <- arrows makes the map rotate



