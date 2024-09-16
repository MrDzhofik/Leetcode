// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000

package main

import "fmt"

func maxi(f int, s int) int {
	if f > s {
		return f
	}
	return s
}

func findMaxAverage(nums []int, k int) float64 {
	total := 0
	curr := 0

	size := len(nums)

	for i := 0; i < k; i++ {
		curr += nums[i]
	}

	total = curr

	for i := k; i < size; i++ {
		fmt.Println("Curr: ", curr, "ans: ", total)
		curr -= nums[i-k]
		curr += nums[i]
		total = maxi(total, curr)
	}
	fmt.Println("Curr: ", curr, "ans: ", total)

	return float64(total) / float64(k)
}

func main() {
	nums := []int{1, 12, -5, -6, 50, 3}
	k := 4
	fmt.Println(findMaxAverage(nums, k))
	fmt.Println("Done")
}
