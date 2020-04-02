#include<bits/stdc++.h>
using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);

	int t;

	cin >> t;

	while(t--){
		bool finish = false;
		bool finish_print = false;
		int place[101]; 
		int players,rolls,sorl;
		int player = 1;
		vector<int> state;

		memset(place,-1,sizeof(place));

		cin >> players >> sorl >> rolls;

		state.resize(players,1);

		for(int i=0;i<sorl;i++){
			int b,e;

			cin >> b >> e;

			place[b] = e;
		}


		for(int i=0;i<rolls;i++){
			int dice;

			cin >> dice;

			if(!finish){
				state[player-1] += dice;

				if(place[state[player-1]] != -1){
					state[player-1] = place[state[player-1]];
				}

				if(state[player-1] >= 100){
					   	finish = true;
						state[player-1] = 100;
				}

				player = (player%players) + 1;
			}else continue;
		}

		for(int i=0;i<players;i++){
			cout << "Position of player " << (i+1) << " is " << state[i] << "." << endl;
		}
	}
	
	return 0;
}
