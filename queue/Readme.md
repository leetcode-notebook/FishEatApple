### 用队列实现栈
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