#include <iostream>
#include <Windows.h>
#include <conio.h>

// ========= functions to control the console window ========
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
void SetCursorPosition(short x, short y)
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

// ========== Functions to print out the load screen. ========= 
void PrintBoarderAnimation()
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
void PrintLoadingAnimation()
{

    
    SetCursorPosition(0,6);

    ChangeTextColour(12);
    std::cout << "\t _                     _\n";
    Sleep(75);
    std::cout << "\t| |                   | (_)             \n";
    Sleep(75);
    std::cout << "\t| |     ___   __ _  __| |_ _ __   __ _  \n";
    Sleep(75);
    std::cout << "\t| |    / _ \\ / _` |/ _` | | '_ \\ / _` | \n";
    Sleep(75);
    std::cout << "\t| |___| (_) | (_| | (_| | | | | | (_| | \n";
    Sleep(75);
    std::cout << "\t\\_____/\\___/ \\__,_|\\__,_|_|_| |_|\\__, | \n";
    Sleep(75);
    std::cout << "\t                                  __/ | \n";
    Sleep(75);
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
void PrintLoadScreen()
{
    ChangeConsoleWindowSize(450, 350);
    PrintBoarderAnimation();
    PrintLoadingAnimation();
    system("cls");
}

// ========== Functions to print out the Main Menu and get input for it =========

//Printing the menu 
void printMenuTitleAnimation()
{
    int iSleep = 50;
    Sleep(iSleep);
    std::cout << "\t\t\t _    _\n";
    Sleep(iSleep);
    std::cout << "\t\t\t|  \\/  |                 \n";
    Sleep(iSleep);
    std::cout << "\t\t\t| .  . | ___ _ __  _   _                 \n";
    Sleep(iSleep);
    std::cout << "\t          ===== | |\\/| |/ _ \\ '_ \\| | | | =====\n";
    Sleep(iSleep);
    std::cout << "\t     ========== | |  | |  __/ | | | |_| | ==========  \n";
    Sleep(iSleep);
    std::cout << "\t=============== \\_|  |_/\\___|_| |_|\\__,_| ===============\n";
    Sleep(iSleep);
}
void PrintMenuOptionsAnimation()
{
    
    int iSleep = 50;

    std::cout << "\t\t\t __   __   ______ _   _______\n";
    Sleep(iSleep);
    std::cout << "\t\t\t/  |  \\ \\  | ___ \\ | | | ___ \\\n";
    Sleep(iSleep);
    std::cout << "\t\t\t`| |   | | | |_/ / | | | |_/ /\n";
    Sleep(iSleep);
    std::cout << "\t\t\t | |   | | |  __/| | | |  __/\n";
    Sleep(iSleep);
    std::cout << "\t\t\t_| |_  | | | |   \\ \\_/ / |\n";
    Sleep(iSleep);
    std::cout << "\t\t\t\\___/  | | \\_|    \\___/\\_|\n";
    Sleep(iSleep);
    std::cout << "\t\t\t      /_/             \n";
    Sleep(iSleep);
    std::cout << "\n";
    std::cout << "\t\t\t _____  __    _____ ______ _   _ \n";
    Sleep(iSleep);
    std::cout << "\t\t\t/ __  \\ \\ \\  /  __ \\| ___ \\ | | |\n";
    Sleep(iSleep);
    std::cout << "\t\t\t`' / /'  | | | /  \\/| |_/ / | | |\n";
    Sleep(iSleep);
    std::cout << "\t\t\t  / /    | | | |    |  __/| | | |\n";
    Sleep(iSleep);
    std::cout << "\t\t\t./ /___  | | | \\__/\\| |   | |_| |\n";
    Sleep(iSleep);
    std::cout << "\t\t\t\\_____/  | |  \\____/\\_|    \\___/\n";
    Sleep(iSleep);
    std::cout << "\t\t\t        /_/\n";
    Sleep(iSleep);
    std::cout << "\n";
    std::cout << "\t\t\t _____  __    _____     _ _\n";
    Sleep(iSleep);
    std::cout << "\t\t\t|  ___| \\ \\  |  ___|   (_) |\n";
    Sleep(iSleep);
    std::cout << "\t\t\t| |__    | | | |____  ___| |_\n";
    Sleep(iSleep);
    std::cout << "\t\t\t|  __|   | | |  __\\ \\/ / | __|\n";
    Sleep(iSleep);
    std::cout << "\t\t\t| |___   | | | |___>  <| | |_\n";
    Sleep(iSleep);
    std::cout << "\t\t\t\\____/   | | \\____/_/\\_\\_|\\__|\n";
    Sleep(iSleep);
    std::cout << "\t\t\t        /_/\n";

}
void PrintMenu()
{
    ChangeConsoleWindowSize(700, 600);
    ChangeTextColour(15);

    printMenuTitleAnimation();
    PrintMenuOptionsAnimation();
}
char GetMenuInput()
{
    char cInput;
    do
    {
        // will make a beeping noise every time the user fails to input a correct value 
        // ony 1 2 or e will be accepted 
        cInput = _getch();
        if (cInput != '1' && cInput != '2' && cInput != 'e' && cInput != 'E')
        {
            Beep(500, 500);
        }
    } while (cInput != '1' && cInput != '2' && cInput != 'e' && cInput != 'E');

    return cInput;
}

//flashing the option that the user inputs 
void FlashPVPOption()
{
    ChangeTextColour(10);
    SetCursorPosition(5, 6);
    std::cout << "\t\t\t __   __   ______ _   _______";
    SetCursorPosition(5, 7);
    std::cout << "\t\t\t/  |  \\ \\  | ___ \\ | | | ___ \\";
    SetCursorPosition(5, 8);
    std::cout << "\t\t\t`| |   | | | |_/ / | | | |_/ /";
    SetCursorPosition(5, 9);
    std::cout << "\t\t\t | |   | | |  __/| | | |  __/";
    SetCursorPosition(5, 10);
    std::cout << "\t\t\t_| |_  | | | |   \\ \\_/ / |";
    SetCursorPosition(5, 11);
    std::cout << "\t\t\t\\___/  | | \\_|    \\___/\\_|";
    SetCursorPosition(5, 12);
    std::cout << "\t\t\t      /_/             ";

    Sleep(350);

    ChangeTextColour(15);
    SetCursorPosition(5, 6);
    std::cout << "\t\t\t __   __   ______ _   _______";
    SetCursorPosition(5, 7);
    std::cout << "\t\t\t/  |  \\ \\  | ___ \\ | | | ___ \\";
    SetCursorPosition(5, 8);
    std::cout << "\t\t\t`| |   | | | |_/ / | | | |_/ /";
    SetCursorPosition(5, 9);
    std::cout << "\t\t\t | |   | | |  __/| | | |  __/";
    SetCursorPosition(5, 10);
    std::cout << "\t\t\t_| |_  | | | |   \\ \\_/ / |";
    SetCursorPosition(5, 11);
    std::cout << "\t\t\t\\___/  | | \\_|    \\___/\\_|";
    SetCursorPosition(5, 12);
    std::cout << "\t\t\t      /_/             ";

    Sleep(350);

    ChangeTextColour(10);
    SetCursorPosition(5, 6);
    std::cout << "\t\t\t __   __   ______ _   _______";
    SetCursorPosition(5, 7);
    std::cout << "\t\t\t/  |  \\ \\  | ___ \\ | | | ___ \\";
    SetCursorPosition(5, 8);
    std::cout << "\t\t\t`| |   | | | |_/ / | | | |_/ /";
    SetCursorPosition(5, 9);
    std::cout << "\t\t\t | |   | | |  __/| | | |  __/";
    SetCursorPosition(5, 10);
    std::cout << "\t\t\t_| |_  | | | |   \\ \\_/ / |";
    SetCursorPosition(5, 11);
    std::cout << "\t\t\t\\___/  | | \\_|    \\___/\\_|";
    SetCursorPosition(5, 12);
    std::cout << "\t\t\t      /_/             ";

    Sleep(350);

    ChangeTextColour(15);
    SetCursorPosition(5, 6);
    std::cout << "\t\t\t __   __   ______ _   _______";
    SetCursorPosition(5, 7);
    std::cout << "\t\t\t/  |  \\ \\  | ___ \\ | | | ___ \\";
    SetCursorPosition(5, 8);
    std::cout << "\t\t\t`| |   | | | |_/ / | | | |_/ /";
    SetCursorPosition(5, 9);
    std::cout << "\t\t\t | |   | | |  __/| | | |  __/";
    SetCursorPosition(5, 10);
    std::cout << "\t\t\t_| |_  | | | |   \\ \\_/ / |";
    SetCursorPosition(5, 11);
    std::cout << "\t\t\t\\___/  | | \\_|    \\___/\\_|";
    SetCursorPosition(5, 12);
    std::cout << "\t\t\t      /_/             ";

    Sleep(350);

    ChangeTextColour(10);
    SetCursorPosition(5, 6);
    std::cout << "\t\t\t __   __   ______ _   _______";
    SetCursorPosition(5, 7);
    std::cout << "\t\t\t/  |  \\ \\  | ___ \\ | | | ___ \\";
    SetCursorPosition(5, 8);
    std::cout << "\t\t\t`| |   | | | |_/ / | | | |_/ /";
    SetCursorPosition(5, 9);
    std::cout << "\t\t\t | |   | | |  __/| | | |  __/";
    SetCursorPosition(5, 10);
    std::cout << "\t\t\t_| |_  | | | |   \\ \\_/ / |";
    SetCursorPosition(5, 11);
    std::cout << "\t\t\t\\___/  | | \\_|    \\___/\\_|";
    SetCursorPosition(5, 12);
    std::cout << "\t\t\t      /_/             ";
}
void FlashCPUOption()
{
    ChangeTextColour(10);
    SetCursorPosition(5, 14);
    std::cout << "\t\t\t _____  __    _____ ______ _   _ \n";
    SetCursorPosition(5, 15);
    std::cout << "\t\t\t/ __  \\ \\ \\  /  __ \\| ___ \\ | | |\n";
    SetCursorPosition(5, 16);
    std::cout << "\t\t\t`' / /'  | | | /  \\/| |_/ / | | |\n";
    SetCursorPosition(5, 17);
    std::cout << "\t\t\t  / /    | | | |    |  __/| | | |\n";
    SetCursorPosition(5, 18);
    std::cout << "\t\t\t./ /___  | | | \\__/\\| |   | |_| |\n";
    SetCursorPosition(5, 19);
    std::cout << "\t\t\t\\_____/  | |  \\____/\\_|    \\___/\n";
    SetCursorPosition(5, 20);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(15);
    SetCursorPosition(5, 14);
    std::cout << "\t\t\t _____  __    _____ ______ _   _ \n";
    SetCursorPosition(5, 15);
    std::cout << "\t\t\t/ __  \\ \\ \\  /  __ \\| ___ \\ | | |\n";
    SetCursorPosition(5, 16);
    std::cout << "\t\t\t`' / /'  | | | /  \\/| |_/ / | | |\n";
    SetCursorPosition(5, 17);
    std::cout << "\t\t\t  / /    | | | |    |  __/| | | |\n";
    SetCursorPosition(5, 18);
    std::cout << "\t\t\t./ /___  | | | \\__/\\| |   | |_| |\n";
    SetCursorPosition(5, 19);
    std::cout << "\t\t\t\\_____/  | |  \\____/\\_|    \\___/\n";
    SetCursorPosition(5, 20);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(10);
    SetCursorPosition(5, 14);
    std::cout << "\t\t\t _____  __    _____ ______ _   _ \n";
    SetCursorPosition(5, 15);
    std::cout << "\t\t\t/ __  \\ \\ \\  /  __ \\| ___ \\ | | |\n";
    SetCursorPosition(5, 16);
    std::cout << "\t\t\t`' / /'  | | | /  \\/| |_/ / | | |\n";
    SetCursorPosition(5, 17);
    std::cout << "\t\t\t  / /    | | | |    |  __/| | | |\n";
    SetCursorPosition(5, 18);
    std::cout << "\t\t\t./ /___  | | | \\__/\\| |   | |_| |\n";
    SetCursorPosition(5, 19);
    std::cout << "\t\t\t\\_____/  | |  \\____/\\_|    \\___/\n";
    SetCursorPosition(5, 20);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(15);
    SetCursorPosition(5, 14);
    std::cout << "\t\t\t _____  __    _____ ______ _   _ \n";
    SetCursorPosition(5, 15);
    std::cout << "\t\t\t/ __  \\ \\ \\  /  __ \\| ___ \\ | | |\n";
    SetCursorPosition(5, 16);
    std::cout << "\t\t\t`' / /'  | | | /  \\/| |_/ / | | |\n";
    SetCursorPosition(5, 17);
    std::cout << "\t\t\t  / /    | | | |    |  __/| | | |\n";
    SetCursorPosition(5, 18);
    std::cout << "\t\t\t./ /___  | | | \\__/\\| |   | |_| |\n";
    SetCursorPosition(5, 19);
    std::cout << "\t\t\t\\_____/  | |  \\____/\\_|    \\___/\n";
    SetCursorPosition(5, 20);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(10);
    SetCursorPosition(5, 14);
    std::cout << "\t\t\t _____  __    _____ ______ _   _ \n";
    SetCursorPosition(5, 15);
    std::cout << "\t\t\t/ __  \\ \\ \\  /  __ \\| ___ \\ | | |\n";
    SetCursorPosition(5, 16);
    std::cout << "\t\t\t`' / /'  | | | /  \\/| |_/ / | | |\n";
    SetCursorPosition(5, 17);
    std::cout << "\t\t\t  / /    | | | |    |  __/| | | |\n";
    SetCursorPosition(5, 18);
    std::cout << "\t\t\t./ /___  | | | \\__/\\| |   | |_| |\n";
    SetCursorPosition(5, 19);
    std::cout << "\t\t\t\\_____/  | |  \\____/\\_|    \\___/\n";
    SetCursorPosition(5, 20);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);
}
void FlashExitOption() 
{
    ChangeTextColour(10);
    SetCursorPosition(5, 22);
    std::cout << "\t\t\t _____  __    _____     _ _\n";
    SetCursorPosition(5, 23);
    std::cout << "\t\t\t|  ___| \\ \\  |  ___|   (_) |\n";
    SetCursorPosition(5, 24);
    std::cout << "\t\t\t| |__    | | | |____  ___| |_\n";
    SetCursorPosition(5, 25);
    std::cout << "\t\t\t|  __|   | | |  __\\ \\/ / | __|\n";
    SetCursorPosition(5, 26);
    std::cout << "\t\t\t| |___   | | | |___>  <| | |_\n";
    SetCursorPosition(5, 27);
    std::cout << "\t\t\t\\____/   | | \\____/_/\\_\\_|\\__|\n";
    SetCursorPosition(5, 28);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(15);
    SetCursorPosition(5, 22);
    std::cout << "\t\t\t _____  __    _____     _ _\n";
    SetCursorPosition(5, 23);
    std::cout << "\t\t\t|  ___| \\ \\  |  ___|   (_) |\n";
    SetCursorPosition(5, 24);
    std::cout << "\t\t\t| |__    | | | |____  ___| |_\n";
    SetCursorPosition(5, 25);
    std::cout << "\t\t\t|  __|   | | |  __\\ \\/ / | __|\n";
    SetCursorPosition(5, 26);
    std::cout << "\t\t\t| |___   | | | |___>  <| | |_\n";
    SetCursorPosition(5, 27);
    std::cout << "\t\t\t\\____/   | | \\____/_/\\_\\_|\\__|\n";
    SetCursorPosition(5, 28);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(10);
    SetCursorPosition(5, 22);
    std::cout << "\t\t\t _____  __    _____     _ _\n";
    SetCursorPosition(5, 23);
    std::cout << "\t\t\t|  ___| \\ \\  |  ___|   (_) |\n";
    SetCursorPosition(5, 24);
    std::cout << "\t\t\t| |__    | | | |____  ___| |_\n";
    SetCursorPosition(5, 25);
    std::cout << "\t\t\t|  __|   | | |  __\\ \\/ / | __|\n";
    SetCursorPosition(5, 26);
    std::cout << "\t\t\t| |___   | | | |___>  <| | |_\n";
    SetCursorPosition(5, 27);
    std::cout << "\t\t\t\\____/   | | \\____/_/\\_\\_|\\__|\n";
    SetCursorPosition(5, 28);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(15);
    SetCursorPosition(5, 22);
    std::cout << "\t\t\t _____  __    _____     _ _\n";
    SetCursorPosition(5, 23);
    std::cout << "\t\t\t|  ___| \\ \\  |  ___|   (_) |\n";
    SetCursorPosition(5, 24);
    std::cout << "\t\t\t| |__    | | | |____  ___| |_\n";
    SetCursorPosition(5, 25);
    std::cout << "\t\t\t|  __|   | | |  __\\ \\/ / | __|\n";
    SetCursorPosition(5, 26);
    std::cout << "\t\t\t| |___   | | | |___>  <| | |_\n";
    SetCursorPosition(5, 27);
    std::cout << "\t\t\t\\____/   | | \\____/_/\\_\\_|\\__|\n";
    SetCursorPosition(5, 28);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);

    ChangeTextColour(10);
    SetCursorPosition(5, 22);
    std::cout << "\t\t\t _____  __    _____     _ _\n";
    SetCursorPosition(5, 23);
    std::cout << "\t\t\t|  ___| \\ \\  |  ___|   (_) |\n";
    SetCursorPosition(5, 24);
    std::cout << "\t\t\t| |__    | | | |____  ___| |_\n";
    SetCursorPosition(5, 25);
    std::cout << "\t\t\t|  __|   | | |  __\\ \\/ / | __|\n";
    SetCursorPosition(5, 26);
    std::cout << "\t\t\t| |___   | | | |___>  <| | |_\n";
    SetCursorPosition(5, 27);
    std::cout << "\t\t\t\\____/   | | \\____/_/\\_\\_|\\__|\n";
    SetCursorPosition(5, 28);
    std::cout << "\t\t\t        /_/\n";

    Sleep(350);
}
void FlashSelectedOption(char cInput)
{
    switch (cInput)
    {
    case '1':
        FlashPVPOption();
        break;
    case '2':
        FlashCPUOption();
        break;
    case 'e':
    case 'E':
        FlashExitOption();
        break;
    default:
        Beep(500, 500);
        break;
    }

}

// ========= Functions for Printing Out the Game Screen =========


void PrintGameTitle()
{
    int iSleep = 100;

    ChangeTextColour(15);
    SetCursorPosition(0, 6);
    std::cout << "============================================================================================";
    SetCursorPosition(0, 0);

    ChangeTextColour(11);
    Sleep(iSleep);
    std::cout << "\t\t\t    \\_/ |_|\\___|   \\_/\\__,_|\\___|   \\_/\\___/ \\___|\n";

    ChangeTextColour(15);
    SetCursorPosition(0, 6);
    std::cout << "============================================================================================";
    SetCursorPosition(0, 0);

    ChangeTextColour(11);
    Sleep(iSleep);
    std::cout << "\t\t\t    | | | | (__    | | (_| | (__    | | (_) |  __/\n";
    std::cout << "\t\t\t    \\_/ |_|\\___|   \\_/\\__,_|\\___|   \\_/\\___/ \\___|\n";

    ChangeTextColour(15);
    SetCursorPosition(0, 6);
    std::cout << "============================================================================================";
    SetCursorPosition(0, 0);

    ChangeTextColour(11);
    Sleep(iSleep);
    std::cout << "\t\t\t    | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\ \n";
    std::cout << "\t\t\t    | | | | (__    | | (_| | (__    | | (_) |  __/\n";
    std::cout << "\t\t\t     \\_/ |_|\\___|   \\_/\\__,_|\\___|   \\_/\\___/ \\___|\n";

    ChangeTextColour(15);
    SetCursorPosition(0, 6);
    std::cout << "============================================================================================";
    SetCursorPosition(0, 0);

    ChangeTextColour(11);
    Sleep(iSleep);
    std::cout << "\t\t\t    | |  _  ___    | | __ _  ___    | | ___   ___  \n";
    std::cout << "\t\t\t    | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\ \n";
    std::cout << "\t\t\t    | | | | (__    | | (_| | (__    | | (_) |  __/\n";
    std::cout << "\t\t\t     \\_/ |_|\\___|   \\_/\\__,_|\\___|   \\_/\\___/ \\___|\n";

    ChangeTextColour(15);
    SetCursorPosition(0, 6);
    std::cout << "============================================================================================";
    SetCursorPosition(0, 0);

    ChangeTextColour(11);
    Sleep(iSleep);
    std::cout << "\t\t\t  |_   _(_)      |_   _|          |_   _|         \n";
    std::cout << "\t\t\t    | |  _  ___    | | __ _  ___    | | ___   ___  \n";
    std::cout << "\t\t\t    | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\ \n";
    std::cout << "\t\t\t    | | | | (__    | | (_| | (__    | | (_) |  __/\n";
    std::cout << "\t\t\t    \\_/ |_|\\___|   \\_/\\__,_|\\___|   \\_/\\___/ \\___|\n";

    ChangeTextColour(15);
    SetCursorPosition(0, 6);
    std::cout << "============================================================================================";
    SetCursorPosition(0, 0);

    ChangeTextColour(11);
    Sleep(iSleep);
    std::cout << "\t\t\t   _____ _        _____            _____          \n";
    std::cout << "\t\t\t  |_   _(_)      |_   _|          |_   _|         \n";
    std::cout << "\t\t\t    | |  _  ___    | | __ _  ___    | | ___   ___  \n";
    std::cout << "\t\t\t    | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\ \n";
    std::cout << "\t\t\t    | | | | (__    | | (_| | (__    | | (_) |  __/\n";
    std::cout << "\t\t\t    \\_/ |_|\\___|   \\_/\\__,_|\\___|   \\_/\\___/ \\___|";
}
void PrintGameBoard()
{
    int iSleep = 25;
    ChangeTextColour(15);
    SetCursorPosition(0, 7);

                                                            Sleep(iSleep);
    std::cout << "  __      _    _____   _    _____    \n"; Sleep(iSleep);
    std::cout << " /  |    | |  / __  \\ | |  |____ |  \n"; Sleep(iSleep);
    std::cout << " `| |    | |  `' / /' | |      / /   \n"; Sleep(iSleep);
    std::cout << "  | |    | |    / /   | |      \\ \\ \n"; Sleep(iSleep);
    std::cout << " _| |_   | |  ./ /___ | |  .___/ /   \n"; Sleep(iSleep);
    std::cout << " \\___/   | |  \\_____/ | |  \\____/ \n"; Sleep(iSleep);
    std::cout << "         | |          | |            \n"; Sleep(iSleep);
    std::cout << "         |_|          |_|            \n"; Sleep(iSleep);
    std::cout << " ______ _| |_ ______ _| |_ ______    \n"; Sleep(iSleep);
    std::cout << "|______|_   _|______|_   _|______|   \n"; Sleep(iSleep);
    std::cout << "    ___  |_|   _____  |_|    ____    \n"; Sleep(iSleep);
    std::cout << "   /   | | |  |  ___| | |   / ___|   \n"; Sleep(iSleep);
    std::cout << "  / /| | | |  |___ \\  | |  / /___   \n"; Sleep(iSleep);
    std::cout << " / /_| | | |      \\ \\ | |  | ___ \\\n"; Sleep(iSleep);
    std::cout << " \\___  | | |  /\\__/ / | |  | \\_/ |\n"; Sleep(iSleep);
    std::cout << "     |_/ | |  \\____/  | |  \\_____/ \n"; Sleep(iSleep);
    std::cout << "         | |          | |            \n"; Sleep(iSleep);
    std::cout << "         |_|          |_|            \n"; Sleep(iSleep);
    std::cout << " ______ _| |_ ______ _| |_ ______    \n"; Sleep(iSleep);
    std::cout << "|______|_   _|______|_   _|______|   \n"; Sleep(iSleep);
    std::cout << "  _____  |_|   _____  |_|   _____    \n"; Sleep(iSleep);
    std::cout << " |___  / | |  |  _  | | |  |  _  |   \n"; Sleep(iSleep);
    std::cout << "    / /  | |   \\ V /  | |  | |_| |  \n"; Sleep(iSleep);
    std::cout << "   / /   | |   / _ \\  | |  \\____ | \n"; Sleep(iSleep);
    std::cout << " ./ /    | |  | |_| | | |  .___/ /   \n"; Sleep(iSleep);
    std::cout << " \\_/     | |  \\_____/ | |  \\____/ \n"; Sleep(iSleep);
    std::cout << "         | |          | |            \n"; Sleep(iSleep);
    std::cout << "         |_|          |_|         ";      Sleep(iSleep);
}
void PrintRules()
{
    int i = 10;
    ChangeTextColour(13);
    SetCursorPosition(55, i++);
    std::cout << "   ___Rules___";

    ChangeTextColour(15);
    SetCursorPosition(55, i++);
    std::cout << "You must get three ";
    SetCursorPosition(55, i++);
    std::cout << "in a row to win";
    SetCursorPosition(55, i++);
    std::cout << "";
    SetCursorPosition(55, i++);
    std::cout << "To make a move type a number";
    SetCursorPosition(55, i++);
    std::cout << "between 1 and 9 and your ";
    SetCursorPosition(55, i++);
    std::cout << "pice will be placed on the ";
    SetCursorPosition(55, i++);
    std::cout << "suqare that contains that number";
    SetCursorPosition(55, i++);

    std::cout << " ";
    SetCursorPosition(55, i++);
    std::cout << "Player 1 = ";
    ChangeTextColour(11);
    std::cout << "X";
    ChangeTextColour(15);
    SetCursorPosition(55, i++);

    std::cout << "Player 2 = ";
    ChangeTextColour(12);
    std::cout << "O";

    SetCursorPosition(55, i++);
    SetCursorPosition(55, i++);
    ChangeTextColour(13);
    std::cout << "    ___Win___";

    ChangeTextColour(15);
    SetCursorPosition(55, i++);
    std::cout << "XXX   ...   ...";
    SetCursorPosition(55, i++);
    std::cout << "...   XXX   ...";
    SetCursorPosition(55, i++);
    std::cout << "...   ...   XXX";
    SetCursorPosition(55, i++);
    SetCursorPosition(55, i++);
    std::cout << "X..   .X.   ..X";
    SetCursorPosition(55, i++);
    std::cout << "X..   .X.   ..X";
    SetCursorPosition(55, i++);
    std::cout << "X..   .X.   ..X";
    SetCursorPosition(55, i++);
    SetCursorPosition(55, i++);
    std::cout << "   ..X   X..";
    SetCursorPosition(55, i++);
    std::cout << "   .X.   .X.";
    SetCursorPosition(55, i++);
    std::cout << "   X..   ..X";
    SetCursorPosition(55, i++);

    
}
void InitializeGame()
{
    system("cls");
    PrintGameTitle();
    PrintGameBoard();
    PrintRules();
}


void PrintXPice(int iXOffSet, int iYOffSet) 
{
    ChangeTextColour(11);
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "__   __ ";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "\\ \\ / /";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << " \\ V /  ";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << " /   \\  ";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "/ /^\\ \\";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "\\/   \\/ ";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "";
}
void PrintYPice(int iXOffSet, int iYOffSet)
{
    ChangeTextColour(12);
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << " _____ ";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "|  _  |";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "| | | |";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "| | | |";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "\\ \\_/ /";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << " \\___/ ";
    SetCursorPosition(iXOffSet, iYOffSet++);
    std::cout << "";
}
void UpdateGameVisuals(char cInput, int iPlayerturn)
{
    int iXOffset = 0;
    int iYOffset = 0;

    if(cInput == '1')
    {
        iXOffset = 1;
        iYOffset = 7;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }
        
    }
    if (cInput == '2')
    {
        iXOffset = 14;
        iYOffset = 7;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    if (cInput == '3')
    {
        iXOffset = 27;
        iYOffset = 7;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    if (cInput == '4')
    {
        iXOffset = 1;
        iYOffset = 17;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    if (cInput == '5')
    {
        iXOffset = 14;
        iYOffset = 17;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    if (cInput == '6')
    {
        iXOffset = 27;
        iYOffset = 17;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    if (cInput == '7')
    {
        iXOffset = 1;
        iYOffset = 27;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    if (cInput == '8')
    {
        iXOffset = 14;
        iYOffset = 27;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    if (cInput == '9')
    {
        iXOffset = 27;
        iYOffset = 27;

        if (iPlayerturn == 0)
        {
            PrintXPice(iXOffset, iYOffset);
        }
        else
        {
            PrintYPice(iXOffset, iYOffset);
        }

    }
    


    
}



// ======== Functions for the Games Logic =========
bool IsSapceFree(char cInput, char boardArray[3][3])
{
    if (cInput == '1')
    {
        return boardArray[0][0] == '.' ? true :  false;
    }
    else if (cInput == '2')
    {
        return boardArray[0][1] == '.' ? true : false;
    }
    else if (cInput == '3')
    {
        return boardArray[0][2] == '.' ? true : false;
    }
    else if (cInput == '4')
    {
        return boardArray[1][0] == '.' ? true : false;
    }
    else if (cInput == '5')
    {
        return boardArray[1][1] == '.' ? true : false;
    }
    else if (cInput == '6')
    {
        return boardArray[1][2] == '.' ? true : false;
    }
    else if (cInput == '7')
    {
        return boardArray[2][0] == '.' ? true : false;
    }
    else if (cInput == '8')
    {
        return boardArray[2][1] == '.' ? true : false;
    }
    else if (cInput == '9')
    {
        return boardArray[2][2] == '.' ? true : false;
    }
    
}
void UpdateGameState(int PlayerTurn, char cInput, char BoardArray[3][3])
{
    if (cInput == '1')
    {
        PlayerTurn == 0 ? BoardArray[0][0] = 'x': BoardArray[0][0] = 'o';
    }
    else if (cInput == '2')
    {
        PlayerTurn == 0 ? BoardArray[0][1] = 'x' : BoardArray[0][1] = 'o';
    }
    else if (cInput == '3')
    {
        PlayerTurn == 0 ? BoardArray[0][2] = 'x' : BoardArray[0][2] = 'o';
    }
    else if (cInput == '4')
    {
        PlayerTurn == 0 ? BoardArray[1][0] = 'x' : BoardArray[1][0] = 'o';
    }
    else if (cInput == '5')
    {
        PlayerTurn == 0 ? BoardArray[1][1] = 'x' : BoardArray[1][1] = 'o';
    }
    else if (cInput == '6')
    {
        PlayerTurn == 0 ? BoardArray[1][2] = 'x' : BoardArray[1][2] = 'o';
    }
    else if (cInput == '7')
    {
        PlayerTurn == 0 ? BoardArray[2][0] = 'x' : BoardArray[2][0] = 'o';
    }
    else if (cInput == '8')
    {
        PlayerTurn == 0 ? BoardArray[2][1] = 'x' : BoardArray[2][1] = 'o';
    }
    else if (cInput == '9')
    {
        PlayerTurn == 0 ? BoardArray[2][2] = 'x' : BoardArray[2][2] = 'o';
    }
}
bool IsBoardFull(char BoardArray[3][3])
{
    for (int  i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            if (BoardArray[i][j] == '.') 
            {
                return true;
            }
            
        }
    }
    return false;
}




int main()
{
    //startting Variables 
    char cInput = ' '; // is the only veriable used to get input 
    int iPlayerTurn = 0; // 0 = player ones turn || 2 = playe twos turn 
  
    bool bKeepPlaying = true;
    bool bFreeSpace = false;

    char GameStateArray[3][3] = { '.','.','.',    '.','.','.',    '.','.','.', };
    
    // laoding the game and getting menu input fromt he user 
    PrintLoadScreen();
    PrintMenu();
    cInput = GetMenuInput();
    FlashSelectedOption(cInput);

    while (cInput != 'e' &&  cInput != 'E')
    {
        switch (cInput)
        {
        case '1':
            InitializeGame();

            while (bKeepPlaying == true)
            {
                if (bKeepPlaying == true)
                {
                    while (bFreeSpace == false)
                    {
                        cInput = _getch();
                        bFreeSpace = IsSapceFree(cInput, GameStateArray);
                    }
                }

                UpdateGameState(iPlayerTurn, cInput, GameStateArray);
                UpdateGameVisuals(cInput, iPlayerTurn);

                if (iPlayerTurn == 0)
                {
                    iPlayerTurn++;
                }
                else
                {
                    iPlayerTurn--;
                }

                bFreeSpace = false;
                bKeepPlaying = IsBoardFull(GameStateArray);
            }
            
            system("cls");
            break;
        case '2':
            system("cls");
            std::cout << "Menu option 2";
            system("pause");
            system("cls");
            break;
        }

        PrintMenu();
        cInput = GetMenuInput();
        FlashSelectedOption(cInput);
        std::cout << "\n\n";
    }

    system("cls");
    std::cout << "Thanks for playing";
    



	return 0;
}
