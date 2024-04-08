//
//  main.cpp
//  2529
//
//  Created by 최민경 on 2024/04/08.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int k;
static vector<char> arr;
static vector<int> num;
static vector<bool>visited;
static long long max_answer, min_num = 9999999999;
static string min_answer;

void DFS();

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> k;
    
    visited.resize(10);
    
    for (int i=0;i<k*2;i++)
    {
        char c;
        
        cin >> c;
        
        if (c == ' ') continue;
        
        arr.push_back(c);
    }
    
    DFS();
    
    cout << max_answer << "\n" << min_answer;
    
    return 0;
}

void DFS()
{
    if (num.size() == k+1)
    {
        bool flag = true;
        
        for (int i=0;i<k;i++)
        {
            if (arr[i] == '>')
            {
                if (!(num[i] > num[i+1]))
                {
                    flag = false;
                }
            }
            
            else
            {
                if (!(num[i] < num[i+1]))
                {
                    flag = false;
                }
            }
        }
        
        if (flag)
        {
            string str = "";
            
            for (int i=0;i<k+1;i++)
            {
                str += num[i]+'0';
            }
            
            long long n = stoll(str);
            
            min_num = min(min_num, n);
            max_answer = max(max_answer, n);
            
            if (min_num == n)
            {
                min_answer = str;
            }
        }
        
        return ;
    }
    
    for (int i=0;i<=9;i++)
    {
        if (!visited[i])
        {
            num.push_back(i);
            visited[i] = true;
            DFS();
            visited[i] = false;
            num.pop_back();
        }
    }
}
