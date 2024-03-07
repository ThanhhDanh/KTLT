#include<iostream>
using namespace std;


bool scp(int x) {
	int  a = sqrt(x);
	return (a * a == x);
}


int main1() {
	int array[10];
	for (int i = 0; i < 10; i++) {
		cout << "Nhap gia tri array["<<i<<"]: " ;
		cin >> array[i];
	}
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	/*cout << "----------------Gia tri lon nhat và gia tri nho nhat-------------\n";
	int max = array[0], min = array[0], lt_max = 0, lt_min = 0;
	for (int i = 0; i < 10; i++) {
		if (array[i] > max) {
			max = array[i];
			lt_max = i;
		}
		if (array[i] < min) {
			min = array[i];
			lt_min = i;
		}
	}

	cout << "Gia tri lon nhat là: " << max <<" co vi tri thu: "<< lt_max<< endl;
	cout << "Gia tri nho nhat là: " << min << " co vi tri thu: " << lt_min << endl;*/

	/*cout << "-------------Tinh tong cac so duong va tinh tong cac so am-----------------\n";
	int soduong = 0, soam = 0, tong = 0;
	for (int i = 0; i < 10; i++) {
		tong += array[i];
		if (array[i] > 0) {
			soduong += array[i];
		}
		if (array[i] < 0) {
			soam += array[i];
		}
	}

	cout << "Tong cac so duong: " << soduong << endl;
	cout << "Tong cac so am: " << soam << endl;
	cout << "Tong cac so trong mang: " << tong << endl;*/

	cout << "----------So chinh phuong--------------------\n";
	int n = 0, sum = 0;
	for (int i = 0; i < 10; i++) {
		if (scp(array[i])) {
			sum += array[i];
		cout << array[i] << " ";
		}
	}
	cout << endl;
	cout << "Tong so chinh phuong la: " << sum << endl;


	system("pause");
	return 0;
}