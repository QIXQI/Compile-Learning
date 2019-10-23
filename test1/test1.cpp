#include <iostream>
#include <string.h>
using  namespace std;

// 测试用例
string test = "int x:=5; if(x>0) then x:=2*x+1/3; else x:=2/x; #";   
// 关键字列表
string keyword[8] = {"for", "if", "then", "else", "while", "do", "until", "int"};
int token;      // 词法记号
string num;        // 存放整数
string id;         // 存放构成词法单元的字符串
int pointer = 0;    // 测试用例的扫描点


// 判断是否是数字
bool isDigit(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }
    return false;
}

// 判断是否是字母
bool isChar(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return true;
    }
    return false;
}

// 判断是否是运算符
bool isOperator(char ch){
    // 运算符
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ':' || ch == '<' || ch == '>' || ch == '=' || ch == ';' || ch == '(' || ch == ')' || ch == '#'){
        return true;
    }
    return false;
}

// 判断是否空白
bool isBlank(char ch){
    // 空白
    if(ch == ' ' || ch == '\n' || ch == '\t'){
        return true;
    }
    return false;
}

// 将词法单元对应的记号保存到token中，属性值保存到num或id中
void lexical(){
    // 除去空白
    while(isBlank(test[pointer])){
        pointer ++;
    }
    // 处理运算符
    if(isOperator(test[pointer])){
        id = test[pointer];
        if(test[pointer] == '+'){
            token = 13;
        }else if(test[pointer] == '-'){
            token = 14;
        }else if(test[pointer] == '*'){
            token = 15;
        }else if(test[pointer] == '/'){
            token = 16;
        }else if(test[pointer] == ':' && test[pointer + 1] != '='){
            token = 17;
        }else if(test[pointer] == ':' && test[pointer + 1] == '='){
            token = 18;
            id += '=';
            pointer ++;
        }else if(test[pointer] == '<' && test[pointer + 1] != '>' && test[pointer + 1] != '='){
            token = 20;
        }else if(test[pointer] == '<' && test[pointer + 1] == '>'){
            token = 21;
            id += '>';
            pointer ++;
        }else if(test[pointer] == '<' && test[pointer + 1] == '='){
            token = 22;
            id += '=';
            pointer ++;
        }else if(test[pointer] == '>' && test[pointer + 1] != '='){
            token = 23;
        }else if(test[pointer] == '>' && test[pointer + 1] == '='){
            token = 24;
            id += '=';
            pointer ++;
        }else if(test[pointer] == '='){
            token = 25;
        }else if(test[pointer] == ';'){
            token = 26;
        }else if(test[pointer] == '('){
            token = 27;
        }else if(test[pointer] == ')'){
            token = 28;
        }else if(test[pointer] == '#'){
            token = 0;
        }else{
            token = -1;
        }
        // pointer ++;
    }else if(isDigit(test[pointer])){          // 处理数字字面量
        token = 11;
        num = test[pointer];
        while(isDigit(test[pointer + 1])){
            num += test[pointer + 1];
            pointer ++;
        }
        if(isChar(test[pointer + 1])){
            token = -1;
        }
        // pointer ++;
    }else if(isChar(test[pointer])){            // 变量或关键字
        token = 10;
        id = test[pointer];
        while(isDigit(test[pointer + 1]) || isChar(test[pointer + 1])){
            id += test[pointer + 1];
            pointer ++;
        }
        // pointer ++;
        if(id == "for"){
            token = 1;
        }else if(id == "if"){
            token = 2;
        }else if(id == "then"){
            token = 3;
        }else if(id == "else"){
            token = 4;
        }else if(id == "while"){
            token = 5;
        }else if(id == "do"){
            token = 6;
        }else if(id == "until"){
            token = 29;
        }else if(id == "int"){
            token = 30;
        }else if(id == "input"){
            token = 31;
        }else if(id == "output"){
            token = 32;
        }
    }
    pointer ++;
}




int main(){
    lexical();
    while(token != 0){
        if(token == 11){
            cout << "(" << token << ", " << num << ")   ";
        }else if(token == -1){
            cout << "error!     " << endl;
            break;
        }else if(token == 10){
            cout << "(" << token << ", '" << id << "')   "; 
        }else{
            cout << "(" << token << ", " << id << ")   "; 
        }
        lexical();
    }
    if(token == 0){
        cout << "(0, '#')   ";
    }
    cout << endl;
    return 0;
}
