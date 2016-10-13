// CANFOXSender.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "CANLIB.h"


int _tmain(int argc, _TCHAR* argv[])
{

	unsigned char cid;
	unsigned char cdata[8];

	CANBus* cFox;

	try 
	{
		cFox = new CANBus(105L,1L,1L,-1L,1000L,CANBus::B125k);
	}
	catch ( long e )
	{
		cout << "Hardware error!" << endl;
		cout << "Error Number: " << e << endl;
		system("PAUSE");
		return 0;
	}


	cout << "CANFOXSender V0.1 von Lars Meindl" << endl;
	cout << "lars.meindl@meindl-hameln.de" << endl << endl;


	while ( true )
	{ 
		cout << "Enter telegram (hex): ID D1 D2 D3 D4 D5 D6 D7 D8" << endl;
		if (
			scanf_s("%x %x %x %x %x %x %x %x %x",
				&cid,
				&cdata[0],
				&cdata[1],
				&cdata[2],
				&cdata[3],
				&cdata[4],
				&cdata[5],
				&cdata[6],
				&cdata[7])
				!= 9 )
		{
				break;
		}
		else
		{
			long retval = cFox->sendMsg8(cid,cdata);
			if ( retval == 0)
			{
				cout << "Message sent successfully" << endl;
			}
			else
			{
				cout << "Error sending: " << retval << endl;
			}
		}
		
	}

	system("PAUSE");
	return 0;
}

