#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> parent;

long long find(long long u)
{
  if(u == parent[u]) return u;
  return parent[u] = find(parent[u]);
}
void merge(long long u, long long v)
{
  u = find(u); v = find(v);
  if(u == v) return;
  parent[v] = u;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i = 0 ; i<room_number.size() ; i++)
    {
        if(parent.find(room_number[i]) == parent.end())
        {
            parent.insert({room_number[i], room_number[i]});
            answer.push_back(room_number[i]);
            if(parent.find(room_number[i] - 1) != parent.end())
            {
                merge(room_number[i], room_number[i] - 1);
            }
            if(parent.find(room_number[i] + 1) != parent.end())
            {
                merge(room_number[i] + 1, room_number[i]);
            }
        }
        else
        {
            long long temp = find(room_number[i]);
            parent.insert({temp + 1, temp + 1});
            answer.push_back(temp + 1);
            merge(temp + 1, temp);
            if(parent.find(temp + 2) != parent.end())
            {
                merge(temp + 2, temp + 1);
            }
        }
    }
    return answer;
}
