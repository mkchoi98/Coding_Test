#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimitor);
int mySum(string a);

int main()
{
    int answer = 0;
    string example;
    
    cin >> example;
    
    vector<string> str = split(example, '-');
    
    for (int i=0;i<str.size();i++)
    {
        int temp = mySum(str[i]);
        
        if (i == 0)
        {
            answer += temp;
        }
        
        else
        {
            answer -= temp;
        }
    }
    
    cout << answer;
    
    return 0;
}

vector<string> split(string input, char delimiter)
{
    vector<string> result;
    stringstream mystream(input);
    string str;
    
    while (getline(mystream, str, delimiter))
    {
        result.push_back(str);
    }
    
    return result;
}

int mySum(string a)
{
    int sum = 0;
    vector<string> str = split(a, '+');
    
    for (int i=0;i<str.size();i++)
    {
        sum += stoi(str[i]);
    }
    
    return sum;
}
