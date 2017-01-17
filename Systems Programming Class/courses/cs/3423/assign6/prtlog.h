#define PCAP_MAGIC  		    0xa1b2c3d4
#define PCAP_SWAPPED_MAGIC 	    0xd4c3b2a1
#define PCAP_MODIFIED_MAGIC 	    0xa1b2cd34
#define PCAP_SWAPPED_MODIFIED_MAGIC 0x34cdb2a1
/*
#define ETH_TYPE_PUP 	0X0200
#define ETH_TYPE_IP 	0X0800
#define ETH_TYPE_ARM 	0X0806
#define ETH_TYPE_REVARP	0X9035
#define ETH_TYPE_8021Q 	0X8100 
#define ETH_TYPE_IPV6 	0X86DD
#define ETH_TYPE_MPLS 	0X8847
#define ETH_TYPE_MPLS_MCAST 	0X8848
#define ETH_TYPE_PPPOEDISC 	0X8863
#define ETH_TYPE_PPPOE 		0X8864
#define ETH_TYPE_LOOPBACK 	0X9000
*/

/*
struct eth_hdr{
eth_addr_t	eth_dst;
eth_addr_t	eth_src;
uint16_t	eth_type;
}
*/

/*
struct pcap_file_header{
u_int32_t magic;
u_int16_t version_major;
u_int16_t version_minor;
u_int32_t thiszone;
u_int32_t sigfigs;
u_int32_t snaplen;
u_int32_t len;
};
*/

/*
struct pcap_pkthdr{
struct timeval ts;
u_int32_t caplen;
u_int32_t len;
};
*/






