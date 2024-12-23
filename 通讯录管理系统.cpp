#include <iostream>
#include <string>
using namespace std;

#define MAX 1000//宏常量，方便以后修改；

struct Person//联系人结构体；
{
	string m_Name;//姓名
	int m_Sex;//性别，1-男，2-女
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//住址
};

struct Addressbooks//通讯录结构体；
{
	struct Person PersonArray[MAX];//联系人数组；
	int m_Size;//记录联系人个数；
};

void showMenu();//封装一个函数显示该界面
void addPerson(struct Addressbooks *p);//添加联系人//用指针接收地址；
void showPerson(struct Addressbooks *p);//显示联系人：
int isExist(struct Addressbooks *p, string name);//检测联系人是否存在
void deletePerson(struct Addressbooks *p);////删除联系人
void findPerson(struct Addressbooks *p);//查找联系人
void modifyPerson(struct Addressbooks *p);//修改联系人
void cleanPerson(struct Addressbooks *p);//清空联系人
#include"通讯录管理系统.h"

void showMenu()//封装一个函数显示该界面
{
	cout << "***************************" << endl;
	cout << "*****  1，添加联系人  *****" << endl;
	cout << "*****  2，显示联系人  *****" << endl;
	cout << "*****  3，删除联系人  *****" << endl;
	cout << "*****  4，查找联系人  *****" << endl;
	cout << "*****  5，修改联系人  *****" << endl;
	cout << "*****  6，清空联系人  *****" << endl;
	cout << "*****  0，退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

//添加联系人：
void addPerson(struct Addressbooks *p)//用指针接收地址；
{
	if (p->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;//退出函数；
	}
	else
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		p->PersonArray[p->m_Size].m_Name = name;//把用户输入的值赋给通讯录；p->m_Size为人数，就是当前是第几个人；

		cout << "请输入性别：" << endl;
		cout << "输入1代表男，输入2代表女。" << endl;
		int sex = 0;
		while (true)//无限循环，直到输入正确再退出；
		{
			cin >> sex;
			if (sex == 1 || sex == 2)//有效输入；
			{
				p->PersonArray[p->m_Size].m_Sex = sex;
				break;//如果输入有效，就退出循环；
			}
			else//这里也可以不加else，因为如果输入有效，代码走到上面if中的break就退出循环了，不会走到这里；
			{
				cin.clear();
				cin.ignore();//输入字母或中文里防止死循环；
				cout << "输入有误，请重新输入：" << endl;
			}

		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)//无限循环，直到输入正确再退出；
		{
			cin >> age;
			if (age > 0 && age < 120)
			{
				p->PersonArray[p->m_Size].m_Age = age;
				break;
			}
			else
			{
				cin.clear();
				cin.ignore();//输入字母或中文里防止死循环；
				cout << "输入有误，请重新输入：" << endl;
			}
		}

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		p->PersonArray[p->m_Size].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		p->PersonArray[p->m_Size].m_Addr = address;

		p->m_Size++;//每添加一个人，人数就加1；
		cout << endl;
		cout << "添加成功。" << endl;//每添加一个人，就提示添加成功；

		system("pause");//按任意键继续；
		system("cls");//清屏；
	}
}

//显示联系人：
void showPerson(struct Addressbooks *p)
{
	if (p->m_Size == 0)
	{
		cout << "当前记录为空。" << endl;
	}
	else
	{
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << "姓名：" << p->PersonArray[i].m_Name << "\t";
			cout << "性别：" << (p->PersonArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << p->PersonArray[i].m_Age << "\t";
			cout << "电话：" << p->PersonArray[i].m_Phone << "\t";
			cout << "地址：" << p->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");//按任意键继续；
	system("cls");//清屏；
}


//检测联系人是否存在，如果存在，返回下标编号，如果不存在返回-1；
int isExist(struct Addressbooks *p, string name)//传通讯录和对比的名字进来，两个名字要作对比；
{
	for (int i = 0; i < p->m_Size; i++)
	{
		if (p->PersonArray[i].m_Name == name)//找到用户输入的姓名了；
			return i;//返回这个人在数组中的下标编号；
	}
	return -1;//如果遍历所有人都没找到用户输入的姓名；
}

//删除联系人
void deletePerson(struct Addressbooks *p)
{
	cout << "请输入要删除的联系人姓名：" << endl;
	string inputname;
	cin >> inputname;
	int Exist = isExist(p, inputname);
	if (Exist != -1)//查到了人，要进行删除；
	{
		cout << "您确定要删除此联系人吗？" << endl;
		cout << "确认删除请按1，否则请按0" << endl;
		bool index = 0;
		cin >> index;
		if (index == 1)
		{
			for (int i = Exist; i < p->m_Size; i++)
			{
				p->PersonArray[i] = p->PersonArray[i + 1];//数据前移，执行删除；
			}
			p->m_Size--;//人数减一；
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "没有联系人被删除" << endl;
			//return;
		}
	}
	else//找不到输入的联系人；
		cout << "查无此人" << endl;

	system("pause");//按任意键继续；
	system("cls");//清屏；
}


//查找联系人
void findPerson(struct Addressbooks *p)
{
	cout << "请输入要查找的联系人姓名：" << endl;
	string inputname;
	cin >> inputname;
	int Exist = isExist(p, inputname);
	if (Exist != -1)//查到了人；
	{
		cout << "姓名：" << p->PersonArray[Exist].m_Name << "\t";
		cout << "性别：" << (p->PersonArray[Exist].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << p->PersonArray[Exist].m_Age << "\t";
		cout << "电话：" << p->PersonArray[Exist].m_Phone << "\t";
		cout << "地址：" << p->PersonArray[Exist].m_Addr << endl;
	}
	else//找不到输入的联系人；
		cout << "查无此人" << endl;

	system("pause");//按任意键继续；
	system("cls");//清屏；
}

//修改联系人
void modifyPerson(struct Addressbooks *p)
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string inputname;
	cin >> inputname;
	int Exist = isExist(p, inputname);
	if (Exist != -1)//查到了人；
	{
		cout << "1：修改姓名" << endl;
		cout << "2：修改性别" << endl;
		cout << "3：修改年龄" << endl;
		cout << "4：修改电话" << endl;
		cout << "5：修改地址" << endl;
		cout << "0：保存退出" << endl;
		while (true)
		{
			int modifyselect = -1;
			cout << "请输入您的选择：" << endl;
			cin >> modifyselect;
			switch (modifyselect)
			{
			case 1:
			{
				string newname;
				cout << "请输入修改后的姓名：" << endl;
				cin >> newname;
				p->PersonArray[Exist].m_Name = newname;//改姓名；
			}
			break;

			case 2:
			{
				cout << "请输入修改后的性别：" << endl;
				cout << "输入1代表男，输入2代表女。" << endl;
				int newsex = 0;
				while (true)
				{
					cin >> newsex;
					if (newsex == 1 || newsex == 2)
					{
						p->PersonArray[Exist].m_Sex = newsex;//改性别；
						break;//如果输入有效，就退出循环；
					}
					else
					{
						cin.clear();
						cin.ignore();//输入字母或中文里防止死循环；
						cout << "输入有误，请重新输入：" << endl;
					}
				}
			}
			break;

			case 3:
			{
				cout << "请输入修改后的年龄：" << endl;
				int newage = 0;
				while (true)//无限循环，直到输入正确再退出；
				{
					cin >> newage;
					if (newage > 0 && newage < 120)
					{
						p->PersonArray[Exist].m_Age = newage;//改年龄；
						break;
					}
					else
					{
						cin.clear();
						cin.ignore();//输入字母或中文里防止死循环；
						cout << "输入有误，请重新输入：" << endl;
					}
				}
			}
			break;

			case 4:
			{
				cout << "请输入修改后的电话：" << endl;
				string newphone;
				cin >> newphone;
				p->PersonArray[Exist].m_Phone = newphone;//改电话；
			}
			break;

			case 5:
			{
				cout << "请输入修改后的地址：" << endl;
				string newaddress;
				cin >> newaddress;
				p->PersonArray[Exist].m_Addr = newaddress;//改地址；
			}
			break;

			case 0:
				cout << "修改成功" << endl;
				system("pause");
				system("cls");//清屏；
				return;
				break;

			default:
				break;
			}
		}
	}
	else//找不到输入的联系人；
		cout << "查无此人" << endl;

	system("pause");//按任意键继续；
	system("cls");//清屏；
}


//清空联系人
void cleanPerson(struct Addressbooks *p)
{
	cout << "您确定要清空联系人吗？" << endl;
	cout << "确认清空请按1，否则请按0" << endl;
	bool cleanindex = 0;
	cin >> cleanindex;
	if (cleanindex == 1)
	{
		p->m_Size = 0;//把人数设置为0，等效于清空了；
		cout << "通讯录已清空" << endl;
	}
	else
	{
		cout << "通讯录没有被清空" << endl;
	}

	system("pause");//按任意键继续；
	system("cls");//清屏；
}

