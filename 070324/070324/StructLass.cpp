#include <iostream>
#include<string>
#include<fstream>
#define _CRT_SECURE_NO_WARNINGS;
using namespace std;

#define SOMH 3


struct SinhVien
{
	long long mssv;
	char hoVaTen[50];
	char maLop[9];
	char ngaySinh[11];
	string queQuan;
	double diem[SOMH];
};

struct DSSV
{
	SinhVien* ds;
	int n;
};

void swap(SinhVien sv1, SinhVien sv2) {
	SinhVien tam = sv1;
	sv1 = sv2;
	sv2 = tam;
}

double calcAverage(SinhVien sv) {
	double tong = 0;
	for (int i = 0; i < SOMH; i++) {
		tong += sv.diem[i];
	}
	return tong / SOMH;
}

int comparatorWithAverage(const SinhVien sv1, const SinhVien sv2) {
	if (calcAverage(sv1) > calcAverage(sv2))
		return 1;
	if (calcAverage(sv1) < calcAverage(sv2))
		return -1;
	return 0;
}

void nhap1SV(SinhVien& sv) {
	cout << "Nhap MSSV: ";
	cin >> sv.mssv;
	cin.ignore(1);
	cout << "Nhap ho ten: ";
	cin.getline(sv.hoVaTen, 50);
	cout << "Nhap ma lop: ";
	cin >> sv.maLop;
	cout << "Nhap ngay sinh: ";
	cin >> sv.ngaySinh;
	cin.ignore(1);
	cout << "Nhap que quan: ";
	getline(cin, sv.queQuan);
	cout << "Nhap 3 cot diem: ";
	for (int i = 0; i < SOMH; i++) {
		cin >> sv.diem[i];
	}
};

void xuat1SV(SinhVien sv) {
	cout << "==========================================================\n";
	cout << "MSSV: "; cout << sv.mssv << endl;
	cout << "Ho ten: "; cout << sv.hoVaTen << endl;
	cout << "Ma lop: "; cout << sv.maLop << endl;
	cout << "Ngay sinh: "; cout << sv.ngaySinh << endl;
	cout << "Que quan: "; cout << sv.queQuan << endl;
	for (int i = 0; i < SOMH; i++) {
		cout << sv.diem[i] << " ";
	}
	cout << endl;
	cout << "DTB: " << calcAverage(sv) << endl;
};

void nhapDSSV(DSSV& mh) {
	do {
		cout << "Nhap so luong danh sach: ";
		cin >> mh.n;
		if (mh.n <= 0 || mh.n > 50)
		{
			cout << "Nhap lai so luong!!!";
		}
	} while (mh.n <= 0 || mh.n > 50);

	//cap phat dong mang SV
	mh.ds = new SinhVien[mh.n];
	for (int i = 0; i < mh.n; i++) {
		nhap1SV(mh.ds[i]);
	}
};

void xuatDSSV(DSSV mh) {
	for (int i = 0; i < mh.n; i++) {
		xuat1SV(mh.ds[i]);
	}
}

void nhapDSSVTuFile(DSSV& mh) {
	ifstream dssv;
	dssv.open("data_sv_2.txt");
	if (dssv.is_open()) {
		dssv >> mh.n;
		mh.ds = new SinhVien[mh.n];
		for (int i = 0; i < mh.n; i++) {
			dssv >> mh.ds[i].mssv;
			dssv.ignore(1);
			dssv.getline(mh.ds[i].hoVaTen, 50);
			dssv >> mh.ds[i].maLop;
			dssv.ignore(1);
			getline(dssv, mh.ds[i].queQuan);
			dssv >> mh.ds[i].ngaySinh;
			dssv.ignore(1);
			for (int j = 0; j < SOMH; j++) {
				dssv >> mh.ds[i].diem[j];
			}
		}
	}
	dssv.close();
}

void huyDSSV(DSSV& mh) {
	delete[]mh.ds;
	mh.ds == NULL;
}

int countByClass(const DSSV mh, const char *className) {
	int count = 0;
	for (int i = 0; i < mh.n; i++) {
		if (strcmp(mh.ds[i].maLop, className)==0) {
			count++;
		}
	}
	return count;
}

int countByAverage(const DSSV mh, const double diem) {
	int count = 0;
	for (int i = 0; i < mh.n; i++) {
		if (calcAverage(mh.ds[i])>= diem) {
			count++;
		}
	}
	return count;
}

void sortByAverage(const DSSV mh, int comparator(SinhVien, SinhVien)) {
	for (int i = 0; i < mh.n-1; i++) {
		for (int j = i; j < mh.n; j++) {
			if (comparatorWithAverage(mh.ds[i], mh.ds[j]) < 0) {
				swap(mh.ds[i], mh.ds[j]);
			}
		}
	}
}

void update(SinhVien &sv) {
	char svMoi[50];
	cout << "Nhap ho va ten muo thay doi : "; cin >> svMoi;
	strcpy(sv.hoVaTen, svMoi);
}

int main() {
	DSSV sv;

	cout << "===========================Danh sach sinh vien===============================\n";
	nhapDSSVTuFile(sv);
	/*nhapDSSV(sv);*/
	xuatDSSV(sv);

	cout << "-----------------------------------Tim kiem lop------------------------------------------\n";
	cout << "So luong sinh vien lop DH23CS01: " << countByClass(sv, "DH23CS01") << endl;
	cout << "---------------------------------------Xet diem trung binh-------------------------------------\n";
	cout << "So luong sinh vien co diem trung binh >= 8.0: " << countByAverage(sv, 8.0) << endl;
	sortByAverage(sv, comparatorWithAverage);
	cout << "---------------------------------------Sap xep diem trung binh--------------------------------------\n";
	xuatDSSV(sv);
	update(sv.ds[0]);
	cout << "---------------------------------------Cap nhat lai sinh vien--------------------------------------\n";
	xuatDSSV(sv);


	huyDSSV(sv);
	system("pause");
	return 1;
}
