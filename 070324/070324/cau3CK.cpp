#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
#include <algorithm>
using namespace std;

void nhapMang2(int** &arr, int& r, int &c) {

	do {
		cout << "Nhap r: ";cin >> r;
		cout << "Nhap c: ";cin >> c;
		if (r < 0 || c < 0) {
			cout << "Nhap lai!!!\n";
		}
	} while (r < 0 || c < 0);
	arr = new int* [r];
	for (int i = 0;i < r;i++) {
		arr[i] = new int[c];
	}
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cout << "Nhap mang 2 chieu voi arr[" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
		cout << endl;
	}
}

void xuatMang2(int** arr, int r, int c) {
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void truyenMangVaoFile(int** arr, int r, int c) {
	ofstream f;
	f.open("Array2.txt");
	if (!f.is_open()) {
		cout << "Khong mo duoc\n";
		return;
	}
	f << r << " " << c << endl; // Ghi số dòng và số cột vào file
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			f << arr[i][j] << " ";
		}
		f << endl;
	}
	f.close();
}

void nhapFile(int**& arr, int& r, int& c) {
	ifstream f("Array2.txt");
	if (!f.is_open()) {
		cout << "Khong mo duoc file\n";
		return;
	}

	f >> r >> c; // Đọc số dòng và số cột từ file
	arr = new int* [r];
	for (int i = 0; i < r; i++) {
		arr[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			f >> arr[i][j];
		}
	}

	f.close();
}

void xuatFile(int** arr, int r, int c) {
	xuatMang2(arr, r, c);  // Gọi hàm xuatMang2 để in mảng ra
}

void calcAdd(int** arr, int r, int c) {
	int tong = 0;
	for (int i = 0;i < r; i++) {
		for (int j = 0;j < c;j++) {
			tong += arr[i][j];
		}
	}
	cout << "Tong: " << tong << endl;
}

int checkMax(int** arr, int r, int c, int i, int j) {
	if (i == r - 1 && j == c - 1) {
		return arr[i][j];
	}
	// Tính vị trí tiếp theo
	int next_i = i + (j + 1) / c;
	int next_j = (j + 1) % c;

	// Tìm giá trị lớn nhất của phần tử hiện tại và phần còn lại của mảng
	return max(arr[i][j], checkMax(arr, r, c, next_i, next_j));

}


int main() {
	int** arr=NULL;
	int r ,c ;
	/*nhapMang2(arr, r, c);
	xuatMang2(arr, r, c);

	truyenMangVaoFile(arr, r, c);*/
	
	nhapFile(arr, r, c);
	xuatFile(arr, r, c);
	calcAdd(arr, r, c);

	// Tìm giá trị lớn nhất trong mảng sử dụng đệ quy
	int maxVal = checkMax(arr, r, c, 0, 0);
	cout << "Gia tri lon nhat trong mang: " << maxVal << endl;

	// Giải phóng bộ nhớ
	for (int i = 0; i < r; i++) {
		delete[] arr[i];
	}
	delete[]arr;
	arr = nullptr;

	system("pause");
	return 0;
}