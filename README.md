# push_swap

## Description

This project is about sorting algorithms and their complexities. The challange is to sort data on two stacks, using the **smallest number of moves** and a limited set of operations.   
The files have to compile with -Wall -Werror -Wextra and to be free of memory leaks. The written code must follow certain rules, which are specified in a standard of the school 42.

### Allowed functions

```
° write
◦ read
◦ malloc
◦ free
◦ exit
```
 Global variables are forbidden.

## Mandatory Part

The goal is to write a program that calculates and displays the smallest program on the standard output, which uses the push_swap command language and sorts the integer arguments received.

#### Set of operations:
|Op | Stack | Description|
| - | - | - |
| **sa** | *swap a* | swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| **sb** | *swap b* | swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| **ss** | *swap a & b* | sa and sb at the same time. |
| **pa** | *push a* | take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| **pb** | *push b* | take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| **ra** | *rotate a*| shift up all elements of stack a by 1. The first element becomes the last one. |
| **rb** | *rotate b* | shift up all elements of stack b by 1. The first element becomes the last one. |
| **rr** | *rotate a & b* | ra and rb at the same time. |
| **rra** | *reverse rotate a*| shift down all elements of stack a by 1. The last element becomes the first one. |
| **rrb** | *reverse rotate b*| shift down all elements of stack b by 1. The last element becomes the first one. |
| **rrr** | *reverse rotate a & b*| rra and rrb at the same time. |

At the end, stack b must be empty and all values must be sorted into stack a in ascending order.

#### Usage

The input contains of a random amount of negative and/or positive numbers that are not duplicated.  

Example execution:
```
	./push_swap 5 2 3 1 4
```
To check the sorting, use the checker as follows:
```
	ARG="5 2 3 1 4"; ./push_swap $ARG | ./checker_linux $ARG
```

#### Efficiency
This push_swap project sorts:   
5 random values in an average of 8 moves.  
100 random values in an average of 650 moves.   
500 random values in an average of 5750 moves.


## Objectives

* Sorting algorithms
* Battery concept and handling elements
* Algorithm implementation


## Skills

* Unix
* Imperative programming
* Rigor
* Algorithms & AI


## Getting Started

### Clone the repository
```shell
git clone git@github.com:wolumen/push_swap.git
cd push_swap
```

### Compiling

The Makefile has the following rules:

| Rule | Function |
| - | - |
| ``make`` | Compiles push_swap executable. |
| ``make clean`` | Deletes all object files. |
| ``make fclean`` | Deletes the object files and the executable. |
| ``make re`` | Makes ``fclean`` and ``make`` again. |
| ``make test`` | Runs the program with provided arguments.|
| ``make memcheck`` | Runs the program with Valgrind and provided arguments. A logfile will be created. |
