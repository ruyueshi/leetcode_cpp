/*
链接：https://www.nowcoder.com/questionTerminal/5afcf93c419a4aa793e9b325d01957e2?answerType=1&f=discussion
来源：牛客网

 小明是一名算法工程师，同时也是一名铲屎官。某天，他突发奇想，想从猫咪的视频里挖掘一些猫咪的运动信息。为了提取运动信息，他需要从视频的每一帧提取“猫咪特征”。一个猫咪特征是一个两维的vector<x, y>。如果x_1=x_2 and y_1=y_2，那么这俩是同一个特征。
       因此，如果喵咪特征连续一致，可以认为喵咪在运动。也就是说，如果特征<a, b>在持续帧里出现，那么它将构成特征运动。比如，特征<a, b>在第2/3/4/7/8帧出现，那么该特征将形成两个特征运动2-3-4 和7-8。
现在，给定每一帧的特征，特征的数量可能不一样。小明期望能找到最长的特征运动。

输入描述:
第一行包含一个正整数N，代表测试用例的个数。

每个测试用例的第一行包含一个正整数M，代表视频的帧数。

接下来的M行，每行代表一帧。其中，第一个数字是该帧的特征个数，接下来的数字是在特征的取值；比如样例输入第三行里，2代表该帧有两个猫咪特征，<1，1>和<2，2>
所有用例的输入特征总数和<100000

N满足1≤N≤100000，M满足1≤M≤10000，一帧的特征个数满足 ≤ 10000。
特征取值均为非负整数。


输出描述:
对每一个测试用例，输出特征运动的长度作为一行
示例1
输入
1
8
2 1 1 2 2
2 1 1 1 4
2 1 1 2 2
2 2 2 1 4
0
0
1 1 1
1 1 1
输出
3
说明
特征<1,1>在连续的帧中连续出现3次，相比其他特征连续出现的次数大，所以输出3

备注:
如没有长度大于2的特征运动，返回1
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int _ = 0; _ < n; _++) {
        int max_len = 1;
        std::map<std::pair<int, int>, int> frame;
        for (int id = 0; id < m; id++) {
            int feature_num;
            std::cin >> feature_num;
            if (feature_num == 0)
                frame.clear();
            else {
                std::set<std::pair<int, int>> current_feature;
                for (int i = 0; i < feature_num; i++) {
                    std::pair<int, int> feature;
                    std::cin >> feature.first >> feature.second;
                    current_feature.insert(feature);
                    frame[feature]++;
                    if (frame[feature] > max_len)
                        max_len = frame[feature];
                }
                for (auto it = frame.begin(); it != frame.end();) {
                    if (current_feature.find(it->first) == current_feature.end())
                        it = frame.erase(it);
                    else
                        it++;
                }
            }
        }
        std::cout << max_len << std::endl;
    }
    return 0;
}
