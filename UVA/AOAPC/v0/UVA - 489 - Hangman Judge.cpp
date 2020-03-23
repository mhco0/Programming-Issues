#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int rnd;

	while(cin >> rnd , rnd != -1){
		string ans,guess;
		int wrds = 0;
		int right = 0;
		int wrong = 0;
		bool right_wrds[128],guess_wrds[128];
		memset(right_wrds,false,128*sizeof(bool));
		memset(guess_wrds,false,128*sizeof(bool));

		cin >> ans >> guess;
		for(auto&it:ans){
			if(!right_wrds[it-'a']){
				right_wrds[it-'a'] = true;
				wrds++;
			}
		}

		for(auto&it:guess){
			if(!guess_wrds[it-'a']){
				guess_wrds[it-'a'] = true;
				if(right_wrds[it-'a']){
					right++;
					if(right == wrds and wrong < 7){
						break;
					}
				}else{
					wrong++;
					if(wrong == 7){
						break;
					}
				}
			}
		}

		cout << "Round " << rnd << endl;

		if(right == wrds){
			cout << "You win." << endl;
		}else if(wrong >= 7){
			cout << "You lose." << endl;
		}else{
			cout << "You chickened out." << endl;
		}
	}

	return 0;
}
