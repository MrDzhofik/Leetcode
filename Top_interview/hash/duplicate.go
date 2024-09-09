// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true

// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true

// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

package main

import "fmt"

func containsNearbyDuplicate(nums []int, k int) bool {
	valIdx := make(map[int]int)
	dist := 10001
	for idx, val := range nums {
		key, ok := valIdx[val]
		if !ok {
			valIdx[val] = idx
		} else {
			fmt.Println(valIdx)
			if key > idx {
				dist = key - idx
			} else {
				dist = idx - key
			}
			fmt.Println("Value: ", val)
			fmt.Println("Index: ", idx, key)
			if dist <= k {
				return true
			} else {
				valIdx[val] = idx
			}
		}
	}
	return false
}

func main() {
	nums := []int{1, 2, 3, 1, 2, 3}
	k := 2
	fmt.Println(containsNearbyDuplicate(nums, k))
}
