# LeetcodeJava2
1.  你的代码bug太多了, 一切都应该以安全第一, 安全比效率跟重要，虽然你知道你自己是一个效率狂.
2.  Math Problems are too many
    1. k^i < 1 + k + k^2 + ... + k^i < k^(i+1)
             1 + k + k^2 + ... + k^i < (k+1)^i
             483. Smallest Good Base
3.  变量range分析
    483. Smallest Good Base
    特别难的题, 类似于数学题, 分析一下变量的范围有时候是有用的
    而且, 就像在这个题目中一样, 任何进制下, 数字位数的范围都是非常小的.
    这种题目, 解答居然就是遍历数字的位数开始.
