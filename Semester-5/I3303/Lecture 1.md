# Operating Systems 2 - Week 1

## Curriculum

- Proccess Management
  - Refresh (I2203)
  - IPC (Intra Proccess Communication)
    - Pipes / unames / named
    - Signals
    - Shared Memory
- Main Memory
- File System Management

## Proccess Management

### Year 2 Overview

#### General

- poccess is a program in execuion
- each process has a pid (identifier) that's an int
- each process has several parts (segments) in Main Memory (code, data, heap that's dynamic, stack)
- processes are organized in a heirachy (in a tree)
- the creation of a new process is done by another process caled parent
- a creation is a cloning of parent with copy of segments
- main process (init) has pid=1
- each process has PCB (Process Control Block) filled with attributes
- process has many states because of multiprossesing
  - running
  - blocked
  - ready

#### Process creation

- Process is created by cloning, in unix it's called **forking**
  
``` C
#include <unistd.h>

int fork();
```

when we do `pid = fork()` we create a child process that's copy of current process. we destinuish between parent and child with return of fork here saved in pid

- if it's 0 then we're in child
- if <> 0 then it's parent, the number is pid of created child

#### Process Identification

- each process has an id
- `int getpid()` returns the pid of calling process
  
``` C
#include <unistd.h>

void main()
{
  int pid;
  pid = getpid();
  printf("The pid of parent process is %d", pid);
  pid = fork();
  if (pid)
    printf("The pid of child process is %d", pid);
}
```

- `int getppid()` returns pid of parent of calling process
- `ps` is a unix command for currently executing processes
- `ps -a` for more info
- `pstree -p` draws a tree of processes

#### Process Termination

- we have Zombie Processes
- we have Orphan Porcesses
- then end of a process can happen when
  - process finishes all the instructions
  - the process ents execution before finishing all instructions
  - the process is killed by another process with more privelages
    - normal, exit(0);
    - abnormal, exit(<>0);
- parent always knows child is dead, that's how processes end
