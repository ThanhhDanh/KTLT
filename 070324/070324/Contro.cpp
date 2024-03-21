#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#define ARRAY_MAX  5



void nhapMang(int array[ARRAY_MAX], int &n) {
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
	for (int i = 0; i < n;i++) {
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

void calcFibonacci() {

	int n;
	do {
		std::cout << "Nhap vao so nguyen n (n > 1): ";
		std::cin >> n;
	} while (n <= 1);


	int *fib = new int[n]; //Cấp phát động 1 mảng để lưu trữ dãy Fib
	//nhapMang(fib, n);

	//Khởi tạo hai phần tử đầu tiên của mảng
	fib[0] = 0;
	fib[1] = 1;



	//Tính và lưu các giá trị phần tử tiếp theo của Fib
	for (int i = 2; i < n;i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	//Xuất giá trị của Fib
	cout << "Gia tri cua day so Fib\n";
	for (int i = 0;i < n;i++) {
		cout<< fib[i] << " ";
	}
	cout << endl;

	delete[] fib;
}


void swap(int &x, int &y) { int temp = x; x = y;y = temp; }

void reverseArray(int* arr, int& n) {
	for (int i = 0; i < n/2;i++) {
		swap(arr[i], arr[n - i - 1]);
	}
}


int main() {
	int x = 80, y = 30;
	int* p;
	p = &x;

	cout<<("--------------------Bài 1---------------------------\n");
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



	cout << ("--------------------Bài 2---------------------------\n");
	/*const int ARRAY = ARRAY_MAX;
	int array[ARRAY];
	int n = ARRAY;*/
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



	cout << ("--------------------Bài 3---------------------------\n");
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


	cout << ("--------------------Bài 4---------------------------\n");
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


	cout << ("--------------------Bài 5---------------------------\n");
	//calcFibonacci();


	cout << ("--------------------Bài 6---------------------------\n");
	const int ARRAY = ARRAY_MAX;
	int array[ARRAY];
	int n = ARRAY;
	nhapMang(array, n);
	xuatMang(array, n);
	reverseArray(array, n);
	xuatMang(array, n);

	system("pause");
	return 0;
}