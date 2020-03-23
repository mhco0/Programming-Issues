#include<bits/stdc++.h>
using namespace std;

long long int show_steps(long long int & a,long long int &l, int steps){
	if(a == 1){
		return steps;
	}else if(!(a&1)){
		a = a/2;
		return show_steps(a,l,steps+1);
	}else{
		a = 3*a + 1LL;
		if(a>l)	return steps;
		else return show_steps(a,l,steps+1);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int a,l,cases = 1;

	while(cin >> a >> l, a != -1 or l != -1){
		cout <<"Case "<< cases << ": A = " << a << ", limit = " << l << ", number of terms = "<<  show_steps(a,l,1) << endl;
		cases++;
	}

	return 0;
}
