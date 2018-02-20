#include <stdio.h>

int main(){

	fprintf("add.xsm", " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",0,2056,0,0,0,0,0,0);
	fprintf("add.xsm", "BRKP");
	fprintf("add.xsm", "MOV R0, 3\n");
	fprintf("add.xsm", "MOV R1, 2\n");
	fprintf("add.xsm", "ADD R0, R1\n");

	return 0;
}
