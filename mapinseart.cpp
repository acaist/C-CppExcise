#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
   cout << "Hello World\n";
	
	vector<int> veci={1,2,3,4,5};
	vector<int> veci2={11,21, 31, 41, 51};
    vector<int> veci3={31,41, 51, 61, 71};
	
	unordered_map<string, vector<int>> table;
	table.emplace("vi",veci);
	cout<< "vector[2] = "<<(table.find("vi")->second)[2]<<endl;
	
	table.emplace("vi emplace",veci2);
	cout<< "vector[2] = "<<(table.find("vi")->second)[2]<<endl;

    table["vi"] = veci3;
	cout<< "vector[2] = "<<(table.find("vi")->second)[2] <<endl;
	
   return 0;
}