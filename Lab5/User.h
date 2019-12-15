#pragma once
#include "MailBox.h"

class  User
{
	static int id; // zmienna statyczna inkrementowana w konstruktorze b�d�ca id nast�pnego  u�ytkownika
	int myid; // id u�ytkownika
	std::string nickname; // nazwa u�ytkownika
	MailBox *mb;// adres skrzynki z kt�r� jest zwiazany u�ytkownik

public:
	int getMyID() { return myid; };
	std::string getNickname() { return nickname; };
	User(MailBox *mb_, std::string & nickname_)//! done
	{
		myid = id++; //przypisanie unikalnego id
		nickname = nickname_;
		// nadanie nazwy u�ytkownikowi
		mb = mb_;
		// przypisanie skrzynki zdefiniowanej wcze�niej
	}

	bool send(std::string &msg, User & reciever)//! done?
	{
		mb->send(msg, this, &reciever); // wywo�ujemy send w klasie Mbox
	};

	bool receive();

};


