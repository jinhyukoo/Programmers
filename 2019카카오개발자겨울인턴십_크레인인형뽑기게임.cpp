#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int i = 0 ; i<moves.size() ; i++)
    {
        int next = moves[i] - 1;
        for(int j = 0 ; j<board.size() ; j++)
        {
            if(board[j][next])
            {
                if(s.empty())
                {
                    s.push(board[j][next]);
                }
                else
                {
                    if(s.top() == board[j][next])
                    {
                        answer += 2;
                        s.pop();
                    }
                    else s.push(board[j][next]);
                }
                board[j][next] = 0;
                break;
            }
        }
    }
    return answer;
}
