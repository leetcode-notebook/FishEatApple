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