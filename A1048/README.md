# PAT_A1048_哈希表法

考点：哈希表(多方法)

难度：容易

数据：用一个哈希表记录每种面值的硬币个数

算法步骤：

1. 读入硬币个数n、需要的面值m、各硬币的面值
2. 用哈希表记录各种面值的硬币个数
3. 遍历面值i从1到500，用哈希表看是否有面值为m-i的硬币(如果m-i == i则要求面值为i的硬币个数不少于2)
4. 输出

注意的地方：

m的范围为0到1000，则m-i的范围也是0到1000，要注意哈希表大小必须开到1000以上，否则m-i可能会越界