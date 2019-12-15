#include "MailBox.h"
#include <ctime>
#include "User.h"
#pragma warning(disable : 4996)
MailBox::MailBox(std::string & name_of_logfile, std::string & name_of_backupfile)
// je�eli plik backup  ju� istnieje wczytuje go do mbox
{
	std::ifstream ifs(name_of_backupfile);
	if (ifs) {
		int i = 0;
		std::cout << "Loading old file" << std::endl;
		while (ifs>>mbox[i]) {
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
// do pliku log zapisujemy date i czas nadania wiadomosci, id oraz nazw�  nadawcy oraz odbiorcy
		// w przypadku przekroczenia skrzynki mbox zwracamy false  i zapisujemy w pliku log to zdarzenie  jako error
		// jezeli id odbiorcy jest r�wna id nadawcy wiadomo�� odrzucamy i zwracamy false
		// umieszczamy tresc wiadomo�ci  czas nadania i adres nadawcy   w tablicy pod indeksem b�d�cym id odbiorcy
		// je�eli by�a wiadomo�� nie odebrana doklejamy j� (operator + na klasie string) wiadomo�ci odzielone s�
		// �a�cuchem "\n***********\n"
{
//	log << 
	std::time_t t = std::time(0);	//get current time
	
	//std::cout
	std::cout << "Send time: " <<std::ctime(&t)<< "Sender ID: " << sender->getMyID() << "\nSender Name: " << sender->getNickname()<<
		"\nReciever ID: "<< reciever->getMyID() << "\nReciver Name: " << reciever->getNickname();
	return false;
}

void MailBox::print()
{
	for (int i = 0; i < N; i++) {
		std::cout << mbox[i] << std::endl;
	}
}
