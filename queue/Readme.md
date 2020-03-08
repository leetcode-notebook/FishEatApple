### 225.用队列实现栈
一开始傻逼了，在pop()里的写得是
`for(int i=0;i<q1.size()-1;i++)`
居然没看到里面对q1在进行操作，size在不停变，傻逼了傻逼了
```cpp
class MyStack {
public:
    queue<int> q1,q2;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size=q1.size();
        for(int i=0;i<size-1;i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q1=q2;
        while(!q2.empty())
        {
            q2.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
### 面试题59 - II. 队列的最大值
使用辅助队列即可实现`max_value`的时间复杂度O(1)的要求,其中pyton的`list`中的pop(0)的时间复杂度为`O(n)`,所以这里用`deque`,复杂度为`O(1)`
```py
class MaxQueue:
    def __init__(self):
        from collections import deque
        self.que=deque()
        self.sortque=deque()
    def max_value(self) -> int:
        return self.sortque[0] if self.sortque else -1

    def push_back(self, value: int) -> None:
        self.que.append(value)
        while self.sortque and value>self.sortque[-1]:
            self.sortque.pop()
        self.sortque.append(value)

    def pop_front(self) -> int:
        if len(self.que)==0: return -1
        popVal=self.que.popleft()
        if popVal==self.sortque[0]:
            self.sortque.popleft()
        return popVal


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```