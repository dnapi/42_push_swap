# Push swap
Project at Hive ( School 42 in Helsinki). 
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

## Objective

The objective is to sort stack A in ascending order using a combination of the provided operations. The initial configuration of stack B is empty stack.

## Constraints

- The algorithm must achieve the sorting using the minimum number of operations.
- The algorithm must be efficient and run within reasonable time constraints.

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


