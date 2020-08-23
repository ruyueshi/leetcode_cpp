/**
 * 5497. 查找大小为 M 的最新分组
 * Source: https://leetcode-cn.com/contest/weekly-contest-203/problems/find-latest-group-of-size-m/
 */

#ifndef SOLUTION5497_H
#define SOLUTION5497_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class solution5497 {
public:
    int findLatestStep(std::vector<int>& arr, int m) {
        int ans = -1;
        int length = arr.size();
        std::string bin(length, '0');
        std::map<int, int> record;
        for (int i = 0; i < length; i++) {
            bin[arr[i]-1] = '1';
            if (this->judge(bin, record, arr[i]-1, m)) {
                ans = i + 1;
            }
        }
        return ans;
    }
private:
    bool judge(const std::string &bin, std::map<int, int> &record, int insert, int m) {
        int left = insert - 1;
        size_t right = insert + 1;
        if (left >= 0 && bin[left] == '1') {
            int left_begin = this->find_key(record, left);
            if (right < bin.length() && bin[right] == '1') {
                record[left_begin] = record[right];
                record.erase(record.find(right));
            } else {
                record[left_begin] = insert;
            }
        } else if (right < bin.length() && bin[right] == '1') { //union
            record.insert({insert, record[right]});
            record.erase(record.find(right));
        } else { // add new
            record.insert({insert, insert});
        }

        auto it = std::find_if(record.begin(), record.end(), [m](const std::map<int, int>::value_type item){return (item.second - item.first + 1) == m;});
        return it != record.end();
    }

    int find_key(const std::map<int, int> &record, int value) {
        auto it = std::find_if(record.begin(), record.end(), [value](const std::map<int, int>::value_type item){return item.second == value;});
        return it != record.end() ? it->first : -1;
    }

    int findLeftBegin(const std::string &bin, int insert) {
        for (int i = insert; i >= 0; i--) {
            if (bin[i] == '0') {
                return (i + 1);
            }
        }
        return 0;
    }
};

void test_solution5497() {
    solution5497 s;
    std::vector<int> arr2 = {3,5,1,2,4};
    std::cout << s.findLatestStep(arr2, 1) << std::endl;
}

#endif // SOLUTION5497_H
