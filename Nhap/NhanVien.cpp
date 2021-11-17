#include"NhanVien.h"

string xoaKhoangTrang(string str)
{
	string temp;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	return str;
}
bool kiemTraHoTen(string str)
{
	int length = str.length();
	string temp1 = str;
	string temp2;
	if (length <= 0)
		return false;
	else
	{
		temp2 = xoaKhoangTrang(temp1);
		for (int i = 0; i < temp2.length(); i++)
		{
			if (!isalpha(temp2[i]))
			{
				return false;
				break;
			}
		}
		return true;
	}
}
bool kiemTraNgay(int ngay)
{
	if (ngay < 0)
		return false;
	return true;
}
NhanVien::NhanVien()
{
	HoTen = "Nguyen Van A";
	SoNgayLamViec = 1;
	MaSo = "1A";
	ChucDanh = "Nhan Vien";
	HeSoLuong = 1.0;
}
NhanVien::NhanVien(string ten, int ngay, string maso, string chucdanh, float hsl)
{
	if (kiemTraHoTen(ten) == true)
		HoTen = ten;
	else
	{
		HoTen = "Nguyen Van A";
	}
	if (kiemTraNgay(ngay) == true)
		SoNgayLamViec = ngay;
	else
	{
		SoNgayLamViec = 1;
	}
	MaSo = maso;
	ChucDanh = chucdanh;
	if (hsl < 0)
		HeSoLuong = 1.0;
	else
		HeSoLuong = hsl;
}
NhanVien::NhanVien(string ten, int ngay)
{
	if (kiemTraHoTen(ten) == true)
		HoTen = ten;
	else
	{
		HoTen = "Nguyen Van A";
	}
	if (kiemTraNgay(ngay) == true)
		SoNgayLamViec = ngay;
	else
	{
		SoNgayLamViec = 1;
	}
	//gan ma so
	int len = ten.size();
	int countTen = 0;
	string chuSoTen;
	for (int i = len - 1; ten[i] != ' '; i--)
	{
		countTen++;
	}
	chuSoTen = ten.substr(len - countTen, countTen);
	string chuSoNgay = to_string(ngay);
	string maso = chuSoNgay + chuSoTen;
	MaSo = maso;
	//gan chuc danh
	if (ngay >= 0 && ngay <= 365)
	{
		ChucDanh = "Nhan Vien";
	}
	else if (ngay > 365 && ngay <= 730)
	{
		ChucDanh = "Quan ly";
	}
	else if (ngay > 730 && ngay <= 1460)
	{
		ChucDanh = "Truong phong";
	}
	else if (ngay > 1460)
	{
		ChucDanh = "Truong ban quan ly";
	}
	//gan he so luong
	if (ChucDanh == "Nhan Vien")
	{
		HeSoLuong = 1.0;
	}
	else if (ChucDanh == "Quan ly")
	{
		HeSoLuong = 1.5;
	}
	else if (ChucDanh == "Truong phong")
	{
		HeSoLuong = 2.25;
	}
	else if (ChucDanh == "Truong ban quan ly")
	{
		HeSoLuong = 4.0;
	}
}
NhanVien::NhanVien(const NhanVien& temp)
{
	HoTen = "Nguyen Van A";
	SoNgayLamViec = 1;
	MaSo = "1A";
	ChucDanh = temp.ChucDanh;
	HeSoLuong = temp.HeSoLuong;
	SoNgayLamViec = temp.SoNgayLamViec;
}
void NhanVien::ganHoTen(string str)
{
	HoTen = str;
}
void NhanVien::ganSoNgayLamViec(int ngay)
{
	SoNgayLamViec = ngay;
}
void NhanVien::ganMaSo()
{
	int len = HoTen.size();
	int countTen = 0;
	string chuSoTen;
	for (int i = len - 1; HoTen[i] != ' '; i--)
	{
		countTen++;
	}
	chuSoTen = HoTen.substr(len - countTen, countTen);
	string chuSoNgay = to_string(SoNgayLamViec);
	string maso = chuSoNgay + chuSoTen;
	MaSo = maso;
}
void NhanVien::ganChucDanh()
{
	if (SoNgayLamViec >= 0 && SoNgayLamViec <= 365)
	{
		ChucDanh = "Nhan Vien";
	}
	else if (SoNgayLamViec > 365 && SoNgayLamViec <= 730)
	{
		ChucDanh = "Quan ly";
	}
	else if (SoNgayLamViec > 730 && SoNgayLamViec <= 1460)
	{
		ChucDanh = "Truong phong";
	}
	else if (SoNgayLamViec > 1460)
	{
		ChucDanh = "Truong ban quan ly";
	}
}
void NhanVien::ganHeSoLuong()
{
	if (ChucDanh == "Nhan Vien")
	{
		HeSoLuong = 1.0;
	}
	else if (ChucDanh == "Quan ly")
	{
		HeSoLuong = 1.5;
	}
	else if (ChucDanh == "Truong phong")
	{
		HeSoLuong = 2.25;
	}
	else if (ChucDanh == "Truong ban quan ly")
	{
		HeSoLuong = 4.0;
	}
}
void NhanVien::nhapThongTin()
{
	cout << "Nhap ho ten:";
	getline(cin, HoTen);
	cout << "Nhap ngay:";
	cin >> SoNgayLamViec;
	/*ganMaSo();
	ganChucDanh();
	ganHeSoLuong();*/
}
void NhanVien::xuatThongTin()
{
	cout << "Thong tin cua nhan vien " << HoTen << " la:" << endl;
	cout << "So ngay lam viec:" << SoNgayLamViec << endl;
	cout << "Ma so:" << MaSo << endl;
	cout << "Chuc danh:" << ChucDanh << endl;
	cout << "He so luong:" << HeSoLuong << endl;
}