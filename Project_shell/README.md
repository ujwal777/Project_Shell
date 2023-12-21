main.c : contains code that displays the prompt and takes in the command from the user.It also has the code to tokenize the input.

display.c : prints the prompt

run.c : contains code to call the required function as per the given input

echo.c : contains code for the echo command

pwd.c : contains code for pwd command

lscall.c : calls the ls function by making adjustments as per the flags used by the user

ls.c : executes ls command

ls2.c : executes a few special cases in ls

fg.c : has function that is called for foreground process.The parent waits until child is terminated 

bg.c : has function that handles background processes

cd.c : contains the cd function that executes the cd command

pinfo.c : has the pinfo() function that executes the pinfo command.Displays pid,process status,execution path and virtual memory.

redir.c : Contains the code for input and output redirection. 

pip.c : Contains code for implementation of commands with pipes. It handles cases of pipes along with input and redirection also

run2.c : Contains code for the function run2().The function run2() is called by pip() when we need to implement the commands before and after a pipe.

jobs.c : Code lists all the background processes in alphabetical order.

fore.c : Used to implement the fg command

back.c : Used to implement the bg command

handlers.c : Contains code for the functions handler() , handler2() and handler3(). The function handler() is called     
whenever a background process is killed.The function handler2() is called whenever ctrl+c is pressed.The function handler3 () is called whenever ctrl+z is pressed.