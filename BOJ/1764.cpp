//
//  main.cpp
//  1764
//
//  Created by 최민경 on 2024/04/05.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    
    cin >> n >> m;
    
    map<string, int> myMap;
    vector<string> answer;
    
    for (int i=0;i<n+m;i++)
    {
        string str;
        
        cin >> str;
        
        myMap[str]++;
        
        if (myMap[str] > 1)
        {
            answer.push_back(str);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << "\n";
    for (int i=0;i<answer.size();i++)
    {
        cout << answer[i] << "\n";
    }
    
    return 0;
}
