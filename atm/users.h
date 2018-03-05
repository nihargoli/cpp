#include "accounts.h"
#ifndef _users_h
#define _users_h
using namespace std;
#include <string>

class users {
	private: 
		//class atm atm_machine;
		class account *user_acc;
	public: 
		long int check_balance();
		bool     fill_account_details( class account * );
		bool     load_cash( long int );
		bool     validate_pin( string pin );
		bool     withdraw_cash( long int );
		bool     change_pin( string pin );

};

#endif
