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
	Sales_data sales_data1, sales_data2;
	double price1, price2;
	double price;
	std::cin >> sales_data1.bookNo >> sales_data1.units_sold >> price1;
	std::cin >> sales_data2.bookNo >> sales_data2.units_sold >> price2;
	if (sales_data1.bookNo == sales_data2.bookNo)
	{
		sales_data1.revenue = sales_data1.units_sold * price1;
		sales_data2.revenue = sales_data2.units_sold * price2;
		double total_revenue = sales_data1.revenue + sales_data2.revenue;
		unsigned cnt = sales_data1.units_sold + sales_data2.units_sold;
		if (cnt)
		{
			price = total_revenue / cnt;
		}
		std::cout << sales_data1.bookNo << " " << cnt << " " << total_revenue << " "
			<< price << " " << std::endl;
	}
	else
	{
		std::cerr << " must be the same book" << std::endl;
	}
	

	return 0;
}
