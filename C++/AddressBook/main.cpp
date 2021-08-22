#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 1000

struct Person
{
	string name;  	 //����
	int sex;   	 //�Ա�
	int age;	  	 //����
	string phone;	 //�绰
	string address;  //��ַ
};

struct AddressBook
{
	Person personArray[MAX];
	int size;
};

void showMenu()
{
	cout << endl;
	cout << "-----------�����˵���-----------" << endl;
	cout << "---------1.�����ϵ��:----------" << endl;
	cout << "---------2.��ʾ��ϵ�ˣ�---------" << endl;
	cout << "---------3.ɾ����ϵ�ˣ�---------" << endl;
	cout << "---------4.������ϵ�ˣ�---------" << endl;
	cout << "---------5.�޸���ϵ�ˣ�---------" << endl;
	cout << "---------6.�����ϵ�ˣ�---------" << endl;
	cout << "---------0.�˳�ͨѶ¼��---------" << endl;
}

//�����ϵ��
void addPerson(struct AddressBook* abs)
{
	if( abs->size == MAX)
	{
		cout << "��ϵ������" << endl;
	}
	else
	{
		string name;
		cout << "������" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;

		while(true)
		{
			int sex = 0;
			cout << "�Ա�(1--��  2--Ů)" << endl;
			cin >> sex;
			if(sex == 1|| sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}

		int age = 0;
		cout << "���䣺" << endl;
		cin >> age;
		abs->personArray[abs->size].age = age;

		string phone;
		cout << "�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		string address;
		cout << "��ַ��" << endl;
		cin >> address;
		abs->personArray[abs->size].address = address;

		abs->size++;
		cout << "��ӳɹ�" << endl;
	}
	
	system("pause");
	system("cls");
}


//��ʾ��ϵ��
void showPerson(struct AddressBook* abs)
{
	if(abs->size == 0)
	{
		cout << "��ϵ��Ϊ��" << endl;
	}
	else
	{
		for(int i=0; i<abs->size; i++)
		{
			cout << "������" << abs->personArray[i].name << "\t";
			cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].age << "\t";
			cout << "�绰��" << abs->personArray[i].phone << "\t";
			cout << "��ַ��" << abs->personArray[i].address << endl;
		}
	}

	system("pause");
	system("cls");
}


//�����ϵ���Ƿ����
int isExist(struct AddressBook* abs, string name)
{
	if(abs->size != 0)
	{
		for(int i=0; i<abs->size; i++)
		{
			if(abs->personArray[i].name == name)
			{
				return i;
			}
		}
	}

	return -1;

}

//ɾ����ϵ��
void deletePerson(struct AddressBook* abs, string name)
{
	int index = isExist(abs,name);
	if(index != -1)
	{
		for(int i=index; i<abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i+1];
		}
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}


//������ϵ��
void findPerson(struct AddressBook* abs, string name)
{
	int index = isExist(abs,name);
	if(index != -1)
	{	
		cout << "������" << abs->personArray[index].name << "\t";
		cout << "�Ա�" << (abs->personArray[index].sex == 1 ? "��":"Ů") << "\t";
		cout << "���䣺" << abs->personArray[index].age << "\t";
		cout << "�绰��" << abs->personArray[index].phone << "\t";
		cout << "��ַ��" << abs->personArray[index].address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}


//�޸���ϵ��
void modifyPerson(struct AddressBook* abs, string name)
{
	int index = isExist(abs,name);
	if(index != -1)
	{
		string name;
		cout << "������" << endl;
		cin >> name;
		abs->personArray[index].name = name;

		while(true)
		{
			int sex = 0;
			cout << "�Ա�(1--��  2--Ů)" << endl;
			cin >> sex;
			if(sex == 1|| sex == 2)
			{
				abs->personArray[index].sex = sex;
				break;
			}
			cout << "����������������" << endl;
		}

		int age = 0;
		cout << "���䣺" << endl;
		cin >> age;
		abs->personArray[index].age = age;

		string phone;
		cout << "�绰��" << endl;
		cin >> phone;
		abs->personArray[index].phone = phone;

		string address;
		cout << "��ַ��" << endl;
		cin >> address;
		abs->personArray[index].address = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}


//�����ϵ��
void clearPerson(struct AddressBook* abs)
{
	abs->size = 0;

	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
}


int main()
{
	int select = 0;
	AddressBook abs;
	abs.size = 0;

	while(true)
	{
		showMenu();
		cin >> select;
		switch(select)
		{
			case 1: //�����ϵ��
			addPerson(&abs);
			break;

			case 2: //��ʾ��ϵ��
			showPerson(&abs);
			break;

			case 3: //ɾ����ϵ��
			{
				string name;
				cout << "����������" << endl;
				cin >> name;
				deletePerson(&abs,name);
				break;
			}
			
			case 4: //������ϵ��
			{
				string name;
				cout << "����������" << endl;
				cin >> name;
				findPerson(&abs,name);
				break;
			}
			

			case 5: //�޸���ϵ��
			{
				string name;
				cout << "����������" << endl;
				cin >> name;
				modifyPerson(&abs,name);
				break;
			}

			case 6: //�����ϵ��
			clearPerson(&abs);
			break;

			case 0: //�˳�ͨѶ¼
			{
				cout << "��ӭ�´��ٴ�ʹ�ã�" << endl;
				system("pause");
				return 0;
			}
			
			default:
			{
				cout << "����������������" << endl;

				system("pause");
				system("cls");
			}
			break;
			
		}
	}

	system("pause");
	return 0;
}