#include <iostream>
#include <string>


//делит адресс на 2 части
std::string  mail_devide(std::string str, int part) {
std::string temp="";

    if (part == 1)
    {
        for(int i=0;i<str.find('@');i++){
            temp+=str[i];
        }
    }
    else if (part == 2){
        for(int i=str.find('@')+1;i<str.length();i++){
            temp+=str[i];
        }

    }
    return temp;

}
//проверяет на коректность символов
bool sim_valid(std::string str, int part) {
    std::string map1{ ".!#$%&'*+-/=?^_`{|}~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
    std::string map2{ "-.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };
    if (part == 1) {
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < map1.length(); j++) {
                if (str[i] == map1[j])
                    break;
                else if (str[i] != map1[j] && j == map1.length() - 1)
                    return false;
            }
        }
    }
    else if (part == 2) {
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < map2.length(); j++) {
                if (str[i] == map2[j])
                    break;
                else if (str[i] != map2[j] && j == map2.length() - 1)
                    return false;
            }
        }
    }
    return true;

}
//проверка точек
bool dot(std::string str) {
    if (str[0] == '.' ) {
        return false;
    }
    else {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '.' && str[i + 1] == '.' || str[i] == '.' && i == (str.length() - 1)) {
                return false;
            }
        }
    }
    return true;

}

bool dog_finder(std::string str){
    int k=0;
    for(int i=0; i<str.length();i++){
        if(str[i]=='@') k++;
        if(k>1 ||k==0&&i==str.length()-1) return false;
    }
    return true;
}
//проверка валидности адреса
bool validation(std::string  const& str) {
    if (!dog_finder(str)|| !dot(str))return false;
    else {
        std::string part1 = mail_devide(str, 1);
        std::string part2 = mail_devide(str, 2);
        if (!sim_valid(part1, 1) || !sim_valid(part2, 2)
            || part1.length() > 64 || part2.length() > 63)
            return false;
        else return true;
    }

}

int main()
{
for(;;) {
    std::string email;
    std::cin >> email;

    if (!validation(email)) {
        std::cout << "\n No\n";
    } else {
        std::cout << "\n Yes\n";
    }


}
}

