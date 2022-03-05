#pragma once
#include <sstream>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>
#include <charconv>
#define MAX_STACK 100
class Parser
{
    public:
    Parser()
    :equation(), str_num()
    {
        value = 0;
    }


    void replaceX(std::string equa, float num)
    {
        std::string::size_type index = std::string::npos;
        if ((index = equa.rfind("x")) != std::string::npos)
            equa.replace(index, 1, std::to_string(num));
    
        equation = equa;
    }

    void infixToRPN(std::string& infix)
    {
        const std::string ops = "_+/*^";
        std::stringstream ss;
        std::stack<int> s;
 
        std::stringstream ssinput(infix);
        std::string token;
        while (std::getline(ssinput, token, ' ')) {
            if (token.empty()) {
                continue;
            }
            char c = token[0];
            size_t idx = ops.find(c);
 
        // check for operator
            if (idx != std::string::npos) 
            {
                while (!s.empty()) {
                    int prec2 = s.top() / 2;
                    int prec1 = idx / 2;
                    if (prec2 > prec1 || (prec2 == prec1 && c != '^')) {
                        ss << ops[s.top()] << ' ';
                        s.pop();
                    } else break;
            }
            s.push(idx);
            } 
            else if (c == '(') 
            {
                s.push(-2); // -2 stands for '('
            } 
             else if (c == ')') {
                // until '(' on stack, pop operators.
                while (s.top() != -2) {
                    ss << ops[s.top()] << ' ';
                    s.pop();
                }
                s.pop();
        } 
        else {
            ss << token << ' ';
        }
    }
 
    while (!s.empty()) {
        ss << ops[s.top()] << ' ';
        s.pop();
    }
 
    equation = ss.str();
    }
    void RPN(std::string expression)
    {
	    int i = 0;
	    float v1, v2, ret;
	    v1 = ret = v2 = 0.0;

	    std::string tok = "";

	while (i < expression.length()){
		//Skip white space
		while (isspace(expression[i])){
			i++;
		}
		//Check for digits and .
		if (isdigit(expression[i]) | expression[i] == '.' | expression[i] == '-'){
			while (isdigit(expression[i]) | expression[i] == '.' | expression[i] == '-'){
				tok += expression[i];
				i++;
			}
			//Push on stack number.
			Push(atof(tok.c_str()));
			tok = "";
		}
		//Check for operator
		else if (IsOp(expression[i])){
			if (expression[i] == '+'){
				v1 = Pop();
				v2 = Pop();
				ret = (v1 + v2);
			}
			if (expression[i] == '_'){
				v1 = Pop();
				v2 = Pop();
				ret = v2 - v1;
			}
			if (expression[i] == '*'){
				v1 = Pop();
				v2 = Pop();
				ret = (v1 * v2);
			}
			if (expression[i] == '/'){
				v1 = Pop();
				v2 = Pop();
				ret = (v2 / v1);
			}
			if (expression[i] == '^'){
				v1 = Pop();
				v2 = Pop();
				ret = pow(v2, v1);
			}
			//INC Counter
			i++;
			//Push result onto stack
			Push(ret);
		}
		else{
			break;
		}
	}
	//Return answer
    value = Pop();
}

    float getValue()
    {
        return value;
    }
    void Parse()
    {
        infixToRPN(equation);
        RPN(equation);
    }

private:
    std::string equation;
    float value;
    std::string str_num;
    float _stack[MAX_STACK];
    int tos = 0;
private:
bool Full(){
	return tos >= MAX_STACK - 1;
}

bool Empty(){
	return tos == 0;
}

void Push(float value){
	if (Full()){
		return;
	}
	tos++;
	_stack[tos] = value;
}

float Pop(){
	float t = _stack[tos];
	tos--;
	return t;
}
//Enf of stack code

bool IsOp(char c){
	//Check for operators.
	switch (c){
		case '+':
		case '_':
		case '*':
		case '/':
        case '^':
			return true;
		default:
			return false;
	}
}

};