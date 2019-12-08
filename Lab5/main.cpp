#include "MailBox.h"
#include "User.h"
#include <string>

int main() {
	std::string lf = "logfile.txt";
	std::string bf = "backupfile.txt";
	MailBox mb(lf, bf );
	std::string us1name = "Jack";
	User us1{ &mb, us1name };

	return 0;
}