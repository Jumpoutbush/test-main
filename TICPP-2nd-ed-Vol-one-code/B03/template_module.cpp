// B03:template class
//1.泛化的Test类模板
#include <bits/stdc++.h>
using namespace std;
template<class T, class U>
class Test	{
	Test(){cout << "泛化版本的构造函数" << endl;}
	void Func(){cout << "泛化版本" << endl;}
};


//2.全特化的Test类模板
//当T和U这两个类型模板参数都为int类型时，做一个特化版本
//全特化：就是所有类型模板参数(这里T 和 U),都用具体类型代表
template<>	//全特化：所有类型模板参数都用具体类型代表，所以这里的template后面的<>里就为空
class Test<int,int>	//上边的T绑定到这里的第一个int,上边的U绑定到这里的第二个int
{
	Test(){cout << "int , int的特化版本构造函数" << endl;}
	//可以该特化版本进行单独处理
	void Func(){cout << "int , int的特化版本" << endl;}
};

template<>	//全特化：所有类型模板参数都用具体类型代表，所以这里的template后面的<>里就为空
class Test<double, int>	//上边的T绑定到这里的第一个int,上边的U绑定到这里的第二个int
{
	Test(){cout << "double , int的特化版本构造函数" << endl;}
	//可以该特化版本进行单独处理
	void Func(){cout << "double , int的特化版本" << endl;}
};


//3.偏特化的类模板
//从参数数量上进行偏特化，现在绑定两个类型模板参数
template<typename U>	//留一个U类型模板参数
class Test<int, U, double>{
	void Func() { cout << "偏特化int ,U, double版本" << endl; }
};
