/**
 * 912. Sort an Array
 * Source: https://leetcode-cn.com/problems/sort-an-array/
 */

#include <algorithm>
#include <random>
#include <vector>

#include "src/utils/print.h"

// 归并排序
class SolutionV1 {
public:
    std::vector<int> sortArray(std::vector<int> &&nums) {
        temp.resize(nums.size());
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    std::vector<int> temp;

    void merge_sort(std::vector<int> &nums, int low, int high) {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(std::vector<int> &nums, int low, int mid, int high) {
        for (int i = low; i <= high; i++) {
            temp[i] = nums[i];
        }

        int i = low, j = mid + 1;
        for (int p = low; p <= high; p++) {
            if (i == mid + 1) {
                nums[p] = temp[j++];
            } else if (j == high + 1) {
                nums[p] = temp[i++];
            } else if (temp[i] <= temp[j]) {
                nums[p] = temp[i++];
            } else {
                nums[p] = temp[j++];
            }
        }
    }
};

// 快速排序
// 三种排序中，快排最快
class SolutionV2 {
public:
    std::vector<int> sortArray(std::vector<int> &nums) {
        std::shuffle(nums.begin(), nums.end(), std::default_random_engine(0));
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quick_sort(std::vector<int> &nums, int low, int high) {
        if (low >= high)
            return;
        int p = partition(nums, low, high);
        quick_sort(nums, low, p - 1);
        quick_sort(nums, p + 1, high);
    }

    int partition(std::vector<int> &nums, int low, int high) {
        int key = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= key)
                high--;
            if (low < high)
                nums[low++] = nums[high];  // low++可以减少一次循环
            while (low < high && nums[low] <= key)
                low++;
            if (low < high)
                nums[high--] = nums[low];
        }
        nums[low] = key;
        return low;
    }
};

// 堆排序
class SolutionV3 {
public:
    std::vector<int> sortArray(std::vector<int> &nums) {
        N = nums.size();
        nums.insert(nums.begin(), 0);
        // V1
        // for (int k = 1; k <= N; k++)
        //     swim(nums, k);
        // V2
        for (int k = N/2; k >= 1; k--) {
            sink(nums, k);
        }
        while (N > 1) {
            std::swap(nums[1], nums[N--]);
            sink(nums, 1);
        }
        nums.erase(nums.begin());
        return nums;
    }

private:
    int N;

    void swim(std::vector<int> &heap, int k) {
        while (k > 1 && heap[k] > heap[k / 2]) {
            std::swap(heap[k], heap[k / 2]);
            k /= 2;
        }
    }

    void sink(std::vector<int> &heap, int k) {
        while (2 * k <= N) {
            int j = 2 * k;
            if (j + 1 <= N && heap[j] < heap[j + 1])
                j++;
            if (heap[k] >= heap[j])
                break;
            std::swap(heap[k], heap[j]);
            k = j;  // 注意此处容易出错，不能直接k=2*k
        }
    }
};

int main() {
    SolutionV3 s;
    std::vector<int> nums = {5, 2, 3, 1};
    auto res = s.sortArray(nums);
    print_vector(res);
    nums = {-74, 48, -20, 2, 10, -84, -5, -9, 11, -24, -91, 2, -71, 64, 63, 80, 28, -30, -58, -11, -44, -87, -22, 54, -74, -10, -55, -28, -46, 29, 10, 50, -72, 34, 26, 25, 8, 51, 13, 30, 35, -8, 50,
            65, -6, 16, -2, 21, -78, 35, -13, 14, 23, -3, 26, -90, 86, 25, -56, 91, -13, 92, -25, 37, 57, -20, -69, 98, 95, 45, 47, 29, 86, -28, 73, -44, -46, 65, -84, -96, -24, -12, 72, -68, 93, 57,
            92, 52, -45, -2, 85, -63, 56, 55, 12, -85, 77, -39};
    res = s.sortArray(nums);
    print_vector(res);
    return 0;
}
