Sorting methods

## Simple Sorting methods
- May be adequate for small sizes
- Must not look for a faster method if the data processing is slower than the sorting.
- *Internal* if it fits into memory.
- *External* if it's inside a storage and must be obtained in large blocks.
- *Nonadaptive* sort is where the sequence of operations is independent of the order of the data.(Well suited for hardware implementation)
- *Adaptive* sort performs different sequences of operations.
- A *Stable* sorting mehod preserves the relative order of items with duplicated keys.
- An *Inversion* is a pair of keys that are out of order in the file.
- A *Permutation* is a rearrangement of the N distinct nonnegative integers less than N.
- **Qsort** in C, is a pointer sort function that takes four arguments: the array, the number of items, the size of the items, and a pointer to a compare function.
- *In situ permutation* or *in-place rearrangement* helps sort data according to index arrays. Must leave an empty place to be filled by the next index.

### Selection sort
It's called selection sort, because it constantly selects the smallest remaining element.
- In a loop it looks for the smallest element to move it.
- The running times depends very little on the amount of order already in the file.
- It is the best for applications where moving data is way more expensive than making comparisons.

## Insertion sort
This sorts iterates over the file with increasing range, exchanging all pairs of keys that are not in order as it goes through the file.
- The initial order of the input keys affects the running time.
- A sentinel key helps making the inner loop smaller, and the program faster.
- It is efficient for sorted files where few modifications have been made.
- Best if comparisons are expensive.

## Bubble sort
- Not highly dependant on the input and inefficient algorithm.
- Alternating the scan between beginning to end and end to beginning, gives shaker sort. Which is quicker.

## Shell sort
- The idea is to compare by moving between gaps of the file.
- Create a different increment each interation.
- Consider the arithmetical interactions among the increments, such as the size of their common divisors.
- A good increment speeds up to 25%.
- Knuth recommended a ratio of a third for increments.

## Key-Indexed sorting
- Clever sorting method for small keys and small range of keys
- Uses keys as indexes for an array that counts the repetition of each key and orders elements in a new array

## Quicksort
Quick sort is the most widely used sorting method. It requires time proportional to *NlogN* on the average to sort *N* items, uses an auxiliary stack and has a short inner loop. 
- It is not stable, takes N2 in worst case, and it's fragile, a mistake can go unnoticed.
- For a quicksort that starts with an edge pivot for an already sorted file, it will create degenerate prtitions.
- A non recursive program is doable with a stack structure, pushing the largest file last helps alleviating stack usage.
- For lists, a stable quicksort can be done by creating two lists on each partitioning, one with keys less than or greater than the pivot, then merging those lists.
- A **probabilistic algorithm** takes advantage of small probabilities for worst-case scenarios to achieve good performance.
### Ways to Improve Quicksort
* Using a stack data structure to make it non-recursive.
* Avoiding processing subfiles of size less than *M*, then insertion sort the remaining file. Or insertion sort each small file.
* 