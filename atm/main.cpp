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
	account a1, a2, a3;

	a1.set_no( 1 );
	a1.set_balance( 1000 );
	a1.set_pin( 1234 );

	a2.set_no( 2 );
	a2.set_balance( 1000 );
	a2.set_pin( 1234 );
	
	a3.set_no( 3 );
	a3.set_balance( 1000 );
	a3.set_pin( 1234 );
	
	std::list<account> list_accs;
	
	list_accs.push_back(a1);
	list_accs.push_back(a2);
	list_accs.push_back(a3);
	
	atm atm_instance;
	std::cout<<"Welcome!" << endl <<"Please insert card(Just insert account no to proceed for now)" << endl;	
	atm_instance.display_menu();

	account *cur_acc;
	std::list<account>::iterator iter;

	for ( iter = list_accs.begin(); iter != list_accs.end(); iter++ ) {
		if (  (*iter).get_no() == 1 ) 
			break;
	}
	//std::cout<<iter->get_no();
	cur_acc = &(*iter);	
	users *u1 = new users;
	u1->fill_account_details(cur_acc);
	cout<<u1->user_acc->get_balance();	
	delete u1;
	//atm_instance.

}
