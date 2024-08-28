#include <stdio.h>
#include <stdbool.h>

int main(int count, char **argv) {
    if(count != 2) { // Ensure exactly one argument is passed
        printf("Please provide exactly one argument.\n");
        return 1;
    }

    char *arg = argv[1]; // Point to the argument string
    bool isInteger = true;
    int cnt=0;
    while(*arg) {
        if(*arg < '0' || *arg > '9') {
            isInteger = false;
            break;
        }
        arg++;
	cnt++;
    }
if(10==cnt){
    if(isInteger) {
        printf("It is an integer value.\n");
    } else {
        printf("It is not an integer value.\n");
    }
} else {
	printf("this is not contact number");
}

    return 0;
}

