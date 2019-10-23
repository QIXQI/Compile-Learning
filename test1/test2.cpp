#include <iostream>
#include <string.h>
using namespace std;

bool checkChar(string password){
    int flag1 = 0;          // 大写字母
    int flag2 = 0;          // 小写字母
    int flag3 = 0;          // 数字
    int flag4 = 0;          // 符号
    for(int i=0; i<password.length(); i++){
        if( password[i] >= 'A' && password[i] <= 'Z'){
            flag1 = 1;
        }else if(password[i] >= 'a' && password[i] <= 'z'){
            flag2 = 1;
        }else if(password[i] >= '0' && password[i] <= '9'){
            flag3 = 1;
        }else if(password[i] != ' '){
            flag4 = 1;
        }
    }
    if(flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1){
        return true;
    }
    return false;
}

// password 以前的密码
bool isContained(char ch, string password){
    for(int i=0; i<password.length(); i++){
        if(ch == password[i]){
            return true;
        }
    }
    return false;
}

// password1 输入的密码, password2 以前的密码
bool isRepeat(string password1, string password2){
    int num = 0;          
    for(int i=0; i<password1.length(); i++){
        if(isContained(password1[i], password2)){
            num ++;
        }
    }
    if(num > 3){
        return true;
    }
    return false;
}

int main(){
    string passwords[20];
    passwords[0] = "by99YL17!";
    string password;
    int len = 1;
    cout << "请输入新密码：";
    while(cin >> password){
        if(password.length() <= 8){
            cout << "密码太短，请重新输入：";
        }else if(!checkChar(password)){
            cout << "密码必须包含大写字母、数字、符号，请重新输入：";
        }else{
            int i;
            for(i=0; i<len; i++){
                if(isRepeat(password, passwords[i])){
                    cout << "与以前密码重复字符多于3个，请重新输入：";
                    break;
                }
            }
            if(i >= len){
                cout << "密码输入正确，符合规范!" << endl;
                break;
            }
        }
    }



    return 0;
}
