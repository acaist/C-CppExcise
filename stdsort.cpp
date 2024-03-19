#include<iostream>
#include <vector>
#include <algorithm>

int main()
{
    using std::vector, std::sort, std::stable_sort;
    vector<int> vec = {0,7, 4, 0 , 1, 2};
    sort(vec.begin(), vec.end());
    stable_sort(vec.begin(), vec.end());
    
    for(auto i : vec){
        printf("%d ", i);
    }

}