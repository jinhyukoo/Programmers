#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int check[100001] = {0, }, max_num = 0;
    for(int i = 0 ; i<s.size() ; i++)
    {
        if(s[i] < '0' && s[i] > '9') continue;
        else
        {
            string temp = "";
            while(s[i] >= '0' && s[i] <='9')
            {
                temp+=s[i];
                i++;
            }
            int num = atoi(temp.c_str());
            max_num = max(max_num, num);
            check[num]++;
        }
    }
    map<int, int> m;
    map<int, int>::iterator iter;
    for(int i = 1 ; i<=max_num ; i++){
        if(check[i]){
            m.insert({-check[i], i});
        }
    }
    for(iter = m.begin() ; iter != m.end() ; iter++)
    {
        answer.push_back((iter->second));
    }
    return answer;
}
