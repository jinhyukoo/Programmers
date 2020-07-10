#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
int N;
bool check(int y, int x)
{
    return (y>=0 && x>=0 && y<=N && x<=N);
}
using namespace std;

int map[101][101][2] = {0, }; //map[y][x][0] 에는 기둥, map[y][x][1]에는 보에 대한 정보 입력하기
bool check_k(int y, int x)
{
    //1을 리턴하면 설치 가능
    if(y == 0) return 1;
    if(check(y-1, x) && map[y-1][x][0]) return 1;
    if(map[y][x-1][1]) return 1;
    if(map[y][x][1]) return 1;
    return 0;
}

bool check_b(int y, int x)
{
    //1을 리턴하면 설치 가능
    if((check(y,x-1) && map[y][x-1][1]) && (check(y, x+1) && map[y][x+1][1])) return 1;
    if(map[y-1][x][0]) return 1;
    if(map[y-1][x+1][0]) return 1;
    return 0;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for(int i = 0 ; i<build_frame.size() ; i++)
    {
        int x = build_frame[i][0], y = build_frame[i][1];
        if(build_frame[i][2]) // 보
        {
            if(build_frame[i][3]) //설치
            {
                if(check_b(y,x)) map[y][x][1] = 1;
            }
            else //삭제
            {
                //보를 삭제할 때 봐야 할 것
                //좌우에 있는 보와 보에 설치된 기둥들이 조건을 충족시키는지 확인할 것
                //삭제할 보가 x,y라고 했을 때 x-1,y, x+1,y에 있는 보와, x,y, x+1,y에 있는 기둥이 조건을 충족하는지 확인할 것
                //map에서 그 부분에 대한 정보를 없애고 4가지 케이스에 대해 1을 return 하는지 확인
                map[y][x][1] = 0;
                if(map[y][x-1][1])
                {
                    if(!check_b(y,x-1))
                    {
                        map[y][x][1] = 1;
                        continue;
                    }
                }
                if(map[y][x+1][1])
                {
                    if(!check_b(y,x+1))
                    {
                        map[y][x][1] = 1;
                        continue;
                    }
                }
                if(map[y][x][0])
                {
                    if(!check_k(y,x))
                    {
                        map[y][x][1] = 1;
                        continue;
                    }
                }
                if(map[y][x+1][0])
                {
                    if(!check_k(y,x+1))
                    {
                        map[y][x][1] = 1;
                        continue;
                    }
                }
            }
        }
        else // 기둥
        {
            //기둥을 삭제할 때 봐야 할 것
            //기둥을 삭제한 후 기둥과 연결되어 있던 보들이 보를 세울 때 봐야 할 기준을 충족시키는가
            //삭제할 기둥이 x,y라고 했을 때 x,y+1, x-1,y+1 에 보가 있다면 기준을 충족하는지 확인할 것, x,y+1에 있는 기둥이 기준을 충족하는지 확인할 것
            //map에서 그 부분에 대한 정보를 없애고 3가지 케이스에 대해 1을 return 하는지 확인
            if(build_frame[i][3]) //설치
            {
                if(check_k(y,x)) map[y][x][0] = 1;
            }
            else //삭제
            {
                map[y][x][0] = 0;
                if(map[y+1][x][0])
                {
                    if(!check_k(y+1,x))
                    {
                        map[y][x][0] = 1;
                        continue;
                    }
                }
                if(map[y+1][x-1][1])
                {
                    if(!check_b(y+1,x-1))
                    {
                        map[y][x][0] = 1;
                        continue;
                    }
                }
                if(map[y+1][x][1])
                {
                    if(!check_b(y+1,x))
                    {
                        map[y][x][0] = 1;
                        continue;
                    }
                }
            }
        }
    }
    //완성한 맵을 돌며 정보 넣어주기
    for(int i = 0 ; i<=n ; i++)
    {
        for(int j = 0 ; j<=n ; j++)
        {
            if(map[j][i][0]) answer.push_back({i,j,0});
            if(map[j][i][1]) answer.push_back({i,j,1});
        }
    }

    return answer;
}
