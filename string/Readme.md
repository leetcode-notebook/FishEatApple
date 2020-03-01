### 139. 单词拆分
暴力解法，时间复杂度高达n的n次方，因此无法通过第29个测试用例，原因为超出时间限制：
`"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]`
其中存在大量的相同字符串的重复运算，可做优化以解决时间复杂度问题。
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s,wordDict,0);
    }
    bool helper(string s,vector<string>& wordDict,int start)
        if(start==s.size()) return true;
        for(int j=start;j<s.size();j++)
        {
            if(find(wordDict.begin(),wordDict.end(),s.substr(start,j-start+1))!=wordDict.end()&&helper(s,wordDict,j+1))
                return true;
        }
        return false;
    }
};
```
仔细分析，发现从for循环的第二次开始，存在计算之前已经计算过的字符串的现象，因此这里可以使用记忆化回溯的方法来避免重复的运算，加快速度：
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int mem[s.size()]={0};
        return helper(s,wordDict,0,mem);
    }
    bool helper(string s,vector<string>& wordDict,int start,int mem[])
    {
        if(start==s.size()) return true;
        if(mem[start]!=0)
        {
            if(1==mem[start]) return true;
            else if(2==mem[start]) return false;
        }
        for(int j=start;j<s.size();j++)
        {
            if(find(wordDict.begin(),wordDict.end(),s.substr(start,j-start+1))!=wordDict.end()&&helper(s,wordDict,j+1,mem))
            {
                mem[start]=1;
                return true;
            }
        }
        mem[start]=2;
        return false;
    }
};
```
用一个mem数组来存放当前位置开始的字符串之前是否已经计算过，在经历过一次完整的字符串计算后，mem数组中保存了相应的状态值，为后续的是否跳过计算计算提供依据，时间复杂度也降低为O(n*n)。