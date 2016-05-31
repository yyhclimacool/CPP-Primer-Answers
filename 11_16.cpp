#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main(){
	map<string, int> mp = {{"kevin", 12}, {"fine", 13}, {"docker", 8}};
	for(auto it = mp.begin(); it != mp.end(); ++it)
		it->second = 1;
	return 0;
}
