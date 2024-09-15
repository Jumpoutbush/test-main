//: C16:fibonacci.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Fibonacci number generator
int fibonacci(int n){
    int c, a = 1, b = 1;
    if(n < 1){
        return 0;
    }if(n == 1 || n == 2){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
} ///:~