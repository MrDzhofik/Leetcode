// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

//     Each child must have at least one candy.
//     Children with a higher rating get more candies than their neighbors.

// Return the minimum number of candies you need to have to distribute the candies to the children.

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

// Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.

package main

func candy(ratings []int) int {
	size := len(ratings)
	candies := make([]int, size)

	for i := range candies {
		candies[i] = 1
	}

	k := 1

	for k != 0 {
		k = 0
		for i := 1; i < size-1; i++ {
			if ratings[i] > ratings[i-1] && candies[i] <= candies[i-1] {
				candies[i] = candies[i-1] + 1
				k++
			} else if ratings[i] > ratings[i+1] && candies[i] <= candies[i+1] {
				candies[i] = candies[i+1] + 1
				k++
			}
		}
	}

	if size > 1 {
		if ratings[0] > ratings[1] {
			candies[0] = candies[1] + 1
		}
		if ratings[size-1] > ratings[size-2] {
			candies[size-1] = candies[size-2] + 1
		}
	}

	sum := 0
	for i := range candies {
		sum += candies[i]
	}

	return sum
}
