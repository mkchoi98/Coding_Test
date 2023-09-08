//
//  main.c
//  1976
//
//  Created by 최민경 on 2023/09/08.
//

#include <stdio.h>

int getParent(int num, int parent[])
{
    if (parent[num] == num)
        return num;
    
    parent[num] = getParent(parent[num], parent);
    
    return parent[num];
}

void unionParent(int a, int b, int parent[])
{
    int a_parent = getParent(a, parent);
    int b_parent = getParent(b, parent);
    
    if (a_parent < b_parent)
    {
        parent[b_parent] = a_parent;
    }
    
    else
    {
        parent[a_parent] = b_parent;
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int input;
    int city[1001];
    
    int parent[201];
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    int i, j;
    
    for (i=0;i<n;i++)
    {
        parent[i] = i;
    }
    
    //for (i=0;i<n;i++) printf("%d ", parent[i]);
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &input);
            
            if (input == 1)
            {
                unionParent(i, j, parent);
            }
        }
    }
    
    //for (i=0;i<n;i++) printf("%d ", parent[i]);
    
    for (i=0;i<m;i++)
    {
        scanf("%d", &city[i]);
    }
    
    int first_parent = getParent(city[0]-1, parent);
    
    for (i=1;i<m;i++)
    {
        if (getParent(city[i]-1, parent) != first_parent)
        {
            /*printf("NO");
            
            return 0;*/
            
            break;
        }
    }
    
    if (i < m) printf("NO");
    else printf("YES");
    
    return 0;
}
