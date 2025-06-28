// A < B < ... < Z < a < b < ... < z
#include <bits/stdc++.h>
using namespace std;

bool z(int k){
    return !k;
}
int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(z(k)) break;
        while(s[i] != 'A'){
            if(isupper(s[i])){
                s[i] = 'A';
                k--;
                if(z(k)){
                    break;
                }
            }else if(islower(s[i])){
                s[i] = toupper(s[i]);
                k--;
                if(z(k)){
                    break;
                }
            }
        }
    }
    cout << s << endl;
    system("pause");
    return 0;
}