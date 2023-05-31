package main

import "fmt" 

func canConstruct(ransomNote string, magazine string) bool {
    magazine_map := make(map[rune]int) 
	for _, c := range magazine {
		_, ok := magazine_map[c]
		if ok {
			magazine_map[c] += 1
		} else {
			magazine_map[c] = 1
		}
	}
	for _, c := range ransomNote {
		v, ok := magazine_map[c]
		if ok {
			if v <= 0 {
				return false
			}
			magazine_map[c] -= 1
		} else {
			return false
		}
	}
	return true
}

func main () {
	fmt.Println(canConstruct("abc", "aabcd"))
}
