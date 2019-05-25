#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <functional>
#include <cstdint.h>
#include <boost/asio/ip/address.hpp>

using boost::asio::ip::address;
namespace dv5
{	
	enum class node_event = {
		// Packet type events.
		// These correspond to packet types in the UDP protocol.
		ping_packet,
		pong_packet,
		findnode_packet,
		neighbors_packet,
		findnode_hash_packet,
		topic_register_packet,
		topic_query_packet,
		topic_nodes_packet,

		// Non-packet events.
		pongTimeout = topic_nodes_packet + 256,
		pingTimeout = pongTimeout + 1,
		neighboursTimeout = pingTimeout + 1
	};


	
	class node_net{
	public:
	};
	class node_id {
	public:
		static int bits = 512;
		typedef std::vector<uint8_t> public_key_t;//tmp until crypto lib is integrated

		explicit node_id(const std::string& hex);
		explicit node_id(const std::string_view hex);
		explicit node_id(const public_key_t& pk);
		explicit node_id(const std::vector<uint8_t>& hash,const std::vector<uint8_t> sig);

		public_key_t get_pub_key() const;

		std::string get_string() const;
		operator std::string() const;
	};


	class node{
	public:
		boost::asio::ip::address ip;
		uint16_t udp_port;
		uint16_t tcp_port;
		node_id id;
		//TODO
	};
}
#endif