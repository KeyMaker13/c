#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include "pcap.h"
#include "dnet.h"
#include "prtlog.h"

void printMagic(int num){
	if (num == PCAP_MAGIC){
		printf("PCAP_MAGIC\n");
	} else if (num == 	PCAP_SWAPPED_MAGIC) {
		printf("PCAP_SWAPPED_MAGIC\n");	
	} else if (num == PCAP_MODIFIED_MAGIC) {
		printf("PCAP_MODIFIED_MAGIC\n");
	} else if (num == PCAP_SWAPPED_MODIFIED_MAGIC) {
		printf("PCAP_SWAPPED_MODIFIED_MAGIC\n");
	}
}

void printIP(int num) {

	if ( num == IP_PROTO_ICMP ){
		printf("\tIP\n");		
		printf("\t\tICMP\n");
	} else 	if ( num == IP_PROTO_IGMP ){
		printf("\tIP\n");		
		printf("\t\tIGMP\n");
	} else 	if ( num == IP_PROTO_TCP ){
		printf("\tIP\n");		
		printf("\t\tTCP\n");
	} else 	if ( num == IP_PROTO_UDP ){
		printf("\tIP\n");		
		printf("\t\tUDP\n");
	}else if (num > 0) {
		printf("\tIP\n");
		printf("\t\tUNRECOGNIZED\n");
	}
}

void printARP( int num) {
	
	if (num == ARP_OP_REQUEST) {
		printf("\tARP\n");
		printf("\t\tarp operation = Arp Request\n");
	} else if (num == ARP_OP_REPLY) {
		printf("\tARP\n");
		printf("\t\tarp operation = Arp Reply\n");
	} else if (num == ARP_OP_REVREQUEST) {
		printf("\tARP\n");
		printf("\t\tarp operation = Arp Revrequest\n");
	} else if (num == ARP_OP_REVREPLY) {
		printf("\tARP\n");
		printf("\t\tarp operation = Arp Revreply\n");
	} else {
		printf("\tARP\n");
		printf("\t\tUNRECOGNIZED\n");
	}

}

void printPTYPE( int num ){
	
	if (num == ETH_TYPE_PUP) {
		printf("\tPUP\n");
	} else if (num == ETH_TYPE_REVARP) {
		printf("\tREVARP\n");
	} else if ( num == ETH_TYPE_8021Q ) {
		printf("\t8021Q\n");
	} else if ( num == ETH_TYPE_IPV6 ) {
		printf("\tIPV6\n");
	} else if ( num == ETH_TYPE_MPLS ) {
		printf("\tMPLS\n");
	} else if ( num == ETH_TYPE_MPLS_MCAST ) {
		printf("\tPPPOEDISC\n");
	} else if ( num == ETH_TYPE_PPPOE ) {
		printf("\tPPPOE\n");
	} else if ( num == ETH_TYPE_LOOPBACK ) {
		printf("\tLOOPBACK\n");
	} else {
		printf("\n");
	}


}


int main (int argc, char *argv[]) {

	int n,fd,firsttime = 1,b_usec,c_usec,pcount = 0;
	unsigned int b_sec,c_sec;
	struct pcap_file_header ph;	
	struct pcap_pkthdr phdr;
	struct eth_hdr ethhdr;		
	struct arp_hdr arp;
	struct ip_hdr ip;

	fd = open(argv[1],O_RDONLY);

	if (fd < 0 ) {
		perror(argv[1]);
		exit(-1);		
	}

	// need to error prone
	if ( read(fd,&ph,sizeof(struct pcap_file_header)) != sizeof(struct pcap_file_header) ){
		printf("Read Error\n"); exit(0);
	}
	
	printMagic(ph.magic);
	printf("Version major number = %d\n", ph.version_major);
	printf("Version minor number = %d\n", ph.version_minor);
	printf("GMT to local correction = %d\n", ph.thiszone);
	printf("Timestamp accuracy = %d\n", ph.sigfigs);
	printf("Snaplen = %d\n", ph.snaplen);
	printf("Linktype = %d\n", ph.linktype);
	printf("\n");

	while ( (n = read(fd,&phdr,sizeof(struct pcap_pkthdr))) == (sizeof(struct pcap_pkthdr)) ){
		

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
		
		read(fd,&ethhdr,sizeof(struct eth_hdr));		
		
		if( ntohs(ethhdr.eth_type) == ETH_TYPE_IP ) {
			read(fd,&ip,sizeof(struct ip_hdr));
			printf("Packet %d\n", pcount);
                	printf("%05u.%06u\n", (unsigned)c_sec, (unsigned)c_usec);
                	printf("Captured Packet Length = %d\n", phdr.caplen);
                	printf("Actual Packet Length = %d\n", phdr.len);
                	printf("Ethernet Header \n");
			printIP(ip.ip_p);                	
			printf("\n");
                	pcount++;	
			lseek(fd,phdr.len - sizeof(struct eth_hdr) - sizeof(struct ip_hdr),SEEK_CUR);
		} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_ARP ) {
			read(fd,&arp,sizeof(struct arp_hdr) ) ;
			printf("Packet %d\n", pcount);
                	printf("%05u.%06u\n", (unsigned)c_sec, (unsigned)c_usec);
                	printf("Captured Packet Length = %d\n", phdr.caplen);
                	printf("Actual Packet Length = %d\n", phdr.len);
                	printf("Ethernet Header \n");
			//printf("arp.ar_op = %d vs ARP_OP_REQUEST: %d\n",arp.ar_op, ARP_OP_REQUEST);			
			printARP(ntohs(arp.ar_op));                	
			/*
			if (ntohs(arp.ar_op) == ARP_OP_REQUEST) {
				printf("\tARP\n");
				printf("\t\tarp operation = Arp Request\n");
			} else if (ntohs(arp.ar_op) == ARP_OP_REPLY) {
				printf("\tARP\n");
				printf("\t\tarp operation = Arp Reply\n");
			} else if (ntohs(arp.ar_op) == ARP_OP_REVREQUEST) {
				printf("\tARP\n");
				printf("\t\tarp operation = Arp Revrequest\n");
			} else if (ntohs(arp.ar_op) == ARP_OP_REVREPLY) {
				printf("\tARP\n");
				printf("\t\tarp operation = Arp Revreply\n");
			} else {
				printf("\tARP\n");
				printf("\t\tUNRECOGNIZED\n");
			}
			*/
			printf("\n");
                	pcount++;	
			lseek(fd,phdr.len - sizeof(struct eth_hdr) - sizeof(struct arp_hdr),SEEK_CUR);
	
		} else {
			printf("Packet %d\n", pcount);
                	printf("%05u.%06u\n", (unsigned)c_sec, (unsigned)c_usec);
                	printf("Captured Packet Length = %d\n", phdr.caplen);
                	printf("Actual Packet Length = %d\n", phdr.len);
                	printf("Ethernet Header \n");
			printPTYPE(ntohs(ethhdr.eth_type));                	
			/*
				if (ntohs(ethhdr.eth_type) == ETH_TYPE_PUP) {
					printf("\tPUP\n");
				} else if (ntohs(ethhdr.eth_type) == ETH_TYPE_REVARP) {
					printf("\tREVARP\n");
				} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_8021Q ) {
					printf("\t8021Q\n");
				} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_IPV6 ) {
					printf("\tIPV6\n");
				} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_MPLS ) {
					printf("\tMPLS\n");
				} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_MPLS_MCAST ) {
					printf("\tMPLS Multicast\n");
				} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_PPPOEDISC ) {
					printf("\tPPPOEDISC\n");
				} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_PPPOE ) {
					printf("\tPPPOE\n");
				} else if ( ntohs(ethhdr.eth_type) == ETH_TYPE_LOOPBACK ) {
					printf("\tLOOPBACK\n");
				} else {
				
				}
			*/
			printf("\n");
                	pcount++;
			lseek(fd,phdr.len - sizeof(struct eth_hdr),SEEK_CUR);	
		}			
	}

	if (n < 0 ){ printf("Read error\n"); exit(0);
	}
	close(fd);	
	return 0;
}








