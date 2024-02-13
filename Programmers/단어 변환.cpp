#include <string>
#include <vector>

using namespace std;

static vector<bool> visited;

void DFS(string begin, string target, vector<string> words, int depth, int *answer);
int cntDiff(string str1, string str2);

int solution(string begin, string target, vector<string> words) {
    int answer = 100;
    bool flag = false;
    
    visited = vector<bool> (words.size(), false);
    
    for (int i=0;i<words.size();i++)
    {
        if (target.compare(words[i]) == 0)
        {
            flag = true;
        }
    }
    
    if (!flag)
    {
        answer = 0;
        
        return answer;
    }
    
    DFS(begin, target, words, 0, &answer);
    
    return answer;
}

int cntDiff(string str1, string str2)
{
    int cnt = 0;
    
    for (int i=0;i<str1.size();i++)
    {
        if (str1[i] != str2[i])
            cnt++;
    }
    
    return cnt;
}

void DFS(string begin, string target, vector<string> words, int depth, int *answer)
{
    if (depth >= *answer)
    {
        return ;
    }
    
    if (begin == target)
    {
        if (depth < *answer)
        {
            *answer = depth;
        }
        return;
    }
    
    for (int i=0;i<words.size();i++)
    {
        if (cntDiff(words[i], begin) == 1 && !visited[i])
        {
            DFS(words[i], target, words, depth+1, answer);
        }
    }
}
