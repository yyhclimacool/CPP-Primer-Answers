#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<string> story = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	vector<string> new_story;
	sort(story.begin(), story.end());
	unique_copy(story.cbegin(), story.cend(), back_inserter(new_story));
	for(const auto & e : new_story)
		cout << e << '\t';
	cout << endl;
	return 0;
}
