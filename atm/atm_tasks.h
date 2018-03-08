#ifndef  _atm_tasks_h
#define _atm_tasks_h
class atm_tasks_interface {
	public:
		virtual void display_menu()  = 0;
		virtual bool validate_card() = 0;
		virtual bool print_receipt() = 0;
};
#endif
