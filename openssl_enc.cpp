#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

FILE * fo;

int main()
{
	char	command[1024];
	char 	result[1024];
	char	url[]="data=to/send=for/our=server"; //30 char max


	sprintf(command, "echo %s | openssl enc -pass file:url.key -e -aes-256-cbc -a -salt\n", url);
	fo = popen(command, "r");
	fscanf(fo, "%s", result);
	fclose(fo);

//	...use result...	
//	printf("%s\n",result);

	exit (0);
}
