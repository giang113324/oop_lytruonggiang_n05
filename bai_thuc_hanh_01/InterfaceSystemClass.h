class SystemInterface {
private:
    bai_xe bai1, bai2, bai3;   // sau này dùng mảng
    bool co1, co2, co3; //có bãi xe 1, 2, 3 hay chưa? 

public:
    SystemInterface();
    void runMenu();// cho phép ng dung chọn 1, 2, 3, 4, ...
    //1 tạo bãi, 2 thêm xe, 3 xoá bãi, 4 lấy xe ra (xoá xe), 5 hiển thi, ...
};
