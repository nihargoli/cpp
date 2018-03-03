#include "accounts.h"
#ifndef _users_h
#define _users_h

class users {
	private: 
		class account a1;
		//class atm atm_machine;
	public: 
		bool fill_account_details();
		bool load_cash();
		int withdraw_cash();
		long int check_balance();
		int change_pin();
};

#endif
