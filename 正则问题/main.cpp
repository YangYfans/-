#include <iostream>
using namespace std;
string s;
int pos = 0;

int dfs()
{
	int tmp = 0, ans = 0;
	int len = s.size();
	while (pos < len)
	{
		if (s[pos] == '(') { pos++; tmp += dfs(); }
		else if (s[pos] == ')') { break; }
		else if (s[pos] == '|') { pos++; ans = max(ans, tmp); tmp = 0; }
		else { pos++; tmp++; }
	}
	ans = max(ans, tmp);
	return ans;
}

int main()
{
	cin >> s;
	int s = dfs();
	cout << s << endl;
	return 0;
}