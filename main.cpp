#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

int DP(std::vector<std::vector<int>> &NumTriangle) {

    auto best = NumTriangle;
    best[0][0] = NumTriangle[0][0];
    for (int i = 1; i < NumTriangle.size(); ++i) {
        best[i][0] = NumTriangle[i][0] + best[i - 1][0];
        best[i][i] = NumTriangle[i][i] + best[i - 1][i - 1];
    }

    for (int i = 1; i < NumTriangle.size(); ++i) {//注意这里的边界
        for (int j = 1; j < i; ++j) {
            best[i][j] = std::max(best[i - 1][j - 1], best[i - 1][j]) + NumTriangle[i][j];//通项公式
        }
    }
    int max_sum = 0;
    auto best_line = best[best.size() - 1];
    for (int i = 0; i < best.size(); ++i) {
        if (max_sum < best_line[i]) {
            max_sum = best_line[i];
        }
    }
    return max_sum;

}

int main() {

    std::string line;
    std::getline(std::cin, line);
    int count;
    std::istringstream iss(line);
    iss >> count;
    std::vector<std::vector<int>> NumTriangle;

    for (int i = 0; i < count; ++i) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<int> tmp_line;
        int tmp_num;
        while (iss >> tmp_num) {
            tmp_line.push_back(tmp_num);
        }
        NumTriangle.push_back(tmp_line);
    }
//
//    for (auto i = NumTriangle.begin(); i != NumTriangle.end(); ++i) {
//        for (auto j = i->begin(); j != i->end(); ++j) {
//            std::cout << *j << " ";
//        }
//        std::cout << std::endl;
//    }

    std::cout << DP(NumTriangle) << std::endl;

    return 0;
}