# PAT_A1071

考点：字符串处理，map

难度：容易

算法步骤：
1. 读入一句话(用``getline()``和string)
2. 在末尾加上``'\n'``(这是为了保证末尾有一个非有效字符)
3. 分解单词：遍历这句话的每个字符，如果是有效字符，则继续拼接，直到读到非有效字符，在map里统计该单词的出现次数
4. 找出最高频单词：遍历map找出现次数最高的单词即可

注意点：
1. 因为可能第一个单词前面有非有效字符，需要检查拼接后的单词长度是否不为0再存入map
2. 如果不在末尾加上``\n``，恰好最后一个单词后面又没有非有效字符的话，最后一个单词就没有统计到
