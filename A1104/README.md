# PAT_A1025

考点：找规律

分析：

只需计算出现了a[i]的片段的个数即可，能够出现a[i]的片段的第一个数一定在a[i]之前，最后一个数一定在a[i]之后(包括a[i])。a[i]之前有i个数，a[i]之后有n-i+1个数，根据乘法原理，能够出现a[i]的片段的个数就是i*(n-i+1)个，因此a[i]被累加了i*(n-i+1)次。遍历一遍数组然后按照此公式累加即可。

注意点：可以在读入数据的时候在线处理，节省存储数列的空间。