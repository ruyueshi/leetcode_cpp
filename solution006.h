#ifndef SOLUTION006_H
#define SOLUTION006_H

#include <iostream>
#include <string>

class solution006
{
public:
    std::string convert(std::string s, int numRows) {
        if (numRows < 2) {
            return s;
        }

        int length = s.length();
        int period = 2 * numRows - 2;
        std::string result;

        for (int row = 0; row < numRows; row++) {
            for (int j = row; j < length; j += period) {
                result.push_back(s[j]);
                if (row > 0 && row < numRows - 1) {
                    int another = j + ((period - j % period) - j % period);
                    if (another < length) {
                        result.push_back(s[another]);
                    }
                }
            }
        }
        return std::string(result);
    }
};

void test_solution006() {
    solution006 s;
    std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << s.convert("PAYPALISHIRING", 4) << std::endl;
}

#endif // SOLUTION006_H
