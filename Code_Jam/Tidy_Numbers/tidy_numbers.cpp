/*
A very nice problem that asks to find the last maximum "tidy" number(The digits from left to right be in ascending order),
smaller than the given number.

Author of this file:Lazaros Zervos
Use this code only for educational purposes.

Copyright@ 2018
*/



#include <iostream>
#include <string>
#include <vector>
#include <cstdbool>
#include <bits/stdc++.h>

using namespace std;





int main(void)	 {

  int No_Of_Trial;
  cin>>No_Of_Trial;

  for(int i=1; i<=No_Of_Trial; i++)  {
	long int tidy_number;

	long int number;	
	cin>>number;


	vector<long int> v;
	long int copy=number;
	while(copy/10 !=0) {
		int last_digit=copy%10;
		v.push_back(last_digit);
		copy=copy/10;
	}
	v.push_back(copy);
	reverse(v.begin(),v.end());

	int rem;
	bool flag=true;
	if(number/10==0){
	 cout<<"Case #"<<i<<": "<<number<<endl;
	 continue;
	}

	for(int z=0; z<v.size()-1; z++) {
		if(v[z]>v[z+1]) {
		  if(flag==false) {
			v[rem]-=1;
			for(int j=rem+1; j<v.size(); j++) {
					v[j]=9;
			}
			break;
		  }
		  else {
			v[z]-=1;
			for(int j=z+1; j<v.size(); j++) {
				v[j]=9;
			}
			break;
		  }
		}
		else if(v[z]==v[z+1] &&  flag==true) {
			rem=z;
			flag=false;
		}
		else if(v[z]<v[z+1]) {
		  flag=true;
		}
   }
   string s;
   for(int j=0; j<v.size(); j++){
	  s+=to_string(v[j]);
   }
   tidy_number=stol(s);
   cout<<"Case #"<<i<<": "<<tidy_number<<endl;
   v.clear();
 }
}

