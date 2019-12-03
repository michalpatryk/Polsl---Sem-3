#include "MailBox.h"
#include "User.h"

int main() {
	std::string lf = "logfile.txt";
	std::string bf = "backupfile.txt";
	MailBox mb(lf, bf );
	return 0;
}