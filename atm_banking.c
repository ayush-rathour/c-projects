#include <stdio.h>

int main()
{
    // Variable declaration
    int ipin, epin, npin, opt;
    float balance, deposit, withdraw;

    // Initial account details
    ipin = 1234;
    balance = 5000;

    // Display ATM menu
    printf("========== ATM ==========\n"
           "1. Check Balance\n"
           "2. Deposit Money\n"
           "3. Withdraw Money\n"
           "4. Change PIN\n"
           "5. Mini Statement\n"
           "6. Exit\n\n"
           "Enter your choice: ");

    scanf("%d", &opt);

    // Ask for PIN before performing any operation
    printf("Enter the Current PIN: ");
    scanf("%d", &epin);

    // Perform operation according to user's choice
    switch (opt)
    {
    // Check account balance
    case 1:
        if (ipin == epin)
        {
            printf("\n=== Check Balance ===\n");
            printf("Your Balance is: %.2f\n", balance);
        }
        else
        {
            printf("Invalid PIN, Access Denied!\n");
        }

        break;

    // Deposit money
    case 2:
        if (ipin == epin)
        {
            printf("\n=== Deposit Money ===\n");
            printf("Enter the amount you want to deposit: ");
            scanf("%f", &deposit);

            // Deposit amount must be greater than zero
            if (deposit > 0)
            {
                balance += deposit;

                printf("Deposit Successful!\n");
                printf("Your New Balance is: %.2f\n", balance);
            }
            else
            {
                printf("Deposit amount must be greater than 0.\n");
            }
        }
        else
        {
            printf("Invalid PIN, Access Denied!\n");
        }

        break;

    // Withdraw money
    case 3:
        if (ipin == epin)
        {
            printf("\n=== Withdraw Money ===\n");
            printf("Enter the amount you want to withdraw: ");
            scanf("%f", &withdraw);

            // Withdrawal must be positive and within available balance
            if (balance >= withdraw && withdraw > 0)
            {
                balance -= withdraw;

                printf("Withdrawal Successful!\n");
                printf("Your New Balance is: %.2f\n", balance);
            }
            else
            {
                printf("Insufficient Balance or Invalid Amount!\n");
            }
        }
        else
        {
            printf("Invalid PIN, Access Denied!\n");
        }

        break;

    // Change PIN
    case 4:
        if (ipin == epin)
        {
            printf("\n=== Change PIN ===\n");
            printf("Enter the New PIN: ");
            scanf("%d", &npin);

            // Update the current PIN
            ipin = npin;

            printf("PIN Updated Successfully!\n");
        }
        else
        {
            printf("Invalid PIN, Access Denied!\n");
        }

        break;

    // Display mini statement
    case 5:
        if (ipin == epin)
        {
            printf("\n=== Mini Statement ===\n");
            printf("Current Balance : %.2f\n"
                   "Account PIN     : ****\n"
                   "Account Status  : Active\n",
                   balance);
        }
        else
        {
            printf("Invalid PIN, Access Denied!\n");
        }

        break;

    // Exit the ATM
    case 6:
        printf("\n=== Exit ===\n");
        printf("Thank you for using our ATM.\n");

        break;

    // Handle invalid menu options
    default:
        printf("Invalid option!\n");

        break;
    }

    return 0;
}