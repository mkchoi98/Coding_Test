//
//  main.cpp
//  1715
//
//  Created by 최민경 on 2024/01/22.
//

#include <iostream>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> que; // 오름차순 정렬
    int card_num;
    
    for (int i=0;i<N;i++)
    {
        cin >> card_num;
        
        que.push(card_num);
    }
    
    int sum;
    int cnt = 0;
    
    while (que.size() != 1)
    {
        int n1, n2;
        
        n1 = que.top();
        que.pop();
        n2 = que.top();
        que.pop();
        
        sum = n1+n2;
        
        //cout << sum << endl;
        
        que.push(sum);
        
        cnt += sum;
    }
    
    cout << cnt;
    
    return 0;
}
