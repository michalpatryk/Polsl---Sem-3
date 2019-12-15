#pragma once
#include <string>
#include <iostream>
#include <fstream>

const int N = 10;

class User; // UWAGA zale�no�� mi�dzy obiektami

class  MailBox
{
	// friend class User; ewntualne uzycie seter�w i geter�w
	std::string mbox[N]; //tablica wiadomo�ci od  uzytkownikow skrzynki
					// indeksem tablicy jest id uzytkownika
	std::ofstream log; //plik z raportem
	std::ofstream backup; // zawarto�� mbox do pliku backup gdy usuwamy obiekt

public:
	MailBox(std::string& name_of_logfile, std::string& name_of_backupfile); //! done
	// je�eli plik backup  ju� istnieje wczytuje go do mbox	
	
	~MailBox(); //!done
	// zapisuje wszystkie wiadomo�ci do backup i usuwa z pami�ci
	// Uwaga poni�sze metody musz� by� w osobnym pliku:

	bool send(std::string &msg, User *sender, User * reciever);		//!done
	// uzytkownik sender wysyla wiadomosc msg do uzytkownika reciever
		// do pliku log zapisujemy date i czas nadania wiadomosci, id oraz nazw�  nadawcy oraz odbiorcy
		// w przypadku przekroczenia skrzynki mbox zwracamy false  i zapisujemy w pliku log to zdarzenie  jako error
		// jezeli id odbiorcy jest r�wna id nadawcy wiadomo�� odrzucamy i zwracamy false
		// umieszczamy tresc wiadomo�ci  czas nadania i adres nadawcy   w tablicy pod indeksem b�d�cym id odbiorcy
		// je�eli by�a wiadomo�� nie odebrana doklejamy j� (operator + na klasie string) wiadomo�ci odzielone s�
		// �a�cuchem "\n***********\n"
	
	std::string * receive(User *user); //!done
	// zwraca NULL w przypadku b��du - indeks poza zakresem, 
	 //lub gdy niema wiadomo�� dla tego u�ytkownika
	void print(); //! done
	// wy�ietla wszystkie wiadomo�ci w skrynce
};


