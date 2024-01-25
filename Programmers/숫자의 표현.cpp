#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    if (n == 1)
    {
        return answer;
    }
    
    vector<int> a(n+1);
    
    for (int i=1;i<=n;i++)
    {
        a[i] = i;
    }
    
    int p1 = 1, p2 = 2;
    
    int sum = a[p1]+a[p2];
    
    while (p1 < p2)
    {
        if (sum < n)
        {
            p2++;
            sum += a[p2];
        }
        
        else if (sum > n)
        {
            sum -= a[p1];
            p1++;
        }
        
        else if (sum == n)
        {
            answer++;
            
            p2++;
            sum += a[p2];
        }
    }
    
    return answer;
}
