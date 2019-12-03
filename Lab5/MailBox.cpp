#include "MailBox.h"
#include <iostream>
MailBox::MailBox(std::string & name_of_logfile, std::string & name_of_backupfile)
// je¿eli plik backup  ju¿ istnieje wczytuje go do mbox
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
