// 有几个直角三角形
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查三条边是否能构成直角三角形
bool isRightTriangle(int a, int b, int c) {
    return a * a + b * b == c * c;
}

// 深度优先搜索函数
int dfs(vector<int> edge) {
    int maxTriangles = 0;
    int n = edge.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int a = edge[i], b = edge[j], c = edge[k];
                if(isRightTriangle(a, b, c)){
                    vector<int> newedge;
                    for(int l = 0; l < n; l++){
                        if(l != i && l != j && l != k){
                            newedge.push_back(edge[l]);
                        }
                    }
                    maxTriangles = max(maxTriangles, 1 + dfs(newedge));
                }
            }
        }
    }
    return maxTriangles;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        vector<int> edge(n);
        for (int j = 0; j < n; ++j) {
            cin >> edge[j];
        }
        // 对边进行排序
        sort(edge.begin(), edge.end());
        // 调用深度优先搜索函数计算最大直角三角形数量
        int result = dfs(edge);
        cout << result << endl;
    }
    system("pause");
    return 0;
}    