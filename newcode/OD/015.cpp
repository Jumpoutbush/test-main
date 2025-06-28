#include <bits/stdc++.h>
using namespace std;

int calculateMinCars(int length){
    int cars = 0;
    cars += length / 3;
    length %= 3;
    cars += length / 2;
    length %= 2;
    cars += length;
    return cars;
}

int minParkingCars(const vector<int>& cars){
    int minCars = 0;
    int n = cars.size();
    int i = 0;
    while(i < n){
        if(cars[i] == 1){
            int length = 0;
            while(i < n && cars[i] == 1){
                length++;
                i++;
            }
            minCars += calculateMinCars(length);
        }else{
            i++;
        }
    }
    return minCars;
}
int main()
{
    string input;
    getline(cin, input);

    vector<int> cars;
    stringstream ss(input);
    string token;
    while(getline(ss, token, ',')){
        cars.push_back(stoi(token));
    }
    int result = minParkingCars(cars);
    cout << result << endl;
    system("pause");
    return 0;
}