﻿/*Задание 2. Крестики-нолики
Что нужно сделать
Старая добрая игра на страницах всех школьных тетрадей.
Поле размером 3 × 3 представлено в виде двумерного массива с типом элементов char.
Участвуют два игрока, они ходят по очереди и ставят в указанные ими в стандартном вводе координаты свой символ —
X или O (буквы латинского алфавита).
Как только у одного из игроков будет установлено подряд три крестика или три нолика, он побеждает.
Если свободных клеток не осталось, а трёх совпадающих элементов не найдено, то объявляется ничья.
Для простоты не будем рассматривать диагональные совпадения — только строго вертикальные и строго горизонтальные.

Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки одинарные и в одну сторону).
Это можно сделать сразу при объявлении либо с помощью вложенного цикла.
На каждом ходе при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение,
и игрок должен указать координаты клетки повторно.
После каждого хода надо выводить в консоль текущее состояние всего игрового поля для наглядности.

Советы и рекомендации
Действия для обоих игроков одинаковые, отличаются только символом, который ставится на поле.
Игровой цикл не должен быть бесконечным. Игра имеет определённое максимальное количество шагов.
Не забывайте про случай ничьей.
Как и в предыдущем задании, здесь будет удобно сразу заполнить массив значениями false.
Количество мест, доступных для заполнения, заранее известно.
В процессе заполнения из этой переменой нужно не забывать вычитать единицу.
Чтобы отметить место как занятое, нужно лишь написать places[i][j] = true;.
Проверку на победу игрока, которую надо осуществлять после каждого хода,
можно сделать с помощью вложенного цикла, сразу проверяя и вертикаль, и горизонталь,
а как именно — попробуйте догадаться сами.
Здесь заранее известно число ходов — 3 * 3.
Столько раз должен быть выполнен цикл, который спрашивает у очередного игрока координаты.
Символ, который будет установлен в указанных координатах, можно на каждом шаге менять подобным образом:
if (gamer_name == 'X')
                gamer_name = 'O';
else
                gamer_name = 'X';*/

#include <iostream>

// функция вывода на экран игрового поля
void dispay_playing_field(char arr[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << arr[j][i];
        }
        std::cout << std::endl;
    }
    return;
}

// функция определения победителя, получает координаты очередного хода,
// возвращает символ победителя или пробел если победителя ещё нет
char winner(char arr[][3], int x, int y, char player)
{
    bool win = true;
    //проверяем вертикаль с координатой хода
    for (int i = 0; i < 3; ++i)
    {
        if (arr[x][i] != player)
        {
            win = false;
        }
    }
    if (win)
    {
        return player;
    }
    //проверяем горизонталь с координатой хода
    for (int i = 0; i < 3; ++i)
    {
        if (arr[i][y] != player)
        {
            win = false;
        }
    }
    if (win)
    {
        return player;
    }
    return ' ';
}

int main()
{
    // объявляем и инициализируем пробелам массив игрового поля
    char playing_Field[3][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
    // первые ходят крестики
    char current_Move = 'X';
    char winnerFlag = ' ';

    std::cout << "Welcome to the Tic Tac toe game program!" << std::endl;
    // цикл на 9 ходов
    for (int i = 1; i < 10; ++i)
    {

        int x, y;
        std::cout << (current_Move == 'X' ? "Player 1 " : "Player 2 ") << "enter the coordinates of your move separated by a space: ";

        std::cin >> x >> y;

        while (true)
        {
            // если введены не числа сбрасываем и очищаем cin
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            // проверяем правильность координат
            if ((x < 1 || x > 3) || (y < 1 || y > 3))
            {
                std::cout << "Input error! The coordinates should be from 1 to 3. Try again: ";
                std::cin >> x >> y;
            }
            // проверяем пусто ли поле по этим координатам
            else if (playing_Field[x - 1][y - 1] != '*')
            {
                std::cout << "Input error! There is already a symbol in these coordinates. Try again: ";
                std::cin >> x >> y;
            }
            // если координаты корректны выходим из цикла
            else
            {
                break;
            }
        }
        // записываем соответсвующий символ на игровое поле
        playing_Field[x - 1][y - 1] = current_Move;

        system("cls");
        dispay_playing_field(playing_Field);
        winnerFlag = winner(playing_Field, x - 1, y - 1, current_Move);
        if (winnerFlag != ' ')
        {
            break;
        }
        current_Move == 'X' ? current_Move = '0' : current_Move = 'X';
    }

    if (winnerFlag == ' ')
    {
        std::cout << "Sorry Nobody";
    }
    else
    {
        std::cout << (winnerFlag == 'X' ? "Player 1 " : "Player 2 ") << "win!!!";
    }
}
