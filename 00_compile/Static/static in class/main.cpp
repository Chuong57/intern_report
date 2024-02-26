#include <bits/stdc++.h>

class SomeClass{
public:
    int non_static_var;
    static int static_var;
    static void static_function(){
        //non_static_var = 10; //uncomment this and it will cause error: non static member can not be accessed by static memeber.
        static_var = 20;
        std::cout<<static_var; 
    }
};

int SomeClass::static_var = 0;

int main(){
    SomeClass::static_function();
    return 0;
}