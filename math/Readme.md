### 7. 整数反转
题目要求超过`[−2的31次方,  2的31次方 − 1]`的值,返回`0`.`int`的范围是32位,所以要用64位的`long`来存放中间过程的计算值。
```cpp
class Solution {
public:
    int reverse(int x) {
        long res=0;
        while(x)
        {
            res=res*10+(x%10);
            x/=10;
        }
        return res>=INT_MIN&&res<=INT_MAX?res:0;
    }
};
```