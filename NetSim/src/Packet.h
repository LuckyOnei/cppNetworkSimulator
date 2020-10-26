#pragma once

#ifndef SRC_PACKET_H
#define SRC_PACKET_H
#endif  // SRC_PACKET_H

//Network Access Layer
namespace NAL
{
	//Base-class for all packets. Contains implementation of basic functionality
	class Packet
	{
		Packet(char* packet);

		char* octets; // contains all the data of packet (including headers etc.)

		/// <summary>Operator to interact with packets insides</summary>
		/// <param name="i">Position of bit to return</param>  
		/// <returns>One bit from packet (true = 1, false = 0). Returns -1 if bit doesn't exist  </returns>  
		bool operator[](unsigned int i);
	};

	class IPPacket : Packet
	{
		IPPacket();
	};
}

