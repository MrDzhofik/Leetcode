package main

func removeElement(nums []int, val int) int {
	i := 0
	j := len(nums) - 1
	for i <= j {
		if nums[i] == val {
			if nums[j] == val {
				j--
			} else {
				tmp := nums[i]
				nums[i] = nums[j]
				nums[j] = tmp
				i++
			}
		} else {
			i++
		}
	}
	return i
}
