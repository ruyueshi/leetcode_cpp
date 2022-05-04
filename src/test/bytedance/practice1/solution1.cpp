/*
链接：https://www.nowcoder.com/test/question/42852fd7045c442192fa89404ab42e92?pid=16516564&tid=56064847
来源：牛客网
我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：

1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

我特喵是个天才！我在蓝翔学过挖掘机和程序设计，按照这个原理写了一个自动校对器，工作效率从此起飞。用不了多久，我就会出任CEO，当上董事长，迎娶白富美，走上人生巅峰，想想都有点小激动呢！
……
万万没想到，我被开除了，临走时老板对我说： “做人做事要兢兢业业、勤勤恳恳、本本分分，人要是行，干一行行一行。一行行行行行；要是不行，干一行不行一行，一行不行行行不行。” 我现在整个人红红火火恍恍惚惚的……

请听题：请实现大锤的自动校对程序

数据范围：  ，每个用例的字符串长度满足

输入描述:
第一行包括一个数字N，表示本次用例包括多少个待校验的字符串。

后面跟随N行，每行为一个待校验的字符串。

输出描述:
N行，每行包括一个被修复后的字符串。

输入例子1:
2
helloo
wooooooow

输出例子1:
hello
woow

输入例子2:
1
nowcoder

输出例子2:
nowcoder
 */

#include <iostream>

std::string &fix_text(std::string &text) {
    int left = 0, right = 0;
    while (right < text.size() - 1) {
        if (right == left) {  // "A"
            if (text[right + 1] == text[right])
                right++;
            else
                right++, left++;
        } else if (right == left + 1) {  // "AA"
            if (text[right + 1] == text[right])
                text.erase(right + 1, 1);
            else
                right++;
        } else if (right == left + 2) {  // "AAB"
            if (text[right + 1] == text[right])
                text.erase(right + 1, 1);
            else
                right++, left += 3;
        }
    }
    return text;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string text;
        std::cin >> text;
        std::cout << fix_text(text) << std::endl;
    }
    return 0;
}
