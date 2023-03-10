#ifndef FANS_PAGE
#define FANS_PAGE
#include <ctime>
#include "User.h"
#include <iostream>

class User;

class Fans_pagexception : public exception
{
public:
	virtual const char* what() const override { return "Data invalid!\n"; }
};
class Emptynamexception : public Fans_pagexception
{
public:
	virtual const char* what() const override { return "Empty name is invalid!\n"; }
};
class UserNoExistexception : public Fans_pagexception
{
public:
	virtual const char* what() const override { return "User not exist!\n"; }
};
class UserAlreadyfollowexception : public Fans_pagexception
{
public:
	virtual const char* what() const override { return "User already follow this page exist!\n"; }
};


class Fans_page
{
	string page_name;
	vector <User*> fans_arr;
	vector<Status*> status_of_page;

public:
	Fans_page(const Fans_page& other) = delete;
	const string get_page_name() const { return page_name; }

	const vector <User*>& get_fans_arr() { return fans_arr; }
    const vector<Status*>& getStatus_of_page() const  { return status_of_page; }  

	Fans_page(string name);
	~Fans_page();
	void add_status(Status* s);
	void print_all_status()const;
	void print_all_my_folowers()const;
	void add_fan( User* newfan);
	void remove_fan(const string& fan_name);
	Fans_page& operator+=(User& other);
	bool operator>(const Fans_page& other) const;
	bool operator>(const User& other) const;
};

#endif 