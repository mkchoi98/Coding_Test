#include <iostream>
#include <vector>

using namespace std;

static vector<int> parents;
static vector<vector<int>> party;

void unionFunc(int a, int b);
int findFunc(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; // 사람의 수, 파티의 수
    
    cin >> N >> M;
    
    parents = vector<int> (N+1);
    
    for (int i=0;i<=N;i++)
    {
        parents[i] = i;
    }
    
    int T; // 진실을 아는 사람의 수
    
    cin >> T;
    
    vector<int> true_person(T+1); // 진실을 아는 사람의 번호
    
    for (int i=0;i<T;i++)
    {
        cin >> true_person[i];
    }
    
    party.resize(M);
    
    for (int i=0;i<M;i++)
    {
        int P; // 파티에 참여하는 사람의 수
        
        cin >> P;
        
        int first = 0;
        
        for (int j=0;j<P;j++)
        {
            int num; // 파티에 참여하는 사람의 번호
            
            cin >> num;
            
            party[i].push_back(num);
            
            if (j == 0)
            {
                first = num;
                continue;
            }
            
            unionFunc(first, party[i][j]);
        }
    }
    
    bool flag = true;
    int answer = 0;
    
    for (int i=0;i<M;i++)
    {
        int cur = party[i][0];
        
        flag = true;
        
        for (int j=0;j<T;j++)
        {
            if (findFunc(cur) == findFunc(true_person[j]))
            {
                flag = false;
                
                break ;
            }
        }
        
        if (flag) answer++;
    }
    
    cout << answer;
    
    return 0;
}

void unionFunc(int a, int b)
{
    a = findFunc(a);
    b = findFunc(b);
    
    if (a != b)
    {
        parents[b] = a;
    }
}

int findFunc(int a)
{
    if (a == parents[a]) return a;
    
    else
    {
        return parents[a] = findFunc(parents[a]);
    }
}
