#ifndef ETHERSHIELD_H
#define ETHERSHIELD_H

#include <inttypes.h>
#include "enc28j60.h"
#include "ip_arp_udp_tcp.h"
#include "net.h"


class EtherShield
{
  public:
  
  	EtherShield();
	  uint16_t ES_fill_tcp_data_p(uint8_t *buf,uint16_t pos, const prog_char *progmem_s);
	  uint16_t ES_fill_tcp_data(uint8_t *buf,uint16_t pos, const char *s);
		void ES_enc28j60Init(uint8_t* macaddr);
		void ES_enc28j60clkout(uint8_t clk);
		void ES_enc28j60PhyWrite(uint8_t address, uint16_t data);
		uint16_t ES_enc28j60PacketReceive(uint16_t len, uint8_t* packet);
		void ES_init_ip_arp_udp_tcp(uint8_t *mymac,uint8_t *myip,uint8_t wwwp);
		uint8_t ES_eth_type_is_arp_and_my_ip(uint8_t *buf,uint16_t len);
		void ES_make_arp_answer_from_request(uint8_t *buf);
		uint8_t ES_eth_type_is_ip_and_my_ip(uint8_t *buf,uint16_t len);
		void ES_make_echo_reply_from_request(uint8_t *buf,uint16_t len);
		void ES_make_tcp_synack_from_syn(uint8_t *buf);
		void ES_init_len_info(uint8_t *buf);
		uint16_t ES_get_tcp_data_pointer(void);
		void ES_make_tcp_ack_from_any(uint8_t *buf);
		void ES_make_tcp_ack_with_data(uint8_t *buf,uint16_t dlen);
		
		// new web client functions 
		void ES_make_arp_request(uint8_t *buf, uint8_t *server_ip);
		uint8_t ES_arp_packet_is_myreply_arp ( uint8_t *buf );
		void ES_tcp_client_send_packet(uint8_t *buf,uint16_t dest_port, uint16_t src_port, uint8_t flags, uint8_t max_segment_size, 
	uint8_t clear_seqck, uint16_t next_ack_num, uint16_t dlength, uint8_t *dest_mac, uint8_t *dest_ip);
		uint16_t ES_tcp_get_dlength( uint8_t *buf );

};	
		
#endif
