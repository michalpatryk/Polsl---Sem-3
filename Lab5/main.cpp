#include "MailBox.h"
#include "User.h"
#include <string>

int main() {
	std::string lf = "logfile.txt";
	std::string bf = "backupfile.txt";
	MailBox mb(lf, bf );
	std::string us1name = "Jack";
	std::string us2name = "Kcaj";
	User us1{ &mb, us1name };
	User us2{ &mb, us2name };

	mb.send(bf, &us1, &us2);
	mb.send(lf, &us1, &us2);
	mb.send(us2name, &us1, &us2);
	mb.send(us1name, &us2, &us1);
	std::string msg1 = "Example Message";
	std::string msg2 = "Other Message";

	us1.send(msg1, us2);
	us2.send(msg1, us2);

	us1.receive();
	std::cout << std::endl;
	us2.receive();

	return 0;
}