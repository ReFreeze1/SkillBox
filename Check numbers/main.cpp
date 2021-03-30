#include <iostream>
#include <string>

using namespace std;

//проверяем корректность символов
bool check_simbols(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[0] < '-' || str[0]>'9'
            || str[0] == '/' || (str[i] < '.' && i != 0)
            || str[i] > '9' || str[i] == '/'
            || (str[i] == '.' && i == str.length() - 1)) {

            return false;
        }
    }
    return true;
}
/*#########################################################################*/

//проверка правильности положения минуса и что присутствует хотябы одно число
bool check_minus(std::string str) {

    for (int i = 0; i + 1 < str.length(); i++) {

        if ((str[i] == '-' && str[i] != str[0])
            || (str[i] == '-' && str[i + 1] == '.'
                && str[i + 1] == str[str.length() - 1])) {
            return false;
        }
    } return true;
}
/*#########################################################################*/

//проверка количества точек и минусов
bool dot_point(std::string str) {
    int dot = 0;
    int minus = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dot += 1;
            if (dot > 1) {
                return false;
            }
        }
        else if (str[i] == '-') {
            minus += 1;
            if (minus > 1) {
                return false;
            }
        }

    }
    return true;
}
/*#########################################################################*/

//проверка коректности ввода
bool correct_input(string str1) {
    if (!check_simbols(str1) || !check_minus(str1)|| !dot_point(str1) ) return false;
    else return true;
}
/*#########################################################################*/

//ввод
string input( string message) {
    string str;
    do {
        cout << endl <<message << endl;
        cin >> str;
    } while (!correct_input(str));
    return str;
}
/*#########################################################################*/

//проверка не является ли число нулем
bool if_Zero(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '1' && str[i] <= '9')
            return false;
    }
    return true;
}
/*#########################################################################*/

//выделяем целую часть
string int_part(string str) {
    string temp = "";
    for (int i = 0; i < str.length()&& str[i]!='.'; i++) {
        temp += str[i];
    }
    //cout <<"\n" <<temp;
    return temp;
}
/*#########################################################################*/

//выделяем дробную часть
string fract_part(string str) {
    string temp = "";
    for (int i = str.find('.') + 1; i < str.length(); i++) {
        temp += str[i];
    }
    // cout << "\n"<<temp;
    return temp;
}
/*#########################################################################*/

//Если в начале строки нули, то пропускаем их
string del_zero(string str, int start) {

    string temp;

    if (start == 1) temp = "-";
    else temp = "";
    do {
        if (str[start] == '0')
            start++;
        else break;
    } while (start < str.length());
    for (int i = start; i < str.length(); i++) {
        temp += str[i];
    }
    //cout << temp;
    return temp;
}
/*#########################################################################*/

//сравниваем
int compare(string str1, string str2) {
    //если одно из чисел равно нулю
    if (if_Zero(str1) && !if_Zero(str2)) return 0;
    else if (!if_Zero(str1) && if_Zero(str2)) return 1;
    else   if (if_Zero(str1) && if_Zero(str2)) return -1;

    int startPos1 = str1[0] == '-';//если отрицательное число то первая позиция 1
    int startPos2 = str2[0] == '-';

    if (startPos1 == 1 && startPos2 == 0) return 0;//если первое отрицательное false
    else  if (startPos1 == 0 && startPos2 == 1) return 1;

    //если выше условия не прошли, то проверяем длины целых частей

    string intPart1 = if_Zero(str1)?int_part(str1): del_zero(int_part(str1), startPos1);
    string intPart2 = if_Zero(str1)? int_part(str2):del_zero(int_part(str2), startPos2);

    if (intPart1.length() < intPart2.length()) return 0;
    else if (intPart1.length() > intPart2.length()) return 1;

    //если длины целых частей равны то сравниваем целые части
    if (intPart1 < intPart2) return 0;
    else if (intPart1 > intPart2) return 1;
    else if (intPart1 == intPart2) {

        //если целые части равны
        string fract1 = fract_part(str1);
        string fract2 = fract_part(str2);

        if (fract1 < fract2) return 0;
        else if (fract1 > fract2)return 1;
        else if (fract1 == fract2) return -1;
    }






}
/*#########################################################################*/

int main() {
    for (;;) {
        string num1 = input("Input first number:");
        string num2 = input("Input second number:");

        if (compare(num1,num2) ==1) cout << "\nMore";
        else if (compare(num1,num2)==0) cout << "\nLess";
        else  if (compare(num1, num2) == -1)cout << "\nEqual";

    }
}