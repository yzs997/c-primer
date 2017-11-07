#include <iostream>
#include <string>

struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data book, currBook;
	double price1, price2;
	if (std::cin >> currBook.bookNo >> currBook.units_sold >> price1)
	{
		currBook.revenue = currBook.units_sold * price1;
		while (std::cin >> book.bookNo >> book.units_sold >> price2)
		{	
			
			book.revenue = book.units_sold * price2;
			if (currBook.bookNo == book.bookNo)
			{
				currBook.units_sold += book.units_sold;
				currBook.revenue += book.revenue;
			}
			else
			{
				std::cout << currBook.bookNo << " " << currBook.units_sold << " " << currBook.revenue
					<< currBook.revenue / currBook.units_sold;
				currBook = book;
			}
		}
		std::cout << currBook.bookNo << " " << currBook.units_sold << " " << currBook.revenue
			<< currBook.revenue / currBook.units_sold;
	}
	return 0;
}
