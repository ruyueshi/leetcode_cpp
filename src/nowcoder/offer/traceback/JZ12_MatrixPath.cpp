/**
 * JZ12. 矩阵中的路径
 * Source: https://www.nowcoder.com/practice/2a49359695a544b8939c77358d29b7e6?tpId=13&tqId=1517966&ru=/exam/oj/ta&qru=/ta/coding-interviews/question-ranking&sourceUrl=%2Fexam%2Foj%2Fta%3Fpage%3D1%26tpId%3D13%26type%3D13
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix char字符型vector<vector<>>
     * @param word string字符串
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> > &matrix, string word) {
        // write code here
        n = matrix.size();
        if (n == 0) {
            return false;
        }
        m = matrix[0].size();
        if (m == 0) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(matrix, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int n, m;

    bool dfs(std::vector<std::vector<char>> &matrix, const std::string &word, int i, int j, int pos) {
        if (i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] != word[pos]) {
            return false;
        }
        if (pos == word.size() - 1) {
            return true;
        }
        matrix[i][j] = '\0';
        bool res = dfs(matrix, word, i - 1, j, pos + 1) || dfs(matrix, word, i, j + 1, pos + 1) ||
                   dfs(matrix, word, i + 1, j, pos + 1) || dfs(matrix, word, i, j - 1, pos + 1);
        matrix[i][j] = word[pos];
        return res;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> matrix = {{'a', 'b', 'c', 'e'},
                                             {'s', 'f', 'c', 's'},
                                             {'a', 'd', 'e', 'e'}};
    std::cout << s.hasPath(matrix, "abcced") << std::endl;
    matrix = {{'A'}};
    std::cout << s.hasPath(matrix, "A") << std::endl;
    return 0;
}
