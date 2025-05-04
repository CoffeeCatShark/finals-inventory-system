#include <iostream>
#include <string>
using namespace std;
bool adminControl = false;
bool validUser = false;


class AccessStrategy{
	public: 
		virtual void displayAccess(const string& username) = 0;
		
		virtual ~AccessStrategy() {}
};

class AdminAccess : public AccessStrategy {
public:
    void displayAccess(const string& username) override {
        cout << "Access Granted" << endl;
        cout << "User: " << username << endl;
        cout << "Role: Admin" << endl;
    }
};

class EmployeeAccess : public AccessStrategy {
public:
    void displayAccess(const string& username) override {
        cout << "Access Granted" << endl;
        cout << "User: " << username << endl;
        cout << "Role: Employee" << endl;
    }
};



class User{
	private:
		AccessStrategy* access;
		string username;
		string password;
	public:
		User(string username_, string password_, AccessStrategy* access_) : username(username_), password(password_), access(access_){} 
		
	void displayAccess() {
		if(access){
			access->displayAccess(username); 
		}
	}
		
		string getName(){
			return username;
		}
		string getPassword(){
			return password;
		}
};


class AccountManager {
private:
    User* user;

public:
    void setUser(User* user_) {
        user = user_;
    }

    void displayUser() {
        if (user)
            user->displayAccess();
        else
            cout << "No user is currently logged in." << endl;
    }
};

AccessStrategy* adminAccess = new AdminAccess();
AccessStrategy* employeeAccess = new EmployeeAccess();

User* admin = new User("ADMIN", "ADMIN", adminAccess);
User* employee = new User("AAA", "AAA", employeeAccess);

AccountManager manager;

void login(){
string username;
string password;

	 cout<<"Enter Username: ";
	 getline(cin, username);
	 cout<<"Enter Password: ";
	 getline(cin, password);
		
		if(username == admin->getName() && password == admin->getPassword()){
			manager.setUser(admin);
			adminControl = true;
			validUser = true;
		}
		else if(username == employee->getName() && password == employee->getPassword()){
			manager.setUser(employee);
			validUser = true;
			
		}
		else{
			cout<<"Error: Username/Password is Incorrect."<<endl;
			return;
		}
				manager.displayUser();	
}

