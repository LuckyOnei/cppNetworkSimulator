/*
* How to read:
* 
* In this project I'm gonna use namespaces as references to netwroks abstraction layers.
* Example:
* NAL::Packet means that packets are defined on Network Acess Layer (NAL)
* 
* List (from lower to higher levels of abstraction):
* 0) Network Acess Layer: Ethernet, IEEE 802.11 WLAN, SLIP, Token Ring, ATM and MPLS
* 1) Internet Layer: IP
* 2) Transport Layer: TCP, UDP, SCTP, DCCP
* 3) Application Layer: HTTP, RTSP, FTP, DNS
* 
* 
*/

#include <iostream>

int main()
{
    std::cout << sizeof(char) << std::endl;
}
