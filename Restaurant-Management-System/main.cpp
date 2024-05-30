#include <iostream>
#include <string>
using namespace std;

void customerShowMenu()
{
	cout << "1. Browse menu" << endl;
	cout << "2. Order dishes" << endl;
	cout << "3. check out" << endl;
}

void managerShowMenu()
{
	cout << "1. Add/Delete materials" << endl;
	cout << "2. Add/Delete dishes" << endl;
	cout << "3. View materials, menu and cuctomers" << endl;
	cout << "4. Modify cuctomers" << endl;
	cout << "5. View Profits" << endl;
}

void chefShowMenu()
{
	cout << "1. Add/Delete materials" << endl;
	cout << "2. Add/Delete Dishes" << endl;
	cout << "3. Browse Materials and Menu" << endl;
}

struct rawMaterials
{
	string m_name;
	int m_expand;
};

struct Materials
{
	struct rawMaterials materialarray[1000];
	int m_size=0;
};

struct dish
{
	string d_dishname;
	int d_price;
};

struct Dish
{
	struct dish disharray[1000];
	int d_size = 0;
};

struct customer
{
	string c_lastname;
	string c_phone;
};

struct Customer
{
	struct customer customerarray[1000];
	int c_size = 0;
};

void showMaterials(Materials* abs1)
{
	if (abs1->m_size == 0)
	{
		cout << "No materials for now" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs1->m_size; i++)
		{
			cout << "Materials: " << abs1->materialarray[i].m_name << endl;
			cout << "Expand of the materials£» " << abs1->materialarray[i].m_expand << endl;
		}
	}
}

int isExist1(Materials* abs1, string m)
{
	for (int i = 0; i <= abs1->m_size; i++)
	{
		if (abs1->materialarray[i].m_name == m)
		{
			return i;
		}
		return -1;
	}
}

int isExist2(Dish* abs2, string d)
{
	for (int i = 0; i < abs2->d_size; i++)
	{
		if (abs2->disharray[i].d_dishname == d)
		{
			return i;
		}
		return -1;
	}
}

int isExist3(Customer* abs3, string c)
{
	for (int i = 0; i < abs3->c_size; i++)
	{
		if (abs3->customerarray[i].c_lastname == c)
		{
			return i;
		}
		return -1;
	}
}

void addorDeleteMaterials(Materials * abs1)
{
	cout << "1--Add" << endl;
	cout << "2--Delete" << endl;
	int a;
	cin >> a;
	while (true)
	{
		switch (a)
		{
		case 1:
		{
			if (abs1->m_size == 1000)
			{
				cout << "Do not need to add materials" << endl;
				return;
			}
			else
			{
				string addmaterial;
				int budget;
				cout << "Add new materials: " << endl;
				cin >> addmaterial;
				abs1->materialarray[abs1->m_size].m_name = addmaterial;
				cout << "Expand of the material:  " << endl;
				cin >> budget;
				abs1->materialarray[abs1->m_size].m_expand = budget;

				abs1->m_size++;
				cout << "Successfully Add" << endl;
				
				system("pause");
				system("cls");
			}
		}			
			break;
		case 2:
		{
			cout << "Enter the materials you want to delete" << endl;
			string delematerial;
			cin >> delematerial;
			if (isExist1(abs1, delematerial) == -1)
			{
				cout << "materials can not be found" << endl;
			}
			else
			{
				cout << "materials is found" << endl;
			}

			int ret1 = isExist1(abs1, delematerial);
			if (ret1 != -1)
			{
				for (int i = 0; i < abs1->m_size; i++)
				{
					abs1->materialarray[i] = abs1->materialarray[i + 1];
				}
				abs1->m_size--;
				system("pause");
				system("cls");
			}

		}
		break;
		default:
			break;

		}
	}
	;
	
}

void addorDeleteDishes(Dish * abs2)
{
	cout << "1--Add" << endl;
	cout << "2--Delete" << endl;
	int b;
	cin >> b;
	while (true)
	{
		switch (b)
		{
		case 1:
		{
			if (abs2->d_size == 1000)
			{
				cout << "Menu is full" << endl;
				return;
			}
			else
			{
				string adddish;
				int price;
				cout << "Adding dishes:  " << endl;
				cin >> adddish;
				abs2->disharray[abs2->d_size].d_dishname = adddish;
				cout << "Adding prices:  " << endl;
				cin >> price;
				abs2->disharray[abs2->d_size].d_price = price;

				abs2->d_size++;
				cout << "successfully adding" << endl;

				system("pause");
				system("cls");
			}
			
		}
			break;
		case 2:
		{
			cout << "Enter the materials you want to delete" << endl;
			string deledish;
			cin >> deledish;
			if (isExist2(abs2, deledish) == -1)
			{
				cout << "dishes can not be found" << endl;
			}
			else
			{
				cout << "dishes is found" << endl;
			}

			int ret2 = isExist2(abs2, deledish);
			if (ret2 != -1)
			{
				for (int i = 0; i < abs2->d_size; i++)
				{
					abs2->disharray[i] = abs2->disharray[i + 1];
				}
				abs2->d_size--;
				system("pause");
				system("cls");
			}
		}
			break;
		default:
			break;

		}
	}
}

void browseMaterial(Materials* abs1)
{
	if (abs1->m_size == 0)
	{
		cout << "No materials" << endl;
	}
	else
	{
		for (int i = 0; i < abs1->m_size; i++)
		{
			cout << "Material: " << abs1->materialarray[i].m_name << endl;
			cout << "Expand: " << abs1->materialarray[i].m_expand << endl;
		}
	}
}

void ModifyCustomers(Customer * abs3)
{
	cout << "1--Add" << endl;
	cout << "2--Delete" << endl;
	int c;
	cin >> c;
	while (true)
	{
		switch (c)
		{
		case 1:
		{
			if (abs3->c_size = 1000)
			{
				cout << "No more customer for now" << endl;
			}
			else
			{
				string customername;
				string phonenum;
				cout << "Enter the last name: " << endl;
				cin >> customername;
				abs3->customerarray[abs3->c_size].c_lastname = customername;
				cout << "Phone of the customer: " << endl;
				cin >> phonenum;
				abs3->customerarray[abs3->c_size].c_phone = phonenum;

				abs3->c_size++;
				cout << "succesfully adding" << endl;

				system("pause");
				system("cls");
			}
		}
			break;
		case 2:
		{
			cout << "Enter the dish you want to delete" << endl;
			string deletcustom;
			cin >> deletcustom;
			if (isExist3(abs3, deletcustom) == -1)
			{
				cout << "materials can not be found" << endl;
			}
			else
			{
				cout << "materials is found" << endl;
			}

			int ret3 = isExist3(abs3, deletcustom);
			if (ret3 != -1)
			{
				for (int i = 0; i < abs3->c_size; i++)
				{
					abs3->customerarray[i] = abs3->customerarray[i + 1];
				}
				abs3->c_size--;
				system("pause");
				system("cls");
			}
		}
			break;
		}
	}
}

void browseMenu(Dish * abs2)
{
	if (abs2->d_size == 0)
	{
		cout<<"No dishes for now" << endl;
 }
	else
	{
		for (int i = 0; i < abs2->d_size; i++)
		{
			cout <<"Dish:  "<< abs2->disharray[i].d_dishname << endl;
			cout << "Price:  " << abs2->disharray[i].d_price << endl;
		}
	}

	system("pause");
	system("cls");
}

void viewCustomer(Customer* abs3)
{
	if (abs3->c_size == 0)
	{
		cout << "No customers" << endl;
	}
	else
	{
		for (int i = 0; i < abs3->c_size; i++)
		{
			cout << "Last name: " << abs3->customerarray[i].c_lastname << endl;
			cout << "Phone number:  " << abs3->customerarray[i].c_phone << endl;
		}
	}
}

void grossProfit(Materials* abs1, Dish* abs2)
{
	double revenue = 0;
	double cost = 0;
	for (int i = 0 ; i < abs2->d_size; i++)
	{
		revenue += abs2->disharray[i].d_price;
	}
	for (int j = 0; j < abs1->m_size; j++)
	{
		cost += abs1->materialarray[j].m_expand;
	}
	double profit = revenue - cost;
	cout << "Total gross Profit for the dishes is:  " << profit << endl;
}

int main()
{
	int select;
	cout << "Classify your identity" << endl;
	cout << "1---Customer" << endl;
	cout << "2--Manager" << endl;
	cout << "3---Chef" << endl;
	cout << "0--Exit" << endl;
	cin >> select;

	Materials abs1;
	abs1.m_size = 0;
	Dish abs2;
	abs2.d_size = 0;
	Customer abs3;
	abs3.c_size = 0;
	while (true)
	{
		switch (select)
		{
		case 1:
			customerShowMenu();
			int choice1;
			cin >> choice1;
			while (true)
			{
				switch (choice1)
				{
				case 1:
					browseMenu(&abs2);
					break;
				case 2:
					cout << "Order dishes..." << endl;
					break;
				case 3:
					cout << "Check out..." << endl;
					break;
				}
				break;
			}
			break;
		case 2:
		{
			managerShowMenu();
			int choice2;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				addorDeleteMaterials(&abs1);
				break;
			case 2:
				addorDeleteDishes(&abs2);
				break;
			case 3:
				browseMaterial(&abs1);
				browseMenu(&abs2);
				viewCustomer(&abs3);
				break;
			case 4:
				ModifyCustomers(&abs3);
				break;
			case 5:
				grossProfit(&abs1, &abs2);
				break;
			}
		}
			break;
		case 3:
		{
			chefShowMenu();
			int choice3;
			cin >> choice3;
			switch (choice3)
			{
			case 1:
				addorDeleteMaterials(&abs1);
				break;
			case 2:
				addorDeleteDishes(&abs2);
				break;
			case 3:
				browseMaterial(&abs1);
				browseMenu(&abs2);
				break;
			}
		}			
			break;
		case 0:
			break;
		default:
			break;
		}
	}
	



	system("pause");
	return 0;
}

