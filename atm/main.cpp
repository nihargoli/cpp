#include "atm.h"
#include "accounts.h"
#include "users.h"
using namespace std;
#include "iostream"
#include "list"

int main()
{

	//For this instance of program following are the assumed users:
	//Ideally this is on server and retrieved based on the card insered.
	std::list<account> list_available_accs;
	list_available_accs.set_account_no( 1 );
	
	atm atm_instance;
	std::cout<<"Welcome!" << endl <<"Please insert card(Just insert account no to proceed for now)" << endl;	
	atm_instance.display_menu();
	//atm_instance.

}
