# Algorithms

Coursework exercises and practical implementations of foundational algorithms in C, C++, and Java.

This repository explores greedy algorithms, divide and conquer, dynamic programming, sorting, and algorithm performance analysis. Most programs are interactive or generate their own input, then display intermediate steps, results, timing information, and complexity details.

## Repository contents

| File | Language | Topic | What it demonstrates |
| --- | --- | --- | --- |
| [`FractionalKnapsack.cpp`](FractionalKnapsack.cpp) | C++ | Fractional Knapsack | Greedy selection based on profit-to-weight ratio. Accepts item data and knapsack capacity, then reports the selected fractions, profit, and execution time. |
| [`FractionalKnapsackCaseStudy.cpp`](FractionalKnapsackCaseStudy.cpp) | C++ | Investment Portfolio Allocation | A fractional-knapsack case study that allocates a budget among assets according to expected-return-to-cost ratio. |
| [`MergeSortBest.c`](MergeSortBest.c) | C | Merge Sort — Best-Case Input | Runs merge sort on already sorted input and reports recursive processing, timing, and space complexity. |
| [`MergeSortAvg.c`](MergeSortAvg.c) | C | Merge Sort — Average-Case Input | Generates a random array of unique values, sorts it with merge sort, and measures execution time. |
| [`MergeSortWorst.c`](MergeSortWorst.c) | C | Merge Sort — Worst-Case Input | Runs merge sort on reverse-sorted input and reports the recursive merge process and timing. |
| [`QuickSortBest.cpp`](QuickSortBest.cpp) | C++ | Quick Sort — Best-Case Demonstration | Sorts an already sorted array of 300 elements while counting comparisons and swaps. |
| [`QuickSortAvg.cpp`](QuickSortAvg.cpp) | C++ | Quick Sort — Average-Case Demonstration | Generates a random array of 200–500 elements, sorts it, and reports comparisons, swaps, timing, and case classification. |
| [`QuicksortWorst.cpp`](QuicksortWorst.cpp) | C++ | Quick Sort — Worst-Case Demonstration | Sorts a reverse-sorted array of 300 elements using the last element as the pivot. |
| [`TSPDynamicProgramming.java`](TSPDynamicProgramming.java) | Java | Travelling Salesperson Problem | Uses dynamic programming to find a minimum-cost tour from a distance matrix and reconstructs the optimal path. |

## Algorithms and complexity

| Algorithm | Time complexity | Space complexity |
| --- | --- | --- |
| Fractional Knapsack | `O(n log n)` | `O(n)` |
| Merge Sort | `O(n log n)` in best, average, and worst cases | `O(n)` auxiliary space plus `O(log n)` recursion stack |
| Quick Sort | `O(n log n)` best/average case; `O(n²)` worst case | `O(n)` worst-case recursion stack |
| TSP Dynamic Programming | `O(n² × 2ⁿ)` | `O(n × 2ⁿ)` |

The case-specific source files are intended for experimentation and comparison. Actual runtime depends on the input size, compiler, machine, and diagnostic output printed by each program.

## Requirements

- A C compiler with C99 support and POSIX `clock_gettime` support for the merge-sort programs.
- A C++ compiler with C++11 or later support.
- Java Development Kit (JDK) 8 or later.

## Compile and run

### Fractional Knapsack

```bash
g++ -std=c++11 FractionalKnapsack.cpp -o fractional_knapsack
./fractional_knapsack
```

### Fractional Knapsack case study

```bash
g++ -std=c++11 FractionalKnapsackCaseStudy.cpp -o portfolio_allocator
./portfolio_allocator
```

### Merge Sort

```bash
gcc -std=c99 MergeSortBest.c -o merge_sort_best
./merge_sort_best

gcc -std=c99 MergeSortAvg.c -o merge_sort_average
./merge_sort_average

gcc -std=c99 MergeSortWorst.c -o merge_sort_worst
./merge_sort_worst
```

On systems where `clock_gettime` requires an additional library, append `-lrt` to the compilation command.

### Quick Sort

```bash
g++ -std=c++11 QuickSortBest.cpp -o quick_sort_best
./quick_sort_best

g++ -std=c++11 QuickSortAvg.cpp -o quick_sort_average
./quick_sort_average

g++ -std=c++11 QuicksortWorst.cpp -o quick_sort_worst
./quick_sort_worst
```

### Travelling Salesperson Problem

```bash
javac TSPDynamicProgramming.java
java TSPDynamicProgramming
```

The Java program asks for the number of cities and then reads the complete distance matrix from standard input.

## Learning objectives

This repository demonstrates:

- Greedy decision-making and ratio-based selection.
- Divide-and-conquer recursion through merge sort and quick sort.
- Best-, average-, and worst-case input analysis.
- Dynamic programming with bitmask-based state representation.
- Runtime measurement, operation counting, and space-complexity analysis.
- Practical implementations across C, C++, and Java.
