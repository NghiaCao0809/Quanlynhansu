#pragma once
#pragma once
#include"User.h"

class Employee : public User
{
public:
	bool operator ==(Employee a) {
		return a.getUserName() + a.getPassWord() == getUserName() + getPassWord();
	}
	Employee(string _userName = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = "")
		:User(_userName, _Password, _Name, _Address, _Phone, _Email) {}

	//đọc file
	void docFile(int& nEP, ifstream& fi) {
		string user;
		getline(fi, user);
		if (user == "") {
			return;
		}
		else {
			this->userName = user;
			string pass;
			getline(fi, pass);
			this->passWord = pass;
			string key;
			getline(fi, key);
			if (key == "") nEP++;
		}
	}

	//tạo file
	void createFile(ofstream& FileOut, char* FileName) {
		User::createFile(FileOut, FileName);
	}

	//nhập thông tin
	void input() {
		User::input();
	}
};