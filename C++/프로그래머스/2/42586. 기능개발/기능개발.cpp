#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prog, vector<int> speeds) {
    vector<int> answer;
    
    for(int i = 0; i < prog.size(); i++)
    {
        int tmp = 100 - prog[i];
        prog[i] = (tmp + speeds[i] - 1) / speeds[i];
    }
    
    int cur = prog[0], cnt = 1;
    for(int i = 1; i < prog.size(); i++)
    {
        if(prog[i] <= cur) cnt++;
        else
        {
            answer.push_back(cnt);
            cur = prog[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}