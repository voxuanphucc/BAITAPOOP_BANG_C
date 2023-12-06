#include <iostream>
#include <vector>

using namespace std;

class CanBo {
public:
    string maCanBo;
    string hoTen;
    int tuoi;
    string gioiTinh;
    string diaChi;

    CanBo(string ma, string ten, int age, string gioiTinh, string diaChi)
        : maCanBo(ma), hoTen(ten), tuoi(age), gioiTinh(gioiTinh), diaChi(diaChi) {}

    virtual void nhapThongTin() {
        cout << "Nhap ma can bo: ";
        cin >> maCanBo;

        cout << "Nhap ho ten: ";
        cin.ignore();

        getline(cin, hoTen);

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cout << "Nhap gioi tinh: ";
        cin.ignore();

        getline(cin, gioiTinh);

        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    virtual void hienThiThongTin() const {
        cout << "Ma can bo: " << maCanBo << ", Ho ten: " << hoTen << ", Tuoi: " << tuoi
             << ", Gioi tinh: " << gioiTinh << ", Dia chi: " << diaChi << endl;
    }

    virtual ~CanBo() {}
};

class CongNhan : public CanBo {
public:
    int bac;

    CongNhan(string ma, string ten, int age, string gioiTinh, string diaChi, int bac)
        : CanBo(ma, ten, age, gioiTinh, diaChi), bac(bac) {}

    void nhapThongTin() override {
        CanBo::nhapThongTin();
        cout << "Nhap bac cong nhan (1-10): ";
        cin >> bac;
    }

    void hienThiThongTin() const override {
        CanBo::hienThiThongTin();
        cout << "Bac cong nhan: " << bac << endl;
    }
};

class KySu : public CanBo {
public:
    string nganhDaoTao;

    KySu(string ma, string ten, int age, string gioiTinh, string diaChi, string nganh)
        : CanBo(ma, ten, age, gioiTinh, diaChi), nganhDaoTao(nganh) {}

    void nhapThongTin() override {
        CanBo::nhapThongTin();
        cout << "Nhap nganh dao tao cua ky su: ";
        getline(cin, nganhDaoTao);
    }

    void hienThiThongTin() const override {
        CanBo::hienThiThongTin();
        cout << "Nganh dao tao cua ky su: " << nganhDaoTao << endl;
    }
};

class NhanVien : public CanBo {
public:
    string congViec;

    NhanVien(string ma, string ten, int age, string gioiTinh, string diaChi, string cv)
        : CanBo(ma, ten, age, gioiTinh, diaChi), congViec(cv) {}

    void nhapThongTin() override {
        CanBo::nhapThongTin();
        cout << "Nhap cong viec cua nhan vien: ";
        getline(cin, congViec);
    }

    void hienThiThongTin() const override {
        CanBo::hienThiThongTin();
        cout << "Cong viec cua nhan vien: " << congViec << endl;
    }
};

class QLCB {
private:
    vector<CanBo*> danhSachCanBo;

public:
    void themMoiCanBo() {
        int luaChon;
        cout << "Chon loai can bo (1. Cong nhan, 2. Ky su, 3. Nhan vien): ";
        cin >> luaChon;

        CanBo* canBo = NULL;

        switch (luaChon) {
            case 1:
                canBo = new CongNhan("", "", 0, "", "", 0);
                break;
            case 2:
                canBo = new KySu("", "", 0, "", "", "");
                break;
            case 3:
                canBo = new NhanVien("", "", 0, "", "", "");
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                return;
        }

        canBo->nhapThongTin();
        danhSachCanBo.push_back(canBo);
        cout << "Them moi thanh cong!" << endl;
    }

    void timKiemTheoHoTen() {
        string hoTen;
        cout << "Nhap ho ten can tim kiem: ";
        cin.ignore();

        getline(cin, hoTen);

        cout << "Ket qua tim kiem theo ho ten '" << hoTen << "':" << endl;
        for (size_t i = 0; i < danhSachCanBo.size(); ++i) {
            if (danhSachCanBo[i]->hoTen == hoTen) {
                danhSachCanBo[i]->hienThiThongTin();
            }
        }
    }

    void hienThiTheoCap() {
        cout << "Danh sach can bo theo cap(tu 3->1 la):" << endl;
        for (size_t i = 0; i < danhSachCanBo.size(); ++i) {
            cout << "Cap: ";
            danhSachCanBo[i]->hienThiThongTin();
        }
    }

    void xoaCanBo() {
        string maCanBo;
        cout << "Nhap ma can bo can xoa: ";
        cin >> maCanBo;

        for (size_t i = 0; i < danhSachCanBo.size(); ++i) {
            if (danhSachCanBo[i]->maCanBo == maCanBo) {
                delete danhSachCanBo[i];
                danhSachCanBo.erase(danhSachCanBo.begin() + i);
                cout << "Xoa thanh cong!" << endl;
                return;
            }
        }

        cout << "Khong tim thay can bo voi ma '" << maCanBo << "'." << endl;
    }

    void hienThiTheoMaCanBo() {
        string maCanBo;
        cout << "Nhap ma can bo can hien thi thong tin: ";
        cin >> maCanBo;

        for (size_t i = 0; i < danhSachCanBo.size(); ++i) {
            if (danhSachCanBo[i]->maCanBo == maCanBo) {
                danhSachCanBo[i]->hienThiThongTin();
                return;
            }
        }

        cout << "Khong tim thay can bo voi ma '" << maCanBo << "'." << endl;
    }

    void hienThiMenu() {
        int luaChon;

        do {
            cout << "\n===== MENU =====" << endl;
            cout << "1. Them moi can bo" << endl;
            cout << "2. Tim kiem theo ho ten" << endl;
            cout << "3. Hien thi theo cap" << endl;
            cout << "4. Xoa can bo" << endl;
            cout << "5. Hien thi thong tin theo ma can bo" << endl;
            cout << "0. Thoat" << endl;
            cout << "Nhap lua chon cua ban: ";
            cin >> luaChon;

            switch (luaChon) {
                case 1:
                    themMoiCanBo();
                    break;
                case 2:
                    timKiemTheoHoTen();
                    break;
                case 3:
                    hienThiTheoCap();
                    break;
                case 4:
                    xoaCanBo();
                    break;
                case 5:
                    hienThiTheoMaCanBo();
                    break;
                case 0:
                    cout << "Tam biet!" << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            }
        } while (luaChon != 0);
    }

    ~QLCB() {
        for (size_t i = 0; i < danhSachCanBo.size(); ++i) {
            delete danhSachCanBo[i];
        }
    }
};

int main() {
    QLCB qlcb;
    qlcb.hienThiMenu();
    return 0;
}

