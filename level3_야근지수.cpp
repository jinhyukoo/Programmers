#include <string>
#include <vector>
#include <queue>
#include <iostream>
//야근피로도 : 야근을 시작한 시점에서 남을 일의 작업량을 제곱하여 더한 값
//todo : 야근 피로도 최소화
//Demi는 1시간에 작업량 1을 처리할 수 있음.
//높은 수부터 1씩 계속 깎아내려가면 된다. 그래야 제곱의 크기가 가장 작다.
//priority_queue를 써서 top을 pop하고 -1을 해준다음 다시 push하는 것을 반복해보자.
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int i = 0 ; i<works.size() ; i++) pq.push(works[i]);
    for(int i = 0 ; i<n ; i++)
    {
        int temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
    }
    while(!pq.empty())
    {
        int temp = pq.top();
        pq.pop();
        if(temp < 0) continue;
        answer += temp*temp;
    }
    return answer;
}
