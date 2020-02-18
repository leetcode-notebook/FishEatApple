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