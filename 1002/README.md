[题目](http://poj.org/problem?id=1002)

## 1. map 映射

time: 1641MS    最优解法耗时: 30MS

map 不用排序. 因为std::map为二叉查找树的存储结构，树的键值存储是有序的。
另外将整串字符串作为key, 平衡二叉树的查询为O(log2n), 近乎于折半查找。
所以最优的解法应该不是map 做存储结构...应该是前缀树之类的数据结构

## 2. 构建前缀树存储  代码:main3.cpp

time: TL 

超时的原因应该是insert 和 print 造成的
