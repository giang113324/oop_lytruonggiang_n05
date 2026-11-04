#include <iostream>
#include <iomanip>
#include <BaiXeClass.h>
using namespace std;

class SystemInterface {
private:
    bai_xe bai1, bai2, bai3;   // sau này dùng mảng
    bool co1, co2, co3;

public:
    SystemInterface();
    void runMenu();
};

SystemInterface::SystemInterface() : co1(false), co2(false), co3(false) {}

void SystemInterface::runMenu() {
    int chon;
    while (true) {
        cout << "\n===== QUAN LY BAI DO XE =====\n";
        cout << "1. Tao bai do\n";
        cout << "2. Them xe\n";
        cout << "3. Xoa bai do\n";
        cout << "4. Lay xe ra\n";
        cout << "5. Hien thi tat ca bai do\n";
        cout << "6. Hien thi xe theo bai\n";
        cout << "7. Liet ke xe theo loai\n";
        cout << "8. Bao cao phi trung binh\n";
        cout << "9. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
//các e chuyển sang lệnh switch cho thầy
        if (chon == 1) {
            int ma; char kt;
            cout << "Ma bai: "; cin >> ma;
            cout << "Kich thuoc (S/M/L): "; cin >> kt;
            if (!co1)      { bai1 = bai_xe(ma, kt); co1 = true; }
            else if (!co2) { bai2 = bai_xe(ma, kt); co2 = true; }
            else           { bai3 = bai_xe(ma, kt); co3 = true; }
            cout << "Da tao bai " << ma << "\n";
        }
        else if (chon == 2) {
            int ma, gio, tg; string loai;
            cout << "Ma xe: "; cin >> ma;
            cout << "Loai (Car/Motorcycle/Bicycle): "; cin >> loai;
            cout << "Gio vao (0-23): "; cin >> gio;
            cout << "Thoi luong (1-23): "; cin >> tg;
            phuong_tien v(ma, loai, gio, tg);
            bool ok = false;
            if (co1 && !ok) ok = bai1.them(v);
            if (co2 && !ok) ok = bai2.them(v);
            if (co3 && !ok) ok = bai3.them(v);
            if (ok) cout << "Da them xe " << ma << " | Phi: $" << fixed << setprecision(2) << v.tinh_phi() << "\n";
            else    cout << "Tat ca bai da day!\n";
        }
        else if (chon == 3) {
            int ma;
            cout << "Ma bai can xoa: "; cin >> ma;
            if (co1 && bai1.lay_ma() == ma) {
                if (co2) { bai1 = bai2; if (co3) { bai2 = bai3; co3 = false; } else co2 = false; }
                else co1 = false;
                cout << "Da xoa bai " << ma << "\n";
            }
            else if (co2 && bai2.lay_ma() == ma) {
                if (co3) { bai2 = bai3; co3 = false; } else co2 = false;
                cout << "Da xoa bai " << ma << "\n";
            }
            else if (co3 && bai3.lay_ma() == ma) {
                co3 = false;
                cout << "Da xoa bai " << ma << "\n";
            }
        }
        else if (chon == 4) {
            int ma;
            cout << "Ma xe can lay ra: "; cin >> ma;
            bool ok = false;
            if (co1 && !ok) ok = bai1.xoa(ma);
            if (co2 && !ok) ok = bai2.xoa(ma);
            if (co3 && !ok) ok = bai3.xoa(ma);
            cout << (ok ? "Da lay xe ra\n" : "Khong tim thay xe\n");
        }
        else if (chon == 5) {
            if (co1) bai1.hien_thi();
            if (co2) bai2.hien_thi();
            if (co3) bai3.hien_thi();
        }
        else if (chon == 6) {
            int ma;
            cout << "Ma bai: "; cin >> ma;
            if (co1 && bai1.lay_ma() == ma) bai1.hien_thi();
            else if (co2 && bai2.lay_ma() == ma) bai2.hien_thi();
            else if (co3 && bai3.lay_ma() == ma) bai3.hien_thi();
        }
        else if (chon == 7) {
            string loai;
            cout << "Loai xe: "; cin >> loai;
            int dem; double tong;
            if (co1 && bai1.co_loai(loai, dem, tong)) bai1.hien_thi();
            if (co2 && bai2.co_loai(loai, dem, tong)) bai2.hien_thi();
            if (co3 && bai3.co_loai(loai, dem, tong)) bai3.hien_thi();
        }
        else if (chon == 8) {
            string loai_arr[3] = {"Car", "Motorcycle", "Bicycle"};
            for (int t = 0; t < 3; ++t) {
                int dem = 0; double tong = 0;
                int d; double s;
                if (co1) { bai1.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                if (co2) { bai2.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                if (co3) { bai3.co_loai(loai_arr[t], d, s); dem += d; tong += s; }
                cout << loai_arr[t] << ": ";
                if (dem == 0) cout << "khong co xe\n";
                else cout << dem << " xe | TB: $" << fixed << setprecision(2) << tong / dem << "\n";
            }
        }
        else if (chon == 9) break;
    }
}