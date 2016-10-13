#include <SIECA132.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

#define CANERROR 1

using std::cout;
using std::cin;
using std::endl;
using std::string;


class CANBus
{

public:
	enum BAUDRATES 
	{
		B1000k,
		B800k,
		B500k,
		B250k,
		B125k,
		B100k,
		B50k,
		B20k
	};

private:
	long canChannel;
	long netNumber;
	long echo;
	long rxtimeout;
	long txtimeout;
	BAUDRATES baudrate;
	HANDLE handle;
	HANDLE htEventR;
	HANDLE htEventE;
	bool CANOpen;
	int recBufSize;
	long openCan(void);
	CMSG canMsg[50];
	char buffer[100];

public:
	
	long msgCount;
	CANBus();
	~CANBus();
	CANBus( long netNumber, long canChannel, long echo, long rxtimeout,
		long txtimeout, BAUDRATES baudrate);
	long filterOff();
	long readMsg();
	void printMsg();
	char* getMsg();
	long sendMsg8(unsigned char id, unsigned char* data);
	long sendMsg8(CMSG msg);
};

class CanMessage
{

private:
	CMSG msg;
	static const int MAX=80;
	char description[MAX];

public:
	CanMessage(const char* descrCString, const char* dataCString )
	{
		int i=0;
		while ( description[i] && i < MAX )
		{
			description[i] = descrCString[i];
		}
		description[MAX] = '\0';

		if ( sscanf_s(dataCString ,"%x %x %x %x %x %x %x %x %x",
				&msg.l_id,
				&msg.aby_data[0],
				&msg.aby_data[1],
				&msg.aby_data[2],
				&msg.aby_data[3],
				&msg.aby_data[4],
				&msg.aby_data[5],
				&msg.aby_data[6],
				&msg.aby_data[7])
				!= 9)
		{
			throw -1;
		}
		msg.by_len = 8;
		msg.by_extended = 0;
		msg.by_remote = 0;
	}

	CMSG getCMSG()
	{
		return msg;
	}

};

//namespace netFox
//{
//	ref class netFox{
//		CANBus* cbo;
//		netFox(long netNumber, long canChannel, long echo, long rxtimeout,
//			long txtimeout, CANBus::BAUDRATES baudrate)
//		{
//			cbo = new CANBus(netNumber,canChannel,echo,rxtimeout,txtimeout,
//				baudrate);
//		}
//	};
//}