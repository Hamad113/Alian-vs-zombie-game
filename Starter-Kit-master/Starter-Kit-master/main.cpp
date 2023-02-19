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
#include <vector>
using namespace std;


int kRows = 7;
int kColumns = 40;
vector<vector<char>> kBoard(kRows, vector<char>(kColumns, ' '));
char myword[] = { 'h' , '>' , 'h' , 'r' , 'p' , '^' , 'p', '<', 'r', 'v' };
int zoombie_life = 200, zoombie_range = 5;
int Alient_health = 100;
int Alein_attack = 0;
int zoombie_attack = 0;


int ClearScreen()
{
#if defined(_WIN32)
    return std::system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    return std::system("clear");
#endif
}

int Pause()
{
#if defined(_WIN32)
    return std::system("pause");
#elif defined(__linux__) || defined(__APPLE__)
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
int total_zombies = 2;
void MoveAlien()
{
    char movement;
    cout << "Move the alien (w = up, s = down, a = left, d = right): ";
    cin >> movement;

    int alienRow, alienCol;
    for (int row = 0; row < kRows; ++row)
    {
        for (int col = 0; col < kColumns; ++col)
        {
            if (kBoard[row][col] == 'A')
            {
                alienRow = row;
                alienCol = col;
                break;
            }
        }
    }
    switch (movement)
    {
    case 'w':
        if (alienRow > 1 && kBoard[alienRow - 2][alienCol] != 'r')
        {
            int random = rand() % 11;
            kBoard[alienRow][alienCol] = myword[random];
            if (kBoard[alienRow - 2][alienCol] == '<' || kBoard[alienRow - 2][alienCol] == '>')
            {
                Alein_attack += 5;
                cout << "Alien attacked Increased!" << endl;
            }
            if (kBoard[alienRow - 2][alienCol] == 'h')
            {
                Alient_health += 10;
                cout << "Health increased by 10!" << endl;
            }
            if (kBoard[alienRow - 2][alienCol] == 'p')
            {
                zoombie_life -= 10;
                cout << "Zombie health decreased!" << endl;
            }
            if (kBoard[alienRow - 2][alienCol] == '1' || kBoard[alienRow - 2][alienCol] == '2')
            {
                cout << "Zombie KILLED!" << endl;
                total_zombies--;
            }
            kBoard[alienRow - 2][alienCol] = 'A';
        }
        break;
    case 's':
        if (alienRow < kRows - 2 && kBoard[alienRow + 2][alienCol] != 'r')
        {
            int random = rand() % 11;
            kBoard[alienRow][alienCol] = myword[random];
            if (kBoard[alienRow + 2][alienCol] == '<' || kBoard[alienRow + 2][alienCol] == '>')
            {
                Alein_attack += 5;
                cout << "Alien attacked Increased!" << endl;
            }
            if (kBoard[alienRow + 2][alienCol] == 'h')
            {
                Alient_health += 10;
                cout << "Health increased by 10!" << endl;
            }
            if (kBoard[alienRow + 2][alienCol] == 'p')
            {
                zoombie_life -= 10;
                cout << "Zombie health decreased!" << endl;
            }
            if (kBoard[alienRow + 2][alienCol] == '1' || kBoard[alienRow + 2][alienCol] == '2')
            {
                cout << "Zombie KILLED" << endl;
                total_zombies--;
            }
            kBoard[alienRow + 2][alienCol] = 'A';
        }
        break;
    case 'a':
        if (alienCol > 1 && kBoard[alienRow][alienCol - 2] != 'r')
        {
            int random = rand() % 11;
            kBoard[alienRow][alienCol] = myword[random];
            if (kBoard[alienRow][alienCol - 2] == '<' || kBoard[alienRow][alienCol - 2] == '>')
            {
                Alein_attack += 5;
                cout << "Alien attacked Increased!" << endl;
            }
            if (kBoard[alienRow][alienCol - 2] == 'h')
            {
                Alient_health += 10;
                cout << "Health increased by 10!" << endl;
            }
            if (kBoard[alienRow][alienCol - 2] == 'p')
            {
                zoombie_life -= 10;
                cout << "Zombie health decreased!" << endl;
            }
            if (kBoard[alienRow][alienCol - 2] == '1' || kBoard[alienRow][alienCol - 2] == '2')
            {
                cout << "Zombie KILLED" << endl;
                total_zombies--;
            }
            kBoard[alienRow][alienCol - 2] = 'A';
        }
        break;
    case 'd':
        if (alienCol < kColumns - 2 && kBoard[alienRow][alienCol + 2] != 'r')
        {
            int random = rand() % 11;
            kBoard[alienRow][alienCol] = myword[random];
            if (kBoard[alienRow][alienCol + 2] == '<' || kBoard[alienRow][alienCol + 2] == '>')
            {
                Alein_attack += 5;
                cout << "Alien attacked Increased!" << endl;
            }
            if (kBoard[alienRow][alienCol + 2] == 'h')
            {
                Alient_health += 10;
                cout << "Health increased by 10!" << endl;
            }
            if (kBoard[alienRow][alienCol + 2] == 'p')
            {
                zoombie_life -= 10;
                cout << "Zombie health decreased!" << endl;
            }
            if (kBoard[alienRow ][alienCol + 2] == '1' || kBoard[alienRow][alienCol + 2] == '2')
            {
                cout << "Zombie KILLED" << endl;
                total_zombies--;
            }
            kBoard[alienRow][alienCol + 2] = 'A';
        }
        break;
    default:
        break;
    }
    if (total_zombies == 0)
    {
        cout << "ALL ZOOMBIES KILLED GAME OVER" << endl;
        exit(0);
    }
    if (zoombie_life < 1)
    {
        cout << "ALL ZOOMBIES KILLED GAME OVER" << endl;
        exit(0);
    }
    
}
void MoveZombies()
{
    int zombieRow[2], zombieCol[2];
    int count = 0;
    for (int row = 0; row < kRows; ++row)
    {
        for (int col = 0; col < kColumns; ++col)
        {
            if (kBoard[row][col] == '1' || kBoard[row][col] == '2')
            {
                zombieRow[count] = row;
                zombieCol[count] = col;
                ++count;
            }
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        int direction = rand() % 4;
        switch (direction)
        {
        case 0:
            if (zombieRow[i] > 1)
            {
                int newRow = zombieRow[i] - 2;
                kBoard[newRow][zombieCol[i]] = kBoard[zombieRow[i]][zombieCol[i]];
                kBoard[zombieRow[i]][zombieCol[i]] = '.';
                zombieRow[i] = newRow;
            }
            break;
        case 1:
            if (zombieRow[i] < kRows - 2)
            {
                int newRow = zombieRow[i] + 2;
                kBoard[newRow][zombieCol[i]] = kBoard[zombieRow[i]][zombieCol[i]];
                kBoard[zombieRow[i]][zombieCol[i]] = '.';
                zombieRow[i] = newRow;
            }
            break;
        case 2:
            if (zombieCol[i] > 1)
            {
                int newCol = zombieCol[i] - 2;
                kBoard[zombieRow[i]][newCol] = kBoard[zombieRow[i]][zombieCol[i]];
                kBoard[zombieRow[i]][zombieCol[i]] = '.';
                zombieCol[i] = newCol;
            }
            break;
        case 3:
            if (zombieCol[i] < kColumns - 2)
            {
                int newCol = zombieCol[i] + 2;
                kBoard[zombieRow[i]][newCol] = kBoard[zombieRow[i]][zombieCol[i]];
                kBoard[zombieRow[i]][zombieCol[i]] = '.';
                zombieCol[i] = newCol;
            }
            break;
        }
        int kAlienRow, kAlienCol;
        for (int row = 0; row < kRows; ++row)
        {
            for (int col = 0; col < kColumns; ++col)
            {
                if (kBoard[row][col] == 'A')
                {
                    kAlienRow = row;
                    kAlienCol = col;
                    break;
                }
            }
        }
        
        if (abs(zombieRow[i] - kAlienRow) <= zoombie_range && abs(zombieCol[i] - kAlienCol) <= zoombie_range)
        {
            Alient_health -= zoombie_attack;
            cout << "Alien hit by zombie " << i + 1 << "! Alien health is now " << Alient_health << endl;
        }
    }
    if (Alient_health == 0 || Alient_health < 0)
    {
        cout << "ZOOMBIES WON!" << endl;
        exit(0);
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
                    
                    
                    kBoard[3][21] = 'A';
                    kBoard[5][31] = '1';
                    kBoard[1][9] = '2';

                }
            }
        }

    
    int allien_life = 100;
    int allien_attack = 10;
    
    srand(time(0));
    zoombie_life = rand() % 70 + 10, zoombie_range = rand() % 10 + 1, zoombie_attack = rand() % 10 + 1;
    ShowGameBoard();
}
void CreatecustomBoard() {
    
    cout << "Enter Board Rows : ";
    cin >> kRows;
    cout << "Enter Board Columns : ";
    cin >> kColumns;
    cout << "Enter zoombie life : ";
    cin >> zoombie_life;
    cout << "Enter zoombie range : ";
    cin >> zoombie_range;
    kRows = kRows * 2;
    kColumns = kColumns * 2;
    int rowshalf = kRows / 2;
    int colhalf = kColumns / 2; 

    int newRows = kRows;
    int newColumns = kColumns;

    kBoard.resize(newRows);
    for (int i = 0; i < kBoard.size(); i++) {
        kBoard[i].resize(newColumns, ' ');
    }



    for (int row = 0; row < kRows; row++)
        for (int col = 0; col < kColumns; col++)
        {
            if (row % 2 == 0)
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
            else
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

    
    if (kBoard[rowshalf ][colhalf - 1] == '+' || kBoard[rowshalf][colhalf - 1] == '-') {
        kBoard[rowshalf -1][colhalf] = 'A';
    }
    else {
        kBoard[rowshalf][colhalf] = 'A';
    }
    
    
    int zoombies = 0;
    string temp = "";
    for (int i = 1; i <= 2; i++) {
        zoombies = rand() % 2;
        temp = to_string(i);
        kBoard[zoombies][zoombies] = temp[0];
    }
    

    for (int row = 0; row < kRows; ++row)
    {
        for (int col = 0; col < kColumns; ++col)
        {
            std::cout << kBoard[row][col];
        }
        cout << endl;
    }
}
void showstats() {
    cout << "Allien      : Life " << Alient_health << ", Attack " << Alein_attack << endl;
    for (int i = 1; i <= total_zombies; i++) {
        cout << "Zoombie " << i << " : Life " << zoombie_life << ", Attack " << zoombie_attack << ", Range " << zoombie_range << endl;;
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
            
            CreatedefaultBoard();
            showstats();
        }
        else if (choice == 2) {
            if (allien == true) {
                cout << "Alliens turn " << endl;
                MoveAlien();
                allien = false;
                zoombie = true;
            }
            else if (zoombie == true) {
                cout << "Zoombie turn " << endl;
                MoveZombies();
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
