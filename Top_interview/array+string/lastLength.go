package main

import (
	"strings"
)

func lengthOfLastWord(s string) int {
	s = strings.Trim(s, " ")
	result := strings.Split(s, " ")
	size := len(result)

	return len(result[size-1])
}
