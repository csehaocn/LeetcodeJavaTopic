需要重新做, 重新理解的题目
300. Longest Increasing Subsequence
  这个题目很有stack的特征, 但是光用stack是解决不了的, 缺点在于stack的操作需要pop out顶部的元素, 这样历史信息就没有了. 
  那么我们应该想象一种新的数据结构, 类似于increasing stack, 但是确还是可以对其中部的元素进行操作, either用binary search, tree map, 或者hashmap
  让我们叫这个结构为increasing hash/binary sequence.
