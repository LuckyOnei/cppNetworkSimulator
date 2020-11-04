/*
* This file specifies physical layer of simulation. 
*/

#pragma once

#ifndef SRC_PHYSICAL_LAYER_H
#define SRC_PHYSICAL_LAYER_H
#endif

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>

namespace L1
{
	class Connection;

	class Machine
	{
	public:
		Machine(std::array<char, 6> mac_adress, int max_msg = 10);
		Machine(std::string mac_adress, int max_msg = 10);
		Machine(int max_msg = 10);

		void SendData(Connection* con, char* data);
		void RecieveData(char* data, bool collision_detected = false);
		
		void StartConnection(Connection* con);
		void EndConnection(Connection* con);

		friend std::ostream& operator<<(std::ostream& os, const Machine& ma)
		{
			os << "MACHINE " << std::string(std::begin(ma.mac_adress), std::end(ma.mac_adress)) << ": ";
			return os;
		}

		
		friend bool operator ==(const Machine& lhs, const Machine& rhs);
		friend bool operator !=(const Machine& lhs, const Machine& rhs);

		

		void Tick()
		{
			if (tick_func != NULL) this->tick_func(*this);
			else std::cout << "Tick functuion is not assigned!";
		}

		void (*tick_func)(Machine& p);

		std::array<char, 6> mac_adress;
		unsigned int max_msg; //Our network card speed
	private:
		std::list<Connection*> connections;
	};

	class Connection
	{
	public:
		Connection(int max_ticks);
		void ConnectMachine(Machine* machine);
		void DisconnectMachine(Machine* machine);
		void SendMsg(Machine& sender, char* msg);
	private:

		struct message
		{
			int ticks_remaining;
			Machine& sender;
			char* data;
			bool collision_happened = false;
		};

		unsigned int max_ticks;
		std::list<Machine*> connected_machines;
		std::vector<message> pending_msgs;

		void Tick(); //Delay simulation
		void Collision(); //Abnormal voltage simulation. We don't want physics in our programming.

	};

	void Connect(Machine* machine, Connection* connection);
	void Disonnect(Machine* machine, Connection* connection);
}
