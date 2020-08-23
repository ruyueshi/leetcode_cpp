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
    // time out
    int findLatestStep1(std::vector<int>& arr, int m) {
        int ans = -1;
        int length = arr.size();
        std::string bin(length, '0');
        std::map<int, int> record;  // key means begin index of substring "11111", value means end index of substring "11111"
        for (int i = 0; i < length; i++) {
            bin[arr[i]-1] = '1';
            if (this->judge(bin, record, arr[i]-1, m)) {
                ans = i + 1;
            }
        }
        return ans;
    }

    int findLatestStep2(std::vector<int>& arr, int m) {
        int ans = -1;
        int length = arr.size();
        std::string bin(length, '0');
//        int link[length];
//        int record[length + 1]; // key means the length of substring "11111", value means the occurrence number of substring "11111" in string 'bin'
//        std::memset(record, 0, sizeof (record));
        std::vector<int> link(length);
        std::vector<int> record(length + 1, 0);
        for (int i = 0; i < length; i++) {
            int index = arr[i] - 1;
            int left = index - 1;
            size_t right = index + 1;
            bin[index] = '1';

            if (left >= 0 && bin[left] == '1') {
                if (right < bin.length() && bin[right] == '1') {
                    int old_len1 = left - link[left] + 1;
                    int old_len2 = link[right] - right + 1;
                    record[old_len1]--;
                    record[old_len2]--;
                    record[old_len1 + old_len2 + 1]++;
                    link[link[left]] = link[right];
                    link[link[right]] = link[left];
                } else {
                    int old_len = left - link[left] + 1;
                    record[old_len]--;
                    record[old_len + 1]++;
                    link[index] = link[left];
                    link[link[left]] = index;
                }
            } else if (right < bin.length() && bin[right] == '1') {
                int old_len = link[right] - right + 1;
                record[old_len]--;
                record[old_len + 1]++;
                link[index] = link[right];
                link[link[right]] = index;
            } else {
                record[1]++;
                link[index] = index;
            }

            if (record[m] > 0) {
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
};

void test_solution5497() {
    solution5497 s;
    std::vector<int> arr = {8,16,10,4,7,5,1,11,14,12,13,6,3,2,9,17,15,19,18};
    std::cout << s.findLatestStep1(arr, 7) << std::endl;
}

#endif // SOLUTION5497_H
