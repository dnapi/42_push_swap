# Push swap
School 42 project @ [Hive Helsinki](https://www.hive.fi/en/)

Algotrithm is inspired by [link](https://www.youtube.com/watch?v=2aMrmWOgLvU). 
We used cyclic buffer implemented on arrays. Allowed external functions are read, write, malloc and free. The code is written according the [Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).
The average number of operation is 5040 for 500 elemetns and 600 for 100 elements.

## Overview

Push Swap is an algorithmic problem that involves sorting a stack of integers using two stacks and a limited set of operations. The goal is to arrange the integers in ascending order using the fewest possible operations.

## Rules

- The algorithm is given two stacks, A and B, initially containing a set of integers.
- The allowed operations are:
  - `sa`: Swap the first two elements of stack A.
  - `sb`: Swap the first two elements of stack B.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa`: Push the first element from stack A onto stack B.
  - `pb`: Push the first element from stack B onto stack A.
  - `ra`: Rotate all elements of stack A upwards (the first element becomes the last).
  - `rb`: Rotate all elements of stack B upwards.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra`: Rotate all elements of stack A downwards (the last element becomes the first).
  - `rrb`: Rotate all elements of stack B downwards.
  - `rrr`: Perform `rra` and `rrb` simultaneously.

## Example

Consider the following initial configuration of stack A: 2 1 3 6 5 8, stack B is empty:

`>./push_swap 2 1 3 6 5 8`  
sa  
pb  
pb  
pb  
sa  
pa  
pa  
pa  

## Requirements
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Global variables are forbidden.
- You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separated by a ’\n’ and nothing else.
- The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
- If no parameters are specified, the program must not display anything and give the prompt back.
- In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.
