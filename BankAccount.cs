using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp1
{
    public class BankAccount
    {
        public string Owner { get; set; }
        public Guid AccountNumber { get; set; }

        public decimal Balance { get;  private set; }

        public BankAccount(string Name) 
        {
            Owner = Name;
            AccountNumber = Guid.NewGuid();
            Balance = 0;
            
        }

        public string Deposite(decimal BalanceAmount)
        {
            if (BalanceAmount <= 0)
            {
                return "You can not not deposite $" + BalanceAmount;
            }
            if (BalanceAmount > 2000)
            {
                return "AML Deposite Limit Reached.";
            }

            Balance += BalanceAmount;

            return "Deposite Completed Successfully";
        }


        public string Withdraw(decimal BalanceAmount)
        {
            if (BalanceAmount <= 0)
            {
                return "You can not not withdraw $" + BalanceAmount;
            }
            if (BalanceAmount > Balance)
            {
                return "You do not have enough money.";
            }

            Balance -= BalanceAmount;

            return "Withdraw Completed Successfully";
        }
    }
}
