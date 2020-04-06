#include<bits/stdc++.h>
using namespace std;

char processed_chess[8][8];
int chess[8][8];
int ok = 64;

void remove_ok(char piece,int i,int j){
	bool black = false;
	
	if(!isupper(piece)){
		black = true;
		piece = toupper(piece);
	}

	switch(piece){	
		case 'P':
			if(black){
				if(i != 7){
					if(j != 0){
		 				if(!chess[i+1][j-1]){
		 					chess[i+1][j-1] = 1;
 							ok--;
 						}
 					}

 					if(j != 7){
		 				if(!chess[i+1][j+1]){
		 					chess[i+1][j+1] = 1;
 							ok--;
 						}
 					}
				}
			}else{
				if(i != 0){
					if(j != 0){
						if(!chess[i-1][j-1]){
							chess[i-1][j-1] = 1;
							ok--;
						}
					}

					if(j != 7){
						if(!chess[i-1][j+1]){
							chess[i-1][j+1] = 1;
							ok--;
						}
					}
				}
			}
		break;
		case 'R':
			for(int j2=j;j2<8;j2++){
				if(!chess[i][j2]){
					chess[i][j2] = 1;
					ok--;
				}else if(j2 == j) continue;
				else if(processed_chess[i][j2] == ' ') continue;
				else break;
			}

			for(int j2=j;j2>=0;j2--){
				if(!chess[i][j2]){
					chess[i][j2] = 1;
					ok--;
				}else if(j2 == j) continue;
				else if(processed_chess[i][j2] == ' ') continue;
				else break;
			}

			for(int i2=i;i2<8;i2++){
				if(!chess[i2][j]){
					chess[i2][j] = 1;
					ok--;
				}else if(i2 == i) continue;
				else if(processed_chess[i2][j] == ' ') continue;
				else break;
			}

			for(int i2=i;i2>=0;i2--){
				if(!chess[i2][j]){
					chess[i2][j] = 1;
					ok--;
				}else if(i2 == i) continue;
				else if(processed_chess[i2][j] == ' ') continue;
				else break;
			}
		break;
		case 'N':
			if(j+2 < 8 && i-1 >= 0){
				if(!chess[i-1][j+2]){
					chess[i-1][j+2] = 1;
					ok--;
				}
			}

			if(j+1 < 8 && i-2 >= 0){
				if(!chess[i-2][j+1]){
					chess[i-2][j+1] = 1;
					ok--;
				}
			}

			if(j+2 < 8 && i+1 < 8){
				if(!chess[i+1][j+2]){
					chess[i+1][j+2] = 1;
					ok--;
				}
			}

			if(j+1 < 8 && i+2 < 8){
				if(!chess[i+2][j+1]){
					chess[i+2][j+1] = 1;
					ok--;
				}
			}

			if(j-1 >= 0 && i+2 < 8){
				if(!chess[i+2][j-1]){
					chess[i+2][j-1] = 1;
					ok--;
				}
			}
	
			if(j-2 >= 0 && i+1 < 8){
				if(!chess[i+1][j-2]){
					chess[i+1][j-2] = 1;
					ok--;
				}
			}

			if(j-2 >= 0 && i-1 >= 0){
				if(!chess[i-1][j-2]){
					chess[i-1][j-2] = 1;
					ok--;
				}
			}

			if(j-1 >= 0 && i-2 >= 0){
				if(!chess[i-2][j-1]){
					chess[i-2][j-1] = 1;
					ok--;
				}
			}
		break; 
		case 'B':
			for(int i2=i,j2=j;i2 >= 0 && j2 >= 0;i2--,j2--){
				if(!chess[i2][j2]){
					chess[i2][j2] = 1;
					ok--;
				}else if(i2 == i && j2 == j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
			}

			for(int i2=i,j2=j;i2 >= 0 && j2 < 8;i2--,j2++){
				if(!chess[i2][j2]){
					chess[i2][j2] = 1;
					ok--;
				}else if(i2 == i && j2 == j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
			}

			for(int i2=i,j2=j;i2 < 8 && j2 >=0;i2++,j2--){
				if(!chess[i2][j2]){
					chess[i2][j2] = 1;
					ok--;
				}else if(i2 == i && j2 == j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
			}

			for(int i2=i,j2=j;i2 < 8 && j2 < 8;i2++,j2++){
				if(!chess[i2][j2]){
					chess[i2][j2] = 1;
					ok--;
				}else if(i2 == i && j2 == j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
			}
		break;
		case 'Q':
			for(int i2=i,j2=j;i2 >= 0 && j2 >= 0;i2--,j2--){
				if(!chess[i2][j2]){
					chess[i2][j2] = 1;
					ok--;
				}else if(i2 == i && j2 == j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
			}

			for(int i2=i,j2=j;i2 >= 0 && j2 < 8;i2--,j2++){
				if(!chess[i2][j2]){
					chess[i2][j2] = 1;
					ok--;
				}else if(i2 == i  && j2 == j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
	        }

			for(int i2=i,j2=j;i2 < 8 && j2 >=0;i2++,j2--){
	            if(!chess[i2][j2]){
	               	chess[i2][j2] = 1;
	                ok--;
	            }else if(i2 == i && j2 == j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
	       	} 

	        for(int i2=i,j2=j;i2 < 8 && j2 < 8;i2++,j2++){
	           	if(!chess[i2][j2]){
	               	chess[i2][j2] = 1;
	                ok--;
	           	}else if(i2 == i && j2 ==j) continue;
				else if(processed_chess[i2][j2] == ' ') continue;
				else break;
			}

			for(int j2=j;j2<8;j2++){
				if(!chess[i][j2]){
		 			chess[i][j2] = 1;
 					ok--;
 				}else if(j2 == j) continue;
				else if(processed_chess[i][j2] == ' ') continue;
 				else break;
			}

			for(int j2=j;j2>=0;j2--){
		 		if(!chess[i][j2]){
		 			chess[i][j2] = 1;
 					ok--;
 				}else if(j2 == j) continue;
				else if(processed_chess[i][j2] == ' ') continue;
 				else break;
 			}

			for(int i2=i;i2<8;i2++){
				if(!chess[i2][j]){
		 			chess[i2][j] = 1;
 					ok--;
 				}else if(i2 == i) continue;
				else if(processed_chess[i2][j] == ' ') continue;
 				else break;
			}
			
			for(int i2=i;i2>=0;i2--){
		 		if(!chess[i2][j]){
		 			chess[i2][j] = 1;
 					ok--;
 				}else if(i2 == i) continue;
				else if(processed_chess[i2][j] == ' ') continue;
 				else break;
 			}

		break;
		case 'K':
			if(i != 0){
				if(!chess[i-1][j]){
					chess[i-1][j] = 1;
					ok--;
				}
			}

			if(i != 7){		
				if(!chess[i+1][j]){
					chess[i+1][j] = 1;
					ok--;
				}
			}

			if(j != 0){
				if(!chess[i][j-1]){
					chess[i][j-1] = 1;
					ok--;
				}
			}

			if(j != 7){
				if(!chess[i][j+1]){
					chess[i][j+1] = 1;
					ok--;
				}
			}

			if(i != 0 && j != 0){
				if(!chess[i-1][j-1]){
					chess[i-1][j-1] = 1;
					ok--;
				}
			}

			if(i != 0 && j != 7){
				if(!chess[i-1][j+1]){
					chess[i-1][j+1] = 1;
					ok--;
				}
			}

			if(i != 7 && j != 7){
				if(!chess[i+1][j+1]){
					chess[i+1][j+1] = 1;
					ok--;
				}
			}

			if(i != 7 && j != 0){
				if(!chess[i+1][j-1]){
					chess[i+1][j-1] = 1;
					ok--;
				}
			}
		break;
	}
}


void process_input(string& input,int i,int j){
	for(auto&it:input){
		if(isdigit(it)){
			j += it-'0';
		}else if(it == '/'){
			i++;
			j = 0;
		}else{
			processed_chess[i][j] = it;
			chess[i][j] = 1;
			ok--;
			j++;
		}
	}

	for(int i2=0;i2<8;i2++){
		for(int j2=0;j2<8;j2++){
			remove_ok(processed_chess[i2][j2],i2,j2);
		}
	}
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	string input;

	while(getline(cin,input)){
		ok = 64;
		memset(processed_chess,' ',sizeof(processed_chess));
		memset(chess,0,sizeof(chess));
		process_input(input,0,0);
		cout << ok << endl;
	}

	return 0;
}
