[题目](http://poj.org/problem?id=1001)

## 1. 模拟法 

time: 200ms

时间复杂度: O(n)

模拟手算过程, 注意的点在[测试数据](http://poj.org/showmessage?message_id=76017)

该题[rank](http://poj.org/problemstatus?problem_id=1001)发现有时间消耗为0ms的情况。有其他的解法，可能是某个数学公式, 待查询。


## 2. 分治法

time: 47ms

时间复杂度： O(lgn)

方法：

x^n = x^(n/2) * x^(n/2)       if n%2 == 0

x^n = x^(n/2) * x^(n/2) * x   if n%2 == 1

不是最优解...


## 3. 优化乘法计算逻辑

见文件main3.cpp

time: 0ms,  but memory=664K, G++提交模块最小的内存占用是16K, 四十分之一.....


## 4. FFT 做大数乘法

发现一种求大数乘法的新办法就是用FFT，目测rank中top1 用的就是此方法，待实现
