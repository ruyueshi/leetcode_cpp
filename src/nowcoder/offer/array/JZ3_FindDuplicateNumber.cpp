#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(const std::vector<int>& numbers) {
        // write code here
        int n = numbers.size();
        for (const auto &i: numbers) {
            if (i < 0 || i >= n) {
                return -1;
            } else if (count[i] > 0) {
                return i;
            } else {
                count[i]++;
            }
        }
        return -1;
    }

private:
    int count[10000] = {0};
};

int main() {
    Solution s;
    std::cout << s.duplicate({2,3,1,0,2,5,3}) << std::endl;
    return 0;
}
