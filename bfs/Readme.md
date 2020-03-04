### 994.腐烂的橘子
其实这就是一道最小路径问题,BFS解法.每一个腐烂的橘子都看成一个树的节点,`push`进队列中.
```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> orangesBad;
        int count=0;
        int row=grid.size(),col=grid[0].size();
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(2==grid[r][c])
                {
                    orangesBad.push(make_pair(r,c));
                }
                if(1==grid[r][c]) count++;
            }
        }
        int round=0;
        while(!orangesBad.empty()&&count)
        {
            round++;
            int size=orangesBad.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> badOrangeCoor=orangesBad.front();
                orangesBad.pop();
                int r=badOrangeCoor.first;
                int c=badOrangeCoor.second;
                if(r-1>=0&&1==grid[r-1][c])
                {
                    grid[r-1][c]=2;
                    count--;
                    orangesBad.push(make_pair(r-1,c));
                }
                if(r+1<row&&1==grid[r+1][c])
                {
                    grid[r+1][c]=2;
                    count--;
                    orangesBad.push(make_pair(r+1,c));
                }
                if(c-1>=0&&1==grid[r][c-1])
                {
                    grid[r][c-1]=2;
                    count--;
                    orangesBad.push(make_pair(r,c-1));
                }
                if(c+1<col&&1==grid[r][c+1])
                {
                    grid[r][c+1]=2;
                    count--;
                    orangesBad.push(make_pair(r,c+1));
                }
            }
        }
        return count?-1:round ;
    }
};
```
### 139.单词拆分
将字符串搜索索引作为节点.
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> qe;
        qe.push(0);
        int mem[s.size()]={0};
        while(!qe.empty())
        {
            int start=qe.front();
            qe.pop();
            if(mem[start]==0)
            {
                for(int i=start+1;i<=s.size();i++)
                {
                    if(find(wordDict.begin(),wordDict.end(),s.substr(start,i-start))!=wordDict.end())
                    {
                        qe.push(i);
                        if(i==s.size()) return true;
                    }
                }
                mem[start]=1;
            }
            
        }
        return false;
    }
};
```