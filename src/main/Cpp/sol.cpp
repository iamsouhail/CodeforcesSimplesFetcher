#include <bits/stdc++.h>
using namespace std;
double q=0;
bool issquare(long x){
	double d = x;
	q = sqrt((double)d);
	return d == (floor(q)*floor(q));
}
int main() {
	long n;
	cin>>n;
	
	
	if(issquare(n)){
		cout<<(floor(q))*2;
	} else {
		if((q - floor(q))<(ceil(q) - q))
			cout<<(2*floor(q) + 1)<<endl;
		else 
			cout<<(2*(floor(q)+1));
	}

	
    return 0;
}