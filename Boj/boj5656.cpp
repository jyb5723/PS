#pragma once 
#include<iostream>
#include<string>
using namespace std; 

string num1, num2; 
int testCase = 1;

string get_Operation(string Original) {
	int lng = Original.length();
	string oper; int pt = 0; 
	for (int i = 0; i < lng; i++) {
		if (Original[i] == ' ') {
			i++;
			while (Original[i] != ' ')
				oper.push_back(Original[i]), i++;
			pt = i; 
			break;
		}
		else
			num1.push_back(Original[i]); 
	}
	while (pt < lng) 
		num2.push_back(Original[pt]), pt++; 
	return oper; 
}


string Result(string oper) {
	string result = "Case ";
	string testNum; int tmp = testCase; 
	while (tmp) {
		testNum = (char)('0' + (tmp % 10)) + testNum;
		tmp /= 10; 
	}
	result += testNum; 
	result += ": ";
	int A = atoi(num1.c_str());
	int B = atoi(num2.c_str()); 
	string Judge; 
	if (oper == "!=") 
		Judge = (A != B) ? "true" : "false"; 
	else if (oper == "==") 
		Judge = (A == B) ? "true" : "false";
	else if (oper == "<") 
		Judge = (A < B) ? "true" : "false";
	else if (oper == ">") 
		Judge = (A > B) ? "true" : "false";
	else if (oper == ">=") 
		Judge = (A >= B) ? "true" : "false";
	else if (oper == "<=") 
		Judge = (A <= B) ? "true" : "false";
	result = result + Judge;
	return result; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL), cout.tie(NULL);
	string str; 
	getline(cin, str); 
	string oper; 
	while ((oper = get_Operation(str)) != "E") {
		cout << Result(oper) << '\n';
		testCase++; 
		num1.clear(); num2.clear(); 
		getline(cin, str); 
		
	}
	return 0; 
}