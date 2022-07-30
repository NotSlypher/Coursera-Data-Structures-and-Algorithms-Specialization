#include <iostream>
#include <string>
#include <vector>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
	int n = str1.length(), m = str2.length();
	std::vector<std::vector<int>> dp(n + 1);
  for (int i = 0; i <= n; ++i)
	  for (int j = 0; j <= m; ++j)
		  dp[i].push_back(j);

  for (int i = 0; i < n + 1; ++i)
	  dp[i][0] = i;
  for (int i = 0; i < m + 1; ++i)
	  dp[0][i] = i;

  for (int i = 1; i < n + 1; ++i)
  {
	  for (int j = 1; j < m + 1; ++j)
	  {
		  if (str1[i - 1] == str2[j - 1])
			  dp[i][j] = dp[i - 1][j - 1];
		  else
			  dp[i][j] = std::min(dp[i - 1][j] + 1,std::min(1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]));
	  }
  }
  return dp[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
