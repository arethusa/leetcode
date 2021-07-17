#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> run(std::vector<int>& arr)
    {
        int sum = 0;
        std::vector<int> sum_index(arr.size() + 1, -1);

        for(int index = 0; index < arr.size(); index++) {
            sum = sum + arr[index];
            sum_index[sum] == -1 ? sum_index[sum] = index : sum_index[sum] = sum_index[sum];
        }

        if (0 != sum % 3 || arr.size() < 3) {
            return std::vector<int>({-1, -1});
        } else if (0 == sum) {
            return std::vector<int>({0, 2});
        }
        int target1 = sum / 3;
        int target2 = target1 * 2;
        int target3 = target1 * 3;
        int f1 = sum_index[target1], f2 = sum_index[target1 + 1] - 1;
        int s1 = sum_index[target2], s2 = sum_index[target2 + 1] - 1;
        int t1 = sum_index[target3], t2 = arr.size() - 1;
        int diff = t2 - t1;
        f1 = f1 + diff;
        s1 = s1 + diff;

        if (f2 < f1 || s2 < s1) {
            return std::vector<int>({-1, -1});
        }

        int check_count = t2 - sum_index[target2 + 1] + 1;
        for (int index = 0; index < check_count; index++) {
            int f = arr[f1 - index];
            int s = arr[s1 - index];
            int t = arr[t2 - index];

            if (f != s || s != t) {
                return std::vector<int>({-1, -1});
            }
        }

        return std::vector<int>({f1, s1 + 1});
    }

    bool exam(std::vector<int> &result, std::vector<int> &arr)
    {
        std::vector<int> answer = run(arr);
        auto rit = result.begin();
        auto ait = answer.begin();

        for (;rit != result.end() && ait != answer.end();rit++, ait++) {
           if (*rit != *ait) {
               return false;
           } 
        }

        return rit == result.end() && ait == answer.end();
    }
};

int main()
{
    Solution s;

    std::vector<int> case1({1,0,1,0,1});
    std::vector<int> result1({0, 3});
    if (!s.exam(result1, case1)) {
       std::cout << "Failed test case 1!\n";
    }

    std::vector<int> case2({1,1,0,1,1});
    std::vector<int> result2({-1, -1});
    if (!s.exam(result2, case2)) {
       std::cout << "Failed test case 2!\n";
    }

    std::vector<int> case3({0,0,0,0,0});
    std::vector<int> result3({0, 2});
    if (!s.exam(result3, case3)) {
       std::cout << "Failed test case 3!\n";
    }

    std::vector<int> case4({1,1,1});
    std::vector<int> result4({0, 2});
    if (!s.exam(result4, case4)) {
       std::cout << "Failed test case 4!\n";
    }

    std::vector<int> case5({0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1});
    std::vector<int> result5({-1, -1});
    if (!s.exam(result5, case5)) {
       std::cout << "Failed test case 5!\n";
    }

    std::vector<int> case6({1,1,1,1,1,1,0,1,1,1});
    std::vector<int> result6({2, 6});
    if (!s.exam(result6, case6)) {
       std::cout << "Failed test case 6!\n";
    }


    return 0;
}
