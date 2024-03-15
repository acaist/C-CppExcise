#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    double doubleValue[3] = {3.14, 2.7, 1.4};
    float floatArray[3];

    std::copy(doubleValue, doubleValue + 3, floatArray);

    float floatValue = floatArray[2];
    std::cout << "Float value: " << floatValue << std::endl;

    int arr[] = {7, 8, 9, 10, 12, 16};
    
    std::vector<int> vec(std::begin(arr), std::end(arr));
     std::vector<int> vec2(arr, arr+3);
    //std::copy(std::begin(arr), std::end(arr), vec);
    for(auto& i : vec)
        printf(" %d ", i);
    printf("\n");
    for(auto& j : vec2)
        printf(" %d ", j);
    return 0;
}