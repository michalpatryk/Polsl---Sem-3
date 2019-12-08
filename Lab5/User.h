#pragma once
#include "MailBox.h"

class  User
{
	static int id; // zmienna statyczna inkrementowana w konstruktorze będąca id następnego  użytkownika
	int myid; // id użytkownika
	std::string nickname; // nazwa użytkownika
	MailBox *mb;// adres skrzynki z którą jest zwiazany użytkownik

public:

	User(MailBox *mb_, std::string & nickname_)//
	{
		myid = id++; //przypisanie unikalnego id
		nickname = nickname_;
		// nadanie nazwy użytkownikowi
		mb = mb_;
		// przypisanie skrzynki zdefiniowanej wcześniej
	}

	bool send(std::string &msg, User & reciever)//
	{
		mb->send(msg, this, &reciever); // wywołujemy send w klasie Mbox
	};

	bool receive()// pobieram wiadomość ze skrzynki
	{
		std::string msg;
		mb->receive(this); // wywołujemy send w klasie Mbox
		// wyświetla wiadomość na ekranie
		// następnie usuwa
	}
};


