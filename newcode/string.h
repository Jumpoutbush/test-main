#include <cstddef>
#include <cstring>
#include <algorithm>
#include <stdexcept>

class string {
public:
    static const size_t s_min_capacity;
private:
    char* data_;    // new 创建堆上数据
    size_t size_;
    size_t capacity_;

    // 重新分配内存
    void realloc_data(size_t new_cap) {
        new_cap = std::max(new_cap, s_min_capacity);
        char* new_data = new char[new_cap + 1];
        if(size_ > 0) {
            std::memcpy(new_data, data_, size_);
        }
        new_data[size_] = '\0';
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }

public:
    string() : size_(0), capacity_(s_min_capacity) {
        data_ = new char[capacity_ + 1];
        data_[0] = '\0';
    }

    // 支持C风格字符串构造函数，遇到'\0'会自动截断字符串
    string(const char* str)
    {
        if(!str){
            throw std::invalid_argument("null pointer");
        }
        size_ = std::strlen(str);
        capacity_ = std::max(size_, s_min_capacity);
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, str, size_ + 1);
    }

    // 二进制安全构造函数
    string(const void* data, size_t len)
    {
        if(!data) {
            throw std::invalid_argument("null pointer");
        }
        size_ = len;
        capacity_ = std::max(len, s_min_capacity);
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, data, len);
        data_[len] = '\0';
    }

    ~string() {
        delete[] data_;
    }

    string(const string& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, other.data_, size_ + 1);
    }

    string(string&& other) noexcept
     : data_(other.data_), 
       size_(other.size_), 
       capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    string& operator = (const string& other) {
        if(this != &other) {
            // data_, size_, capacity_
            char* new_data = new char[other.capacity_ + 1];
            std::memcpy(new_data, other.data_, other.size_ + 1);
            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

    string& operator = (string&& other) noexcept {
        if(this != &other)
        {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.size_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_  = 0;
        }
        return *this;
    }

    // 预分配内存
    void reserve(size_t new_cap) {
        if(new_cap > capacity_) {
            realloc_data(new_cap);
        }
    }

    // 释放多余内存
    void shrink_to_fit() {
        if(capacity_ > size_) {
            realloc_data(size_);
        }
    }

    string& append(const char* str, size_t len){
        if(!str) throw std::invalid_argument("null pointer");
        if(size_ + len > capacity_) {
            reserve((size_ + len) * 2);
        }
        std::memcpy(data_ + size_, str, len);
        size_ += len;
        data_[size_] = '\0';
        return *this;
    }

    string& append(const char* str) {
        if(!str) throw std::invalid_argument("null pointer");
        return append(str, std::strlen(str));
    }

    
    string& operator += (const char* str) noexcept {
        return append(str, std::strlen(str));
    }

    const char* c_str() const noexcept { return data_;}
    const char* data() const noexcept { return data_;}
    size_t size() const noexcept { return size_;}
    size_t capacity() const noexcept { return capacity_;}
    bool empty() const noexcept { return size_ == 0;}
};

const size_t string::s_min_capacity = 15;