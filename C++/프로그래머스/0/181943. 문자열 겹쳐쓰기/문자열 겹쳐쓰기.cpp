#include <string>
#include <vector>

using namespace std;

string solution(string my, string over, int s) 
{
    string ans = my;
    ans.replace(s, over.size(), over);
    return ans;
}