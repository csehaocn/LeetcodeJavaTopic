Binary Search完全是我的弱项, 感觉很多应该用Binary Search的题目, 完全想不到点子上.
  392. Is Subsequence
  follow up
  char list + binary search
  特征
  1. Lots of strings streams. -> 预处理
  2. char index list + binary search -> 一种预处理方式, 知道这种处理, 但是居然忘记了可以binary search
  3. subsequence -> Binary Search. 记住这个不是substring, 不要求连续, 要求跳过. 
 
 
 有的题目居然可以用binary search搜索整个Integer空间, 不过其实想想看, 复杂度不过times 32, log(n)真的非常小...

Binary Search问题的特征
1.  某一个唯独上有上下边界
2.  有tentative trial的办法或者函数
