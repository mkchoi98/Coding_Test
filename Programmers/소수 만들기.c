#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int cnt = 0;
    int i, j, k, l;
    int flag = 0;
    
    for (i=0;i<nums_len-2;i++)
    {
        for (j=i+1;j<nums_len-1;j++)
        {
            for (k=j+1;k<nums_len;k++)
            {
                flag = 0;
                for (l=2;l<nums[i]+nums[j]+nums[k];l++)
                {
                    if ((nums[i]+nums[j]+nums[k]) % l == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    answer++;
            }
        }
    }
    
    return answer;
}
