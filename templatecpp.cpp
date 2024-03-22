#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printVector(const T& vec) {
    for (int i=0; i< vec.size(); ++i) {
        std::cout << vec[i] << ' ';
        //printf(" %g ", (float)vec[i] );
    }
    std::cout << std::endl;
}

int main() {

    {
        std::vector<int> intVec = {17, 2, 31, 4, 25};
        std::vector<std::string> stringVec = {"Hello", "bro"};

        printVector(intVec);        // Prints: 1 2 3 4 5
        printVector(stringVec);     // Prints: Hello World
    }

	return 0;
}