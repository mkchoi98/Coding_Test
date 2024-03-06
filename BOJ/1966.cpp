#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    int N, M;
    
    cin >> T;
    
    for (int t=0;t<T;t++)
    {
        cin >> N >> M;
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        
        for (int i=0;i<N;i++)
        {
            int p;
            
            cin >> p;
            
            pq.push(p);
            q.push({i, p});
        }
        
        int answer = 1;
        
        while (true)
        {
            pair<int, int> cur = q.front();
            int top = pq.top();
            
            if (top == cur.second)
            {
                if (cur.first == M)
                {
                    break;
                }
                
                pq.pop();
                q.pop();
                
                answer++;
            }
            
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}
