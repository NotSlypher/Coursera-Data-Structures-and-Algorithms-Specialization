#include <iostream>
#include <vector>

int get_change(int m) {
	std::vector<int> coins(m+1);
	int deno[3] = {1,3,4};
	coins[0] = 0;
	for(int i = 1; i <= m;i++)
	{
		coins[i] = 3001;
		for(int j = 0; j<3;j++)
		{
			if (i>=deno[j])
			{
				int x = coins[i - deno[j]] + 1;
				if (x < coins[i])
					coins[i] = x;
			}
		}
	}
	return coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
