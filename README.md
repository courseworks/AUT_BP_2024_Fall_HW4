# Question 1: Swapping Values of Two Matrices

## Problem Description

Write a function that swaps the values of two square matrices of the same dimension. Each element in the first matrix should be swapped with the element at the same position in the second matrix. The function should work directly with the matrices (i.e., modify them in place) and return nothing.

### Function Prototype

```c
void swap_matrices(int *matrix1, int *matrix2, int dimension);
```

### Function Parameters

-   `int *matrix1`: A pointer to the first square matrix.
-   `int *matrix2`: A pointer to the second square matrix.
-   `int dimension`: The dimension of the square matrices (i.e., the number of rows or columns).

### Constraints

1. Both matrices are square and have the same dimensions.
2. All elements in the matrices are of type `int`.

### Example

#### Input

Matrix 1 (before swapping):

```
1  2  3
4  5  6
7  8  9
```

Matrix 2 (before swapping):

```
9  8  7
6  5  4
3  2  1
```

Dimension: `3`

#### Output

Matrix 1 (after swapping):

```
9  8  7
6  5  4
3  2  1
```

Matrix 2 (after swapping):

```
1  2  3
4  5  6
7  8  9
```

### Pitfalls to Avoid

-   Ensure you handle all elements of the matrices properly. A mismatch in dimension calculations will lead to incorrect swaps.
-   Remember to use pointer arithmetic to traverse through the elements.
