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
    cout<<"Nhập tên";
    cin>>hoTen;
    cout<<"Nhập SDT";
    cin>>sdt;
    cout<<"Nhập Địa chỉ";
    cin>>diaChi;
}
void KH::In() {
    cout<<"Tên la: "<<hoTen<<endl;
    cout<<"SDT: "<<sdt<<endl;
    cout<<"Địa chỉ: "<<diaChi<<endl;
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
    cout<<"Nhập tên";
    cin>>hoTen;
    cout<<"Nhập SDT";
    cin>>sdt;
    cout<<"Nhập Địa chỉ";
    cin>>diaChi;
    cout<<"Nhập Tên Cửa Hàng";
    cin>>tenCuaHang;
    cout<<"Nhập mã số thuế";
    cin>>msThue;
}
void ChuCuaHang::In() {
    cout<<"Tên la: "<<hoTen<<endl;
    cout<<"SDT: "<<sdt<<endl;
    cout<<"Địa chỉ: "<<diaChi<<endl;
    cout<<"Tên cửa hàng: "<<tenCuaHang<<endl;
    cout<<"Mã số thuế: "<<msThue<<endl;
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
    cout<<"Nhập tên mặt hàng";
    cin>>tenMatHang;
    cout<<"Nhập số lượng";
    cin>>sl;
    cout<<"Nhập đơn giá";
    cin>>donGia;
    cout<<"Nhập đơn vị tính";
    cin>>dvt;
}
void MatHang::In() {
    cout<<"Tên mặt hàng: "<<tenMatHang<<endl;
    cout<<"Số lượng: "<<sl<<endl;
    cout<<"Đơn giá: "<<donGia<<endl;
    cout<<"Đơn vị: "<<dvt<<endl;
    cout<<"Thành tiền: "<<ThanhTien()<<endl;
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
};
HoaDon::HoaDon(){
    soMH = 0;
    a = NULL;
};
void HoaDon::Nhap() {
    cout<<"Nhập thông tin chủ cửa hàng";
    x.Nhap();
    cout<<"Nhập thông tin khách hàng";
    y.Nhap();
    cout<<"Nhập số lượng mặt hàng";
    cin>>soMH;
    a = new MatHang[soMH];
    for (int i = 0; i<soMH; i++) {
        cout<<"Nhập thông tin mặt hàng";
        a[i].Nhap();
    }
}
void HoaDon::In() {
    cout<<"Thông tin chủ cửa hàng";
    x.In();
    cout<<"Thông tin khách hàng";
    y.In();
    cout<<"Số lượng mặt hàng";
    cout<<soMH;
    for (int i = 0; i<soMH; i++) {
        cout<<"Thông tin mặt hàng";
        a[i].In();
    }
}

int main() {
    cout<<"HII";
}