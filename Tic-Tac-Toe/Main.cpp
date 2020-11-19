#include <iostream>
#include <Windows.h>

// changing the colour of the text based on an int paramneter 
void ChangeTextColour(int iCoulorValue)
{
    //0 = Black 
    //1 = Blue 
    //2 = Green 
    //3 = Aqua  
    //4 = Red 
    //5 = Purple
    //6 = Yellow 
    //7 = White 

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), iCoulorValue);
}
void SetCursorPosition(int x, int y)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x,y };
    SetConsoleCursorPosition(output, pos);
}
void ChangeConsoleWindowSize(int iXValue, int iYvalue)
{
    // changeing the size of the console window 
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);

    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, iXValue, iYvalue, TRUE);

}


void printBoarders()
{
    ChangeTextColour(15);

    int iUpperTopindex = 0;
    int iUpperMidindex = 0;
    int iUpperBotindex = 0;

    int iLowerTopindex = 0;
    int iLowerMidindex = 0;
    int iLowerBotindex = 0;

    bool bBoardersDrawn = false;

    while(!bBoardersDrawn)
    {
        if (iLowerBotindex <= 5)
        {
            SetCursorPosition(iUpperTopindex, 0);
            std::cout << "=";
            iUpperTopindex++;

            SetCursorPosition(iLowerBotindex, 18);
            std::cout << "=";
            iLowerBotindex++;
            Sleep(50);
        }
        else if (iLowerBotindex <= 10)
        {
            SetCursorPosition(iUpperTopindex, 0);
            std::cout << "=";
            iUpperTopindex++;

            SetCursorPosition(iUpperMidindex, 1);
            std::cout << "=";
            iUpperMidindex++;

            SetCursorPosition(iLowerBotindex, 18);
            std::cout << "=";
            iLowerBotindex++;

            SetCursorPosition(iLowerMidindex, 17);
            std::cout << "=";
            iLowerMidindex++;

            Sleep(50);
        }
        else if (iLowerBotindex <= 56)
        {
            SetCursorPosition(iUpperTopindex, 0);
            std::cout << "=";
            iUpperTopindex++;

            SetCursorPosition(iUpperMidindex, 1);
            std::cout << "=";
            iUpperMidindex++;

            SetCursorPosition(iUpperBotindex, 2);
            std::cout << "=";
            iUpperBotindex++;

            SetCursorPosition(iLowerBotindex, 18);
            std::cout << "=";
            iLowerBotindex++;

            SetCursorPosition(iLowerMidindex, 17);
            std::cout << "=";
            iLowerMidindex++;

            SetCursorPosition(iLowerTopindex, 16);
            std::cout << "=";
            iLowerTopindex++;

            Sleep(50);
        }
        else
        {
            if(iUpperMidindex <= 56)
            {
                SetCursorPosition(iUpperMidindex, 1);
                std::cout << "=";
                iUpperMidindex++;

                SetCursorPosition(iLowerMidindex, 17);
                std::cout << "=";
                iLowerMidindex++;
            }

            SetCursorPosition(iUpperBotindex, 2);
            std::cout << "=";
            iUpperBotindex++;

            

            SetCursorPosition(iLowerTopindex, 16);
            std::cout << "=";
            iLowerTopindex++;

            Sleep(50);
        }
        
        if (iLowerTopindex == 57) bBoardersDrawn = true;
    }
}
void PrintLoading()
{

    
    SetCursorPosition(0,6);

    ChangeTextColour(12);
    std::cout << "\t _                     _\n";
    std::cout << "\t| |                   | (_)             \n";
    std::cout << "\t| |     ___   __ _  __| |_ _ __   __ _  \n";
    std::cout << "\t| |    / _ \\ / _` |/ _` | | '_ \\ / _` | \n";
    std::cout << "\t| |___| (_) | (_| | (_| | | | | | (_| | \n";
    std::cout << "\t\\_____/\\___/ \\__,_|\\__,_|_|_| |_|\\__, | \n";
    std::cout << "\t                                  __/ | \n";
    std::cout << "\t                                 |___/  \n";

    Sleep(250);
    SetCursorPosition(0, 6);
    ChangeTextColour(11);
    std::cout << "\t _                     _";

    Sleep(250);
    SetCursorPosition(0, 7);
    std::cout << "\t| |                   | (_)             ";

    Sleep(250);
    SetCursorPosition(0, 8);
    std::cout << "\t| |     ___   __ _  __| |_ _ __   __ _  ";

    Sleep(250);
    SetCursorPosition(0, 9);
    std::cout << "\t| |    / _ \\ / _` |/ _` | | '_ \\ / _` | ";

    Sleep(250);
    SetCursorPosition(0, 10);
    std::cout << "\t| |___| (_) | (_| | (_| | | | | | (_| | ";

    Sleep(250);
    SetCursorPosition(0, 11);
    std::cout << "\t\\_____/\\___/ \\__,_|\\__,_|_|_| |_|\\__, | ";

    Sleep(250);
    SetCursorPosition(0, 12);
    std::cout << "\t                                  __/ | ";

    Sleep(250);
    SetCursorPosition(0, 13);
    std::cout << "\t                                 |___/  ";
    std::cout << "\n\n";
    std::cout << "\t\t";
    Sleep(50);
    system("Pause");
}

int main()
{
    ChangeConsoleWindowSize(450, 350);
    printBoarders();
    PrintLoading();
	return 0;
}
