### 1. 两数之和
以时间换空间,时间复杂度为`O(n)`,空间复杂度为`O(n)`
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int index;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(target-nums[i])!=hash.end())
            {
                index=i;
                break;
            }
            else
            {
                hash[nums[i]]=i;
            }
        }
        return {hash[target-nums[index]],index};
    }
};
```
### 409. 最长回文串
```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]]++;
        }
        int j=0,res=0;
        for(int i=0;i<hash.size();i++)
        {
            res+=hash[i]%2==0?hash[i]:0;
            if(hash[i]%2==1)
            {
                if(hash[i]>1) res+=hash[i]-1;
                j+=1;
            }
        }
        return j>0?res+1:res;
    }
};
```
### 3. 无重复字符的最长子串
用**哈希表**纪录字符及其**所在索引**,其中索引用来重新计算新的**子串起始索引**.
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int res=0;
        int start=0;
        for(int i=0;i<s.size();i++)
        {
            if(hash.find(s[i])!=hash.end()&&hash[s[i]]>=start)
            {
                start=hash[s[i]]+1;
            }
            hash[s[i]]=i;
            res=max(res,i-start+1);
        }
        return res;
    }
};
```