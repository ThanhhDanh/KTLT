#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define SOMH 3

struct SinhVien
{
	long long mssv;
	char HovaTen[50];
	char maLop[9];
	string queQuan;
	char ngaySinh[20];
	double diem[SOMH];
};

struct DSSV
{
	SinhVien* ds;
	int n;
};

void nhap1SV(SinhVien& sv) {
	cout << "Nhap mssv: ";
	cin >> sv.mssv;
	cin.ignore(1);
	cout << "Ho va Ten: ";
	cin.getline(sv.HovaTen, 50);
	cout << "Ma lop: ";
	cin >> sv.maLop;
	cin.ignore(1);
	cout << "Que quan: ";
	getline(cin, sv.queQuan);
	cout << "Ngay sinh: ";
	cin >> sv.ngaySinh;
	cin.ignore(1);
	cout << "Nhap 3 cot diem: ";
	for (int i = 0;i < SOMH;i++) {
		cin >> sv.diem[i];
	}
}

void xuat1SV(SinhVien& sv) {
	cout << "===================================\n";
	cout << "MSSV: " << sv.mssv << endl;
	cout << "Ho va Ten: " << sv.HovaTen << endl;
	cout << "Ma lop: " << sv.maLop << endl;
	cout << "Que quan: " << sv.ngaySinh << endl;
	cout << "Ngay sinh: " << sv.ngaySinh << endl;
	cout << "Diem: ";
	for (int i = 0;i < SOMH;i++) {
		cout << sv.diem[i] <<" ";
	}
	cout << endl;
	cout << "===================================\n";
}


void nhapDSSV(DSSV& ds) {
	do {
		cout << "Nhap so luong ds: ";
		cin >> ds.n;
		if (ds.n < 0 || ds.n>50) {
			cout << "Nhap lai!!\n";
		}
	} while (ds.n < 0 || ds.n>50);

	ds.ds = new SinhVien[ds.n];
	for (int i = 0;i < ds.n;i++) {
		nhap1SV(ds.ds[i]);
	}
}

void xuatDSSV(DSSV& ds) {
	for (int i = 0;i < ds.n;i++) {
		xuat1SV(ds.ds[i]);
	}
}

void nhapFile(DSSV& ds) {
	ifstream f;
	f.open("data_sv_2.txt");
	if (f.is_open()) {
		f >> ds.n;
		ds.ds = new SinhVien[ds.n];
		for (int i = 0;i < ds.n;i++) {
			f >> ds.ds[i].mssv;
			f.ignore(1);
			f.getline(ds.ds[i].HovaTen, 50);
			f >> ds.ds[i].maLop;
			f.ignore(1);
			getline(f, ds.ds[i].queQuan);
			f >> ds.ds[i].ngaySinh;
			f.ignore(1);
			for (int j = 0;j < SOMH;j++) {
				f >> ds.ds[i].diem[j];
			}
		}
	}
	f.close();
}


int checkByMaLop(DSSV& ds, const char *nameClass) {
	int count = 0;
	for (int i = 0;i < ds.n;i++) {
		if (strcmp(ds.ds[i].maLop, nameClass)==0) {
			count++;
		}
	}
	return count;
}

double calcAverage(SinhVien& sv) {
	double tong = 0;
	for (int i = 0;i < SOMH;i++) {
		tong += sv.diem[i];
	}
	return tong/SOMH;
}

void swap(SinhVien& sv1, SinhVien& sv2) {
	SinhVien tamp = sv1;
	sv1 =  sv2;
	sv2 = tamp;
}

int checkByAverage(DSSV& ds, double d) {
	int count = 0;
	for (int i = 0; i < ds.n;i++) {
		if (calcAverage(ds.ds[i]) > d) {
			count++;
		}
	}
	return count;
}

void sortByAverage(DSSV ds) {
	for (int i = 0; i < ds.n - 1;i++) {
		for (int j = i + 1; j < ds.n;j++) {
			if (calcAverage(ds.ds[i]) > calcAverage(ds.ds[j])) {
				swap(ds.ds[i], ds.ds[j]);
			}
		}
	}
}

void update(SinhVien& sv) {
	//...Vi du nguoi dung cap nhat ngay sinh
	char nsMoi[11];
	cout << "Nhap ngay sinh moi: ";
	cin >> nsMoi;
	strcpy(sv.ngaySinh, nsMoi);
}

void xoaSV(DSSV& mh, long long id) {
	for (int i = 0; i < mh.n; i++) {
		if (mh.ds[i].mssv == id) {
			for (int j = i; j < mh.n - 1; j++) {
				mh.ds[j] = mh.ds[j + 1];
			}
			mh.n--;
		}
	}
}

void themSV(DSSV& mh, SinhVien svMoi) {
	if (mh.ds == NULL) {
		mh.n = 1;
		mh.ds = new SinhVien[mh.n];
		mh.ds[0] = svMoi;
	}
	else
	{
		SinhVien* tam = mh.ds;
		mh.ds = new SinhVien[mh.n + 1];
		for (int i = 0; i < mh.n; i++) {
			mh.ds[i] = tam[i];
		}
		mh.ds[mh.n++] = svMoi;

		delete[] tam;
	}
}


void huyDsSv(DSSV& ds) {
	delete[]ds.ds;
	ds.ds = NULL;
}

int main() {
	SinhVien sv;
	DSSV ds;


	/*nhap1SV(sv);
	xuat1SV(sv);*/
	/*nhapDSSV(ds);*/
	nhapFile(ds);
	xuatDSSV(ds);

	/*int kq = checkByMaLop(ds,"DH23CS02");
	cout << "Co " << kq <<" sinh vien hoc lop do\n";

	cout << "Co " << checkByAverage(ds, 8.0) << " sinh vien hoc diem do\n";*/


	sortByAverage(ds);
	cout << "Danh sach sinh vien co diem trung binh giam dan\n";
	xuatDSSV(ds);


	huyDsSv(ds);


	system("pause");
	return 0;
}