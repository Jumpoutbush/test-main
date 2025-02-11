// 多态例子
#include <iostream>
using namespace std;

class Instrucment{
public:
    Instrucment(){cout << "Instrucment constructor" << endl;}
    Instrucment(const Instrucment& inc) = delete;
    Instrucment& operator=(const Instrucment& inc) = delete;

    virtual void play(){
        cout << "Instrucment" << endl;
    }

    virtual ~Instrucment(){}
};

class Piano : public Instrucment {
public:
    Piano(){cout << "Piano constructor" << endl;}
    void play() override{
        cout << "Piano" << endl;
    }
    ~Piano(){ cout << "~Piano" << endl;}
};

class Violin : public Instrucment {
public:
    Violin(){cout << "violin constructor" << endl;}
    void play() override{
        cout << "Violin" <<endl;
    }
    ~Violin(){ cout << "~Violin" << endl;}
};

void perform(Instrucment* it){
    it->play();
}
int main()
{
    Piano* piano = new Piano();
    Violin* violin = new Violin();
    perform(piano);
    perform(violin);
    return 0;
}