#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int knapsack(int nW, map<int,int> & rivals, int * weights)
{
	// 2-dimensional DP
	// L(i, j) <-> if it is possible to have a boat with weight j, considering
	// only the pirates in the first i couples of rivals
	bool L[rivals.size() + 1][nW + 1];

	// initialize to false
	for(int i = 0; i <= rivals.size(); i++) {
		for (int j = 0; j <= nW; j++) {
			L[i][j] = false;
		}
	}

	// L(0, 0) = true
	// L(0, j) = false for j != 0
	L[0][0] = true;

	// L(i+1, j) = L(i, j-w[k]) or L(i, j), where k is one of the pirates
	// concerned by the (i+1)-th rivalry
	int jWeight = 0; // How many rivalries have been explored
	for (auto rivalry : rivals) {
		for (int j = 0; j <= nW; j++) {
			if (rivalry.second != -1) {
				if (j - weights[rivalry.first] >= 0) {
					L[jWeight + 1][j] = L[jWeight][j - weights[rivalry.first]]
					                    || L[jWeight + 1][j];
				}
				if (j - weights[rivalry.second] >= 0)
				{
					L[jWeight + 1][j] = L[jWeight][j - weights[rivalry.second]]
					                    || L[jWeight + 1][j];
				}
			}
			else {
				if (j - weights[rivalry.first] >= 0) {
					L[jWeight + 1][j] = L[jWeight][j - weights[rivalry.first]]
					                    || L[jWeight][j];
				}
				else
					L[jWeight + 1][j] = L[jWeight][j];
			}
		}
		jWeight++;
	}

	int nWMax = nW;
	while ((nWMax >= 0) && (!L[rivals.size()][nWMax])) {
		nWMax--;
	}

	return nWMax;
}

int main()
{
	int nN, nR;
	int totalWeight = 0;

	cin >> nN;
	cin >> nR;
	
	int weights[nN];

	for (int i = 0; i < nN; i++) {
		cin >> weights[i];
		totalWeight += weights[i];
	}

	// rivals is a map that contains all rivalries as a unique entry,
	// including x:-1 when x has no rival
	map<int,int> rivals;
	bool hasRival[nN] = {};
	for (int i = 0; i < nR; i++) {
		int nID1, nID2;
		cin >> nID1 >> nID2;

		rivals[min(nID1, nID2)] = max(nID1, nID2);
		hasRival[nID1] = true;
		hasRival[nID2] = true;
	}
	for(int i = 0; i < nN; i++)
		if(!hasRival[i])
			rivals[i] = -1;

	int boatMin = knapsack(totalWeight/2, rivals, weights);

	cout << (totalWeight - 2*boatMin) << endl;
	
	return 0;
}