#include <IOstream>  //allows for cin and cout
#include <conio.h>   //allows of _getch()
#include <stdlib.h> //allows for the use of system()
#include <ctime>    //allows for the creation of random numbers

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
void ManageBoard(char cInput, int iRow, int iColumn, char acBoard[3][3])
{
	

}
void PrintBorad(char acBoard[3][3])
{
	std::cout << "  1 2 3" << "\n";
	std::cout << "1 "<<acBoard[0][0] << "|" << acBoard[0][1] << "|" << acBoard[0][2] << "\n";
	std::cout << "  -+-+-" << "\n";
	std::cout << "2 "<<acBoard[1][0] << "|" << acBoard[1][1] << "|" << acBoard[1][2] << "\n";
	std::cout << "  -+-+-" << "\n";
	std::cout << "3 "<<acBoard[2][0] << "|" << acBoard[2][1] << "|" << acBoard[2][2] << "\n";

	std::cout << "\n" << "\n" << "\n" << "\n" << "\n";
}
void PlayerOneTurn(char acBoard[3][3])
{
	int iRow;
	int iColumn;

	std::cout << "Pick a Row: ";
	std::cin >> iRow;

	std::cout << "Pick a column";
	std::cin >> iColumn;

	acBoard[iRow - 1][iColumn - 1] = 'X';
}

void PlayerTwoTurn(char acBoard[3][3])
{
	int iRow;
	int iColumn;

	std::cout << "Pick a Row: ";
	std::cin >> iRow;

	std::cout << "Pick a column";
	std::cin >> iColumn;

	acBoard[iRow - 1][iColumn - 1] = '0';
}

void ComputersTurn(char acBoard[3][3])
{
	int iRow = 0;
	int iColumn = 0;

	do 
	{
		iRow = rand() % 3;
		iColumn = rand() % 3;

	} while (acBoard[iRow][iColumn] != '.');

	acBoard[iRow][iColumn] = '0';
	
}
void RunGame(char cMode, char acBoard[3][3]) 
{
	if (cMode == '1')
	{
		//player ones turn 
		PrintBorad(acBoard);
		PlayerOneTurn(acBoard);
		PrintBorad(acBoard);

		//player ones turn 
		PrintBorad(acBoard);
		PlayerTwoTurn(acBoard);
		PrintBorad(acBoard);
	}
	else if (cMode == '2')
	{
		//player ones turn 
		PrintBorad(acBoard);
		PlayerOneTurn(acBoard);
		

		//player ones turn 
	
		ComputersTurn(acBoard);
	

		//player ones turn 
		PrintBorad(acBoard);
		PlayerOneTurn(acBoard);
		

		//player ones turn 
		
		ComputersTurn(acBoard);
		PrintBorad(acBoard);
		
	}
	else if (cMode == 'e' || cMode == 'E')
	{
		system("cls");
		std::cout << "Thank you for playing";
	}


	
}


int main() {
	
	srand(time(NULL)); //Seeding the random number that the computer will use 

	char acGameBoard[3][3]; // the arry that will represent the board 
	//pre filling the array with . to make it look nice to the pleyer 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			acGameBoard[i][j] = '.';
		}
	}
	
	char cGameMode =Intro();
	RunGame(cGameMode, acGameBoard);


	return 0;
}