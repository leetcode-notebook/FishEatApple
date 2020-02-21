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