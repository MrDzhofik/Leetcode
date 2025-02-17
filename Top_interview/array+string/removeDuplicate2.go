package main

func removeDuplicates(nums []int) int {
	size := len(nums)
	index := 1
	count := 0
	for i := 1; i < size; i += 1 {
		if nums[i] != nums[i-1] {
			nums[index] = nums[i]
			index++
			count = 0
		} else {
			count++
			if count <= 1 {
				nums[index] = nums[i]
				index++
			}
		}
	}

	return index
}
