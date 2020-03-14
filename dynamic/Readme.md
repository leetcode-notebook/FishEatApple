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
####    62.不同路径
动态方程为`dp[i][j]=dp[i-1][j]+dp[i][j-1];`
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int i=0;i<m;i++) dp[0][i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
```
上面的空间复杂度为O(n*n)，考虑将其优化为O(n)，但是时间也随之变大了，以时间换空间。
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dmn=1,dn=1,dm[m];
        for(int i=0;i<m;i++) dm[i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dmn=dm[j]+dn;
                dm[j]=dmn;
                dn=dmn;
            }
            dn=1;
        }
        return dmn;
    }
};
```
### 139.单词拆分
将单词拆分为两个子字符串
`d[n]=for(i){d[i]&&剩下的子字符串是否符合要求}`
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool check[s.size()+1]={false};
        check[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check[j]&&find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end())
                {
                    check[i]=true;
                    break;
                }
            }
        }
        return check[s.size()];
    }
};
```
### 322. 零钱兑换
*   此题也有**递归**解法,其实两种解法类似,**递归**是`自顶向下`的思路,而**动态规划**是`自底向上`的思路.
*   动态规划最重要的是找到**动态转移方程**,这里的方程为`dp[n]=min(dp[n],dp[n-coin]+1)`
```py
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[amount+1]*(amount+1)
        dp[0]=0
        for i in range(1,amount+1):
            for coin in coins:
                if (i-coin)<0: continue
                dp[i]=min(dp[i],dp[i-coin]+1)
        return dp[amount] if dp[amount]!=(amount+1) else -1
```
### 121. 买卖股票的最佳时机
首要的是要列出动态转移方程,其中重要的一点是考虑`dp[n]`的含义,结合题意,`dp[n]`的意思为**第n天**将股票卖出所能获得的最大利润,因此我们需要知道`n`之前的**最小的价格**,综上,`dp[n]=max(dp[n-1],list[n]-minPrice)`.此外,这题因为还可以在降低空间复杂度上下功夫.
```py
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<2: return 0
        minPrice=prices[0]
        maxProfit=0
        for i in range(1,len(prices)):
            maxProfit=max(maxProfit,prices[i]-minPrice)
            minPrice=min(minPrice,prices[i])
        return maxProfit if maxProfit>0 else 0
```
### 300. 最长上升子序列
动态转移方程为`dp[n]=max(dp(j))+1 {0<=j<n} 需满足nums[n]>nums[j]`,此题用**贪心**+**二分查找**可以降低时间复杂度.
```py
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums)==0:return 0
        dp=[1]
        for i in range(len(nums)-1):
            dp.append(1)
            for j in range(i+1):
                if nums[i+1]>nums[j]:
                    dp[i+1]=max(dp[j]+1,dp[i+1])
        return max(dp)
```