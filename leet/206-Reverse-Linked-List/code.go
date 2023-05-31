package main

type ListNode struct {
	Val int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	var next *ListNode
	cur_head := head
	for cur_head != nil {
		next = cur_head.Next
		cur_head.Next = prev
		prev = cur_head
		cur_head = next
	}
	return prev
}

func main() {
	ListNode := &ListNode{1, nil} 
	reverseList(ListNode)
}