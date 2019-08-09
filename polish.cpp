#include<bits/stdc++.h>
using namespace std;

bool number(string &str){
	if(str == "+" or str == "*" or str == "/" or str == "-") return false;
	return true;
}

int operate(int a,int b,string & str){
	if(str == "+"){
		return a+b;
	}else if(str == "-"){
		return a-b;
	}else if(str == "*"){
		return a*b;
	}else{
		return a/b;
	}
}

int eval(vector<string>& a){
	stack<int> ps;
	stack<pair<string,int>> opr;
	
	for(int i = a.size()-1;i>=0;i--){
		if(!number(a[i])){
			opr.push({a[i],0});
		}else{
			ps.push(stoi(a[i]));
			if(!opr.empty()){
				auto pp = opr.top();
				opr.pop();
				pp.second++;
				opr.push(pp);
			}
			
			while(!opr.empty() && opr.top().second == 2 ){
				int lhs = ps.top();
				ps.pop();
				int rhs = ps.top();
				ps.pop();
				
				int parcial = operate(lhs,rhs,opr.top().first);
				opr.pop();
				
				ps.push(parcial);
				if(!opr.empty()){
					auto pp = opr.top();
					opr.pop();
					pp.second++;
					opr.push(pp);
				}
			}
		}
	}
	
	int ans  = ps.top();
	ps.pop();
	
	return ans;
}


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<string> a = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};
	vector<string> b = {"2", "2", "/"};
	
	cout << eval(a) << endl;
		
	return 0;
}
