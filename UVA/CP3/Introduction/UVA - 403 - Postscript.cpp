#include<bits/stdc++.h>
using namespace std;

void print(const vector<string>& paper){
	string dashes(60,'-');
	for(int i=0;i<paper.size();i++){
		cout << paper[i] << endl;
	}
	cout << endl;
	cout << dashes << endl;
	cout << endl;
}

vector<string> process_font(const string& font,const string& txt){
	if(font == "C1"){
		vector<string> ret {{txt.substr(1,txt.size()-2)}};

		return ret;
	}else if(font == "C5"){
		vector<string> alf = {".***..****...****.****..*****.*****..****.*...*.*****.",
							  "*...*.*...*.*...*.*...*.*.....*.....*.....*...*...*...",
							  "*****.****..*.....*...*.***...***...*..**.*****...*...",
							  "*...*.*...*.*.....*...*.*.....*.....*...*.*...*...*...",
							  "*...*.****...****.****..*****.*......***..*...*.*****.",
							  "..***.*...*.*.....*...*.*...*..***..****...***..****..",
							  "...*..*..*..*.....**.**.**..*.*...*.*...*.*...*.*...*.",
							  "...*..***...*.....*.*.*.*.*.*.*...*.****..*...*.****..",
							  "*..*..*..*..*.....*...*.*..**.*...*.*.....*..**.*..*..",
							  ".**...*...*.*****.*...*.*...*..***..*......****.*...*.",
							  ".****.*****.*...*.*...*.*...*.*...*.*...*.*****.......",
							  "*.....*.*.*.*...*.*...*.*...*..*.*...*.*.....*........",
							  ".***....*...*...*..*.*..*.*.*...*.....*.....*.........",
							  "....*...*...*...*..*.*..**.**..*.*....*....*..........",
							  "****...***...***....*...*...*.*...*...*...*****......."};

		vector<string> ret(5,"");
		string txt2{txt.substr(1,txt.size()-2)};

		for(auto& it:txt2){
			if(it == ' '){
				for(int i=0,j=10;i<5;i++,j++){
					ret[i] += alf[j].substr(54-6,6);
				}
			}else{
				if('A' <= it && it <= 'I' ){
					for(int i=0,j=0;i<5;i++,j++){
						ret[i] += alf[j].substr((it-'A')*6,6);
					}
				}else if('J' <= it && it <= 'R'){
					for(int i=0,j=5;i<5;i++,j++){
						ret[i] += alf[j].substr((it-'A'+1)*6-60,6);
					}
				}else if ('S' <= it && it <= 'Z'){
					for(int i=0,j=10;i<5;i++,j++){
						ret[i] += alf[j].substr((it-'A'+2)*6-120,6);
					}
				}
			}
		}

		return ret;
	}
}

void place(vector<string> & paper,const string&font,int r,int c,const vector<string> & txt,const char j = 'l'){
	if(j == 'l'){
		for(int i=r,i2=0;i2<txt.size() && i<60;i++,i2++){
			for(int j=c,j2=0;j2<txt[i2].size() && j<60;j++,j2++){
				if(font == "C1"){
					if(txt[i2][j2] != ' ') paper[i][j] = txt[i2][j2];
				}else{
					if(txt[i2][j2] != '.') paper[i][j] = txt[i2][j2];
				}	
			}
		}
	}else if(j == 'r'){
		for(int i=r,i2=0;i2<txt.size() && i<60;i++,i2++){
			for(int j=c,j2=txt[i2].size()-1;j2>=0 && j>=0;j--,j2--){
				if(font == "C1"){
					if(txt[i2][j2] != ' ') paper[i][j] = txt[i2][j2];
				}else{
					if(txt[i2][j2] != '.') paper[i][j] = txt[i2][j2];
				}	
			}
		}
	}else if(j == 'c'){	
		for(int i=r,i2=0;i2<txt.size() && i<60;i++,i2++){
			for(int j=29,j2=(txt[i2].size()>>1)-1;j2>=0 && j>=0;j--,j2--){
				if(font == "C1"){
					if(txt[i2][j2] != ' ') paper[i][j] = txt[i2][j2];
				}else{
					if(txt[i2][j2] != '.') paper[i][j] = txt[i2][j2];
				}
			}
		}


		for(int i=r,i2=0;i2<txt.size() && i<60;i++,i2++){
			for(int j=30,j2=(txt[i2].size()>>1);j2<txt[i2].size() && j<60;j++,j2++){
				if(font == "C1"){
					if(txt[i2][j2] != ' ') paper[i][j] = txt[i2][j2];
				}else{
					if(txt[i2][j2] != '.') paper[i][j] = txt[i2][j2];
				}	
			}
		}
	}
}

vector<string> new_paper(void){
	vector<string> paper;

	for(int i=0;i<60;i++){
		string dots(60,'.');

		paper.push_back(dots);
	}

	return paper;	
}

vector<string> slipt(const string& inp, const char& de){
	string buffer = "";
	vector<string> ret;

	for(auto&it:inp){
		if(it != de) buffer += it;
		else if(it == de && buffer != ""){
			ret.push_back(buffer);
			buffer = "";
		}
	}

	if(buffer != ""){
		ret.push_back(buffer);
	}

	return ret;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(0);
	string input;
	vector<string> paper = new_paper();

	while(getline(cin,input)){
		string comm = input.substr(0,2);

		if(comm == ".P"){
			string left_input = input.substr(0,input.find_first_of("|"));
			string txt = input.substr(input.find_first_of("|"),input.size()-input.find_first_of("|"));
			vector<string> op = slipt(left_input,' ');
			int r = stoi(op[2]) - 1, c = stoi(op[3]) - 1;

			place(paper,op[1],r,c,process_font(op[1],txt));
		}else if(comm  == ".L"){
			string left_input = input.substr(0,input.find_first_of("|"));
			string txt = input.substr(input.find_first_of("|"),input.size()-input.find_first_of("|"));
			vector<string> op = slipt(left_input,' ');
			int r = stoi(op[2]) - 1 , c = 0;

			place(paper,op[1],r,c,process_font(op[1],txt));
		}else if(comm == ".R"){
			string left_input = input.substr(0,input.find_first_of("|"));
			string txt = input.substr(input.find_first_of("|"),input.size()-input.find_first_of("|"));
			vector<string> op = slipt(left_input,' ');
			int r = stoi(op[2]) - 1 , c = 59;

			place(paper,op[1],r,c,process_font(op[1],txt),'r');
		}else if(comm == ".C"){
			string left_input = input.substr(0,input.find_first_of("|"));
			string txt = input.substr(input.find_first_of("|"),input.size()-input.find_first_of("|"));
			vector<string> op = slipt(left_input,' ');
			int r = stoi(op[2]) - 1, c = (((int)(txt.size()-2))&1) ? 1:0;
			
			place(paper,op[1],r,c,process_font(op[1],txt),'c');
		}else{
			print(paper);
			paper = new_paper();
		}
	}

	return 0;
}
