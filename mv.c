/*
 PC0401:
 
 Check the man pages for the mv command.
 
 Use the rename system call to write your own version of the mv command.
 
 The program should display an appropriate message if the file does not exist, or the command is invoked with the wrong number of arguments.
 
 If the destination is the name of a directory, then mv moves the file into that directory.  Otherwise, mv renames the file if possible.
 
 Test Plan:
 
 TEST                EXPECTED OUTPUT
 
 gcc mv.c            program compiles
 ./mv                appropriate error message
 ./mv a              appropriate error message
 ./mv a b            file a is renamed to b
 ./mv a dir          file a is moved to directory dir
 ./mv a dir/a        file a is moved to dir, keeps same name
 ./mv a dir/b        file a is moved to dir, but named b
 ./mv dir/a b        file a is moved from dir into current directory
 
 Hw Assignment #4
 
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>


int main( int ac, char* av[] )
{
    int firstIsDir = 0;
    int secondIsDir = 0;
    char name1[80];
    char name2[80];
    int i = 0;
    
    if (ac != 3)
    {
        printf("mv: missing file operand!\n");
        printf("Try 'mv --help' for more information.\n");
        exit(1);
    }
    if (ac == 3)
    {
        while(1)
        {
            if (av[1][i] == '/')
            {
                secondIsDir = 1;
                break;
            }
            i++;
        }
        while(1)
        {
            if (av[2][i] == '/')
            {
                secondIsDir = 1;
                break;
            }
            i++;
        }
       if (((firstIsDir == 0) && (secondIsDir == 0)))
        {
            strcpy(name1, av[1]);
            strcpy(name2, av[2]);
            if (rename (name1, name2) == -1)
            {
                printf ("Rename error!\n");
            }
        }
        else if (((firstIsDir == 0) && (secondIsDir == 1)))
        {
            strcpy(name1, av[1]);
            strcpy(name2, av[2]);
            if (rename (name1, name2) == -1)
            {
                strcat(name2 , "/");
                strcat(name2, name1);
                if (rename (name1, name2) == -1)
                {
                    printf ("Rename error!\n");
                }
            }
        }
        else
        {
            printf("Wrong file!\n");
        }
   }
    return (0);
}
