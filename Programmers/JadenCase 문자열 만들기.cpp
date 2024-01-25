#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for (int i=0;i<s.size();i++)
    {   
        if (i == 0 && (s[i] >= 'a' && s[i] <= 'z'))
        {
            s[i] -= 32;
        }
        
        else if (i != 0 && s[i-1] == ' ' && (s[i] >= 'a' && s[i] <= 'z'))
        {
            s[i] -= 32;
        }
        
        else if (i != 0 && s[i-1] != ' ' && (s[i] >= 'A' && s[i] <= 'Z'))
        {
            s[i] += 32;
        }
        
        answer.push_back(s[i]);
    }
    
    return answer;
}
