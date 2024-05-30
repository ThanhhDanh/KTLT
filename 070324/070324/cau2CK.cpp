#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#define ARRAY 10
using namespace std;

struct Array
{
	int* arr;
	int n;
};


bool checkSN(int x) {
	return x > 0 ? x : false;
}

void nhapMang(int* &arr, int &n) {
	for (int i = 0;i < n;i++) {
		cout << "Nhap gia tri cua mang arr[" << i << "]: ";
		cin >> arr[i];
	}
}

void xuatMang(int* arr, int n) {
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void truyenSoVaoFile(int *arr, int n) {
	ofstream f;
	f.open("Array1.txt");
	if (!f.is_open()) {
		cout << "Khong mo duoc file\n";
		return;
	}
	for (int i = 0;i < n;i++) {
		f << arr[i] << " ";
	}
	f.close();
}

void nhapFile(Array&ds) {
	ifstream f;
	f.open("Array1.txt");
	if (f.is_open()) {
		f >> ds.n;
		ds.arr = new int [ds.n];
		for (int i = 0;i < ds.n;i++) {
			f >> ds.arr[i];
			f.ignore(1);
		}
	}
	f.close();
}

void xuatFile(Array &ds) {
	for (int i = 0;i < ds.n;i++) {
		cout << ds.arr[i] << " ";
	}
	cout << endl;
}


int main() {

	int array = ARRAY;
	int* arr = new int[array];
	int n;
	Array ds;
	/*cout << "Nhap so luong phan tu trong mang: ";
	cin >> n;*/


	/*nhapMang(arr, n);
	xuatMang(arr, n);
	truyenSoVaoFile(arr,n);*/
	nhapFile(ds);
	xuatFile(ds);

	delete[]arr;
	delete[] ds.arr;

	system("pause");
	return 0;
}