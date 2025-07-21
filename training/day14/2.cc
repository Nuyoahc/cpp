#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int t; cin >> t;
	vector<int> a(t * 3);
	for (int i = 0; i < t * 3; i++) cin >> a[i];

	sort(a.begin(), a.end());
	long long sum = 0;
	int n = a.size();
	int j = n / 3;
	int k = 0;
	for (int i = n - 2; k < j; k++, i -= 2)
	{
		sum += a[i];
	}
	cout << sum << endl;

	return 0;
}
