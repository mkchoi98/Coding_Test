//
//  main.c
//  1717
//
//  Created by 최민경 on 2023/09/08.
//

#include <stdio.h>

int getParent(int num, int parent[])
{
    if (parent[num] == num) return num;
    
    return parent[num] = getParent(parent[num], parent);
}

void unionParent(int a, int b, int parent[])
{
    int a_parent = getParent(a, parent);
    int b_parent = getParent(b, parent);
    
    if (a_parent < b_parent)
    {
        parent[b_parent] = a_parent;
    }
    
    else parent[a_parent] = b_parent;
}

int main(int argc, const char * argv[]) {
    int n, m;
    int parent[1000001];
    int op, a, b;
    
    scanf("%d %d", &n, &m);
    
    int i;
    
    for (i=0;i<=n;i++)
    {
        parent[i] = i;
    }
    
    for (i=0;i<m;i++)
    {
        scanf("%d %d %d", &op, &a, &b);
        
        if (op == 0)
        {
            unionParent(a, b, parent);
        }
        
        else
        {
            if (getParent(a, parent) == getParent(b, parent))
            {
                printf("YES\n");
            }
            
            else printf("NO\n");
        }
    }
    
    return 0;
}
