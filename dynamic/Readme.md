### 121.买卖股票的最佳时机
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int maxProfit=0,minPrice=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            maxProfit=max(maxProfit,prices[i]-minPrice);
            minPrice=min(minPrice,prices[i]);
        }
        return maxProfit>0?maxProfit:0;
    }
};
```
### 70.爬楼梯
发现是斐波那契数列
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(1==n) return n;
        int pp=1,p=2;
        int res=2;
        n-=2;
        while(n--)
        {
            res=pp+p;
            pp=p;
            p=res;
        }
        return res;
    }
};
```
### 53.最大子序和
重点是考虑`d[n-1]`项的值，如果是负的话，那就以为前面的子序和产生的是**负作用**，应当舍弃，将当前值作为最新的子序和，无论当前值的大小，循环期间要将产生的最大的子序和保留下来。
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=nums[0];
        int sum=pre,res=pre;
        if(nums.size()<2) return res;
        for(int i=1;i<nums.size();i++)
        {
            if(pre<=0) sum=nums[i];
            else sum+=nums[i];
            pre=sum;
            res=max(res,sum);
        }
        return res;
    }
};
```