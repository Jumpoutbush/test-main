#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_set<int> s(a.begin(), a.end());
    int result = s.size() > 0 ? s.size() - 1 : 0;
    cout << result << endl;
    system("pause");
    return 0;
}