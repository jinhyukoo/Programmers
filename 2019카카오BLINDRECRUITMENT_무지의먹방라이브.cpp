#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
struct data{
    int time;
    int index;
};

bool cmp(const data &p1, const data &p2){
    if(p1.index < p2.index){
        return true;
    }
    else{
        return false;
    }
}
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0, delete_time;
    long long time_count = 0, delete_count = 0;
    vector<struct data> v;
    priority_queue<pair<int, int>> pq;
    for(int i = 0 ; i<food_times.size() ; i++)
    {
        time_count += food_times[i];
        pq.push({-food_times[i], i+1});
    }
    if(time_count <= k) return -1;
    time_count = 0;
    //벡터를 오름 차순으로 정렬하여 앞에서부터 시간을 제거해간다.
    while(time_count + (pq.size() * (-pq.top().first - delete_count)) <= k)
    {
        delete_time = -pq.top().first; //삭제될 시간
        time_count += (pq.size() * (delete_time - delete_count)); //삭제될 시간 - 그동안 삭제된 시간
        pq.pop();

        int temp = delete_time - delete_count; //실제로 삭제된 시간
        delete_count += temp;//그동안 삭제된 시간 업데이트
    }
    for(int i = 0 ; !pq.empty() ; i++)
    {
        v.push_back({-pq.top().first, pq.top().second});
        pq.pop();
    }
    cout<<v.size();
    stable_sort(v.begin(), v.end(), cmp);

    long long temp_index = (k - time_count)%v.size();
    answer = (v.begin() + temp_index)->index;
    return answer;
}
