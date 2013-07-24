class account():
    """ This is a class that defines bank accounts
    """
    MIN_DEPOSIT_AMOUNT=1.00
    MIN_INITIAL_BALANCE_AMT=10.00
    account_number=""
    opening_branch=""
    balance=0.0
    accountholder=""
    def __init__(self,**kwargs):
        self.account_number = kwargs["account_number"]
        self.opening_branch = kwargs["opening_branch"]
        if (kwargs["opening_balance"] < self.MIN_INITIAL_BALANCE_AMT):
            return(False)
        self.balance=kwargs["opening_balance"]
        self.accountholder=kwargs["account_holder"]
    def deposit(self,deposit_amount):
        if (deposit_amount < self.MIN_DEPOSIT_AMOUNT):
            return(False)
        self.balance = self.balance + deposit_amount
        return (True)
    def withdraw(self,withdrawal_amount):
        if (self.balance - withdrawal_amount > 0):
            self.balance = self.balance - withdrawal_amount
        else:
            return(False)
        return(True)
    def getbalance(self):
        return(self.calculate_balance())
    def calculate_balance(self):
        return(self.balance)

class current_account(account):
    overdraft=0.0
    MINIMUM_OVERDRAFT_LIMIT=500
    def __init__(self,**kwargs):
        try:
            self.overdraft = kwargs["initial_overdraft"]
        except KeyError:
            self.overdraft = self.MINIMUM_OVERDRAFT_LIMIT
        finally:
            account.__init__(self,**kwargs)
    def setOverdraftLimit(self,amount_to_increase):
        try:
           self.overdraft = self.overdraft + amount_to_increase
        except TypeError:
            return(False)
        return(True)
    def getOverdraftLimit(self):
        return(self.overdraft)



class savings_account(account):
    interest_rate=0.0
    MINIMUM_INTEREST_RATE=0.04
    def __init__(self,**kwargs):
        try:
            self.interest_rate = kwargs["interest_rate"]
        except KeyError:
            self.interest_rate = self.MINIMUM_INTEREST_RATE
        finally:
            account.__init__(self,**kwargs)
    def calculate_new_balance(self):
        self.balance = self.balance + self.balance * self.interest_rate
