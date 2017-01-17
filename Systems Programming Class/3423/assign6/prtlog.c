#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <arpa/inet.h>
#include "prtlog.h"
#include "pcap.h"
#include "dnet.h"

uint16_t ntohs(uint16_t a);
void printmagic(int a);
void printpr(int a);
void printop(int a);

int main(int argc, char *argv[]){
	int fin;
	struct pcap_file_header temp;

	if(( fin=open(argv[1],O_RDONLY))<0){
		perror(argv[1]);
		exit(-1);
	}

	read(fin,&temp,sizeof(struct pcap_file_header));

	printmagic(temp.magic);
	printf("\n");
	printf("Version major number = %d\n",temp.version_major);
	printf("Version minor number = %d\n",temp.version_minor);
	printf("GMT to local correction = %d\n",temp.thiszone);
	printf("Timestamp accuracy = %d\n",temp.sigfigs);
	printf("Snaplen = %d\n",temp.snaplen);
	printf("Linktype = %d\n",temp.linktype);
	printf("\n");

	struct pcap_pkthdr temp1;
	int count=0;
  
	while ( (read(fin,&temp1,sizeof(struct pcap_pkthdr)))>0){
		printf("Packet %d\n",count);
 
		unsigned int b_sec, c_sec; 

		int b_usec, c_usec;

		if(count ==0){
			b_sec=temp1.ts.tv_sec;
			b_usec=temp1.ts.tv_usec;
		}

		c_sec=(unsigned)temp1.ts.tv_sec - b_sec;
		c_usec =(unsigned)temp1.ts.tv_usec - b_usec;
		while (c_usec<0){
			c_usec += 1000000;
			c_sec--;
		}

		printf("%05u.%06u\n",(unsigned)c_sec,(unsigned)c_usec);

		printf("Captured Packet Length = %d\n",temp1.caplen);
		printf("Actual Packet Length = %d\n",temp1.len);

		count++;

		struct eth_hdr head;
		struct arp_hdr  *arphead;
		struct ip_hdr  *iphead;

		read(fin,&head,sizeof (struct eth_hdr));

		char buf[1024];

		read(fin,&buf,(temp1.len - sizeof(struct eth_hdr)));
 
		if(ntohs(head.eth_type)==ETH_TYPE_ARP)
		{
			arphead=(struct arp_hdr *) buf;
			printf("Ethernet Header\n");
			printf("   ARP\n");
			printf("      arp operation = ");printop((int)ntohs(arphead->ar_op));
			printf("\n");
		}
		else if (ntohs(head.eth_type)==ETH_TYPE_IP)
		{
			iphead=(struct ip_hdr *)buf;
			printf("Ethernet Header\n");
			printf("   IP\n");
			printf("      "); printpr((int)iphead->ip_p);
			printf("\n");
		}

		else {printf("\n");}

		printf("\n");

	}
	exit(0);
}

void printmagic(int a){
	switch(a){
		case PCAP_MAGIC:
			printf("PCAP_MAGIC");
			break;
		case PCAP_SWAPPED_MAGIC:
			printf("PCAP_SWAPPED_MAGIC");
			break;
		case PCAP_MODIFIED_MAGIC:
			printf("PCAP_MODIFIED MAGIC");
			break;
		case PCAP_SWAPPED_MODIFIED_MAGIC:
			printf("PCAP_SWAPPED_MODIFIED_MAGIC");
			break;
		default:
			printf("Could not find a match!\n");
	}
}

void printop(int a){
	switch(a){
		case ARP_OP_REQUEST: printf("Arp Request");break;
		case ARP_OP_REPLY:printf("Arp Reply");break;
		case ARP_OP_REVREQUEST:printf("Arp Revrequest");break;
		case ARP_OP_REVREPLY:printf("Arp Revreply");break;
		default: printf("UNRECONGNIZED");

	}
}

void printpr(int a){
	switch(a){
		case 1: printf("ICMP");break;
		case 2: printf("IGMP");break;
		case 6:  printf("TCP");break;
		case 17:  printf("UDP");break;
		default: printf("UNRECONGNIZED");
	}	
}

uint16_t ntohs(uint16_t a){
	return(a<<8) | (a>>8);
}
