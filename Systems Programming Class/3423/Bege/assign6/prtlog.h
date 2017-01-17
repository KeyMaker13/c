
#define PCAP_MAGIC			0xa1b2c3d4
#define PCAP_SWAPPED_MAGIC		0xd4c3b2a1
#define PCAP_MODIFIED_MAGIC 		0xa1b2cd34
#define PCAP_SWAPPED_MODIFIED_MAGIC	0x34cdb2a1




#define ETH_TYPE_PUB	0x0200
#define ETH_TYPE_IP	0x0800
#define ETH_TYPE_ARP	0x0806
#define ETH_TYPE_REVARP 0x8035
#define ETH_TYPE_8021Q  0x8100
#define ETH_TYPE_IPV6   0x86DD
#define ETH_TYPE_MPLS   0x8847
#define ETH_TYPE_MPLS_MCAST	0x8848
#define ETH_TYPE_PPPOEDISC	0x8863
#define ETH_TYPE_PPPOE	0x8864
#define ETH_TYPE_LOOPBACK	0x9000



/*
struct eth_hdr{
eth_addr_t	eth_dst;
eth_addr_t	eth_src;
uint16_t	eth_type;




}





struct pcap_file_header{

u_int32_t magic;
u_int16_t version_major;
u_int16_t version_minor;
u_int32_t thiszone;
u_int32_t sigfigs;
u_int32_t snaplen;
u_int32_t len;
}header;



struct pcap_pkthdr{
struct timeval ts;
u_int32_t caplen;
u_int32_t len;
} packet;

*/
