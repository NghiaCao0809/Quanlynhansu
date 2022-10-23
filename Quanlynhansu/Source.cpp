#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

void SetColor(int backgound_color, int text_color)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(color, color_code);
}

string catChuoi(string s, int vitri) {
	return s.substr(vitri, s.length() - vitri);
}

#include"Admin.h"
#include"Employee.h"
#include"Suport.h" 
#include"User.h"

int main()
{
	char clickMainMenu = 0;
	int cMM = 1;
	showMainMenu(cMM);
	User user[100];
	ifstream FileIn;
	ofstream FileOut;
	while (clickMainMenu != 27)
	{
		clickMainMenu = _getch();
		if (clickMainMenu != -32)
		{
			showMainMenu(cMM);
			//Switch Main Menu
			switch (clickMainMenu)
			{
				//Key Down
			case 80:
				cMM++;
				if (cMM == 4) {
					cMM = 1;
				}
				showMainMenu(cMM);
				break;
				//Key Up
			case 72:
				cMM--;
				if (cMM == 0) {
					cMM = 3;
				}
				showMainMenu(cMM);
				break;
				//Key Enter
			case 13:
				//Switch choice Of Main Menu
				switch (cMM)
				{
				case 1:
				{
					Admin admin[100];
					int nAD = 0;
					getDS<Admin>(nAD, admin, "Admins.txt");
					string userName = "", passWord = "", message = "";
					for (int i = 3; i >= 0; i--) {
						showAdminLogin(userName, passWord, message);
						if (checkAccountAdmin(userName, passWord, nAD, admin))
						{
							char choiceMA = 0;
							int kMA = 1;
							showMenuAdmin(kMA);
							while (choiceMA != 27)
							{
								choiceMA = _getch();
								if (choiceMA != -32) {
									showMenuAdmin(kMA);
									//Switch Menu Admin
									switch (choiceMA)
									{
										//Key Down
									case 80:
										kMA++;
										if (kMA == 7) {
											kMA = 1;
										}
										showMenuAdmin(kMA);
										break;
										//Key Up
									case 72:
										kMA--;
										if (kMA == 0) {
											kMA = 6;
										}
										showMenuAdmin(kMA);
										break;
										//Key Enter
									case 13:
										switch (kMA)
										{
										case 1:
										{
											addEmployee(user);
											exit();
											showMenuAdmin(kMA);
											break;
										}
										case 2:
										{
											system("cls");
											SetColor(0, 11);
											string _user;
											cout << " Nhap Username muon xoa: ";
											cin >> _user;
											if (checkUserNameEmployee(user, _user))
											{
												cout << " Khong tim thay " << _user << " de xoa!" << endl;
											}
											else
											{
												deleteEmployee(user, _user);
											}
											exit();
											break;
											showMenuAdmin(kMA);
										}
										case 3:
										{
											system("cls");
											string userName;
											cout << "Moi ban nhap Username can tim: ";
											cin >> userName;
											findEmployee(user, userName);
											exit();
											break;
											showMenuAdmin(kMA);
										}
										case 4:
										{
											system("cls");
											string userName;
											cout << endl << endl << "Nhap Username muon thay doi thong tin: ";
											cin >> userName;
											if (!checkUserNameEmployee(user, userName))
											{
												char choiceUP = 0;
												int kUP = 1;
												menuUpdate(kUP);
												while (choiceUP != 27)
												{
													choiceUP = _getch();
													if (choiceUP != -32)
													{
														menuUpdate(kUP);
														switch (choiceUP)
														{
														case 80:
															kUP++;
															if (kUP == 6) {
																kUP = 1;
															}
															menuUpdate(kUP);
															break;
															//Key Up
														case 72:
															kUP--;
															if (kUP == 0) {
																kUP = 5;
															}
															menuUpdate(kUP);
															break;
															//Key Enter
														case 13:
															switch (kUP)
															{
															case 1:
															{
																system("cls");
																updateName(user, userName);
																menuUpdate(kUP);
																break;
															}
															case 2:
															{
																system("cls");
																updateAddress(user, userName);
																menuUpdate(kUP);
																break;
															}
															case 3:
															{
																system("cls");
																updatePhone(user, userName);
																menuUpdate(kUP);
																break;
															}
															case 4:
															{
																system("cls");
																updateEmail(user, userName);
																menuUpdate(kUP);
																break;
															}
															default:
																choiceUP = 27;
																menuUpdate(kUP);
																break;
															}
															break;
														default:
															break;
														}
													}
												}
											}
											else {
												cout << "Username khong ton tai" << endl;
												exit();
											}
											break;
											showMenuAdmin(kMA);
										}
										case 5:
										{
											showEmployees(user);
											exit();
											break;
											showMenuAdmin(kMA);
										}
										default:
											choiceMA = 27;
											showMainMenu(cMM);
											break;
										}

									default:
										showMainMenu(cMM);
										break;
									}
									//End Switch Menu Admin
								}
							}
							break;
						}
						else {
							if (i > 1) {
								message = "Sai ten dang nhap hoac mat khau!. Nhap sai qua 3 lan thi se quay lai man hinh chinh ";
							}
							else {
								break;
							}
						}
					}
					showMainMenu(cMM);
					break;
				}
				case 2:
				{
					Employee employee[100];
					string userName = "", passWord = "", message = "";
					string saveUsername = "";
					for (int i = 3; i >= 0; i--)
					{
						showEmployeeLogin(userName, passWord, message);
						if (checkAccountEmployee(employee, userName, passWord, saveUsername))
						{
							char choiceEP = 0;
							int kEP = 1;
							showMenuEmployee(kEP);
							while (choiceEP != 27)
							{
								choiceEP = _getch();
								if (choiceEP != -32) {
									showMenuEmployee(kEP);
									switch (choiceEP)
									{
										//Key Down
									case 80:
										kEP++;
										if (kEP == 4) {
											kEP = 1;
										}
										showMenuEmployee(kEP);
										break;
										//Key Up
									case 72:
										kEP--;
										if (kEP == 0) {
											kEP = 3;
										}
										showMenuEmployee(kEP);
										break;
										//Key Enter
									case 13:
										switch (kEP)
										{
										case 1:
										{
											system("cls");
											showEmployeeInfo(user, saveUsername);
											exit();
											break;
											showMenuEmployee(kEP);
										}
										case 2:
										{
											system("cls");
											menuChangePass(user, saveUsername);
											exit();
											break;
											showMenuEmployee(kEP);
										}
										default:
											choiceEP = 27;
											break;
											showMainMenu(cMM);
										}
									default:
										showMainMenu(cMM);
										break;
									}
								}
							}

						}
						else
						{
							if (i > 1) {
								message = "Sai ten dang nhap hoac mat khau!. Nhap sai qua 3 lan thi se quay lai man hinh chinh ";
							}
							else {
								break;
							}
						}
					}
					showMainMenu(cMM);
					break;
				}
				default:
					exit(0);
					break;
				}//End Switch Main Menu
			}
		}
	}
}
