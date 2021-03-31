#include <iostream>

using namespace std;
//проверяем символы
bool check_sim(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '.') {
            if (str[i] < '0' || str[i]>'9') {
                //  cout << "\nsim false";
                return false;
            }
        }
    }
    return true;
}
//поиск точек. выдает индекс точки
int dot_finder(string str, int dot) {
    int dot_number = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            dot_number++;
            if (dot == dot_number)
                return i;
        }
    }
}
//перевод из char в int
int convert(string str, int dot_number) {
    int dot_last;
    int dot ;
    dot_number == 1 ? dot_last = -1 : dot_last =dot_finder(str,dot_number-1) ;
    dot_number == 4 ? dot = str.length() : dot = dot_finder(str, dot_number);
    int num =0;
    int k = 1;
    for (int j = dot-1; j > dot_last ; --j) {
        num =((int)str[j] - (int)'0') * k + num ;
        k *= 10;
    }
    // cout << num;
    return num;
}
//проверка числа от 0 до 255
bool check_number(int number) {
    return number > 255 || number < 0;
}
//проверяем первые нули
bool check_zeroLead(std::string str) {
    if (str[0] == '0') return false;
    for (int i = 1; i < str.length(); i++) {
        if ( str[i] !='.'&& str[i - 1] == '0' && str[i+1]!='.'&& i!=(str.length()-1)) {
            //  cout << "\nZERO false";
            return false;
        }
    }
    return true;
}
//считаем точки
bool dot_counter(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '.') count++;
        if (str[i] == '.' && str[i + 1]=='.') return false;
    }
    if (count == 3)
        return true;
    else {
        //  cout << "\ndot false";
        return false; }
}
//проверяем правильность ip
bool check_IP(string str) {
    if (!dot_counter(str) || !check_sim(str) || !check_zeroLead(str) || check_number(convert(str, 1))||
        check_number(convert(str, 2)) || check_number(convert(str, 3))
        || check_number(convert(str, 4))) {
        // std::cout << "\ncheck_IP false";
        return false;
    }
    else return true;
}

int main()
{
    for (;;) {
        string ip;
        cin >> ip;
        !check_IP(ip) ? cout << "\nNo\n" : cout << "\nYes\n";
    }
}
