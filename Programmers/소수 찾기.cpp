#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<bool> visited;
static vector<int> arr;

void DFS(string numbers, string made_num, int *answer);

bool isPrime(int n);

int solution(string numbers) {
    int answer = 0;
    
    visited.resize(numbers.size(), false);
    
    DFS(numbers, "", &answer);
    
    return answer;
}

bool isPrime(int n)
{
    if (n <= 1) return false;
    
    for (int i=2;i<n;i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

bool check(int n)
{
    for (int i=0;i<arr.size();i++)
    {
        if (arr[i] == n)
        {
            return false;
        }
    }
    
    return true;
}

void DFS(string numbers, string made_num, int *answer)
{
    if (made_num != "" && isPrime(stoi(made_num)))
    {
        // cout << made_num <<" ";
        
        if (check(stoi(made_num)))
        {
            (*answer)++;
            arr.push_back(stoi(made_num));
        }
    }
    
    for (int i=0;i<numbers.size();i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            made_num += numbers[i];
            
            DFS(numbers, made_num, answer);
            
            made_num.erase(made_num.size()-1);
            visited[i] = false;
        }
    }
}
