//#include<iostream>
//using namespace std;
//#define SIZE 4
//
//int queens[SIZE] = { 0 };
//
//void xuatKetQua() {
//	for (int i = 0; i < SIZE; i++) {
//		for (int j = 0; j < SIZE; j++) {
//			if (queens[i] == j) {
//				cout << "Q\t";
//			}
//			else
//			{
//				cout << "-\t";
//			}
//			cout << endl;
//		}
//	}
//}
//
//
//bool checkViTri(int i, int j) {
//	for (int k = 0; k < i; k++) {
//		if (queens[k] == j || abs(i - k) == abs(queens[k] - j)) {
//			return false;
//		}
//	}
//	return 0;
//}
//
//void putQueen(int i){
//	for (int j = 0; j < SIZE; j++) {
//		if (checkViTri(i, j)) {
//			queens[i] = j;
//			if (i == SIZE - 1) {
//				xuatKetQua();
//			}
//			else
//			{
//				putQueen(i + 1);
//			}
//			queens[i] = -1;
//		}
//	}
//}
//
//int main() {
//	putQueen(1);
//	system("pause");
//	return 1;
//}