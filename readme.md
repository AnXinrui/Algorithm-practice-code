# 刷题日常代码

## 一、语法练习 + 模拟

[合法日期 - 蓝桥云课 (lanqiao.cn)](https://www.lanqiao.cn/problems/541/learning/?page=1&first_category_id=1&sort=students_count&second_category_id=3&tags=模拟)

```cpp
#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int d, m;
  cin >> m >> d;
  int ar[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m <= 12 && m > 0 && d <= ar[m-1]) {
    cout << "yes";
  }
  else
    cout << "no";
  return 0;
}
```



## 二、基础算法

### 1.二分

P2249 [Algorithm-practice-code/luogu/p2249.cpp at master · AnXinrui/Algorithm-practice-code (github.com)](https://github.com/AnXinrui/Algorithm-practice-code/blob/master/luogu/p2249.cpp)

P1873[Algorithm-practice-code/luogu/p1873.cpp at master · AnXinrui/Algorithm-practice-code (github.com)](https://github.com/AnXinrui/Algorithm-practice-code/blob/master/luogu/p1873.cpp)



[P1678[Algorithm-practice-code/luogu/p1678.cpp at master · AnXinrui/Algorithm-practice-code (github.com)](https://github.com/AnXinrui/Algorithm-practice-code/blob/master/luogu/p1678.cpp)





[P2440 [Algorithm-practice-code/luogu/p2440.cpp at master · AnXinrui/Algorithm-practice-code (github.com)](https://github.com/AnXinrui/Algorithm-practice-code/blob/master/luogu/p2440.cpp)



[P2678 [NOIP2015 提高组\] 跳石头 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P2678)

代码：[Algorithm-practice-code/luogu/p2678.cpp at master · AnXinrui/Algorithm-practice-code (github.com)](https://github.com/AnXinrui/Algorithm-practice-code/blob/master/luogu/p2678.cpp)

### 2.前缀和

### 3. 差分

### 4.双指针

## 三、数据结构

### 1.链表、邻接表

### 2.栈与队列，单调栈，单调队列

### 3.哈希表

[P1001 A+B Problem - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P1001)

### 4.并查集

### 5. KMP

### 6.堆

### 7. tire

## 四、图论

### 1. DFS

### 2. BFS

### 3.拓扑排序

### 4. Dijkstra

### 5. SPFA

### 6. Floyd

## 四、动态规划

### 1.基础dp

### 2.线性dp

### 3.区间dp

### 4.树形dp

## 五、高级数据结构

### 1.线段树

### 2.树状数组

### 3.矩阵乘法

### 六、数论

## 其他(遇到再学)

1. 最小生成树
2. 二分图
3. 计数dp
4. 数位dp