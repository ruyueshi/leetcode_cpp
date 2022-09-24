/**
 * JZ53 数字在升序数组中出现的次数
 * Source: https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=23274&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>

class SolutionV1 {
public:
    int GetNumberOfK(std::vector<int> data, int k) {
        int n = data.size();
        int left = 0, right = n;
        while (left < right) {
            int media = left + (right - left) / 2;
            if (k == data[media]) {
                int i = media, j = media;
                while (i >= 0 && data[i] == k) {
                    i--;
                }
                while (j < n && data[j] == k) {
                    j++;
                }
                return (j - i - 1);
            } else if (k < data[media]) {
                right = media;
            } else {
                left = media + 1;
            }
        }
        return 0;
    }
};

class SolutionV2 {
public:
    int GetNumberOfK(std::vector<int> data, int k) {
        n = data.size();
        if (n == 0) {
            return 0;
        }
        int left_index = left_bound(data, k);
        int right_index = right_bound(data, k);
        return left_index == -1 ? 0 : (right_index - left_index + 1);
    }

private:
    int n;

    int left_bound(const std::vector<int> &data, int k) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (k < data[mid]) {
                right = mid - 1;
            } else if (k > data[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left == n || data[left] != k)
            return -1;
        return left;
    }

    int right_bound(const std::vector<int> &data, int k) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (k < data[mid]) {
                right = mid - 1;
            } else if (k > data[mid]) {
                left = mid + 1;
            } else {
                left = mid + 1;
            }
        }
        if (right == -1 || data[right] != k)
            return -1;
        return right;
    }
};

int main() {
    SolutionV2 s;
    std::cout << s.GetNumberOfK({1, 2, 3, 3, 3, 3, 4, 5}, 3) << std::endl;
    return 0;
}

