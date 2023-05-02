/*
*
*   COOLORS
* 
*  -> made by : J-c0b
*  -> github : https://github.com/J-c0B
*  -> email : n.hetma.n.7@gmail.com 
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


#define command1 "--help"
#define command2 "--hex"
#define command3 "--dec"

int hex(char c);
void err(int code);


int main(int argc, char * argv[])
{   
    setlocale(LC_ALL, "");
   


if(argv[1] != NULL)
{
    if (argv[2] != NULL)
    {

    
if (strcmp(argv[1],command1) == 0)
{

puts(" ");                                                                                                                      //
puts("  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");                                                            //
puts(" ");                                                                                                                      //
puts("  Options : ");                                                                                                           //
puts(" ");                                                                                                                      //
puts(" ");                                                                                                                      //
puts("       --help  : Shows all available arguments");                                                                         // I could do it better
puts(" ");                                                                                                                      //
puts("       --hex   :   Shows color from hexadecimal color representation . example : FFFFFF ( without '#' )");                //
puts(" ");                                                                                                                      //
puts("       --dec   :    Shows color from decimal color representation . example : 052012034 ( without ',' )");                //
puts(" ");                                                                                                                      //
puts("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");                                                           //

}
else if (strcmp(argv[1],command2) == 0)
{
  
   char color[6];
    
    int rgb[3];

    if(strlen(argv[2]) <= 6)
    {
        strcpy(color , argv[2]);

    rgb[0] = hex(color[0])*16 + hex(color[1]);                    //
     rgb[1] = hex(color[2])*16 + hex(color[3]);                   // Also this <-
      rgb[2] = hex(color[4])*16 + hex(color[5]);                  //

    
    printf("\x1B[38;2;%i;%i;%im",rgb[0],rgb[1],rgb[2]);
    puts("|");
    printf("|\n");
    puts("|");
    puts("|->  █████████");
    }
    else
    {
        err(1);
    }
   
}
else if(strcmp(argv[1],command3) == 0) 
{   

    char color[9];
 
    if(strlen(argv[2]) <= 9)
    {
           strcpy(color , argv[2]);
        char red[4] = {color[0],color[1],color[2]}, green[4]= {color[3],color[4],color[5]} ,blue[4]= {color[6],color[7],color[8]} ;  // And this <- but for a small project , it just doesn't matter
    
    printf("\x1B[38;2;%s;%s;%sm",red,green,blue);
   puts("|"); 
   printf("|\n");
   puts("|");
   puts("|->  █████████");
    
    
    }
    else
    {
        err(1);
    }

}
else
{

err(0);

}

}
else
{

    err(0);
}

}
else
{
    err(1);
}
  printf("\x1B[0m\n");
return 0;
}


int hex(char c)
{
 char hex[6] = {'A','B','C','D','E','F'};
 char hex_lowercase[6] = {'a','b','c','d','e','f'}; 

for(int x = 0;x<sizeof(hex);x++)
{

if(c == hex[x])
{

return 10 + x;
break;

}
else if (c == hex_lowercase[x])
{

return 10 + x;
break;

}


}

return (c - '0');
}

void err(int code)
{

if(code ==0)
{

printf("\x1B[0m\n");
errno = 3;
puts(" ");
puts  ("||                                                            ||");
perror("'' Invalid argument , choose --help for more information .... ''");
exit(1);

}
else
{

printf("\x1B[0m\n");
errno = 2;
puts(" ");
puts  ("||                                ||");
perror("'' Color lenght out of range .... ''");
exit(1);


}


}


