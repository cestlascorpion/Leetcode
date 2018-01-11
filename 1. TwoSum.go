package main

import (
    "fmt"
)

func twoIndex(nums []int, target int) []int {
    for i, v1 := range nums {
        if i+1 != len(nums) {
            for j, v2 := range nums[i+1:] {
                if target == (v1 + v2) {
                    return []int{i, i + j + 1}
                }
            }
        }
    }
    return []int{}
}

func main() {
    nums := []int{2, 7, 11, 15}
    fmt.Println(nums[0:])
    target := 9
    output := twoIndex(nums, target)
    fmt.Println(output)
}