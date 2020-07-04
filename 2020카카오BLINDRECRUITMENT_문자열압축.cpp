#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string answer_str = s;
    for(int i = 1 ; i<=s.size()/2 ; i++)
    {
        string temp_str = "";
        vector<string> v;
        for(int j = 0 ; j<s.size() ; j+=i)
        {
            string temp = s.substr(j,i);
            v.push_back(temp);
        }
        if(s.size() % i != 0)
        {
            int temp_divide = s.size()/i, temp_minus = s.size() - (temp_divide * i);
            string temp = s.substr(temp_divide * i, temp_minus);
        }
        int count = 1;
        for(int j = 1 ; j<v.size() ; j++)
        {
            if(v[j] == v[j-1]){
                count++;
            }
            else if(v[j] != v[j-1])
            {
                if(count == 1)
                {
                    temp_str += v[j-1];
                }
                else
                {
                    temp_str += to_string(count);
                    temp_str += v[j-1];
                    count = 1;
                }
            }
        }
        if(count != 1)
        {
            temp_str += to_string(count);
            temp_str += v.back();
        }
        else
        {
            temp_str += v.back();
        }
        if(answer_str.size() > temp_str.size()) answer_str = temp_str;
    }
    answer = answer_str.size();
    return answer;
}
