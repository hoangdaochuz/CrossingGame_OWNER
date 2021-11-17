#pragma once
#include<iostream>
#include<string>
using namespace std;
string xoaKhoangTrang(string str);
bool kiemTraHoTen(string str);
bool kiemTraNgay(int ngay);
class NhanVien {
	string HoTen;
	int SoNgayLamViec;
	string MaSo;
	string ChucDanh;
	double HeSoLuong;
public:
	NhanVien();
	NhanVien(string ten, int ngay, string maso, string chucdanh, float hsl);
	NhanVien(string ten, int ngay);
	NhanVien(const NhanVien& temp);
	~NhanVien() {}
	void nhapThongTin();
	void xuatThongTin();
	string layHoTen()
	{
		return HoTen;
	}
	int laySoNgayLamViec()
	{
		return SoNgayLamViec;
	}
	string layMaSo()
	{
		return MaSo;
	}
	string layChucDanh()
	{
		return ChucDanh;
	}
	double layHeSoLuong()
	{
		return HeSoLuong;
	}
	void ganHoTen(string str);
	void ganSoNgayLamViec(int ngay);
	void ganMaSo();
	void ganChucDanh();
	void ganHeSoLuong();
};