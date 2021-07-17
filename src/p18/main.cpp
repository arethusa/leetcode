#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        int max_size = nums.size();
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int index1 = 0; index1 < max_size - 3; index1 = nextIndex(nums, index1, max_size - 3)) {
            int num1 = nums[index1];
            int target1 = target - num1;

            if (target1 < nums[index1 + 1] + nums[index1 + 2] + nums[index1 + 3]) {
                break;
            } else if (target1 > nums[max_size - 1] + nums[max_size - 2] + nums[max_size - 3]) {
                continue;
            }
            
            for (int index2 = index1 + 1; index2 < max_size - 2; index2 = nextIndex(nums, index2, max_size - 2)) {
                int num2 = nums[index2];
                int target2 = target1 - num2;
                if (target2 < nums[index2 + 1] + nums[index2 + 2]) {
                    break;
                } else if (target2 > nums[max_size - 1] + nums[max_size - 2]) {
                    continue;
                }

                for (int index3 = index2 + 1; index3 < max_size - 1; index3 = nextIndex(nums, index3, max_size - 1)) {
                    int num3 = nums[index3];
                    int target3 = target2 - num3;
                    int index4 = -1;

                    if (target3 < nums[index3 + 1]) {
                        continue;
                    } else if (target3 == nums[index3 + 1]) {
                        index4 = index3 + 1; 
                    } else if (target3 > nums[max_size - 1]) {
                        continue;
                    } else if (target3 == nums[max_size - 1]) {
                        index4 = max_size -1;
                    } else {
                        index4 = findNum(nums, index3 + 1, max_size - 1, target3);
                    }

                    if (-1 != index4) {
                        result.push_back({nums[index1], nums[index2], nums[index3], nums[index4]});
                    }
                }
            }
        }
        
        return result;
    }

    int nextIndex(std::vector<int> &nums, int start, int end)
    {
        int index = start;
        int number = nums[start];

        while(index < end && number == nums[index]) {
            index++;
        }

        return index;
    }

    int findNum(std::vector<int> &nums, int start, int end, int target)
    {
        int index = (start + end) / 2;

        if (start > end) {
           return -1;
        } else if(nums[index] < target) {
            return findNum(nums, index + 1, end, target); 
        } else if (nums[index] > target) {
            return findNum(nums, start, index -1, target); 
        }

        return index;
    }

    bool exam(std::vector<std::vector<int>> &result, int target, std::vector<int> &numbers)
    {
        std::vector<std::vector<int>> answer = fourSum(numbers, target);

        if (result.size() != answer.size()) {
            return false;
        }

        for (auto r: result) {
            bool find = false;

            for (auto a: answer) {
                auto rit = r.begin();
                auto ait = a.begin();

                for (;rit != r.end() && ait != a.end();rit++, ait++) {
                    if (*rit != *ait) {
                        break;
                    } 
                }

                if (rit == r.end() && ait == a.end()) {
                    find = true;
                    break;
                }
            }

            if (!find) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;

    int case1_target = 0;
    std::vector<int> case1_numbers({1, 0, -1, 0, -2, 2});
    std::vector<std::vector<int>> result1;
    result1.push_back({-2, -1, 1, 2});
    result1.push_back({-2, 0 , 0, 2});
    result1.push_back({-1, 0, 0, 1});

    if (!s.exam(result1, case1_target, case1_numbers)) {
       std::cout << "Failed test case 1!\n";
    }

    int case2_target = 8;
    std::vector<int> case2_numbers({2, 2, 2, 2});
    std::vector<std::vector<int>> result2;
    result2.push_back({2, 2, 2, 2});

    if (!s.exam(result2, case2_target, case2_numbers)) {
       std::cout << "Failed test case 2!\n";
    }

    int case3_target = -11;
    std::vector<int> case3_numbers({1,-2,-5,-4,-3,3,3,5});
    std::vector<std::vector<int>> result3;
    result3.push_back({-5,-4,-3,1});

    if (!s.exam(result3, case3_target, case3_numbers)) {
       std::cout << "Failed test case 3!\n";
    }

    int case4_target = 11;
    std::vector<int> case4_numbers({0,1,5,0,1,5,5,-4});
    std::vector<std::vector<int>> result4;
    result4.push_back({-4,5,5,5});
    result4.push_back({0,1,5,5});

    if (!s.exam(result4, case4_target, case4_numbers)) {
       std::cout << "Failed test case 4!\n";
    }


    return 0;
}
