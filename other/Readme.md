### 1103. 分糖果 II
```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int c=1;
        while(candies>0)
        {
            for(int i=0;i<num_people;i++)
            {
                candies-=c;
                if(candies>=0)
                    res[i]+=c;
                else
                {
                    res[i]+=(c+candies);
                    break;
                }
                c++;
            }
        }
        return res;
    }
};
```
### 1013. 将数组分成和相等的三个部分
像这种情况:`
[10,-10,10,-10,10,-10,10,-10]`,`sum/3=0`,所以最后`p>=3`即可.
```py
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum=0
        for val in A:
            sum+=val
        if sum%3!=0: return False
        v=sum//3
        sum=0
        p=0
        for val  in A:
            sum+=val
            if v==sum:
                p+=1
                sum=0
        return True if 3<=p else False
```
### 1071. 字符串的最大公因子
两个概念:
*   如果 `str1` 和 `str2` 拼接后等于` str2`和 `str1` 拼接起来的字符串（注意拼接顺序不同），那么一定存在符合条件的字符串` X`
*   如果存在一个符合要求的字符串 `X`，那么也一定存在一个符合要求的字符串` X'`，它的长度为 `str1 `和 `str2` 长度的最大公约数
```py
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        return str1[:math.gcd(len(str1),len(str2))] if(str1+str2==str2+str1) else ""
```
169. 多数元素
```py
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dict={}
        for num in nums:
            if num in dict:dict[num]+=1
            else:dict[num]=1
            if dict[num]>(len(nums)//2):return num
```