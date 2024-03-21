#include<iostream>
using namespace std;
//#define MAX_COL 100
//#define MAX_ROW 50

bool isMin(int x) {
	return x < 0 ? true : false;
}

bool isMax(int x) {
	return x >= 0 ? true : false;
}

//void nhapMang(int array[][MAX_COL], int& r, int& c) {
//	for (int r = 0; r < MAX_ROW; r++) {
//		for (int c = 0; c < MAX_COL; c++) {
//			cout << "Nhap gia tri cua mang array[" << r << "][" << c << "]: ";
//			cin >> array[r][c];
//		}
//		cout << endl;
//	}
//}
//
//void xuatMang(const int array[][MAX_COL], int r, int c) {
//	for (int r = 0; r < MAX_ROW; r++) {
//		for (int c = 0; c < MAX_COL; c++) {
//			cout << array[r][] << " ";
//		}
//		cout << endl;
//}

int main2(){
	/*int array[3][4];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "Nhap gia tri cua mang array[" << i << "][" << j << "]: ";
			cin >> array[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}*/
	/*const int row = 4, col = 3;
	int i = 0, j = 0;
	int array[row][col];
	while (i < row) {
		j = 0;
		while (j < col) {
			cout << "Nhap gia tri cua mang array[" << i << "][" << j << "]: ";
			cin >> array[i][j];
			j++;
		}
		cout << endl;
		i++;
	}

	cout << "Sau khi nhap gia tri cho mang\n";
	i = 0;
	while (i < row) {
		j = 0;
		while (j < col) {
			cout << array[i][j] << " ";
			j++;
		}
		cout << endl;
		i++;
	}*/


	const int MAX_ROW = 10;
	const int MAX_COL = 15;
	int array[MAX_ROW][MAX_COL];
	int row = 0 , col = 0, chon, sum = 0, max, min, max_row, max_col, min_row, min_col , x;
	int count = 0;
	bool flag = true;

	do {
		cout << "1.Nhap gia tri hang va cot\n";
		cout << "2.Nhap gia tri cua mang\n";
		cout << "3.Xuat mang\n";
		cout << "4.Tinh tong\n";
		cout << "5.Tinh tong so hang\n";
		cout << "6.Tinh tong so cot\n";
		cout << "7.Gia tri lon nhat va nho nhat voi vi tri cua no\n";
		cout << "8.Nhap gia tri x bat ky de tim trong mang\n";
		cout << "9.Thoat\n";
		cout << "Chon tu 1 - 9: ";
		cin >> chon;
		system("cls");
		switch (chon)
		{
		case 1:
			do {
				cout << "Nhap gia tri hang: ";
				cin >> row;
				cout << "Nhap gia tri cot: ";
				cin >> col;
				if (row <= 0 || row > MAX_ROW || col <= 0 || col > MAX_COL) {
					cout << "Vui long nhap lai ( hang < 10 va cot < 15)\n";
				}
			} while (col > MAX_COL || row > MAX_ROW || col <= 0 || row <= 0);

			break;

		case 2:
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					cout << "Nhap gia tri cua mang array[" << i << "][" << j << "]: ";
					cin >> array[i][j];
				}
				cout << endl;
			}
			flag = true;
			break;
		case 3:
			if (flag) {
				for (int i = 0; i < row; i++) {
					for (int j = 0; j < col; j++) {
						cout << array[i][j] << " ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Vui long nhap mang!!!\n";
			}
			break;

		case 4:
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					sum += array[i][j];
				}
			}
			cout << "Tong cac so trong mang: " << sum << endl;
			break;

		case 5:
			cout << "Nhap hang can tinh: ";
			cin >> row;
			for (int i = 0; i < row; i++) {
				sum += array[row][i];
			}
			cout << "Tong so hang: " << sum << endl;
			return sum;
			break;


		case 6:
			cout << "Nhap cot can tinh: ";
			cin >> col;
			for (int i = 0; i < col; i++) {
				sum += array[i][col];
			}
			cout << "Tong so cot: " << sum << endl;
			return sum;
			break;
		case 7:
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					max = isMax(array[i][j]);
					max_row = i;
					max_col = j;
					min = isMin(array[i][j]);
					min_row = i;
					min_col = j;
				}
			}
			cout << "Gia tri lon nhat trong mang: " << max << " o hang thu " << max_row << " va cot thu " << max_col << endl;
			cout << "Gia tri nho nhat trong mang: " << min << " o hang thu " << min_row << " va cot thu " << min_col << endl;
			break;


		case 8:
			cout << "Nhap gia tri x: ";
			cin >> x;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (array[i][j] == x) {
						cout << x << " ";
						count++;
					}
				}
			}

			if (count > 0) {
				cout << "\nGia tri " << x <<" xuat hien " << count << " lan trong ma tran\n";
			}
			else {
				cout << "Gia tri " << x << " khong xuat hiện trong ma tran\n";
			}

			break;



		default:
			break;
		}
	} while (chon != 9);

	system("pause");
	return 0;

}