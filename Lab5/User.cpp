#include "User.h"


int User::id = 0;

bool User::receive()
// pobieram wiadomość ze skrzynki
{
	std::string msg;// wywołujemy send w klasie Mbox !!!RECEIVE!!!

	if (mb->receive(this) != nullptr) {
		msg = *mb->receive(this);
		std::cout << msg;
		mb->pulverize(this);	//delete content of my mailbox
	}
	// wyświetla wiadomość na ekranie
	// następnie usuwa
	return true;
}
