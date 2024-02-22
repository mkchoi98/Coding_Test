//
//  main.cpp
//  20546
//
//  Created by 최민경 on 2024/02/22.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int money_jh, money_sm;
    int money;
    
    cin >> money;
    
    money_jh = money_sm = money;
    
    int MachineDuck[14];
    
    for (int i=0;i<14;i++)
    {
        cin >> MachineDuck[i];
    }
    
    int cnt = 0;
    
    for (int i=0;i<14;i++)
    {
        while (MachineDuck[i] <= money_jh)
        {
            money_jh -= MachineDuck[i];
            cnt++;
        }
    }
    
    money_jh += cnt*MachineDuck[13];
    
    int cnt_up = 0, cnt_down = 0;
    bool sell = false, buy = false;
    cnt = 0;
    
    for (int i=1;i<14;i++)
    {
        if (sell)
        {
            money_sm += cnt*MachineDuck[i];
            cnt = 0;
            
            sell = false;
        }
        
        if (buy)
        {
            while (MachineDuck[i] <= money_sm)
            {
                money_sm -= MachineDuck[i];
                cnt++;
            }
            
            buy = false;
        }
        
        if (MachineDuck[i-1] < MachineDuck[i]) cnt_up++;
        else cnt_up = 0;
        
        if (MachineDuck[i-1] > MachineDuck[i]) cnt_down++;
        else cnt_down = 0;
        
        if (cnt_up >= 2)
        {
            sell = true;
        }
        
        if (cnt_down >= 2)
        {
            buy = true;
        }
    }
    
    if (cnt != 0)
    {
        money_sm += cnt*MachineDuck[13];
    }
    
    if (money_sm > money_jh)
        cout << "TIMING";
    else if (money_sm < money_jh)
        cout << "BNP";
    else
        cout << "SAMESAME";
    
    return 0;
}
