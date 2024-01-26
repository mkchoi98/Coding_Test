//
//  main.cpp
//  11657
//
//  Created by 최민경 on 2024/01/26.
//

#include <iostream>
#include <vector>
#include <tuple>

#define MAX 987654321

using namespace std;

typedef tuple<int, int, int> edge;
static int N, M;
static vector<long> mdistance;
static vector<edge> edges;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    mdistance.resize(N+1);
    std::fill(mdistance.begin(), mdistance.end(), MAX);
    
    for (int i=0;i<M;i++)
    {
        int start, end, time;
        
        cin >> start >> end >> time;
        
        edges.push_back({start, end, time});
    }
    
    // 벨만-포드 알고리즘
    mdistance[1] = 0;
    
    for (int i=1;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);
            
            if (mdistance[start] != MAX && mdistance[end] > mdistance[start] + time)
            {
                mdistance[end] = mdistance[start] + time;
            }
        }
    }
    
    // 음수 사이클 확인
    
    bool mCycle = false;
    
    for (int j=0;j<M;j++)
    {
        edge medge = edges[j];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);
        
        if (mdistance[start] != MAX && mdistance[end] > mdistance[start] + time)
        {
            mCycle = true;
        }
    }
    
    if (mCycle)
    {
        cout << "-1";
    }
    
    else
    {
        for (int i=2;i<=N;i++)
        {
            if (mdistance[i] == MAX)
            {
                cout << "-1\n";
            }
            
            else
            {
                cout << mdistance[i] << "\n";
            }
        }
    }
    
    return 0;
}
