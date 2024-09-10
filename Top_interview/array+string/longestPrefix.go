// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

package main

import (
	"fmt"
	"slices"
)

func longestCommonPrefix(strs []string) string {
	ans := ""
	size := len(strs)
	slices.Sort(strs)
	first := strs[0]
	last := strs[size-1]
	fmt.Println(strs)
	var sizeWord int
	if len(first) < len(last) {
		sizeWord = len(first)
	} else {
		sizeWord = len(last)
	}
	for i := 0; i < sizeWord; i += 1 {
		if first[i] == last[i] {
			ans += string(first[i])
		} else {
			i = sizeWord
		}
	}
	return ans

}

func main() {
	strs := []string{"aaa", "aa", "aaa"}
	fmt.Println(longestCommonPrefix(strs))
}
