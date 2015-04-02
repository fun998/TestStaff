#include <stdio.h>
#include "wsdd.nsmap"
#include "discoWSH.h"
#include "wsaapi.h"
#include "wsddapi.h"

int main()
{
	struct soap* soap = soap_new();
	// struct soap* serv = soap_new();

	struct __wsdd__ProbeMatches resp;
	
	const char* id = soap_wsa_rand_uuid(soap);
	soap_wsdd_Probe(soap,
	  SOAP_WSDD_ADHOC,
	  SOAP_WSDD_TO_TS,
	  "soap.udp://239.255.255.250:3702/",
	  id,
	  NULL,
	  "tdn:NetworkVideoTransmitter",
	  "onvif://www.onvif.org",
	  NULL);
	
	// soap_bind(serv, "localhost", 10080, 100);
	
	if((soap_recv___wsdd__ProbeMatches(soap, &resp) == SOAP_OK) && !soap->error)
	{
		printf("Device Service Address  : %s\r\n", resp.wsdd__ProbeMatches->ProbeMatch->XAddrs);    
		printf("Device EP Address       : %s\r\n", resp.wsdd__ProbeMatches->ProbeMatch->wsa__EndpointReference.Address);    
		printf("Device Type             : %s\r\n", resp.wsdd__ProbeMatches->ProbeMatch->Types);    
		printf("Device Metadata Version : %d\r\n", resp.wsdd__ProbeMatches->ProbeMatch->MetadataVersion); 
	}
	
	return 0;
}
