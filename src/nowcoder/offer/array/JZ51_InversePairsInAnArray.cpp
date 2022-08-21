/**
 * JZ51. 数组中的逆序对
 * Source: https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=23260&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
class SolutionV1 {
public:
    int InversePairs(vector<int> data) {
        int n = data.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (data[i] > data[j]) {
                    sum = (sum + 1) % 1000000007;
                }
            }
        }
        return sum;
    }
};

// O(nlogn)
// merge sort
class SolutionV2 {
public:
    int InversePairs(vector<int> data) {
        int n = data.size();
        sum = 0;
        temp.resize(n);
        merge_sort(data, 0, n - 1);
        return sum;
    }

private:
    int sum;
    std::vector<int> temp;

    void merge_sort(std::vector<int> &data, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        merge_sort(data, low, mid);
        merge_sort(data, mid + 1, high);
        merge(data, low, mid, high);
    }

    void merge(std::vector<int> &data, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            temp[i] = data[i];
        }
        int i = low, j = mid + 1;
        for (int p = low; p <= high; p++) {
            if (i == mid + 1) {
                data[p] = temp[j++];
            } else if (j == high + 1) {
                data[p] = temp[i++];
            } else if (temp[i] <= temp[j]) {
                data[p] = temp[i++];
            } else {
                sum = (sum + mid + 1 - i) % 1000000007;
                data[p] = temp[j++];
            }
        }
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.InversePairs({1, 2, 3, 4, 5, 6, 7, 0}) << std::endl;
    return 0;
}

