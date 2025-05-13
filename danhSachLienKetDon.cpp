#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

typedef Node* List;

struct danhSachLienKetDon {
	List nutDauTien = NULL;
	
	void themVaoDauDanhSach(int data) {
		Node* nutMoi = new(Node);
		nutMoi->data = data;
		nutMoi->next = nutDauTien;
		nutDauTien = nutMoi; 
	}
	
	void themVaoCuoiDanhSach(int data) {
		Node* nutMoi = new(Node);
		nutMoi->data = data;
		nutMoi->next = NULL;
		List duyet = nutDauTien;
		if (duyet == NULL) nutDauTien = nutMoi;
		else {
			while (duyet->next != NULL) {
				duyet = duyet->next;
			}
			duyet->next = nutMoi;
		}
	}
	
	void xoaDauDanhSach() {
		if (nutDauTien == NULL) {
			cout << "Danh sach rong.";
			return;
		}
		else {
			List temp = nutDauTien;
			nutDauTien = nutDauTien->next;
			delete temp;
		}
	}
	
	void xoaCuoiDanhSach() {
		List duyet = nutDauTien;
		if (nutDauTien == NULL) {
			cout << "Danh sach rong.";
			return;
		}
		else {
			while (duyet->next->next != NULL) {
				duyet = duyet->next;
			}
			delete duyet->next; 
			duyet->next = NULL;
		}
	}
	
	void menuCacPhuongThucThem() {
		cout << "Chon phuong thuc them vao danh sach:" << endl;
		cout << "1. Luon them vao dau danh sach" << endl;
		cout << "2. Luon them vao cuoi danh sach" << endl;
		cout << "3. Lua chon cho tung phan tu" << endl;
		cout << "0. Thoat" << endl;
		cout << endl;
		cout << "Nhap chon phuong thuc: ";
	}
	
	void nhapDanhSach() {
		int duLieu;	
		cout << "Nhap danh sach (nhap 0 de thoat): " << endl;
		
		do {
			cin >> duLieu;
			if (duLieu == 0) break; 
			themVaoDauDanhSach(duLieu);
		}
		while (duLieu != 0);
	}

	void xuatDanhSach() {
		List duyet = nutDauTien;
		if (duyet == NULL) cout << "Empty List." << endl;
		else {
			while (duyet != NULL) {
				cout << duyet->data << " ";
				duyet = duyet->next;
			}
			cout << endl;	
		}
	}
	
	void menu() {
		cout << "\n----------DANH SACH LIEN KET DON----------";
		cout << "\n1. Nhap danh sach";
		cout << "\n2. Xuat danh sach";
		cout << "\n3. Them vao dau danh sach";
		cout << "\n4. Them vao cuoi danh sach";
		cout << "\n5. Xoa dau danh sach";
		cout << "\n6. Xoa cuoi danh sach";
		cout << "\n0. Thoat";
		cout << "\nNhap lua chon: ";
	}
}; 

int main() {
	danhSachLienKetDon danhSach;
	char option;
	
	do {
		danhSach.menu();
		cin >> option;
		switch (option) {
			case '1':
				danhSach.nhapDanhSach();
				break;
			case '2':
			 	danhSach.xuatDanhSach();
				break;
			case '3':
				cout << "Nhap du lieu: ";
				int dlCase3;
				cin >> dlCase3;
				danhSach.themVaoDauDanhSach(dlCase3);
				break;
			case '4':
				cout << "Nhap du lieu: ";
				int dlCase4;
				cin >> dlCase4;
				danhSach.themVaoCuoiDanhSach(dlCase4);
				break;
			case '5':
				danhSach.xoaDauDanhSach();
				break;
			case '6':
				danhSach.xoaCuoiDanhSach();
				break;
			case '0':
				cout << "Ket thuc chuong trinh." << endl;
				break;
			default:
				cout << "Vui long nhap hop le!!!";
		}
	}
	while (option != '0');
	
	return 0;
}
