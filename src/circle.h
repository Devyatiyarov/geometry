#define MAX 100

typedef struct {
	double x;
	double y;
	double r;
	int index;
} Circle;

void print_circle(Circle *c, int i);
int scan_errors(Circle *c, char *str, int index, int count_err);
