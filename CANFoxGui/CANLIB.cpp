#include "CANLIB.h"


CANBus::CANBus( long netNumber, long canChannel, long echo, long rxtimeout,
		long txtimeout, BAUDRATES baudrate): CANOpen(false), handle(NULL), recBufSize(1)
{
	
	this->netNumber = netNumber;
	this->canChannel = canChannel;
	this->echo = echo;
	this->rxtimeout = rxtimeout;
	this->txtimeout = txtimeout;
	this->baudrate = baudrate;
	this->recBufSize = recBufSize;
	
	long retval = openCan();
	
	if (retval != 0 )
		throw retval;
	
	CANOpen=true;
	
	retval = canSetBaudrate(handle, baudrate);
	if (retval != 0 )
		throw retval;

}

CANBus::CANBus(): CANOpen(false), handle(NULL), recBufSize(1)
{
	netNumber = 105;
	canChannel = 1;
	echo = 1;
	rxtimeout = -1;
	txtimeout = 1000;
	baudrate = B125k;
	

	long retval = openCan();
	
	if (retval != 0 )
		throw retval;
	
	CANOpen=true;
	
	retval = canSetBaudrate(handle, baudrate);
	if (retval != 0 )
		throw retval;

}

CANBus::~CANBus()
{
	canClose(handle);
}

long CANBus::openCan()
{
	long retval;
	htEventR = CreateEvent(NULL,TRUE,FALSE,TEXT("R2"));
	htEventE = CreateEvent(NULL,TRUE,FALSE,TEXT("E2"));

	retval = canOpen(
		netNumber,
		0,
		echo,
	
		txtimeout,
		rxtimeout,
		"CANFOXLogger",
		"R1",
		"E1",
		&handle);

	return retval;
}


long CANBus::filterOff()
{
	long retval = canEnableAllIds(handle, true);
	if ( retval != 0 )
	{
		cout << " handle: " << handle << endl;
		cout << "error in filterOff: " << retval << endl;
		system("PAUSE");
		exit(1);
	}

	return retval;
}

long CANBus::readMsg()
{
	msgCount = recBufSize;

	long retval = canRead(handle, canMsg, &msgCount);

	if (retval != 0 )
	{
		cout << "error in readMsg: " << retval << endl;
		throw retval;
	}

	return retval;
}

void CANBus::printMsg()
{

	for ( int i = 0; i < msgCount; i++ )
	{
		printf("TIME: %d ", canMsg[i].ul_tstamp); 

		printf ( "ID: %03X ", canMsg[i].l_id );
		//printf ( "n bytes: %ld\n",	canMsg[i].by_len & 0x0F );
		// print data bytes
		printf( " Data: ");
		for (int k = 0; k < (canMsg[i].by_len & 0x0F); k++ )
		{
			printf ( "%02X ", canMsg[i].aby_data[k] );
		}
		printf ( "\n\n" );
	}
}

char* CANBus::getMsg()
{
//	string str;
	
	//for (int i=0; i< msgCount; i++)
	//{
	//	str += "ID: " + to_string<long>(canMsg[i].l_id, std::hex) + " ";
	//	str += " DATA:";
	//	for (int k = 0; k < (canMsg[i].by_len & 0x0F); k++ )
	//	{
	//		str += " "+ to_string<long>(canMsg[i].aby_data[k], std::hex);
	//	}
	//}

	sprintf (buffer, "ID: %03X Data: %02X %02X %02X %02X %02X %02X %02X %02X \0"
		, canMsg[0].l_id
		, canMsg[0].aby_data[0]
		, canMsg[0].aby_data[1]
		, canMsg[0].aby_data[2]
		, canMsg[0].aby_data[3]
		, canMsg[0].aby_data[4]
		, canMsg[0].aby_data[5]
		, canMsg[0].aby_data[6]
		, canMsg[0].aby_data[7]
		);

	return buffer;
}

long CANBus::sendMsg8(unsigned char id, unsigned char* data)
{
	CMSG msg;
	msg.aby_data[0] = data[0];
	msg.aby_data[1] = data[1];
	msg.aby_data[2] = data[2];
	msg.aby_data[3] = data[3];
	msg.aby_data[4] = data[4];
	msg.aby_data[5] = data[5];
	msg.aby_data[6] = data[6];
	msg.aby_data[7] = data[7];
	msg.l_id = id;
	msg.by_len = 8;
	msg.by_extended = 0;
	msg.by_remote = 0;
	long len =1;

	long retval = canSend(handle, &msg, &len);

	return retval;
}

long CANBus::sendMsg8(CMSG msg)
{
	long len =1;
	long retval = canSend(handle, &msg, &len);
	return retval;
}