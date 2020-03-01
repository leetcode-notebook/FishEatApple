### 53.最大子序和
*   将数组的最大子序和这个问题**拆分**成以中间值为界限的左边范围的最大子序和、右边范围的最大子序和、穿越中间值的最大子序和，这三个值的最大值即为整个数组的最大子序和。
*   其中穿越中间值的最大子序和=左边范围的最大值+右边范围的最大值。
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    int helper(vector<int>& nums,int left,int right)
    {
        if(left==right) return nums[left];
        int p=(left+right)/2;
        int leftVal=helper(nums,left,p);
        int rightVal=helper(nums,p+1,right);
        int crossVal=crossCal(nums,left,p,right);
        return max(max(leftVal,rightVal),crossVal);
    }
    int crossCal(vector<int>& nums,int left,int p,int right)
    {
        int maxLeft=INT_MIN,maxRight=INT_MIN;
        int curVal=0;
        for(int i=p;i>=left;i--)
        {
            curVal+=nums[i];
            maxLeft=max(maxLeft,curVal);
        }
        curVal=0;
        for(int i=p+1;i<=right;i++)
        {
            curVal+=nums[i];
            maxRight=max(maxRight,curVal);
        }
        return maxLeft+maxRight;
    }
};
```