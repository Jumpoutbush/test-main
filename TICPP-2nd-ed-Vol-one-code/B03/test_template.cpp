#include <bits/stdc++.h>
using namespace std;
//泛化版本
template<typename T, typename U>
void Func(const T& a, const U& b){
	cout << "Func()泛化版本" << endl;
	cout << a << " " << b << endl;
}
//全特化版本
template<>
void Func(const int& a, const double& b){
	cout << "Func()int,double 全特化版本" << endl;
	cout << a << " " << b << endl;
}
//偏特化版本（不支持！！！）

int main(){
	const char* p = "I Love China";
	int a = 12;
	Func(p, a);
	//全特化函数模板实际上等价于实例化一个函数模板，并不是等级一个函数重载
	Func(15, 25.3);	//特化版本
	return 0;
}
