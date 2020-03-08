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