#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Name: Itsuki Akiniwa
// Date: Feb 2 2025
// Course: 2107
// Assignment number: Lab03
// Project: ATM

float balance(float x, int *z){ // 1 (float nBalance, int nTransactions)
  printf("Your couurent balance is: %.2f\n", x);
  *z += 1; // add the number of transactions

  int nChoice;
  puts("Do you want a receipt?");
  puts("1. Yes");
  puts("2. No");
  printf("Enter your choice: ");
  scanf("%d", &nChoice);

  if(nChoice == 1){
    puts("Virtual receipt printed.");
  }
  else{
    puts("No receipt chosen");
  }
  puts("");
  return 0;
}

float withdrawal(float *x, int *y, int *z, int *a){ // 2 (float nBalance, int nTotalWithdraw, int nTransactions, int nInvalid)

  int nWithdraw;
  printf("Enter amount to withdraw (in multipuls of $20s,); ");
  scanf("%d", &nWithdraw);

  
  if(*y == 1000 || *y + nWithdraw > 1000){
    puts("The limit is $1000 a day");
    puts("");
    *a += 1;
    return 0;
  }else{
    if(nWithdraw % 20 != 0 || nWithdraw < 20){ // Check if multipuls of 20
        puts("This is invalid amount");
        puts("");
        *a += 1;
        return 0;
    }else{ // successful
        *x -= nWithdraw; // new Balance
        *y += nWithdraw; // caliculate the total amount of withdrawing
        printf("Please take your cash. Your new balance is: $%.2f\n", *x);

        *z += 1; // add the number of transactions
      }
  }

  int nChoice;
  puts("Do you want a receipt?");
  puts("1. Yes");
  puts("2. No");
  printf("Enter your choice: ");
  scanf("%d", &nChoice);

  if(nChoice == 1){
    puts("Virtual receipt printed.");
  }
  else{
    puts("No receipt chosen");
  }
  puts("");
  return 0;
}

float deposition(float *x, int *y, int *z, int *a){ // 3 (float nBalance, int nTotalDeposite, int nTransactions)
  
  int nDeposite;
  printf("Enter amount to depisite (dailiy limt $10000): ");
  scanf("%d", &nDeposite);

  
  if(*y == 10000 || *y + nDeposite > 10000 || nDeposite > 10000){
    puts("The limit is $10000 a day");
    puts("");
    *a += 1;
    return 0;
  }else{
    *x += nDeposite; // new Balance
    *y += nDeposite; // caliculate the total amount of Deposition
    printf("Deposite successful. Your new balance is: $%.2f", *x);

    *z += 1; // add the number of transactions
  }

  int nChoice;
  puts("Do you want a receipt?");
  puts("1. Yes");
  puts("2. No");
  printf("Enter your choice: ");
  scanf("%d", &nChoice);

  if(nChoice == 1){
    puts("Virtual receipt printed.");
  }
  else{
    puts("No receipt chosen");
  }
  puts("");
  return 0;
}

int quit(int *z){ // 4 (int nTransactions)
  puts("Thank you for using our ATM.");
  printf("You performed %d transaction(s).\n", *z);
  puts("Goodbye!");
  puts("");
  return 0;
}

int main(int argc, const char * argv[]) {

  float nBalance = 5000;
  int nPin;

  int nTotalWithdraw = 0; // This is for withdraw. In order to chaeck if the total amount of withdrawing does not exceed $1000 in a day
  int nTotalDeposit = 0; // For deposition
  int nTransactions = 0;
  int nInvalid = 0; // The number of invalid inputs

  puts("========================================");
  puts("\tWelcome to the ATM Machine");
  puts("========================================");

  printf("Please enter your 4-digit PIN: ");
  scanf("%d", &nPin);

  int nPinAttempts = 1; // The number of attempts for entering PIN 

  while (nPin != 3014)
  {
    if(nPinAttempts == 3){
      puts("");
      puts("Too many invalid attempts. Transaction canceled");
      exit(1);
    }else{
      nPinAttempts++;
      puts("");
      puts("This is not a valid PIN");
      puts("Try again");
      puts("");
      printf("Please enter your 4-digit PIN: ");
      scanf("%d", &nPin);
    }   
  }

  puts("PIN validation successful.");
  puts("");
  puts("ATM Main Menue:");
  puts("1. Check Balance");
  puts("2. Withdraw Cash");
  puts("3. Deposite Cash");
  puts("4. Quit");

  int nSelection;
  printf("Select an option: ");
  scanf("%d", &nSelection);
  puts("");

  while(nSelection != 4){
    if(nSelection == 1){
    balance(nBalance, &nTransactions);
    }else if(nSelection == 2){
    withdrawal(&nBalance, &nTotalWithdraw, &nTransactions, &nInvalid);
    }else{ // nSelection == 3
    deposition(&nBalance, &nTotalDeposit, &nTransactions, &nInvalid);
    }

    if(nInvalid != 3){
      puts("ATM Main Menue:");
      puts("1. Check Balance");
      puts("2. Withdraw Cash");
      puts("3. Deposite Cash");
      puts("4. Quit");
      printf("Select an option: ");
      scanf("%d", &nSelection);
      puts("");
    }else{
      puts("Because of three invalid inputs, this transaction was canceled.");
      puts("");
      exit(1);
    }
  }
    quit(&nTransactions);
    exit(0);
}




/*

- Define nBalance = 5000 and nPin = 3014

Function 1: Balance
Function 2: Cash Withdrawal
Function 3: Cash Deposition
Function 4: Quit
*/



