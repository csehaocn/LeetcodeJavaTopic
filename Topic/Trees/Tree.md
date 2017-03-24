1.	Iterative Traversal of Trees
	0.	Need a current pointer + stack + null current pointer enabled
		All other versions are much more complicated.
		Generally, enable null pointer is much easier in many cases.
		Even though it introduces one more layer of function calls.
	1.	Like BFS and DFS
	2.	DFS:
		1. Need a current pointer + stack
		2. Don`t get confused with BFS, stack only solution will not work.
	3.	BFS:
		1. Deque only will work.
	

2.	preOrder inOrder postOrder means root first, root middle, root post. Don`t get confused.

3.	preOrder inOrder postOrder.
	1.	I used to think preOrder and inOrder are of the same complexity
		while(!s.isEmpty() && c != null)
		as a matter of fact, preOrder is a easier problem than inorder.
		while(c!=null)
	2.	In this case, the three problem are of increasing complexity 
		Depending on the level of how long you have to keep the root node before discarding
		1.	preOrder,  no storage, keep its right subtree if not null is good enough.
		2.	inOrder,   keep untill it pops out
		3.	postOrder, keep untill it was push pop(peek) push pop, twice the procedure.	
			so the reason why postOrder is hard, largely due to 
			1.	we need (maybe) complicated conditions (or additional information) 
			to judge if it is first pop or second pop. (or going up or down, from left 
			subtree or right subtree) 
			2.	since we can not use c as null in this case. (we can not distinguish
			left null and right null), more complication were introduced. (this non-null
			complication exists in pre in order traversal as well) 
			
