#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0, left = 0, right = 200000000;
    while(left <= right)
    {
        vector<int> temp_stones = stones;
        int mid = (left + right)/2, space_count = 0, flag = 0;
        for(int i = 0 ; i<temp_stones.size() ; i++)
        {
            temp_stones[i] -= mid;
        }
        for(int i = 0 ; i<temp_stones.size() ; i++)
        {
            if(temp_stones[i] <= 0) space_count++;
            else space_count = 0;
            if(space_count>=k)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            right = mid - 1;
            answer = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}
