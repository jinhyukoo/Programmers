#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;
int arr[4][3] = {0, };
int d[10][2] = {{3,1}, {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
pair<int, int> find_left()
{
    for(int i = 0 ; i<4 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            if(arr[i][j] == 1) return {i,j};
        }
    }
}
pair<int, int> find_right()
{
    for(int i = 0 ; i<4 ; i++)
    {
        for(int j = 0 ; j<3 ; j++)
        {
            if(arr[i][j] == 2) return {i,j};
        }
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    arr[3][0] = 1; arr[3][2] = 2;
    for(int i = 0 ; i<numbers.size() ; i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            pair<int, int> temp = find_left();
            answer += "L";
            arr[temp.first][temp.second] = 0;
            arr[d[numbers[i]][0]][d[numbers[i]][1]] = 1;

        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            pair<int, int> temp = find_right();
            answer += "R";
            arr[temp.first][temp.second] = 0;
            arr[d[numbers[i]][0]][d[numbers[i]][1]] = 2;

        }
        else
        {
            pair<int, int> temp_left = find_left();
            pair<int, int> temp_right = find_right();
            int temp_y = d[numbers[i]][0], temp_x = d[numbers[i]][1];
            pair<int, int> left_mid, right_mid;
            int lm = abs(temp_left.first - temp_y) + abs(temp_left.second - temp_x);
            int rm = abs(temp_right.first - temp_y) + abs(temp_right.second - temp_x);
            if(lm == rm)
            {
                if(hand == "right")
                {
                    arr[temp_right.first][temp_right.second] = 0;
                    answer += "R";
                    arr[temp_y][temp_x] = 2;
                }
                else
                {
                    arr[temp_left.first][temp_left.second] = 0;
                    answer += "L";
                    arr[temp_y][temp_x] = 1;
                }
            }
            else if(lm > rm)
            {
                arr[temp_right.first][temp_right.second] = 0;
                answer += "R";
                arr[temp_y][temp_x] = 2;
            }
            else
            {
                arr[temp_left.first][temp_left.second] = 0;
                answer += "L";
                arr[temp_y][temp_x] = 1;
            }
        }
    }
    return answer;
}
