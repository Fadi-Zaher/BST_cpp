#include<iostream>
#include<bitset>

using namespace std;


typedef bitset<9> Mask;

int main() {

	Mask has_a;
	cin>>has_a;
	Mask result;
	for (int i = has_a.size()-1; i >= 0; i--)
		result[has_a.size()-1 - i]=has_a[i];

	cout<<result<<endl;
	return 0;
}