/**
 * JZ40. 最小的 K 个数
 * Source: https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=23263&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "src/utils/print.h"

using namespace std;

// call std::sort()
class SolutionV1 {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k == 0) {
            return {};
        }
        std::sort(input.begin(), input.end());
        std::vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
};

// heap sort
class SolutionV2 {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k == 0) {
            return {};
        }
        n = input.size();
        input.insert(input.begin(), -1);

        // build min heap
        for (int i = n / 2; i >= 1; i--) {
            sink(input, i);
        }
        std::vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(input[1]);
            std::swap(input[1], input[n--]);
            sink(input, 1);
        }
        return res;
    }

private:
    int n;

    void sink(std::vector<int> &input, int i) {
        while (2 * i <= n) {
            int j = 2 * i;
            if (j + 1 <= n && input[j] > input[j + 1]) {
                j++;
            }
            if (input[i] <= input[j]) {
                break;
            }
            std::swap(input[i], input[j]);
            i = j;
        }
    }
};

int main() {
    SolutionV2 s;
    print_vector(s.GetLeastNumbers_Solution({4, 5, 1, 6, 2, 7, 3, 8}, 4));
    return 0;
}
