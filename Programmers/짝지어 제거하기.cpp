#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> stack1;
    stack<char> stack2;
    int i = 0;
    
    for (int i=s.size()-1;i>=0;i--)
    {
        stack2.push(s[i]);
    }
    
    while (!stack2.empty())
    {
        if (stack1.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
        else
        {
            if (stack1.top() == stack2.top())
            {
                stack1.pop();
                stack2.pop();
            }
            
            else
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }

    if (stack1.empty()) answer = 1;
    
    return answer;
}
