# push_swap
The goal is to find the minimum number of instructions to sort the set of integers received as argument.

- At the beginning:
  - The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
  - The stack b is empty
- To sort in ascending order numbers into stack a, these are the avaible instructions:
  - `sa` _(swap a)_: Swap the first 2 elements at the top of stack a.
  - `sb` _(swap b)_: Swap the first 2 elements at the top of stack b. 
  - `ss` : sa and sb at the same time.
  - `pa` _(push a)_: Take the first element at the top of b and put it at the top of a. 
  - `pb` _(push b)_: Take the first element at the top of a and put it at the top of b. 
  - `ra` _(rotate a)_: Shift up all elements of stack a by 1. The first element becomes the last one.
  - `rb` _(rotate b)_: Shift up all elements of stack b by 1. ''
  - `rr` : ra and rb at the same time.
  - `rra` _(reverse rotate a)_: Shift down all elements of stack a by 1. The last element becomes the first one.
  - `rrb` _(reverse rotate b)_: Shift down all elements of stack b by 1. ''
  - `rrr` : rra and rrb at the same time.
