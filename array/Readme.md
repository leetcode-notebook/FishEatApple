### 945. 使数组唯一的最小增量
先排序，再加一
```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<=1) return 0;
        sort(A.begin(),A.end());
        int res=0;
        for(int i=1;i<A.size();i++)
        {
            if(A[i]<=A[i-1])
            {
                int diff=A[i-1]-A[i]+1;
                A[i]+=diff;
                res+=diff;
            }
        }
        return res;
    }
};
```