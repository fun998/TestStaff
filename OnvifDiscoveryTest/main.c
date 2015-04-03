#include <stdio.h>
#include "wsdd.nsmap"
#include "discoWSH.h"
#include "wsaapi.h"
#include "wsddapi.h"


#define PROBEMATCHES_LIST_LENGTH 256
#define TIME_OUT 10
int main()
{
	struct soap* soap = soap_new();
	// struct soap* serv = soap_new();

	struct __wsdd__ProbeMatches respTmp;
	struct __wsdd__ProbeMatches *respList = (struct __wsdd__ProbeMatches *)malloc(PROBEMATCHES_LIST_LENGTH * sizeof(respList));

	const char* id = soap_wsa_rand_uuid(soap);

	int result = 0;

	int deviceCount = 0;

	soap->accept_timeout = TIME_OUT;
	soap->connect_timeout = TIME_OUT;
	soap->recv_timeout = TIME_OUT;
	soap->send_timeout = TIME_OUT;

	result = soap_wsdd_Probe(soap,
	  SOAP_WSDD_ADHOC,
	  SOAP_WSDD_TO_TS,
	  "soap.udp://239.255.255.250:3702/",
	  id,
	  NULL,
	  "tdn:NetworkVideoTransmitter",
	  "onvif://www.onvif.org",
	  NULL);
	if(result != NULL)
		printf("%d: %d\n", result, soap->error);
	


	//if((soap_recv___wsdd__ProbeMatches(soap, &respTmp) == SOAP_OK) && !soap->error)
	//{
	//	printf("Device Service Address  : %s\r\n", resp.wsdd__ProbeMatches->ProbeMatch->XAddrs);    
	//	printf("Device EP Address       : %s\r\n", resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.Address);    
	//	printf("Device Type             : %s\r\n", resp.wsdd__ProbeMatches->ProbeMatch->Types);    
	//	printf("Device Metadata Version : %d\r\n", resp.wsdd__ProbeMatches->ProbeMatch->MetadataVersion); 
	//}
	
	
	do
	{
		result = soap_recv___wsdd__ProbeMatches(soap, &respTmp);
		if( result != SOAP_OK)
		{
			break;
		}

		if(soap->error != NULL)
		{
			printf("Line %d, soap_recv___wsdd__ProbeMatches error: %d, %s, %s\n",
				__LINE__, 
				soap->error, 
				*soap_faultcode(soap),
				*soap_faultstring(soap));
			continue;
		}

		if(respTmp.wsdd__ProbeMatches == NULL)
		{
			continue;
		}

		printf("%3d. Type %s at %s\n", 
			deviceCount + 1, 
			respTmp.wsdd__ProbeMatches->ProbeMatch->Types, 
			respTmp.wsdd__ProbeMatches->ProbeMatch->XAddrs);

		respList[deviceCount] = respTmp;
		deviceCount++;

	} while(!soap->error && deviceCount < PROBEMATCHES_LIST_LENGTH);

	printf("%d device(s) found.\n", deviceCount);

	free(respList);

	soap_destroy(soap);   
    soap_end(soap);   
    soap_free(soap); 

	return 0;
}
