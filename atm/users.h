#include "accounts.h"
#ifndef _users_h
#define _users_h

class users {
	private: 
		accounts a1;
	public:
		fill_account_details();
		load_cash();
		withdraw_cash();
		check_balance();
		change_pin();
};

#endif
