class SystemInterface {
private:
    bai_xe bai1, bai2, bai3;   // sau này dùng mảng
    bool co1, co2, co3; //có bãi xe 1, 2, 3 hay chưa? 

public:
    SystemInterface();
    void runMenu();// cho phép ng dung chọn 1, 2, 3, 4, ...
    //1 tạo bãi, 2 thêm xe, 3 xoá bãi, 4 lấy xe ra (xoá xe), 5 hiển thi, ...
};

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
    }