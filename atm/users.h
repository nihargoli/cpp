#include "accounts.h"
#ifndef _users_h
#define _users_h

class users {
	private: 
		//class atm atm_machine;
	public: 
		class account *user_acc;
		long int check_balance();
		bool     fill_account_details( class account * );
		bool     load_cash();
		int      withdraw_cash();
		int      change_pin();
};

#endif
