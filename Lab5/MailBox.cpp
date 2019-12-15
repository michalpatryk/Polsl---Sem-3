#include "MailBox.h"
#include <ctime>
#include "User.h"
#pragma warning(disable : 4996)
MailBox::MailBox(std::string & name_of_logfile, std::string & name_of_backupfile)
// je¿eli plik backup  ju¿ istnieje wczytuje go do mbox
{
	std::ifstream ifs(name_of_backupfile);
	if (ifs) {
		int i = 0;
		std::cout << "Loading old file" << std::endl;
		while (ifs >> mbox[i]) {
			i++;
			std::cout << "Line loaded" << std::endl;
		}
	}
	else {
		std::cout << "CREATING NEW FILE" << std::endl;
		backup = std::ofstream(name_of_backupfile);
	}

	log = std::ofstream(name_of_logfile);
}

MailBox::~MailBox()
{
	for (int i = 0; i < mbox->length(); i++) {
		log << mbox[i] << std::endl;
	}
}

bool MailBox::send(std::string & msg, User * sender, User * reciever)
// do pliku log zapisujemy date i czas nadania wiadomosci, id oraz nazwę  nadawcy oraz odbiorcy
	   // w przypadku przekroczenia skrzynki mbox zwracamy false  i zapisujemy w pliku log to zdarzenie  jako error
	   // jezeli id odbiorcy jest równa id nadawcy wiadomość odrzucamy i zwracamy false
	   //! umieszczamy tresc wiadomości  czas nadania i adres nadawcy   w tablicy pod indeksem będącym id odbiorcy
	   // jeżeli była wiadomość nie odebrana doklejamy ją (operator + na klasie string) wiadomości odzielone są
	   // łańcuchem "\n***********\n"
{

	std::time_t t = std::time(0);	//get current time
	log << "\nSend time: " << std::ctime(&t) << "Sender ID: " << sender->getMyID() << "\nSender Name: " << sender->getNickname() <<
		"\nReciever ID: " << reciever->getMyID() << "\nReciver Name: " << reciever->getNickname();


	if ((sender->getMyID() < 10 && reciever->getMyID() < 10) ) {
		if (sender->getMyID() != reciever->getMyID()) {
			if (mbox[reciever->getMyID()].empty()) { mbox[reciever->getMyID()] = msg; }
			else { 
				mbox[reciever->getMyID()] += "\n***********\n";
				mbox[reciever->getMyID()] += msg;
			}
		}
	}
	else log << "ERROR!!!";
	return false;
}

std::string * MailBox::receive(User * user)
// zwraca NULL w przypadku b³êdu - indeks poza zakresem, 
	 //lub gdy niema wiadomoœæ dla tego u¿ytkownika
{
	if (user->getMyID() < 10) {
		if (!mbox[user->getMyID()].empty()) return &mbox[user->getMyID()];		//!Only recieve, no deletion here
	}
	return nullptr;
}

void MailBox::pulverize(User * user)
{
	if (user->getMyID() < 10) {
		mbox[user->getMyID()] = "";
	}
}

void MailBox::print()
{
	for (int i = 0; i < N; i++) {
		std::cout << mbox[i] << std::endl;
	}
}
