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