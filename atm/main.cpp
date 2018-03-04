#include "atm.h"
#include "accounts.h"
#include "users.h"
using namespace std;
#include "iostream"
#include "list"

int main()
{
	// For this instance of program following are the assumed users:
	// Ideally this is on server and retrieved based on the card insered.
	account a1, a2, a3;
	int option, req_account_no;
	bool acc_found = false;

	a1.set_no( 1 );
	a1.set_balance( 1000 );
	a1.set_pin( 1234 );

	a2.set_no( 2 );
	a2.set_balance( 1000 );
	a2.set_pin( 1234 );
	
	a3.set_no( 3 );
	a3.set_balance( 1000 );
	a3.set_pin( 1234 );
	
	// Build list of created accounts..
	std::list<account> list_accs;	
	list_accs.push_back(a1);
	list_accs.push_back(a2);
	list_accs.push_back(a3);
	
	// Iterate through accounts list to pick the choosen account for the current 
	// transaction 
	std::list<account>::iterator iter;
	while ( 1 ) {
		std::cout<<"Welcome!" << endl\
			<<"Please insert card(Just insert account no to proceed for now)"\
			<< endl;
		cin>>req_account_no;	
		for ( iter = list_accs.begin(); iter != list_accs.end(); iter++ ) {
			if (  (*iter).get_no() == req_account_no ) {
				acc_found = true;
				break;
			}
		}
		if ( acc_found ) 
			break;
	}
	account *cur_acc;
	cur_acc = &(*iter);
	//cout<<cur_acc->get_balance();	
	users *u1 = new users;
	u1->fill_account_details(cur_acc);

	atm atm_instance;
	int amt, pin;
	while ( 1 ) {
		cout<<"===================================================================="\
			<<endl;
		atm_instance.display_menu();
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
				int pin1,pin2; 
				cout<<"Enter current pin:"<<endl;
				cin>>pin;
				if ( u1->validate_pin( pin ) ) {
					cout<<"Please enter new pin"<<endl;
					cin>>pin1;
					cout<<"Renter new pin"<<endl;
					cin>>pin2;
					if ( pin1 == pin2 ) {
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
	//std::cout<<iter->get_no();
	delete u1;
	//atm_instance.
}
