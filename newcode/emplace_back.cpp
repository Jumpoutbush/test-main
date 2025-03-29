#include <bits/stdc++.h>
using namespace std;

struct Person{
    string name;
    int age;
    //初始构造函数
    Person(string p_name, int p_age): name(std::move(p_name)), age(p_age){
        cout << "I have been constructed" <<endl;
    }
    //拷贝构造函数
    Person(const Person& other): name(std::move(other.name)), age(other.age){
        cout << "I have been copy constructed" <<endl;
    }
    //转移构造函数
    Person(Person&& other) : name(std::move(other.name)), age(other.age){
        cout << "I have been moved"<<endl;
    }
};

int main()
{
    {
        vector<Person> people;
        cout << "emplace" << endl;
        people.emplace_back("jane", 20);
        cout << "pushback" << endl;
        people.push_back(Person("jyyc", 20));
        cout << "deconstruct" << endl;
    }
    system("pause");
    return 0;
}

