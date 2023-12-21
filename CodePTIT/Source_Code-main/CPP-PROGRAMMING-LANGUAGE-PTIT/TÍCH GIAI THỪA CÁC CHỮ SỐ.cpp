#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		string a;
		cin >> a;
		string ans ="";
		for(long long i = 0; i <a.size(); i++){
			if(a[i] == '1' || a[i] == '0')
				continue;
			if(a[i] == '2') ans += '2';
		else if(a[i] == '3') ans += '3';
		else if(a[i] == '4') ans += "223";
		else if(a[i] == '5') ans += '5';
		else if(a[i] == '6') ans += "35";
		else if(a[i] == '7') ans += '7';
		else if(a[i] == '8') ans += "2227";
		else if(a[i] == '9') ans += "3327";
		}		
		sort(begin(ans), end(ans), greater<char>());
		cout << ans << endl;
	}
	return 0;
}