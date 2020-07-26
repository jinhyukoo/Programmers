#include <string>
#include <vector>
using namespace std;

long long solution(int N) {
    long long answer = 0, fibo[81] = {1,1, };
    for(int i = 2 ;i<=N;i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    answer = fibo[N-1]*2 + fibo[N]*2;
    return answer;
}
