#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// Structure declaration
struct acc_type
{
    char bank_branch[20];
    char acc_holder_name[30];
    int age;
    int acc_number;
    char acc_holder_address[100];
    int phone_number;
    float available_balance;
};
struct acc_type account[20];
int num_acc;

void Create_new_account();
void Cash_Deposit();
void Cash_withdrawal();
void Account_information();
void Edit_Details();
void Log_out();
void Transfer_Funds();
void Check_Account_Balance();
void display_options();

/* main program */
int main()
{
    system("color 9");
    char option;
    num_acc = 0;
    while (1)
    {
        printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Welcome to the ABC Bank. Following are the banking services for you \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        display_options();
        printf("\nTo continue, please enter the number into the relevant options (1/2/3/4/5/6/7/8/9): ");
        option = getch();
        printf("%c \n", option);
        switch (option)
        {
        case '1':
            Create_new_account();
            break;
        case '2':
            Cash_Deposit();
            break;
        case '3':
            Cash_withdrawal();
            break;
        case '4':
            Account_information();
            break;
        case '5':
            Edit_Details();
            break;
        case '6':
            Transfer_Funds();
            break;
        case '7':
            Check_Account_Balance();
            break;
        case '8':
            return 0;
        case '9':
            system("cls");
            break;
        default:
            system("cls");
            printf("\nTo continue, please enter the number into the relevant options (1/2/3/4/5/6/7/8/9): \n ");
            break;
        }
    }
    return 0;
}

/*Function to display available options in this application*/
void display_options()
{
    printf("\n\t\t 1. Create new account \n");
    printf("\t\t 2. Cash Deposit \n");
    printf("\t\t 3. Cash withdrawal \n");
    printf("\t\t 4. Account information \n");
    printf("\t\t 5. Edit Details \n");
    printf("\t\t 6. Transfer Funds \n");
    printf("\t\t 7. Check Account Balance \n");
    printf("\t\t 8. Log out \n");
    printf("\t\t 9. Clear the screen and display available options\n");
}

/* Function to create new account */
void Create_new_account()
{
    char bank_branch[20];
    char acc_holder_name[30];
    int age;
    int acc_number;
    char acc_holder_address[100];
    int phone_number;
    float available_balance = 0;
    fflush(stdin);

    printf("\n\t\t\tCreate a New Account....\n\n");
    printf("New Account Details:");
    printf("\n\tEnter the bank branch            : ");
    scanf("%s", bank_branch);
    printf("\tEnter the account holder name    : ");
    scanf("%s", acc_holder_name);
    printf("\tEnter your age                   : ");
    scanf("%d", &age);
    printf("\tEnter the account number (1 to 10): ");
    scanf("%d", &acc_number);
    printf("\tEnter the account holder address : ");
    scanf("%s", acc_holder_address);
    printf("\tEnter your phone number          : ");
    scanf("%d", &phone_number);

    strcpy(account[acc_number - 1].bank_branch, bank_branch);
    strcpy(account[acc_number - 1].acc_holder_name, acc_holder_name);
    account[acc_number - 1].age = age;
    account[acc_number - 1].acc_number = acc_number;
    strcpy(account[acc_number - 1].acc_holder_address, acc_holder_address);
    account[acc_number - 1].phone_number = phone_number;
    account[acc_number - 1].available_balance = available_balance;

    printf("\nAccount has been created successfully. Thank you.\n\n");
    printf("\tBank branch            : %s \n", account[acc_number - 1].bank_branch);
    printf("\tAccount holder name    : %s \n", account[acc_number - 1].acc_holder_name);
    printf("\tAge                    : %d \n", account[acc_number - 1].age);
    printf("\tAccount number         : %d \n", account[acc_number - 1].acc_number);
    printf("\tAccount holder address : %s \n", account[acc_number - 1].acc_holder_address);
    printf("\tPhone number           : %d \n", account[acc_number - 1].phone_number);
    printf("\tAvailable balance      : %.2f \n", account[acc_number - 1].available_balance);
}

// Displaying account information
void Account_information()
{
    printf("\n\t\tAccount Details....\n\n");
    for (int i = 0; i < 20; i++)
    {
        if (strlen(account[i].bank_branch) > 0)
        {
            printf("Bank branch              : %s \n", account[i].bank_branch);
            printf("Account holder name      : %s \n", account[i].acc_holder_name);
            printf("Age                      : %d \n", account[i].age);
            printf("Account number           : %d \n", account[i].acc_number);
            printf("Account holder address   : %s \n", account[i].acc_holder_address);
            printf("Phone number             : %d \n", account[i].phone_number);
            printf("Available balance        : %.2f \n\n", account[i].available_balance);
        }
    }
}

// Function to deposit amount in an account
void Cash_Deposit()
{
    int acc_no;
    float add_money;
    printf("\n\t\t\tCash Deposit.....\n");
    printf("Enter account number: ");
    scanf("%d", &acc_no);
    printf("Current balance: %.2f \n", account[acc_no - 1].available_balance);
    printf("Deposit Amount: ");
    scanf("%f", &add_money);
    account[acc_no - 1].available_balance = account[acc_no - 1].available_balance + add_money;
    printf("New balance: %.2f \n", account[acc_no - 1].available_balance);
}

// Function to withdraw amount from an account
void Cash_withdrawal()
{
    int acc_no;
    float withdraw_money;
    float interest;
    printf("\n\t\t\tCash Withdrawal....\n");
    printf("\nEnter account number :");
    scanf("%d", &acc_no);
    printf("Final Deposit Amount: %.2f \n", account[acc_no - 1].available_balance);

    if (account[acc_no - 1].age > 60)
    {
        interest = account[acc_no - 1].available_balance * 0.1;
        printf("Interest: %.2f", interest);
    }
    else
    {
        interest = account[acc_no - 1].available_balance * 0.05;
        printf("Interest: %.2f", interest);
    }

    printf("\nAccount Balance: %.2f", account[acc_no - 1].available_balance + interest);
    printf("\nWithdraw Amount: ");
    scanf("%f", &withdraw_money);
    printf("\t\t Withdrawal Successful....! ");
    account[acc_no - 1].available_balance = (account[acc_no - 1].available_balance + interest) - withdraw_money;
    printf("\nNew balance: %.2f \n", account[acc_no - 1].available_balance);
}

// Function to update details of an account
void Edit_Details()
{
    int acc_number;
    char acc_holder_name[30];
    char acc_holder_address[100];
    int phone_number;
    fflush(stdin);

    printf("\n\t\t\tEdit Details....\n\n");
    printf("Enter the account number (1 to 10): ");
    scanf("%d", &acc_number);
    printf("Enter the account holder name to update   : ");
    scanf("%s", acc_holder_name);
    printf("Enter the account holder address to update : ");
    scanf("%s", acc_holder_address);
    printf("Enter your phone number to update          : ");
    scanf("%d", &phone_number);
    printf("\nSuccessfully...! Changed Your Following Account Details.\n\n");

    strcpy(account[acc_number - 1].acc_holder_name, acc_holder_name);
    strcpy(account[acc_number - 1].acc_holder_address, acc_holder_address);
    account[acc_number - 1].phone_number = phone_number;

    printf("\nAccount Has Been Updated Successfully. Thank You.\n\n");
    printf("\tBank branch            : %s \n", account[acc_number - 1].bank_branch);
    printf("\tAccount holder name    : %s \n", account[acc_number - 1].acc_holder_name);
    printf("\tAge                    : %d \n", account[acc_number - 1].age);
    printf("\tAccount number         : %d \n", account[acc_number - 1].acc_number);
    printf("\tAccount holder address : %s \n", account[acc_number - 1].acc_holder_address);
    printf("\tPhone number           : %d \n", account[acc_number - 1].phone_number);
    printf("\tAvailable balance      : %.2f \n", account[acc_number - 1].available_balance);
}

// Function to transfer funds between accounts
void Transfer_Funds()
{
    int from_acc_no, to_acc_no;
    float transfer_amount;
    printf("\n\t\t\tTransfer Funds....\n");
    printf("Enter your account number: ");
    scanf("%d", &from_acc_no);
    printf("Enter the account number to transfer to: ");
    scanf("%d", &to_acc_no);
    printf("Enter amount to transfer: ");
    scanf("%f", &transfer_amount);

    if (account[from_acc_no - 1].available_balance >= transfer_amount)
    {
        account[from_acc_no - 1].available_balance -= transfer_amount;
        account[to_acc_no - 1].available_balance += transfer_amount;
        printf("Transfer successful! New balance: %.2f \n", account[from_acc_no - 1].available_balance);
    }
    else
    {
        printf("Insufficient balance in your account for this transfer.\n");
    }
}

// Function to check account balance
void Check_Account_Balance()
{
    int acc_no;
    printf("\n\t\t\tCheck Account Balance....\n");
    printf("Enter your account number: ");
    scanf("%d", &acc_no);
    printf("Current balance: %.2f \n", account[acc_no - 1].available_balance);
}

// Function to log out (exit the application)
void Log_out()
{
    printf("\n\t\t\tLogging Out....\n");
    exit(0);
}
