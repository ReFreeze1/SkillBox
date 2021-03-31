#include <iostream>

//делит адресс на 2 части
int mail_devide(std::string str, int part) {
   
    int k=0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '@') {
            k = i;
        }
    }
    if (part == 1)
        return k;
    else if (part == 2)
        return k + 1;
}
//проверяет на коректность символов
bool sim_valid(std::string str, int part, int dog) {
    std::string map1{ ".!#$%&'*+-/=?^_`{|}~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
    std::string map2{ "-.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };
    if (part == 1) {
        for (int i = 0; i < dog; i++) {
            for (int j = 0; j < map1.length(); j++) {
                if (str[i] == map1[j])
                    break;
                else if (str[i] != map1[j] && j == map1.length() - 1)
                    return false;
            }
        }
    }
    else if (part == 2) {
        for (int i = dog; i < str.length(); i++) {
            for (int j = 0; j < map2.length(); j++) {
                if (str[i] == map2[j])
                    break;
                else if (str[i] != map2[j] && j == map2.length() - 1)
                    return false;
            }
        }
    }
    
}
//счетчик
int counter(std::string str, int part) {
    int count=0;
    if (part == 1) {
        for (int i = 0; i < mail_devide(str, part); i++) {
            count++;
        }
    }
    else if (part == 2) {
        for (int i = mail_devide(str, part); i <str.length() ; i++) {
            count++;
        }
    }
    return count;
}
//проверка точек
bool dot(std::string str) {
    if (str[0] == '.' || str[mail_devide(str, 2)] == '.') {
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
//проверка валидности адреса
bool validation(std::string str) {
    if (mail_devide(str,1)==0 || !sim_valid(str, 1, mail_devide(str, 1)) || !sim_valid(str, 2, mail_devide(str, 2))
        || counter(str, 1) > 64 || counter(str, 2) > 63 || !dot(str))
        return false;
    else return true;
}

int main()
{

        std::string email;
        std::cin >> email;

        if (!validation(email)) {
            std::cout << "\n No\n";
        }
        else {
            std::cout << "\n Yes\n";
        }


}

