#pragma once
#include <string>
#include "MailBox.h"

class  User
{
	static int id; // zmienna statyczna inkrementowana w konstruktorze b�d�ca id nast�pnego  u�ytkownika
	int myid; // id u�ytkownika
	std::string nickname; // nazwa u�ytkownika
	MailBox *mb;// adres skrzynki z kt�r� jest zwiazany u�ytkownik

public:

	User(MailBox *mb_, std::string & nickname_)//
	{
		myid = id++; //przypisanie unikalnego id
		// nadanie nazwy u�ytkownikowi
		// przypisanie skrzynki zdefiniowanej wcze�niej
	}

	bool send(std::string &msg, User & reciever)//
	{
		mb->send(msg, this, &reciever); // wywo�ujemy send w klasie Mbox
	};

	bool receive()// pobieram wiadomo�� ze skrzynki
	{
		std::string msg;
		mb->receive(this); // wywo�ujemy send w klasie Mbox
		// wy�wietla wiadomo�� na ekranie
		// nast�pnie usuwa
	}
};


