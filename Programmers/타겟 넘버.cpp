#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int op[2]; // 0: '+', 1: '-'

void DFS(vector<int> &numbers, int target, int result, int *answer, int index);

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size = numbers.size();
    
    for (int i=0;i<2;i++)
    {
        op[i] = size;
    }
    
    DFS(numbers, target, 0, &answer, 0);
    
    return answer;
}

void DFS(vector<int> &numbers, int target, int result, int *answer, int index)
{
    if (index == numbers.size())
    {
        if (target == result) 
        {
            (*answer)++;
        }
        
        return ;
    }
    
   if (op[0] != 0)
   {
       op[0]--;
       DFS(numbers, target, result+numbers[index], answer, index+1);
       op[0]++;
   }
    
    if (op[1] != 0)
    {
        op[1]--;
        DFS(numbers, target, result-numbers[index], answer, index+1);
        op[1]++;
    }
}
