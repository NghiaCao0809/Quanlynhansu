#pragma once

template <class T>
bool isEmpty(int n, T a) {
	return (n == 0);
}

template <class T>
void loadFile(int n, T* array, string fileText) {
	ofstream fi(fileText, ios::out);
	for (int i = 0; i < n; i++) {
		array[i].ghiFile(fi);
	}
	fi.close();
}

template <class T>
void getDS(int& n, T* array, string fileText) {
	ifstream fi(fileText);
	while (!fi.eof()) {
		array[n].docFile(n, fi);
	}
	fi.close();
}

void exit() {
	char x = _getch();
	while (x != 27) {
		if (x != -32) {
			SetColor(0, 12);
			cout << "Nhan ESC de quay lai." << endl;
		}
		x = _getch();
	}
}


// 1 - Main menu
// 2 - Admin menu
// 3 - Update menu
// 4 - Employee menu

void titleSelection(int choice, int k, int t)
{
	string message;
	switch (t)
	{
	case 1:
	{
		switch (choice)
		{
		case 1: message = "        Quan tri vien        ";
			break;
		case 2: message = "          Nhan vien          ";
			break;
		default:
			message = "            Thoat            ";
			break;
		}
		break;
	}
	case 2:
	{
		switch (choice)
		{
		case 1: message = "        Them Employee        ";
			break;
		case 2: message = "        Xoa Employee         ";
			break;
		case 3: message = "        Tim Employee         ";
			break;
		case 4: message = "      Cap nhat Employee      ";
			break;
		case 5: message = " Hien thi thong tin Employee ";
			break;
		default:
			message = "           Thoat             ";
			break;
		}
		break;
	}
	case 3:
	{
		switch (choice)
		{
		case 1: message = "       Cap nhat ho ten       ";
			break;
		case 2: message = "       Cap nhat dia chi      ";
			break;
		case 3: message = "    Cap nhat so dien thoai   ";
			break;
		case 4: message = "        Cap nhat email       ";
			break;
		default:
			message = "           Thoat             ";
			break;
		}
		break;
	}
	default:
		switch (choice)
		{
		case 1: message = "   Xem thong tin tai khoan   ";
			break;
		case 2: message = "         Doi mat khau        ";
			break;
		default:
			message = "           Thoat             ";
			break;
		}
		break;
	}
	cout << setw(22) << "*";
	if (choice == k) {
		SetColor(9, 0);
	}
	cout << setw(27) << message;
	SetColor(0, 11);
	cout << "*" << endl;
}

void showMainMenu(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 14);
	cout << setw(57) << right << "***************************************\n";
	cout << setw(18) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "            QUAN LY NHAN SU          "; SetColor(0, 14); cout << setw(0) << right << "*\n";
	cout << setw(58) << right << "***************************************\n\n";
	SetColor(0, 11);
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;

	for (int i = 1; i <= 3; i++) {
		titleSelection(i, k, 1);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}

//Admin Funtions

//Login

void showAdminLogin(string& _userName, string& _passWord, string message) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 12);
	cout << setw(63) << message << endl;
	SetColor(0, 10);
	cout << setw(49) << right << "************************\n";
	cout << setw(25) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "   DANG NHAP ADMIN    "; SetColor(0, 10); cout << setw(0) << right << "*\n";
	cout << setw(50) << right << "************************\n\n";

	SetColor(0, 3);
	string userName;
	cout << setw(33) << "User: ";
	SetColor(0, 7);
	cin >> userName;
	_userName = userName;
	SetColor(0, 3);
	string passWord;
	cout << setw(37) << "Password: ";
	SetColor(0, 7);

	string pass = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			pass += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	cout << endl;
	_passWord = pass;
}

void showMenuAdmin(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 10);
	cout << setw(54) << right << "*********************************\n";
	cout << setw(21) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "          MENU QUAN LY         "; SetColor(0, 10); cout << setw(0) << right << "*\n";
	cout << setw(55) << right << "*********************************\n\n";
	SetColor(0, 11);
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	for (int i = 1; i <= 6; i++) {
		titleSelection(i, k, 2);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 15);
}

bool checkAccountAdmin(string userName, string passWord, int nAD, Admin* admin) {
	for (int i = 0; i < nAD; i++) {
		if (admin[i].getUserName() == userName && admin[i].getPassWord() == passWord) {
			return true;
			break;
		}
	}
	return false;
}

// Add Employee Function

bool checkUserNameEmployee(User* user, string _User)
{
	ifstream fileIn("Employees.txt", ios::app);
	while (!fileIn.eof())
	{
		user = new Employee();
		user->readFile(fileIn);
		if (_User == user->getUserName())
			return false;
	}
	fileIn.close();
	return true;
}

void addEmployee(User* user)
{
	string _User, _Pass;
	user = new Employee();
	system("cls");
	SetColor(0, 10);
	cout << setw(55) << right << "**********************************\n";
	cout << setw(21) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "  NHAP THONG TIN CUA NHAN VIEN  "; SetColor(0, 10); cout << setw(0) << right << "*\n";
	cout << setw(56) << right << "**********************************\n\n";
	SetColor(0, 11);
	cout << " Nhap Username muon them: ";
	cin >> _User;
	if (!checkUserNameEmployee(user, _User))
	{
		SetColor(0, 14);
		cout << " Username da ton tai !" << "\n";
	}
	else
	{
		char* FilePath = new char[_User.length() + 1];//tạo một chuỗi kí tự mới
		strcpy(FilePath, _User.c_str());//coppy từ chuỗi nguồn sang chuỗi mới

		ofstream fileOut("Employees.txt", ios::app);
		Employee* Emp = new Employee();// new class employees		
		fileOut << _User << ", " << "111111" << endl;//xuất tên và pass trong file txt
		fileOut.close();
		Emp->createFile(fileOut, FilePath);//gọi tạo file
		Emp->input();//nhập thông tin
		fileOut << Emp->getName() << endl << Emp->getAddress() << endl << Emp->getPhone() << endl << Emp->getEmail();
		fileOut.close();
		SetColor(0, 14);
		cout << " Them thanh cong !" << endl;
	}
}

// Show Employees 

void showEmployees(User* user)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	user = new Employee();
	string strUser[100];
	int n = 0;
	system("cls");
	SetColor(0, 11);
	cout << setw(22) << "" << setfill('*') << setw(35) << "*" << setfill(' ') << endl;
	cout << setw(57) << "*                                 *" << endl;

	cout << setw(57) << "*       DANH SACH NHAN VIEN       *" << endl;

	cout << setw(57) << "*                                 *" << endl;
	cout << setw(22) << "" << setfill('*') << setw(35) << "*" << setfill(' ') << endl << endl;
	while (!fileIn.eof())
	{
		user->readFile(fileIn);
		strUser[n] = user->getUserName();
		n++;
	}
	fileIn.close();
	for (int i = 0; i < n; i++) {
		SetColor(0, 9);
		cout << "  Thong tin ";
		SetColor(0, 15);
		cout << strUser[i] << ": " << endl;
		string s = strUser[i];
		char* fileName = new char[s.length() + 1];
		strcpy(fileName, s.c_str());
		user->openFile(fileIn, fileName);
		user->readInfomation(fileIn);
		SetColor(0, 11);
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
		SetColor(0, 13);
		cout << setw(20) << left << " Ho va ten";
		cout << setw(17) << left << "Dia Chi";
		cout << setw(18) << left << "SDT";
		cout << setw(15) << left << "Email" << endl;
		SetColor(0, 11);
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
		SetColor(0, 15);
		cout << " " << setw(19) << left << user->getName();
		cout << setw(17) << left << user->getAddress();
		cout << setw(18) << left << user->getPhone();
		cout << setw(15) << left << user->getEmail() << endl;
		SetColor(0, 11);
		cout << setfill('-') << setw(79) << "-" << setfill(' ') << endl;
		fileIn.close();
	}
}

// Delete Employee 

void deleteEmployee(User* user, string s) {
	ifstream fileIn;
	fileIn.open("Employees.txt", ios_base::app);// mở file
	ofstream fileOut;
	fileOut.open("C:\\EmployeesCopy.txt", ios_base::out);
	int count = 0;
	while (!fileIn.eof())//đọc file
	{
		user = new Employee();
		user->readFile(fileIn);
		if (user->getUserName() != s)
		{
			fileOut << user->getUserName() << "," << user->getPassWord() << endl;
		}
		count++;
	}
	fileIn.close();
	fileOut.close();
	system("del Employees.txt");
	char* c = (char*)"Employees";
	user->createFile(fileOut, c);
	fileOut.close();
	fileIn.open("C:\\EmployeesCopy.txt", ios_base::in);
	fileOut.open("Employees.txt", ios_base::app);
	while (count > 1) {
		user = new Employee();
		user->readFile(fileIn);
		if (count == 2)
		{
			fileOut << user->getUserName() << "," << user->getPassWord();
			break;
		}
		fileOut << user->getUserName() << "," << user->getPassWord() << endl;
		count--;
	}
	fileIn.close();
	fileOut.close();
	user->deleteFile(s);//xóa employees
	SetColor(0, 14);
	cout << " Xoa thanh cong !" << endl;
	system("del C:\\EmployeesCopy.txt");

}

// Find Employee

void findEmployee(User* user, string userName)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	user = new Employee();
	if (!checkUserNameEmployee(user, userName))
	{
		ifstream f;
		char* fileName = new char[userName.length() + 1];
		strcpy(fileName, userName.c_str());
		user->openFile(f, fileName);
		user->readInfomation(f);//đọc file
		cout << " Thong tin Employee can tim: " << endl;
		cout << " Ho ten: " << user->getName() << endl;//getname
		cout << " Dia chi: " << user->getAddress() << endl;
		cout << " So dien thoai: " << user->getPhone() << endl;
		cout << " Dia chi Email: " << user->getEmail() << endl;
		f.close();
	}
	else {
		SetColor(0, 14);
		cout << "Username khong ton tai!" << endl;
	}
	fileIn.close();
}

// Update Employee

void menuUpdate(int k)
{
	system("cls");
	cout << "\n\n";
	SetColor(0, 10);
	cout << setw(54) << right << "*********************************\n";
	cout << setw(21) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "          MENU UPDATE          "; SetColor(0, 10); cout << setw(0) << right << "*\n";
	cout << setw(55) << right << "*********************************\n\n";
	SetColor(0, 11);
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	for (int i = 1; i <= 5; i++) {
		titleSelection(i, k, 3);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}

void updateName(User* user, string strUser)
{
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	cout << " Nhap ho ten can thay doi: ";
	cin.ignore();
	getline(cin, edit);
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("C:\\NoName.txt", ios_base::out);
	fileOut << edit << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("C:\\NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	cout << " Cap nhat ho ten Employee thanh cong !" << endl;
	user->deleteFile("NoName");
	exit();
}

void updateAddress(User* user, string strUser)
{
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	cout << " Nhap dia chi can thay doi: ";
	cin.ignore();
	getline(cin, edit);
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("C:\\NoName.txt", ios_base::out);
	fileOut << user->getName() << endl << edit << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("C:\\NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	cout << " Cap nhat dia chi Employee thanh cong !" << endl;
	user->deleteFile("NoName");
	exit();
}

void updatePhone(User* user, string strUser)
{
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	cout << " Nhap so dien thoai can thay doi: ";
	cin.ignore();
	getline(cin, edit);
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("C:\\NoName.txt", ios_base::out);
	fileOut << user->getName() << endl << user->getAddress() << endl << edit << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("C:\\NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	cout << " Cap nhat so dien thoai Employee thanh cong !" << endl;
	user->deleteFile("NoName");
	exit();
}

void updateEmail(User* user, string strUser)
{
	ifstream fileIn;
	ofstream fileOut;
	char* file = new char[strUser.length() + 1];
	strcpy(file, strUser.c_str());
	string edit;
	cout << " Nhap email can thay doi: ";
	cin.ignore();
	getline(cin, edit);
	user->openFile(fileIn, file);
	user->readInfomation(fileIn);
	fileOut.open("C:\\NoName.txt", ios_base::out);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << edit;
	fileIn.close();
	fileOut.close();
	user->deleteFile(strUser);//xóa tên cũ
	char* fileName = new char[strUser.length() + 1];
	strcpy(fileName, strUser.c_str());//copy chuỗi sang file name
	fileIn.open("C:\\NoName.txt", ios::in);
	user->readInfomation(fileIn);
	user->createFile(fileOut, fileName);
	fileOut << user->getName() << endl << user->getAddress() << endl << user->getPhone() << endl << user->getEmail();
	fileIn.close();
	fileOut.close();
	SetColor(0, 14);
	cout << " Cap nhat email Employee thanh cong !" << endl;
	user->deleteFile("NoName");
	exit();
}

// Employee Funtions

void showEmployeeLogin(string& _userName, string& _passWord, string message) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 12);
	cout << setw(63) << message << endl;
	SetColor(0, 13);
	cout << setw(49) << right << "************************\n";
	cout << setw(25) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "  DANG NHAP EMPLOYEE  "; SetColor(0, 13); cout << setw(0) << right << "*\n";
	cout << setw(50) << right << "************************\n\n";

	SetColor(0, 3);
	string userName;
	cout << setw(33) << "User: ";
	SetColor(0, 7);
	cin >> userName;
	_userName = userName;
	SetColor(0, 3);
	string passWord;
	cout << setw(37) << "Password: ";
	SetColor(0, 7);

	string pass = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			pass += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	cout << endl;
	_passWord = pass;
}

bool checkAccountEmployee(User* user, string userName, string passWord, string& saveUsername) {
	ifstream fileIn("Employees.txt", ios_base::app);
	user->readFile(fileIn);
	if (user->getUserName() + user->getPassWord() == userName + " " + passWord) {
		saveUsername = userName;
		return true;
	}
	fileIn.close();
	return false;
}

void showMenuEmployee(int k) {
	system("cls");
	cout << "\n\n";
	SetColor(0, 13);
	cout << setw(54) << right << "*********************************\n";
	cout << setw(21) << right << "*"; SetColor(0, 15); cout << setw(0) << right << "         MENU NHAN VIEN        "; SetColor(0, 13); cout << setw(0) << right << "*\n";
	cout << setw(55) << right << "*********************************\n\n";
	SetColor(0, 11);
	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	for (int i = 1; i <= 3; i++) {
		titleSelection(i, k, 4);
	}

	cout << setw(21) << "" << setfill('*') << setw(31) << "*" << setfill(' ') << endl;
	cout << "\n\n\n";
	SetColor(0, 11);
}

// Show Employee Information

void showEmployeeInfo(User* user, string userName)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	user = new Employee();
	ifstream f;
	char* fileName = new char[userName.length() + 1];
	strcpy(fileName, userName.c_str());
	user->openFile(f, fileName);
	user->readInfomation(f);//đọc file
	cout << " Thong tin Employee: " << endl;
	cout << " Ho ten: " << user->getName() << endl;
	cout << " Dia chi: " << user->getAddress() << endl;
	cout << " So dien thoai: " << user->getPhone() << endl;
	cout << " Dia chi Email: " << user->getEmail() << endl;
	f.close();
	fileIn.close();
}

// Change Password

void changePass(User* user, string currentPass, string newPass, string userName)
{
	ifstream fileIn;
	ofstream fileOut;
	string s = "NoName";
	char* fileName = new char[s.length() + 1];//tạo chuỗi mới
	strcpy(fileName, s.c_str());//copy chuỗi
	user->createFile(fileOut, fileName);
	fileIn.open("Employees.txt", ios_base::in);//mở file
	int count = 0;
	while (!fileIn.eof())
	{
		user->readFile(fileIn);
		count++;
	}
	fileIn.close();
	int tmp = count;
	fileIn.open("Employees.txt", ios_base::in);
	while (count > 0)
	{
		user->readFile(fileIn);
		if (count == 1)
		{
			fileOut << user->getUserName() << "," << user->getPassWord();
			break;
		}
		fileOut << user->getUserName() << "," << user->getPassWord() << endl;
		count--;
	}
	fileIn.close();
	fileOut.close();
	user->deleteFile("Employees");
	string s2 = "NoName";
	char* fileName2 = new char[s2.length() + 1];
	strcpy(fileName2, s2.c_str());
	user->openFile(fileIn, fileName2);
	fileOut.open("Employees.txt", ios_base::out);
	while (tmp > 0)
	{
		user->readFile(fileIn);
		if (userName == user->getUserName() && " " + currentPass == user->getPassWord() && tmp == 1)
		{
			fileOut << user->getUserName() << ", " << newPass;
			break;
		}
		else if (userName == user->getUserName() && " " + currentPass == user->getPassWord())
		{
			fileOut << user->getUserName() << ", " << newPass << endl;
		}
		else
		{
			if (tmp == 1)
			{
				fileOut << user->getUserName() << "," << user->getPassWord();
				break;
			}
			else if (tmp != 1)
			{
				fileOut << user->getUserName() << "," << user->getPassWord() << endl;
			}
			else
			{
				break;
			}
		}
		tmp--;
	}
	SetColor(0, 14);
	cout << "\n Doi mat khau thanh cong !\n";
	fileIn.close();
	fileOut.close();
	user->deleteFile("NoName");
}

void menuChangePass(User* user, string userName)
{
	ifstream fileIn("Employees.txt", ios_base::app);
	ofstream fileOut;
	int size = 0;
	SetColor(0, 9);
	cout << "             KHONG SU DUNG MAT KHAU MAC DINH : 111111 " << endl << endl;
	SetColor(0, 11);
	cout << " Nhap password hien tai: ";
	string currentPass;
	string passC = "\0";
	char kytuC = 0;
	int iC = 0;
	while (kytuC != '\r') {
		kytuC = _getch();
		if ((kytuC >= 'a' && kytuC <= 'z') || (kytuC >= 'A' && kytuC <= 'Z') || (kytuC >= '0' && kytuC <= '9')) {
			passC += kytuC;
			iC++;
			cout << "*";
		}
		if (kytuC == '\b' && iC >= 1) {
			cout << "\b \b";
			iC--;
		}
	}
	currentPass = passC;

	cout << endl << " Nhap password moi: ";
	string newPass;
	string passN = "\0";
	char kytuN = 0;
	int iN = 0;
	while (kytuN != '\r') {
		kytuN = _getch();
		if ((kytuN >= 'a' && kytuN <= 'z') || (kytuN >= 'A' && kytuN <= 'Z') || (kytuN >= '0' && kytuN <= '9')) {
			passN += kytuN;
			iN++;
			cout << "*";
		}
		if (kytuN == '\b' && iN >= 1) {
			cout << "\b \b";
			iN--;
		}
	}
	newPass = passN;

	cout << endl << " Nhap lai password moi: ";
	string confirmPass;
	string passP = "\0";
	char kytu = 0;
	int i = 0;
	while (kytu != '\r') {
		kytu = _getch();
		if ((kytu >= 'a' && kytu <= 'z') || (kytu >= 'A' && kytu <= 'Z') || (kytu >= '0' && kytu <= '9')) {
			passP += kytu;
			i++;
			cout << "*";
		}
		if (kytu == '\b' && i >= 1) {
			cout << "\b \b";
			i--;
		}
	}
	confirmPass = passP;
	cout << endl;
	bool check = false;
	bool checkN = false;
	bool checkP = false;
	while (!fileIn.eof())
	{
		user = new Employee();
		user->readFile(fileIn);
		if (" " + (string)currentPass == user->getPassWord())
		{
			check = true;
			break;
		}
		if (" " + (string)newPass != "111111")
		{
			checkN = true;
			break;
		}
		if (" " + (string)newPass == (string)confirmPass)
		{
			checkP = true;
			break;
		}
	}

	if (check == false)
	{
		SetColor(0, 14);
		cout << "\n Mat khau ban nhap khong chinh xac, ban vui long kiem tra lai !" << endl;
	}
	else if (checkN = false)
	{
		SetColor(0, 14);
		cout << "\n Mat khau trung voi mat khau mat dinh, ban vui long kiem tra lai !" << endl;
	}
	else if (checkP = false)
	{
		SetColor(0, 14);
		cout << "\n Mat khau xac nhan khong chinh xac, ban vui long kiem tra lai !" << endl;
	}
	else
	{
		changePass(user, currentPass, newPass, userName);
	}
	fileIn.close();
}

#pragma once
