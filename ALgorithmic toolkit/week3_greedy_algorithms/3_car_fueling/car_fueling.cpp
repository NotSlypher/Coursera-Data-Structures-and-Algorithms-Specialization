#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int currpos = 0, cnt = 0, currstop = 0, i = 0;
    bool flag = 0;
    stops.push_back(dist);
    while(currpos < dist)
    {
        while (i < stops.size() and stops[i] - currstop <= tank) {
            i++;
            flag = true;
        }
        if (flag) {
            if (i == stops.size()) break;
            currstop = stops[i - 1];
            currpos = currstop;
            cnt ++;
        }
        else {
            return -1;
        }
        flag = false;
    }
    return cnt;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
