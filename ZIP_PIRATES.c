#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<conio.h>

void gotoxy();
void reg_sys();
void login_sys();
void CONTACT_MANGEMENT_SYS();
void MAIN_LOGIN_SYS();
void NUMBER_CONV();
void BIN_TO_ALL();
void DEC_TO_ALL();
void OCT_TO_ALL();
void HEX_to_ALL();
void HEX_to_bin();
void HEX_TO_DEC();
void HEX_TO_OCT();
void BIN_TO_DEC();
void BIN_TO_OCT();
void BIN_TO_HEX();
void OCT_TO_BIN();
void OCT_TO_DEC();
void OCT_TO_HEX();

void gotoxy(int r,int n)
{
    COORD a;
    a.X=r;
    a.Y=n;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);

}
void MAIN_LOGIN_SYS()
{
    system("COLOR 0A");
    int n;
    gotoxy(65,13);
    printf("LOGIN TO ENTER");
    gotoxy(65,14);
    printf("------------------------");
    gotoxy(64,16);
    printf("1.register");
    gotoxy(64,17);
    printf("2.login");
    gotoxy(64,19);
    printf("Enter choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        reg_sys();
        system("cls");
        gotoxy(65,8);
        printf("Write your valid password and username To Enter");
        login_sys();
        break;
    case 2:
        login_sys();
        break;
    case 3:
        gotoxy(65,8);
        printf("\nThank you........");
        break;
    default:
        gotoxy(65,9);
        printf("Wrong input");
    }

}

struct login
{
    char username[100];
    char password[100];
    char fname[100];
    char lname[100];
};

void reg_sys()
{
    system("CLS");
    system("COLOR 0A");
    FILE *log;
    log = fopen("login.txt","w");
    struct login l;

    printf("\n\n\t\t\t\t\t\t\tEnter your first name: ");
    scanf("%s",&l.fname);
    printf("\n\n\t\t\t\t\t\t\tEnter your last name: ");
    scanf("%s",&l.lname);
    printf("\n\n\t\t\t\t\t\t\tEnter username: ");
    scanf("%s",&l.username);
    printf("\n\n\t\t\t\t\t\t\tEnter password: ");
    scanf("%s",&l.password);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\n\n\t\t\t\t\t\t\tYour username is your userID\n");
    printf("\n\n\t\t\t\t\t\t\tYour password is your user Password\n");
    printf("\n\n\t\t\t\t\t\t\tEnter with those information\n");
    printf("\n\n\t\t\t\t\t\t\tPress any key to continue");
    getch();
    system("CLS");


};
void login_sys()
{
    system("CLS");
    system("COLOR 0A");
    char username[100],password[100];
    FILE *log;
    log = fopen("login.txt","r");
    struct login l;
    printf("\n\n\t\t\t\t\t\t\tEnter userID: ");
    scanf("%s",&username);
    printf("\n\n\t\t\t\t\t\t\tEnter password: ");
    scanf("%s",&password);
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0 )
        {
            printf("\n\n\t\t\t\t\t\t\tlogin successfull\n\n\n");
        }
        else if(strcmp(username,l.username) !=1)
        {
            printf("\n\n\t\t\t\t\t\t\tWrong username");
        }
        else if(strcmp(password,l.password) !=1)
        {
            printf("\n\n\t\t\t\t\t\t\tWrong password");
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\tWrong input");
        }
    }
    fclose(log);

};
void HEX_to_bin()
{
    system("cls");
    char hex[17], bin[65] = "";
    int i = 0;


    printf("\n\n\t\t\t\t\t\t\tEnter any hexadecimal number: ");
    scanf("%s",&hex);


    for(i=0; hex[i]!='\0'; i++)
    {
        switch(hex[i])
        {
        case '0':
            strcat(bin, "0000");
            break;
        case '1':
            strcat(bin, "0001");
            break;
        case '2':
            strcat(bin, "0010");
            break;
        case '3':
            strcat(bin, "0011");
            break;
        case '4':
            strcat(bin, "0100");
            break;
        case '5':
            strcat(bin, "0101");
            break;
        case '6':
            strcat(bin, "0110");
            break;
        case '7':
            strcat(bin, "0111");
            break;
        case '8':
            strcat(bin, "1000");
            break;
        case '9':
            strcat(bin, "1001");
            break;
        case 'a':
        case 'A':
            strcat(bin, "1010");
            break;
        case 'b':
        case 'B':
            strcat(bin, "1011");
            break;
        case 'c':
        case 'C':
            strcat(bin, "1100");
            break;
        case 'd':
        case 'D':
            strcat(bin, "1101");
            break;
        case 'e':
        case 'E':
            strcat(bin, "1110");
            break;
        case 'f':
        case 'F':
            strcat(bin, "1111");
            break;
        default:
            printf("Invalid hexadecimal input.");
        }
    }

    printf("\n\n\t\t\t\t\t\t\tHexademial number = %s\n", hex);
    printf("\n\n\t\t\t\t\t\t\tBinary number = %s\n", bin);
    gotoxy(65,20);
    printf("Press any key\n");
    getch();
    system("cls");

}
void HEX_TO_DEC()
{
    system("cls");
    int number;
    printf("\n\n\t\t\t\t\t\t\t\t\tHexadecimal to decimal\n\t\t\t\t\t\t\t\t\t----------------------\n\n");
    printf("\n\n\t\t\t\t\t\t\tEnter hexadecimal number=");
    scanf("%x",&number);
    printf("\n\n\t\t\t\t\t\t\tDecimal number=%d",number);
    gotoxy(65,15);
    printf("Press any key\n");
    getch();
    system("cls");
}
void HEX_TO_OCT()
{

    system("cls");
    int number;
    printf("\n\n\t\t\t\t\t\t\t\t\tHexadecimal to Octal\n\t\t\t\t\t\t\t\t\t--------------------\n\n");
    printf("\n\n\t\t\t\t\t\t\tEnter hexadecimal number=");
    scanf("%x",&number);
    printf("\n\n\t\t\t\t\t\t\toctal number=%o",number);
    gotoxy(65,15);
    printf("Press any key\n");
    getch();
    system("cls");

}
void HEX_to_ALL()
{
    system("COLOR 0A");
    int input;
    while(input!=4)
    {
        gotoxy(65,8);
        printf("Hexadecimal conversion");
        gotoxy(65,9);
        printf("________________________");
        gotoxy(62,15);
        printf("1.Hexadecimal to binary");
        gotoxy(62,16);
        printf("2.Hexadecimal to Decimal");
        gotoxy(62,17);
        printf("3.Hexadecimal to Octal");
        gotoxy(62,18);
        printf("4.Exit");
        gotoxy(62,19);
        printf("Enter your choice: ");
        scanf("%d",&input);
        switch(input)
        {
        case 1:
            system("cls");
            HEX_to_bin();
            break;
            system("cls");
        case 2:
            system("cls");
            HEX_TO_DEC();
            break;
            system("cls");
        case 3:
            system("cls");
            HEX_TO_OCT();
            break;
            system("cls");
        case 4:
            system("cls");
            gotoxy(65,12);
            printf("Thanks\n");
            system("cls");
        }

    }

}
void DEC_TO_ALL()
{
    system("cls");
    system("COLOR 0A");
    int number1,number2,n1,n,i,j, binno=0,dn;
    while(n1!=4)
    {
        gotoxy(65,10);
        printf("Decimal conversion");
        gotoxy(65,11);
        printf("________________________");
        gotoxy(62,15);
        printf("1.Decimal to Octal");
        gotoxy(62,16);
        printf("2.Decimal to Hexadecimal");
        gotoxy(62,17);
        printf("3.Decimal to Binary");
        gotoxy(62,18);
        printf("4.Exit");
        gotoxy(62,19);
        printf("Enter your choice: ");
        scanf("%d",&n1);

        switch(n1)
        {
        case 1:
            system("cls");
            gotoxy(65,4);
            printf("Convert Decimal to octal: ");
            gotoxy(65,5);
            printf("---------------------------------\n");
            gotoxy(65,7);
            printf("Decimal Number = ");
            scanf("%d",&number1);
            number1=("%o",number1);
            gotoxy(65,8);
            printf("The octal number is %o", number1);
            getch();
            system("cls");
            break;
        case 2:
            system("cls");
            gotoxy(65,4);
            printf("Convert Decimal to hexadecimal: ");
            gotoxy(65,5);
            printf("--------------------------------");
             gotoxy(65,7);
            printf("Decimal Number = ");
            scanf("%d",&number2);
            number2=("%x",number2);
            gotoxy(65,8);
            printf("The Hexadecimal number is %x", number2);
            getch();
            system("cls");
            break;
        case 3:
            system("cls");
            gotoxy(65,4);
            printf("Convert Decimal to Binary: ");
            gotoxy(65,5);
            printf("---------------------------------");
            gotoxy(65,7);
            printf("Enter a number to convert : ");
            scanf("%d",&n);

            dn=n;
            i=1;

            for(j=n; j>0; j=j/2)
            {
                binno=binno+(n%2)*i;
                i=i*10;
                n=n/2;
            }

            gotoxy(65,8);
            printf("The Binary number of %d is %d.",dn,binno);
            getch();
            system("cls");
            break;


        default:
            printf("\t\t\t\tWrong input");
            system("cls");

        }
    }
    gotoxy(65,10);
    printf("Press any key\n");
    getch();
    system("CLS");

}
void BIN_TO_DEC()
{
    system("cls");
    long int i,n,x=0,a;
    printf("\n\n\t\t\t\t\t\t\tEnter any binary number: ");
    scanf("%d",&n);
    printf("\n\n\t\t\t\t\t\t\tThe decimal value %d is ",n);

    for(i=0; n!=0; ++i)
    {
        a=n%10;
        x=(a)*(pow(2,i))+x;
        n=n/10;
    }

    printf("%d",x);
    gotoxy(65,10);
    printf("Press any key\n");
    getch();
    system("cls");
}
void BIN_TO_OCT()
{
    system("cls");
    int n1, n,p=1;
    int dec=0,i=1,j,d;
    int ocno=0,dn;

    printf("\n\n\t\t\t\t\t\t\tEnter a binary number :");
    scanf("%d",&n);
    n1=n;
    for (j=n; j>0; j=j/10)
    {
        d = j % 10;
        if(i==1)
            p=p*1;
        else
            p=p*2;

        dec=dec+(d*p);
        i++;
    }

    /*--------------------------------------------*/
    dn=dec;
    i=1;

    for(j=dec; j>0; j=j/8)
    {
        ocno=ocno+(j % 8)*i;
        i=i*10;
        n=n/8;
    }

    printf("\n\n\t\t\t\t\t\t\tThe Binary Number : %d\n\n\t\t\t\t\t\t\tThe equivalent Octal  Number : %d \n\n",n1,ocno);
    gotoxy(65,10);
    printf("Press any key\n");
    getch();
    system("cls");
}


void BIN_TO_HEX()
{
    system("cls");
    long int binary, hexadecimal = 0, i = 1, remainder;

    printf("\n\n\t\t\t\t\t\t\tEnter the binary number: ");
    scanf("%ld", &binary);
    while (binary != 0)
    {
        remainder = binary % 10;
        hexadecimal = hexadecimal + remainder * i;
        i = i * 2;
        binary = binary / 10;
    }
    printf("\n\n\t\t\t\t\t\t\thexadecimal value is: %lX", hexadecimal);
    gotoxy(65,10);
    printf("Press any key\n");
    getch();
    system("cls");

}
void BIN_TO_ALL()
{
    int n;
    system("COLOR 0b");
    while(n!=4)
    {
        gotoxy(65,8);
        printf("Binary conversion");
        gotoxy(65,9);
        printf("________________________");
        gotoxy(62,15);
        printf("1.Binary to Decimal");
        gotoxy(62,16);
        printf("2.Binary to Octal");
        gotoxy(62,17);
        printf("3.Binary to Hexadecimal");
        gotoxy(62,18);
        printf("4.Exit");
        gotoxy(62,19);
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\tConvert Binary to decimal\n ");
            printf("\t\t\t\t\t\t---------------------------------\n");
            BIN_TO_DEC();
            system("cls");
            break;
        case 2:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\tConvert Binary to octal\n ");
            printf("\t\t\t\t\t\t---------------------------------\n");
            BIN_TO_OCT();
            system("cls");
            break;
        case 3:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\ttConvert Binary to hexadecimal\n ");
            printf("\t\t\t\t\t\t---------------------------------\n");
            BIN_TO_HEX();
            system("cls");
            break;
        case 4:
            printf("\n\t\t\t\t\t\t\tprogramme terminated!!\n\n");
            gotoxy(65,10);
            printf("Press any key\n");
            system("CLS");
            break;
        default:
            printf("\n\t\t\t\t\t\t\tWrong input!!");
            gotoxy(65,10);
            printf("Press any key\n");
            getch();
            system("CLS");
        }
    }


}
void OCT_TO_DEC()
{
    system("cls");
    int number;
    gotoxy(65,4);
    printf("Octal to Decimal");
    gotoxy(65,5);
    printf("------------------");
    gotoxy(65,7);
    printf("Enter Octal number = ");
    scanf("%o",&number);
    gotoxy(65,8);
    printf("Decimal number=%d",number);
    gotoxy(65,15);
    printf("Press any key\n");
    getch();
    system("cls");
}
void OCT_TO_HEX()
{
    system("cls");
    int number;
    gotoxy(65,4);
    printf("Octal to Hexadecimal");
    gotoxy(65,5);
    printf("--------------------");
    gotoxy(65,7);
    printf("Enter Octal number=");
    scanf("%o",&number);
    gotoxy(65,8);
    printf("Hexadecimal number=%x",number);
    gotoxy(65,20);
    printf("Press any key\n");
    getch();
    system("cls");
}
void OCT_TO_BIN()
{
    system("cls");
    char oct[17], bin[65] = "";
    int i = 0;
    gotoxy(65,4);
    printf("Octal to binary");
    gotoxy(65,5);
    printf("------------------");
    gotoxy(65,7);
    printf("Enter any octal number: ");
    scanf("%s",&oct);

    for(i=0; oct[i]!='\0'; i++)
    {
        switch(oct[i])
        {
        case '0':
            strcat(bin, "000");
            break;
        case '1':
            strcat(bin, "001");
            break;
        case '2':
            strcat(bin, "010");
            break;
        case '3':
            strcat(bin, "011");
            break;
        case '4':
            strcat(bin, "100");
            break;
        case '5':
            strcat(bin, "101");
            break;
        case '6':
            strcat(bin, "110");
            break;
        case '7':
            strcat(bin, "111");
            break;
        default:
            printf("Invalid octal input.");
        }
    }
    gotoxy(65,8);
    printf("Binary number = %s\n", bin);
    gotoxy(65,20);
    printf("Press any key\n");
    getch();
    system("cls");
}
void OCT_TO_ALL()
{
    int n;
    system("COLOR 0b");
    while(n!=4)
    {
        gotoxy(65,8);
        printf("Octal conversion");
        gotoxy(65,9);
        printf("___________________");
        gotoxy(62,15);
        printf("1.Octal to Binary");
        gotoxy(62,16);
        printf("2.Octal to Decimal");
        gotoxy(62,17);
        printf("3.Octal to Hexadecimal");
        gotoxy(62,18);
        printf("4.Exit");
        gotoxy(62,19);
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\tConvert Octal to Binary\n ");
            printf("\t\t\t\t\t\t---------------------------------\n");
            OCT_TO_BIN();
            break;
            getch();
            system("cls");
        case 2:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\tConvert Octal to Decimal\n ");
            printf("\t\t\t\t\t\t---------------------------------\n");
            OCT_TO_DEC();
            break;
            getch();
            system("cls");
        case 3:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\ttConvert Octal to hexadecimal\n ");
            printf("\t\t\t\t\t\t---------------------------------\n");
            OCT_TO_HEX();
            break;
            getch();
            system("cls");
        case 4:
            system("cls");
        default:
            printf("\n\t\t\t\t\t\t\tWrong input!!");
            gotoxy(65,10);
            printf("Press any key\n");
            getch();
            system("cls");
        }
    }


}
void NUMBER_CONV()
{
    int n;
    while(n!=5)
    {
        gotoxy(65,8);
        printf("NUMBER CONVERSION\n");
        printf("\t\t\t\t\t\t\t---------------------------------\n\n\n\n");
        printf("\t\t\t\t\t\t\tWhich conversion you wanna do?\n");
        printf("\t\t\t\t\t\t\t[1] Binary conversion\n");
        printf("\t\t\t\t\t\t\t[2] Decimal conversion\n");
        printf("\t\t\t\t\t\t\t[3] Octal conversion\n");
        printf("\t\t\t\t\t\t\t[4] Hexadecimal conversion\n");
        printf("\t\t\t\t\t\t\t[5] Exit\n");
        printf("\t\t\t\t\t\t\tEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            system("cls");
            BIN_TO_ALL();
            break;
            system("cls");
        case 2:
            system("cls");
            DEC_TO_ALL();
            break;
            system("cls");
        case 3:
            system("cls");
            OCT_TO_ALL();
            break;
            system("cls");
        case 4:
            system("cls");
            HEX_to_ALL();
            break;
            system("cls");
        case 5:
            system("cls");
            printf("\n\n\t\t\t\t\t\t\tProgramme terminated!!\n\t\t\t\t\t\t\tThanks");
            gotoxy(65,10);
            printf("Press any key\n");
            getch();
            system("cls");
        }
    }
}
void Add_contact()
{
    char name[500],Address[500];
    int number,n,i;
    FILE *file;
    file = fopen("contact.txt","a");
    if(file==NULL)
    {
        gotoxy(40,10);
        printf("File not found");

    }
    else
    {

        printf("\n\n\t\t\t\t\t\t\tWrite valid name,number to add contact\n");
        printf("\n\n\t\t\t\t\t\t\tHow many contact you wanna add: ");
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            printf("\n\n\t\t\t\t\t\t\tEnter the name: ");
            scanf("%s",&name);
            printf("\t\t\t\t\t\t\tEnter the number: ");
            scanf("%d",&number);
            printf("\t\t\t\t\t\t\tEnter the address: ");
            scanf("%s",&Address);
            fprintf(file,"\t\t\t\t\t\t\t  Name:%s\n\t\t\t\t\t\t\t  Number:%d\n\t\t\t\t\t\t\t  Address:%s\n",name,number,Address);
            fprintf(file,"\t\t\t\t\t\t\t-------------------------------\n");
            fprintf(file,"\t\t\t\t\t\t\t-------------------------------\n");
        }

    }
    fclose(file);
    system("CLS");
}

void show_contact()
{
    system("CLS");
    char ch;
    FILE *file;
    file=fopen("contact.txt","r");
    if(file==NULL)
    {
        gotoxy(40,10);
        printf("\t\t\t\t\t\t\tFile not found");

    }
    else
    {
        printf("\n\t\t\t\t\t\t\tALL CONTACT LIST\n\n\n");
        while(!feof(file))
        {
            ch = fgetc(file);
            printf("%c",ch);
        }
        fclose(file);
    }

}
void CONTACT_MANGEMENT_SYS()
{
    int n;
    gotoxy(65,4);
    printf("\CONTACT MANAGEMENT SYSTEM");
    gotoxy(65,5);
    printf("_______________________________\n");
    while(n!=3)
    {
        printf("\n\n\t\t\t\t\t\t\t[1].Add conatct\n");
        printf("\t\t\t\t\t\t\t[2].View all conatct\n");
        printf("\t\t\t\t\t\t\t[3].Exit\n");
        printf("\t\t\t\t\t\t\tEnter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            system("cls");
            system("COLOR 0B");
            Add_contact();
            break;
            system("cls");
            gotoxy(65,5);
            printf("Contact added successfully\n");
            printf("Press any key to continue");
            getch();
        case 2:
            system("cls");
            system("COLOR 0f");
            show_contact();
            break;
            gotoxy(65,10);
            printf("Press any key\n");
            getch();
            system("cls");
        case 3:
            system("cls");
            system("COLOR 0A");
            printf("\n\n\t\t\t\t\t\t\tProgrsmme terminated!!\n\n\t\t\t\t\t\t\tThanks\n");
            gotoxy(65,10);
            printf("Press any key\n");
            getch();
            system("cls");
        }

    }
}
void main()
{
    gotoxy(60,8);
    printf("CONTACT MANAGEMENT SYSTEM AND NUMBER CONVERSION");
    gotoxy(60,9);
    printf("_________________________________________________");
    MAIN_LOGIN_SYS();
    system("cls");
    int n;
    gotoxy(60,8);
    printf("CONTACT MANAGEMENT SYSTEM AND NUMBER CONVERSION");
    gotoxy(60,9);
    printf("_________________________________________________");
    while(n!=3)
    {
        gotoxy(65,14);
        printf("[1].Contact management system");
        gotoxy(65,15);
        printf("[2].Number conversion");
        gotoxy(65,16);
        printf("[3].Exit");
        gotoxy(65,17);
        printf("Enter choice: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            system("cls");
            system("COLOR 0A");
            CONTACT_MANGEMENT_SYS();
            break;
        case 2:
            system("cls");
            system("COLOR 0F");
            NUMBER_CONV();
            system("cls");
            break;
        case 3:
            system("cls");
            system("COLOR 0C");
            gotoxy(65,15);
            printf("Programme terminatted!!!!");
            gotoxy(65,10);
            printf("Press any key\n");
            getch();
            system("cls");
            break;


        }
    }
}












