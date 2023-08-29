# Plotting-with-Polish-notation

## About

This program builds graphs of the introduced functions, breaking them into tokens and translating them into Polish notation.

***

## Functionality

* The program takes a function as input and builds its graph with a definition area from 0 to 4Pi and a range of values from -1 to 1. 

* The coordinate center is located on the left border in the center. The abscissa axis is directed to the right, and the ordinate axis is down.

* Available operations: +, -, *, /, (), sin, cos, tan, ctg, ln, sqrt.

* There is no enter validation so in case of incorrect input program can crash. In correct input should be only available operations, integer numbers and 'x' (no whitespaces).

***

## Architecture of the program

* The program consists of 6 modules: graph.c, polish_not.c, calc.c, draw_graph.c, queue.c, stack.c.

* _graph.c_<br>
It is an entry module, where functions to read an input, translate it into Polish notation and plot a graph based on it are called.

* *polish_not.c*<br>
This module is responsible for reading the string, splitting it into tokens and translating it into Polish notation.

* _calc.c_<br>
Here the value of the expression is calculated based on its Polish notation and the value of x.

* *draw_graph.c*<br>
This module is responsible for the construction and output of the graph.

* _queue.c stack.c_<br>
In these libraries custom stack and queue data structures, which are used in other modules, are implemented.