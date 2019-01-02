#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

	/*vectorは動的配列。 data[3]を宣言して値を全部2で初期化してるのと同じ*/
	vector<int>data(3,2);


	for(int i = 0;i < 3;i++){
		cout << data[i];
	}
	
	return 0;	
}