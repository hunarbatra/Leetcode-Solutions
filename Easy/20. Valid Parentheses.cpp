class Solution {
public:
    bool isValid(string s) {
        stack<char> pstack;       
        for(char ch : s)
        {
            if(ch== '(' || ch=='[' || ch=='{')  { pstack.push(ch);}
            else
            {
                if(pstack.empty()) return false;
                if(ch==')' && pstack.top()!='(') return false;
                if(ch=='}' && pstack.top()!='{') return false;
                if(ch==']' && pstack.top()!='[') return false;
                pstack.pop();
            }
        }
        return pstack.empty(); //if after all the popping, stack is empty, then it returns true, else false
    }
};