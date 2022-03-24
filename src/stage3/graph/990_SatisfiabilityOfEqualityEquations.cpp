/**
 * 990. Satisfiability of Equality Equations
 * Source: https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
 */

#include <iostream>
#include <string>
#include <vector>

#include "src/utils/graph.h"

class Solution {
public:
    bool equationsPossible(std::vector<std::string> &equations) {
        UF uf(26);
        for (auto &e: equations) {
            if (e[1] == '=') {
                uf.uf_union(e[0] - 'a', e[3] - 'a');
            }
        }

        for (auto &e: equations) {
            if (e[1] == '!') {
                if (uf.uf_connect(e[0] - 'a', e[3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::vector<std::string> equations = {"c==c", "b==d", "x!=z"};
    std::cout << s.equationsPossible(equations) << std::endl;
    return 0;
}
