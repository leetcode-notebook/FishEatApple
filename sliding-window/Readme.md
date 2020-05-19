### 面试题57 - II. 和为s的连续正数序列
滑动窗口有左界限和右界限,固定住左界限不动,将右界限往右移动,如果值大于`target`,则右移左界限,这种做法保证**不发生回溯现象**,进而保证时间复杂度控制在O(n).
```py
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        left=1
        right=1
        sumVal=0
        res=[]
        while left<=target//2:
            if sumVal<target:
                sumVal+=right
                right+=1
            elif sumVal>target:
                sumVal-=left
                left+=1
            else:
                res.append(list(range(left,right)))
                sumVal-=left
                left+=1
        return res
```
### 76. 最小覆盖子串
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        int match=0,left=0,right=0,minLen=INT_MAX,start=0;
        for(char ch:t) need[ch]++;
        while(right<s.size()){
            if(need.count(s[right])){
                if(++window[s[right]]==need[s[right]]) match++;
            }
            right++;
            while(match==need.size()){
                int len=right-left;
                if(len<minLen){
                    minLen=len;
                    start=left;
                }
                if(need.count(s[left])){
                    window[s[left]]--;
                    if(window[s[left]]<need[s[left]]) match--;
                }
                left++;
            }
        }
        return minLen!=INT_MAX?s.substr(start,minLen):"";
    }
};
```
### 438. 找到字符串中所有字母异位词
改编自上面那道题目，解题思路一致
```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        int match=0,left=0,right=0;
        vector<int> res;
        for(char ch:p) need[ch]++;
        while(right<s.size()){
            char chR=s[right];
            if(need.count(chR)){
                if(++window[chR]==need[chR]) match++;
            }
            right++;
            while(match==need.size()){
                if(right-left==p.size()) res.push_back(left);
                char chL=s[left];
                if(need.count(chL)){
                    if(--window[chL]<need[chL]) match--;
                }
                left++;
            }
        }
        return res;
    }
};
```
### 3. 无重复字符的最长子串
直接套用**滑动窗口**解题框架即可：
```cpp
滑动窗口解题框架：
int left = 0, right = 0;

while (right < s.size()) {
    window.add(s[right]);
    right++;

    while (valid) {
        window.remove(s[left]);
        left++;
    }
}
```

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        int left=0,right=0;
        unordered_map<char,int> window;
        int res=INT_MIN;
        while(right<s.size()){
            char chR=s[right];
            window[chR]++;
            right++;
            while(window[chR]>1){
                char chL=s[left];
                window[chL]--;
                left++;
            }
            // res=res<right-left?right-left:res;
            res=max(right-left,res);
        }
        return res;
    }
};
```