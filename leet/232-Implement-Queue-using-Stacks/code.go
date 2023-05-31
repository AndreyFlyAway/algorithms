package main

import "fmt"
import "container/list"

type MyQueue struct {
    input_st list.List
    output_st list.List
}


func Constructor() MyQueue {
	return MyQueue{}
}


func (this *MyQueue) Push(x int)  {
    this.input_st.PushFront(x)
}


func (this *MyQueue) Pop() int {
	this.Peek()
	var ret int
	if this.output_st.Len() != 0 {
		ret = this.output_st.Front().Value.(int);
		this.output_st.Remove(this.output_st.Front())
	} 
	return ret
}


func (this *MyQueue) Peek() int {
	if this.output_st.Len() == 0 {
		for n := this.input_st.Front() ; n != nil ; n = n.Next() {
			this.output_st.PushFront(n.Value)
		}
		this.input_st.Init()
	} 
	if this.output_st.Len() != 0 {
		return this.output_st.Front().Value.(int);
	} 
	return 0
}

func (this *MyQueue) Empty() bool {
	return this.output_st.Len() == 0 && this.input_st.Len() == 0
}


// ["MyQueue","push","push","push","push","pop","push","pop","pop","pop","pop"]
// [[],[1],[2],[3],[4],[],[5],[],[],[],[]]
// [null,null,null,null,null,1,null,2,3,4,5]

func main() {
	q := Constructor()
	q.Push(1)
	q.Push(2)
	q.Push(3)
	q.Push(4)
	fmt.Println(q.Pop())
	q.Push(5)
	fmt.Println(q.Pop())
	fmt.Println(q.Pop())
	fmt.Println(q.Pop())
	fmt.Println(q.Pop())
}