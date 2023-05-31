
package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	if(root == nil) {
		return false
	}
    ret := dfs(root)
	return ret != -1
}

func dfs(node *TreeNode) int {
	if node == nil {
		return 1
	} else {
		leftVal := dfs(node.Left)
		rightVal := dfs(node.Right)
		tmp := leftVal - rightVal
		if leftVal == -1 || rightVal == -1 || tmp < -1 || tmp > 1 {
			return -1
		}
		if leftVal > rightVal {
			return leftVal + 1
		}
		return rightVal + 1
	}
}

func main() {
	node := TreeNode{1, nil, nil}
	fmt.Println(isBalanced(&node))
}