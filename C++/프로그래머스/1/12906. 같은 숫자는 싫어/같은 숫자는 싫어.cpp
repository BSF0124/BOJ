#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int pos = 0;
    for(auto i : arr)
    {
        if(answer.empty() || answer[pos-1] != i) 
        {
            answer.push_back(i);
            pos++;
        }
    }

    return answer;
}