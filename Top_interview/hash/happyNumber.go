// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

//     Starting with any positive integer, replace the number by the sum of the squares of its digits.
//     Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//     Those numbers for which this process ends in 1 are happy.

// Return true if n is a happy number, and false if not.

package main

import (
	"fmt"
)

func sumOfSquares(num int) int {
	total := 0
	for num > 0 {
		tmp := num % 10
		num /= 10
		total += tmp * tmp
	}
	fmt.Println(total)
	return total
}

func isHappy(n int) bool {
	seen := make(map[int]bool)
	for n != 1 {
		if seen[n] {
			return false
		}
		seen[n] = true
		n = sumOfSquares(n)
	}
	return true
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(isHappy(n))
}
