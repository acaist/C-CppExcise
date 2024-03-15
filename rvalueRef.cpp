#include <iostream>
#include <string>
#include <vector>

//right value referance
void modifyValue(int&& value) {
    value = 10;
}

// Function that takes an rvalue reference
void processString(std::string&& str) {
    std::cout << "Processing string: " << str << std::endl;
    str = " move inside function !";
    // ... Do some processing with the string ...
}

void strRValRef();

void stdmoveStr();

int main() {
    int x = 5;
    modifyValue(std::move(x));//move become r-value
    std::cout << "Modified value: " << x << std::endl;
    
    int arr[4] = {1,2,3,4};
    modifyValue(std::move(arr[1]));

    std::cout << "Modified value: " << arr[1] << std::endl;


    //string
    strRValRef();

    //string move
    stdmoveStr();

    return 0;
}

void strRValRef() 
{
    std::string message = "Hello, world!";

    // Pass an rvalue to the function
    processString(std::move(message));

    // Attempt to use the moved-from object (undefined behavior)
    std::cout << "After move, message: " << message << std::endl;

    return;
}

void stdmoveStr()
{
    using std::string, std::vector, std::cout, std::endl;
    string str = "hello";
    cout << "before str: " << str << endl;

    vector<string> vstr;
    vstr.emplace_back(std::move(str)); //move constor instead of copy constor
    cout << "after  str: " << str << endl;
}