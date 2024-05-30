#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define SOMH 3

class SinhVien
{
private:
	long long mssv;
	char HoVaTen[50];
	char maLop[10];
	string queQuan;
	char ngaySinh[20];
	double diem[SOMH];

public:
	SinhVien() {};
	
	SinhVien(long long id, char *ht, char *ml, string qq, char *ns, double *d) {
		mssv = id;
		strcpy_s(HoVaTen, ht);
		strcpy_s(maLop, ml);
		queQuan = qq;
		strcpy_s(ngaySinh, ns);
		for (int i = 0;i < SOMH;i++) {
			diem[i] = d[i];
		}
	}
	void nhap1SV();
	void xuat1SV();
	double calcAverage(double d);

	char* getMaLop() {
		return maLop;
	}
};

double SinhVien::calcAverage(double d) {
	double tong = 0;
	for (int i = 0;i < SOMH;i++) {
		tong += diem[i];
	}
	return tong;
}

void SinhVien::nhap1SV()
{
	cout << "MSSV: ";
	cin >> mssv;
	cin.ignore(1);
	cout << "Ho va Ten: ";
	cin.getline(HoVaTen,50);
	cout << "Ma lop: ";
	cin >> maLop;
	cin.ignore(1);
	cout << "Que quan: ";
	getline(cin, queQuan);
	cout << "Ngay sinh: ";
	cin.getline(ngaySinh, 20);
	cout << "Diem: ";
	for (int i = 0;i < SOMH;i++) {
		cin >> diem[i];
	}
	cout << endl;
}

void SinhVien::xuat1SV() {
	cout << "=============================\n";
	cout << "MSSV: " << mssv << endl;
	cout << "Ho va Ten: " << HoVaTen << endl;
	cout << "Ma lop: " << maLop << endl;
	cout << "Que quan: " << queQuan << endl;
	cout << "Ngay sinh: " << ngaySinh << endl;
	cout << "Diem: ";
	for (int i = 0;i < SOMH;i++) {
		cout << diem[i] << " ";
	}
	cout << endl;
	cout << "=========================================\n";
}


class DSSV
{
private:
	SinhVien* ds;
	int n;

public:
	DSSV() {};
	void nhapDSSV();
	void xuatDSSV();
	void nhapFile();
	int countByAverage(double d);
	int countByClass(const char* nameClass);
};

void DSSV::nhapDSSV() {
	do {
		cout << "Nhap so luong ds: ";
		cin >> n;
		if (n < 0 || n > 50) {
			cout << "Nhap lai\n";
		}
	} while (n < 0 || n > 50);
	ds = new SinhVien[n];
	for (int i = 0;i < n;i++) {
		ds[i].nhap1SV();
	}
}

void DSSV::xuatDSSV() {
	for (int i = 0;i < n;i++) {
		ds[i].xuat1SV();
	}
}

void DSSV::nhapFile() {
	ifstream f;
	f.open("data_sv_2.txt");
	if (f.is_open()) {
		f >> n;
		ds = new SinhVien[n];
		for (int i = 0;i < n;i++) {
			long long mssv;
			char HoVaTen[50];
			char maLop[10];
			string queQuan;
			char ngaySinh[20];
			double diem[SOMH];

			f >> mssv;
			f.ignore(1);
			f.getline(HoVaTen, 50);
			f >> maLop;
			f.ignore(1);
			getline(f, queQuan);
			f.getline(ngaySinh, 20);
			for (int j = 0;j < SOMH;j++) {
				f >> diem[j];
			}
			SinhVien sv(mssv, HoVaTen, maLop, queQuan, ngaySinh, diem);
			ds[i] = sv;
		}
	}
	f.close();
}

int DSSV::countByClass(const char *nameClass) {
	int count = 0;
	for (int i = 0;i < n;i++) {
		if (strcmp(ds[i].getMaLop(), nameClass) == 0) {
			count++;
		}
	 }
	return count;
}

int DSSV::countByAverage(double d) {
	int count = 0;
	for (int i = 0;i < n;i++) {
		if (ds[i].calcAverage(i) > d) {
			count++;
		}
	}
	return count;
}



DSSV::~DSSV() {
	delete[]ds;
	ds = NULL;
}

int main() {
	SinhVien sv;
	DSSV ds;
	/*sv.nhap1SV();
	sv.xuat1SV();*/

	//ds.nhapDSSV();
	ds.nhapFile();
	ds.xuatDSSV();
	ds.countByAverage(8.0);
	int kq = ds.countByClass("DH23CS02");
	cout << "Co " << kq << " sinh vien hoc lop nay\n";




	system("pause");
	return 0;
}