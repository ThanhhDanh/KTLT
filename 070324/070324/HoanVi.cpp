//#include<iostream>
//using namespace std;
//
//
//int* a;//lưu 1 kết quả
//int* p;//đánh dấu 1 phần tử được chọn
//int n;
//
//void xuaKetqua() {
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << "";
//	}
//	cout << endl;
//}
//
//
//void hoanVi(int i) {
//	for (int j = 1; j < n + 1; j++) {
//		if (p[j] == 0) {
//			a[i] = j;
//			p[j] = 1;
//			if (i == n - 1) {
//				xuaKetqua();
//			}
//			else {
//				hoanVi(i + 1);
//			}
//			p[j] = 0;
//		}
//	}
//}
//
//
//
//
//int main() {
//
//	cout << "Nhap n: "; cin >> n;
//	a = new int[n];
//	p = new int[n + 1];
//	for (int i = 0; i < n + 1; i++) {
//		p[i] = 0;
//	}
//	hoanVi(n);
//
//	delete[]p;
//
//	system("pause");
//	return 1;
//}