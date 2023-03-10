#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
using namespace std;

//Lop Cha

class DocGia{
   
    protected:
        string hoten;
        string ngaylapthe;
        int sothangcohieuluc;
    public:
        void Input();
        void Output();
        
};
//Dinh nghia phuong thuc nhap cua Lop cha la lop Doc Gia
void DocGia::Input(){
    fflush(stdin);   // Xoa bo nho dem
    cout << "\nNhap ho ten doc gia: ";
    getline(cin, hoten);
    fflush(stdin);
    cout << "\nNhap ngay lap the (dd/mm/yyyy): ";
    getline(cin, ngaylapthe);
    cout << "\nNhap so thang co hieu luc: ";
    cin >> sothangcohieuluc;

}

//Dinh nghia phuong thuc xuat cua lop cha la lop doc gia
void DocGia::Output(){
    cout << "\nHo ten doc gia: " << hoten;
    cout << "\nNgay lap the (dd/mm/yyyy): " << ngaylapthe;
    cout << "\nSo thang co hieu luc: " << sothangcohieuluc;
}



//Lop con

class DocGiaTreEm : public DocGia{
    private:
        string hotenNDD;    // Ho ten nguoi dai dien
    public:
        void Input();
        void Output();
        int Tinh_Tien_Lam_The();     // Phuong thuc tinh tien lam the cua doc gia tre em
       
};




//Dinh nghia phuong thuc nhap cua lop con la Doc gia tre em
void DocGiaTreEm::Input(){
    //goi lai phuong thuc nhap thong tin doc gia cua lop cha
    DocGia::Input();  // nhap thong tin chung
    fflush(stdin);
    cout << "\nNhap ho ten nguoi dai dien: ";
    getline(cin, hotenNDD);
}

//Dinh nghia phuong thuc xuat cua lop con la doc gia tre em
void DocGiaTreEm::Output(){
    DocGia::Output();
    cout << "\nHo ten nguoi dai dien: " << hotenNDD;
}
//Phuong thuc tinh tien lam the cua doc gia tre em

int DocGiaTreEm::Tinh_Tien_Lam_The(){
    return sothangcohieuluc * 5000;
}

// Lop nguoi lon ke thua lop cha la lop Doc Gia
class DocGiaNguoiLon : public DocGia{
    private:
        string CMND;
    public:
        void Input();
        void Output();
        int Tinh_Tien_Lam_The();

       
};



//Dinh nghia phuong thuc nhap cua lop con la doc gia nguoi lon
void DocGiaNguoiLon::Input(){
    DocGia::Input();
    fflush(stdin);
    cout << "\nNhap CMND: ";
    getline(cin,CMND);

}

//Dinh nghia phuong thuc xuat cua lop con la doc gia nguoi lon
void DocGiaNguoiLon::Output(){
    DocGia::Output();
    cout << "\nCMND: " << CMND;
}
//Phuong thuc tinh tien lam the cho doc gia nguoi lon

int DocGiaNguoiLon::Tinh_Tien_Lam_The(){
    return sothangcohieuluc * 10000;
}

// Lop thu vien

class ThuVien{
    private:
        vector<DocGiaTreEm> ds_docgiatreem;
        vector<DocGiaNguoiLon> ds_docgianguoilon;
    public:
    void Input();
    void Output();
    int Tinh_Tong_Tien_Lam_The();
    
};

// Phuong thuc nhap thong tin cac loai doc gia
void ThuVien::Input(){
    int luachon;
    while(true){
        system("cls");
        cout << "\n\n\t\t============Thu Vien============";
        cout << "\n\t 1.Doc Gia Tre Em.";
        cout << "\n\t 2.Doc Gia Nguoi Lon.";
        cout << "\n\t 3. Thoat.";
        cout << "\n\n\t\t============End=================";
        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if(luachon == 1){
            DocGiaTreEm x; // Khai bao doi tuong doc gia tre em
            cout << "\n\n\t\t Nhap thong tin doc gia\n";
            x.Input();
            ds_docgiatreem.push_back(x);  // them doi tuong doc gia tre em x vao trong mang vector

        }
        if(luachon == 2){
            DocGiaNguoiLon x; // Khai bao doi tuong doc gia nguoi lon
            cout << "\n\n\t\t Nhap thong tin doc gia\n";
            x.Input();
            ds_docgianguoilon.push_back(x);  // them doi tuong doc gia nguoi lon x vao trong mang vector
            
        }
        else if(luachon == 3){
            break;
        }
        else {
            cout << "\nLua chon khong hop le!\n";
            system("pause");
        }
    }
}
//Phuong thuc xuat thong tin
void ThuVien::Output(){
    //Xuat thong tin doc gia nguoi lon
    for(int i =0;i<ds_docgiatreem.size();i++){
        cout << "\n\n\t\tTHONG TIN DOC GIA TRE EM THU " << i + 1 << endl;
        ds_docgiatreem[i].Output();
    }
    //Xuat thong tin doc gia nguoi lon
    for(int i =0;i<ds_docgianguoilon.size();i++){
        cout << "\n\n\t\tTHONG TIN DOC GIA NGUOI LON THU " << i + 1 << endl;
        ds_docgianguoilon[i].Output();
    }
}

//Tinh tong tien lam the

int ThuVien::Tinh_Tong_Tien_Lam_The(){
    int sum = 0;
    //duyet danh sach doc gia tre em
    for(int i =0;i<ds_docgiatreem.size();i++){
        sum = sum + ds_docgiatreem[i].Tinh_Tien_Lam_The();
    }
    //Duyet danh sach doc gia nguoi lon
    for(int i =0;i<ds_docgianguoilon.size();i++){
        sum = sum + ds_docgianguoilon[i].Tinh_Tien_Lam_The();
    }
    return sum;
    
}
int main(){
    system("cls");
    ThuVien *x = new ThuVien;
    x->Input();
    x->Output();
    cout << "\n\n\t\tTong tien lam the: " << x->Tinh_Tong_Tien_Lam_The() << " VND";
    cout << endl;
    
    delete x;
    return 0;
}