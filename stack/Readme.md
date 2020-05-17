### 20.有效的括号
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        int len=s.size();
        if(0==len) return true;
        if(s[0]==')'||s[0]==']'||s[0]=='}') return false;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                sk.push(s[i]);
            }
            else
            {
                if(sk.empty()) return false;
                char c=sk.top();
                sk.pop();
                if(s[i]==')'&&c=='(') continue;
                else if(s[i]==')') return false;
                if(s[i]==']'&&c=='[') continue;
                else if(s[i]==']') return false;
                if(s[i]=='}'&&c=='{') continue;
                else if(s[i]=='}') return false;
            }
        }
        return sk.empty();
    }
};
```
### 232. 用栈实现队列
看起来在`peek()`的时候时间复杂度为`O(n)`，但是算`均摊成本`的时候其实只是`O(1`)，因为每个`val`其实只`push,pop`了一次。
```cpp
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=peek();
        s2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```