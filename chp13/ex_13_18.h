#pragma once

#include <string>

class Employee
{
public:
	Employee(std::string _name = std::string()) : name(_name), id(id_generator++) {}
	const int get_id() const { return id; }
private:
	std::string name;
	int id;
private:
	static int id_generator;	
};
