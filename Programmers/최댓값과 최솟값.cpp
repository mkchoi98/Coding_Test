#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;
    string temp = "";

    for (int i=0;i<s.size();i++)
    {   
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        
        else
        {
            num.push_back(stoi(temp));
            temp = "";
        }
    }
    
    num.push_back(stoi(temp));
    
    sort(num.begin(), num.end());
    
    answer += to_string(num[0]) + " " + to_string(num[num.size()-1]);
    
    return answer;
}
