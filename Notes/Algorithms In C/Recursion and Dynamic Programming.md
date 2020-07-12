Recursion and Dynamic Programming

## Tips for recursive programs

- Things done before the return call are done in order
- Things done after the return call are done in reverse-order
- Divide an conquer. Usually recursive functions have two returns and we divide the problem into sub problems, helps for fractals.

## Bottom up dynamic programming

- Memorize previous results to calculate curret result
- starts from the smalles valuest

### Knapsack problem
- Resolved with a table of n by w columns, where n is the number of items and w is the total size. To fill a square on the table, the program iterates all over the previous row to find if it's viable to add the weight of the next item into the knapsack.

## Top-down dynamic programming/Memoization

- Allows to use recursive functions moe efficiently
- Rememebers all computed values to avoid computing again