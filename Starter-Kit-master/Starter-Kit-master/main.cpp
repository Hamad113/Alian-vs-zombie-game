//// ********************************************************* 
//// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
//// Year: Trimester 1, 2022/23 (T2215) 
//// Lab: T13L 
//// Names: Bin_Afeef_Hamad | Maresh, Mohanad Ayoub | Bin Afeef, Abdullah  
//// IDs: 1211300020 | 1211303662 | 1211306604 
//// Emails: 1211300020@student.mmu.edu.my | 1211303662@student.mmu.edu.my | 1211306604@student.mmu.edu.my 
//// Phones: 01125200968 | 01139645167 | 0182440619 
//// ********************************************************* 
//
#include <iostream>
#include <string>
using namespace std;


const int kRows = 7;
const int kColumns = 40;
const int defaultmiddle = kColumns / 2;
char kBoard[kRows][kColumns];
char myword[] = { 'h' , '>' , 'h' , 'r' , 'p' , '^' , 'p', '<', 'r', 'v' };
const char allien = 'A';
int allien_attack = 10;
int allien_life = 100;
int zoombie_life = 200, zoombie_range = 10, zoombie_attack = 200;
int zoombie_count = 2;


int ClearScreen()
{
#if defined(_WIN32)
    return std::system("cls");
#elif defined(_linux) || defined(__APPLE_)
    return std::system("clear");
#endif
}

int Pause()
{
#if defined(_WIN32)
    return std::system("pause");
#elif defined(_linux) || defined(__APPLE_)
    return std::system(R"(read -p "Press any key to continue . . . " dummy)");
#endif
}

void ShowGameBoard()
{
    for (int row = 0; row < kRows; ++row)
    {
        for (int col = 0; col < kColumns; ++col)
        {
            std::cout << kBoard[row][col];
        }
        cout << endl;
    }

}

void CreatedefaultBoard()
{

    for (int row = 0; row < kRows; ++row)
        for (int col = 0; col < kColumns; ++col)
        {
            if (row == 0 || row == 2 || row == 4 || row == 6)
            {
                if (col % 2 == 0)
                {
                    kBoard[row][col] = '-';
                }
                else
                {
                    kBoard[row][col] = '+';
                }
            }
            else if (row == 1 || row == 3 || row == 5)
            {
                if (col % 2 == 0)
                {
                    kBoard[row][col] = '|';
                }
                else
                {
                    int random = rand() % 11;
                    kBoard[row][col] = myword[random];
                    
                    // setting Allien default position
                    kBoard[3][21] = allien;
                    kBoard[5][31] = '1';
                    kBoard[1][9] = '2';

                }
            }
        }
    
    cout << defaultmiddle << endl;

    //setting to default
    allien_life = 100;
    allien_attack = 10;
    srand(time(0));
    zoombie_life = rand() % 191 + 10, zoombie_range = rand() % 30 + 10, zoombie_attack = rand() % 50 + 10;
    ShowGameBoard();
}
void CreatecustomBoard() {
    int kRows = 0;
    int kColumns = 0;
    cout << "Enter Board Rows : ";
    cin >> kRows;
    cout << "Enter Board Columns : ";
    cin >> kColumns;
    cout << "Enter zoombie numbers : ";
    cin >> zoombie_count;
    cout << "Enter zoombie life : ";
    cin >> zoombie_life;
    cout << "Enter zoombie range : ";
    cin >> zoombie_range;
    int rowshalf = kRows / 2;
    int colhalf = kColumns / 2; 

    for (int row = 0; row < kRows; ++row)
        for (int col = 0; col < kColumns; ++col)
        {
            if (row == 0 || row == 2 || row == 4 || row == 6)
            {
                if (col % 2 == 0)
                {
                    kBoard[row][col] = '-';
                }
                else
                {
                    kBoard[row][col] = '+';
                }
            }
            else if (row == 1 || row == 3 || row == 5)
            {
                if (col % 2 == 0)
                {
                    kBoard[row][col] = '|';
                }
                else
                {
                    int random = rand() % 11;
                    kBoard[row][col] = myword[random];
                }
            }
        }

    // placing allien and zoombie
    kBoard[rowshalf][colhalf] = allien;
    int zoombies = 0;
    string temp = "";
    for (int i = 1; i <= zoombie_count; i++) {
        zoombies = rand() % zoombie_count;
        temp = to_string(i);
        kBoard[zoombies][zoombies] = temp[0];
    }
    
    ShowGameBoard();
}

void showstats() {
    cout << "Allien      : Life " << allien_life << ", Attack " << allien_attack << endl;
    for (int i = 1; i <= zoombie_count; i++) {
        cout << "Zoombie " << i << " : Life " << zoombie_life << ", Attack " << allien_attack << ", Range " << zoombie_range << endl;;
    }
    cout << "Press 3 to return to main menu" << endl;
}

void game() {
    bool allien = true;
    bool zoombie = false;
    showstats();
    int choice = 0;
    while (choice != 3) {
        cout << "1) Set to default " << endl;
        cout << "2) Do turn " << endl;
        cout << "3) Exit " << endl;
        cout << "Please enter your choice: ";
        cin >> choice;
        ClearScreen();
        if (choice == 1) {
            //pf::ClearScreen();
            CreatedefaultBoard();
            showstats();
        }
        else if (choice == 2) {
            if (allien == true) {
                cout << "Alliens turn " << endl;
                allien = false;
                zoombie = true;
            }
            else if (zoombie == true) {
                cout << "Zoombie turn " << endl;
                allien = true;
                zoombie = false;
            }
            ShowGameBoard();
            showstats();
        }
        else if (choice == 3) {
            ClearScreen();
            break;
        }
    }
}




void DemoPause()
{
    cout << "Pausing Now" << endl;
    Pause();
    cout << endl;
}

void DemoClearScreen()
{
    cout << "Pausing and Clearing Screen Now" << endl;
    Pause();
    ClearScreen();
    cout << endl;
}
 

int main()
{
    cout << "===== Allien VS zombies =====" << endl;
    int choice = 0;
    while(choice != 3) {
        cout << "1) Start Game" << endl;
        cout << "2) Set Board Settings" << endl;
        cout << "3) Exit" << endl;
        cout <<endl<< "Please enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            ClearScreen();
            cout << "Creating Default board of 7x40" << endl;
            CreatedefaultBoard();
            game();
            
        }
        else if (choice == 2) {
            ClearScreen();
            cout << "Creating custom board" << endl;
            CreatecustomBoard();
            game();
        }
        else if (choice == 3) {
            break;
  }

}
}
