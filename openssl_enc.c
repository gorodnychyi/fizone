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
	char	mac[32];
	int		gw_id;

    	const int size = 256;
    	char 	ip_address[size];
    	int 	hw_type;
    	int 	flags;
    	char 	mac_address[size];
    	char 	mask[size];
    	char 	device[size];
	
    	gw_id=11;

	FILE* fp = fopen("/proc/net/arp", "r");
    	char line[size];
    	while(fgets(line, size, fp))
    	{
        	sscanf(line, "%s 0x%x 0x%x %s %s %s\n",ip_address,&hw_type,&flags,mac_address,mask,device);
        	if(strstr(device, "wlp2s0") != 0) {
        		printf("Wlan_if: %s\nMAC: %s\n", device, mac_address);
        		break;
        	}
    	}	
	fclose(fp);

	sprintf(command, "echo mac=%s/id=%d | openssl enc -pass file:url.key -e -aes-256-cbc -a -salt\n", mac_address,gw_id);
	fo = popen(command, "r");
	fscanf(fo, "%s", result);
	fclose(fo);

//	...use result...
	printf("Device_id: %d\n", gw_id);	
	printf("%s\n",result);

	exit (0);
}
