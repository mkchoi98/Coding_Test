#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> open, close;
    
    int i, j;
    
    for (i=0;i<s.size();i++)
    {
        for (j=0;j<s.size();j++)
        {
            if (s[j] == '(' || s[j] == '{' || s[j] == '[')
            {
                open.push(s[j]);
            }
            
            else
            {
                if (open.empty())
                {
                    break;
                }
                
                close.push(s[j]);
            }
            
            if (!open.empty() && !close.empty())
            {
                char open_top = open.top();
                char close_top = close.top();

                if (open_top == '{' && close_top == '}')
                {
                    open.pop();
                    close.pop();
                }

                else if (open_top == '[' && close_top == ']')
                {
                    open.pop();
                    close.pop();
                }

                else if (open_top == '(' && close_top == ')')
                {
                    open.pop();
                    close.pop();
                }
                
                else break;
            }
        }
        
        if (j == s.size() && open.empty() && close.empty())
        {
            answer++;
        }
        
        char temp = s[0];
        for (j=1;j<s.size();j++)
        {
            s[j-1] = s[j];
        }
        
        s[s.size()-1] = temp;
    }
    
    return answer;
}
