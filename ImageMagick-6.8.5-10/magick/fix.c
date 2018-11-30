
#include <string.h>
#include <ctype.h>
#include "magick/fix.h"

//Function to remove special charaters from command strings
char * sanitizeInput (char * command)
{
    //List of allowed special characters
    const char * allowedSpecials = " :/_-&$?+=";
    int filterIndex = 0; 
    char temp;
    for(int i =0; command[i]!='\0'; i++)
    {
        temp = command[i];
        if(isalnum(temp)||strchr(allowedSpecials, temp)!=NULL)
        {
            //save desired chars in their new filtered position
            command[filterIndex]=temp;
            filterIndex++;
        }
    }
    //null terminate the string
    command[filterIndex]='\0';
    return command;
}
