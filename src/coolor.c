/*
*
*   COOLOR
*   Simple colour displayer    
* 
*  -> made by : J-c0b
*  -> github : https://github.com/J-c0B
*  -> email : gjak2700@gmail.com 
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define ARG1 "--help"
#define ARG2 "--hex"
#define ARG3 "--dec"
#define ARG4 "--install"
#define ARG5 "--uninstall"

void hex(char c[],short int colour[]);
void dec(char c[],short int colour[]);
void printc(short int colour[]);
void err(int code);

short int colour[3];

int main(int argc, char * argv[])
{   
    setlocale(LC_ALL, "");

if(argc>1)
{
    
if (strcmp(argv[1],ARG1) == 0)
{

printf("Options \n");
printf("\t--help  Shows all available arguments\n");
printf("\t--hex   Shows colour from hexadecimal color notation\n");
printf("\t--dec   Shows colour from decimal colour notation\n");
printf("\t--install  Performs an installation into a system (no need to keep the downloaded file to run after that)\n");
printf("\t--uninstall Removes the program from the system");

}
else if (strcmp(argv[1],ARG2) == 0)
{
hex(argv[2],colour);
printc(colour);
}
else if(strcmp(argv[1],ARG3) == 0) 
{ 

if(argc >= 5)
    for(int i = 2;i<5;i++)
    {
    dec(argv[i],colour);
    }
else
    err(2);

printc(colour);
}
else if(strcmp(argv[1],ARG4) == 0)
{
char cpath[256];
getcwd(cpath,sizeof(cpath));
chdir(cpath);
system("sudo ln coolor /usr/bin/coolor");
}
else if(strcmp(argv[1],ARG5) == 0)
{
system("sudo rm /usr/bin/coolor");
}

}
else
    err(1);
return 0;
}

void dec(char c[],short int colour[])
{
    static int ccount = 0;
    int p = strlen(c)-1;
if(c != NULL)
{
    for(int i =0;i<3&&c[i]>='0';i++)
    {
        colour[ccount] += pow(10,p)*(c[i]-'0');
        p--;
    }
    ccount += (ccount<3)?1:0;
}
else
    err(2);

}



void hex(char c[],short int colour[])
{
int i = -1,p;

if(c != NULL)
    for(int n = 0;c[n] != '\0';n++)
    {

    i += (n%2==0) ? 1:0;
    p = (n%2==0) ? 1:0;

    if(c[n]>'9')
    {
       colour[i] += pow(16,p)*(10+(tolower(c[n])-'a'));
    }
    else
    {
        colour[i] += pow(16,p)*(c[n]-'0');
    }
    }
else 
    err(2);

}

void err(int code)
{
printf("Error:\t");
if(code ==1)
{
printf("\x1B[0m");
printf("Invalid argument , type --help for more information");
exit(0);
}
else
{
printf("\x1B[0m");
printf("Invalid colour lenght");
exit(0);
}
}

void printc(short int colour[])
{
// printf("red : %i , green : %i , blue %i\n",colour[0],colour[1],colour[2]);  /* For testing purposes */ 
printf("\x1B[38;2;%i;%i;%im",colour[0],colour[1],colour[2]);
printf("█████████\n");
printf("\x1B[0m\n");
}