#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "hd_theongay.cpp"
using namespace std;
class arr_hd_theongay {
	private:
		vector <hd_theongay*> list_hd_theongay;
	public:
		void nhap();
		void search();
		void display();
		int thongKeSoLuongHoaDonTheoNgay();
		arr_hd_theongay();
		void option();
		~arr_hd_theongay();
};
void arr_hd_theongay::nhap() 
{
	hd_theongay hdngay;
	bool x = true;
	hdngay.nhap(); //nhap thong tin
	this->list_hd_theongay.push_back(&hdngay);
	for (int i = 0; i < list_hd_theongay.size(); i++)  // kiem tra ton tai
	{ 
		if (hdngay.getMaHD() == list_hd_theongay[i - 1]->getMaHD()) 
		{
			cout << "Ma ton tai !!" << endl;
			this->list_hd_theongay.pop_back();
			x = false;
		}
	}
	if (x == true) 
	{
		cout << "Them thanh cong !!" << endl;
		cout << "Nhan 'y' de luu thong tin"<< endl;
		char ch;
		cin.ignore();
		cin>>ch;
		if(ch=='y')
		{
			ofstream fileout;
			fileout.open("hd_theongay.txt",ios::app);
			hdngay.ghifile(fileout);
			cout<<"Luu thanh cong !!"<<endl;
			fileout.close();
		}
		else
		{
			cout<<"Khong luu thong tin!!"<<endl;
		}
	}
}
void arr_hd_theongay::search() 
{
	hd_theongay hdngay;
	string mahd;
	/// nhap ma hoa don muon tim
	cout<<"Nhap ma hoa don muon tim kiem: ";getline(cin,mahd);
	for(int i=0;i<list_hd_theongay.size();i++)
	{
		if(mahd==list_hd_theongay[i]->getMaHD())
		{
			list_hd_theongay[i]->xuat(); ///hien thi thong tin
			break;
		}
		if(i==(list_hd_theongay.size()-1))
		{
			cout<<"Ma khong ton tai!!"<<endl;
		}
	}	
}
void arr_hd_theongay::display() {
	for(int i=0;i<list_hd_theongay.size();i++)
	{
		list_hd_theongay[i]->xuat();
	}
}
int arr_hd_theongay::thongKeSoLuongHoaDonTheoNgay() {
	int dem=0;
	int d,m,y;
	cout <<"Nhap ngay: "; cin>>d;
	cout <<"Nhap thang: "; cin>>m;
	cout <<"Nhap nam: "; cin>>y;
	for(int i=0;i<list_hd_theongay.size();i++)
	{
		if(y==list_hd_theongay[i]->ngayHD.getY())
		{
			if(m==list_hd_theongay[i]->ngayHD.getM())
			{
				if(d==list_hd_theongay[i]->ngayHD.getD())
				{
					dem=dem+1;	
				}
			}
		}
	}
	ofstream fileout;
	fileout.open("ThongKeSoLuongHoaDonTheoNgay.txt",ios::app);
	fileout<<"So luong hoa don ngay ";
	fileout<<this->d<<"/";
	fileout<<this->m<<"/";
	fileout<<this->y<<"la :";
	fileout<<this->dem<<endl;
	fileout.close();
}
void arr_hd_theongay::option() {
	arr_hd_theongay dshdtheongay;
	int luachon;
	cout<<"Danh sach chuc nang:"<<endl
	<<"1. Nhap moi thong tin."<<endl
	<<"2. Tim kiem theo ma hoa don."<<endl
	<<"3. Hien thi tat ca thong tin hoa don."<<endl
	<<"4. Thong ke so luong thong tin hoa don theo ngay."<<endl
	<<"5. Xoa thong tin hoa don theo ma hoa don."<<endl
	<<"Vui long nhap lua chon theo so thu tu cua tung chuc nang!!"<<endl;
	cout<<"Thuc hien chuc nang thu: ";cin>>luachon;
	switch(luachon)
	{
		case 1: //chuc nang nhap
			dshdtheongay.nhap();
			break;
		case 2: //chuc nang tim kiem
			dshdtheongay.search();
			break;
		case 3: //chuc nang hien thi
			dshdtheongay.display();
			break;
		case 4: //chuc nang thong ke
			dshdtheongay.thongKeSoLuongHoaDonTheoNgay();
			break;
		case 5: //chuc nang xoa thong tin
			
			break;
		default: 
			cout<<"Khong phai chuc nang he thong!!";
			break;
	}
}


