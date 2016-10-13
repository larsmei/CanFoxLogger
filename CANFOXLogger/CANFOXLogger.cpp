// CANFOXLogger.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "CANLIB.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	CANBus* cFox;

	try 
	{
		cFox = new CANBus(105L,1L,1L,-1L,1000L,CANBus::B125k);
		cFox->filterOff();
	}
	catch ( long e )
	{
		cout << "Hardware error!" << endl;
		cout << "Error Number: " << e << endl;
		system("PAUSE");
		return 0;
	}

	cout << "CANFOXLogger V0.1 von Lars Meindl" << endl;
	cout << "lars.meindl@meindl-hameln.de" << endl << endl;
	cout << "Begin Reading: " << endl;

	
	
	while (  true )
	{
		cFox->readMsg();
		cFox->printMsg();
		//cout << cFox->getMsg() << endl;
	}

	system("PAUSE");
	return 0;
}

