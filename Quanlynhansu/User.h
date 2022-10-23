#pragma once
#pragma once

class User {
protected:
    string userName, passWord, name, address, phone, email;
public:
    string getUserName() { return userName; }
    string getPassWord() { return passWord; }
    string getName() { return name; }
    string getAddress() { return address; }
    string getPhone() { return phone; }
    string getEmail() { return email; }
    void setUserName(string _userName) { userName = _userName; }
    void setPassWord(string _passWord) { passWord = _passWord; }
    void setName(string _name) { name = _name; }
    void setAddress(string _address) { address = _address; }
    void setPhone(string _phone) { name = _phone; }
    void setEmail(string _email) { email = _email; }

    User(string _userName = "", string _passWord = "111111", string _name = "", string _address = "", string _phone = "", string _email = "")
    {
        userName = _userName;
        passWord = _passWord;
        name = _name;
        address = _address;
        phone = _phone;
        email = _email;
    }
    User(const User& u) {
        userName = u.userName;
        passWord = u.passWord;
        name = u.name;
        address = u.address;
        phone = u.phone;
        email = u.email;
    }
    ~User() {}
    //đọc file
    void docFile(int& nUS, ifstream& fi)
    {
        string _userName;
        getline(fi, _userName);
        if (_userName == "") {
            return;
        }
        else {
            this->userName = _userName;
            string _passWord;
            getline(fi, _passWord);
            this->passWord = _passWord;
            string _name;
            getline(fi, _name);
            this->name = _name;
            string _address;
            getline(fi, _address);
            this->address = _address;
            string _phone;
            getline(fi, _phone);
            this->phone = _phone;
            string _email;
            getline(fi, _email);
            this->email = _email;
            string key;
            getline(fi, key);
            if (key == "") nUS++;
        }
    }

    virtual void readFile(ifstream& fileIn) {
        getline(fileIn, userName, ',');
        getline(fileIn, passWord);
        getline(fileIn, name);
        getline(fileIn, address);
        getline(fileIn, phone);
        getline(fileIn, email);
    }

    //tạo file
    virtual void createFile(ofstream& FileOut, char*& fileName) {
        string str = (string)fileName;//tên file
        string strFile = "C:\\" + str + ".TXT";//đường dẫn
        fileName = new char[strFile.length() + 1];//tạo một chuỗi mới
        strcpy(fileName, strFile.c_str());//coppy từ sang chuỗi đích từ chuỗi nguồn
        if (fileName != NULL)// nếu không NULL sẽ mở file
        {
            FileOut.open(fileName, ios_base::out);
        }
        delete[] fileName;//NULL là delete
    }

    //xóa file
    virtual void deleteFile(string fileName) {
        char c = 34;
        string Del = "del ";
        string FilePath1 = "C:\\";
        string FilePath2 = ".txt";
        string strDel = c + Del + FilePath1 + fileName + FilePath2 + c;
        char* chuoiXoa = new char[strDel.length() + 1];
        strcpy(chuoiXoa, strDel.c_str());
        system(chuoiXoa);
    }

    //nhập thông tin
    virtual void input() {
        cin.ignore();
        cout << " Nhap thong tin ca nhan " << endl;
        cout << " Ho ten : ";
        getline(cin, name);//nhập từ bàn phím
        cout << " Dia chi: ";
        getline(cin, address);
        cout << " So dien thoai: ";
        getline(cin, phone);
        cout << " Dia chi Email: ";
        getline(cin, email);
    }

    //đọc thông tin từng dòng
    virtual void readInfomation(ifstream& fileIn) {
        getline(fileIn, name);
        getline(fileIn, address);
        getline(fileIn, phone);
        getline(fileIn, email);
    }

    //mở file
    virtual void openFile(ifstream& fileIn, char*& fileName) {//nếu file đã có thì mở file
        string str = (string)fileName;// tên file
        string strFile = "C:\\" + str + ".TXT";//đường dẫn
        fileName = new char[strFile.length() + 1];
        strcpy(fileName, strFile.c_str());
        if (fileName != NULL)
        {
            fileIn.open(fileName, ios_base::in);
        }
        delete[] fileName;
    }
};