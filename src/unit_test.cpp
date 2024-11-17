#include <gtest/gtest.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern "C" {
#include "Q1_SwapArrays.h"
#include "Q2_TransposeMatrix.h"
#include "Q3_SortArray.h"
}

// #####################################
// ############ Q1 Tests ###############
// #####################################

// Helper function to compare two arrays
bool arraysAreEqual(int *arr1, int *arr2, int rows, int cols) {
	for (int i = 0; i < rows * cols; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

// Test Case 1: Successful Swap with Valid Dimensions
TEST(Swap2DArraysTest, SuccessfulSwap) {
	int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};

	int array2[2][3] = {{7, 8, 9}, {10, 11, 12}};

	int expectedArray1[2][3] = {{7, 8, 9}, {10, 11, 12}};

	int expectedArray2[2][3] = {{1, 2, 3}, {4, 5, 6}};

	bool result = swap2DArrays((int *)array1, (int *)array2, 2, 3);

	EXPECT_TRUE(result);
	EXPECT_TRUE(arraysAreEqual((int *)array1, (int *)expectedArray1, 2, 3));
	EXPECT_TRUE(arraysAreEqual((int *)array2, (int *)expectedArray2, 2, 3));
}

// Test Case 2: Swap with Negative Dimensions
TEST(Swap2DArraysTest, NegativeDimensions) {
	int array1[2][3] = {};
	int array2[2][3] = {};

	bool result = swap2DArrays((int *)array1, (int *)array2, -2, -3);

	EXPECT_FALSE(result) << "If either of the dimensions are negative, then "
							"you have to return false.";
}

// Test Case 3: Minimal Array Size (1x1)
TEST(Swap2DArraysTest, MinimalArraySize) {
	int array1[1][1] = {{1}};
	int array2[1][1] = {{2}};

	int expectedArray1[1][1] = {{2}};
	int expectedArray2[1][1] = {{1}};

	bool result = swap2DArrays((int *)array1, (int *)array2, 1, 1);

	EXPECT_TRUE(result) << "Array of size 1*1 failed to swap.";
	EXPECT_EQ(array1[0][0], expectedArray1[0][0]);
	EXPECT_EQ(array2[0][0], expectedArray2[0][0]);
}

// Test Case 4: Large Arrays
TEST(Swap2DArraysTest, LargeArrays) {
	const int rows = 100;
	const int cols = 100;
	int array1[rows][cols];
	int array2[rows][cols];

	// Initialize arrays
	for (int i = 0; i < rows * cols; i++) {
		((int *)array1)[i] = i;
		((int *)array2)[i] = i + 10000;
	}

	bool result = swap2DArrays((int *)array1, (int *)array2, rows, cols);

	EXPECT_TRUE(result) << "Failed to swap large arrays.";

	// Verify swap
	for (int i = 0; i < rows * cols; i++) {
		EXPECT_EQ(((int *)array1)[i], i + 10000)
			<< "Large arrays incorrectly swapped.";
		EXPECT_EQ(((int *)array2)[i], i) << "Large arrays incorrectly swapped.";
	}
}

// Test Case 5: Arrays with Same Pointers
TEST(Swap2DArraysTest, SameArrays) {
	int array[2][3] = {{1, 2, 3}, {4, 5, 6}};

	bool result = swap2DArrays((int *)array, (int *)array, 2, 3);

	// Swapping the same array should proceed without errors
	EXPECT_TRUE(result);

	// The array should remain unchanged
	int expectedArray[2][3] = {{1, 2, 3}, {4, 5, 6}};

	EXPECT_TRUE(arraysAreEqual((int *)array, (int *)expectedArray, 2, 3))
		<< "Swapping the same array should proceed without errors.";
}

// Test Case 6: Null Pointers
TEST(Swap2DArraysTest, NullPointers) {
	int *array1 = nullptr;
	int *array2 = nullptr;

	bool result = swap2DArrays(array1, array2, 2, 3);

	// The function should handle null pointers and return false
	EXPECT_FALSE(result)
		<< "You should be carefull with pointers and first check if they are "
		   "nullptr or not, return false if they are.";
}

// Test Case 7: Verify No Partial Swap on Failure
TEST(Swap2DArraysTest, NoPartialSwapOnFailure) {
	int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};

	int array2[2][3] = {{7, 8, 9}, {10, 11, 12}};

	int originalArray1[2][3];
	int originalArray2[2][3];

	// Copy original arrays
	memcpy(originalArray1, array1, sizeof(array1));
	memcpy(originalArray2, array2, sizeof(array2));

	// Intentionally pass invalid dimensions
	bool result = swap2DArrays((int *)array1, (int *)array2, -2, 3);

	EXPECT_FALSE(result);

	// Verify that arrays remain unchanged
	EXPECT_TRUE(arraysAreEqual((int *)array1, (int *)originalArray1, 2, 3))
		<< "You returned false, but you have partially changed the arrays, you "
		   "have to check the conditions at first";
	EXPECT_TRUE(arraysAreEqual((int *)array2, (int *)originalArray2, 2, 3))
		<< "You returned false, but you have partially changed the arrays, you "
		   "have to check the conditions at first";
	;
}

// #####################################
// ############ Q2 Tests ###############
// #####################################

// Helper function to compare two matrices
bool matricesAreEqual(int *mat1, int *mat2, int dimension) {
	for (int i = 0; i < dimension * dimension; i++) {
		if (mat1[i] != mat2[i]) {
			return false;
		}
	}
	return true;
}

// Test Case 1: Successful Transpose of a 3x3 Matrix
TEST(TransposeMatrixTest, SuccessfulTranspose3x3) {
	int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

	int expectedMatrix[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};

	bool result = transposeMatrix(int *matrix, 3);

	EXPECT_TRUE(result)
		<< "Expected transposeMatrix to return true for valid input.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)expectedMatrix, 3))
		<< "The matrix was not correctly transposed.";
}

// Test Case 2: Successful Transpose of a 4x4 Matrix
TEST(TransposeMatrixTest, SuccessfulTranspose4x4) {
	int matrix[4][4] = {
		{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	int expectedMatrix[4][4] = {
		{1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 16}};

	bool result = transposeMatrix((int *)matrix, 4);

	EXPECT_TRUE(result)
		<< "Expected transposeMatrix to return true for valid input.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)expectedMatrix, 4))
		<< "The matrix was not correctly transposed.";
}

// Test Case 3: Transpose of a 1x1 Matrix
TEST(TransposeMatrixTest, Transpose1x1Matrix) {
	int matrix[1][1] = {{42}};
	int expectedMatrix[1][1] = {{42}};

	bool result = transposeMatrix((int *)matrix, 1);

	EXPECT_TRUE(result)
		<< "Expected transposeMatrix to return true for a 1x1 matrix.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)expectedMatrix, 1))
		<< "A 1x1 matrix should remain unchanged after transposition.";
}

// Test Case 4: Zero Dimension Matrix
TEST(TransposeMatrixTest, ZeroDimensionMatrix) {
	int matrix[1][1] = {{0}};

	bool result = transposeMatrix((int *)matrix, 0);

	EXPECT_FALSE(result)
		<< "Expected transposeMatrix to return false for zero dimension.";
}

// Test Case 5: Negative Dimension Matrix
TEST(TransposeMatrixTest, NegativeDimensionMatrix) {
	int matrix[1][1] = {{0}};

	bool result = transposeMatrix((int *)matrix, -3);

	EXPECT_FALSE(result)
		<< "Expected transposeMatrix to return false for negative dimension.";
}

// Test Case 6: Large Square Matrix
TEST(TransposeMatrixTest, LargeSquareMatrix) {
	const int dimension = 10;
	int matrix[dimension][dimension];
	int expectedMatrix[dimension][dimension];

	// Initialize the matrix and expectedMatrix
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			matrix[i][j] = i * dimension + j;
			expectedMatrix[j][i] = i * dimension + j;
		}
	}

	bool result = transposeMatrix((int *)matrix, dimension);

	EXPECT_TRUE(result)
		<< "Expected transposeMatrix to return true for large matrices.";
	EXPECT_TRUE(
		matricesAreEqual((int *)matrix, (int *)expectedMatrix, dimension))
		<< "The large matrix was not correctly transposed.";
}

// Test Case 7: Matrix with Duplicate Elements
TEST(TransposeMatrixTest, MatrixWithDuplicateElements) {
	int matrix[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

	int expectedMatrix[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

	bool result = transposeMatrix((int *)matrix, 3);

	EXPECT_TRUE(result) << "Expected transposeMatrix to return true for matrix "
						   "with duplicate elements.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)expectedMatrix, 3))
		<< "The matrix with duplicate elements was not correctly transposed "
		   "(should remain the same).";
}

// Test Case 8: Matrix with Negative Elements
TEST(TransposeMatrixTest, MatrixWithNegativeElements) {
	int matrix[2][2] = {{-1, -2}, {-3, -4}};

	int expectedMatrix[2][2] = {{-1, -3}, {-2, -4}};

	bool result = transposeMatrix((int *)matrix, 2);

	EXPECT_TRUE(result) << "Expected transposeMatrix to return true for matrix "
						   "with negative elements.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)expectedMatrix, 2))
		<< "The matrix with negative elements was not correctly transposed.";
}

// Test Case 9: Verify No Partial Transpose on Failure
TEST(TransposeMatrixTest, NoPartialTransposeOnFailure) {
	int matrix[2][2] = {{1, 2}, {3, 4}};

	int originalMatrix[2][2];
	memcpy(originalMatrix, matrix, sizeof(matrix));

	bool result = transposeMatrix((int *)matrix, 0);

	EXPECT_FALSE(result)
		<< "Expected transposeMatrix to return false for zero dimension.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)originalMatrix, 2))
		<< "transposeMatrix should not modify the matrix if the operation "
		   "fails.";
}

// Test Case 10: Null Pointer as Matrix
TEST(TransposeMatrixTest, NullPointerMatrix) {
	int *matrix = nullptr;

	bool result = transposeMatrix(matrix, 3);

	EXPECT_FALSE(result) << "Expected transposeMatrix to return false when "
							"matrix pointer is null. always check pointers for "
							"nullptr before using it.";
}

// Test Case 12: Same Element Values After Double Transpose
TEST(TransposeMatrixTest, DoubleTransposeReturnsOriginalMatrix) {
	int matrix[3][3] = {{5, 4, 3}, {2, 1, 0}, {-1, -2, -3}};

	int originalMatrix[3][3];
	memcpy(originalMatrix, matrix, sizeof(matrix));

	// First Transpose
	bool result1 = transposeMatrix((int *)matrix, 3);
	EXPECT_TRUE(result1) << "First transpose failed.";

	// Second Transpose
	bool result2 = transposeMatrix((int *)matrix, 3);
	EXPECT_TRUE(result2) << "Second transpose failed.";

	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)originalMatrix, 3))
		<< "After two transpositions, the matrix should return to its original "
		   "state.";
}

// Test Case 13: Matrix with Maximum Integer Values
TEST(TransposeMatrixTest, MatrixWithMaxIntValues) {
	int matrix[2][2] = {{INT_MAX, INT_MAX}, {INT_MAX, INT_MAX}};

	int expectedMatrix[2][2] = {{INT_MAX, INT_MAX}, {INT_MAX, INT_MAX}};

	bool result = transposeMatrix((int *)matrix, 2);

	EXPECT_TRUE(result)
		<< "Expected transposeMatrix to handle maximum integer values.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)expectedMatrix, 2))
		<< "The matrix with maximum integer values was not correctly "
		   "transposed.";
}

// Test Case 14: Matrix with Mixed Positive and Negative Values
TEST(TransposeMatrixTest, MatrixWithMixedValues) {
	int matrix[2][2] = {{0, -1}, {1, 0}};

	int expectedMatrix[2][2] = {{0, 1}, {-1, 0}};

	bool result = transposeMatrix((int *)matrix, 2);

	EXPECT_TRUE(result) << "Expected transposeMatrix to return true for matrix "
						   "with mixed values.";
	EXPECT_TRUE(matricesAreEqual((int *)matrix, (int *)expectedMatrix, 2))
		<< "The matrix with mixed values was not correctly transposed.";
}

// #####################################
// ############ Q1 Tests ###############
// #####################################

// Helper function to check if an array is sorted
bool isArraySorted(double *array, int size) {
	for (int i = 1; i < size; i++) {
		if (array[i - 1] > array[i]) {
			return false;
		}
	}
	return true;
}

// Test Case 1: Sorting with Bubble Sort
TEST(SortArrayTest, BubbleSortCorrectness) {
	double array[] = {5.2, 3.1, 4.8, 1.6, 2.9};
	double expectedArray[] = {1.6, 2.9, 3.1, 4.8, 5.2};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'b';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly using Bubble Sort.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Sorted array does not match the expected result.";
}

// Test Case 2: Sorting with Insertion Sort
TEST(SortArrayTest, InsertionSortCorrectness) {
	double array[] = {10.5, -2.3, 7.7, 3.3, 0.0};
	double expectedArray[] = {-2.3, 0.0, 3.3, 7.7, 10.5};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'i';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly using Insertion Sort.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Sorted array does not match the expected result.";
}

// Test Case 3: Sorting with Selection Sort
TEST(SortArrayTest, SelectionSortCorrectness) {
	double array[] = {2.2, 3.3, 1.1, 5.5, 4.4};
	double expectedArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 's';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly using Selection Sort.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Sorted array does not match the expected result.";
}

// Test Case 4: Sorting with Merge Sort
TEST(SortArrayTest, MergeSortCorrectness) {
	double array[] = {9.9, 7.7, 5.5, 3.3, 1.1};
	double expectedArray[] = {1.1, 3.3, 5.5, 7.7, 9.9};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'm';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly using Merge Sort.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Sorted array does not match the expected result.";
}

// Test Case 5: Invalid Algorithm Character
TEST(SortArrayTest, InvalidAlgorithmCharacter) {
	double array[] = {1.0, 2.0, 3.0};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'x';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_EQ(elapsed_time, 0)
		<< "Expected elapsed_time to be 0 for invalid algorithm character.";
	EXPECT_FALSE(isArraySorted(array, size))
		<< "Array should not be sorted for invalid algorithm.";
}

// Test Case 6: Null Array Pointer
TEST(SortArrayTest, NullArrayPointer) {
	double *array = NULL;
	int size = 5;
	char algorithm = 'b';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_EQ(elapsed_time, 0)
		<< "Expected elapsed_time to be 0 for NULL array pointer.";
}

// Test Case 7: Negative Array Size
TEST(SortArrayTest, NegativeArraySize) {
	double array[] = {1.0, 2.0, 3.0};
	int size = -3;
	char algorithm = 'i';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_EQ(elapsed_time, 0)
		<< "Expected elapsed_time to be 0 for negative array size.";
}

// Test Case 8: Zero Array Size
TEST(SortArrayTest, ZeroArraySize) {
	double array[] = {1.0, 2.0, 3.0};
	int size = 0;
	char algorithm = 's';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_EQ(elapsed_time, 0)
		<< "Expected elapsed_time to be 0 for zero array size.";
}

// Test Case 9: Sorting an Already Sorted Array
TEST(SortArrayTest, AlreadySortedArray) {
	double array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double expectedArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'i';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size)) << "Array should remain sorted.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Array should remain unchanged after sorting.";
}

// Test Case 10: Sorting an Array with Duplicate Elements
TEST(SortArrayTest, ArrayWithDuplicates) {
	double array[] = {3.3, 2.2, 3.3, 1.1, 2.2};
	double expectedArray[] = {1.1, 2.2, 2.2, 3.3, 3.3};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'b';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly with duplicates.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Sorted array does not match the expected result with duplicates.";
}

// Test Case 11: Sorting an Array with One Element
TEST(SortArrayTest, SingleElementArray) {
	double array[] = {42.0};
	double expectedArray[] = {42.0};
	int size = 1;
	char algorithm = 'i';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Single element array should be considered sorted.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Single element array should remain unchanged.";
}

// Test Case 12: Sorting a Large Array and Comparing Merge Sort Performance
TEST(SortArrayTest, MergeSortPerformance) {
	const int size = 100000;
	double *array = new double[size];
	double *arrayCopy = new double[size];

	// Initialize the array with random values
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = (double)(rand() % size);
		arrayCopy[i] = array[i];
	}

	// Sort using Bubble Sort
	clock_t bubbleTime = sortArray(array, size, 'b');

	// Reset array
	memcpy(array, arrayCopy, sizeof(double) * size);

	// Sort using Merge Sort
	clock_t mergeTime = sortArray(array, size, 'm');

	EXPECT_GT(bubbleTime, 0) << "Expected bubbleTime to be greater than 0.";
	EXPECT_GT(mergeTime, 0) << "Expected mergeTime to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly using Merge Sort.";
	EXPECT_LT(mergeTime, bubbleTime)
		<< "Expected Merge Sort to be faster than Bubble Sort on large arrays.";

	// Clean up
	delete[] array;
	delete[] arrayCopy;
}

// Test Case 13: Sorting with Uppercase Algorithm Character
TEST(SortArrayTest, UppercaseAlgorithmCharacter) {
	double array[] = {4.0, 2.0, 5.0, 1.0, 3.0};
	double expectedArray[] = {1.0, 2.0, 3.0, 4.0, 5.0};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'S';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly using Selection Sort.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Sorted array does not match the expected result.";
}

// Test Case 14: Sorting an Array with Negative and Positive Numbers
TEST(SortArrayTest, ArrayWithNegativeAndPositiveNumbers) {
	double array[] = {-1.1, 2.2, -3.3, 4.4, 0.0};
	double expectedArray[] = {-3.3, -1.1, 0.0, 2.2, 4.4};
	int size = sizeof(array) / sizeof(array[0]);
	char algorithm = 'I';

	clock_t elapsed_time = sortArray(array, size, algorithm);

	EXPECT_GT(elapsed_time, 0) << "Expected elapsed_time to be greater than 0.";
	EXPECT_TRUE(isArraySorted(array, size))
		<< "Array is not sorted correctly with negative numbers.";
	EXPECT_EQ(memcmp(array, expectedArray, sizeof(array)), 0)
		<< "Sorted array does not match the expected result with negative "
		   "numbers.";
}

// Test Case 15: Performance Comparison of Sorting Algorithms on Large Array
TEST(SortArrayTest, SortingAlgorithmsPerformanceComparison) {
	const int size = 50000;
	double *arrayOriginal = new double[size];
	double *array = new double[size];
	clock_t times[4];  // Stores times for each algorithm
	char algorithms[] = {'b', 'i', 's', 'm'};
	const char *algorithmNames[] = {"Bubble Sort", "Insertion Sort",
									"Selection Sort", "Merge Sort"};

	// Initialize the array with random values
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++) {
		arrayOriginal[i] = (double)(rand() % size);
	}

	for (int i = 0; i < 4; i++) {
		memcpy(array, arrayOriginal, sizeof(double) * size);
		times[i] = sortArray(array, size, algorithms[i]);

		EXPECT_GT(times[i], 0) << "Expected time for " << algorithmNames[i]
							   << " to be greater than 0.";
		EXPECT_TRUE(isArraySorted(array, size))
			<< "Array is not sorted correctly using " << algorithmNames[i]
			<< ".";
	}

	// Merge Sort should be faster than the other algorithms on large arrays
	for (int i = 0; i < 3; i++) {
		EXPECT_LT(times[3], times[i])
			<< "Expected Merge Sort to be faster than " << algorithmNames[i]
			<< " on large arrays.";
	}

	// Clean up
	delete[] arrayOriginal;
	delete[] array;
}
