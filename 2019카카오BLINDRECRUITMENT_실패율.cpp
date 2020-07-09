#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct data{
    double lose;
    int index;
};

bool cmp(const data &p1, const data &p2){
    if(p1.lose > p2.lose){
        return true;
    }
    else{
        return false;
    }
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stage_clear(N+1, 0), stage_challenger(N+2, 0);
    vector<struct data> lose_v;
    for(int i = 0 ; i<stages.size() ; i++)
    {
        if(stages[i] == N+1) continue;
        stage_challenger[stages[i]]++;
    }
    for(int i = 1 ; i<=N ; i++)
    {
        cout<<stage_challenger[i]<<" ";
    }
    cout<<'\n';
    double divider = stages.size();
    for(int i = 1 ; i<=N ; i++)
    {
        double temp = stage_challenger[i];
        lose_v.push_back({temp/divider, i});
        divider -= stage_challenger[i];
    }
    for(int i = 0 ; i<lose_v.size() ; i++)
    {
        cout<<lose_v[i].index<<" "<<lose_v[i].lose<<'\n';
    }
    stable_sort(lose_v.begin(), lose_v.end(), cmp);
    for(int i = 0 ; i<lose_v.size() ; i++) answer.push_back(lose_v[i].index);
    return answer;
}
