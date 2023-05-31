package main

import "fmt" 

func majorityElement(nums []int) int {
	var ret int = -1
	n := len(nums)
	if(n == 1) {
		return nums[0]
	}

	values_m := make(map[int]int)
	for _, v := range nums {
		_, ok := values_m[v]
		if(ok) {
			values_m[v] += 1;
			if(values_m[v] > n / 2 ) {
				ret = v
			}
		} else {
			values_m[v] = 1
		}
	}
	return ret
}

func main() {
	nums := []int {} 
	fmt.Println(majorityElement(nums))
}