### 46.全排列
```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backTrack(nums,track);
        return res;
    }
    void backTrack(vector<int>& nums,vector<int>& track){
        if(track.size()==nums.size())
        {
            res.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(find(track.begin(),track.end(),nums[i])!=track.end())
            {
                continue;
            }
            track.push_back(nums[i]);
            backTrack(nums,track);
            track.pop_back();//这一步是撤销选择，不能用clear操作，否则无限递归
        }
    }
};
```
### 51.N皇后
注意`for`循环中多个判断条件情况下要用`&&`，不能用逗号`,`。
```cpp
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backTracking(board,0);
        return res;
    }
    void backTracking(vector<string>& board,int row){
        if(row==board.size())
        {
            res.push_back(board);
            return;
        }
        int n=board.size();
        for(int col=0;col<n;col++)
        {
            if(!isValid(board,row,col)) continue;
            board[row][col]='Q';
            backTracking(board,row+1);
            board[row][col]='.';
        }
    }
    bool isValid(vector<string>& board,int row,int col){
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q') return false;
        }
        int n=board.size();
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
};
```
### 78.子集
```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backTracking(nums,0,track);
        return  res;
    }
    void backTracking(vector<int>& nums,int start,vector<int>& track){
        res.push_back(track);
        for(int i=start;i<nums.size();i++)
        {
            track.push_back(nums[i]);
            backTracking(nums,i+1,track);
            track.pop_back();
        }
    }
};
```
### 37.解数独
注意数独中数字是**从1开始**的，**不是从0开始**的！
```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board,0,0);
    }
    bool backTracking(vector<vector<char>>& board,int r,int c)
    {
        int m=9; 
        if(c==m) 
        {
            return backTracking(board,r+1,0);
        }
        if(r==m) return true;
        if(board[r][c]!='.')
        {
            return backTracking(board,r,c+1);
        }
        for(int i=1;i<10;i++)
        {
            char num=i+48;
            if(!isValid(board,num,r,c)) continue;
            board[r][c]=num;
            if(backTracking(board,r,c+1)) return true;
            board[r][c]='.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board,char num,int r,int c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==num) return false;
            if(board[i][c]==num) return false;
            if(board[(r/3)*3+i/3][(c/3)*3+i%3]==num) return false;
        }
        return true;
    }
};
```
### 36.有效的数独
建立了**查找表**取代循环查找值是否有效的方法，时间复杂度与空间复杂度均为O(1)
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9,vector<bool>(9,false));
        vector<vector<bool>> col(9,vector<bool>(9,false));
        vector<vector<bool>> box(9,vector<bool>(9,false));
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int index=board[i][j]-'1';
                    if(row[i][index]==false) row[i][index]=true;
                    else return false;
                    if(col[index][j]==false) col[index][j]=true;
                    else return false;
                    if(box[(i/3)*3+index/3][(j/3)*3+index%3]==false) box[(i/3)*3+index/3][(j/3)*3+index%3]=true;
                    else return false;
                }
            }
        }
        return true;
    }
};
```
### 22.括号生成
利用**回溯法**找到所有的可选答案，然后根据括号的两个特征进行筛选：
1、一个「合法」括号组合的左括号数量一定等于右括号数量，这个很好理解。
2、对于一个「合法」的括号字符串组合 p，必然对于任何 0 <= i < len(p) 都有：子串 p[0..i] 中左括号的数量都大于或等于右括号的数量。
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left=n,right=n;
        vector<string> res;
        string track;
        backTracking(left,right,res,track);
        return res;
    }
    void backTracking(int left,int right,vector<string>& res,string& track){
        if(left>right) return;
        if(left<0||right<0) return;
        if(left==0&&right==0)
        {
            res.push_back(track);
            return;
        }
        track.push_back('(');
        backTracking(left-1,right,res,track);
        track.pop_back();

        track.push_back(')');
        backTracking(left,right-1,res,track);
        track.pop_back();
    }
};
```