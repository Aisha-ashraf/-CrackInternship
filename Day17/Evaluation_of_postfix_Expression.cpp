//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
 stack<int> st;
        
        //iterating over the given string.
        for (int i = 0; i<S.size(); ++i)
        {
            //if current character is an operand, we push it to the stack.
            if (isdigit(S[i]))
                st.push(S[i] - '0');
    
            //else current character is an operator.
            else
            {
                //we pop and store the values of first two elements of stack.
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                
                //we perform required operation and push the result in stack.
                switch (S[i])
                {
                 case '+': st.push(val2 + val1); break;
                 case '-': st.push(val2 - val1); break;
                 case '*': st.push(val2 * val1); break;
                 case '/': st.push(val2 / val1); break;
                }
            }
        }
        //returning the top element of the stack.
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends