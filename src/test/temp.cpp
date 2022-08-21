#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == elem) {
                sum++;
            } else {
                A[i-sum] = A[i];
            }
        }
        return n - sum;
    }
};

int main() {
    Solution s;
    int A[] = {1,5,2,7,3,4,2,1,2};
    std::cout << s.removeElement(A, 9, 2) << std::endl;
    return 0;
}