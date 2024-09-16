// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

package main

import "fmt"

func isSubsequence(s string, t string) bool {
	secondPointer := 0
	firstSize := len(t)
	secondSize := len(s)

	if secondSize == 0 {
		return true
	}

	for firstPointer := 0; firstPointer < firstSize; firstPointer++ {
		if t[firstPointer] == s[secondPointer] {
			secondPointer++
		}
		if secondPointer == secondSize {
			return true
		}
	}

	return false
}

func main() {
	var s string
	var t string
	fmt.Scanln(&s)
	fmt.Scanln(&t)
	fmt.Println(isSubsequence(s, t))
	fmt.Println("Done")
}
