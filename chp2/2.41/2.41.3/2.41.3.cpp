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
		unsigned cnt = currBook.units_sold;
		double total_revenue = currBook.revenue;
		

		while (std::cin >> book.bookNo >> book.units_sold >> price2)
		{	
			
			book.revenue = book.units_sold * price2;
			if (currBook.bookNo == book.bookNo)
			{
				cnt += book.units_sold;
				total_revenue += book.revenue;
			}
			else
			{
				std::cout << currBook.bookNo << " " << cnt << " " << total_revenue << " "
					<< total_revenue / cnt << std::endl;
				currBook = book;
				cnt = currBook.units_sold;
				total_revenue = currBook.revenue;
			}
		}
		std::cout << currBook.bookNo << " " << cnt << " " << total_revenue << " "
			<< total_revenue / cnt << std::endl;
	}
	return 0;
}
