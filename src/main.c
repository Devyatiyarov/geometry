#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"

int main()
{
	FILE *file;
        file = fopen("c.txt", "r");
        if (!file) {
        	printf("Can`t open file\n");
        	return -1;
   	}
	char str[MAX];
	Circle *c = (Circle *)malloc(sizeof(Circle) * MAX);
	int i = 0;
	int count_err = 0;
    	while (!feof(file)) {
    		i++;
    		(c + i)->index = i;
       		fgets(str, MAX, file);
        	if (scan_errors(c, str, i, count_err) == -1) {
        		i--;
        		count_err++;
    			continue;
        	}
      	}

    	print_circle(c, i);

    	fclose(file);
    	free(c);
    	c = NULL;
    
	return 0;
}
