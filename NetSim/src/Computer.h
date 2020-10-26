#pragma once

class Computer
{
	Computer(char mac_adress[6]);

	char mac_adress[6];

	int SendMsg();
	int BindPort();
};