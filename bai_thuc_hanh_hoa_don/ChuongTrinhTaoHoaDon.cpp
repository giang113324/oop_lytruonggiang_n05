#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class KH {
    string hoTen;
    string sdt;
    string diaChi;
    public:
        KH ();
        void Nhap();
        void In();
};
KH::KH() {
    hoTen = "";
    sdt = "";
    diaChi = "";
}
void KH::Nhap() {
    cout<<"Ten Khach hang: ";
    cin>>hoTen;
    cout<<"Nhap sdt: ";
    cin>>sdt;
    cout<<"Nhap dia chi: ";
    cin>>diaChi;
}
void KH::In() {
    cout<<"Ten la: "<<hoTen<<" | "<<"SDT: "<<sdt<<" | "<<"Dia Chi: "<<diaChi<<endl;
}

class ChuCuaHang {
    string hoTen;
    int sdt;
    string diaChi;
    string tenCuaHang;
    float msThue;
    public:
        ChuCuaHang ();
        void Nhap();
        void In();
};
ChuCuaHang::ChuCuaHang(){
    hoTen = "";
    sdt = 0;
    diaChi = "";
    tenCuaHang = "";
    msThue = 0;
};
void ChuCuaHang::Nhap() {
    cout<<"Ten Chu cua hang la: ";
    cin>>hoTen;
    cout<<"Sdt la: ";
    cin>>sdt;
    cout<<"Dia chi la: ";
    cin>>diaChi;
    cout<<"Nhap ten cua hang: ";
    cin>>tenCuaHang;
    cout<<"Nhap ma so thue: ";
    cin>>msThue;
}
void ChuCuaHang::In() {
    cout<<"Ten chu cua hang: "<<hoTen<<" | "<<"SDT: "<<sdt<<" | "<<"Dia Chi: "<<diaChi<<endl;
    cout<<"Ten cua hang: "<<tenCuaHang<<" | "<<"Ma so thue: "<<msThue<<endl;
}

class MatHang {
    string tenMatHang;
    int sl;
    int donGia;
    string dvt;
    public:
        MatHang ();
        void Nhap();
        void In();
        float ThanhTien() {
            return donGia*sl;
        };
};
MatHang::MatHang(){
    tenMatHang = "";
    sl = 0;
    donGia = 0;
    dvt = "";
}
void MatHang::Nhap() {
    cout<<"Nhap ten mat hang: ";
    cin>>tenMatHang;
    cout<<"Nhap so luong: ";
    cin>>sl;
    cout<<"Nhap don gia: ";
    cin>>donGia;
    cout<<"Nhap dvt: ";
    cin>>dvt;
}
void MatHang::In() {
    cout<<"Ten mat hang: "<<tenMatHang<<endl;
    cout<<"So luong: "<<sl<<endl;
    cout<<"Don gia: "<<donGia<<endl;
    cout<<"Don vi tinh: "<<dvt<<endl;
    cout<<"Total: "<<ThanhTien()<<"\n"<<endl;
}

class HoaDon {
    ChuCuaHang x;
    KH y;
    int soMH;
    MatHang *a;
    public:
        HoaDon();
        void Nhap();
        void In();
        float TongTien(){
            float sum = 0;
            for (int i = 0; i<soMH; i++) {
                sum += a[i].ThanhTien();
            }
            return sum;
        };
};
HoaDon::HoaDon(){
    soMH = 0;
    a = NULL;
};
void HoaDon::Nhap() {
    cout<<"Nhap thong tin chu cua hang\n";
    x.Nhap();
    cout<<"Nhap thong tin khach hang\n";
    y.Nhap();
    cout<<"Nhap so luong mat hang\n";
    cin>>soMH;
    a = new MatHang[soMH];
    for (int i = 0; i<soMH; i++) {
        cout<<"Nhap thong tin mat hang: \n";
        a[i].Nhap();
    }
}
void HoaDon::In() {
    cout<<"\nThong tin chu cua hang\n";
    x.In();
    cout<<"\nThong tin khach hang\n";
    y.In();
    cout<<"So luong mat hang: "<<soMH<<"\n"<<endl;
    for (int i = 0; i<soMH; i++) {
        cout<<"Thong tin Mat Hang: \n";
        a[i].In();
    }
    cout<<"Tong tien: "<<TongTien()<<endl;
}

int main() {
    HoaDon i;
    i.Nhap();
    i.In();
}