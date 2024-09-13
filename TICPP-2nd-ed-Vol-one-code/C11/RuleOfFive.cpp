#include<iostream>
#include<vector>
class RuleOfFive{
public:
    RuleOfFive(const RuleOfFive &rhs) : m_value(new int(*(rhs.m_value))){}
    //RuleOfFive(RuleOfFive&& rhs);
    RuleOfFive &operator=(const RuleOfFive &rhs){
        *m_value = *rhs.m_value;
        return *this;
    }
    RuleOfFive& operator=(RuleOfFive&& rhs){
        delete m_value;
        m_value = rhs.m_value;
        rhs.m_value = nullptr;
        return *this;
    }
    ~RuleOfFive(){delete m_value;}
    RuleOfFive() : m_value(new int(10)){}
    void print() const {std::cout << *m_value << std::endl;}
private:
    int *m_value;
};
int print(const int& a)
{
    std::cout << a << std::endl;
}
// RuleOfFive::RuleOfFive(RuleOfFive&& rhs){//move的实际作用
//     m_value = rhs.m_value;
//     rhs.m_value= nullptr;//b的值实际上变成了nullptr
// }
int main()
{
    int abc = 10;
    const int& abc2 = abc;
    print(abc2);//1,传入没有const的int&也可以
    print(abc);//取abc const引用
    print(10);//生成了a=10的临时变量,const表示这个值不会变,	编译器给它生成临时变量

    std::vector<int> a;
    for(int i = 0; i < 10; i++) a.push_back(i);
    RuleOfFive b;
    auto& c = b;
    RuleOfFive e = b;
    RuleOfFive d = std::move(b);
    e = std::move(d);
    //b.print();
    system("pause");
}