# Operating Systems 2 - Week 1

## Proccess Management

### Year 2 Overview

#### More on Process Terminations

- when using `int exit(int status)` the process sends a byt (number between 0 and 255) to parent it inform about status
- Even when child exits the process is still on system and has a PCB until it's parent receives the info about it's death
- Using the functions `int wait(int *st)` found in `#include <sys/wait.h>`, takes a pointer to an int and returns pid of exited child
- we need to do `st = st >> 8` to be able to read the number returned
- this is the first tpe of communication between two processes and a type of synchronization (but it's naive)
- we use one `wait` for each child, and it returns -1 if no child exists
- `waitpid (int pid, int *st, int options)` to wait for a specific child
- `wait(Null)` to just wait and not get any info
- the option `WNOHANG` lets the code continue execuing without waiting for child but getting information later on

Exercise: determine the max of an array of integers (0 <= int <= 255) by deviding task between parent and child, parent gets first half and child has second

My Solution

``` C
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    //fill your array
    int array[10] = {1, 0, 14, 253, 17, 99, 10, 159, 2, 200};
    int length = 10;
    int localMax = 0;
    
    int pid = fork();
    if (pid) {
        
        for (int i = 0; i < length / 2; i++)
        {
            if (array[i] > localMax)
                localMax = array[i];
        }
        int result;
        wait(&result);
        result = result >> 8;
        if (result > localMax)
            printf("Max number is: %d", result);
        else
            printf("Max number is: %d", localMax);
    }
    else {
        for (int i = length / 2; i < length; i++)
        {
            if (array[i] > localMax)
                localMax = array[i];
        }
        exit(localMax);
    }
    return 0;
}
```

##### Orphan Process

When the parent of a process die  before the child finishes, the child is immediately the init process (pid=1) becomes parent of orphan process

``` C
#include <unistd.h>

void main(){
	if (!fork())
		while (1);
	else
		exit(0);
}
```

##### Zombie Process

A process that exits system but it's parent doesn't execute the wait function

``` C
#include <unistd.h>

void main(){
	if (fork())
		while (1);
	else
		exit(0);
}
```

### Executing a file

1. create a child
2. replace the task of child with another task (image)

- `int execl(char *filename, char *arg0, char *arg1, ...)`
- `int execv(char *filename, char *argv[])`
- ` int execlp(char *filename, char *arg0, char *arg1, ...)`
- `int execvp(char *filename, char *argv[])`

- the p after the exec indicates PATH, it tells the execute to search in PATH if program isn't found
- PATH is a collection of directories with your commonly used executables

Example: Create a C program that executes the unix command "ls -l -a"

``` C
#include <>

void main()
{
	if (!fork())
	{
		execl("/bin/ls", "ls", "-l", "-a", NULL);
		printf("Exec Failure\n"); // we only reach here if process disn't exit in execl so it's a failure
	}
}
```
it could've been `execv("/bin/ls", {"ls", "-l", "-a", NULL})` or `execvp("ls", {"ls", "-l", "-a", NULL}))` etc...
**Note: The family of exec functions never return**
