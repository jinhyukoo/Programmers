#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
//콘이 셔틀을 타고 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각을 구하여라.
//콘은 같은 시각에 도착한 크루 중 대기열에서 제일 뒤에 선다.
//하루가 지나면 대기열은 초기화된다.
//즉 n*t보다 timetable의 원소값이 클 경우 이 원소들은 무시해도 된다는 말이다.
//계산해야 할 것은 09:00보다는 값이 크고 09:00 + n*t 보다는 작은 timetable의 원소가 몇 개인지 세어야 한다.
//버스가 떠날때마다 timetable에서 빠질 수 있는 원소는 모두 빼주자.
//그렇게 count를 하다가 마지막 값에 도달하면 그 값이 정답이 될 것이다.
using namespace std;

int string_to_int(string s)
{
    string temp_hour = "", temp_minute = "";
    int int_hour = 0, int_minute = 0, int_time = 0;
    int_hour += (s[0] - '0') * 600;
    int_hour += (s[1] - '0') * 60;
    int_minute += (s[3] - '0') * 10;
    int_minute += (s[4] - '0');
    int_time = int_hour + int_minute;
    return int_time;
}
string int_to_string(int n)
{
    int hour = n/60, minute = n%60;
    string temp_hour = "0", temp_minute = "0";
    if(hour >= 10)
    {
        temp_hour = "";
        temp_hour = to_string(hour);
    }
    else
    {
        temp_hour += to_string(hour);
    }
    if(minute >= 10)
    {
        temp_minute = "";
        temp_minute = to_string(minute);
    }
    else
    {
        temp_minute += to_string(minute);
    }
    return temp_hour + ":" + temp_minute;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> timetable_int;
    vector<int> bus_timetable;
    int bus_arrive = 540;
    //todo : timetable의 원소 int형태로 변환하기
    for(int i = 0 ; i<timetable.size() ; i++)
    {
        int temp = string_to_int(timetable[i]);
        if(temp > 1080 && temp < 1440) continue;
        timetable_int.push_back(temp);
    }
    sort(timetable_int.begin(), timetable_int.end());
    for(int i = 0 ; i<n ; i++)
    {
        bus_timetable.push_back(bus_arrive + i*t);
    }
    for(int i = 0 ; i<bus_timetable.size()-1 ; i++)
    {
        int count = 0;
        while(!timetable_int.empty() && count<m && timetable_int[0] <= bus_timetable[i])
        {
            timetable_int.erase(timetable_int.begin());
            count++;
        }
    }
    int count = 0, result;
    while(!timetable_int.empty() && count<m && timetable_int[0] <= bus_timetable[n-1])
    {
        count++;
        if(count == m)
        {
            result = timetable_int[0] - 1;
            break;
        }
        timetable_int.erase(timetable_int.begin());
    }
    if(count<m) result = bus_timetable[n-1];
    answer = int_to_string(result);
    return answer;
}
