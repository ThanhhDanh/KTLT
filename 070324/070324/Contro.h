#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define ARRAY_MAX  5
#define MAX_COL 3
#define MAX_ROW 3

int* findArray(int* array, int n, int& x) {
	cout << "Nhap gia tri can tim: ";
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (*array == x) {
			return array; //trả về con trỏ đến vị trí đầu tiên của sô nguyên x
		}
		array++; // Di chuyển con trỏ đến phần tiếp theo trong mảng
	}

	return nullptr;

	delete[] array;
}


void sortArray(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}


void calcFibonacci() {

	int n;
	do {
		std::cout << "Nhap vao so nguyen n (n > 1): ";
		std::cin >> n;
	} while (n <= 1);


	int* fib = new int[n]; //Cấp phát động 1 mảng để lưu trữ dãy Fib
	//nhapMang(fib, n);

	//Khởi tạo hai phần tử đầu tiên của mảng
	fib[0] = 0;
	fib[1] = 1;



	//Tính và lưu các giá trị phần tử tiếp theo của Fib
	for (int i = 2; i < n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	//Xuất giá trị của Fib
	cout << "Gia tri cua day so Fib\n";
	for (int i = 0; i < n; i++) {
		cout << fib[i] << " ";
	}
	cout << endl;

	delete[] fib;
}


void swap(int& x, int& y) { int temp = x; x = y; y = temp; }

void reverseArray(int* arr, int& n) {
	for (int i = 0; i < n; i++) {
		swap(arr[i], arr[n - i - 1]);
	}

	delete[] arr;
}



void nhapMang(int array[ARRAY_MAX], int& n) {
	for (int i = 0; i < ARRAY_MAX; i++) {
		cout << "Nhap gia tri mang array[" << i << "]: ";
		cin >> array[i];
	}
	cout << endl;
}

void xuatMang(const int array[ARRAY_MAX], int n) {
	for (int i = 0; i < ARRAY_MAX; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void mangRandom(int array[ARRAY_MAX], int n) {
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 10; //Giới hạn giá trị ngẫu nhiên từ 0 - 9
	}
	cout << endl;
}


int UCLN(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}


bool find(int x, int y) {
	return x == y ? x : false;
}

void nhapMang2(int**& arr, int& r, int& c) {

	do {
		cout << "Nhap gia tri hang: ";
		cin >> r;
		cout << "Nhap gia tri cot: ";
		cin >> c;
		if (r > 4 || c > 4) {
			cout << "Nhap lai!!";
		}
	} while (r > 4 || c > 4);
	arr = new int* [r];
	for (int i = 0; i < r; i++) {
		arr[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Nhap gia tri cua mang 2 chieu arr[" << r << "][" << c << "]: ";
			cin >> arr[i][j];
		}
	}
}


void xuatMang2(int** arr, int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
	}
	cout << endl;
}


