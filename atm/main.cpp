#include "atm.h"
#include "accounts.h"
#include "users.h"
#include "atm_state_machine.h"
#define ACCOUNT_NO_LEN 2
#define PIN_LEN 4

using namespace std;
#include "iostream"
#include "list"
#include "string"

//Takes two arguments.
//#1 - input string
//#2 - Number of allowed digits.
bool validate_input_type( std::string result , int no )
{
    bool ok = false;
    if (result.length() == no)
    {
            bool allDigits = true;
            for(unsigned index = 0; index < no; ++index)
            {
                allDigits = allDigits && ( 
                    (result[index] >= '0') && 
                    (result[index] <='9') 
                    );
            }
            ok = allDigits;
    }
    return ok;
}

// Begin
int main()
{
	// For this instance of program following are the assumed users:
	// Ideally this is on server and retrieved based on the card insered.
	account a1, a2, a3;
	int option;
	string req_account_no;
	bool acc_found = false;

	a1.set_no( "11" );
	a1.set_balance( 1000 );
	a1.set_pin( "1234" );

	a2.set_no( "12" );
	a2.set_balance( 1000 );
	a2.set_pin( "1234" );
	
	a3.set_no( "13" );
	a3.set_balance( 1000 );
	a3.set_pin( "1234" );
	
	// Build list of created accounts..
	std::list<account> list_accs;	
	list_accs.push_back(a1);
	list_accs.push_back(a2);
	list_accs.push_back(a3);
	
	// Create atm context object and change states accordingly.
	atm_context ac( new no_card_inserted );
	
	// Iterate through accounts list to pick the choosen account for the current 
	// transaction 
	std::list<account>::iterator iter;
	while ( 1 ) {
		ac.display_helper();
		cin>>req_account_no; 
		if ( validate_input_type( req_account_no , ACCOUNT_NO_LEN )  ) {
			for ( iter = list_accs.begin(); iter != list_accs.end(); iter++ ) {
				if (  (*iter).get_no() == req_account_no ) {
					acc_found = true;
					break;
				}
			}
		}
		if ( acc_found ) 
			break;
		else {
			cout<<"Invalid account entry"<<endl;
		}
	}
	account *cur_acc;
	cur_acc = &(*iter);
	users *u1 = new users;
	u1->fill_account_details(cur_acc);

	//atm atm_instance;
	int amt;
	std::string pin, pin1, pin2; 
	ac.state_change();
	while ( 1 ) {
		ac.display_helper();
		cin>>option;
		//1.Load cash
		//2.Withdraw cash
		//3.Change Pin
		//4.Check Available balance
		//5.Exit
		switch ( option ) {
			case 1:
				cout<<"Enter amount to load" << endl;
				cin>>amt;
				if ( u1->load_cash(amt) )
					cout<<"cash loaded successfully"<<endl;
				continue;
				break;
			case 2:
				cout<<"Enter amount to withdraw:" << endl;
				cin>>amt;	
				cout<<"Enter pin:";
				cin>>pin;
				if ( !validate_input_type( pin, PIN_LEN ) ) {
					cout<<"Invalid entry!" << endl;
					continue;
				}
				if ( u1->validate_pin( pin ) ) {
					if ( u1->withdraw_cash(amt) )
						cout<<"Withdrawn successfully!" <<endl;
					else
						cout<<"Failed to withdraw! Retry" << endl;
				} else {
					cout<<"Invalid pin." << endl;
				}
				continue;
				break;
			case 3:
				cout<<"Enter current pin:"<<endl;
				cin>>pin;
				if ( !validate_input_type( pin, PIN_LEN) ) {
					cout<<"Invalid entry!" << endl; 
					continue;
				}
				if ( u1->validate_pin( pin ) ) {
					cout<<"Please enter new pin"<<endl;
					cin>>pin1;
					cout<<"Renter new pin"<<endl;
					cin>>pin2;
					if ( pin1 == pin2 )  {
						u1->change_pin( pin1 );
						cout<<"Pin changed successfully" << endl;
					} else {
						cout<<"Both pin numbers do not match!" << endl;
					}
				} else {
					cout<<"Invalid pin."<<endl;
				}
				continue;
				break;
			case 4: 
				cout<<"Enter pin: "<<endl;
				cin>>pin;		
				if ( !validate_input_type( pin, PIN_LEN ) ) {
					cout<<"Invalid entry!" << endl; 
					continue;
				}
				if ( u1->validate_pin( pin ) ) {
					cout<<"Available balance is "\
						<< u1->check_balance()\
						<< endl;
				} else {
					cout<<"Invalid pin." << endl;
				}
				continue;
				break;
			case 5:
				break;
			default:
				cout<<"Invalid option.. try again! "<< endl;
				continue;
				break;
		}
		break;
	}
	// Exit from atm state machine
	ac.state_change();
	delete u1;
}
