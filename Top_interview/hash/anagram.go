// Given two strings s and t, return true if t is an
// anagram
// of s, and false otherwise.

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

package main

import "fmt"

func isAnagram(s string, t string) bool {
	countS := make(map[rune]rune)
	countT := make(map[rune]rune)
	for _, char := range s {
		if _, found := countS[char]; found {
			countS[char] += 1
		} else {
			countS[char] = 1
		}
	}

	for _, char := range t {
		if _, found := countT[char]; found {
			countT[char] += 1
		} else {
			countT[char] = 1
		}
	}

	if len(countS) != len(countT) {
		return false
	}

	for key, _ := range countS {
		if countS[key] != countT[key] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isAnagram("rat", "car"))
}
