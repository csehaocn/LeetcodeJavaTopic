# Stacks
题目特征

2.  优先级, 替换.
    316. Remove Duplicate Letters
    右边还有没有的问题, 可以实现用一次扫描count, 然后第二次扫, 一边扫一边减.
    Similar Problem
        Create Max Number from Array of Digits.
        402. Remove K Digits

3.  Increasing stack / decreasing stack
    3.1.  寻找(左边/右边)第一个（小于/大于）自己的数
          注意: 左边第一个最小和右边第一个最大并不是对偶问题, e.g. 1 3 2 中的 1和2. 但是用左stack和右stack都可以解, 不过一个是递增stack, 一个是递减  stack.
          84. Largest Rectangle in Histogram
          42. Trapping Rain Water
          496. Next Greater Element I
    
    3.2.  Increasing stack和decreasing stack可以解决很多问题
          不光是, increasing decreasing的数组元素，包括Increasing和Decreasing的pair of int
          456. 132 Pattern
