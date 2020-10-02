#include <IOstream>
#include <conio.h>
#include <stdlib.h>

// function to introduce the player to the game and ask for a game mode
char Intro() 
{
	std::cout << "Welcome to Tic-Tac-Toe" << "\n";
	std::cout << "Press any key to continue..." << "\n";

	_getch();
	system("cls");

	std::cout << "<<<Please Select Game Mode>>>" << "\n";
	std::cout << "Press 1 to play aginst a Human" << "\n";
	std::cout << "press 2 to play Aginst the Computer" << "\n";
	std::cout << "press E to Exit" << "\n";

	//getting user input
	char cPickMode;
	cPickMode = _getch();
	return cPickMode;
}
void PrintBorad(char cInput, int iRow, int iColumn)
{
	char acBoard[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			acBoard[i][j] = '.';
		}
	}
	std::cout << acBoard[0][0] << "|" << acBoard[0][1] << "|" << acBoard[0][2] << "\n";
	std::cout << "-+-+-" << "\n";
	std::cout << acBoard[1][0] << "|" << acBoard[1][1] << "|" << acBoard[1][2] << "\n";
	std::cout << "-+-+-" << "\n";
	std::cout << acBoard[2][0] << "|" << acBoard[2][1] << "|" << acBoard[2][2] << "\n";
}
void RunGame(char cMode) 
{
	if (cMode == '1')
	{
		PrintBorad('x', 2, 2);
	}
	else if (cMode == '2')
	{
		PrintBorad('x', 2, 2);
	}
	else if (cMode == 'e' || cMode == 'E')
	{
		system("cls");
		std::cout << "Thank you for playing";
	}


	
}


int main() {

	char cGameMode =Intro();
	RunGame(cGameMode);


	return 0;
}