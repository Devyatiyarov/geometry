#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"

int scan_errors(Circle *c, char *str, int index, int count_err)
{
	char circle[7] = "circle\0";
	for (int i = 0; circle[i] != '\0'; i++) {
		if (circle[i] != str[i]) {
			printf("String %d\n\t error: ", index + count_err);
			printf("Name Error\n");
			printf(">%c\n", str[i]);
			count_err++;
			return -1;
		}
	}
	char temp_x[MAX];
	char temp_y[MAX];
	char temp_r[MAX];
	if (str[6] != '(') {
		printf("String %d\n\t error: ", index + count_err);
		printf("Missing Bracket\n");
		printf(">%c\n", str[6]);
		return -1;
	}
	int i = 7;
	if ((str[i] < '0' || str[i] > '9') && str[i] != '-') {
		printf("String %d\n\t error: ", index + count_err);
		printf("Sintax Error\n");
		printf(">%c\n", str[i]);
		return -1;
	}
	for (int j = 0; str[i] != ' '; i++, j++) {
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-') {
			printf("String %d\n\t error: ", index + count_err);
			printf("Coordinate Error\n");
			printf(">%c\n", str[i]);
			return -1;
		}
		temp_x[j] = str[i];
	}
	(c + index)->x = atof(temp_x);	
	i++;

	if ((str[i] < '0' || str[i] > '9') && str[i] != '-') {
		printf("String %d\n\t error: ", index + count_err);
		printf("Syntax Error\n");
		printf(">%c\n", str[i]);
		return -1;
	}
	
	for (int j = 0; str[i] != ','; i++, j++) {
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-') {
			printf("String %d\n\t error: ", index + count_err );
			printf("Coordinate Error\n");
			printf(">%c\n", str[i]);
			return -1;
		}
		temp_y[j] = str[i];
	}
	i += 2;
	(c + index)->y = atof(temp_y);

	if (str[i] < '0' || str[i] > '9') {
		printf("String %d\n\t error: ", index + count_err);
		printf("Syntax Error\n");
		printf(">%c\n", str[i]);
		return -1;
	}

	for (int j = 0; str[i] != ')'; i++, j++) {
		if (str[i] == '\0') {
			printf("String %d\n\t error: ", index + count_err);
			printf("Syntax Error\n");
			printf(">%c\n", str[i]);
			return -1;
		}
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.') {
			printf("String %d\n\t error: ", index + count_err);
			printf("Coordinate Error\n");
			printf(">%c\n", str[i]);
			return -1;
		}
		temp_r[j] = str[i];
	}
	(c + index)->r = atof(temp_r);
	if ((c + index)->r <= 0) {
		printf("String %d\n\t error: ", index + count_err);
		printf("Radius can`t be <= 0\n");
		return -1;
	}	
	if (str[i] != ')') {
		printf("String %d\n\t error: ", index + count_err);
		printf("Missing Bracket\n");
		printf(">%c\n", str[i]);
		return -1;
	}
	return 0;
}

void print_circle(Circle *c, int size)
{	
	for (int i = 1; i < size; i++) {
		printf("%d. circle(%f %f, %f)\n", (c + i)->index, (c + i)->x, (c + i)->y, (c + i)->r);
		printf("\tperimeter = %f\n", get_perimeter(c, i));
		printf("\tarea = %f\n", get_area(c, i));
		printf("\tintersects: \n");	
		get_intersect(c, size, i);
	}
}

double get_perimeter(Circle *c, int i)
{
	return (c + i)->r * 2 * M_PI;
}	

double get_area(Circle *c, int i)
{
	return (c + i) ->r * (c + i)->r * M_PI;
}	

