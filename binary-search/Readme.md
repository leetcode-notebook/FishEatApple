### 378. 有序矩阵中第K小的元素
**因为left<=target，同时right<=target，而二分法最后的结果必将是left==right,所以得到的值必将在矩阵中**
```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int left=matrix[0][0],right=matrix[n-1][n-1];
        while(left<right){
            int mid=left+(right-left)/2;
            //这里必须是<，因为如果是<=，那么right=mid将导致错误
            calKth(matrix,mid,n)<k?left=mid+1:right=mid;
        }
        return left;
    }
    int calKth(vector<vector<int>>& matrix,int mid,int n){
        int count=0;
        int row=n-1,col=0;
        while(row>=0&&col<n){
            int val=matrix[row][col];
            //这里必须是<=，因为第k小的数意思是小于等于那个数
            if(val<=mid){
                count+=row+1;
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }
};
```