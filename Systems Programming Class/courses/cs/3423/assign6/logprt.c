
// read one bit of data at a time
// see what to do from there
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include "logprt.h"

int main (int argc, char *argv[]) {
	int n,fd,firsttime = 1,b_usec,c_usec,pcount = 0;
	unsigned int b_sec,c_sec;		
	struct pcap_file_header pr;	
	struct pcap_pkthdr phdr;

	fd = open(argv[1],O_RDONLY);
	if (fd == -1) { 
		printf("Error opening file descriptor\n"); perror(argv[1]); exit(-1);
	}

	printf("file descriptor is: %d\n",fd);	
	read(fd,&pr,sizeof(struct pcap_file_header));
	
	if (pr.magic == PCAP_MAGIC){
		printf("PCAP_MAGIC\n");
	} else if (pr.magic == 	PCAP_SWAPPED_MAGIC) {
		printf("PCAP_SWAPPED_MAGIC\n");	
	} else if (pr.magic == PCAP_MODIFIED_MAGIC) {
		printf("PCAP_MODIFIED_MAGIC\n");
	} else if (pr.magic == PCAP_SWAPPED_MODIFIED_MAGIC) {
		printf("PCAP_SWAPPED_MODIFIED_MAGIC\n");
	}
	
	printf("Version major number = %d\n", pr.version_major);
	printf("Version minor number = %d\n", pr.version_minor);
	printf("GMT to local correction = %d\n", pr.thiszone);
	printf("Timestamp accuracy = %d\n", pr.sigfigs);
	printf("Snaplen = %d\n", pr.snaplen);
	printf("Linktype = %d\n", pr.linktype);
	printf("\n");

	while ( (read(fd,&phdr,sizeof(struct pcap_pkthdr) )) == sizeof(struct pcap_pkthdr) ) {
		if (firsttime) {
			firsttime = 0;
			b_sec = phdr.ts.tv_sec;
			b_usec = phdr.ts.tv_usec;
		}
			
		c_sec = (unsigned) phdr.ts.tv_sec - b_sec;
		c_usec = (unsigned) phdr.ts.tv_usec - b_usec;

		while(c_usec < 0) {
			c_usec += 1000000;
			c_sec--;
		}
		
		//if ( (phdr.caplen == phdr.len) && (phdr.caplen != 0 ) ){
		
		printf("Packet %d\n", pcount); 
		printf("%05u.%06u\n", (unsigned)c_sec, (unsigned)c_usec);
		printf("Captured Packet Length = %u\n", phdr.caplen);
		printf("Actual Packet Length = %u\n", phdr.len);
		printf("\n");
		pcount++;
		lseek(fd,phdr.len,SEEK_CUR);
		//}
		
		
		
	}
	
	return 0;
}
