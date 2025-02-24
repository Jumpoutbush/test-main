#include <cassert>
#include <iostream>
#include <cstring>
#include "note.h"

#define TEST_CASE(name) \
    do { \
        std::cout << "Running test case: " << #name << "..."; \
        test_##name(); \
        std::cout << "PASSED" << std::endl; \
    } while (0)

void test_constructors()
{
    // 默认构造
    string s1;
    assert(s1.empty());
    assert(s1.size() == 0);
    assert(s1.capacity() == 15);
    assert(s1.c_str()[0] == '\0');

    // C风格构造
    string s2("hello");
    assert(s2.size() == 5);
    assert(s2.capacity() >= 5);
    assert(strcmp(s2.c_str(), "hello") == 0);

    char data[] = {'H', 'e', '1', '1', '0'};
    string s3(data, 11);
    assert(s3.size() == 11);
    assert(memcmp(s3.data(), data, 11) == 0);

    try{
        string s3(nullptr);
        assert(false);
    } catch(const std::invalid_argument&) {

    }
}

void test_copy_operations() 
{
    string s1("hello");

    string s2(s1);
    assert(strcmp(s2.c_str(), "hello") == 0);
    assert(s1.c_str() != s2.c_str());

    string s3;
    s3 = s1;
    assert(strcmp(s3.c_str(), "hello") == 0);
    assert(s1.c_str() != s3.c_str());
}

void test_move_operations()
{
    string s1("hello");
    const char* original_data = s1.c_str();
    string s2(std::move(s1));

    assert(s2.c_str() == original_data);
    assert(s1.empty());
    assert(s1.c_str() == nullptr);

    string s3;
    s3 = std::move(s2);

    assert(s3.c_str() == original_data);
    assert(s2.empty());
    assert(s2.c_str() == nullptr);

}

void test_capacity_management()
{
    string s;
    assert(s.capacity() == 15);

    s.reserve(20);
    assert(s.capacity() >= 20);

    s.append("hello");
    size_t cap = s.capacity();
    s.shrink_to_fit();
    assert(s.capacity() == 15);
    
}

void test_append_operations()
{
    string s;
    s.append("hello");
    assert(strcmp(s.c_str(), "hello") == 0);

    s += " world";
    assert(strcmp(s.c_str(), "hello world") == 0);
}

void test_edge_cases()
{
    string s1("");
    assert(s1.size() == 0);
    assert(s1.c_str()[0] == '\0');

    std::string long_str(1000, 'x');
    string s2(long_str.c_str());
    assert(s2.size() == 1000);
    assert(memcmp(s2.data(), long_str.c_str(), 1000) == 0);
}

int main()
{
    TEST_CASE(constructors);
    TEST_CASE(copy_operations);
    TEST_CASE(move_operations);
    TEST_CASE(capacity_management);
    TEST_CASE(append_operations);
    TEST_CASE(edge_cases);
    std::cout << "\nAll tests passed" << std::endl;
    getchar();
    return 0;
}