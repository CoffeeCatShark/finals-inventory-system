#include <iostream>
#include <string>
#include <ctime>
#include "AccessControl.h"
#include "Inventory.h"

using namespace std;
//readyItem() TO READY ADDING AN ITEM
//inventory.deleteItem()
//inventory.listItem()


bool menu(){
		while(!validUser){
		login();
	}
string input;	
	cout<<"INVENTORY MANAGEMENT SYSTEM"<<endl;
	cout<<"=================================="<<endl;
	cout<<"[0]\tExit Program"<<endl;
	cout<<"[1]\tView Inventory"<<endl;
	cout<<"[2]\tUpdate Item Quantities"<<endl;
	cout<<"[3]\tRemove Item Quantities"<<endl;
	if(adminControl == true){
	cout<<"[4]\tAdd New Items"<<endl;
	cout<<"[5]\tDelete Items from Inventory"<<endl;
	cout<<"[6]\tPrint Current Inventory"<<endl;
	}
	cout<<"Input: ";
	int _input = exceptionHandle();
	
	if(adminControl == false){
	switch (_input){
		case 0: 
		return false;
		
		break;
		case 1: inventory.listItem();
		
		break;
		case 2: 
		cout<<"Input Name of ID: ";
		getline(cin,input);
		inventory.addQuantity(input);
		
		break;
		case 3:
		cout<<"Input Name of ID: ";
		getline(cin,input);
		inventory.removeItem(input);
		
		break;
		default: cout<<"BUFFER"<<endl;
	}
}
	if(adminControl == true){
		switch (_input){
		case 0: 
		return false;
		
		break;
		case 1: inventory.listItem();
		
		break;
		case 2: 
		cout<<"Input Name of ID: ";
		getline(cin,input);
		inventory.addQuantity(input);
		
		break;
		case 3:
		cout<<"Input Name of ID: ";
		getline(cin,input);
		inventory.removeItem(input);
		
		break;
		case 4: 
		readyItem();
		
		break;
		case 5:
		deleteConfirm();
		
		break;
		case 6: inventory.printReceipt();
				cout<<"Inventory Receipt Printed."<<endl;
		
		
		break;
		default: cout<<"BUFFER"<<endl;
	}
	}
return true;
}

int main(){
	
	
	inventory.initializeInventory();
	
	bool isRunning = true;
	while(isRunning){
		isRunning = menu();
	}
	
	inventory.saveInventory();
	
	delete admin;
	delete employee;
	delete adminAccess;
	delete employeeAccess;
	return 0;
}