#pragma once
#include <string>
#include <iostream>
#include <fstream>

const int N = 10;

class User; // UWAGA zale¿noœæ miêdzy obiektami

class  MailBox
{
	// friend class User; ewntualne uzycie seterów i geterów
	std::string mbox[N]; //tablica wiadomoœci od  uzytkownikow skrzynki
					// indeksem tablicy jest id uzytkownika
	std::ofstream log; //plik z raportem
	std::ofstream backup; // zawartoœæ mbox do pliku backup gdy usuwamy obiekt

public:
	MailBox(std::string& name_of_logfile, std::string& name_of_backupfile); //! done
	// je¿eli plik backup  ju¿ istnieje wczytuje go do mbox	
	
	~MailBox(); //!done
	// zapisuje wszystkie wiadomoœci do backup i usuwa z pamiêci
	// Uwaga poni¿sze metody musz¹ byæ w osobnym pliku:

	bool send(std::string &msg, User *sender, User * reciever);		//!done
	// uzytkownik sender wysyla wiadomosc msg do uzytkownika reciever
		// do pliku log zapisujemy date i czas nadania wiadomosci, id oraz nazwê  nadawcy oraz odbiorcy
		// w przypadku przekroczenia skrzynki mbox zwracamy false  i zapisujemy w pliku log to zdarzenie  jako error
		// jezeli id odbiorcy jest równa id nadawcy wiadomoœæ odrzucamy i zwracamy false
		// umieszczamy tresc wiadomoœci  czas nadania i adres nadawcy   w tablicy pod indeksem bêd¹cym id odbiorcy
		// je¿eli by³a wiadomoœæ nie odebrana doklejamy j¹ (operator + na klasie string) wiadomoœci odzielone s¹
		// ³añcuchem "\n***********\n"
	
	std::string * receive(User *user); //!done
	// zwraca NULL w przypadku b³êdu - indeks poza zakresem, 
	 //lub gdy niema wiadomoœæ dla tego u¿ytkownika
	void print(); //! done
	// wyœietla wszystkie wiadomoœci w skrynce
};


