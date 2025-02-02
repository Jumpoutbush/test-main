#include<iostream>
#include<stdio.h>

using namespace std;

class A{
public:
	void func() { cout << "A " << endl; }
};
class Adm1 : public A{
public:
    void func() { cout << "Adm1 " << endl; }
};
class Adm2 : public A{
public:
    void func() { cout << "Adm2 " << endl; }
};

class B{
public:
	void func() { cout << " B " << endl; }
};
class Tec1 : public B{
public:
	void func() { cout << "Tec1 " << endl; }
};
class Tec2 : public B{
public:
	void func() { cout << "Tec2 " << endl; }
};

template<class T, class X = void, int N = 0>	
class Singleton	{
public:
	static T* GetInstance(){
		static T v;
		static int x;
		x++;
		printf("x = %d\tX: %p\n", x, &x);
		return &v;
	}
};

int main(int argc,char** argv){
	A* A_Adm1 = Singleton<A, Adm1, 1>::GetInstance();
	A_Adm1->func();
	A* A_Adm2 = Singleton<A, Adm2, 2>::GetInstance();
	A_Adm2->func();
	B* B_Tec1 = Singleton<B, Tec1, 3>::GetInstance();
	B_Tec1->func();
    B* B_Tec2 = Singleton<B, Tec2, 4>::GetInstance();
	B_Tec2->func();
	printf("%p\n%p\n%p\n%p\n", A_Adm1, A_Adm2, B_Tec1, B_Tec2);
	return 0;
}
