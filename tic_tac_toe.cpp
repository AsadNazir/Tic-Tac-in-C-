#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include <ctime>
using namespace std;

// struct single_p
// {
//     char name[10];
//     char arr[3][3];
//     int state;
//     char p1;
//     char p2;
// };
struct multi_p
{
    char name[30];
    char name2[30];
    char arr[3][3];
    char state;
    char p1;
    char p2;
};
int menu();
void print(char arr[][3]);
char sub_menu();
void FiLL_Arr(multi_p &asad);
void TIC_TAC(int random = 0);
void custom_char(multi_p &a);
void move_validate(multi_p &asad);
int num_checker(multi_p &asad, int a);
void num_extractor(int no, int &no1, int &no2);
bool win_checker(multi_p &asad);
void print_player(multi_p asad);
void Record_getter();
void Filler(multi_p &asad);
int Computer(multi_p asad);
int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            TIC_TAC();
            break;
        case 2:
            TIC_TAC(1);
            break;
        case 3:
            Record_getter();
            break;
        case 4:

            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
// menu function
int menu()
{
    int choice;
    cout << "WELCOME TO TIC TAC TOE" << endl;
    cout << "Press 1 to start a 2 palyer game" << endl;
    cout << "Press 2 to start single game" << endl;
    cout << "Press 3 for previous stats" << endl;
    cout << "Press 4 for to quit" << endl;
    cin >> choice;
    while (!(choice >= 1 && choice <= 4))
    {
        cout << "Please enter a valid number" << endl;
        cin >> choice;
    }
    return choice;
}
// ----------------------------------------------------------------
// print funtion
void print(char arr[][3])
{
    cout << right << setw(30) << "| " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << " | " << endl;
    cout << right << setw(41) << "----|---|----" << endl;
    cout << right << setw(30) << "| " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << " | " << endl;
    cout << right << setw(41) << "----|---|----" << endl;
    cout << right << setw(30) << "| " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << " | " << endl;
}
// ----------------------------------------------------------------
char sub_menu()
{

    int a;
    cout << "THIS IS FOR PLAYER 1" << endl;
    cout << "PRESS 1 FOR ' X '.\nPRESS 2 FOR ' O '.\nPRESS 3 FOR YOUR OWN CUSTOM ALPHABET" << endl;
    cin >> a;
    while (!(a >= 1 && a <= 3))
    {
        cout << "ENTER A CORRECT NUMBER" << endl;
        cin >> a;
    }
    if (a == 1)
    {
        return 'X';
    }
    else if (a == 2)
    {
        return 'O';
    }
    return 'C';
}
//--------------------------------
// Filling
void FiLL_Arr(multi_p &asad)
{
    int no = 49;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            asad.arr[i][j] = char(no);
            no++;
        }
    }
}
// ------------------------------
void custom_char(multi_p &asad)
{
    cout << "ENTER THE ALPHABET FOR PLAYER 1" << endl;
    cin >> asad.p1;
    cout << "ENTER THE ALPHABET FOR PLAYER 2" << endl;
    cin >> asad.p2;
    while (asad.p1 == asad.p2)
    {
        cout << "The character " << asad.p1 << " is already taken. Choose another one" << endl;
        cin >> asad.p2;
    }
}
//-------------------------------
void num_extractor(int no, int &no1, int &no2)
{
    no2 = ((no - 1) % 3);
    if (no >= 1 && no <= 3)
    {
        no1 = 0;
    }
    else if (no >= 4 && no <= 6)
    {
        no1 = 1;
    }
    else
    {
        no1 = 2;
    }
}
//-------------------------------
bool win_checker(multi_p &asad)
{
    if (asad.arr[0][0] == asad.arr[0][1] && asad.arr[0][1] == asad.arr[0][2])
    {
        asad.state = asad.arr[0][0];
        return true;
    }
    else if (asad.arr[1][0] == asad.arr[1][1] && asad.arr[1][1] == asad.arr[1][2])
    {
        asad.state = asad.arr[1][0];
        return true;
    }
    else if (asad.arr[2][0] == asad.arr[2][1] && asad.arr[2][1] == asad.arr[2][2])
    {
        asad.state = asad.arr[2][0];
        return true;
    }
    //rows done
    else if (asad.arr[0][0] == asad.arr[1][0] && asad.arr[1][0] == asad.arr[2][0])
    {
        asad.state = asad.arr[0][0];
        return true;
    }
    else if (asad.arr[0][1] == asad.arr[1][1] && asad.arr[1][1] == asad.arr[2][1])
    {
        asad.state = asad.arr[0][1];
        return true;
    }
    else if (asad.arr[0][2] == asad.arr[1][2] && asad.arr[1][2] == asad.arr[2][2])
    {
        asad.state = asad.arr[0][2];
        return true;
    }
    //col done
    else if (asad.arr[0][0] == asad.arr[1][1] && asad.arr[1][1] == asad.arr[2][2])
    {
        asad.state = asad.arr[0][0];
        return true;
    }
    else if (asad.arr[0][2] == asad.arr[1][1] && asad.arr[1][1] == asad.arr[2][0])
    {
        asad.state = asad.arr[0][2];
        return true;
    }
    return false;
}
//------------------------------
int Computer(multi_p asad)
{
    int input, no1, no2;
    cout << "Computers turn ( " << asad.p2 << " )"
         << " TURN" << endl;
    _getch();
    input = ((rand() % 9) + 1);
    num_extractor(input, no1, no2);
    while (asad.arr[no1][no2] == asad.p1 || asad.arr[no1][no2] == asad.p2)
    {
        input = ((rand() % 9) + 1);
        cout << "The numbers are " << no1 << " " << no2 << endl;
        num_extractor(input, no1, no2);
    }
    return input;
}
//-------------------------------
int num_checker(multi_p &asad, int a)
{
    int num = 0;
    int input;
    int no1, no2;
    int i = 0;
    char p;
    srand(unsigned(time(NULL)));
    while (i < 9)
    {

        if (num % 2 == 0)
        {
            cout << "PLAYER 1 ( " << asad.p1 << " )"
                 << " TURN" << endl;
            cin >> input;
            p = asad.p1;
            num++;
        }
        else
        {
            if (a)
            {
                input = Computer(asad);
                p = asad.p2;
            }
            else
            {
                cout << "PLAYER 2 ( " << asad.p2 << " )"
                     << " TURN" << endl;
                p = asad.p2;
                cin >> input;
            }
            num++;
        }

        while (!(input >= 1 && input <= 9))
        {

            cout << "Enter correct number" << endl;
            cin >> input;
        }
        num_extractor(input, no1, no2);
        while (asad.arr[no1][no2] == asad.p1 || asad.arr[no1][no2] == asad.p2)
        {
            cout << "Enter correct number from the table that is not taken" << endl;
            cin >> input;
            num_extractor(input, no1, no2);
        }

        system("cls");
        asad.arr[no1][no2] = p;
        print(asad.arr);

        if (win_checker(asad))
        {
            cout << "GAME OVER. PLAYER " << asad.state << " WON" << endl;
            return 1;
        }

        i++;
    }
    cout << "GAME IS A DRAWN " << endl;
    return 0;
}
//-------------------------------
void Filler(multi_p &asad)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (asad.arr[i][j] != asad.p1 && asad.arr[i][j] != asad.p2)
            {
                asad.arr[i][j] = ' ';
            }
        }
    }
}
//-------------------------------
void TIC_TAC(int random)
{
    system("cls");
    multi_p asad;
    string name, name2 = "Computer";
    cout << "The layout of the game is as follows" << endl
         << endl;
    FiLL_Arr(asad);
    print(asad.arr);
    cout << endl
         << endl;
    _getch();
    char a = sub_menu();
    if (a == 'X')
    {
        asad.p1 = a;
        asad.p2 = 'O';
    }
    else if (a == 'O')
    {
        asad.p1 = a;
        asad.p2 = 'X';
    }
    else
    {
        custom_char(asad);
    }

    system("cls");
    cout << "Player 1 is " << asad.p1 << endl;
    cout << "Player 2 is " << asad.p2 << endl;
    cout << "Press any key to enter the game." << endl;
    system("cls");
    print(asad.arr);
    int var = num_checker(asad, random);
    if (var)
    {
        fstream out("player.bin", ios::out | ios::binary | ios::app);
        if (!out.is_open())
        {
            cout << "ERROR: Couldn't open'" << endl;
            exit(-1);
        }
        cout << "Enter name of the Player " << asad.p1 << endl;
        cin.ignore();
        getline(cin, name);
        if (!random)
        {
            cin.ignore();
            cout << "Enter name of the Player " << asad.p2 << endl;
            getline(cin, name2);
        }
        Filler(asad);
        strcpy(asad.name, name.c_str());
        strcpy(asad.name2, name2.c_str());
        out.write(reinterpret_cast<char *>(&asad), sizeof(multi_p));
        _getch();
        out.close();
        system("cls");
    }
}
//------------------------------
void print_player(multi_p asad)
{
    cout << endl
         << "------------------------------------------------" << endl<<endl;
    cout << setw(15) << left << "Player 1 :" << asad.name << " ( " << asad.p1 << " )" << endl;
    cout << setw(15) << left << "Player 2 :" << asad.name2 << " ( " << asad.p2 << " )" << endl;
    cout << "Player " << asad.state << " WON" << endl;
    cout << endl;
    print(asad.arr);
  
}
//------------------------------
void Record_getter()
{
    system("cls");
    fstream in("player.bin", ios::in | ios::binary);
    multi_p asad;
    if (!in.is_open())
    {
        cout << "ERROR: Couldn't open'" << endl;
        exit(-1);
    }
    in.read(reinterpret_cast<char *>(&asad), sizeof(multi_p));
    while (in)
    {
        print_player(asad);
        in.read(reinterpret_cast<char *>(&asad), sizeof(multi_p));
    }
    cout << endl
         << "Pres any key to continue " << endl;

    _getch();
    system("cls");
    in.close();
}