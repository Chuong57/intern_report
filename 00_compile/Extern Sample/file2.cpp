#include <bits/stdc++.h>
#include "file1.hpp"

extern int global_var;
int SomeFunction();

int main(){
    global_var = 10;
    std::cout<<global_var;
    SomeFunction();
    return 0;
}