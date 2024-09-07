// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:

// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

package main

import (
	"fmt"
)

func spiralOrder(matrix [][]int) []int {
	rows := len(matrix)
	cols := len(matrix[0])

	total := rows * cols

	startRow := 0
	startCol := 0
	endRow := rows - 1
	endCol := cols - 1

	count := 0

	ans := make([]int, 0)

	for count < total {
		// print up row
		for i := startCol; i <= endCol && count < total; i += 1 {
			ans = append(ans, matrix[startRow][i])
			count += 1
		}
		startRow += 1

		// print end col
		for i := startRow; i <= endRow && count < total; i += 1 {
			ans = append(ans, matrix[i][endCol])
			count += 1
		}
		endCol -= 1

		// print end row
		for i := endCol; i >= startCol && count < total; i -= 1 {
			ans = append(ans, matrix[endRow][i])
			count += 1
		}
		endRow -= 1

		// print start col
		for i := endRow; i >= startRow && count < total; i -= 1 {
			ans = append(ans, matrix[i][startCol])
			count += 1
		}
		startCol += 1
	}
	return ans
}

func main() {
	matrix := [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
	fmt.Println(matrix)
	ans := spiralOrder(matrix)
	fmt.Println(ans)
}
