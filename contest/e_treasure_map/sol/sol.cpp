#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Treasure{
	int weight;
	int bridge; // strength of the bridge between the treasure and its parent
	vector<int> children;
};


// Recursively get the biggest amount of gold we can get at a given node
int most_gold(const vector<Treasure> &treasures, int position){
	if(treasures[position].children.size()==0){
		return treasures[position].weight;
	}else{
		int sum=0;
		for(auto child:treasures[position].children){
			sum += min( most_gold(treasures, child), treasures[child].bridge );		
		}
		sum += treasures[position].weight;
		return sum;
	}		
}

// Read input and construct the tree
int main(){
	vector<Treasure> treasures;

	int n;
	cin >> n;
	treasures.resize(n);
	for(int i=0; i<n; ++i){
		cin >> treasures[i].weight;
	}

	for(int i=1; i<n; ++i){
		int child, parent, bridge;
		cin >> parent >> child >> bridge;
		
		treasures[parent].children.push_back(child);
		treasures[child].bridge = bridge;
	}

	cout << most_gold(treasures, 0) << endl;

	return 0;
}
