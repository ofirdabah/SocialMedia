#ifndef FACEBOOK_H
#define FACEBOOK_H

#include "Fans_page.h"
#include "Status.h"
#include "StatusVideo.h"
#include "StatusPhoto.h"
#include "User.h"

class Facebookexception : public exception
{
public:
	virtual const char* what() const override { return "Invalid data!"; }
};
class UserExistexception : public Facebookexception
{
public:
	virtual const char* what() const override { return "User name is already exist,Try again please!\n"; }
};
class FanPageExistexception : public Facebookexception
{
public:
	virtual const char* what() const override { return "Fan page name is already exist,Try again please!\n"; }
};
class friendofyourselfExistexception : public Facebookexception
{
public:
	virtual const char* what() const override { return "We belive that evreyone can be friend with himself but not in this website!,please try again!!\n"; }
};
class UserNotExistexception : public Facebookexception
{
	string name;
public:
	UserNotExistexception(string n)
	{
		name = "User name: ";
		name += n;
		name += " is not exist, Try again please!\n";
	}

	virtual const char* what() const override { return name.c_str(); }
};
class FanPageNotExistexception : public Facebookexception
{
	string name;

public:

	FanPageNotExistexception(string n)
	{
		name = "Fan page name: ";
		name += n;
		name += " is not exist, Try again please!\n";
	}

	virtual const char* what() const override { return name.c_str();}
};


class Facebook {

	Facebook(const Facebook& other) = delete;
	vector<User*> all_users;
	vector<Fans_page*> all_fans_page;


public:

	Facebook();
	~Facebook();

	void add_user(string s, int d, int m, int y);
	void add_fanPage(const string page_name);
	void add_status_to_user(const string name, const string status , const string fileName, int num);
	void add_status_to_fan_page(const string name, const string status, const string fileName, int num);
	void show_all_status(string name, int num)const;
	void show_all_friends_status(string name)const;
	void create_friendship(string name, string name2);
	void cancel_friendsship(string name, string name2);
	void add_fan_to_fanPage(string fan_name, string page_name);
	void print_all_users_and_pages()const;
	void print_all_followers(string name, int num)const;
	void remove_fan_from_page(string fan_name, string page_name);
	bool IsUserExist(string u_name)const;
	bool IsFanPageExist(string f_name)const;

};

#endif 


