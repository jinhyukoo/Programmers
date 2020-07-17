#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    for(int i = 0  ; i<operations.size() ; i++)
    {
        if(operations[i][0] == 'I')
        {
            if(operations[i][2] == '-')
            {
                string temp = "";
                for(int j = 3 ; operations[i][j]>='0' && operations[i][j]<='9' ; j++) temp += operations[i][j];
                int num = -atoi(temp.c_str());
                v.push_back(num);
            }
            else
            {
                string temp = "";
                for(int j = 2 ; operations[i][j]>='0' && operations[i][j]<='9' ; j++) temp += operations[i][j];
                int num = atoi(temp.c_str());
                v.push_back(num);
            }

        }
        else
        {
            if(!v.empty())
            {
                if(operations[i][2] == '1')
                {
                    sort(v.begin(), v.end());
                    v.erase(v.begin() + v.size() - 1);
                }
                else
                {
                    sort(v.begin(), v.end());
                    v.erase(v.begin());
                }
            }
        }
    }
    if(v.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        sort(v.begin(), v.end());
        answer.push_back(v[v.size()-1]);
        answer.push_back(v[0]);
    }

    return answer;
}
