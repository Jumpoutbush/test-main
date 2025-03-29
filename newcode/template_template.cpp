#include <iostream>
#include <vector>
#include <list>

template <template <typename, typename> class Container, typename T>
class ContainerWrapper{
private:
    Container<T, std::allocator<T>> container_;     // allocator<T>要在T定义之后，顺序不能变
public:
    
    ContainerWrapper() = default;
    ContainerWrapper(Container<T, std::allocator<T>>& container) : container_(container){}
    void print(const Container<T, std::allocator<T>>& container){
        for(const auto& item : container){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> v{1,2,3};
    std::list<int> l{4,5,6};

    ContainerWrapper<std::vector, int> vecwrapper;
    ContainerWrapper<std::list, int> listwrapper;

    vecwrapper.print(v);
    listwrapper.print(l);
    system("pause");
    return 0;
}
