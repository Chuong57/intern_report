#include "static_function.hpp"

void NormalFunctions();
//static void StaticFunctions(); //uncomment this and it will cause error: Static function can not be accessed by other files than its file (internal link)

int main(){
    NormalFunctions();
    //StaticFunctions(); //uncomment this and it will cause error
    return 0;
}