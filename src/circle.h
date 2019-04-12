#define MAX 100

typedef struct {
	double x;
	double y;
	double r;
	int index;
} Circle;

//void get_intersect(Circle *c, int size, int index);
double get_perimeter(Circle *c, int i);
double get_area(Circle *c, int i);
void print_circle(Circle *c, int i);
int scan_errors(Circle *c, char *str, int index, int count_err);
