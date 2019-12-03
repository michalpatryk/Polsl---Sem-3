#pragma once
#include <string>
#include "MailBox.h"

class  User
{
	static int id; // zmienna statyczna inkrementowana w konstruktorze bêd¹ca id nastêpnego  u¿ytkownika
	int myid; // id u¿ytkownika
	std::string nickname; // nazwa u¿ytkownika
	MailBox *mb;// adres skrzynki z któr¹ jest zwiazany u¿ytkownik

public:

	User(MailBox *mb_, std::string & nickname_)//
	{
		myid = id++; //przypisanie unikalnego id
		// nadanie nazwy u¿ytkownikowi
		// przypisanie skrzynki zdefiniowanej wczeœniej
	}

	bool send(std::string &msg, User & reciever)//
	{
		mb->send(msg, this, &reciever); // wywo³ujemy send w klasie Mbox
	};

	bool receive()// pobieram wiadomoœæ ze skrzynki
	{
		std::string msg;
		mb->receive(this); // wywo³ujemy send w klasie Mbox
		// wyœwietla wiadomoœæ na ekranie
		// nastêpnie usuwa
	}
};


