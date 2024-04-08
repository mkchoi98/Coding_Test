#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int min_len = 21;
    
    for (int i=0;i<phone_book.size();i++)
    {
        int len = phone_book[i].length();
        
        if (min_len > len)
        {
            min_len = len;
        }
    }
    
    map<string, int> myMap;
    
    for (int i=0;i<phone_book.size();i++)
    {
        myMap[phone_book[i]] = 1;
    }
    
    for (int i=0;i<phone_book.size();i++)
    {
        for (int j=min_len;j<=20;j++)
        {
            if (phone_book[i].size() <= j) break;
            
            string str = phone_book[i].substr(0, j);
            
            if (myMap[str] == 1)
            {
                return false;
            }
        }
    }
    
    return answer;
}
