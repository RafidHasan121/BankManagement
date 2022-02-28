#include <stdio.h>
#include <stdlib.h>
#define Max 9999


    typedef struct {
        char name[50];
        int AccNo;
        char AccType[50];
        int balance;
        } Account;


    void File2Mem (Account acc[]);
    void AddAcc(Account acc [], int x);
    int search(Account list[], int number);
    void ViewAcc(Account acc[]);
    void del(Account acc[]);

    int main (){
        int x,AccNo,index,choice;
        char y ;
        Account acc[Max];
        FILE *f = fopen("Masterfile.txt", "a+");
        while(1){
            printf ("\t\t\t\t\tWelcome To Bank Management System\n\n\n");
            printf ("Your Option's Are : \n\n\n");
            printf (" 1. Add Account \n");
            printf ("\n 2. View Account \n");
            printf ("\n 3. Delete Account\n");
            printf ("\n 4. Search Account Number\n");
            printf ("\n 5. Exit\n");
            printf ("\n Choose Corresponding Number (1-5)\n");
            scanf ("%d", &choice);

            switch (choice)
                {
            case 1:
            printf("Number of account to be added: ");
            scanf("%d", &x);
            int sumcount=0;
            FILE *fcnt = fopen("Counter.txt", "r");
            fscanf(fcnt, "%d", &sumcount);
            fclose(fcnt);
            sumcount = sumcount + x;
            FILE *fcnt2 = fopen("Counter.txt", "w");
            fprintf(fcnt2 , "%d", sumcount);
            fclose(fcnt2);
            AddAcc(acc,x);
            continue;

            case 2:
                ViewAcc(acc);
                continue;


            case 3:
                printf("Are you sure you want to delete whole record? (Y/N):\n");
                scanf("%s",&y);
                if(y == 'Y' || y == 'y'){
                    del (acc);
                    printf("Record Deleted Successfully!!\n\n");
                    }
                else if (y == 'N' || y=='n')
                    printf("Back To Menu:\n\n");

                else printf("INVALID INPUT\n\n");
                    continue;


            case 4:
                printf("Enter account number to search : ");
                scanf("%d", &AccNo);
                index = search(acc, AccNo);
                if (index == -1)
                {
                    printf("\t\t\t\t\t\tRecord not found!!\n\n ");
                }
                else
                {
                    printf("\n\nName: %s\nA/c Number: %d\nA/c Type %s\nBalance: %d\n\n",
                        acc[index].name, acc[index].AccNo, acc[index].AccType,
                        acc[index].balance);
                }
                continue;


            case 5: printf("\n\n\t\t\t\t\tThank You\n");
                    exit(0);

        }
     }
    fclose(f);
    }



    void File2Mem (Account acc[]){
        int i, counter;
        FILE *f = fopen("Counter.txt", "r");
        fscanf(f ,"%d", &counter);
        fclose(f);
        FILE *fp = fopen("Masterfile.txt", "r");
        for(i=0; i<counter; i++){
            if (feof(fp))
                break;
            else {
        fscanf(fp ,"%s", acc[i].name);
        fscanf(fp ,"%d" , &acc[i].AccNo);
        fscanf(fp ,"%s", acc[i].AccType);
        fscanf(fp ,"%d", &acc[i].balance);}}
        fclose(fp);
    }




    void AddAcc(Account acc [], int x){
        FILE *f = fopen("Masterfile.txt", "a+");
        int i;

        for(i=0; i<x; i++){
            printf("Account number %d", i+1);
                printf("\n Name: ");
                    scanf("%s^\n", acc[i].name);
                    fprintf (f, "%s\t", acc[i].name);
                printf("\n Account number: ");
                    scanf("%d", &acc[i].AccNo);
                    fprintf(f, "%d\t", acc[i].AccNo);
                printf("\n Account Type: ");
                    scanf("%s^\n", acc[i].AccType);
                    fprintf (f, "%s\t", acc[i].AccType);
                printf("\n Balance: ");
                    scanf("%d", &acc[i].balance);
                    fprintf(f, "%d\t\n", acc[i].balance);
                printf("\n\nAccount added successfully!!\n\n");
        }
        fclose(f);
    }


    int search(Account list[], int number)
{
        int i, counter, x=0;
        FILE *fp = fopen("Counter.txt", "r");
        fscanf(fp ,"%d", &counter);
        fclose(fp);
        File2Mem(list);


        for (i = 0; i<counter ; i++)
    {
            if (list[i].AccNo == number)
        {
                return i;
                break;
        }
            else x= -1 ;
    }
        return x;
    }

    void ViewAcc(Account acc[]){
        FILE *f = fopen ("Counter.txt", "r");
        int i, counter;
        int sum=0;
        float avg;
        fscanf(f,"%d", &counter);
        fclose(f);
        File2Mem(acc);
        for(i=0; i<counter; i++){
            sum = sum+acc[i].balance;
            printf("\n\nAccount number %d :", i+1);
            printf("\nName: %s", acc[i].name);
            printf("\nAccount number: %d", acc[i].AccNo);
            printf("\nAccount Type: %s", acc[i].AccType);
            printf("\nBalance: %d", acc[i].balance);
        }
        avg = (sum *1.0) / counter;
        printf("\n\n\n\t\t\tTotal Accounts:%d\n",counter);
        printf("\t\t\tTotal balance of all accounts: %d\n", sum);
        printf("\t\t\tAverage Balance: %f\n\n", avg);
    }

    void del(Account acc[]){
        remove("Masterfile.txt");
        remove("Counter.txt");
        FILE *f1 = fopen("Masterfile.txt", "w");
        fclose(f1);
        FILE *f2 = fopen("Counter.txt", "w");
        fprintf(f2, "%d",0);
        fclose(f2);
    }
