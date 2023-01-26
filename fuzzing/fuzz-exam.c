#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int powerade(int num, int grade){
    int res = num;
    for (int i = 1; i < grade; i++)
        res*=num;
    return(res);
}

int plus(int first, int second){
    int res;
    res = first + second;
    return(res);
}

int minus(int first, int second){
    int res;
    res = first - second;
    return(res);
}

int multiply(int first, int second){
    int res;
    res = first * second;
    return(res);
}

int divide(int first, int second){
    int res;
    res = first / second;
    return(res);
}

int module(int first, int second){
    int res;
    res = first % second;
    return(res);
}

void usage (char *program)
{
  fprintf (stderr, "%s\n", program);
  fprintf (stderr, "usage: %s [options] [digit 1] [digit 2]\n", program);
  fprintf (stderr, "Options\n");
  fprintf (stderr, "   --powerade\n      Powerade first digit into second digit degree\n");
  fprintf (stderr, "   --plus\n     Addition of first and second digit\n");
  fprintf (stderr, "   --minus\n        Subtraction of first and second digit\n");
  fprintf (stderr, "   --multiply\n        Multiply of first and second digit\n");
  fprintf (stderr, "   --divide\n        Division of first and second digit\n");
}

int main(int argc, char *argv[]){
    printf("Simple calculator\n");
    if (argc == 1){
        fprintf(stderr,"Error in %s\n", argv[0]);
        usage(argv[0]);
    }

    if (argc > 2){
        if (strncmp(argv[1], "--powerade", strlen("--powerade")) == 0){
            int first = atoi(argv[2]);   
            int second = atoi(argv[3]);
            printf("Result of %d ^ %d = %d\n", first, second, powerade(first, second));
        }
        else if (strncmp(argv[1], "--plus", strlen("--plus")) == 0){
            int first = atoi(argv[2]);
            printf("%d\n", first);
            int second = atoi(argv[3]);
            printf("Result of %d + %d = %d\n", first, second, plus(first, second));
        }
        else if (strncmp(argv[1], "--minus", strlen("--minus")-1) == 0){
            int first = atoi(argv[2]);
            int second = atoi(argv[3]);
            printf("Result of %d - %d = %d\n", first, second, minus(first, second));
        }
        else if(strncmp(argv[1], "--multiply", strlen("--multiply")-1) == 0){
            int first = atoi(argv[2]);
            int second = atoi(argv[3]);
            printf("Result of %d * %d = %d\n", first, second, multiply(first, second));
        }
        else if(strncmp(argv[1], "--divide", strlen("--divide")-1) == 0){
            int first = atoi(argv[2]);
            int second = atoi(argv[3]);
            printf("Result of %d / %d = %d\n", first, second, divide(first, second));
        }
        else if(strncmp(argv[1], "--module", strlen("--module")-1) == 0){
            int first = atoi(argv[2]);
            int second = atoi(argv[3]);
            printf("Result of %d % %d = %d\n", first, second, module(first, second));
        }
        else if(strncmp(argv[1], "--sqrt", strlen("--sqrt")-1) == 0){
            double first = (double)atoi(argv[2]);
            double res = sqrt(first);
            printf("Result of sqrt(%.0lf) = %.2lf\n", first, res);
        }
        else{
            strncpy(argv[4],"error!!", strlen("error"));
            usage(argv[4]);
        }
    }
    printf("Goodbye\n");

}
