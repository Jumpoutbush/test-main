#include <iostream>
#include <functional>
#include <memory>

class SomeOne{
private:
    TaskScheduler sche;
};

class TaskScheduler{
    friend class TaskContext;
public:
    TaskScheduler() : self_ref(this, [](TaskScheduler const*){}){}
    TaskScheduler& do(function<void(TaskContext)> f);
private:
    std::shared_ptr<TaskScheduler> self_ref;
};

class TaskContext{
    friend class TaskScheduler;
    std::weak_ptr<TaskScheduler> owner;
public:
    TaskContext& do(function<void(TaskContext)> f){
        if(auto const sb = owner.lock())
            f(sb);
        return *this;
    }
};