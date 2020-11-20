#include <iostream>
#include <Windows.h>
#include <conio.h>

// ========= functions to contorl the console window ========
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

// ========== Functions to print out the Main Menu =========

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




int main()
{
    char cInput = ' ';

    PrintLoadScreen();
    PrintMenu();
    std::cout << "\n\n";

    cInput = _getch();
    FlashSelectedOption(cInput);

    switch (cInput)
    {
    case '1':
        system("cls");
        std::cout << "Menu option 1";
        system("pause");
        break;
    case '2':
        system("cls");
        std::cout << "Menu option 2";
        system("pause");
        break;
    case 'e':
    case 'E':
        system("cls");
        system("pause");
        break;
    default:
        Beep(500, 500);
        break;
    }

	return 0;
}
