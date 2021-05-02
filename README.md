# Man-Mv-Command-
Objective:  Use the rename system call to write your own version of the mv command.
 
 Check the man pages for the mv command.
  
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
 
