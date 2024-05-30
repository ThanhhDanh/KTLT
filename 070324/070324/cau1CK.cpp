#include<iostream>
#include<string>
#include <cstring>
#include<algorithm> //Thư viện cho any_of
#include<cctype> //Thư viện cho isdigit
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//Hàm kiểm tra một chuỗi nhận vào có ký tự số hay không? 
bool containsDigit(const string& str) {
	return any_of(str.begin(), str.end(), isdigit);
}

//Hàm kiểm tra một chuỗi nhận vào có chứa khoảng trắng đầu và cuối chuỗi
//hay không ?
bool containsSpace(const string& str) {
	return any_of(str.begin(), str.end(), isspace);
}

//Hàm tách bỏ khoảng trắng đầu cuối, bên trong chuỗi
string trim(const string& str) {
	auto start = str.begin();
	auto end = str.end();
	while (start != end && isspace(*start)) {
		start++;
	}
	do {
		--end;
	} while (distance(start, end) > 0 && isspace(*end));
	return string(start, end + 1);

}
string trimSpaceStartAndEnd(const string& str) {
	return trim(str);
}


int main() {
	//----------------------------------------Câu 1:
	string input;
	cout << "Nhap chuoi can kiem tra: ";
	getline(cin, input);

	string ouput = trimSpaceStartAndEnd(input);
	cout << "Chuoi sau khi bo khoang trang dau va cuoi: " << ouput << endl;

	if (containsSpace(input)) {
		//cout << "Chuoi co chua ki tu\n";
		cout << "Chuoi co chua khoang trang dau va cuoi\n";
	}
	else
	{
		//cout << "Chuoi khong chua ki tu\n";
		cout << "Chuoi khong co chua khoang trang dau va cuoi\n";
	}

	//Hàm tách từng từ trong chuỗi bằng ký tự do người dùng nhập. 
	char str1[] = "Le Thanh Danh";
	char str2[] = " ";
	char* context = nullptr;
	char * result = strtok_s(str1, str2,&context);
	while (result != NULL)
	{
		cout << result << endl;
		result = strtok_s(NULL, str2, &context);
	}
	delete[]result;

	system("pause");
	return 1;
}