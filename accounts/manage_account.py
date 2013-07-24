#!/usr/bin/env python

import sys
from account_classes import account,current_account,savings_account

account_dictionary = {}
function_dictionary = {}
def create_current_account():
    a_id = raw_input("Please enter the account id")
    while (1):
        try:
            a_balance = float(raw_input("Please enter the initial balance: "))
        except ValueError:
            print "Invalid balance"
            continue
        if (a_balance == -1):
            return(False)
    ah_name=raw_input("Please enter the account holders name")
    while (1):
        try:
            a_overdraft = float(raw_input("Please enter the initial overdraft: "))
        except ValueError:
            print "Invalid overdraft"
           continue
        if (a_overdraft = -1):
            return(False)
        ob = raw_input("Please enter the opening branch: ")
        cur_obj = current_account(account_id = a_id, account_holder = ah_name,opening_balance=ob,initial_overdraft=a_overdraft,opening_branch=ob)
        account_dictionary[a_id] = cur_obj

    cur_acct = current_account(
def create_savings_account():
    pass
def add_account():
        a_id = raw_input("Please enter the account id: ")
        if not account_dictionary[a_id]:
            print "error"
            return(False)
        try:
            deposit_amt = float(raw_input("Enter the amount to deposit: "))
        except ValueError:
            print "Invalid deposit amount"
            return(False)
        if (deposit_amt < -0):
            print "Invalid deposit amount"
            return(False)
        account_dictionary[a_id].deposit(deposit_amt)
        return(True)


    pass
def subtract_account():
    pass
def exit_routine():
    try:
        f = open("account_output.dat","wb+")
    except IOError,err:
        print "ERROR: ",str(err)
        sys.exit(1)
    pickle.dump(account_dictionary,f)
    sys.exit(0)

def initialize():
    try:
        f = open("account_output.dat","rb")
    except IOError,err:
        print "ERROR: ",str(err)
        sys.exit(1)
    account_dictionary = pickle.load(f)
    function_dictionary={1:create_current_account,2:create_savings_account,3:add_account,4:subtract_account,5:view_account,6:exit_routine)




while (1):
    print "Press 1. To create a Current Account"
    print "Press 2. To create a Savings Accoungt"
    print "Press 3. To add to account"
    print "Press 4. To subtract from account"
    print "Press 5. To view account details"
    print "Press 6. To exit"
    input = int(raw_input())
    function_dictionary[input]()

