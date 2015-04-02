/* discoWSServer.c
   Generated by gSOAP 2.8.21 from wsdiscovery.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "discoWSH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) discoWSServer.c ver 2.8.21 2015-04-01 12:44:52 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "SOAP-ENV:Fault"))
		return soap_serve_SOAP_ENV__Fault(soap);
	if (!soap_match_tag(soap, soap->tag, "wsdd:Hello"))
		return soap_serve___wsdd__Hello(soap);
	if (!soap_match_tag(soap, soap->tag, "wsdd:Bye"))
		return soap_serve___wsdd__Bye(soap);
	if (!soap_match_tag(soap, soap->tag, "wsdd:Probe"))
		return soap_serve___wsdd__Probe(soap);
	if (!soap_match_tag(soap, soap->tag, "wsdd:ProbeMatches"))
		return soap_serve___wsdd__ProbeMatches(soap);
	if (!soap_match_tag(soap, soap->tag, "wsdd:Resolve"))
		return soap_serve___wsdd__Resolve(soap);
	if (!soap_match_tag(soap, soap->tag, "wsdd:ResolveMatches"))
		return soap_serve___wsdd__ResolveMatches(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_SOAP_ENV__Fault(struct soap *soap)
{	struct SOAP_ENV__Fault soap_tmp_SOAP_ENV__Fault;
	soap_default_SOAP_ENV__Fault(soap, &soap_tmp_SOAP_ENV__Fault);
	if (!soap_get_SOAP_ENV__Fault(soap, &soap_tmp_SOAP_ENV__Fault, "SOAP-ENV:Fault", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = SOAP_ENV__Fault(soap, soap_tmp_SOAP_ENV__Fault.faultcode, soap_tmp_SOAP_ENV__Fault.faultstring, soap_tmp_SOAP_ENV__Fault.faultactor, soap_tmp_SOAP_ENV__Fault.detail, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Code, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Reason, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Node, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Role, soap_tmp_SOAP_ENV__Fault.SOAP_ENV__Detail);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsdd__Hello(struct soap *soap)
{	struct __wsdd__Hello soap_tmp___wsdd__Hello;
	soap_default___wsdd__Hello(soap, &soap_tmp___wsdd__Hello);
	if (!soap_get___wsdd__Hello(soap, &soap_tmp___wsdd__Hello, "-wsdd:Hello", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsdd__Hello(soap, soap_tmp___wsdd__Hello.wsdd__Hello);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsdd__Bye(struct soap *soap)
{	struct __wsdd__Bye soap_tmp___wsdd__Bye;
	soap_default___wsdd__Bye(soap, &soap_tmp___wsdd__Bye);
	if (!soap_get___wsdd__Bye(soap, &soap_tmp___wsdd__Bye, "-wsdd:Bye", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsdd__Bye(soap, soap_tmp___wsdd__Bye.wsdd__Bye);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsdd__Probe(struct soap *soap)
{	struct __wsdd__Probe soap_tmp___wsdd__Probe;
	soap_default___wsdd__Probe(soap, &soap_tmp___wsdd__Probe);
	if (!soap_get___wsdd__Probe(soap, &soap_tmp___wsdd__Probe, "-wsdd:Probe", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsdd__Probe(soap, soap_tmp___wsdd__Probe.wsdd__Probe);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsdd__ProbeMatches(struct soap *soap)
{	struct __wsdd__ProbeMatches soap_tmp___wsdd__ProbeMatches;
	soap_default___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches);
	if (!soap_get___wsdd__ProbeMatches(soap, &soap_tmp___wsdd__ProbeMatches, "-wsdd:ProbeMatches", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsdd__ProbeMatches(soap, soap_tmp___wsdd__ProbeMatches.wsdd__ProbeMatches);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsdd__Resolve(struct soap *soap)
{	struct __wsdd__Resolve soap_tmp___wsdd__Resolve;
	soap_default___wsdd__Resolve(soap, &soap_tmp___wsdd__Resolve);
	if (!soap_get___wsdd__Resolve(soap, &soap_tmp___wsdd__Resolve, "-wsdd:Resolve", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsdd__Resolve(soap, soap_tmp___wsdd__Resolve.wsdd__Resolve);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___wsdd__ResolveMatches(struct soap *soap)
{	struct __wsdd__ResolveMatches soap_tmp___wsdd__ResolveMatches;
	soap_default___wsdd__ResolveMatches(soap, &soap_tmp___wsdd__ResolveMatches);
	if (!soap_get___wsdd__ResolveMatches(soap, &soap_tmp___wsdd__ResolveMatches, "-wsdd:ResolveMatches", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __wsdd__ResolveMatches(soap, soap_tmp___wsdd__ResolveMatches.wsdd__ResolveMatches);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of discoWSServer.c */
