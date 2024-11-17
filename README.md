<h1 align="center">
<strong>AUT_BP_2024_Fall Homework 4</strong>
</h1>

<p align="center">
<strong> Deadline: 2nd of Azar - Friday - 23:59 o'clock</strong>
</p>

---

## **Question 1: Swapping Values of Two 2D Arrays**

### **Objective**

Implement a function in C that swaps the elements of two two-dimensional arrays of integers. The function should take two 2D arrays and their respective dimensions as inputs. It will swap each corresponding element between the two arrays. The function should return a boolean value indicating whether the operation was successful or not.

### **Function Prototype**

```c
#include <stdbool.h>

bool swap2DArrays(int *arr1, int *arr2, int rows, int cols);
```

### **Detailed Description**

You are required to write a function named `swap2DArrays` that swaps the elements of two 2D integer arrays. The function must adhere to the following specifications:

1. **Parameters:**
   - `int *arr1`: Pointer to the first 2D array.
   - `int *arr2`: Pointer to the second 2D array.
   - `int rows`: The number of rows in each array.
   - `int cols`: The number of columns in each array.

2. **Operation:**
   - The function should iterate through each element of both arrays and swap the elements at the same positions.

3. **Return Value:**
   - Return `true` if the swap operation is successful.
   - Return `false` if the swap operation fails due to invalid dimensions or any other reason.

### **Example**

#### **Input**

Suppose we have the following two 2D arrays, each with 2 rows and 3 columns:

```c
int array1[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

int array2[2][3] = {
    {7, 8, 9},
    {10, 11, 12}
};
```

#### **Function Call**

```c
bool result = swap2DArrays((int *)array1, (int *)array2, 2, 3);
```

#### **Expected Output**

After calling the function, the arrays should be swapped as follows:

```c
// array1 after swap
{
    {7, 8, 9},
    {10, 11, 12}
};

// array2 after swap
{
    {1, 2, 3},
    {4, 5, 6}
};
```

The function should return `true`, indicating that the swap was successful.

### **Notes**

- Pay attention to pointer arithmetic when accessing elements of the 2D arrays.
- Ensure that you handle edge cases, such as zero or negative dimensions, appropriately.
- Test your function with different array sizes to ensure its robustness.
- Test your code with unit-tests and modify your code if needed.

---

## **Question 2: In-Place Transpose of a Square Matrix**

### **Objective**

Implement a function in C that transposes a square matrix (2D array) in-place. The function should take a square matrix and its dimension as inputs. It should modify the original matrix by transposing it. The function should return a boolean value indicating whether the operation was successful or not.

### **Function Prototype**

```c
#include <stdbool.h>

bool transposeMatrix(int *matrix, int dimension);
```

### **Detailed Description**

You are required to write a function named `transposeMatrix` that transposes a square matrix in-place. The function must adhere to the following specifications:

1. **Parameters:**

   - `int *matrix`: Pointer to the first element of the square matrix.
   - `int dimension`: The dimension (number of rows and columns) of the square matrix.

2. **Operation:**

   - **Transpose of a Matrix:** The transpose of a matrix is obtained by flipping the matrix over its main diagonal. In other words, the element at position `(i, j)` in the original matrix moves to position `(j, i)` in the transposed matrix.
   - The function should modify the original matrix by swapping elements symmetrically over the main diagonal.

3. **Return Value:**

   - Return `true` if the transpose operation is successful.
   - Return `false` if the operation fails due to any reason (e.g., invalid dimension).

### **Example**

#### **Input**

Suppose we have the following square matrix of dimension 3:

```c
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

#### **Function Call**

```c
bool result = transposeMatrix((int *)matrix, 3);
```

#### **Expected Output**

After calling the function, the matrix should be transposed in-place:

```c
// matrix after transpose
{
    {1, 4, 7},
    {2, 5, 8},
    {3, 6, 9}
};
```

The function should return `true`, indicating that the transpose was successful.

### **Constraints**

- The dimension must be a positive integer.
- Do not use dynamic memory allocation (`malloc`, `free`) for this problem.
- The function must perform the transpose in-place without using an additional matrix.


### **Notes**

- **Edge Cases:** Handle edge cases such as zero or negative dimensions by returning `false` and not modifying the matrix.

---

## **Question 3: Sorting an Array with Multiple Algorithms**

### **Objective**

Implement a function in C that sorts an array of doubles using one of four sorting algorithms based on a given character input. The function should also measure and return the time elapsed during the sorting process.
- **Merge Sort Implementation is Optional, you will get Bonus Points if you implement it**

### **Function Prototype**

```c
#include <time.h>

clock_t sortArray(double *array, int size, char algorithm);
```

### **Detailed Description**

You are required to write a function named `sortArray` that sorts an array of doubles using the specified sorting algorithm. The function must adhere to the following specifications:

1. **Parameters:**

   - `double *array`: Pointer to the array of doubles to be sorted.
   - `int size`: The number of elements in the array.
   - `char algorithm`: A character indicating which sorting algorithm to use:
     - `'b'` or `'B'`: **Bubble Sort**
     - `'i'` or `'I'`: **Insertion Sort**
     - `'s'` or `'S'`: **Selection Sort**
     - `'m'` or `'M'`: **Merge Sort**

2. **Return Value:**

   - The function returns a `clock_t` value representing the time elapsed during the sorting process.

3. **Sorting Algorithms:**

   - **Bubble Sort:** Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
   - **Insertion Sort:** Builds the final sorted array one item at a time, with the movement of elements.
   - **Selection Sort:** Divides the input list into two parts: a sorted sublist and an unsorted sublist, and repeatedly selects the smallest (or largest) element from the unsorted sublist.
   - **Merge Sort:** A divide and conquer algorithm that divides the input array into two halves, calls itself for the two halves, and then merges the sorted halves.

4. **Time Measurement:**

   - Use the `clock()` function from `time.h` to measure the time before and after the sorting algorithm runs.
   - The elapsed time is calculated as `end_time - start_time`.

5. **Behavior:**

   - If the `algorithm` character does not match any of the specified options, the function should not sort the array and should return `0`.
   - Handle both uppercase and lowercase characters for the algorithm selection.

### **Example**

#### **Input**

Suppose we have the following array of doubles:

```c
double array[] = {5.2, 3.1, 4.8, 1.6, 2.9};
int size = 5;
char algorithm = 'i'; // Use Insertion Sort
```

#### **Function Call**

```c
clock_t elapsed_time = sortArray(array, size, algorithm);
```

#### **Expected Output**

After calling the function, the array should be sorted in ascending order:

```c
// array after sorting
{1.6, 2.9, 3.1, 4.8, 5.2};
```

The function returns the elapsed time during the sorting process.

### **Constraints**

- The array must not be `NULL`, and `size` must be greater than `0`.
- Do not use any built-in sorting functions like `qsort`.
- Implement the sorting algorithms yourself using pointers.
- Do not use dynamic memory allocation (`malloc`, `free`) for this problem. **(You can and should use `malloc` for merge sort, and you are permitted to do so.)**

### **Notes**

- **Time Measurement:**
  - The `clock()` function returns the number of clock ticks since the program started.
  - To get the elapsed time in seconds, you can divide the clock ticks by `CLOCKS_PER_SEC`.
- **Algorithm Implementation:**
  - Implement each sorting algorithm in its own function.
  - Use pointer arithmetic to access and manipulate array elements.

---

## Contact

If you have any questions regarding the homework, feel free to reach out:

-   **Teaching Assistant**: Seyyed Mohammad Hamidi
-   **Telegram Group**: [t.me/AUT_BP_Fall_2024](https://t.me/AUT_BP_Fall_2024)
-   **Github**: [github.com/smhamidi](https://github.com/smhamidi)

---

<p align="center">
  <img src="./resource/Already_Broken.jpg" alt="Already Broken" style="width: 40%;">
</p>

**Best Regards, [Hamidi](https://github.com/smhamidi)**
