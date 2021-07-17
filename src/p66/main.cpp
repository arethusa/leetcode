#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        bool plusOne = true;

        for (auto it = digits.rbegin(); it != digits.rend() && plusOne; it++) {
            *it = *it + 1;

            if (10 == *it) {
                *it = 0;
                continue;
            }

            plusOne = false;
        }

        if (plusOne) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }

    bool exam(std::vector<int> &result, std::vector<int> &digits)
    {
        std::vector<int> answer = plusOne(digits);
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

    std::vector<int> testCase1({1, 2, 3, 4});
    std::vector<int> result1({1, 2, 3, 5});
    if (!s.exam(result1, testCase1)) {
       std::cout << "Failed test case 1!\n";
    }

    std::vector<int> testCase2({1, 9});
    std::vector<int> result2({2, 0});
    if (!s.exam(result2, testCase2)) {
       std::cout << "Failed test case 2!\n";
    }

    std::vector<int> testCase3({9, 9});
    std::vector<int> result3({1, 0, 0});
    if (!s.exam(result3, testCase3)) {
       std::cout << "Failed test case 3!\n";
    }

    return 0;
}
