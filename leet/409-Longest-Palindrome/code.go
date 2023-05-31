package main

import "fmt" 

func longestPalindrome(s string) int {
	ret := 0
	s_map := make(map[rune]int)
	for _, c := range s {
		_, ok := s_map[c]
		if(ok) {
			s_map[c] += 1
			if s_map[c] % 2 == 0 {
				ret += 2
			}
		} else {
			s_map[c] = 1
		}
	}
	if ret < len(s) {
		ret += 1
	}
	return ret
}

func main() {
	fmt.Println(longestPalindrome("abcbakk"))
}