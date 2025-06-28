#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

// 构建图
void buildGraph(int n, vector<vector<string>>& lines, unordered_map<string, vector<string>>& graph, unordered_map<string, vector<int>>& lineMap) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < lines[i].size(); ++j) {
            string station = lines[i][j];
            lineMap[station].push_back(i);
            if (j > 0) {
                graph[lines[i][j - 1]].push_back(station);
                graph[station].push_back(lines[i][j - 1]);
            }
        }
    }
}

// BFS搜索并记录路径
bool bfs(const string& start, const string& end, unordered_map<string, vector<string>>& graph, unordered_map<string, vector<int>>& lineMap, unordered_map<string, string>& prev, int& cost) {
    unordered_set<string> visited;
    queue<string> q;
    q.push(start);
    visited.insert(start);
    cost = 2;  // 初始费用为单条线路票价2元
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            string cur = q.front();
            q.pop();
            if (cur == end) {
                return true;
            }
            for (string neighbor : graph[cur]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    prev[neighbor] = cur;
                    // 判断是否需要换乘加价
                    vector<int> curLines = lineMap[cur];
                    vector<int> neighborLines = lineMap[neighbor];
                    bool isTransfer = true;
                    for (int l : curLines) {
                        for (int nl : neighborLines) {
                            if (l == nl) {
                                isTransfer = false;
                                break;
                            }
                        }
                        if (!isTransfer) break;
                    }
                    if (isTransfer) {
                        cost += 1;
                    }
                    q.push(neighbor);
                }
            }
        }
    }
    return false;
}

// 回溯路径
vector<string> getPath(const string& start, const string& end, unordered_map<string, string>& prev) {
    vector<string> path;
    string at = end;
    while (at != start) {
        path.push_back(at);
        at = prev[at];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> lines(n);
    for (int i = 0; i < n; ++i) {
        string lineStr;
        getline(cin >> ws, lineStr);
        stringstream ss(lineStr);
        string station;
        while (ss >> station) {
            lines[i].push_back(station);
        }
    }
    string start, end;
    cin >> start >> end;

    unordered_map<string, vector<string>> graph;
    unordered_map<string, vector<int>> lineMap;
    buildGraph(n, lines, graph, lineMap);

    unordered_map<string, string> prev;
    int cost;
    if (bfs(start, end, graph, lineMap, prev, cost)) {
        vector<string> path = getPath(start, end, prev);
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << "-";
            }
        }
        cout << endl;
        cout << cost << endl;
    } else {
        cout << "NA" << endl;
    }
    system("pause");
    return 0;
}