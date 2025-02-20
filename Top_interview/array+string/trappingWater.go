// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

package main

import "fmt"

func trap(height []int) int {
	size := len(height)
	res := 0
	for i := 0; i < size-1; {
		j := i + 1
		for j < size && height[i] > height[j] {
			j++
		}
		if j >= size {
			i++
			continue
		}
		for curr := i + 1; curr < j; curr++ {
			fmt.Println("res: ", res, "i: ", i, "j: ", j)
			res += height[i] - height[curr]
		}
		i = j
	}
	return res
}

func main() {
	height := []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
	fmt.Println(trap(height))
}
