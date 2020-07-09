#include <string>
#include <vector>
#include <map>

using namespace std;
struct data{
    string id;
    string order;
};
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> id_nickname;
    vector<struct data> id_order;
    for(int i = 0 ; i<record.size() ; i++)
    {
        string order = "", id = "", nickname = "";
        int count = 0;
        for(int j = 0 ; j<record[i].size() ; j++)
        {
            if(record[i][j] == ' '){
                count++;
                continue;
            }
            if(count == 0) order += record[i][j];
            if(count == 1) id += record[i][j];
            if(count == 2) nickname += record[i][j];
        }
        if(order == "Enter")
        {
            //들어오면 아이디, 닉네임 map에 저장
            //id와 order id_order 벡터에 저장
            id_nickname[id] = nickname;
            id_order.push_back({id, order});
        }
        else if(order == "Change")
        {
            //map에서 아이디, 닉네임 바꾸기
            id_nickname[id] = nickname;
        }
        else
        {
            //id_order 벡터에 명령 입력
            id_order.push_back({id, order});
        }
    }
    for(int i = 0 ; i<id_order.size() ; i++)
    {
        string temp = "";
        if(id_order[i].order == "Enter")
        {
            temp += id_nickname.find(id_order[i].id)->second;
            temp += "님이 들어왔습니다.";
        }
        else
        {
            temp += id_nickname.find(id_order[i].id)->second;
            temp += "님이 나갔습니다.";
        }
        answer.push_back(temp);
    }
    return answer;
}
