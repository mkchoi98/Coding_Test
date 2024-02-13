#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static vector<bool> visited;
static bool check = false;

void DFS(string start, vector<vector<string>> tickets, vector<string> &answer, int depth, int index);

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    visited.resize(tickets.size());
    
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", tickets, answer, 0, 0);
    
    return answer;
}

void DFS(string start, vector<vector<string>> tickets, vector<string> &answer, int depth, int index)
{    
    if (depth == tickets.size())
    {
        answer.push_back(tickets[index][1]);
        
        check = true;
        
        return ;
    }
    
    for (int i=0;i<tickets.size();i++)
    {
        if (start == tickets[i][0] && !visited[i])
        {
            visited[i] = true;
            answer.push_back(start);
            DFS(tickets[i][1], tickets, answer, depth+1, i);
            
            if (!check)
            {
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
}
