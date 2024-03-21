#include "Contro.h"

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define ARRAY_MAX  5
#define MAX_COL 3
#define MAX_ROW 3


int main() {
	int x = 80, y = 30;
	int* p;
	p = &x;
	const int ARRAY = ARRAY_MAX;
	int array[ARRAY];
	int n = ARRAY;


	cout<<"--------------------Sap xep---------------------------\n";
	/*nhapMang(array, n);
	xuatMang(array, n);
	sortArray(array, n);
	xuatMang(array, n);*/


	cout<<"--------------------Bài 1---------------------------\n";
	/*cout << p << endl;
	cout << "Dia chi cua bien x: " << &x << endl;
	cout << "Dia chi luu trong con tro p: " << p << endl;
	cout << "Gia tri cua bien ma p tro den: " << *p << endl;
	cout << "Gia tri cua bien x: " << x << endl;

	if (*p == x) {
		cout << "Gia tri cua x trung voi gia tri ma p luu tru\n";
	}
	else
	{
		cout << "Gia tri cua x khong trung voi gia tri ma p luu tru\n";
	}
	delete p;*/



	cout << "--------------------Bài 2---------------------------\n";
	/*nhapMang(array, n);
	xuatMang(array, n);*/
	// Thiết lập seed cho hàm random
	//srand(time(0));
	//mangRandom(array, n);
	//xuatMang(array, n);
	//int* q = array;
	// //Kí pháp độ dời
	//cout << "Ki phap do doi\n";
	//for (int i = 1; i < n;i++) {
	//	cout << "*(q + " << i << ") = " << *(q + i) << endl;
	//}

	//delete q;



	cout << "--------------------Bài 3---------------------------\n";
	// Cấp phát động cho 2 con trỏ lưu trữ giá trị của 2 số nguyên
	/*int* a = new int;
	int* b = new int;

	cout << "Nhap gia tri cho so nguyen thu nhat: ";
	cin >> *a;
	cout << "Nhap gia tri cho so nguyen thu nhat: ";
	cin >> *b;

	int result = UCLN(*a, *b);
	cout << "Uoc chung lon nhat cua " << *a << " va " << *b << " la: " << result << endl;;

	delete a;
	delete b;*/


	cout << "--------------------Bài 4---------------------------\n";
	//int* arr; //con trỏ để lưu trữ mảng
	//int size; //kích thước của mảng
	//int i;
	//int max = 0;

	//do {
	//	cout << "Nhap so phan tu cua mang (toi da 30 phan tu): ";
	//	cin >> size;
	//	if (size > 30)
	//	{
	//		cout << "Vui long nhap lai!!\n";
	//	}
	//} while (size > 30);

	//arr = new int[size];
	//
	///*for (int i = 0; i < size; i++) {
	//	cout << "Nhap gia tri của mang arr[" << i << "]:";
	//	cin >> arr[i];
	//}
	//cout << endl;*/
	//nhapMang(arr, size);
	//xuatMang(arr, size);
	////Kí pháp độ dời với số lẻ
	//cout << "Ki phap do doi\n";
	//for (int i = 1; i < size; i++) {
	//	cout << "*(arr + " << i << ") = " << *(arr + i) << endl;
	//	if (arr[i] > max) {
	//		max = arr[i];
	//		p = &max;
	//	}
	//}
	//cout << "Gia tri lon nhat trong mang la: " << max << " va co dia chi la: " << p << endl;

	//delete[] arr;


	cout << "--------------------Bài 5---------------------------\n";
	//calcFibonacci();


	cout << "--------------------Bài 6---------------------------\n";
	/*const int ARRAY = ARRAY_MAX;
	int array[ARRAY];
	int n = ARRAY;
	nhapMang(array, n);
	xuatMang(array, n);
	reverseArray(array, n);
	xuatMang(array, n);*/

	cout << "--------------------Bài 7---------------------------\n";
	/*const int ARRAY = ARRAY_MAX;
	int array[ARRAY];
	int n = ARRAY;
	nhapMang(array, n);
	xuatMang(array, n);
	int* result =  findArray(array, n, x);

	if (result != nullptr) {
		cout << "So nguyen " << x << " xuat hien o vi tri " << result - array << " trong mang" << endl;
	}
	else {
		cout << "So nguyen " << x << " khong co trong mang\n";
	}*/


	cout << "--------------------Bài 8---------------------------\n";
	int** arr, r, c;
	nhapMang2(arr, r, c);
	xuatMang2(arr, r, c);

	for (int i = 0; i < r; i++) {
		delete[]arr[i];
	}
	delete[]arr;


	system("pause");
	return 0;
}