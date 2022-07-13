#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if ((double)a.first / (double)a.second >= (double)b.first / (double)b.second)
		return false;
	else
		return true;
}

double get_optimal_value(int capacity, vector<pair<int, int>> loot, int n)
{
	if (capacity == 0 || loot.empty())
		return 0;
	// write your code here
	double amount = min((loot.begin() + n - 1)->second, capacity);
	capacity -= amount;
	double value = (loot.begin() + n - 1)->first * amount / (loot.begin() + n - 1)->second;
	loot.pop_back();
	return value + get_optimal_value(capacity, loot, n - 1);
}

int main()
{
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<pair<int, int>> loot;
	for (int i = 0; i < n; i++)
	{
		int t1, t2;
		std::cin >> t1 >> t2;
		loot.emplace_back(make_pair(t1, t2));
	}
	sort(loot.begin(), loot.end(), cmp);
	double optimal_value = get_optimal_value(capacity, loot, n);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
