#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 1000

struct Person
{
	string name;  	 //姓名
	int sex;   	 //性别
	int age;	  	 //年龄
	string phone;	 //电话
	string address;  //地址
};

struct AddressBook
{
	Person personArray[MAX];
	int size;
};

void showMenu()
{
	cout << endl;
	cout << "-----------【主菜单】-----------" << endl;
	cout << "---------1.添加联系人:----------" << endl;
	cout << "---------2.显示联系人：---------" << endl;
	cout << "---------3.删除联系人：---------" << endl;
	cout << "---------4.查找联系人：---------" << endl;
	cout << "---------5.修改联系人：---------" << endl;
	cout << "---------6.清空联系人：---------" << endl;
	cout << "---------0.退出通讯录：---------" << endl;
}

//添加联系人
void addPerson(struct AddressBook* abs)
{
	if( abs->size == MAX)
	{
		cout << "联系人已满" << endl;
	}
	else
	{
		string name;
		cout << "姓名：" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;

		while(true)
		{
			int sex = 0;
			cout << "性别：(1--男  2--女)" << endl;
			cin >> sex;
			if(sex == 1|| sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}

		int age = 0;
		cout << "年龄：" << endl;
		cin >> age;
		abs->personArray[abs->size].age = age;

		string phone;
		cout << "电话：" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		string address;
		cout << "地址：" << endl;
		cin >> address;
		abs->personArray[abs->size].address = address;

		abs->size++;
		cout << "添加成功" << endl;
	}
	
	system("pause");
	system("cls");
}


//显示联系人
void showPerson(struct AddressBook* abs)
{
	if(abs->size == 0)
	{
		cout << "联系人为空" << endl;
	}
	else
	{
		for(int i=0; i<abs->size; i++)
		{
			cout << "姓名：" << abs->personArray[i].name << "\t";
			cout << "性别：" << (abs->personArray[i].sex == 1 ? "男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话：" << abs->personArray[i].phone << "\t";
			cout << "地址：" << abs->personArray[i].address << endl;
		}
	}

	system("pause");
	system("cls");
}


//检测联系人是否存在
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

//删除联系人
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
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}


//查找联系人
void findPerson(struct AddressBook* abs, string name)
{
	int index = isExist(abs,name);
	if(index != -1)
	{	
		cout << "姓名：" << abs->personArray[index].name << "\t";
		cout << "性别：" << (abs->personArray[index].sex == 1 ? "男":"女") << "\t";
		cout << "年龄：" << abs->personArray[index].age << "\t";
		cout << "电话：" << abs->personArray[index].phone << "\t";
		cout << "地址：" << abs->personArray[index].address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}


//修改联系人
void modifyPerson(struct AddressBook* abs, string name)
{
	int index = isExist(abs,name);
	if(index != -1)
	{
		string name;
		cout << "姓名：" << endl;
		cin >> name;
		abs->personArray[index].name = name;

		while(true)
		{
			int sex = 0;
			cout << "性别：(1--男  2--女)" << endl;
			cin >> sex;
			if(sex == 1|| sex == 2)
			{
				abs->personArray[index].sex = sex;
				break;
			}
			cout << "输入有误，重新输入" << endl;
		}

		int age = 0;
		cout << "年龄：" << endl;
		cin >> age;
		abs->personArray[index].age = age;

		string phone;
		cout << "电话：" << endl;
		cin >> phone;
		abs->personArray[index].phone = phone;

		string address;
		cout << "地址：" << endl;
		cin >> address;
		abs->personArray[index].address = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}


//清空联系人
void clearPerson(struct AddressBook* abs)
{
	abs->size = 0;

	cout << "清除成功" << endl;
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
			case 1: //添加联系人
			addPerson(&abs);
			break;

			case 2: //显示联系人
			showPerson(&abs);
			break;

			case 3: //删除联系人
			{
				string name;
				cout << "输入姓名：" << endl;
				cin >> name;
				deletePerson(&abs,name);
				break;
			}
			
			case 4: //查找联系人
			{
				string name;
				cout << "输入姓名：" << endl;
				cin >> name;
				findPerson(&abs,name);
				break;
			}
			

			case 5: //修改联系人
			{
				string name;
				cout << "输入姓名：" << endl;
				cin >> name;
				modifyPerson(&abs,name);
				break;
			}

			case 6: //清空联系人
			clearPerson(&abs);
			break;

			case 0: //退出通讯录
			{
				cout << "欢迎下次再次使用！" << endl;
				system("pause");
				return 0;
			}
			
			default:
			{
				cout << "输入有误，重新输入" << endl;

				system("pause");
				system("cls");
			}
			break;
			
		}
	}

	system("pause");
	return 0;
}