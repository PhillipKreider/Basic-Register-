#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct StockInfo
{
	double price;
	string des;
	int part;
};

int main()
{
	char found;
	double tax;
	double subtotal;
	double total;
	double owed;
	double product_price;
	int pn; // parts number 
	int pro_count; // keeps track of product count 
	double tendered;
	double extra_money; // When tendered amount was insuffeciant
	double change;
	int part_no;
	double price;
	string desc;
	int count = 0;

	cout << setprecision(2) << showpoint << fixed;
	ofstream outfile;
	ifstream stock;
	outfile.open("receipt.txt");
	outfile << setprecision(2) << showpoint << fixed;

	StockInfo product[9];

	stock.open("stock.txt");
	for (count = 0; count < 9; count++)
	{
		stock >> part_no;
		product[count].part = part_no;
		stock >> desc;
		product[count].des = desc;
		stock >> price;
		product[count].price = price;
	}
	stock.close();

	cout << "Please enter a parts number, and when you are done " << endl;
	cout << "enter 0 to close out purchase." << endl;
	cin >> pn;
	total = 0;
	subtotal = 0;
	while (pn != 0)
	{
		found = 'n';
		for (count = 0; count < 9; count++)
		{
			product[count].price;
			product[count].des;
			product[count].part;

			if (pn == product[count].part)
			{
				cout << product[count].price << endl;
				cout << product[count].des << endl;
				cout << product[count].part << endl;
				cout << "How many " << product[count].des << " were bought?" << endl;
				cin >> pro_count;
				subtotal = product[count].price * pro_count;
				cout << "Subtotal: $" << subtotal << endl;
				outfile << "Part Number: " << product[count].part << endl;
				outfile << "Description: " << product[count].des << endl;
				outfile << "Price: $" << product[count].price << endl;
				outfile << "Product Quanity: " << pro_count << endl;
				outfile << "Subtotal: $" << subtotal << endl;
				found = 'y';
				total = total + subtotal;
			}
		}
		if (found == 'n')
		{
			cout << "Part Number was not found." << endl;
		}
		cout << "Please enter your next part number, or 0 to end." << endl;
		cin >> pn;
	}
	tax = total * .08;
	cout << "Tax: " << tax << endl;
	outfile << "Tax: " << tax << endl;
	total = tax + total;
	cout << "Total: " << total << endl;
	outfile << "Total: " << total << endl;
	cout << "What was the amount of money tendered?" << endl;
	cin >> tendered;
	while (tendered < total)
	{
		cout << "The amount paid was insuffecient, please get more money." << endl;
		cout << "How much more was tendered?" << endl;
		cin >> extra_money;
		tendered = tendered + extra_money;
	}
	change = tendered - total;
	cout << "Change: " << change << endl;
	outfile.close();
	return 0;
}