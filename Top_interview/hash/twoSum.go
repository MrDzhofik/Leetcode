// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

package main

import "fmt"

func twoSum(nums []int, target int) []int {
	valIndex := make(map[int]int)
	for idx, val := range nums {
		valIndex[val] = idx
	}

	ans := make([]int, 2)

	for idx, val := range nums {
		key := target - val
		index, ok := valIndex[key]
		if index != idx && ok {
			ans[0] = idx
			ans[1] = index
			break
		}
	}
	return ans
}

func main() {
	nums := []int{2, 7, 11, 8, 3}
	target := 9
	fmt.Println(twoSum(nums, target))
}
