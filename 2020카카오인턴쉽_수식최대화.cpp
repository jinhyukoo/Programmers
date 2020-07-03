#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;
vector<string> num;
vector<char> operand;
long long calcul(string order)
{
    vector<string> temp_num = num;
    vector<char> temp_operand = operand;
    for(int i = 0 ; i<order.size() ; i++)
    {
        for(int j = 0 ; j<temp_operand.size() ; j++)
        {
            if(temp_operand[j] == order[i])
            {
                long long temp1 = stoll(temp_num[j]), temp2 = stoll(temp_num[j+1]);
                //연산을 하기 위한 숫자 2개를 vector에서 빼준다.
                temp_num.erase(temp_num.begin() + j);
                temp_num.erase(temp_num.begin() + j); //삭제되면 그 다음 숫자가 삭제된 수가 있던 자리로 오기 때문에 그 자리에서 한 번더 삭제
                string temp_input;
                //부호 종류에 따라 연산을 설정
                if(order[i] == '*') temp_input = to_string(temp1 * temp2);
                else if(order[i] == '-') temp_input = to_string(temp1 - temp2);
                else temp_input = to_string(temp1 + temp2);
                //연산한 값을 다시 그 자리에 넣어준다.
                temp_num.insert(temp_num.begin() + j, temp_input);
                //연산자도 제거해준다.
                temp_operand.erase(temp_operand.begin() + j);
                //연산자를 제거 해줬으니 한 칸 앞으로 가서 다시 탐색을 시작한다.
                j--;
            }
        }
    }
    return stoll(temp_num[0]);
}
long long solution(string expression) {
    long long answer = 0;
    string temp = "";
    //숫자와 연산자를 구분하여 vector에 저장한다.
    for(int i = 0 ; i<expression.size() ; i++)
    {
        if(expression[i] != '-' && expression[i] != '+' && expression[i] != '*')
        {
            temp += expression[i];
        }
        else
        {
            operand.push_back(expression[i]);
            num.push_back(temp);
            temp = "";
        }
    }
    num.push_back(temp); //마지막 숫자까지 push_back
    //총 6가지의 경우의 수가 있으므로 각 경우의 수 중 가장 큰 값을 찾는다.
    long long r = abs(calcul("*+-"));
    r = max(r, abs(calcul("*-+")));
    r = max(r, abs(calcul("+-*")));
    r = max(r, abs(calcul("+*-")));
    r = max(r, abs(calcul("-*+")));
    r = max(r, abs(calcul("-+*")));
    answer = r;
    return answer;
}
