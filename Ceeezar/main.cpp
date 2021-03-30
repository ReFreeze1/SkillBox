#include <iostream>
#include <string>

std::string encrypt_caesar(std::string txt, int code) {
    for (int i = 0; i < txt.length(); i++) {
        int a = 26;
        if (code < 0)
            a = -26;

        txt[i] == ' ' ? txt[i] = ' ' : txt[i] += code;

        if (txt[i] > 'Z' && txt[i] < 'a') {
            txt[i] = txt[i] - a;
        }
        else
        if (txt[i] > 'z') {
            txt[i] = txt[i] - a;
        }

    }
    return txt;
}
std::string decrypt_caesar(std::string txt, int code) {

    return encrypt_caesar(txt, (-code));
}



int check_code(int code) {
    if (code > 26)
        code = code % 26;
    else return code;
}

int main()
{
    std::cout << "Enter text: \n";
    std::string text;
    std::getline(std::cin, text);
    int kod;
    std::cout << "Input code: ";
    std::cin >> kod;


    text = encrypt_caesar(text, check_code(kod));
    std::cout << text;
    std::cout << "\n===========================================\n";

    text = decrypt_caesar(text, check_code(kod));
    std::cout << text << std::endl;




}

