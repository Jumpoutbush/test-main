#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <string>

/**
 * 计算经过必过点的最短路径长度
 * 
 * @param graph 表示图的字符串
 * @param mustPass 表示必过点的字符串
 * @return 最短路径长度
 */
int calculateMinDistance(const std::string& graph, const std::string& mustPass) {
    // 边界情况检查
    if (graph.empty() || mustPass.empty()) {
        return 0;  // 如果图或必过点为空，则无需移动
    }
    
    if (mustPass.length() == 1) {
        return 0;  // 如果只有一个必过点，则无需移动
    }
    
    // 记录每个字符在图中的所有出现位置
    std::unordered_map<char, std::vector<int>> charPositions;
    for (int i = 0; i < graph.length(); i++) {
        char c = graph[i];
        charPositions[c].push_back(i);
    }
    
    // 检查所有必过点是否在图中
    for (char c : mustPass) {
        if (charPositions.find(c) == charPositions.end()) {
            return -1;  // 必过点不在图中，无法通过
        }
    }
    
    // 计算最短路径
    int totalDistance = 0;
    for (int i = 0; i < mustPass.length() - 1; i++) {
        char current = mustPass[i];
        char next = mustPass[i + 1];
        
        // 计算从当前字符到下一个字符的最短距离
        int minDistanceBetween = INT_MAX;
        for (int pos1 : charPositions[current]) {
            for (int pos2 : charPositions[next]) {
                int distance = std::abs(pos2 - pos1);
                minDistanceBetween = std::min(minDistanceBetween, distance);
            }
        }
        
        totalDistance += minDistanceBetween;
    }
    
    return totalDistance;
}

int main() {
    // 读取输入
    std::string graph, mustPass;
    std::getline(std::cin, graph);
    std::getline(std::cin, mustPass);
    
    // 计算最短路径长度
    int minDistance = calculateMinDistance(graph, mustPass);
    std::cout << minDistance << std::endl;
    system("pause");
    return 0;
}
