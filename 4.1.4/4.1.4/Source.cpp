#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;


class Solution{
public :
	double calcualte(vector<string> & tokens){
		stack<string> st;
		for (auto token : tokens){
			if (!isOperator(token)){
				st.push(token);
			}
			else{
				string right = st.top();
				st.pop();
				int rightNum = stoi(right);
				string left = st.top();
				st.pop();
				int leftNum = stoi(left);
				int result = 0;
				if (token == "+") result = leftNum + rightNum;
				else if (token == "-") result = leftNum + rightNum;
				else if (token == "*") result = leftNum*rightNum;
				else result = leftNum/rightNum;
				st.push(to_string(result));
			}
		}
		return stoi(st.top());
	}

private:
	bool isOperator(string & token){
		return token.size() == 1 && string("+-*/").find(token) != string::npos;
	}
};

void main(){
	Solution s;
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	cout<<s.calcualte(tokens)<<endl;
}