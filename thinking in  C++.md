84713b96-461b-4ac0-9e0f-0d7033883cd1

```c++
#ifndef x                 //先测试x是否被宏定义过
#define x
   程序段1   //如果x没有被宏定义过，定义x，并编译程序段 1
#endif   
　　程序段2　　 //如果x已经定义过了则编译程序段2的语句，“忽视”程序段 1
```

# C第一章 对象导言

## 1.1抽象的过程

第一个成功的面向对象语言Smalltalk的***五个***基本特性：

（1）***万物皆对象***，理论上，可以在需要解决的问题中取出任意概念性的成分，把它表示为程序中的对象

（2）***程序就是一组对象，对象之间通过发送消息互相通知做什么***。更具体地讲，可以将消息看作是对于调用某个特定对象所属函数的请求

（3）***每一个对象都有它自己的由其它对象构成的存储区***。这样就可以***通过包含已经存在的对象创造新的对象***

（4）***每个对象都有一个类型***，***每个对象都是某个类的实例***,“dog是animal的实例”

（5)***一个特定类型的所有对象都能接受相同的消息***，“circle”类型的对象也是“shape”类型的对象，保证“circle”能接收“shape”的消息

## 1.2对象有一个接口

 类型名：light

接口：on();off();brighten();dim()

light  lt;//light是对象名  

lt.on();

***接口规定我们能向特定对象发出什么请求，实现包括满足这种请求的代码和隐藏的数据***

## 1.3实现的隐藏

访问控制的理由：

1.防止客户程序员插手他们不应当接触的部分，也就是对于数据类型的内部实施方案是必需的部分

2.允许库设计者去改变这个类内部工作方式，而不必担心这样做会影响客户程序员

​		例如重写类优化代码时，如果***接口和实现***是严格分离和被保护的，库设计者可容易地完成任务，用户只需重新连接就可以了

​		public意味着随后的定义对所有人都可用，相反，private意味除了该类型的创建者和该类型的内部成员函数之外，任何人都不能访问这些定义，protected与private基本类似，不过继承的类可以访问protected成员，但不能访问private成员

## 1.4实现的重用

​		重用一个类最简单的方法就是直接使用这个类的对象，并且还可以将这个类的对象放到一个新的类里面。称之为“创建一个成员对象”。还可以用任何数量和类型的其他对象组成一个新类，通过组合得到新类所希望的功能，称之为***“聚合”***常被称为“has-a”

## 1.5继承：接口重用

​		继承的好处是选取已有的类克隆它，然后对这个克隆增加和修改，而不是克服困难地强制性创造每个类。

​		如果原来的类（称为基类、超类或父类）被修改，则这个修改过的“克隆”（成为派生类、继承类或子类）也会表现出这些改变

​		对象不简单地继承一个类，收到一个特定消息后必定执行一些代码，伴随着接口必然有一些实现。***通过重载函数可改变已经存在的基类函数的行为***，可直接在派生类中创建新定义。

### 1.5.1 is-a关系和is-like-a关系

​		继承应当只覆盖基类吗？这就意味着派生类与基类是完全相同的类型，因为它们有相同的接口。结果是，我们可以用派生类的对象替代基类的对象，这被认为是***纯替代*** ，常常被称为***代替原则*** ，“圆形是一个形体”看作“is-a”（是）关系

​		有时需要向一个派生类添加新的接口元素，这样就扩展了接口并创建了新类型。新类型仍可以替代这个基类，但这些新函数不能从基类访问。这可以描述为“is-like-a"关系。新类型有老类型的接口，但还包含其他函数，所以不能说完全相同。

空调：cool（）；

​														<----派生----温度控制系统：cool（）<----派生----温度计：lowerTemperature（）

热泵：cool（）；heat（）；

热泵 is like a 空调

## 1.6具有多态性的可互换对象

​		如果试图把派生类型的对象看作是它们所属的基本类型（圆形看作形体，自行车看作车辆，鸬鹚看作鸟），这里就有一个问题：如果一个函数告诉一个一般的形体去绘制它自己，或者告诉一个一般的车辆去行驶，或者告诉一只一般的鸟去飞翔，则编译器在编译时就不能确切地知道应当执行哪段代码。

​																																	Goose:move()

​		BirdController:relocate()    ----派生---->Bird:move()    ----派生---->

​																																	Penguin:move()

​		BirdController对象只是与一般的bird对象交互，并不知道他们到底是什么类型。这对于BirdController是方便的，因为不需要编写专门的代码来确定它正在对哪种Bird工作以及它有什么样的行为。但当忽略专门的Bird类型而调用move（）时，Goose和Penguin会出现正确的行为吗？

​		***早捆绑***：编译器会对特定的函数名产生调用，而连接器将这个调用解析为要执行代码的绝对地址，直到程序运行时，编译器才会确定执行代码的地址

​		***晚捆绑***：给对象发送消息时，在程序运行阶段才去确定被调用的代码，编译器保证这个被调用的函数存在，并执行参数和返回值的类型检查（不采用这种方法的称为弱类型语言），但它并不知道将执行的确切代码。

​		为了执行晚捆绑，C++编译器在真正调用的地方插入一段特殊的代码。通过使用存放在对象自身中的信息，这段代码***在运行时计算被调用的函数函数体的地址***。这样，每个对象就能够根据这段二进制代码的内容有不同的行为，当一个对象接受消息时，它根据这个消息判断该干什么。

​		用***virtual*** 关键字声明希望某个函数有晚捆绑的灵活性，因为默认情况下成员函数不能进行动态捆绑，virtual（虚）函数可用来表示在相同家族中的类具有的不同行为，这些不同是多态产生的原因。

​		void doStuff(Shape& ***s***):取这个***对象*** 的地址，传给doStuff（）

​		如果在程序的其他部分使用doStuff（）：

Circle c;

Triangle t;

Line l;

doStuff(c);

doStuff(t);

doStuff(l);

​		doStuff的调用会自动正确地工作，而不管调用对象的确切类型

​		doStuff（c）中将***Circle传递给对Shape有效的函数，因为Circle是一个Shape，所以可以由doStuff（）处理，***这就是说任何能由doStuff（）发送给Shape的消息，Circle都能接收。

​		我们把处理派生类型就如同处理其基类型的过程称为向上类型转换 

​		doStuff（）{s.erase();s.draw();}是指：它是一种shape，我知道它能erase（）和draw（）自己，如法操作，注意细节的正确性，而非：如果是Circle，做这件事，如果是Square，做这件事，等等。所有特殊形状的动作由该图形重载。

## 1.7创建和销毁对象

​		栈是内存中一个区域，可以直接由微处理器在程序执行期间存放数据。在栈中的变量有时称为***自动变量或局部变量*** 。

​		第二种方法是在称为堆的区域动态创建对象。用这种方法，可以直到运行时还不知道需要多少个对象，它们的生命周期和它们的准确的数据类型是什么。这些决定是在程序运行之中做出的。如果需要新的对象，直接使用new关键字让它在堆上生成。当使用结束时，用关键字delete释放。

## 1.8异常处理

## 1.9分析设计

## 1.10极限编程

### 1.10.1先写测试

### 1.10.2结对编程

# 第二章  对象的创建与使用

## 2.1语言翻译过程

### 2.1.3编译过程

​		编编译一般分两遍进行。首先，对预处理过的代码进行语法分析，编译器把源代码分解成小的单元并把它们按树形结构组织起来。“A+B”中的A，+，B就是语法分析树中的叶子节点。

​		有时编译的第一遍和第二遍至今啊使用全局优化器来生成更短、更快的代码。

​		编译的第二遍，由代码生成器遍历语法分析树，把树的每个节点转化为汇编语言或机器代码，如果是汇编语言还需要汇编成.o文件

​		连接器把一组目标模块连接成为一个可执行程序，操作系统可以装载和运行它，当某个目标模块中共的函数要引用另一目标模块中的函数或变量时，由连接器来处理这些引用

## 2.2分段编译工具

### 2.2.1声明及定义

​		可以在不同的地方声明相同的变量和函数，但只能有一个定义

​		声明是向编译器介绍名字--标识符，告诉编译器，这个函数或变量在某处可以找到，它的模样像什么；定义是说：“在这里建立变量”，“在这里建立函数”，为名字分配存储空间。

#### 2.2.1.1函数声明的语法

```c++
int func1(int ,int);
a=func1(2,3）；
int func1(int length,int width);
```

#### 2.2.1.2带空参数表的函数

C语言中声明

```C++
int func2();
```

表示“一个可带任意参数（任意数目，任意类型）的函数”，妨碍了类型检查，而在C++中它意味着“不带参数的函数”

#### 2.2.1.3函数的定义

```c++
int func1(int length,int width){}
```

#### 2.2.1.4变量声明的语法

​		***extern关键字***  ：

```c++
extern int a;
extern int func1(int length,int width);
```

表示声明一个变量但不定义它

## 2.3第一个C++程序

### 2.3.2名字空间

​		程序达到一定规模时，会遇到“用完了”函数名和标识符，***namespace关键字***，库或程序中的每一个C++定义集被封装在一个名字空间中，如果其他的定义中有相同的名字，但它们在不同的名字空间，就不会产生冲突。

```C++ 
using namespace std;
```

​		这意味着打开“std”名字空间，使它所有的名字都可用，就不用担心特殊的库组件是在同一名字空间中，因为在使用using指令地方，它的名字空间在整个文件中都是可用的。

​		现代头文件的包含命令已经标准化了，过去典型包含头文件的方式是带上“.h”，那时，名字空间不是语言的一部分，所以，对已经存在的代码要提供向后兼容，不带“.h”的头文件必须要和using指令合用。

### 2.3.4”hello world!“

转义字符：\n换行；\t跳格；\\反斜杠；\b空格

//:       content    ///:~

## 2.4关于输入输出流

```c++
cout<<dec<<15<<endl;

cout<<oct<<15<<endl;

cout<<hex<<15<<endl;

cout<<char(65)<<endl;
```

### 2.4.1字符数组拼接功能

如果两个加引号的字符数组邻接，并且他们之间没有标点，编译器就会把这些字符数组连接成单个字符数组

### 2.4.2用cin读取

## 2.5字符串介绍

## 2.6文件的读写

​		为了打开文件进行读写操作必须包含<fstream>,虽然<fstream>会自动包含<iostream>，但如果打算使用cin、cout，最好还是显式地包含<iostream>

​		getline（）把一行读入到string对象中（以换行符结束），getline（）第一个参数是ifstream对象，第二个参数是stream对象

```c++
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in("Scopy.cpp");//open for reading
    ofstream out("Scopy2.cpp");//open for writing
    string s;
    while(getline(in,s));//Discards newline char
    	out<<s<<"\n"
}
```

```c++
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    ifstream in("FillString.cpp");
    string s,line;
    while(getline(in,line))
        s+=line+"\n";
    cout<<s;
}
```

​		string具有动态分配特性，不必担心string的内存分配，只管添加新内容进去就行了，string会自动扩展并保存新的输入

​		把整个文件都输入进一个字符串的好处是，string类有许多函数可用来对字符串进行查找和操作，使用它们可以把文件当作单个的字符串来处理，把一个文件作为许多行的集合而不是一大段文本来处理，通常是很方便的

## 2.7vector

​		vector类是一个模板，意味着可以创建任何事物的类，把类型名输入到尖括号内vector<string> v

​		为了在vector末尾后追加一个新元素，可以使用成员函数push_back()

```c++
int main(){
    vector<string> v;
	ifstream in("Fillvector.cpp");
	string line;
	while(getline(in,line))
    	v.push_back(line);
	for(int i=0;i<v.size();i++)
    	cout<<i<<":"<<v[i]<<endl;
	return 0;
}
```

同样地：***区别于换行符，以空格为输出间隙的in***

```c++
while(in>>word)
	words.push_back(word);
```

还可通过

```c++
for(int i=0;i<v.size();i++)
	v[i]=v[i]*10
```

来对v[i]中的单元赋值

# 第三章  c++中的C

## 3.1创建函数

声明的函数原型中，可以接受：

```c++
int translate(float,float,float);
```

C++中func（）类型的空参数列表代表没有参数，而C中代表不确定参数

为了实现不知道会有多少个参数，可使用***可变的参数表*** 

```c++
int translate(float,...)
```

### 3.1.3通过库管理器创建自己的库

​		如果想创建一个库，那么就建立一个头文件，它包含库中所有的函数原型，把这个头文件放在预处理器搜索路径中的谋出路，或者在当前目录中，以便能被#include“头文件”发现，或者在包含路径中，以便能被#include<头文件>发现

## 3.2执行控制语句

## 3.3运算符简介

## 3.4数据类型简介

### 3.4.2bool类型与true和false

​		bool类型由两种内建的常量true（1）和false（0）表示

### 3.4.4指针简介

```c++
#include<iostream>
using namespace std;
int dog,cat,bird,fish;
void f(int pet){
    cout<<"pet id number:"<<pet<<endl;
}
int main(){
    int i,j,k;
    cout<<"f():"<<(long)&f<<endl;
    cout<<"dog:"<<(long)&f<<endl
    cout<<"cat:"<<(long)&f<<endl;
    cout<<"bird:"<<(long)&f<<endl;
    cout<<"fish:"<<(long)&f<<endl;
    cout<<"i:"<<(long)&i<<endl;
    cout<<"j:"<<(long)&j<<endl;
    cout<<"k:"<<(long)&k<<endl;
    return 0;
}
```

​		内存中代码和数据一般分开存放。相继定义的变量在内存中是连续存放的，根据各自的数据类型所要求的字节数分隔开，或按整数字节对齐。

​		***最好每行定义一个指针***

```c++ 
int a=47;
int* ipa = &a;
```

### 3.4.5修改外部对象

```c++
#include<iostream>
using namespace std;
void f(int* p){
    cout<<"p="<<p<<endl;
    cout<<"*p="<<*p<<endl;
    *p=5;
    cout<<"p="<<p<<endl;
}
int main(){
    int x=47;
    cout<<"x="<<x<<endl;
    cout<<"&x="<<&x<<endl;
    f(&x);
    cout<<"x="<<x<<endl;
    return 0;
}
```

x=47

&x=0065Fe00 ***若不强制转换则地址为十六进制表示***

p=0065Fe00

*p=47

p=0065Fe00

x=5

p中的值就是变量x的地址，指针p的确是指向变量x

### 3.4.6C++引用简介

​		C和C++中指针的作用基本一致，但是C++中增加了另外一种给函数传递地址的途径。这就是按引用传递

```c++
void f(int& r){
    cout<<"r="<<r<<endl;
    cout<<"&r="<< &r<<endl;
    r=5;
    cout<<"r="<<r<<endl;
}
int main(){
    int x=47;
    cout<<"x="<<x<<endl;
    cout<<"&x="<<&x<<endl;
    f(x);
    cout<<"x="<<x<<endl;
}
```
x=47;&x=0065FE00;r=47;&r=0065FE00;r=5;x=5;r是x的引用，r中存放的值即为x的值

​		在函数f()的参数列表中，不用int*来传递指针，而是用int&来传递引用，**如果仅仅写r会得到r引用的变量值**，如果对r赋值，其实是对r引用的变量赋值，得到r中存放地址值的唯一方法是用‘&’

### 3.4.7用指针和引用作为修饰符

​		当传递对象进出函数时，指针和引用也能工作；这里有和指针一起工作的另一种类型：void，如果声明指针是void*，它意味着任何类型的地址都可以间接引用那个指针，而如果声明int *，则只能对int型变量的地址间接引用那个指针

```c++
int main(){
    void* vp;
    char c;
    int i;
    float f;
    double d;
    //任何类型的地址都可以间接引用void*
    vp=&c;
    vp=&i;
    vp=&f;
    vp=&d;
}
```

​		一旦间接引用一个void*，就会丢失关于类型的信息，这意味着在使用前，必须转换为正确的类型

```c++
int main(){
	int i=99;
    void* vp= &i;
    *((int*)vp)=3;
}
```

## 3.5作用域

### 3.5.1实时定义变量

C++允许在作用域的任何地方定义变量，所以可以在正好使用它之前定义，在定义时对它初始化以防止犯某种类型的错误

## 3.6指定存储空间分配

### 3.6.1全局变量

​		如果在一个文件中使用***extern关键字***来声明另一个文件中存在的全局变量，那么这个文件可以是使用这个数据

```c++
//:C03:Global.cpp
int globe;
void func();
int main(){
    globe = 12;
    cout<<globe<<endl;
    func();
    cout<<globe<<endl;
}///:~

//:C03:Global2.cpp{0} {0}代表不要从这个文件生成exe编译它是为了把它连接进一些其他的可执行文件中
extern int globe;
void func(){
    globe = 47;
}
```



### 3.6.2 局部变量

​		局部变量出现在一个作用域内，局限于一个函数，被称为***“自动******变量 ”*** ，在进入作用域时自动生成，离开作用域时自动消失，默认为auto

```c++
auto name = "yyc";//等价于
const char* name2 = "yyc";//auto = const char*
```

```c++
std::vector<int> group;
for(auto v : group){//1 std::vector<int> iterator it = group.begin(); it!= group.end(); it++{}
    v = v * v;//对group无影响,会拷贝一次，效率损失
}
for(auto& v : group){
    v = v * v;//对group有影响，会误操作group
}
for(const auto& v : group){
     v = v * v;//不会误操作group
}
```



### 3.6.3 静态变量

​		通常，函数中定义的局部变量在函数作用域结束时消失，再次调用这个函数时，会重新创建该变量的存储空间，其值会被重新初始化。如果想使局部变量的值在程序的整个生命周期里仍然存在，***可以定义函数的局部变量为static，并给它一个初值*** ，初始化只在函数第一次调用时执行，函数调用之间变量的值保持不变。***区别全局变量，static变量在函数范围之外是不可用的*** 

```c++
void func(){
    static int i = 0;
    cout<< "i=" << ++i << endl;
}
int main(){
    for(int x = 0; x < 10 ; x++)
        func();
}
```

​		***如果不使用static打印出的值总是  ‘1’*** 

```c++
#include <iostream>
using namespace std;
int i = 0;
int fun(int n) {
    static int a = 2;
    a++;
    return (a * n);
}

int main() {
    int k = 5;
    {
        int i = 2;
        k += fun(i);
    }
    k += fun(i);
    cout << k;
    return (0);
}
//11

```

***{ }组成一个作用域，在main的{}外，fun(i)调用的是全局的  i***	 

​	static的第二层意思和前面含义相关，即“在某个作用域外不可访问” 。当应用static函数名和所有函数外部的变量时，它的意思是“在文件的外部不可以使用这个名字” ，函数名或局部变量是局部于文件的；我们说它具有 “文件作用域”。

```c++
//:C03:FileStatic.cpp
static int fs;
int main(){
    fs = 1;
}///:~

//:C03:FileStatic2.cpp
//Trying to reference fs
extern int fs;
void func(){
    fs = 100;
}///:~
编译会引起连接错误，虽然fs是全局变量，但在函数外部不起作用，在文件作用于外当然也不起作用
```

### 3.6.4 外部变量

```c++
//:C03:Forward.cpp
#include <iostream>
using namespace std;
extern int i;
extern void func();
int main(){
    i = 0;
    func();
}
int i;
void func(){
    i++;
    cout << i;
}///:~
```

​		当编译器遇到extern int i 时，知道i作为全局变量存在于某处。当编译器遇到变量i的定义时，并没有看到别的声明，所以知道它在文件的前面已经找到了同样声明的i。如果已经把变量i定义为static，又要告诉编译器，i是全局定义的（通过extern），但是它也有文件作用域（通过static），所以编译器会产生错误

#### 3.6.4.1 连接

​		内部连接：只对正被编译的文件创建存储空间，别的文件可以使用相同的标识符或全局变量，连接器不会发现冲突--也就是为每一个标识符创建单独的存储空间。***C++中内部连接是由关键字static指定的*** 

​		外部连接：为所有被编译过的文件创建一片单独的存储空间，连接器必须解决所有对这片存储空间的引用。全局变量和函数名有外部连接。***通过关键字extern声明，可以从其他文件访问这些变量和函数***。函数之外定义的所有变量（在C++中除了const）和函数定义默认为外部连接。可以使用关键字static特地强制它们具有内部连接，也可以在定义时使用关键字extern显式指定标识符具有外部连接，在C中不必用extern定义函数或变量，但是C++中有时必须使用const

### 3.6.5常量

标准前：预处理器

​		#define PI = 3.14159 -- 不进行类型检查，不能得到PI的地址（所以不能向PI传递一个指针和一个引用），PI不能是用户定义的变量类型。PI的意义是从定义它的地方持续到文件结束的地方；预处理器并不识别作用域

​		修饰符const告诉编译器这个名字表示常量，不管是内部的还是用户定义的数据类型都可以定义为const，如若定义了某对象为const，然后试图修改它，编译器将会产生错误

​		const int x = 10;

​		可以在参数列表中使用命名常量，即使列表中的参数是指针或引用（可以获得const地址）。const就像正常变量一样有作用域，所以可以在函数中隐藏一个const，确保名字不会影响程序的其余部分

3.6.5.1 常量值

​		在C++中，一个const必须有初值（在C中不是这样）。如果不特殊指定为八进制、十六进制、浮点数或字符，默认为十进制。

​		***常量值前带零被认为是八进制数*** ，017被认为是合法的八进制数=15(10)

​		***常量值前带0x被认为是十六进制数*** ，0x1fe是一个合法的十六进制数=510(10)

​		***浮点数可以含有小数点和指数幂（用e表示，意思是“10的幂”）***

### 3.6.6 volatile变量

​		***限定词const告诉编译器“这是不会改变的”；限定词volatile“不知道何时会改变”***

## 3.7 运算符及其使用

### 3.7.5位运算符

​		位运算符允许在一个数中处理个别的位（因为浮点数使用一种特殊的内部格式，所以位运算符只适用于整型 char、int、long）。位运算符对参数中的相应位做布尔代数运算来产生结果。

​		如果两个输入位都是1，则“与”运算符&在结果位上产生1，否则为0 。如果两个输入位有一个是1，则“或”运算符（|）在结果位上产生1，只有当两个输入位都是0时，结果位才是0 。如果两个输入位之一是1而不是同时为1，则位的异或运算符x or ^ 的结果位为1 。位的“非”运算符（~，也称为补运算符）是一个一元运算符，它只带有一个参数。

​		位运算符可以和“=”结合来统一运算和赋值：&=、|=、^=都是合法运算，~是一元运算符，不能与=连用

## 3.8创建复合类型

### 3.8.1用typedef命名别名

```c
typedef unsigned long ulong;
typedef      原类型     别名 ;
int* x, y;//生成一个int*x和一个int*y(不是一个int*)，*只绑定右边不绑定左边
typedef int* IntPtr;
IntPtr x,y;//则x和y都是int*类型
```

### 3.8.2用struct把变量结合在一起

```c++
typedef struct SelfReferential{
    int i;
    SelfReferential* sr;
}SelfReferential;
int main(){
    SelfReferential sr1,sr2;
    sr1.sr = &sr2;
    sr2.sr = &sr1;
    sr1.i = 47;
    sr2.i = 1024;
}
```

sr1和sr2互相指向并且每个都拥有一块数据，实际上，struct的名字不必和typedef的名字一样

#### 3.8.2.1指针和struct

```c++
typedef struct Structure3{
    char c;
    int i;
    float f;
    double d;
}Structure3;
int main(){
	Structure3 s1,s2;
	Structure3* sp = &s1;
	sp->c = 'a';
    sp->i = 1;
    sp->f = 3.14;
    sp->d = 0.00093;
    sp = &s2;
    sp->c = 'a';
    sp->i = 1;
    sp->f = 3.14;
    sp->d = 0.00093;
}
```

***类是struct更有潜力的继任者***

### 3.8.3用enum提高程序清晰度

​		枚举数据类型是把名字和数字相联系的一种方式

```c++
enum ShapeType{
    circle,
    square,
    rectangle
};
int main(){
    ShapeType shape = circle;
    switch(shape){
        case circle: break;
        case square: break;
        case rectangle: break;
    }
}
```

​		shape是被列举的ShapeType的变量，可以把它的值和列举的值比较，因为shape实际上只是int，所以它可以具有任何一个int拥有的值（包括负数）

```c++
enum ShapeType{
    circle = 10,
    square = 20,
    rectangle = 50,
    pop		//对不赋给值，编译器会使用相邻的下一个整数值，比如赋给51
};
```

### 3.8.4用union节省内存

​		union把所有数据放进一个单独的空间***，计算出放在union中的最大项*** 所必需的空间数

​		每当在union中放置一个值，总是放在union开始的同一个地方，但是只使用必需的空间。因此，我们创建的是一个能容纳任何一个union变量的“超变量”，***所有的union变量的地址都是相同的（struct或类中地址是不同的）***

```c++
#include<bits/stdc++.h>
using namespace std;
union Packed{
    char i;
    short j;
    int k;
    long l;
    float f;
    double d;
};
int main(){
    cout<<"sizeof(Packed) = "
        <<sizeof(Packed) <<endl;
    system("pause");
    return 0;
}
:// sizeof(Packed) = 8,因此只占用8个字节，union可以节省空间
```

#### 3.8.5.1指针和数组

```c++
int a[10];
cout<<a<<" "<<&a[0];
//这两个地址都是数组a的起始地址
//可以把数组标识符看作是数组起始处的只读指针
//尽管不能改变数组标识符指向，但是可以另创建指针，使它在数组中移动
int* ip =a;
for(int i=0;i<10;i++){
    ip[i] = i*10;
}
```

函数参数的声明中，如果以一个数组作为参数，那么(int a[])和(int* a)是一样的参数表

## 3.10函数地址

### 3.10.1定义函数指针

void (*funcPtr)();

从变量名开始(funcPtr)，右-左-右-左声明

右括号拦住-*代表指针-无参数列表-返回void

funcPtr是一个指针，指向一个不带参数并返回void的函数

如果*funcPtr不带括号，void *funcPtr()声明一个函数而不是一个指针变量

### 3.10.2复杂的声明和定义

### 3.10.3使用函数指针

```c++
#include<iostream>
using namespace std;
void func(){
    cout<<"func() called..."<<endl;
}
int main(){
    void (*fp)();
    fp = func;
    (*fp)();
    void (*fp2)() = func;
    (*fp2)();
    cout<<&fp<<endl<<&fp2;
    system("pause");
    return 0;
}
```

在定义了指向函数的指针fp后，用fp=func使fp获得函数func()的地址，func2（）同时定义和初始化

### 3.10.4指向函数的指针数组

# 第四章  数据抽象

# 第五章  隐藏实现

## 5.2C++的访问控制

​	public, private, protected：

public意味在其后面声明的所有成员可以被所有的人访问，

private关键字意味除了该类型的创建者和类的内部成员函数之外，任何人比如全局函数main、别的对象成员，都不能访问（编译错误）

​		使用public的方法调用

protected与private基本相似，但***继承的结构可以访问protected成员***，但不能访问private成员

## 5.3友元

​		想允许显式地不属于当前结构的一个成员函数访问当前结构中的数据，声明这个函数为friend。一个friend必须在一个结构内声明，必须从类的内部声明一个函数为友元，而不是从外部定义一个新的类A，然后说：我是B的友元。

​		可以把一个全局函数声明为friend，也可以把另一个结构中的成员函数甚至整个结构都声明为friend

```c++
//: C05:Friend.cpp
//Friend allows special access
#include<bits/stdc++.h>
using namespace std;
struct X;
struct Y{
    void f(X*);
};
struct X{
    private:
    	int i;
    public:
    	void initialize();
    	friend void g(X*, int);
    	friend void Y::f(X*);
    	friend struct Z;
    	friend void h();
};
void X::initialize(){
    i=0;
}
void g(X* x, int i){
    x->i = 47;
}
struct Z{
    private:
        int j;
    public:
        void initialize();
        void g(X* x);
};
void Z::initialize(){
    j=99;
}
void Z::g(X* x){
    x->i += j;
}
void h(){
    X x;
    x.i = 100;
}
int main(){
    X x;
    Z z;
    z.g(&x);
    system("pause");
    return 0;
}
```

​		

```c++
//global friend

```

struct  Y有一个成员函数f()，它将修改X类型的对象。

​		***因为C++的编译器要求在引用任一变量前必须先声明，***

```c++
friend void Y::f(X*);//这一步
```

***所以struct Y必须在它的成员Y::f(X*)被声明为struct X的一个友元之前声明，但要声明Y::f(X *)，又必须先声明struct X。***

```c++
struct Y{
    void f(X*);
};//这一步
```

​		**解决的办法：Y::f(X ***)引用了一个X对象的地址，编译器允许程序员在声明Y::f(X *)之前做一个X的不完全的类型说明，这一点用struct X时完成，该声明仅仅告诉编译器，有一个叫X的struct，所以当它被引用时，只要不涉及名字外的信息，就不会产生错误

​		如果传递的是X的整个对象，编译器必须知道X的全部定义用来确定它的大小与如何传递，但Y定义时X并未进行定义，所以只传递一个地址，编译器是知道这个地址的固定大小的。

​		这样，在

```c++
struct X
```

的正式定义中，就可以成功地声明Y::f(X*)为一个friend函数，如果程序员在编译器获得Y的全部说明信息之前声明它，就会产生一条错误。

​		第一个声明将一个全局函数g()作为一个友元函数，但g()在这之前并没有在全局范围内做过声明，这表明friend可以在声明函数的同时又将它作为struct的友元，这种扩展声明对整个结果同样有效：

​		friend struct Z；

是Z的一个不完全的类型说明，并把整个结构都当做一个friend

### 5.3.1嵌套友元

​		嵌套的结构并不能自动获得访问private成员的权限。要获得私有成员的权限，必须：

1、首先声明（而不定义）一个嵌套的结构，然后声明它是全局范围使用的一个friend，最后定义这个结构

2、结构的定义必须与friend声明分开

```c++
struct Holder{
private:
    int a[sz];
public:
    struct Pointer;
    friend struct Pointer;
    struct Pointer{
    private:
        Holder* h;
        int* p;
    public:
        void initialize(Holder* h);
    }
}
```

Pointer中*p 访问Holder中数组，Pointer的不同对象来选择数组的不同部分

## 5.6句柄类

```c++
class Handle{
    struct Cheshire;
    Cheshire* smile;
}
```

Cheshire是一个结构名，但没有定义，对一个指向struct的指针来说足够了，但在提供结构的主体部分之前不能创建一个对象。

***Cheshire是一个嵌套结构，必须用作用域定义***

修改task.json的arg参数${file}为 ${fileDirname}/*.cpp或特定cpp文件来实现分模块设计

# 第六章  初始化与清理

## 6.1构造函数

## 6.2析构函数

​		析构函数调用的唯一证据是包含该对象的右括号，当对象超出它的作用域时，编译器会自动调用析构函数（花括号也可定义作用域）

```c++
{
   Tree t(12);
}//这个右括号的作用域结束时，析构函数被调用
```

​	系统/编译器默认析构函数：

​			默认地调用类成员的析构函数，同时如果是派生类，自动调用派生类析构函数。

​	However，成员本身的析构函数是什么都不做，并没有释放空间。

## 6.5重写Stack

## 6.6聚合初始化

```c++
struct Y{
    float f;
    int i;
    Y(int a);
};
Y y1[] = {Y(1),Y(2),Y(3)};

class Z{
    //private:
    int i,j;
    public:
    Z(int ii,int jj);
    void print();
};
Z::Z(int ii,int jj){
    i = ii;
    j = jj;
}
void Z::print(){
    cout<<"i="<<i<<",j="<<j<<endl;
}
int main(){
    Z zz[] = {Z(1,2), Z(3,4), Z(5,6), Z(7,8)};
    for(int i=0;i<sizeof(zz)/sizeof(*zz);i++)
        zz[i].print();
}
```

## 6.7默认构造函数

​		即不带任何参数的构造函数，用来创建一个原型对象

# 第七章  函数重载与默认参数

## 7.1名字修饰

void f();

class X{void f();};

class内的函数f()不会与全局的f()发生冲突，编译器用不同的内部名f()和X::f()来区分两个函数

对

```c++
void print(char);
void print(float);
会产生_print_char和_print_float这样的内部名
```



### 7.1.1 返回值重载

​		为什么只能通过范围和参数来重载，不能通过返回值？

```c++
void f();
int f();
```

​		当编译器能从上下文中唯一确定的函数意思时，如int x = f()，***在C中，总是可以调用一个函数而忽略它的返回值，即调用了函数的副作用*** ，但我怎么知道调用哪个f？，所以c++禁止这样做

### 7.1.2 类型安全连接

​		编译器按函数被调用的方式推断函数的声明，而一个函数未经声明就调用了，这种错误难以发现。

一般地：

​		所有函数在被使用前需要声明      ||       包含一个合适的头文件

当错误的声明被调用时：

```c++
f(int){};
f(char);
f(1);
```

编译器修饰名字，变为诸如：f_int，

使用的函数是f_char，当连接器试图找到f_char，却只能找到f_int。就会报告一条出错信息，这就是类型安全连接。

## 7.2重载的例子

// Stach3.h 

## 7.3联合

​		union的空间为结构中占空间最大数，用union可以节省空间

​		struct默认public，class默认private。struct和union也可以带有构造和析构函数

​		union与class唯一的不同之处在于存储数据的方式，int类型和float类型会咋同一内存覆盖区存放，但是union不能在继承时作为基类使用

## 7.4默认参数

```c++
Stash(int size, int initQuantity =  0);
```

### 7.4.1占位符参数

​		函数定义时不一定需要标识符

```c++
void f(int x, int, float flt);
```

x和flt可以引用，但中间这个参数不行。目的在于以后可以修改函数定义而不需要修改所有的函数调用？

## 7.5 选择重载还是默认参数

*扩充内存手法

```c++
byte[size];
byte* newmem = new byte[minSize];
memset(newmem + size, 0, minSize - size);
memcpy(newmem, mem, size);
delete []mem;
mem = new mem;
size = minSize;
```

```c++
MyString::MyString() {  buf = 0; }

MyString::MyString(char* str) {
  buf = new Mem(strlen(str) + 1);
  strcpy((char*)buf->pointer(), str);
}
MyString s("My test string");
MyString s2;
/*
如果删掉默认构造函数，另一个改为MyString(char* str = "")的默认参数
s2本不应该创建Mem对象，却总会创建一个Mem，需要判定str的大小是否为0，MyString的开销才开始增长
应改为：
*/
MyString::MyString(char* str) {
    if(!*str){
        buf = 0;
        return;
    }
  buf = new Mem(strlen(str) + 1);
  strcpy((char*)buf->pointer(), str);
}
```



# 第八章   常量

## 8.1值代替

```c++
#define BUFSIZE 100
```

只在预处理期间存在，目的是为使用它的所有编译单元提供一个值，没有类型信息

### 8.1.1头文件里的const

​		要使用const而非#define，必须把const定义放进头文件里。***C++中const默认为内部连接，也就是说const仅在const被定义过的文件里才是可见的*** 。

​		定义const必须赋值，除非extern const int bufsize。

​		C++编译器并不为const创建存储控件，它把这个定义保存在***符号表***里，如果用***extern强制进行存储空间分配***

​		常量折叠就是将常量表达式计算求值，并用求得的值来替换表达式，放入常量表。可以算作一种编译优化。（**预编译阶段**）

### 8.1.2 const的安全性

### 8.1.3聚合

​	编译器不会把聚合保存到它的符号表中（对比const），所以必须分配内存。const意味着：不能改变的一片存储空间。***不能在编译期间使用它的值，因为编译器在编译期间不需要知道存储的内容***。编译器会给出错误提示是因为它

不能在数组定义里找到一个常数表达式。

```c++
struct S { int i, j; };
const S s[] = { { 1, 2 }, { 3, 4 } };
//double d[s[1].j]; // Illegal
```

## 8.2指针

​		使指针成为 const，仍避免存储分配并进行常量折叠

​		const修饰指针正指向的对象，或者const修饰在指针里存储的地址。

### 8.2.1指向const的指针

​		定义指针技巧：标识符开始处读并从里向外，const修饰最靠近它的那个。

```c++
const int* u;
```

​		***u是一个指针，指向一个const int，不需要初始化，因为u可以指向任何标识符，也就是说它不是一个const，但它所指的值是不能改变的。***

​		int const* v

​		v是一个普通指针，它指向const int，两个定义是一样的，应该用第一种。

### 8.2.2const指针

必须把const标明的部分放在*的右边，如：

```c++
int d = 1;
int* const w = &d;//w是一个指针，是指向int的const指针
```

因为指针本身是const指针，编译器需要赋初值，在指针生命周期内不变。但可以改变它所指的值，比如*w = 2.



把一个const指针指向一个const对象

```c++
//两种合法形式
int d = 1;
const int* const x = &d;
int const* const x2 = &d;
```

现在指针和对象都不能改变

### 8.2.3赋值和类型检查

​		可以把非const对象的地址赋给const指针，不能把const对象的地址赋给非const指针，可能通过被赋值的指针改变这个对象的值 ，可以通过强制类型转换把const转为非const但是不好，打破了const属性与const安全性

### 8.3.1传递const参数

```c++
void f1(const int i){
    i++;//ILLegal，编译异常，可以做参数不能改变值 
} 
```

函数体中不能对const参数修改

初始值变量不会被f1改变，由于参数是按值传递的，因此立即产生原变量的副本

为不使混淆，函数内部使用const限定参数优于参数表里用const限定参数，引用像一个被自动间接引用的常量指针

```c++
void f2(int ic){
	const int& i = ic;
	i++;//非法,编译时异常
}
```

### 8.3.2返回const值

```c++
int f3(){return 1;}
const int  = f3();
//正常工作
const int f4(){return 1;}
int k = f4();
//同样正常工作
```

​	 

****什么是左值右值？

****所以区别在于能否取地址

```c++
void LeftOrRight(){
    int a = 0;//a有名字、类型，是左值，0没有名字是右值
    int b;//b没有值，左值
    int c = 2 + 3;//c左值同a，2+3=5没有名字同0，右值
    int d = a + c;//d左值，a+c右值
    //右值不能取地址&，左值可以
    auto address = &a;
    //不能adress2 = &(2+3)
}
```

&& and std::move()

一个右值相当于一个临时变量，不能取引用，但可以取const引用

```c++
int print(const int& a){//可以传入左值右值const引用如1
    cout << a << endl;
}
int main()
{
    int abc = 10;
    const int& abc2 = abc;
    print(abc2);//1,传入没有const的int&也可以
    print(abc);//取abc const引用
    print(10);//生成了a=10的临时变量,const表示这个值不会变,	编译器给它生成临时变量
}
```

```c++
RuleOfFive b;
RuleOfFive d = std::move(b);//std::move()把左值换为右值
```

​	∵按值返回一个内建类型时，const没有意义的原因是：它总是一个值而不是一个变量，编译器不让它成为一个左值。因为它总是一个值而不是一个变量

```c++
void f7(X& x){
	x.modify();
}
X f5(){
	return X();
}
f7(f5());//cannot bind non-const lvalue reference of type 'X&' to an rvalue of type 'X'
```

​		f7()把它的参数作为一个非const引用，这与取一个非const指针一样，不能编译是因为会产生一个临时量：

#### 8.3.2.1临时量

​		临时量自动设为const，f7(f5)时产生临时对象保存f5()的返回值，使能传递给f7（），如果f7（）的参数是按值传递的，它是可以工作的，但是f7（）是按引用传递的，意味着取临时对象X的地址。//  因为f7（）的参数不是按const引用传递的，所以允许对临时对象X进行修改。但编译器知道，一旦表达式计算结束，临时对象也不复存在，因此对临时对象X的所有修改都将丢失，由于临时对象设为const，这种情况是错误的。

```c++
f5() = X(1); // OK -- non-const return value
f5().modify(); // OK
```

​		尽管可以编译通过，f5（）返回一个X对象，要满足表达式，必须创建临时变量来保存返回值。这两个表达式中临时对象被修改，表达式被编译通过后，临时对象也将被清除。丢失了所有修改。从而代码可能出现问题，但编译没有问题。

### 8.3.3传递和返回地址

​		如果传递或返回一个地址（一个指针或一个引用）使用const防止客户程序员取地址并修改其初值。

​		为了用const指针参数使用一个函数，应传一个const地址给一个函数

const int* 才能复制 const int* 修饰

int i = const int* 可行，简单的赋值

8.3.3.1标准参数传递

```c++
void g1(X&){}
void g2(const X&){}
int main()
{
    g1(f());//error
    g2(f());//Ok
}
```

​		把一个临时对象传递给接收const引用的函数是可能的，但不能把一个临时对象传递给接受指针的函数--对于指针，它必须明确地接受地址。一个总是const的临时变量，它的地址可以传递给一个函数，这就是为什么当临时变量按引用传递给一个函数时，函数的参数必须是const引用。

​		f（）按值返回类X的一个对象。意味着当立即取f（）的返回值并把它传递给另外一个函数时（g1（）、g2（）函数的调用），将建立一个临时变量，该临时量是const。这样，g1（）中的调用是错的，因为g1（）不接受const引用，但是函数g2（）中的调用是正确的。

## 8.4类

​		const用于类的两种方法：const的数据成员、整个对象作为const

### 8.4.1类里的const

​		构造函数初始化列表是构造函数里专门初始化的地方，***出现在构造函数的定义中***，

```c++
class Fred{
    const int size;
public:
    Fred(int sz);
}
Fred::Fred(int sz) : size(sz) {}//冒号后和花括号前的size部分
							 //提醒人们，表里的初始化发生在构造函数的任何代码执行之前
					          //这是初始化所有const的地方	
```

​		

***在类中建立一个const时，不能给它初值*** ，初始化工作需要在构造函数进行。因为const必须在建立的地方被初始化，所以在构造函数的主体里const必定已经被初始化了，否则无法防止在构造函数主体的不同地方改变const值。

#### 8.4.1.2内建类型构造函数

int，float......

```c++
float pi(3.14.59);
```

看成好像有一个构造函数，这在初始化const数据成员时尤为重要，因为必须在进入函数体前被初始化

### 8.4.2编译期间类里的常量static const修饰

​		如何让一个类有编译期间的常量成员？使用static关键字，意味：不管类的对象被创建多少次，都只有一个实例

必须在static const定义的地方进行初始化。

```c++
class StringStack{
    static const int size = 100;
}
用size决定数组stack大小，编译期常量
```

### 8.4.3const对象和成员函数

​		用const限定类成员函数

```c++
const int i = 1;
const blob b(2);
```

​		b是类型blob的一个const对象，编译器强调对象是const的，因此必须保证对象的数据成员在其生命周期内不被改变。可以轻易地保证共有数据不被改变，但它怎么知道哪些成员函数将会改变数据？又如何知道哪些成员函数对const对象来说是“安全”的呢？

​		***如果声明一个成员函数为const，等于告诉编译器该成员函数可以为一个const对象所调用，非const对象也可以。没有被明确声明为const的成员函数被看成是将要修改对象中数据成员的函数，而且编译器不允许它为一个const对象所调用*** 

​		***函数仅在类定义里是const的，不能保证成员函数按声明的方式去做，强制在定义函数时要重申const说明***  ，否则编译器把它看做一个不同的函数，const声明的函数不管以何种方式改变非const成员函数，都是错误

​		***声明一个成员函数的时候用const关键字是用来说明这个函数是 "只读(read-only)"函数，也就是说明这个函数不会修改任何数据成员(object)。 为了声明一个const成员函数， 把const关键字放在函数括号的后面。声明和定义的时候都应该放const关键字。***

​		一个const成员函数调用const和非const对象都是安全的，但并不默认成为const函数，因此不修改数据成员的任何函数都应该声明为const，这样可以和const对象一起使用。非const成员函数不能被const对象调用。

```c++
class X{
	int i;
public：
	int f() const;
	int X::f() const{return i;}
}
int main()
{
    X x1(10);
    const X x2(20);
    x1.f();
    x2.f();
}
```

## 8.5volatile

​		语法与const一样，但volatile的意思是“在编译器认识范围外，这个数据可以被改变”，不知何故，环境正在改变数据（多任务、多线程、中断处理），volatile告诉编译器不要擅自做出有关该数据的任何假定。

​		可const volatile，不能被客户程序员改变，但可以通过外部的代理程序改变

# 第九章  内联函数

## 9.2内联函数

​		任何在类中定义的函数自动地成为内联函数，但也可在非类的函数前面加上inline关键字使之成为内联函数，但为使之有效，必须使函数体和声明结合在一起，否则编译器将其作为普通函数对待

```c++
inline int plusOne(int x);//没有任何效果
inline int plusOne(int x){return ++x;}//成功
```

### 9.2.1类内部的内联函数

​		类内部定义函数默认inline（构造函数、用户自定函数）

​		使用内联函数的目的是减少函数调用的开销，内联定义放在头文件里。编译器看到这个定义时，把函数类型（名字+返回值）和函数体放到符号表里。使用函数时，编译器检查以确保调用正确、返回值正确，将函数调用换位函数体，因而消除了开销。

### 9.2.2访问函数

​		在类中内联函数的最重要的使用之一就是用做访问函数（access function）。容许读或修改对象状态--一个或几个内部变量。

```c++
class Access {
  int i;
public:
  int read() const { return i; }
  void set(int ii) { i = ii; }
};

int main() {
  Access A;
  A.set(100);
  int x = A.read();
} ///:~
```

​		不把  i  设为公有，而是用内联函数去访问它，对私有数据成员的所有访问只能通过成员函数接口。

​		如果没有内联函数，对read（）调用产生this压栈、执行call调用，产生比内联函数代码多，执行时间长。

9.2.2.1访问器和修改器

​		访问函数的概念分为访问器（accessor）和修改器（mutator），可以用重载函数为访问器和修改器提供相同函数名，调用函数的方式决定了是读还是修改信息。



# 第十章  名字控制	

## 10.1来自C语言的静态元素

在C和C++中，static都有两种基本的含义，并且这两种含义经常是相互冲突的

1）***固定地址***上进行存储分配。对象是在静态数据区创建的，而非函数调用时在堆栈上创建。

2）对一个特定的编译单位来说是局部的，static控制名字的可见性，这个名字在***此类或单元之外不可见***

### 10.1.1函数内部的静态变量

​		函数调用时，堆栈指针下移，为局部变量分配内存，如果变量有初始化表达式，每当程序运行至此，初始化就被调用。

​		***有时想在两次函数调用之间保留一个变量的值，可以定义全局变量来实现，但这样以一来，这个变量就不仅仅只受这个函数的控制。*** static对象将存储在静态存储区而非堆栈中，它只在第一次调用时初始化一次，以后它将在两次函数调用之间保持它的值。

```c++
char oneChar(const char* charArray = 0)
{
    static const char* s;//注
    if(charArray) {
    s = charArray;
    return *s;
  }
  else
    require(s, "un-initialized s");
  if(*s == '\0')
    return 0;
  return *s++;
}
char* a  = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    oneChar(a);
    char c;
    while((c = oneChar()) != 0)
    cout << c << endl;
}
```

​		//注：static const char* s 在每次oneChar（）调用时保存它的值，因为它放在程序静态存储区而不是堆栈中。

当字符指针char*做参数调用oneChar（）时，参数被赋给s，返回字符串第一个字符。以后每次调用oneChar（）都不用带参数，函数使用默认参数charArray = 0，函数就会用以前初始化的s值取字符返回 *s++。

#### 10.1.1.1 函数内部的静态对象

```c++
class X {
  int i;
public:
  X(int ii = 0) : i(ii) {} // Default
  ~X() { cout << "X::~X()" << endl; }
};

void f() {
  static X x1(47);
  static X x2; // Default constructor required
}

int main() {
  f();
} ///:~
```

​		***静态变量的规则同样适用于自定义的静态对象，必须有初始化操作。零赋值只对内建类型有效。***

​		***x2  如果一个静态对象没有指定构造函数参数，这个类就必须有默认的构造函数***

​		只有在第一次转到对象定义点时，需要执行构造函数

#### 10.1.1.2静态对象的析构函数

​		静态对象的析构函数，包括静态存储的所有对象，不仅仅是局部静态对象在程序从main（）中退出时，或者exit被调用时才被调用。由于main（）内部也是靠exit（）结束的，意味着析构函数中使用exit（）是很危险的，意味着无穷的递归调用。如果用abort（）退出程序，静态对象的析构函数不会被调用。

​		同普通对象一样，静态对象的销毁也按初始化反向进行。全局对象总是在main（）之前被创建，退出main（）时销毁。如果一个包含局部静态对象的函数从未被调用，这个对象的构造函数也不会被执行，析构也不会执行。

### 10.1.2控制连接

​		文件作用域内的所有名字对程序中所有翻译单元都是可见的，***就是所谓外部连接***。全局变量和普通函数都有外部连接。

​		文件作用域内，使用static的对象或函数的名字对翻译单元是局部于该单元的。***名字有内部连接***，意味着可以在其他的翻译单元使用同样的名字而不发生名字冲突。

#### 10.1.2.1冲突问题

```c++
int a = 0;//进入main()函数前，a已经被初始化了，对所有翻译单元可见
/* 相同定义 */ extern int a = 0; 
//static(只在翻译单元内可见)的反义词是extern，明确声明了这个名字对所有翻译单元都可见
/* 相反定义 */ static int a = 0;
//改变了a的可见性，a成了一个内连接
//但存储类型没有改变，对象总是驻留在静态区，不论是static还是extern
```



## 10.2名字空间

### 10.2.1创建一个名字空间

```c++ 
namespace MyLib{
}
```

​		namespace 与class，struct，union，enum的区别：

1）namespace只能在全局范围内定义，但他们之间可以互相嵌套

2）namespace结尾花括号不用跟分号

3）按类的语法定义namespace，定义的内容可在多个头文件延续 

```c++
//文件1
namespace MyLib{
    extern int x;
    void f();
}
//文件2
namespace MyLib{
    extern int y;
    void g();
}
```

​		***文件2的同名namespace是给MyLib加入了更多的名字而不是重定义！***

​		namespace的名字可以用另一个名字来做别名，

```c++
namespace BobsSuperDuperLibrary{
	class Widget;
    class Poppit;
}
namespace Bob = BobsSuperDuperLibrary;
```

​		作为它的别名

4）不能像类一样创建名字空间的实例

10.2.1.1未命名的名字空间

​		可以不用标识符而使用“namespace”增加一个名字空间

```c++
namespace{
	class A{};
    class B{};
    int i, j, k;
}
```

​		此空间中的名字自动地在翻译单元内无限制有效，但要确保每个翻译单元只有一个未命名的名字空间。

#### 10.2.1.2友元

```c++
namespace Me{
    class Us{
        friend void you();
    };
}
```

​		you（）就成了名字空间Me的一个成员。

### 10.2.2使用名字空间

两种方法在一个名字空间中引用一个名字：

1）作用域运算符

2）using namespace 把所有名字引入到名字空间去

#### 10.2.2.1 作用域解析

```c++
namespace X{
    class Y{
      int i;  
    };
}
int X::Y::i = 9;
```

#### 10.2.2.2using 指令

```c++
namespace Int{
    
}
namespace Math{
    using namespace Int;
}
```

​		using 指令的缺点：

包含两个含有相同定义函数的名字空间时，会产生二义性，即使永远不产生二义性 

#### 10.2.2.3使用声明

使用声明一次性引入名字到当前范围

```c++
namespace U{
    inline void f()
}
namespace V{
    inline void f()
}
void h()
{
    using namespace U;
    using V::f;
    f(); // Calls V::f() 没有使用U中f（）
    U::f();
}

```

也可以将using声明放在一个名字空间内

```c++
namespace Q{
	using U::f;
    using V::g;
}
void m()
{
    using namespace Q;
    f();//Calls U::f()
    g();//Calls V::g()
}
int main(){m();}
```

### 10.2.3名字空间的使用

std：

当使用<iostream.h>，也就是早期的c++实现；当使用<iostream>的时候，该头文件没有定义全局命名空间，必须使用namespace std；这样才能正确使用cout。

如下写法，则出错

\#include <iostream.h>

using namespace std; 

所以 要么写成
\#include <iostream>

using std::cout;

using std::cin;

## 10.3C++中静态成员

​		***有时需要为某个类的所有对象分配一个单一的存储空间，*** 在C中，可以使用全局变量，但不安全,可以被任何人修改，在大项目中容易与其他名字相冲突。

​		需要把一个数据当成全局变量存储，又被隐藏在类的内部，并清楚地与这个类相联系，

​		类所创建的所有对象，其静态数据成员共享一块存储空间，静态数据属于类，它的名字只在类的范围内有效，并且可以是public、private、protected的

### 10.3.1定义静态数据成员的存储

​		***因为类的静态数据成员有单一的存储空间而不管产生了多少个对象，存储空间必须在一个单独的地方定义，编译器不会分配存储空间，如果静态数据成员被声明但没有定义，连接器会报告一个错误*** 

​		定义必须出现在类的外部，不允许内联，而且只能定义一次。因此它通常放在一个类的实现文件中。

```c++
class A{

    static int i;
public:
};
int A::i = 1;//静态数据成员定义存储区 ，必须定义
int i = 1;//普通全局变量
```

Staticinit.cpp

#### 10.3.1.1静态数组的初始化

​		const和非const的静态类对象初始化都必须在外部进行，遵守典型的静态定义语法

​		对象数组

```c++
class Stat {
  // This doesn't work, although 
  // you might want it to:
  //!  static const X x(100);
  // Both const and non-const static class 
  // objects must be initialized externally:
  static X x2;
  static X xTable2[];
  static const X x3;
  static const X xTable3[];
};

X Stat::x2(100);

X Stat::xTable2[] = {
  X(1), X(2), X(3), X(4)
};

const X Stat::x3(100);

const X Stat::xTable3[] = {
  X(1), X(2), X(3), X(4)
};
```



### 10.3.2嵌套类和局部类 

​		把一个静态数据成员放在另一个类的嵌套类中。***然而不能在***

***		局部类中（函数内部定义的类）有静态数据成员。***

原因：

​		局部类中与静态成员直接相关的问题，为了定义数据成员，怎样才能在文件范围内定义它呢？它已然在函数作用域内才有效

​		实际上很少使用局部类（可能以此为原因）

### 10.3.3静态成员函数

​		***类的设计者是想把这些函数与整个类在概念上关联起来。***

​		***静态成员函数不能访问一般的数据成员 而只能访问静态数据成员，也只能调用其他的静态成员函数***

```c++
class X{
    static int j;
public:
    static int incr(){return ++j;}
    static int f(){return incr();}
}
int X::j = 0;
int main()
{
    X x;
    X* xp = &x;
    x.f();
    xp->f();
    X::f(); // 只能与静态成员联用
}
```

​		通常，当前对象的地址（this）是被隐式传递到被调用的函数的，***但一个静态成员函数没有this***，所以无法访问一般的成员。由此速度有所提升。

​		static关键字指定它类的对象来说，都只占用一块相同的存储空间，静态函数意味着对这个函数的所有调用而言，一个局部变量只有一份拷贝。

​		如果类的构造函数是私有的，采用static的方式定义一唯一的对象，可以访问那个对象但是不能产生任何新的对象

```c++
class Egg{
    Egg(int ii) : i(ii){}
    Egg(const Egg&); // 拷贝构造函数
public:
    static Egg* instance() {return &e;}
    int val() const {return i;}
}
Egg Egg::e(47);
int main()
{
    cout << Egg::instance()->val() << endl;
    //不能用e.instance调用，反正也是唯一的对象
}
```

​		为了完全防止创建其他对象，还需要再做以下工作：增加一个叫拷贝构造函数的私有构造函数。如果删除这个拷贝构造函数，就能创建Egg对象

```c++
Egg e = *Egg::instance();
Egg e2(*Egg::instance());
```



## 10.4静态初始化的相依性



# 第十一章 引用和拷贝构造函数

​		一种特殊的构造函数，需要用引用来实现从现有的相同类型的对象中产生新的对象。编译器使用拷贝构造函数通过按值传递的方式在函数中传递和返回对象

## 11.1C++中的指针

​		就void而言，C不允许随便地把一个类型的指针赋值给另一个类型，但允许void* 实现

```c++
void* v = bird* b
```

​		C++中不允许这样做，必须显式地使用类型转化  cast-name<type>(expression);

cast-name:static_cast、 dynamic_cast、const_cast、reinterpret_cast。

static_cast：具有任何定义的类型转换

```c++
double dPi = 3.1415926;
int num = static_cast<int>(dPi); *//num的值为3*
double d = 1.1;
void *p = &d;
double *dp = static_cast<double *>(p);
```

dynamic_cast：

const_cast：

reinterpret_cast：



## 11.2C++中引用

```c++
int x = 0;
int& a = x;
a++;//a = 1, x = 1;
```

​		任何引用必须和存储单元联系，访问引用时就是在访问那个存储单元。增加a实际上就是在增加x

使用规则：

1）引用被创建时，必须被初始化，指针可以在任何时刻被初始化

2）一旦一个引用被初始化为指向一个对象，它就不能改变为另一个对象引用（指针可以在任何时候指向另一个对象）

3）不可能有NULL引用。必须确保引用是一和块合法的存储单元关联

### 11.2.1函数中的引用

​		经常用在函数参数的返回值中。引用被用作函数参数，在函数内任何对引用的修改将对函数外的参数产生变化。

```c++
int* f(int* x){
    (*x)++;
    return x;
}
int& g(int& x){
    x++;
    return x;
}
```

​		当引用参数为非常量对象时，这个引用才能工作，如果是常量对象，g(int&  x)将不接受这个参数，因为这个函数修改外部参数时会修改const（实际不行），对内建类型，参数是常量引用的函数不会改变参数，而对于用户定义的类型，该函数只能调用常量成员函数，而且不应当改变任何公共的数据成员。

​		使用常量引用：因为函数也许会接收临时对象，临时对象是由另一个函数的返回值创立或函数使用者显式地创立的。临时对象总是不变的，因此如果不适用常量引用，参数不被编译器接收。

```c++
void f(int&){}
f(1);//Error
// "cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'",

void g(const int&){}
g(1);
```

​		f(1)调用时，编译器建立一个引用，为一个int类型分配存储单元，同时将其初始化为1并为其产生一个地址和引用捆绑在一起，分配单元的引用int&是左值，生成的地址是右值，使用const将地址改为左值。

#### 	11.2.1.2	指针引用

​		函数参数变成指针的引用，不用取指针的地址。

```c++
void increment(int*& i){i++;}
//i是一个指针，指向
```

***		指针本身的值会增加，而不是它指向的内容增加***

​		int *vlaue与int *&value作为函数形参时区别在于：
​		（1）int *value是将value指向的地址传进去，所以value指针不可为空指针，必须指向某一地址。
​		（2）int *&value则是将该指针变量传进去，相当于传入该指针的地址，所以该指针可以为空指针。

C语言中int      *a与int *    a的区别:

用法上没有区别，理解上有区别。前者表示a地址指向的类型是整形，后者表示a是个整形的指针。

## 11.3拷贝构造函数

```c++
X(X&);//X引用的X
```

### 11.3.1按值传递和返回

#### 11.3.1.1传递和返回大对象

​		当一个结构体太大（复杂的struct）以至于不能在寄存器中返回，调用函数时把参数内容压栈

#### 11.3.1.2函数调用栈框架

​		略看不懂

#### 11.3.1.3重入

​		414 

#### 11.3.1.4 位拷贝与初始化

```c++
//: C11:HowMany.cpp
HowMany f(HowMany x)
{
    x.printf("");
    return x;
}
int main()
{
    HowMany h;
    HowMany h2 = f(h);
}
```

​		 **浅拷贝：**位拷贝，拷贝构造函数，赋值重载 ，多个对象共用同一块资源，同一块资源释放多次，崩溃或者内存泄漏

​		编译器默认提供的拷贝是浅拷贝（shallow copy），将一个对象中所有成员变量的值拷贝到另一个对象，***如果某个成员变量是个指针，只会拷贝指针中存储的地址值，并不会拷贝指针指向的内存空间***，可能会导致堆空间多次 free 的问题。 

​		**深拷贝：**每个对象共同拥有自己的资源，必须显式提供拷贝构造函数和赋值运算符。

​		原来的对象h存在于函数框架之外，同时函数体内又增加了一个对象，这个对象是通过按值传递的方式传入的对象的拷贝，参数的传递是使用编译器默认的浅拷贝（位拷贝），但C++How Many类需要真正 的初始化来维护他的完整性。默认位拷贝不能达到效果。

​		f() 调用的最后，HowMany x超出了花括号的范围，其析构函数被调用，析构函数使objectCount减小。h2对象的创建是用位拷贝产生的，所以构造函数没有调用。

### 11.3.2拷贝构造函数 

```c++
//HowMany.cpp
HowMany h2 = f(h);
```

​		先前为创立的对象h2是由函数f（）的返回值创立的，所以又从一个现有的对象中创建了一个新对象。

```c++
//HowMany2.cpp
class HowMany2{
    HowMany2(const HowMany2& h) : name(h.name) {//copy-constructor，尽量传入const
    name += " copy";
    ++objectCount;
    print("HowMany2(const HowMany2&)");
  }
};
HowMany2 f(HowMany2 x){
    return x;
}
```

****类的三大基本规则，管理资源

1. 析构函数是第一个要自订的默认函数，不要抛出异常
2. 自订拷贝构造函数（如果使用了默认拷贝构造函数）
3. 拷贝的" = "要重载

### 11.3.3默认拷贝构造函数

//: C11:DefaultCopyConstructor.cpp

//: C11:HowMany.cpp(按值传递)

```c++
以下情况都会调用拷贝构造函数：
一个对象以值传递的方式传入函数体
一个对象以值传递的方式从函数返回
一个对象需要通过另外一个对象进行初始化。
```
​		拷贝构造函数实现按值传递方式的参数传递和返回，这种简单的结构情况下，编译器有效地创建一个默认拷贝构造函数，这些都是默认的原始行为：位拷贝

​		如果类中根本没有构造函数，编译器自动地创建一个默认的构造函数，不过构造函数什么也不做。然而如果加了一个拷贝构造函数，就告诉了编译器将自己处理构造函数的创建，编译器不再创建默认的构造函数。并且，除非显式地创建一个默认的构造函数，否则指示出错。

```c++
//使用默认拷贝构造函数而不是自订的后果
RuleOfThree rule("test");
RuleOfThree rule2(rule);
//如果没有自订的拷贝构造函数，而是使用默认拷贝构造函数，rule2的cstring = rule的cstring
//析构时是rule的成员cstring的析构函数被调用两次
class RuleOfThree{
  char* cstring;
public:
    ~RuleOfThree(){
        delete[] cstring; //deallocate
    }
    RuleOfThree(const char* arg)
        : cstring(new char[std::strlen(arg) + 1]) //allocate
        {
            std::strcpy(cstring, arg);
        }
    RuleOfThree(const RuleOfThree& other)//copy-constructor
    {
        cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(cstring, other.cstring);
    }
    //当不希望类被拷贝和=,使用如下两个
	//RuleOfThree(const RuleOfThree& other) = delete;//表示不需要编译器生成默认拷贝构造函数
	//use of deleted function 'RuleOfThree::RuleOfThree(const HowMany&)'
    RuleOfThree& operator=(const RuleOfThree& other)//重载=
    {
        char* tmp_cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(tmp_cstring, other.cstring);
    }
    //RuleOfThree& operator=(const RuleOfThree& other) = delete
};
```



### 11.3.4替代拷贝构造函数的方法

​		仅当准备用按值传递的方式传递类对象时，才需要拷贝构造函数。如果不那么做时，就不需要拷贝构造函数。

#### 11.3.4.1 防止按值传递

​		声明一个私有拷贝构造函数，甚至不必去定义它，除非成员函数或友元函数需要执行按值传递方式的传递。

​		如果用户试图用按值传递方式传递或返回对象，会因私有报错。

​		但是按引用传递可以

```c++
class NoCC {
  int i;
  NoCC(const NoCC&); // No definition
    //NoCC(const Nocc&) = delete;
public:
  NoCC(int ii = 0) : i(ii) {}
};

void f(NoCC& nocc)//按引用传递！
{}//NoCC做参数是不行的

int main() {
  NoCC n;
  f(n); // Error: copy-constructor called
```

​		因为已显式声明我们接管了这项工作，编译器不再创建默认的拷贝构造函数。

## 11.4指向成员的指针

​		类内部没有地址，选择一个类的成员意味着在类中偏移，只有把这个偏移和具体的对象开始地址结合才能得到实际地址，成员指针的语法要求选择一个对象的同时间接引用成员指针。

​		为了取得指针指向内容，必须用*号间接引用。但是它只是一个对象内的偏移，所以必须也要指定那个对象。*要和间接引用结合指向一个对象的指针，新的语法变为

```c++
->*;
//对于一个对象或引用，则为：
.*;
objectPointer->*pointerToMember = 47;
object.*pointerTomember = 47;
```

​		现在看看定义objectToMember的语法是什么

```c++
int ObjectClass::*pointerToMember;
```

​		定义一个名字为pointerToMember的成员指针，该指针可以指向在ObjectClass类中的任一int类型的成员。还可以在定义的时候初始化这个成员指针

```c++
int ObjectClass::*pointerToMember = &ObjectClass::a;//int型的a
```

```c++
class Data {
public:  
  int a, b, c; 
  void print() const {
    cout << "a = " << a << ", b = " << b
         << ", c = " << c << endl;
  }
};

int main() {
  Data d, *dp = &d;
  int Data::*pmInt = &Data::a;
  dp->*pmInt = 47;
  pmInt = &Data::b;
  d.*pmInt = 48;
  pmInt = &Data::c;
  dp->*pmInt = 49;
  dp->print();
} ///:~
```

### 11.4.1函数

​		指向函数的指针定义如下：

```c++
int (*fp)(float);
```

​		（*fp）的圆括号来强迫编译器正确判断定义，没有圆括号，表达式返回的是一个int *值的函数

```c++
class Simple2{
public:
    int f(float) const {return 1;}
};
int f(float) const {return 1;}
int (Simple2::*fp)(float) const;//defination
int (Simple2::*fp2)(float) const = &Simple2::f;
fp = &Simple2::f;
```

# 第12章  运算符重载

## 12.2语法

​		定义重载的运算符就像定义函数，只是该函数的名字为operator@，函数参数表中参数的个数取决于两个因素：

​		1）运算符是一元的还是二元的

​		2）运算符被定义为全局函数还是成员函数

​		在类中定义运算符重载，重载的运算符被定义为内联成员函数。

​		 对于非条件运算符（条件运算符通常返回一个布尔值），如果两个参数是相同的类型，总是希望返回相同类型的对象或引用。

## 12.3可重载的运算符

​		不能用C中当前没有意义的运算符（比如用**代表求幂），不能改变运算符优先级，不能改变运算符参数的个数。

### 12.3.1一元运算符

```c++
+，-，~，&，！，++，--;
//前++和后++区别
// Prefix:前++
friend const Integer&//友员运算符使能够访问私有成员
    operator++(Integer& a);
// Postfix:后++
  friend const Integer
    operator++(Integer& a, int);
```

​		当一元运算符被定义为成员函数时，是没有参数的，所调用的成员函数属于运算符左侧的那个对象（!A的A）。

```c++
! :代表逻辑取反，即：把非0的数值变为0，0变为1;
~ :表示按位取反，即在数值的二进制表示方式上,将0变为1，将1变为0；
```



### 12.3.2二元运算符

​		对于二元运算符，唯一的参数是出现在运算符右侧的那个操作数（A+B的B）。

```c++
// Operators that create new, modified value:
+, -, *, /, %, ^, &, |, <<, >>, 
// Assignments modify & return lvalue:
+=, -=, *=, /=, %=, ^=, &=, >>=, <<=, 
// Conditional operators return true/false:
==, !=, <, >, <=, >=, &&, ||
```

1. 返回引用和不返回引用的区别
下面两个代码是在类中的成员函数，而m_data_变量为类的私有成员变量。

```c++
int& at()//因为想返回+=之前那个数，而不是重新分配的一个内存单元为其赋值，所以用引用
{
    return m_data_;
}

int at()
{
    return m_data_;
}
```
​		上面两个函数，第一个返回值是int的引用int&，第二个返回值是int，但是二者有什么区别？
​		返回值为引用型（int& ）的时候，返回的是地址，因为这里用的是 int& a=A.at(); ，***所以a和m_data_指的是同一块地址。***
​		返回值不是引用型（int）的时候，返回的是一个数值。这个时候就很有意思了，***编译器是先将这个数值放入一个内存中，再把这个地址付给a，此时的a代表的地址和m_data代表的地址不一样。***
​		综上两点可以看出，当返回的值是引用型时，会返回该变量的地址。当返回的值不是引用型时，编译器会专门给返回值分配出一块内存的
​		返回引用的优点：一般用作类对象的返回值，可以减少临时对象的申请、构造等操作，节省空间时间
​		函数返回若不返回一个变量的引用，则一定会生成一个临时变量

### 12.3.3 参数和返回值

​		1）对于任何参数，如果***仅需要从参数中读取而不改变它***，默认地应当作为const引用来传递他。普通运算符+，-，和布尔运算不会改变参数，所以以const传递是主要的使用方式。当函数是一个类成员时，就转换为const成员函数。只有***会改变***左侧参数的运算符赋值（+=）和operator=，***左侧参数不是常量***，但因为参数将被改变，所以参数仍然按地址传递

​		2）返回值的类型取决于运算符的具体含义，使用运算符产生一个新值，就需要产生一个作为返回值的新对象。例如：Integer::operator+必须生成一个操作数之和的Integer对象，这个对象作为一个常量通过传值方式返回，所以作为一个左值结果不会被改变。

​		3）所有运算符均改变左值。为了使赋值结果能用于链式表达式（a=b=c），应该能够返回一个刚刚改变了的左值的引用。***编译器从右向左分析这个表达式*** ，所以并非一定要返回一个非常量值来支持链式赋值。

​		4）对于逻辑运算符，人们希望至少得到一个int返回值，最好是bool返回值

### 12.3.4不常用的运算符

```c++
,, ->, 
```



### 12.3.5不能重载的运算符

​		1）成员选择operator. 。如果允许它重载，就不能用普通的方法访问成员，只能用指针和指针operator->访问

​		2）成员指针间接引用operator.*，因为与operator.同样的原因不能重载。

​		3）没有求幂运算符

​		4）不存在用户定义的运算符，因为难以决定其优先级

​		5）不能改变运算符优先级规则

| 优先级序号 | 运算符名                                     | 目   | 结合性   | 备注               |
| ---------- | -------------------------------------------- | ---- | -------- | ------------------ |
| 1          | ：：                                         | 2    |          | 作用域运算符       |
| 2          | ++，--                                       | 1    |          | 后缀自增自减运算符 |
|            | （），{}                                     | 2    |          | 函数风格转型       |
|            | （）                                         | 2    | ^        | 函数调用           |
|            | []                                           | 2    | \|       | 下标访问           |
|            | .，->                                        | 2    | 从左到右 | 成员访问           |
| 3          | ++，--                                       | 1    |          | 前缀自增自减运算符 |
|            | +，-                                         | 1    |          | 正负号             |
|            | ！，~                                        | 1    |          | 逻辑非，按位取反   |
|            | （）                                         | 2    |          | C风格转型          |
|            | *，&                                         | 1    | ^        | 解引用，取地址     |
|            | sizeof                                       | 1    | \|       | 取大小             |
|            | new,new[],delete,delete[]                    | 1    | 从右到左 | 动态内存分配       |
| 4          | .*，  ->*                                    | 2    |          | 指向成员指针       |
| 5          | *， /，%                                     | 2    |          | 乘除取余           |
| 6          | +，-                                         | 2    |          | 加减               |
| 7          | <<， >>                                      | 2    |          | 左移右移           |
| 8          | <=>                                          | 2    |          | 三路比较运算符     |
| 9          | <，<=，>，>=                                 | 2    |          | 比较大小运算符     |
| 10         | ==， ！=                                     | 2    |          | 比较是否相等运算符 |
| 11         | &                                            | 2    |          | 按位与             |
| 12         | ^                                            | 2    |          | 按位异或           |
| 13         | \|                                           | 2    | ^        | 按位或             |
| 14         | &&                                           | 2    | \|       | 逻辑与             |
| 15         | \|\|                                         | 2    | 从左到右 | 逻辑或             |
| 16         | ?:                                           | 3    | ^        | 三元条件运算符     |
|            | throw                                        | 0或1 | \|       | 抛出错误           |
|            | =，+=，-=，*=，/=，%=，<<=，>>=，&=，^=，\|= | 2    | 从右到左 | 赋值               |
| 17         | ，                                           | 2    | 从左到右 | 依次执行，返回最后 |



## 12.4非成员运算符

​		怎么选择成员还是非成员运算符？总的来说没有什么差异，成员运算符强调了运算符和类的联合。当左侧操作数是当前类的对象时，运算符会工作的很好。

​		有时左侧运算符是别的类对象，operator<<和>>时。

## 12.5重载赋值符

```c++
MyType b;
MyType a = b;
a = b;
```

​		第二行定义了对象a，a是从现有的MyType对象创建的，所以是使用拷贝构造函数的。虽然是一个=，但是拷贝构造函数仍在调用。

​		第三行等号左侧有一个以前以初始化了的对象，不用为一个已经存在的对象调用构造函数。为a调用MyType::operator = ，把出现在右侧的任何东西作为参数

​		当处理=时，如果对象还没有被创建，初始化是需要的，否则使用赋值operator=，

​		最好避免使用=的初始化代码，而是用显式的构造函数形式。

```c++
class Fi{
    Fi(){}
};
class Fee{
    Fee(int){}
    Fee(const Fi&){}
};
Fee fee = 1;//改为Fee fee(1);
Fi fi;
Fee fum = fi;//改为Fee fum(fi);
```

### 12.5.1operator = 的行为

​		operator=仅是成员函数，密切的与“=”左侧的对象相联系，如果允许定义operator=为全局的，那么我们就会试图重新定义内置的“=”

```c++
int operator= (int, MyType);//Global = not allowed!
```

​		编译器通过强制operator=为成员函数而避开这个问题

​		当创建一个operator=时，必须从右侧对象中拷贝所有需要的信息到当前的对象（调用运算符的对象）（a=b），以完成为类的“赋值”，对于简单的对象

```c++
class Value{
    int a,b,c;
    Value(int aa, int bb, int cc): a(aa), b(bb), c(cc){}
    Value& operator=(const Value& rv){
        a = rv.a;
        b = rv.b;
        c = rv.c;
        return *this;
    }
}
int main()
{
    Value a, b(1,2,3);
    a = b;
}
```

​		"="左侧的对象拷贝了右侧对象中的所有内容，然后返回它的引用，可以创建更加复杂的表达式。

​		这个例子中，准备给两个相同类型的对象赋值时，应该首先检查一下自赋值：这个对象是否对自身赋值了？

```c++
a = a;
如果b是a的另一个名字（例如，已被初始化为a的引用），那这也是对自己赋值
```

​		有些情况下无论怎样赋值都是无害的，但如果对类的实现进行修改，将会出现差异：一个赋值运算符必须首先释放掉一个对象的资源（去掉旧值），然后根据新值分配新的资源。在自己给自己赋值的情况下，释放旧的资源将是灾难性的，因为在分配新的资源时会需要旧的资源。

```c++
String& String::operator=(const String& rhs)
{
  delete [] data;    // delete old memory
  // 分配新内存，将rhs的值拷贝给它
  data = new char[strlen(rhs.data) + 1];
  strcpy(data, rhs.data);
  return *this;      
}
if(&dh != this){}//判断一下如果自赋值就跳过！
```

​		如果可以在赋值运算符函数体的首部检测到是给自己赋值，就可以立即返回，从而可以节省大量的工作，否则必须去实现整个赋值操作

#### 12.5.1.1类中指针

​		如果对象不是那么简单时，对象里包含指向别的对象的指针将如何？简单地拷贝一个指针意味着以指向相同的存储单元的对象而结束。这种情况下需要自己做薄记。

​		当作一个赋值运算或一个拷贝构造函数时，最简单的方法就是拷贝这个指针所涉及的一切

​		***重载operator<<***

```c++
void rename(const string& newName) 
{
    nm = newName;
    cout << "Dog renamed to: " << *this << endl;
}
//重载operator <<
friend ostream& operator<<(ostream& os,const Person& p)//第一个参数应该传cout,第二个参数传Person的对象
{
    return os << "[" << dh.houseName 
      << "] contains " << *dh.p;
}
```

​		将*this传递给cout进而调用ostream operator<<。

#### 12.5.1.2引用计数

```c++
DogHouse& operator=(const DogHouse& dh) {
    // Check for self-assignment:
    if(&dh != this) {
      p = new Dog(dh.p, " assigned");
      houseName = dh.houseName + " assigned";
    }
    return *this;
}
```

​		拷贝构造函数和operator=对指针所指向的内容做了一个新拷贝，并由析构函数删除它。如果对象需要大量的内存或过高的初始化，我们也许想避免这种拷贝。解决的方法称为***引用计数*** 。可以使一块存储单元具有智能，知道有多少对象指向它。拷贝构造函数或赋值运算意味着把另外的指针指向现在的存储单元并增加引用计数。消除意味着减小计数，计数为0则销毁这个对象。

```c++
//attach()增加计数detach()减小计数;
```

​		定义一个成员函数，别的对象在指向这个对象时调用attach（）结束指向时调用detach（）。

​		代码太多了不想看了

#### 12.5.1.3自动创建operator=

​		将一个对象赋给相同类型的另一个对象，默认地编译器自动创建type::operator=(type)，

​		一般不会想让编译器做这些，对于复杂的类应该显式地创建一个operator=，如果真的不想让人执行赋值运算，可以把operator=声明为private函数

## 12.6自动类型转换

​		如果编译器看到了一个表达式或函数调用使用了一个不合适的类型，它经常会执行一个自动类型转换，从现在的类型到所要求的类型。C++中可通过自动类型转换函数来为用户定义类型达到同样的效果：特殊类型的构造函数和重载的运算符。

### 12.6.1构造函数转换

​		构造函数把另一类型对象（或引用）作为它的单个参数，这个构造函数允许编译器执行自动类型转换。

```c++
class One{};
class Two{
public:
	Two(const One&){}//从One变成Two，在类Two中变
};
void f(Two){}
int main(){
	One one;
    f(one);
}
```

​		编译器检查到f（）应当以类Two作为参数但用的是One，然后编译器检查是否有从对象One到对象Two的方法。它发现了构造函数Two::Two（One）被调用，结果传了一个Two对象给f（）。

​		这种情况避免了定义两个f（）重载版本的麻烦，代价是调用Two的隐藏构造函数，损失效率。

#### 12.6.1.1阻止构造函数转换

​		有时通过构造函数自动类型转换可能出现问题，为了避免问题可以，在前面加***explicit关键字***（explicit的主要作用）（只能用于构造函数）

```c++
class Two{	
	explicit Two(const One&){}
};
void f(Two){}
int main(){
    One one;
    //No auto conversion allowed
    //! f(one);
    f(Two(One));//创建一个从One到Two的临时对象
}

```

### 12.6.2运算符转换

​		创建一个成员函数，通过关键字operator后跟随想要转换到的类型的方法，将当前类型转换为希望的类型。

因为没有指定一个返回类型--返回类型就是正在重载的运算符的名字。

```c++
class Three{
    int i;
public:
    Three(int ii = 0, int = 0):i(ii){}
};
class Four{
    int x;
public:
    Four(int xx) : x(xx){}
    operator Three() const {return Three(x);}//Four变成Three,在Four中变
    									 //构造函数是Four变成Three,在Three中变
};
void g(Three){}
int main(){
    Four four(1);
    g(four);
    g(1);//calls Three(1,0)
}
```

​		将运算符重载写在全局而不用成员运算符，原因是全局版本中的自动类型转换可以针对左右任一操作数，而成员函数版本必须保证左侧操作数已处于正确的形式，全局版本可以省代码。只需要定义为友元来保证私有的访问即可。

### 12.6.4自动类型转换的缺陷

​		1、编译器必须选择如何执行类型转换，如果没有正确地设计出转换，编译器会产生麻烦。类X可以用operator Y()
把它转换为类Y。如果类Y有一个单个参数为X的构造函数，这也表示同样的类型转换。现在编译器有两个从X到Y的转换方法，所以当发生转换时，编译器会产生一个二义性错误。解决的方法是直接避免那样做，仅提供一个单一类型自动转换方法。

​		2、当提供了转换到不止一种类型的自动转换会发生一个更难解决的问题（扇出）

```c++
class Apple{
public:
    operator Orange() const;
    operator Pear() const;
};
void eat(Orange);
void eat(Pear);
int main(){
    Apple c;
    //!eat(c); 
    	//Error: Apple-> Orange or Apple -> Pear??
    	//call of overloaded 'eat(Apple&)' is ambiguous
}
```

​		通常，自动类型的解决方法是只提供一个从某类型向另一个类型转换的自动转换版本。当然也可以有多个向其他类型的转换，但它们不应该是自动类型转换，***而应该用如makeA（）和makeB（）这样的名字来创建显式的函数调用***

​		什么意思：显式--强制类型转换
​		name<type>(expression);
​		cast-name:static_cast、 dynamic_cast、const_cast、reinterpret_cast。

#### 12.6.4.1隐藏的行为

​		看不懂，反正编译器自动创建特殊函数了

# 第十三章	动态对象创建

## 13.1对象创建

1）为对象分配内存。

2）调用构造函数初始化那个内存

第一步分配内存的时间：

​		1）在静态存储区域，存储空间在程序开始之前就可以分配。这个存储空间在程序的整个运行期间都存在。

​		2）无论何时到达一个特殊执行点（左大括号“  {  ” ）时，存储单元都可以在栈上被创建，出了执行点（右大括号}）这个存储单元自动被释放。这些栈分配运算内置于处理器的指令集中。

​		3）存储单元也可以从一块称为堆（自由存储单元）的地方分配，***称为动态分配内存*** ，运行时调用程序分配这些内存。这意味可以在任何时候决定分配内存及分配多少内存。当然也负责决定何时释放内存。由我们决定-------而不受范围决定。

​		在malloc时，只是分配了一块内存而不是生成一个对象，所以返回一个void *指针。C++中不许将void *类型指针赋予任何其他指针，必须做类型转换。C中对象使用时忘记初始化是程序出错的主要来源

### 13.1.2operator new 

​		C++ 中把创建一个对象所需的所有动作都结合在一个new运算符中。

```c++
MyType *fp = new MyType(1,2);//一定要采用指针来new
```

等价于调用malloc(sizeof(MyType))并使用（1，2）作为参数表来为MyType调用构造函数，this指针指向返回值的地址。在指针赋给fp之前，它是不定的，初始化的对象。

### 13.1.3operator delete

​		new 的反面表达式是delete表达式，delete表达式首先调用析构函数，然后释放内存（free()），正如new表达式返回一个指向对象的指针一样，delete需要一个对象的地址delete fp；

​		delete只用于删除new创建的对象，malloc,calloc,realloc创建的对象用delete都属于未定义动作

## 13.3用于数组的new和delete

```c++
MyType* fp = new MyType[100];
```

​		这样在堆上为100个MyType对象分配了足够的内存并为每一个对象调用了构造函数，但是现在仅拥有一个MyType*，它和

```c++;
MyType* fp2 = new MyType;
```

​		创建单个对象得到的结果是一样的。

​		 fp实际上是一个数组的起地址，可以用     fp[3]   形式来选择数组的元素。但销毁数组时发生了什么呢？

```c++
delete fp2;//OK
delete fp;// Not the desired effect
```

​		为所给地址指向的MyType对象调用析构函数，然后释放内存。但对于fp，另外99个对象的析构函数没有调用。适当数量的存储单元会被释放，但由于数组被分配在一整块内存中，整个内存大小被分配程序存储在某个地方。

​		解决方法是给编译器一个信息，说明它其实是一个数组起始地址， 

```c++
delete[]  fp;
```

​		旧版本

```c++
delete [100]fp;
```

  ，强迫设计者加入数组对象数量，有可能弄错对象数量，让编译器处理的附加代价小，所以只在一个地方指明对象数量要比两个地方指明好。

### 13.3.1使指针更像数组

​		fp可以被修改指向任何类型，对于一个数组的起始地址来讲没有什么意义，一般定义为常量更好些。***任何修改指针的企图都会被认为出错***。//ctrl+f “ 从里向外”看看怎么读这个定义

```c++
int const* q = new int[10];//q是一个指针，指向const int
const int* q = new int[10];//同上
```

​		都把const和指针指向的int捆绑在一起，而不是指针本身

```c++
int* const q = new int[10];//q是一个const指针，它是int型的
```

​		就是说q中的数组元素可以被修改了，但对q本身修改（q++）是不合法的。

```c++
#include<iostream>
using namespace std;
int main()
{
    int const* q1 = new int[10];
    const int* q2 = new int[10];
    int* const q3 = new int[10];
    q1++;
    //!q1[3] = 4;
    q2++;
    //!q3++;
    q3[4] = 10;
    cout << q3[4] << endl;
    system("pause");
    return 0;
}
```

![d91c79b42513476e9ff21eba25fc7cc1](E:\md的图片\d91c79b42513476e9ff21eba25fc7cc1.png)

## 13.4耗尽内存

​		new-handler 函数会被调用

​		它的默认动作是产生一个异常，

​		new-handler 的行为和operator new()绑在一起，如果已经重载了operator new（），new-handler将不会按默认调用。如果仍想使用new-handler，不得不在operator new() 代码中加入这些工作的代码。

## 13.5重载new和delete

### 13.5.1重载全局new和delete

​		重载的new必须有一个size_t参数(size的标准C类型)		传递了一个分配内存的对象的长度

```c++
void* operator new(size_t sz);
```

# 第十四章   继承和组合

## 14.1组合语法

 在新建的类中创建一个已有类的嵌入类

```c++
class X{void set();};
class Y{
	public :
	X x;
};
int main()
{
    y.x.set();//访问嵌入对象（成为子对象）的成员函数只需再一次的成员选择。
}
```

更常见把嵌入的对象设为私有，在共有接口中包含嵌入对象的使用。

## 14.2继承语法

1）通过继承，子类会把父类所占空间组合，sizeof会累加

2）Inheritance.cpp    line30  子父类中同名对象

D.change();//因为是X中的permute修改i所以返回Y的对象D的值由x的i决定

## 14.3构造函数的初始化表达式表

​		如果子对象没有默认构造函数或想改变构造函数的某个默认参数，新类的构造函数没有权利访问这个子对象的私有数据成员，所以不能直接地对它们初始化

​		解决方法：

```c++
class MyType:public Bar{
    
}
MyType::MyType(int i):Bar(i){...}
```

### 14.3.2成员对象初始化

成员对象：

```c++
class B{}；

class A{class B obj;}

//obj 即为成员对象

MyType2::MyType2(int i):Bar(i), m(i+1){}
```

​		MyType2构造函数的开头，该类从Bar继承来，包含一个成为m的成员对象。注意：虽然可以看到基类的类型，但只能看到成员对象的标识符。

### 14.3.2在初始化表达式表中的内建类型

​		对于没有构造函数的内建类型嵌入对象，初始化怎样进行呢？

​		为了使语法一致，把内建类看作这样一种类型，只有一个取单个参数的构造函数，而这个参数与正在初始化的变量的类型相同。

```c++
class X{
    int i;
    float f;
    char c;
    char* s;
public:
    X():i(7),f(1.4),c('x'),s("howdy"){}
};
int main()
{
    X x;
    int i(100);				}
    int* ip = new int(47);   }伪构造函数调用
}
```

## 14.4组合和继承的联合

​		C类对B类进行了继承并且有一个类型A的对象



## 14.5名字隐藏

​		如果继承一个类并且对它的成员函数重新进行定义，可能会出现两种情况。

第一种是正如在基类种所进行的定义一样，在派生类的定义中明确地定义操作和返回类型，称为对普通成员函数***重定义***

第二种如果基类的成员函数是虚函数的情况，又可称之为重写

重载

​		函数名相同，参数列表个数或顺序，类型不同。不能靠返回类型判断

1）相同的范围（在同一个作用域中）

2）函数名字相同

3）参数不同

4）virtual关键字可有可无

5）返回值可以不同

重写

​		覆盖（override）派生类重新定义基类的虚函数**是指派生类函数覆盖基类函数**

1）不在同一个作用域（分别位于派生类与基类）

2）函数名字相同

3）参数相同

4）基类函数必须有virtual关键字，不能有static

5）返回值相同（或是协变）

​		能在使用父类型的场景中改用[子类]子类型的被称为协变。
​		能在使用子类型的场景中改用父类型的被称为逆变。
​		不能做到以上两点的被称为不变。
​		以上的场景通常包括数组，继承和泛型

重定义

​		隐藏，**是指派生类的函数屏蔽了与其同名的基类函数**

1）不在同一个作用域（分别位于派生类与基类）

2）函数名字相同

3）返回值可以不同

4）参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏

5）参数相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏

### 如果在派生类中改变成员函数参数列表和返回类型，会发生什么情况呢？

//NameHiding.cpp

​		对于派生类中有相同参数列表的函数，会以派生类的函数功能为准

​		若调用的函数参数与派生类中参数列表不同，且可以访问基类的成员函数（public），那么以基类函数功能为准

## 14.6非自动继承的函数

不能自动地从基类继承到派生类的函数：

​		构造函数和析构函数，处理对象的创建和析构，但它们只知道对它们的特定层次上的对象做些什么。所以该类以下各个层次中所有的构造函数和析构函数都必须被调用，也就是说构造函数和析构函数不能被继承，必须为每一个特定的派生类分别创建。

​		operator=不能被继承，它完成类似于构造函数的活动，尽管我们知道如何由等号右边的***对象初始化***左边的对象的所有成员，但这并不意味着这个初始化在继承后拥有相同的意义

​		编译器中，构造函数和operator= 产生方式：

被嵌入的类：外部的构造函数调用时（后），内嵌类的构造函数也同时调用（先），

派生类的产生方式：构造函数调用顺序：基类中嵌入类->基类->派生类

​																 基类->派生类中嵌入类->派生类

operator=：对于嵌入类，必须显式赋值，完成operator=的所谓***对象初始化工作*** 

​				   对于“继承”operator=，需要在派生类重定义时显式地将基类的operator=所作的工作与派生类中operator=的函数参数对象进行绑定。

​		无论何时我们继承了一个类，这些调用都将成为我们使用的规范形式的一部分

### 14.6.1继承和静态成员函数

静态与非静态成员函数共同点：

1）可被继承到派生类中

2）如果重新定义了一个静态成员，所有在基类中的其他重载函数会被隐藏

3）如果我们改变了基类中一个函数的特征，所有使用该函数名字的基类版本都会被隐藏

**静态成员函数不可以是虚函数

## 14.7组合与继承的选择

​		组合：has - a，通常是希望在新类内部具有已存在类的功能时使用，而不是希望已存在类作为它的接口。嵌入一个新的对象用以实现新类的功能，而新类的用户看到的是新定义的接口而不是老类的接口。为此，在新类的内部嵌入已存在类的private对象

​		继承：is - a

### 14.7.2私有继承

​		对私有继承成员公有化：***对private继承来的类，如果想使它是可视的，在派生类中public部分声明它的名字即可。这个名字下包含所有重载的函数，都是public的***

## 14.8protected

​		有时希望某些东西隐藏起来，但仍允许其派生类的成员访问，就这个类的用户而言，它是private的，但它可被从这个类继承来的任何类使用。

​		最好让数据成员是private，通过protected成员函数控制对该类的继承者的访问

## 14.12向上类型转换

***（运算符重载中有强制类型转换：搜索：强制类型转换）***

```c++
class Instrument{
public:
    void play(note) const{}
};
class Wind : public Instrument{}；
void tune(Instrument& i){
    i.play(middleC);
}
int main(){
    Wind flute;
    tune(flute);//本来是接受一个Instrument但是现在参数却是一个Wind--Instrument的派生类
    //本来C++的类型检查是非常严格的，但Wind对象也是一个Instrument对象，tune（）函数对于Instrument的所有调用对于Wind也都是可调用的（这是由继承保证的）
}
```

​		在tune（）中，这些代码对Instrument和从Instrument派生来的任何类型都有效

​		这种将Wind引用或指针转变成Instrument引用或指针的，派生类转为父类的行为称为向上类型转换。

### 14.12.1为什么要向上类型转换

​		从派生类到基类的类型转换，在继承图上是上升的。

​		Instrument

​		Wind

### 14.12.2向上类型转换和拷贝构造函数

​		如果允许编译器为派生类生成拷贝构造函数，***首先自动地调用基类的拷贝构造函数，再是各成员对象的拷贝构造函数。

child构造函数中

```c++
class Child:public Parent{
Child(int ii) : Parent(ii), i(ii), m(ii);
friend ostream&
    operator<<(ostream& os, const Child& c){
    return os << (Parent&)c << c.m//不能改为(Parent)c!，此时编译器把它当成一个Parent对象
        //调用operator<<的Parent版本
              << "Child: " << c.i << endl;
  }
};
```

如果为Child写自己的拷贝构造函数，并且出现错误

```c++
Child(const Child& c) : /* Parent(c), */ i(ii), m(ii);
```

这时将会为Child中的基类部分调用默认的构造函数，这是在没有其他构造函数可供选择调用的情况下，编译器回溯搜索的结果。

```c++
//比方说，Parent有一个构造函数
Parent():i(0){}//则调用这个版本
```

​		这可能并不是我们所希望的，我们会希望基类部分从已存在的对象拷贝至新的对象，***这需要正确地调用基类拷贝构造函数，总之，不要漏掉这个Parent（c）***

​		c是一个Child对象，传递给Parent干什么？

​		Parent（c）：传给Child对象一个Parent构造函数意味着什么？Child由Parent继承而来，Child的引用相当于Parent的引用。基类拷贝构造函数的调用将一个Child的引用向上类型转换为一个Parent的引用，并且使用它来执行构造函数 

***一句话总结：***

​		***参数接受基类的引用，那么也可以接受其派生类，因为派生类就是一种基类，但是任何向上类型转换都会损失对象的类型信息***

### 14.12.3继承与组合（再论）

​		确定使用继承还是组合时，最清楚的方法是询问是否需要从新类向上类型转换。

### 14.12.4指针和引用向上类型转换

```c++
Wind w;
Instrument* ip = &w;
Instrument& ir = w;
```

​		与函数一样，都不要求显式地类型转换

### 14.12.5危机

​		***任何向上类型转换都会损失对象的类型信息***，上述写法只能把ip作为Instrument指针处理，它不知道ip实际上可能是指向Wind的对象，所以当调用play成员函数时，ip->play(middleC);

编译器只知道它在对Instrument指针调用play（），而不是应该做的调用wind：：play（），这个问题将由多态性：virtual函数实现。

# 第十五章  多态性和虚函数

## 15.2向上类型转换

​		取一个对象的地址（指针或引用），并将其作为基类的地址来处理，这被称为向上类型转换，因为继承树的绘制方式是以基类为顶点的。

```c++
class Instrument{
    void play(note) const{
        cout << "Instrument::play" << endl;
    }
};
class Wind : Instrument{
	 void play(note) const{
        cout << "Wind::play" << endl;
    }
}
void tune(Instrument& i) {
  i.play(middleC);
}

int main(){
    Wind flute;
    tune(flute);//Instrument::play
}
```



## 15.3问题

​		调用输出的是Instrument::play，我们知道这个对象实际上是Wind而不是Instrument，应当调用Wind::play，为此，由Instrument派生的任何对象不论它处于什么位置都应当使用它的play（）版本。为了理解这个问题，需要知道捆绑概念

### 15.3.1函数调用捆绑

​		把函数体与函数调用相联系称为捆绑，捆绑在程序运行之前完成时，称为早捆绑。C编译只有一种方式，就是早捆绑。

​		Instrument.cpp中的问题是早捆绑引起的，因为编译器只有在Instrument地址时它并不知道要调用的正确函数。

​		解决的方法称为晚捆绑，这意味着捆绑根据对象的类型，发生在运行时。

​		晚捆绑又称动态捆绑或运行时捆绑。

​		编译器不知道实际的对象类型，但它插入能找到和调用正确函数体的代码，晚捆绑机制因语言而异，某些种类的类型信息必须装在对象自身中。

## 15.4虚函数

​		对于特定的函数，为了引起晚捆绑，C++要求在基类中声明这个函数时使用virtual关键字。晚捆绑只对virtual函数起作用，而且只在使用含有virtual函数的基类的地址时发生，尽管它们也可以在更早的基类中定义。

​		仅仅在声明时需要使用关键字virtual，定义时不需要，如果一个函数在基类中被声明为virtual，在所有的派生类中都是virtual的，在派生类中virtual函数的重定义称为重写（overriding）

​		加了virtual后，play(flute)调用的则是Wind：：play

### 15.4.1扩展性

​		通过将play（）在基类中定义为virtual，不用改变tune（）函数就可以在系统中随意增加新韩淑，只与基类接口通信。这样的程序是可扩展的，可以从公共基类继承新数据类型而增加新功能。操作基类接口的函数完全不需要改变就可以适用于这些新类

​		与运算符重载相同效果的成员函数：

```c++
void getArea(){

    cout << "Circle with radius " << x ;

    cout << " has an area of " << x * x * 3.14 << endl;
}

  friend ostream&

  operator<<(ostream& os, const Circle& c){

  return os << "Circle with radius " << c.x

       << "has an area of " << c.x * c.x * 3.14 << endl;

 }
```



## 15.5C++如何实现晚捆绑

​		编译器对每个包含虚函数的类创建一个表VTABLE，编译器放置特定类的虚函数地址。在每个带有虚函数的类中，编译器秘密地放置一个指针vpointer（VPTR）指向这个对象的VTABLE。当通过基类指针做虚函数调用时（多态调用时），编译器静态地插入能取得这个VPTR并在VTABLE表查找函数地址的代码。

### 15.5.1存放类型信息    Sizes.cpp

​		不带虚函数，对象的长度恰好就是所期望的长度：单个int的长度。带有单个虚函数的One Virtual，对象的长度是NoVirtual加上一个void指针的长度 。它反映出，如果有一个或多个虚函数，编译器都只在这个结构中插入一个单个指针VPTR。因此OneVirtual和TWOVIRTUAL的长度没有区别。只需要一个表，所有的虚函数地址都包含在这个单个表中。

​		在这个例子中，对象至少需要一个数据成员。如果没有数据成员，C++编译器会强制这个对象是非零长度，因为每个对象必须有一个互相区别的地址，比如在零长度对象的数组中索引寻址是不可行的，所有通过把一个“哑”成员插入到对象中，否则这个对象就会是零长度。、

## 15.6为什么需要虚函数

​		为什么虚函数如此重要，但却是可选的呢？为什么我们需要知道它呢？回答关系到C++的基本哲学：“因为它不是相当高效的”。它并不是一个对于绝对地址的一个简单的CALL。

## 15.7抽象基类和纯虚函数

​		在设计时常常希望基类仅仅作为其派生类的一个接口。这就是说：

​		***仅想对基类进行向上类型转换，使用它的接口，而不希望用户实际地创建一个基类的类型*** 

​		要做到这点，可以在基类中加入至少一个纯虚函数来使基类成为抽象类

​		***纯虚函数使用关键字virtual，并在其后面加上=0，抽象类不能拿产生对象 virtual void f() = 0;不要加{}***

**不同的是虚函数可以加花括号在类中定义，然后再派生类中重写

​		***当继承一个抽象类时，必须实现所有的纯虚函数，否则继承出来的也是一个抽象类。***

​		类中全是纯虚函数称为纯抽象类

注意：纯虚函数禁止对抽象类的函数以传值方式调用。void describe(Pet p)这类，这也是防止对象切片的一种方法

### 15.7.1纯虚定义

​		在基类中对纯虚函数提供定义是可能的。如果要创建对象，则纯虚函数必须在派生类中定义

​		然而我们可能希望一些公共代码，使一些或所有派生类定义都能调用，而不必在每个函数中重复这段代码

​		在抽象类的结构体外进行虚函数的实现 Class：：function（）{}

​		再在派生类中，通过名字调用它

​		这个特点的另一个好处（第一个好处是第二行）是，允许我们实现从常规虚函数到纯虚函数的改变，而无需打乱已存在的代码

## 15.8继承和VTABLE

​		在派生类中继承或增加新的虚函数时会发生什么呢？

虚函数表：

| virtual &Pet::name()->      | &Pet::name()                |
| --------------------------- | --------------------------- |
| **virtual &Pet::speak()->** | **&Dog::speak()**//Override |
|                             | **virtual &Dog::sit()**     |

​		对于两者都有的speak的地址，编译器在Dog的VTable中把speak（）的地址准确地映射到Pet的VTable中同样的位置。

​		因为编译器产生的代码（汇编指令）在VTable中使用的是简单的偏移来选择虚函数。

​		因为基类中只含有name和speak函数，所以它就是编译器唯一允许调用的函数。

​		那么如果编译器只有基类对象的指针，怎么知道自己正在对Dog对象工作呢？

​		使用强制类型转换

​				((Dog*)p[1]) -> sit()可以消除产生的出错信息

​		这里使用强转的条件是我们已知p[1]的类型是Dog*，而通常情况下我们并不知道。

​		如果知道保存在一般容器中的所有对象的确切信息（因为可用基类直接保存而不知道是哪个派生类的对象），会使我们的设计工作在最佳状态（或者没有选择）。这就是运行时类型辨认（Run-Time  Type Identification)问题

​		RTTI是有关向下类型转换基类指针到派生类指针的问题。

​		向上类型转换是自动的，不需强制，因为它是绝对安全的

​		向下类型转换是不安全的，因为这里没有关于实际类型的编译信息，所以必须准确地知道这个类实际是什么

### 15.8.1对象切片

​		当多态地处理对象时，传地址和传值有明显的不同，这里的例子都是传地址的而不是传值的。

​		***这是因为地址都有相同长度***  

​				**其实并不是所有机器上指针都具有相同长度，只在讨论范围内认为它是相同的

​		传递派生类（它通常大一点）对象的地址和传递基类对象的地址是相同的。；

​		如果一个对象进行向上类型转换，而不是使用地址或引用，这个对象被“切片”，知道生下来的是适合于目的的子对象。ObjectSlicing.cpp

```c++
void describe(Pet p) {}
```

​		describe（）通过传值方式传递了一个Pet类型的对象，本来希望对Pet对象调用其虚函数description（），对Dog对象调用其description（）函数，实际上两次都调用了Pet基类版本的description函数。

​		在这个程序中，发生了两件事，

***		第一，describe（）接受的是一个Pet对象而不受指针或引用，所以describe（）中任何调用都会引起一个与Pet对象相同大小（通常基类小于派生类）的对象压栈并在调用后清除*** ，这意味着Pet派生来的类的对象被传给describe（），编译器会接受它，但只拷贝这个对象对应于Pet的部分，切除这个对象的派生部分

​		对象切片实际是当它拷贝到一个新的对象时，去掉原来的对象一部分，使编译器知道这个新对象的确切类型。而不是像使用指针或引用那样简单地改变地址的内容。

​		如果基类Pet的description（）函数是一个纯虚函数，因为编译器不会允许我们创建基类对象，所以它将阻止对象进行切片。这可能会是纯虚函数最重要的作用：

​		从对象切片的原因出发，编译器先得知道切完片的基类对象有多大，而纯虚函数阻止了这个对象的生成，那么它将通过一个编译错误来阻止对象切片。

## 15.9重载和重新定义

​		编译器不允许我们改变虚函数的重新定义过的函数的返回值，***如果不是虚函数，在派生类中可以重定义返回值。***

​		如果重定义了一个基类重载成员函数（基类中同名函数没有这种***参数表***，派生类中新增），则在派生类中其他的重载函数将会被隐藏。f（）的新版本实际上并没有重新定义一个已存在的虚函数的接口，f（）的两个基类版本会被f（int）隐藏（直接就不可用了）。但是如果把d4向上类型转换到Base，则只有基类版本是可行的，派生类Drive4则不行。

```c++
class Base{
public:
    virtual int f(){}
    virtual void f(string){}
    virtual void g(){}
};
class Derived1 : public Base{
public:
    void g(){}
};
class Derived2 : public Base{
public:
    int f(){}
};
class Derived3 : public Base{
public:
    //! void f(){};
    //不能改变虚函数的返回类型
};
class Derived4 : public Base{
public:
    int f(int){}
};
int main()
{
    Derived1 d1;
    Derived2 d2;
    //Derived3没重定义所以不建对象例子了
    Derived4 d4;
    //d1,d2的g()和f()都可以使用
    //! d4.f(1)修改了参数表，也可以使用，但是f()的两个基类版本再也不能使用了
}
```

***总结***

​		如果参数表没有变，不能修改返回类型

​		如果改了参数表的重定义，基类同名函数版本将在派生类中被隐藏

### 15.9.1变量返回类型

​		在总结的1）中，我们不能在重新定义的过程中修改虚函数的返回类型，通常是这样的，但是也有特例：

​		我们可以稍稍修改返回类型。

​		如果返回一个指向基类的指针或引用，则该函数的重新定义版本将会从基类返回的内容中返回一个指向派生类的指针或引用。VariantReturn.cpp

## 15.10虚函数和构造函数

​		创建一个包含虚函数的对象时，必须初始化它的VPTR以指向它的VTABLE，这必须在对虚函数进行任何调用之前完成。

​		因为生成一个对象是构造函数的工作，所以设置VPTR也是构造函数的工作。

​		如果该类有虚函数，则生成的构造函数（显式创建或编译器自动生成）将会包含相应的VPTR初始化代码。

### 15.10.1构造函数调用次序

​		构造函数的调用顺序和在构造函数中虚函数调用的方法

​		所有的基类构造函数总是在继承类的构造函数中被调用，因为构造函数专门的工作：确保对象被正确地建立，当派生类不能访问基类中成员时，只有基类自己的构造函数能初始化它自己的成员。

​		基类构造函数首先被调用    -->    派生类在基类中所有能访问的成员都已初始化

### 15.10.2虚函数在构造函数中的行为

​		如果在构造函数中调用了虚函数会怎样？

​				普通成员函数：虚函数在运行时决定，因为编译时这个对象不知道它处于成员函数所在类还是派生类。

​		构造函数中调用虚函数并非如此，***被调用的只是这个函数的本地版本***，也就是说虚机制在构造函数中不工作

​		理由：

1）构造函数的工作是生成对象。在任何构造函数中，可能只是部分形成对象--我们只能知道基类已被初始化，，但并不能知道哪个类是从这个基类继承来的。然而虚函数在继承层次上是“向前”和“向外”进行调用，它可以调用在派生类中的函数。如果在构造函数中也这样做，所调用的函数可能操作还未初始化的成员

2）机械方面，构造函数初始化VPTR，然而构造函数只知道它属于当前的类，完全不知道这个对象是否是***基于其他类的*** 。编译器在为这个构造函数产生代码时，它既不为基类，也不为派生类产生代码（因为类不知道谁继承它）。

​		在这个对象声明周期中内，VPTR将保持被初始化未指向这个VTABLE。但如果接着还有一个更晚派生的构造函数被调用，，这个构造函数又将设置VPTR指向它的VTABLE。如果接着还有一个更晚派生的构造函数被调用，这个构造函数由将VPTR设置指向它的VTABLE。***以此类推，直到最后一个构造函数结束。VPTR的状态是由被最后调用的构造函数确定的。***这就是为什么构造函数是按照从基类到最晚派生的类的顺序的一个理由**

## 15.11析构函数和虚析构函数

​		***构造函数不能为虚函数，但析构函数能够且常常必须是虚的。***

​		***析构函数从最晚派生的类开始，并向上到基类***

​		***派生类的析构函数然后调用基类的析构函数***

​		**析构函数可以是虚的，因为这个对象已经知道它是什么类型，在构造期间则不然**

### 15.11.1纯虚析构函数

​		必须为纯虚析构函数提供一个函数体

​		纯虚与非纯虚的唯一区别在于纯虚析构函数使得基类是抽象类（基类的其他函数都是纯虚函数），所以不能创建一个基类的对象。

​		当从某个含有虚析构函数的类中继承出一个类，不像其他的纯虚函数，不要求在派生类中提供虚函数定义

```c++
class AbstractBase{
public:
    virtual ~AbstractBase() = 0;
};
AbstractBase::~AbstractBase() {}
class Derived : public AbstractBase {};
//没有重写基类的纯虚析构函数

int main()
{
    Derived d;
}
```

​		一般来说，如果派生类中基类的纯虚函数没有重新定义，则派生类会称为抽象类，但如果不进行析构函数定义，编译器却自动为每个类生成一个析构函数定义，而派生类不会成为抽象类。

​		***作用：析构函数的纯虚性的唯一效果是阻止基类的实例化***。如果有其他的纯虚函数，它们会阻止基类的实例化，但如果没有，析构函数是唯一的一个函数时，纯虚析构函数将会执行这些操作

​		作为一个准则，任何时候我们类中都要有一个虚函数，我们应当立即增加一个虚析构函数（即使他什么也不做）

### 15.11.2析构函数中的虚机制

​		在析构函数中，不会使用晚捆绑机制调用这个函数，不论是虚的还是非虚的，只有成员函数的“本地”版本被调用，虚机制被忽略。

​		派生类的虚函数没有被调用，假设在析构函数中使用虚机制，那么调用一个在继承层次中比当前析构函数更晚派生的函数是可能的。

​		析构函数从外层被调用，从最晚派生的析构函数向基类析构函数，所以实际上被调用的函数可能操作在已被删除的对象上。因此编译器决定在编译时只调用这个函数的本地版本（该类自己的成员函数），不调用派生类重写的版本。

## 15.12运算符重载

​		使用virtual运算符重载，例如处理矩阵、向量、标量（了解一下吧）

​		

## 15.13 向下类型转换

​		当一个shape向下类型转换时，可以是circle、square、triangle等，因此需要安全地进行向下类型转换。

​		C++提供特殊的类dynamic_cast的显示类型转换。它就是一种安全类型向下类型转换。

​		dynamic_cast使用VTable中的信息来判断实际类型

​		有时在向下转型时知道正在处理的是何种类型，使用static_cast代替它

​		dynamic_cast是RTTI的一种形式，向上转型的shape指针类型相继于circle和square比较（typeid）

总结：

​		到目前为止，搞不清楚的有：

```c++
const int* q;int* const q;//查const int* 第十三章
运算符重载语法
virtual 改不了返回值，如果改了参数表，基类同名函数被隐藏
Child(const Child& c) : /* Parent(c), */ i(ii), m(ii);//拷贝构造函数的初始化列表
```



# 第十六章  模板介绍

## 16.1容器

​		使用static数组，使它不会多次生成这些数

### 16.1.1容器的需求

​		容器类的需求是在堆上new创建，delete销毁的时候体现的

​		编写程序时不知道将来需要创建几个对象。例如设计空中交通指挥系统时不应限制这个系统能处理的飞机数目，不希望由于实际飞机的数目超过设计值而导致系统失败。

​		另外，如果创建一个巨大的C++对象的全局数组，那么构造函数和析构函数的开销会使系统效率显著的下降。

C++有更好的方法：用new创建需要的对象，将其指针放入容器中，待实际使用时将其取出并进行处理 

## 16.3模板方法

​		template关键字告诉编译器，随后的类定义将操作一个或多个未指明的类型。

```c++
#include<iostream>
using namespace std;

template <class T>
void Swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}
int main()
{
    int n = 1,  m = 2;
    Swap(n, m);
    double f = 1.2, g = 2.3;
    Swap(f, g);
    return 0;
}
```

​		T是替换参数，代表一个类型名称，它将出现在原本由某一特定类型出现的地方

​		随后在类中使构造类型typename改为T，

```c++
template <class T>
class Array{
	T A[size];
public:
	T& function(){}
};
```

### 16.3.1非内联函数定义

```c++
template<class T>
class Array {
  enum { size = 100 };
  T A[size];
public:
  T& operator[](int index);
};

template<class T>
T& Array<T>::operator[](int index) {
  require(index >= 0 && index < size,
    "Index out of range");
  return A[index];
}
```

### 16.3.2作为模板的IntStack

### 16.3.3模板中的常量

```c++
template<class T, int size = 100>
```

​		允许在实例化时设置Array长度，并且还可以提供默认值

# 第二卷    实用编程技术

# 第一章  异常处理

## 1.1传统的错误处理

1）函数中返回错误信息，标准C中提供errno和perror()来设置全局错误状态标志

2）标准C库的信号处理系统，signal（）用以推断发生了什么，raise（）产生一个事件

3）非局部跳转函数：setjmp（）和longjmp（），setjmp（）在程序中保存一个已知的无错误的状态，一旦发生错误，longjmp（）返回到该状态，这使得错误发生的位置和保存状态的位置之间高度耦合

​		这两个函数并不调用析构函数，所以对象不会被正确地清理，longjmp（）跳到超出析构函数作用范围以外的部分，则程序的行为不可预料

## 1.2抛出异常

​		当出现了异常--通过当前语境无法获得足够的信息以决定应该采取什么样的措施--程序员可以创建一个包含错误信息的对象并把它抛出当前语境。

# 第九章    多重继承

## 9.2接口继承

​		接口继承仅仅是在一个派生类接口中添加了成员函数的声明，C++中并不直接支持这种方式，C++中模拟接口继承常见的技术是从一个仅包含声明的接口类派生一个类。，除析构函数外，这些声明都是纯虚函数   

  

# 多线程

![image-20240915130545115](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20240915130545115.png)

## Lambda表达式

```c++
void abssort(float* x, unsigned n){
    std::sort(x, x + n,
             [](float a, float b){
                 return (std::abs(a) < std::abs(b));
             }
    );
}
```

sort的第三个参数是一个传递排序规则的函数，实例中直接将排序函数的实现写在应该传递函数的位置，盛趣了定义排序函数的过程。理由是这个函数不需要复用，且短小，于是可以直接传递函数体。

1. [ ] 表示捕获列表，描述上下文哪些数据可以被Lambda使用，以及使用方式

   ```c++
   //[&var]表示引用传递变量var(也可以值传递),前面加&表示全部都用引用
   int num = 100;
   auto function = ([&num]{
       std::cout << num << std::endl;
   	}
   );
   fucntion();
   //[=]表示按值传递所有父作用域变量,包括this理解为上下文参数
   int index = 1;
   int num = 100;
   auto function = ([=]{
       std::cout << "index: " << index << ", "
           << "num: " << num << std::endl;
   	}
   );
   //[=, &]拷贝与引用混合
   //[=, &a, &b] 表示以引用传递的方式捕捉变量a和b,以值传递方式捕捉其他所有变量
   int index = 1;
   int num = 100;
   auto function = ([=, &index, &num]{
       num = 1000;
       index = 2;
       std::cout << "index: " << index << ", "
           << "num: " << num << std::endl;
   	}
   );
   ```

   ```c++
   //两种引用的传值方式
   std::thread t3([=, &c]{ad(a,b,c);});//直接将c作为引用传入
   std::thread t4(add, a, b, std::ref(c));//本来是按值传递的,转换成c的引用
   ```

   如果要穿const引用，std::cref(c);

2. 参数列表 [ ] (int first, int second)

```c++
//lambda接受参数输入, 可选, 大多数蕾仕于函数列表
auto function = ([](int first, int second){
    return first + second;
	}
);
```

3. 函数体

   ```c++
   thread c([&c3, &totalC, iter2, end]{
       realWork(c3, totalC, iter2, end)
   }
   );
   ```




## 创建线程

```c++
//: B02: LearnThread.cpp
C++多线程主要使用的是线程库<thread>
```

```c++
std::thread newThread1(threadFunctionA);
std::thread newThread2(threadFunctionB,2);
newThread1.join();
newThread2.join();//join函数等待线程执行完成
```

执行函数有引用参数

```c++
void threadFunc(int &arg1, int arg2)
{
	arg1 = arg2;
	std::cout << "arg1 = " << arg1 << std::endl;
}
int main()
{
    int a = 1;
	int b = 5;
    std::thread newTh(threadFunc, std::ref(a), b);
	std::thread newTh(threadFunc, a, b);  //此处会报错
}
```

thread在传递参数时用的是右值，如果需要传递左值即a，b可以用std::ref 和 std::cref

### join()和detach()

```c++
nt main()
{
	Obj obj;
	std::thread t(foo);

	if (t.joinable())
	{
		//t.join();  		// 等待线程t执行完毕

		t.detach();  // 分离线程t与主线程
	}

	std::cout << "Run Main thread!\n";
	system("pause");
	return 0;
}
```

|      | 方法       | 说明                                                         |
| ---- | ---------- | ------------------------------------------------------------ |
| 1    | join()     | 等待线程完成，如果线程还未执行完毕，则当前线程（一般是主线程）将被阻塞，直到该线程执行完成，主线程才会继续执行。 |
| 2    | detach()   | 将当前线程与创建的线程**分离**，使它们分别运行，当分离的线程执行完毕后，系统会自动回收其资源。如果一个线程被分离了，就**不能再使用**`join()`函数了，因为线程已经无法被联接了。 |
| 3    | joinable() | 判断线程是否可以执行`join()`函数，返回**true/false**         |

​	**会发生的：**如上，如果使用 t.detach()将线程 t 分离，那么他们将同时执行，主线程不会被阻塞。否则在 t.join()时主线程将被阻塞，直到 t 线程执行完毕。

​						使用 t.join()时，t(foo)执行完后会sleep一下，主线程再执行完毕

​						使用 t.detach()时，主线程不会被阻塞，程序直接执行结束

如果此程序中**不使用**`join()`，那么在 t 线程作用域结束时，就会给程序直接执行`dum`，不会给`Obj`析构的机会

​	**注意：** 

- 线程是在**thread**对象被定义的时候开始执行的，而不是在调用`join()`函数时才执行的，调用`join()`函数只是阻塞等待线程结束并回收资源。
- 分离的线程（执行过`detach()`的线程）会在调用它的线程结束或自己结束时自动释放资源

- 线程会在函数运行完毕后**自动释放**，不推荐利用其他方法强制结束线程，可能会因资源未释放而导致内存泄漏。

- 若没有执行`join()`或`detach()`的线程在程序结束时会引发异常。

  

### this_thread

|      | 使用                            | 说明                                   |
| ---- | ------------------------------- | -------------------------------------- |
| 1    | std::this_thread::sleep_for()   | 当前线程休眠指定的时间                 |
| 2    | std::this_thread::sleep_until() | 当前线程休眠直到指定时间点             |
| 3    | std::this_thread::yield()       | 当前线程让出CPU，允许其他线程运行      |
| 4    | std::this_thread::get_id()      | 获取当前线程的ID                       |
| 5    | std::this_thread == / !=        | 重载运算符==, !=, 比较两个线程是否相等 |

```c++
//: B02: csdn_thread4.cpp
若线程不让出时间片，不休眠，则会按顺序执行完两个线程中5个i;
若让出时间片，不休眠，同上;
若不让出时间片，休眠，则子线程2和3会交替执行;
让出时间片，休眠，同上;
```

### std::mutex

#### 1.lock()unlock()

|      | 方法       | 说明                                                         |
| ---- | ---------- | ------------------------------------------------------------ |
| 1    | lock()     | **将mutex上锁**。如果mutex已经被其它线程上锁，那么会阻塞，直到解锁；如果mutex已经被同一个线程锁住，那么会产生**死锁**。 |
| 2    | unlock()   | **将mutex解锁**，释放其所有权。如果有线程因为调用`lock()`不能上锁而被阻塞，则调用此函数会将mutex的主动权随机交给其中一个线程；如果mutex不是被此线程上锁，那么会引发未定义的异常。 |
| 3    | try_lock() | **尝试将mutex上锁**。如果mutex未被上锁，则将其上锁并返回**true**；如果mutex已被锁则返回**false**。 |

- 加解锁顺序必须相同
- 不能在未获得锁的情况下对共享数据进行操作。
- 由于使用了 `std::mutex` 来控制对共享资源的访问，因此**可能会对程序的性能造成影响**，如果需要优化程序性能，可以考虑使用无锁编程等技术。

#### 2. lock_guard

自动加锁解锁，作用域结束时自动释放锁资源，避免手动管理出错。

- **自动加锁：** 在创建`std::lock_guard`对象时，会立即对指定的互斥量进行加锁操作。这样可以确保在进入作用域后，互斥量已经被锁定，避免了并发访问资源的竞争条件。
- **自动解锁：**`std::lock_guard`对象在作用域结束时，会自动释放互斥量。无论作用域是通过正常的流程结束、异常抛出还是使用`return`语句提前返回，`std::lock_guard`都能保证互斥量被正确解锁，避免了资源泄漏和死锁的风险。
- **适用于局部锁定：** 由于`std::lock_guard`是通过栈上的对象实现的，因此适用于在局部范围内锁定互斥量。当超出`std::lock_guard`对象的作用域时，互斥量会自动解锁，释放控制权。

**使用`std::lock_guard`的一般步骤如下：**

1. 创建一个`std::lock_guard`对象，传入要加锁的互斥量作为参数。
2. 执行需要加锁保护的代码块。
3. `std::lock_guard`对象的作用域结束时，自动调用析构函数解锁互斥量。

```c++
//: B02: csdn_thread6.cpp
std::mutex mtx;//互斥量
{
    std::lock_guard<std::mutex> lock(mtx);//加锁互斥量
    cout << "running" << endl;//执行需要加锁保护的代码
    //不能使用lock.unlock()/lock.lock()执行不需要加锁保护的代码
}//lock_guard对象的析构函数自动解锁互斥量
```

对比unique_lock()👇如果在线程函数体里不能对lock加解锁

#### 3.unique_lock

比std::lock_guard更多的功能和灵活性

- 自动加锁和解锁： 与std::lock_guard类似，std::unique_lock在**创建对象时**立即对指定的互斥量进行加锁操作，确保互斥量被锁定。在对象的**生命周期结束时**，会自动解锁互斥量。这种自动加锁和解锁的机制避免了手动管理锁的复杂性和可能出现的错误。 
- 支持灵活的加锁和解锁： 相对于std::lock_guard的自动加锁和解锁，std::unique_lock提供了更灵活的方式。它可以**在需要的时候手动加锁和解锁互斥量**，允许**在不同的代码块中**对互斥量进行多次加锁和解锁操作。
- 支持延迟加锁和条件变量：std::unique_lock还支持**延迟加锁**的功能，可以在不立即加锁的情况下创建对象，稍后根据需要进行加锁操作。此外，它还可以与条件变量（std::condition_variable）一起使用，实现更复杂的线程同步和等待机制。

```c++
//: B02: csdn_thread7.cpp
std::mutex mtx;  // 互斥量

void thread_function()
{
    std::unique_lock<std::mutex> lock(mtx);  // 加锁互斥量
    std::cout << "Thread running" << std::endl;
    // 执行需要加锁保护的代码
    lock.unlock();  // 手动解锁互斥量
    // 执行不需要加锁保护的代码
    lock.lock();  // 再次加锁互斥量
    // 执行需要加锁保护的代码
}  
// unique_lock对象的析构函数自动解锁互斥量
```

#### 4.condition_variable

条件变量，提供等待和通知的机制，是现成可以等待某个条件成立时被唤醒，或者在满足某个条件时通知其他等待的线程。其提供了以下几个函数用于等待和通知线程：

|      | 方法       | 说明                                                         |
| ---- | ---------- | ------------------------------------------------------------ |
| 1    | wait       | 使当前线程进入等待状态，直到被其他线程通过`notify_one()`或`notify_all()`函数**唤醒**。该函数需要一个互斥锁作为参数，调用时会自动释放互斥锁，并在被唤醒后重新获取互斥锁。 |
| 2    | wait_for   | 使当前线程进入等待状态，最多等待一定的时间，直到被其他线程通过`notify_one()`或`notify_all()`函数唤醒，**或者等待超时**。                                                                                                         该函数需要一个互斥锁和一个时间段作为参数，返回时有两种情况：等待超时返回`std::cv_status::timeout`，被唤醒返回`std::cv_status::no_timeout` |
| 3    | wait_until | 使当前线程进入等待状态，直到被其他线程通过`notify_one()`或`notify_all()`函数唤醒，或者等待时间达到指定的绝对时间点。                                                                                                          该函数需要一个互斥锁和一个绝对时间点作为参数，返回时有两种情况：时间到达返回`std::cv_status::timeout`，被唤醒返回`std::cv_status::no_timeout` |
| 4    | notify_one | `notify_one()`: 唤醒一个等待中的线程，如果有多个线程在等待，则选择其中一个线程唤醒。 |
| 5    | notify_all | `notify_all()`: 唤醒所有等待中的线程，使它们从等待状态返回。 |

**`std::condition_variable`的主要特点如下：**

- 等待和通知机制：`std::condition_variable`允许线程进入等待状态，直到某个条件满足时才被唤醒。

  线程可以调用`wait`函数进入等待状态，并指定一个互斥量作为参数，以确保线程在等待期间互斥量被锁定。当其他线程满足条件并调用`notify_one`或`notify_all`函数时，等待的线程将被唤醒并继续执行。

- 与互斥量配合使用：`std::condition_variabl`需要与互斥量`(std::mutex或std::unique_lock< std::mutex >)`配合使用，以确保线程之间的互斥性。在等待之前，线程必须先锁定互斥量，以避免竞争条件。当条件满足时，通知其他等待的线程之前，必须再次锁定互斥量。

- **支持超时等待：**`std::condition_variable`提供了带有超时参数的等待函数`wait_for`和`wait_until`，允许线程在等待一段时间后自动被唤醒。这对于处理超时情况或限时等待非常有用。

使用std::condition_variable的一般步骤如下：

1. 创建一个std::condition_variable对象.
2. 建一个互斥量对象（std::mutex或std::unique_lock< std::mutex >）。
3. 在等待线程中，使用std::unique_lock锁定互斥量，并调用wait函数进入等待状态。
4. 在唤醒线程中，使用std::unique_lock锁定互斥量，并调用notify_one或notify_all函数通知等待的线程。
5. 等待线程被唤醒后，继续执行相应的操作。

```c++
//: B02:csdn_thread8.cpp
std::mutex mtx;
std::condition_variable cv;
bool isReady = false;

void thread_function()
{
	std::unique_lock<std::mutex> lock(mtx);
    while(!isReady)
    {
        cv.wait(lock); //等待条件满足
    }
    std::cout << "Threadis notified" << std::endl;
}
int main()
{
    std::thread t(thread_function);//在线程对象被定义时开始执行
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    {
        std::lock_guard<std::mutex> lock(mtx);
        isReady = true;
    }
    cv.notify_one();
    t.join();
}
```



## 共享变量

```c++
//B02:/ CountThread.cpp
在这个程序中,原本的c2和c3处理后的totalValue和预期结果不同,原因是对共享变量的写有冲突(或者类似原因);
其中,b执行 
    realWork(counter2, totalValue, iter, iter2);
c执行
    realWork(c3, totalValue, iter2, end);
//改正
引入c4后,c2,c3分别处理1/3的数据,最后共同写入totalValue
```

由CountThread.cpp引出问题：多线程之间如何共享非const变量

1. 如果没有必要的话线程间不要共享资源。

## 原子操作

```c++
//B02:/ atomic.cpp
#include <atomic>
```

```c++
//错误的
int m_count; //共享资源m_count导致冲突
std::thread b([&counter2, &totalValue, iter, iter2]{
        realWork(counter2, totalValue, iter, iter2);
    }
);
std::thread c([&c3, &totalValue, iter2, end]{
        realWork(c3, totalValue, iter2, end);
    }
);
```

```c++
std::atomic<int> m_count;//原子操作
//++ -- + - * /
//m_count.fetch_add(1)等都支持
```

## 临界区

```c++
//: B02:BankAccount.cpp
void transferMoney(BankAccount& a, BankAccount& b, int money){
    if(&a == &b) return;
    if(&(a.Mutex) < &(b.Mutex)){
        std::lock_guard<std::mutex> lockA(a.Mutex);
        std::lock_guard<std::mutex> lockB(b.Mutex);
        //需要保加锁护的代码块, a.Balance与b.Balance
        if(a.Balance <= money)
            return;
        a.Balance -= money;
        b.Balance += money;
    }else{//找一个标识符,让两个lock根据情况先后执行
        std::lock_guard<std::mutex> lockA(b.Mutex);
        std::lock_guard<std::mutex> lockB(a.Mutex);
        //需要保加锁护的代码块, a.Balance与b.Balance
        if(a.Balance <= money)
            return;
        a.Balance -= money;
        b.Balance += money;
    }
}
/*
    问题:找一个标识符,让两个lock根据情况先后执行，如果有多方是不是要2^n次else
    解决方法:利用标准库接口  std::lock(a.Mutex, b.Mutex);//可以有若干多参数
*/
```

#### adopt_lock

```c++
std::lock(a.Mutex, b.Mutex);//把所有mutex全部锁住,才会往下走,否则等待
//下面两步做解锁过程
std::lock_guard<std::mutex> lockA(a.Mutex, std::adopt_lock);
std::lock_guard<std::mutex> lockB(a.Mutex, std::adopt_lock);
```

## thread交互

```c++
//: B02:ConditionaVariable.cpp
若worker中while(!ready)什么也不做,输出顺序会混乱;
std::lock_guard<std::mutex> lock(mutex);//简单上锁,正常输出
而worke里使用printf(),由于它是线程安全的,也会正常输出;//可看作和cout的区别,它不是线程安全的

```

改造一下程序，在ready = true前面让线程休眠两分钟。即：条件不满足，程序一直在while里面死循环

`this_thread::yield`相当于为忙等待提供了一个机会，可以主动让出线程的时间片，OS重新进行调度，但是下一个被调度进来的线程是哪个由OS来决定，有可能是别的线程，也有可能还是当前线程。

```c++
//把CPU让给其他程序
std::this_thread::yield();
1. 主动让出CPU,线程主动请求让出CPU时间片,而不是被OS强制调度;
2. 时间不确定,yield()让出CPU的时间是实际根据调度策略和系统负载的;
3. 不参与当前调度周期, 只能在下个调度周期里等待分配CPU时间片;
4. 适用于忙等待状态:线程处于需要不断检查的(死)循环中,yield()可以避免无谓的CPU消耗,也就是上述程序所做的
```

```c++
//方法2,worker也sleep_for一下,隔一段时间检查一次ready
void worker(int i){
    while(!ready){
        //do nothing -> endless loop
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
```

每个线程里执行多一些任务，相比之下线程之间调度和等待的时间比例就会降低

#### 条件变量

```c++
//两个线程交替打印奇偶数
std::condition_variable cv;
std::unique_lock<std::mutex> lock(mtx);		//加锁,必须使用unique_lock保证后面能灵活开锁
cv.wait(lock, []{return quit || !globalList.empty();});		//释放lock,等待后面条件达成
```



