#include <iostream>

//Контроль ввода
bool enter_control(std::string txt) {

    for (int i = 0; i < txt.length(); i++) {
        if (txt[i] != 'X' && txt[i] != 'O' && txt[i] != '.') {

            return false;
        }
    }
    return true;
}
//навигация по полю
char nav(std::string str, int x, int y) {
    for (int i = 0; i < x; i++) {
        int j;
        for (j = 0; j < y; j++) {
            if (i == (x - 1) && j == (y - 1))
                return str[(i*3) + j];
        }
    }
}
//Проверка строки
int check_win_str(std::string str, char sim, int row) {
    int k = 0;
    for (int i = 1; i <= 3; i++) {
        if (nav(str,row,i) == sim) k++;
    }
    if (k==3) {
     //   std::cout << sim << " won str\n";
        return 1;

    }
    else return 0;

}
//проверка колонки
int check_win_col(std::string str, char sim, int col) {
    int k = 0;
    for (int i = 1; i <= 3; i++) {
        if (nav(str, i, col) == sim) k++;
    }
    if (k == 3) {
      //  std::cout << sim << " won col\n";
        return 1;

    }
    else return 0;
}
//проверка диагоналей
int check_win_diag(std::string str, char sim, bool diag) {
    if (diag) {
        int k = 0;
        for (int i = 1; i <= 3; i++) {
            if (nav(str, i, i) == sim) k++;
        }
        if (k == 3) {
       //     std::cout << sim << " won dian norm\n";
            return 1;

        }
        else return 0;
    }
    else {
        int k = 0;
        for (int i = 1; i <= 3; i++) {


            if (nav(str, (2-i+2), i) == sim) k++;


        }
        if (k == 3) {
            std::cout << sim << " won diaf obr\n";
            return 1;

        }
        else return 0;
    }
}
//счетчик
int counter(std::string str, char sim) {
    int k = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == sim) {
            k++;
        }
    }
  //  std::cout << "\nCounter " << sim << k;
    return k;
}
//проверка игрового поля
int finder_sim(std::string str, char sim) {
    int k = check_win_str(str, sim, 1) + check_win_str(str, sim, 2) + check_win_str(str, sim, 3) +
            check_win_col(str, sim, 1) + check_win_col(str, sim, 2) + check_win_col(str, sim, 3) +
            check_win_diag(str, sim, 1) + check_win_diag(str, sim, 0);
    return k;
}
//проверка победителя
void check_winner(std::string str) {
    int X, O;
    X = finder_sim(str, 'X');
    O = finder_sim(str, 'O');

    if(X == 1 && O == 0 ) {
        std::cout << "\nPetya won!";
    }
    else if (X == 0 && O == 1 && counter(str, 'X') <= counter(str, 'O')) {
        std::cout << "\nVanya won!";
    }
    else if (X == 0 && O == 0 || (counter(str,'X')>counter(str,'O')&& O==1&&X==0)) {
        std::cout << "\nNobody";
    }

}
//поиск некоректности
bool incorrect_finder(std::string str) {
    int X, O,x,o;
    X = finder_sim(str, 'X');
    O = finder_sim(str, 'O');
    x = counter(str, 'X');
    o = counter(str, 'O');

    if (X == 1 && O == 1 || X > 1 || O > 1 ||x<o ||enter_control(str)==false) {
        std::cout << "\nIncorrect ";
        return false;
    }
    else if (O==1 && x>o) {
        std::cout << "\nIncorrect ";
        return false;
    }
    else if(X == 1 && o >= x) {
        std::cout << "\nIncorrect ";
        return false;
    }
    else
        return true;
}



int main()
{
    std::string line1;
    std::cin >> line1;
    std::string line2;
    std::cin >> line2;
    std::string line3;
    std::cin >> line3;
    std::string line = line1+line2+line3;



    if (incorrect_finder(line)==true) {
        check_winner(line);
    }
}

