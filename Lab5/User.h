#pragma once
#include "MailBox.h"

class  User
{
	static int id; // zmienna statyczna inkrementowana w konstruktorze będąca id następnego  użytkownika
	int myid; // id użytkownika
	std::string nickname; // nazwa użytkownika
	MailBox *mb;// adres skrzynki z którą jest zwiazany użytkownik

public:
	int getMyID() { return myid; };
	std::string getNickname() { return nickname; };
	User(MailBox *mb_, std::string & nickname_)//! done
	{
		myid = id++; //przypisanie unikalnego id
		nickname = nickname_;
		// nadanie nazwy użytkownikowi
		mb = mb_;
		// przypisanie skrzynki zdefiniowanej wcześniej
	}

	bool send(std::string &msg, User & reciever)//! done?
	{
		bool test = mb->send(msg, this, &reciever); // wywołujemy send w klasie Mbox
		return test;
	};

	bool receive();

};


