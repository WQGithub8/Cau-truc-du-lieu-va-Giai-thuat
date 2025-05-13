#include <iostream>
using namespace std;

struct mangMotChieu {
	int soPhanTu = 0;
	int mang[100];
	
	void nhapMangMotChieu() {
		cout << "Nhap so luong phan tu: ";
		cin >> soPhanTu;
		cout << "Nhap mang: " << endl;
		for (int i = 0; i < soPhanTu; i++) {
			cin >> mang[i];
		}
	}
	
	void xuatMangMotChieu() {
		if (soPhanTu == 0) {
			cout << "Empty Array" << endl;
		} 
		else {
			for (int i = 0; i < soPhanTu; i++) {
				cout << mang[i] << " ";
			}
			cout << endl;
		}
	}
	
	int viTriChen(int phanTu) {
		for (int i = 0; i < soPhanTu; i++) {
			if (phanTu < mang[i]) return i;
		}
		return soPhanTu;	
	}
	
	void chenPhanTu(int phanTu) {
		int viTri = viTriChen(phanTu);
		for (int i = soPhanTu; i > viTri; i--) {
			mang[i] = mang[i - 1];		
		}
		mang[viTri] = phanTu;
		soPhanTu++;
	}
	
	int viTri(int phanTu) {
		if (phanTu > mang[soPhanTu - 1] || phanTu < mang[0]) return -1;
		for (int i = 0; i <= soPhanTu / 2; i++) {
			if (mang[i] == phanTu) {
				return i;
			}
			else if (mang[soPhanTu - 1 - i] == phanTu) {
				return soPhanTu - 1 - i;
			}
		}
		return -1;
	}
	
	void xoaPhanTuTaiViTri(int viTri) {
		if (soPhanTu == 0) {
			cout << "Empty Array.";
		}
		else {
		    if (viTri < soPhanTu) {
				for (int i = viTri; i < soPhanTu - 1; i++) {
					mang[i] = mang[i + 1];
				}
			}
			soPhanTu--;
		}
	}
	
	void xoaPhanTu(int phanTu) {
		int i;
		
		if (soPhanTu == 0) {
			cout << "Empty Array.";
		}
		else {
			for (i = 0; i < soPhanTu; i++) {
				if (mang[i] == phanTu) {
					xoaPhanTuTaiViTri(i);
					i--;
				}
			}
		}
	}
	
	bool kiemTraMangTangDan() {
		for (int i = 0; i < soPhanTu - 1; i++) {
			if (mang[i] >= mang [i + 1]) return false;
		}
		return true;
	}
	
	bool kiemTraMangGiamDan() {
		for (int i = 0; i < soPhanTu - 1; i++) {
			if (mang[i] <= mang [i + 1]) return false;
		}
		return true;
	}
	
	bool kiemTraMangKhongTang() {
		for (int i = 0; i < soPhanTu - 1; i++) {
			if (mang[i] < mang [i + 1]) return false;
		}
		return true;
	}
	
	bool kiemTraMangKhongGiam() {
		for (int i = 0; i < soPhanTu - 1; i++) {
			if (mang[i] > mang [i + 1]) return false;
		}
		return true;
	}
	
	void menu() {
		cout << "\n----------MANG MOT CHIEU----------";
		cout << "\n1. Nhap mang";
		cout << "\n2. Xuat mang";
		cout << "\n3. Chen phan tu";
		cout << "\n4. Xoa phan tu";
		cout << "\n5. Xoa phan tu tai vi tri";
		cout << "\n6. Tim phan tu";
		cout << "\n0. Thoat";
		cout << "\nNhap lua chon: ";
	}

}; 

int main() {	
	mangMotChieu a;
	char option;
	
	do {
		a.menu();
		cin >> option;
		switch (option) {
			case '1':
				a.nhapMangMotChieu();
				break;
			case '2':
				a.xuatMangMotChieu();
				break;
			case '3':
				int phanTu;
				cout << "Nhap phan tu can chen: ";
				cin >> phanTu;
				a.chenPhanTu(phanTu);
				break;
			case '4':
				int phanTuXoa;
				cout << "Nhap phan tu can xoa: ";
				cin >> phanTuXoa;
				a.xoaPhanTu(phanTuXoa);
				break;
			case '5':
				int viTri;
				cout << "Nhap vi tri can xoa: ";
				cin >> viTri;
				a.xoaPhanTuTaiViTri(viTri);
				break;
			case '6':
				int phanTuCanTim;
				cout << "Nhap phan tu can tim: ";
 				cin >> phanTuCanTim;
				cout << "Vi tri: " << a.viTri(phanTuCanTim) << endl;
				break;
			case '0':
				cout << "Chuong trinh ket thuc!" << endl;
				break;
			default:
				cout << "Vui long nhap hop le!!!" << endl;
		}
	}
	while (option != '0'); 
	
	return 0;
}
