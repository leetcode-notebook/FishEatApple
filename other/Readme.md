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