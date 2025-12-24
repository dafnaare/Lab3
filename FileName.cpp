#include <iostream>
#include <random>
#include <Windows.h>
using namespace std;


void consoleErase(int N) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0, k = 0; i < N; i++, k = k + 4) {
		if ((i + 2) % 2 == 0) {
			for (int j = 0; j < N; j++) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << "    " << '\r';
				cout.flush();
				Sleep(100);
			}
		}
		else {
			for (int j = N - 1; j >= 0; j--) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << "    " << '\r';
				cout.flush();
				Sleep(100);
			}
		}
	}
	destCoord.X = 4 * N + 1;
	destCoord.Y = N;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << endl;
}


template<int row, int col>
void consoleOut(int(&arr)[row][col], int N) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0, k = 0; i < N; i++, k = k + 4) {
		if ((i + 2) % 2 == 0) {
			for (int j = 0; j < N; j++) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				printf("%3d", arr[i][j]);
				cout << '\r';
				//cout << arr[i][j] << '\r';
				cout.flush();
				Sleep(100);
			}
		}
		else {
			for (int j = N-1; j >= 0; j--) {
				destCoord.X = k;
				destCoord.Y = j + 1;
				SetConsoleCursorPosition(hStdout, destCoord);
				printf("%3d", arr[i][j]);
				cout << '\r';
				//cout << arr[i][j] << '\r';
				cout.flush();
				Sleep(100);
			}
		}
	}
	destCoord.X = 4*N + 1;
	destCoord.Y = N;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << endl;
}

void eraseN2str(int N) {
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	destCoord.X = 0;
	destCoord.Y = N + 1;
	SetConsoleCursorPosition(hStdout, destCoord);
	cout << "                                                                               ";
	SetConsoleCursorPosition(hStdout, destCoord);
}

template<int Nrow, int Ncol>
void arrayFilling(int(&arr)[Nrow][Ncol], int N, int z) {
	if (z==1) {
		int* end = *arr + N * N - 1;
		for (int* ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = rand() % N * N + 1;
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = rand() % N*N + 1;
			}
		}*/
	}
	else {
		int* end = *arr + N * N - 1;
		for (int* ptr = *arr; ptr <= end; ptr++)
		{
			*ptr = 0;
		}
	}
}

template<int N1row, int N1col>
void array1Filling(int(&arr)[N1row][N1col], int(&arr1)[N1row][N1col], int N) {
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			arr1[a][b] = arr[a][b];
		};
	};
}

template<int T21row, int T21col>
void task21(int(&arr)[T21row][T21col], int(&arr1)[T21row][T21col], int N) {
	Sleep(1000);
	cout << "Task 2.1 (1[N*N] -> 2[N*N] -> 3[N*N] -> 4[N*N] -> 1[N*N]): ";
	Sleep(1000);
	/*
	int* end = *arr + (N * N - 1)/4;
	int i = 0, j = N/2;
	for (int* ptr = *arr; ptr <= end; ptr++)
	{
		*ptr = *(*(arr1 + i) + (j + N / 2));
		i++;
		if (i = N / 2) {
			i = 0;
			j++;
		}
	}
	*/
	//4 в 1
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + i) + (j + N / 2));
		}
	}
	//1 во 2
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i - N / 2)) + j);
		}
	}
	//2 в 3
	for (int i = N / 2; i < N; i++) {
		for (int j = N / 2; j < N; j++) {
			arr[i][j] = *(*(arr1 + i) + (j - N / 2));
		}
	}
	//3 в 4
	for (int i = 0; i < N / 2; i++) {
		for (int j = N / 2; j < N; j++) {
			arr[i][j] = *(*(arr1 + (i + N / 2)) + j);
		}
	}
	//consoleErase(N);
	consoleOut(arr, N);
}

template<int T22row, int T22col>
void task22(int(&arr)[T22row][T22col], int(&arr1)[T22row][T22col], int N) {
	Sleep(1000);
	cout << "Task 2.2 (1[N*N] <-> 3[N*N], 2[N*N] <-> 4[N*N]): ";
	Sleep(1000);
	//1 и 3
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i+N/2)) + (j + N / 2));
			arr[i + N / 2][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	//2 и 4
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i - N / 2)) + (j + N / 2));
			arr[i - N / 2][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	consoleOut(arr, N);
}

template<int T23row, int T23col>
void task23(int(&arr)[T23row][T23col], int(&arr1)[T23row][T23col], int N) {
	Sleep(1000);
	cout << "Task 2.3 (1[N*N] <-> 4[N*N], 2[N*N] <-> 3[N*N]): ";
	Sleep(1000);
	//1 и 4
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + i) + (j + N / 2));
			arr[i][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	//2 и 3
	for (int i = N / 2; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + i) + (j + N / 2));
			arr[i][j + N / 2] = *(*(arr1 + i) + j);
		}
	}
	consoleOut(arr, N);
}

template<int T24row, int T24col>
void task24(int(&arr)[T24row][T24col], int(&arr1)[T24row][T24col], int N) {
	Sleep(1000);
	cout << "Task 2.4 (1[N*N] <-> 2[N*N], 3[N*N] <-> 4[N*N]): ";
	Sleep(1000);
	//1 и 2
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			arr[i][j] = *(*(arr1 + (i + N / 2)) + j);
			arr[i + N / 2][j] = *(*(arr1 + i) + j);
		}
	}
	//4 и 3
	for (int i = 0; i < N / 2; i++) {
		for (int j = N / 2; j < N; j++) {
			arr[i][j] = *(*(arr1 + (i + N / 2)) + j);
			arr[i + N / 2][j] = *(*(arr1 + i) + j);
		}
	}
	consoleOut(arr, N);
}

template<int T2row, int T2col>
void task2(int(&arr)[T2row][T2col], int (&arr1)[T2row][T2col], int N) {
	cout << "Task 2. Enter a number (1, 2, 3, 4 or 0 (to finish task 2)): ";
	int t2;
	cin >> t2;
	eraseN2str(N);
	switch (t2) {
	case 1: {
		task21(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 2: {
		task22(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 3: {
		task23(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 4: {
		task24(arr, arr1, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		task2(arr, arr1, N);
		break;
	}
	case 0: {
		return;
		break;
	}
	default: {
		cout << "You entered not 1, 2, 3, 4 or 0";
		Sleep(3000);
		eraseN2str(N);
		task2(arr, arr1, N);
		return;
		break;
	}
	}
}

//Shaker Sort
template<int Shrow, int Shcol>
void shakerSort(int(&arr)[Shrow][Shcol], int N) {
	int* right = *arr + N * N - 1;
	int* left = *arr;
	while (left <= right) {
		for (int *i = left; i < right; ++i)
		{
			if (*i > *(i + 1))
				swap(*i, *(i + 1));
		}
		--right;

		for (int *i = right; i > left; --i)
		{
			if (*i < *(i - 1))
				swap(*i, *(i - 1));
		}
		++left;
	}

}

template<int T4row, int T4col>
void task4(int(&arr4)[T4row][T4col], int N) {
	cout << "Task 4. Choose (1(+), 2(-), 3(*), 4(/)) ";
	int t4s, t4n;
	cin >> t4s;
	eraseN2str(N);
	cout << "Task 4. Enter a number ";
	cin >> t4n;
	eraseN2str(N);
	switch (t4s) {
	case 1: {
		cout << "Task 4. arr[N][N] + " << t4n;
		int* end = *arr4 + N * N - 1;
		for (int* ptr = *arr4; ptr <= end; ptr++)
		{
			*ptr = *ptr+t4n;
		}
		consoleOut(arr4, N);
		break;
	}
	case 2: {
		cout << "Task 4. arr[N][N] - " << t4n;
		int* end = *arr4 + N * N - 1;
		for (int* ptr = *arr4; ptr <= end; ptr++)
		{
			*ptr = *ptr - t4n;
		}
		consoleOut(arr4, N);
		break;
	}
	case 3: {
		cout << "Task 4. arr[N][N] * " << t4n;
		int* end = *arr4 + N * N - 1;
		for (int* ptr = *arr4; ptr <= end; ptr++)
		{
			*ptr = *ptr * t4n;
		}
		consoleOut(arr4, N);
		break;
	}
	case 4: {
		if (t4n != 0) {
			cout << "Task 4. arr[N][N] / " << t4n;
			int* end = *arr4 + N * N - 1;
			for (int* ptr = *arr4; ptr <= end; ptr++)
			{
				*ptr = *ptr / t4n;
			}
			consoleOut(arr4, N);
		}
		else {
			cout << "Task 4. You choose /0";
			Sleep(2000);
			eraseN2str(N);
			task4(arr4, N);
		}
		break;
	}
	default: {
		cout << "You entered not 1, 2, 3 or 4";
		Sleep(3000);
		eraseN2str(N);
		task4(arr4, N);
		return;
		break;
	}
	}
}

void arrayOrder(int* PN) {
	cout << "choose the array order (6, 8, 10) ";
	cin >> *PN;
	cout << endl;
	switch (*PN) {
	case 6: {
		const int N = 6;
		int arr[N][N];
		int z = 0;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		z = 1;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		Sleep(1000);
		int arr1[N][N];
		array1Filling(arr, arr1, N);
		task2(arr, arr1, N);
		cout << "Task 3. Shaker Sort";
		Sleep(1000);
		int arr3[N][N];
		array1Filling(arr1, arr3, N);
		shakerSort(arr3, N);
		consoleOut(arr3, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		//4
		int arr4[N][N];
		array1Filling(arr1, arr4, N);
		task4(arr4, N);
		break;
	}
	case 8: {
		const int N = 8;
		int arr[N][N];
		int z = 0;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		z = 1;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		Sleep(1000);
		int arr1[N][N];
		array1Filling(arr, arr1, N);
		task2(arr, arr1, N);
		cout << "Task 3. Shaker Sort";
		Sleep(1000);
		int arr3[N][N];
		array1Filling(arr1, arr3, N);
		shakerSort(arr3, N);
		consoleOut(arr3, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		//4
		int arr4[N][N];
		array1Filling(arr1, arr4, N);
		task4(arr4, N);
		break;
	}
	case 10: {
		const int N = 10;
		int arr[N][N];
		int z = 0;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		z = 1;
		arrayFilling(arr, N, z);
		consoleOut(arr, N);
		Sleep(1000);
		int arr1[N][N];
		array1Filling(arr, arr1, N);
		task2(arr, arr1, N);
		cout << "Task 3. Shaker Sort";
		Sleep(1000);
		int arr3[N][N];
		array1Filling(arr1, arr3, N);
		shakerSort(arr3, N);
		consoleOut(arr3, N);
		Sleep(1000);
		eraseN2str(N);
		cout << "Original matrix: ";
		consoleOut(arr1, N);
		eraseN2str(N);
		//4
		int arr4[N][N];
		array1Filling(arr1, arr4, N);
		task4(arr4, N);
		break;
	}
	default: {
		cout << "You entered not 6, 8 or 10\n\n";
		arrayOrder(PN);
		break;
	}
	}
}


int main() {
	
	int PN = 0;
	arrayOrder(&PN);
	
	/*
	//»ƒ« 18
	int const n = 10;
	int arrI[n][n], m = 1, nm;
	arrayFilling(arrI, n, m);
	consoleOut(arrI, n);
	int* end = *arrI + n * n - 1;
	for (int* ptr = *arrI; ptr <= end; ptr++)
	{
		*ptr = *ptr * 2;
	}
	consoleOut(arrI, n);
	cout << "Erase? (any number) ";
	cin >> nm;
	consoleErase(n);
	eraseN2str(n);
	*/
	return 0;
}

