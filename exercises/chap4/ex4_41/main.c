#include "Item.h"
#include "DEQUE.h"
#include "stdio.h"
#include "stdlib.h"

void print(char *s){
    printf("%s",s);
    printf("\n");
}

int isLowerCase( char c){
    if (c >= 'a' && c <= 'z'){
        return 1;
    }
    else{
       return 0; 
    }
}

int isUpperCase(char c){
    if (c >= 'A' && c <= 'Z'){
        return 1;
    }
    else{
        return 0;
    }
}

int isOp(char c){
    if (c == '+' || c == '*'){
        return 1;
    }
    else{
        return 0;
    }
}

int doOp(char c){
    if (c == '+'){
        Item item = QUEUEget();
        printf("%c ", item);
    }
    else if (c == '*'){
        Item item = QUEUEpop();
        printf("%c ", item);
    }
    else{
        print("Wrong operand given");
    }
}

int processArgs(char *com){
    int i = 0;
    while (com[i] != 0){
        char p = com[i];
        if (isLowerCase(p)){
            QUEUEput(p);
        }
        else if (isUpperCase(p)){
            QUEUEpush(p);
        }
        else if (isOp(p)){
            doOp(p);
        }
        else{
            return -1;
        }
        i = i + 1;
    }
}

int main(int argc, char *argv[]){
    if (argc != 2){
        print("No arguments given");
        return -1;
    }
    int i = 0;
    char *commands = argv[1];
    while (commands[i] != 0){
        i = i + 1;
    }
    int comLen = i + 1;
    QUEUEinit(comLen);
    int res = processArgs(commands);
    if (res == -1){
        print("Invalid argument was given");
        return -1;
    }
    QUEUEdestroy();
    return 0;
}