#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findFunc(int a);
void unionFunc(int a, int b);

typedef struct Edge
{
    int s, e, w;
    
   bool operator > (const Edge& temp) const
    {
        return w > temp.w;
    }
}Edge;

static vector<int> parent;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int V, E;
    
    cin >> V >> E;
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    
    parent.resize(V+1);
    
    for (int i=0;i<E;i++)
    {
        int A, B, C;
        
        cin >> A >> B >> C;
        
        pq.push(Edge{A, B, C});
    }
    
    for (int i=1;i<=V;i++)
    {
        parent[i] = i;
    }
    
    int result = 0;
    int useEdge = 0;
    
    while (useEdge < V-1)
    {
        Edge now = pq.top();
        
        pq.pop();
        
        if (findFunc(now.s) != findFunc(now.e))
        {
            unionFunc(now.s, now.e);
            
            result += now.w;
            
            useEdge++;
        }
    }
    
    cout << result;
    
    return 0;
}

int findFunc(int a)
{
    if (a != parent[a])
    {
        return parent[a] = findFunc(parent[a]);
    }
    
    else return a;
}

void unionFunc(int a, int b)
{
    a = findFunc(a);
    b = findFunc(b);
    
    if (a != b)
    {
        parent[b] = a;
    }
}
