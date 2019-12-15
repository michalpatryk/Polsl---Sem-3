#include "User.h"


int User::id = 0;

bool User::receive()
// pobieram wiadomoœæ ze skrzynki
{
	std::string msg;// wywo³ujemy send w klasie Mbox !!!RECEIVE!!!

	if (mb->receive(this) != nullptr) {
		msg = *mb->receive(this);
		std::cout << msg;
		mb->pulverize(this);	//delete content of my mailbox
	}
	// wyœwietla wiadomoœæ na ekranie
	// nastêpnie usuwa
	return true;
}
