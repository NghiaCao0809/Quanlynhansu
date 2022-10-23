#pragma once
#pragma once
#include"User.h"

class Admin : public User
{
public:

	//khởi tạo
	bool operator ==(Admin a) {
		return a.getUserName() + a.getPassWord() == getUserName() + getPassWord();
	}
	Admin(string _userName = "", string _Password = "111111", string _Name = "", string _Address = "", string _Phone = "", string _Email = "")
		:User(_userName, _Password, _Name, _Address, _Phone, _Password) {}

	//đọc file
	void docFile(int& nAD, ifstream& fi) {
		string user;
		getline(fi, user);
		if (user == "") {
			return;
		}
		else {
			this->userName = catChuoi(user, 6);
			string pass;
			getline(fi, pass);
			this->passWord = catChuoi(pass, 10);
			string key;
			getline(fi, key);
			if (key == "") nAD++;
		}
	}
};
