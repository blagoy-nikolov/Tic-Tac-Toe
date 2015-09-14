#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const char USER_ONE = 'X';
const char USER_TWO = 'O';
void print_matrix(const int &n, const char matrix[100][100])
{
	cout << endl << "  ";
	for (int i = 0; i < n; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << " ";
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
void check_for_err(const int &n, int &col,int &row, const char matrix[100][100])
{
	while (col>n - 1 || row > n - 1||row<0||col<0||matrix[row][col]!='.')
	{
		cout << "Wrong position (either already set or not existing)" << endl;
		cout << "Please enter again: "; cin >> col >> row;
	}
}
bool check_for_win(const int &n, const int &col, const int &row, const char matrix[100][100], const char &user)
{
	int counter=0;
	for (int j = col-5; j <= col+5; j++)
	{
		if (j < 0) continue;
		if (j > n-1) break;
		if (matrix[row][j] == user) counter++;
		if (counter >= 5) return true;
		if (matrix[row][j + 1] != user) counter = 0;
	}
	counter = 0;
	for (int i= row - 5; i <= row + 5; i++)
	{
		if (i < 0) continue;
		if (i > n - 1) break;
		if (matrix[i][col] == user) counter++;
		if (counter >= 5) return true;
		if (matrix[i+1][col] != user) counter = 0;
	}
	counter = 0;
	for (int i = row - 5; i <= row + 5; i++)
	{
		if (i < 0) continue;
		if (i > n - 1) break;
		if (matrix[i][i] == user) counter++;
		if (counter >= 5) return true;
		if (matrix[i + 1][i+1] != user) counter = 0;
	}
	counter = 0;
	for (int i = row-5; i <= row+5; i++)
	{
		if (i < 0) continue;
		if (i > n - 1) break;
		if (matrix[i][n - i] == user) counter++;
		if (counter >= 5) return true;
		if (matrix[i+1][n - i - 1] != user) counter = 0;
	}

	return false;


}
bool isdot(const char s)
{
	return s == '.';
}
int main()
{
	char matrix[100][100];
	int n;
	cout << "N=";
		cin >> n;
		if (n <= 5)
		{
			cout << "N must be bigger! " << endl;
			goto end;
		}
	
	int elem_count = sizeof(matrix) / sizeof(matrix[0][0]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = '.';
		}
	}
	cout << "User one: X" << endl << "User two: O"<<endl;
	
	do
	{
	print_matrix(n, matrix);
	int row = 0, col = 0;
	cout << "Please enter position for ";
	cout << "user one (row and col): "; cin >> row >> col;
	check_for_err(n, col, row, matrix);
	matrix[row][col] = 'X';
	if (check_for_win(n, col, row, matrix, USER_ONE))
	{
		cout << "User one win!" << endl;
		break;
	}
	system("CLS");
	print_matrix(n, matrix);
	cout << "Please enter position for ";
	cout << "user two (row and col): "; cin >> row >> col;
	check_for_err(n, col, row, matrix);
	matrix[row][col] = 'O';
	if (check_for_win(n, col, row, matrix, USER_TWO))
	{
		cout << "User two win!" << endl;
		break;
	}
	system("CLS");
	print_matrix(n, matrix);
	system("CLS");
	} while (any_of(matrix[0], matrix[0] + elem_count, isdot));


	end:
	system("Pause");
	return 0;
}
