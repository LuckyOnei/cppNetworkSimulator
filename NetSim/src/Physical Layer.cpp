#include "Physical Layer.h"

#include <algorithm>
#include <iostream>

void L1::Connect(Machine* machine, Connection* connection)
{
	machine->StartConnection(connection);
	connection->ConnectMachine(machine);
}

void L1::Disonnect(Machine* machine, Connection* connection)
{
	machine->EndConnection(connection);
	connection->DisconnectMachine(machine);
}

L1::Connection::Connection(int max_ticks)
{
	this->max_ticks = max_ticks;
}

void L1::Connection::ConnectMachine(Machine* machine)
{
	connected_machines.push_back(machine); //add it
}

void L1::Connection::DisconnectMachine(Machine* machine)
{
	connected_machines.remove(machine);
}

void L1::Connection::SendMsg(Machine& sender, char* msg)
{
	message a
	{
		this->max_ticks, //time remaining
		sender,			 //machine that sent this signal
		msg				 //message itself
	};

	pending_msgs.push_back(a);
}

void L1::Connection::Tick()
{
	if (pending_msgs.size() > 1) Collision();

	for (auto message : pending_msgs)
	{
		message.ticks_remaining--;

		if (message.ticks_remaining == 0)
		{
			for (auto machine : connected_machines)
			{
				if (*machine != message.sender) machine->RecieveData(message.data, message.collision_happened);
			}
		}
	}
}

void L1::Connection::Collision()
{
	for (auto msg : pending_msgs)
		msg.collision_happened = true;
}

bool L1::operator==(const Machine& lhs, const Machine& rhs)
{
	if (lhs.mac_adress == rhs.mac_adress && lhs.connections == rhs.connections)
		return true;
	else
	return false;
}

bool L1::operator!=(const Machine& lhs, const Machine& rhs)
{
	return !(lhs == rhs);
}


L1::Machine::Machine(std::array<char, 6> mac_adress, int max_msg)
{
	this->mac_adress = mac_adress;
	this->max_msg = max_msg;
	this->tick_func = NULL;
}

L1::Machine::Machine(std::string mac_adress, int max_msg)
{
	for (int i = 0; i < 6; ++i)
		this->mac_adress[i] = mac_adress[i];
	
	this->max_msg = max_msg;
	this->tick_func = NULL;
}

L1::Machine::Machine(int max_msg)
{
	for (int i = 0; i < 6; ++i)
		this->mac_adress[i] = abs(rand()) % 128;
		
	this->max_msg = max_msg;
	this->tick_func = NULL;
}

void L1::Machine::SendData(Connection* con, char* data)
{
	con->SendMsg(*this, data);
}

void L1::Machine::RecieveData(char* data, bool collision_detected)
{
	//TODO create buffer
}

void L1::Machine::StartConnection(Connection* con)
{
	this->connections.push_back(con);
}

void L1::Machine::EndConnection(Connection* con)
{
	this->connections.remove(con);
}

