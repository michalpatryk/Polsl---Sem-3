#include "User.h"


int User::id = 0;

bool User::receive()
// pobieram wiadomo�� ze skrzynki
{
	std::string msg;// wywo�ujemy send w klasie Mbox !!!RECEIVE!!!

	if (mb->receive(this) != nullptr) {
		msg = *mb->receive(this);
		std::cout << msg;
		mb->pulverize(this);	//delete content of my mailbox
	}
	// wy�wietla wiadomo�� na ekranie
	// nast�pnie usuwa
	return true;
}
