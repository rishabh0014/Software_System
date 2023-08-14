#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	FILE *demo;

	demo = fopen("demoo.txt","r+");
	fprintf(demo, "%s", "RRR");
	return 0;
}
