#include <iostream>
#include <string>
using namespace std;

#define MAX 1000//�곣���������Ժ��޸ģ�

struct Person//��ϵ�˽ṹ�壻
{
	string m_Name;//����
	int m_Sex;//�Ա�1-�У�2-Ů
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//סַ
};

struct Addressbooks//ͨѶ¼�ṹ�壻
{
	struct Person PersonArray[MAX];//��ϵ�����飻
	int m_Size;//��¼��ϵ�˸�����
};

void showMenu();//��װһ��������ʾ�ý���
void addPerson(struct Addressbooks *p);//�����ϵ��//��ָ����յ�ַ��
void showPerson(struct Addressbooks *p);//��ʾ��ϵ�ˣ�
int isExist(struct Addressbooks *p, string name);//�����ϵ���Ƿ����
void deletePerson(struct Addressbooks *p);////ɾ����ϵ��
void findPerson(struct Addressbooks *p);//������ϵ��
void modifyPerson(struct Addressbooks *p);//�޸���ϵ��
void cleanPerson(struct Addressbooks *p);//�����ϵ��
#include"ͨѶ¼����ϵͳ.h"

void showMenu()//��װһ��������ʾ�ý���
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

//�����ϵ�ˣ�
void addPerson(struct Addressbooks *p)//��ָ����յ�ַ��
{
	if (p->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;//�˳�������
	}
	else
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		p->PersonArray[p->m_Size].m_Name = name;//���û������ֵ����ͨѶ¼��p->m_SizeΪ���������ǵ�ǰ�ǵڼ����ˣ�

		cout << "�������Ա�" << endl;
		cout << "����1�����У�����2����Ů��" << endl;
		int sex = 0;
		while (true)//����ѭ����ֱ��������ȷ���˳���
		{
			cin >> sex;
			if (sex == 1 || sex == 2)//��Ч���룻
			{
				p->PersonArray[p->m_Size].m_Sex = sex;
				break;//���������Ч�����˳�ѭ����
			}
			else//����Ҳ���Բ���else����Ϊ���������Ч�������ߵ�����if�е�break���˳�ѭ���ˣ������ߵ����
			{
				cin.clear();
				cin.ignore();//������ĸ���������ֹ��ѭ����
				cout << "�����������������룺" << endl;
			}

		}

		cout << "���������䣺" << endl;
		int age = 0;
		while (true)//����ѭ����ֱ��������ȷ���˳���
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
				cin.ignore();//������ĸ���������ֹ��ѭ����
				cout << "�����������������룺" << endl;
			}
		}

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		p->PersonArray[p->m_Size].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		p->PersonArray[p->m_Size].m_Addr = address;

		p->m_Size++;//ÿ���һ���ˣ������ͼ�1��
		cout << endl;
		cout << "��ӳɹ���" << endl;//ÿ���һ���ˣ�����ʾ��ӳɹ���

		system("pause");//�������������
		system("cls");//������
	}
}

//��ʾ��ϵ�ˣ�
void showPerson(struct Addressbooks *p)
{
	if (p->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ�ա�" << endl;
	}
	else
	{
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << "������" << p->PersonArray[i].m_Name << "\t";
			cout << "�Ա�" << (p->PersonArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << p->PersonArray[i].m_Age << "\t";
			cout << "�绰��" << p->PersonArray[i].m_Phone << "\t";
			cout << "��ַ��" << p->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");//�������������
	system("cls");//������
}


//�����ϵ���Ƿ���ڣ�������ڣ������±��ţ���������ڷ���-1��
int isExist(struct Addressbooks *p, string name)//��ͨѶ¼�ͶԱȵ����ֽ�������������Ҫ���Աȣ�
{
	for (int i = 0; i < p->m_Size; i++)
	{
		if (p->PersonArray[i].m_Name == name)//�ҵ��û�����������ˣ�
			return i;//����������������е��±��ţ�
	}
	return -1;//������������˶�û�ҵ��û������������
}

//ɾ����ϵ��
void deletePerson(struct Addressbooks *p)
{
	cout << "������Ҫɾ������ϵ��������" << endl;
	string inputname;
	cin >> inputname;
	int Exist = isExist(p, inputname);
	if (Exist != -1)//�鵽���ˣ�Ҫ����ɾ����
	{
		cout << "��ȷ��Ҫɾ������ϵ����" << endl;
		cout << "ȷ��ɾ���밴1�������밴0" << endl;
		bool index = 0;
		cin >> index;
		if (index == 1)
		{
			for (int i = Exist; i < p->m_Size; i++)
			{
				p->PersonArray[i] = p->PersonArray[i + 1];//����ǰ�ƣ�ִ��ɾ����
			}
			p->m_Size--;//������һ��
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "û����ϵ�˱�ɾ��" << endl;
			//return;
		}
	}
	else//�Ҳ����������ϵ�ˣ�
		cout << "���޴���" << endl;

	system("pause");//�������������
	system("cls");//������
}


//������ϵ��
void findPerson(struct Addressbooks *p)
{
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string inputname;
	cin >> inputname;
	int Exist = isExist(p, inputname);
	if (Exist != -1)//�鵽���ˣ�
	{
		cout << "������" << p->PersonArray[Exist].m_Name << "\t";
		cout << "�Ա�" << (p->PersonArray[Exist].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << p->PersonArray[Exist].m_Age << "\t";
		cout << "�绰��" << p->PersonArray[Exist].m_Phone << "\t";
		cout << "��ַ��" << p->PersonArray[Exist].m_Addr << endl;
	}
	else//�Ҳ����������ϵ�ˣ�
		cout << "���޴���" << endl;

	system("pause");//�������������
	system("cls");//������
}

//�޸���ϵ��
void modifyPerson(struct Addressbooks *p)
{
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string inputname;
	cin >> inputname;
	int Exist = isExist(p, inputname);
	if (Exist != -1)//�鵽���ˣ�
	{
		cout << "1���޸�����" << endl;
		cout << "2���޸��Ա�" << endl;
		cout << "3���޸�����" << endl;
		cout << "4���޸ĵ绰" << endl;
		cout << "5���޸ĵ�ַ" << endl;
		cout << "0�������˳�" << endl;
		while (true)
		{
			int modifyselect = -1;
			cout << "����������ѡ��" << endl;
			cin >> modifyselect;
			switch (modifyselect)
			{
			case 1:
			{
				string newname;
				cout << "�������޸ĺ��������" << endl;
				cin >> newname;
				p->PersonArray[Exist].m_Name = newname;//��������
			}
			break;

			case 2:
			{
				cout << "�������޸ĺ���Ա�" << endl;
				cout << "����1�����У�����2����Ů��" << endl;
				int newsex = 0;
				while (true)
				{
					cin >> newsex;
					if (newsex == 1 || newsex == 2)
					{
						p->PersonArray[Exist].m_Sex = newsex;//���Ա�
						break;//���������Ч�����˳�ѭ����
					}
					else
					{
						cin.clear();
						cin.ignore();//������ĸ���������ֹ��ѭ����
						cout << "�����������������룺" << endl;
					}
				}
			}
			break;

			case 3:
			{
				cout << "�������޸ĺ�����䣺" << endl;
				int newage = 0;
				while (true)//����ѭ����ֱ��������ȷ���˳���
				{
					cin >> newage;
					if (newage > 0 && newage < 120)
					{
						p->PersonArray[Exist].m_Age = newage;//�����䣻
						break;
					}
					else
					{
						cin.clear();
						cin.ignore();//������ĸ���������ֹ��ѭ����
						cout << "�����������������룺" << endl;
					}
				}
			}
			break;

			case 4:
			{
				cout << "�������޸ĺ�ĵ绰��" << endl;
				string newphone;
				cin >> newphone;
				p->PersonArray[Exist].m_Phone = newphone;//�ĵ绰��
			}
			break;

			case 5:
			{
				cout << "�������޸ĺ�ĵ�ַ��" << endl;
				string newaddress;
				cin >> newaddress;
				p->PersonArray[Exist].m_Addr = newaddress;//�ĵ�ַ��
			}
			break;

			case 0:
				cout << "�޸ĳɹ�" << endl;
				system("pause");
				system("cls");//������
				return;
				break;

			default:
				break;
			}
		}
	}
	else//�Ҳ����������ϵ�ˣ�
		cout << "���޴���" << endl;

	system("pause");//�������������
	system("cls");//������
}


//�����ϵ��
void cleanPerson(struct Addressbooks *p)
{
	cout << "��ȷ��Ҫ�����ϵ����" << endl;
	cout << "ȷ������밴1�������밴0" << endl;
	bool cleanindex = 0;
	cin >> cleanindex;
	if (cleanindex == 1)
	{
		p->m_Size = 0;//����������Ϊ0����Ч������ˣ�
		cout << "ͨѶ¼�����" << endl;
	}
	else
	{
		cout << "ͨѶ¼û�б����" << endl;
	}

	system("pause");//�������������
	system("cls");//������
}

