#include "users.h"
using namespace std;
#include <string>

//Argument: pointer to accounts class object
//Assign a user object with his account details.
bool users::fill_account_details( class account *acc ){
	users::user_acc = acc;	
}
                
//Argument: Amount to be loaded
//Loads cash of a user
bool users::load_cash( long int amt ) {
	users::user_acc->set_balance ( (users::user_acc->get_balance()) + amt );
}
                
//Argument: Amount to be withdrawn
//Withdraw cash!
bool users::withdraw_cash ( long int amt ) {
	if ( amt > users::user_acc->get_balance() )
		return false;
	else {  
		users::user_acc->set_balance ( (users::user_acc->get_balance()) - amt );
		return true;
	}
}

//Argument: None
//returns users current disposable balance.
long int users::check_balance() { 
	return ( users::user_acc->get_balance() );
}

//Argument: New pin
//Changes existing pin
bool users::change_pin( string pin ) { 
	users::user_acc->set_pin( pin );
	return true;
}

//Argument: pin
//validates passed pin against user's current pin
bool users::validate_pin( string pin ) {
	if ( users::user_acc->get_pin() == pin )
		return true;
	else
		return false;
}

