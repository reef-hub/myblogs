# lc416 分割等和子集
> [题目链接](https://leetcode.cn/problems/partition-equal-subset-sum/)  

> 求和函数:使用numeric头文件中的accumulate函数进行求和。  
accumulate(nums.begin(), nums.end(), 0);  
0为初始值，也可设置为其它值。
## 回溯
每个数都有被选择与不被选择两种状态，用0和1表示。超时
```cpp
bool  backtracking(vector<int>& nums, int target, int sum, int curpos) {
    if (sum == target)  return true;
    int state[2] = { 1, 0 };
    if (curpos < nums.size()) {
        for (int j = 0; j < 2; j++) {
            sum += state[j] * nums[curpos];
            bool res = backtracking(nums, target, sum, curpos + 1);
            if (res == true) return true;
            sum -= state[j] * nums[curpos];
        }
    }
    return false;
}
bool canPartition(vector<int>& nums) {
    int target = accumulate(nums.begin(), nums.end(), 0);
    if (target % 2 == 1) return false;
    else {
        bool res = backtracking(nums, target / 2, 0, 0);
        return res;
    }
}
```
## 动态规划
1. 背包体积为sum/2；
2. 背包要放入的商品（集合里的元素）重量为元素的数值，价值也为元素的数值；
3. 背包如果正好装满，说明找到了总和为sum/2的子集。
4. 背包中每一个元素是不可重复放入。

动态规划5步曲  
1. 确定dp数组以及其下标含义  
01背包中，dp[j]表示：容量为j的背包，所背的物品价值最大可以为dp[j]；
本题中，dp[j]表示背包总容量是j，最大可以凑成j的子集总和为dp[j]。  
2. 确定递推公式  
01背包的递推公式：dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);  
本题，相当于背包里放入数值，则物品i重量为nums[i],其价值也是nums[i];  
所以递推公式：dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]])  
3. 初始化dp数组  
```cpp
// 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
// 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
vector<int> dp(10001, 0);
```  
4. 确定遍历顺序  
```cpp
for(int i = 0; i < nums.size(); i++) {
    for(int j = targrt; j >= nums[i]; j--) {
        dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]]);
    }
}
```
5. 举例推导dp数组  
dp[j]的数值一定是小于等于j的。   
如果dp[j] == j 说明，集合中的子集总和正好可以凑成总和j。



