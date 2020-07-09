[题目](http://poj.org/problem?id=1002)

## 1. map 映射

time: 1641MS  rank top1: 30MS
该代码在用g++ 提交时TL， 原因在于std::map为二叉树的存储结构，每次插入的值都会排序。改为C++提交即可 


