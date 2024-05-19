#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int sister[3];
	int prince[2];
	int cards[53];
	int waste[3];

	while(cin >> sister[0] >> sister[1] >> sister[2] >> prince[0] >> prince[1],\
		sister[0] || sister[1] || sister[2] || prince[0] || prince[1]){
		int loss = 0;
		
		memset(cards,0,sizeof(cards));
		memset(waste,0,sizeof(waste));
		
		for(int i=0;i<3;i++){
			cards[sister[i]] = 1;
		}	
	
		for(int i=0;i<2;i++){
			cards[prince[i]] = 1;	
		}

		sort(sister,sister+3);
		sort(prince,prince+2);
	
		for(int i=1;i>=0;i--){
			int worst_case = 0x3f3f3f3f;

			for(int j=0;j<=2;j++){
				if(sister[j] > prince[i] && !waste[j]){
					worst_case = j;
					break;
				}
			}

			if(worst_case != 0x3f3f3f3f){
				loss++;
				waste[worst_case] = 1;
			}
		}
		
		if(loss >= 2) cout << -1 << endl;
		else if(loss == 0){
			for(int i=1;i<=52;i++){
				if(!cards[i]){
					cout << i << endl;
					break;
				}
			}
		}else{
			bool found = false;
			int card = -1;
			for(int i=2;i>=0;i--){
				if(!waste[i]){
					for(int j = sister[i];j<=52;j++){
						if(!cards[j]){
							card = j;
							found = true;
							break;
						}
					}
					break;
				}
			}

			if(!found) cout << -1 << endl;
			else cout << card << endl;
		}
	}
	
	return 0;
}