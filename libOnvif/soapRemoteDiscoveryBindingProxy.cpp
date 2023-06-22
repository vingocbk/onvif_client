/* soapRemoteDiscoveryBindingProxy.cpp
   Generated by gSOAP 2.8.114 for onvif.h

gSOAP XML Web services tools
Copyright (C) 2000-2021, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapRemoteDiscoveryBindingProxy.h"

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy()
{	this->soap = soap_new();
	this->soap_own = true;
	RemoteDiscoveryBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy(const RemoteDiscoveryBindingProxy& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
}

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	RemoteDiscoveryBindingProxy_init(_soap->imode, _soap->omode);
}

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy(struct soap *_soap, const char *soap_endpoint_url)
{	this->soap = _soap;
	this->soap_own = false;
	RemoteDiscoveryBindingProxy_init(_soap->imode, _soap->omode);
	soap_endpoint = soap_endpoint_url;
}

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy(const char *soap_endpoint_url)
{	this->soap = soap_new();
	this->soap_own = true;
	RemoteDiscoveryBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = soap_endpoint_url;
}

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	RemoteDiscoveryBindingProxy_init(iomode, iomode);
}

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy(const char *soap_endpoint_url, soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	RemoteDiscoveryBindingProxy_init(iomode, iomode);
	soap_endpoint = soap_endpoint_url;
}

RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	RemoteDiscoveryBindingProxy_init(imode, omode);
}

RemoteDiscoveryBindingProxy::~RemoteDiscoveryBindingProxy()
{	if (this->soap_own)
	{	this->destroy();
		soap_free(this->soap);
	}
}

void RemoteDiscoveryBindingProxy::RemoteDiscoveryBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] = {
        { "SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL },
        { "SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL },
        { "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL },
        { "xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL },
        { "chan", "http://schemas.microsoft.com/ws/2005/02/duplex", NULL, NULL },
        { "wsdd", "http://schemas.xmlsoap.org/ws/2005/04/discovery", NULL, NULL },
        { "c14n", "http://www.w3.org/2001/10/xml-exc-c14n#", NULL, NULL },
        { "ds", "http://www.w3.org/2000/09/xmldsig#", NULL, NULL },
        { "saml1", "urn:oasis:names:tc:SAML:1.0:assertion", NULL, NULL },
        { "saml2", "urn:oasis:names:tc:SAML:2.0:assertion", NULL, NULL },
        { "wsu", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd", NULL, NULL },
        { "xenc", "http://www.w3.org/2001/04/xmlenc#", NULL, NULL },
        { "wsc", "http://docs.oasis-open.org/ws-sx/ws-secureconversation/200512", "http://schemas.xmlsoap.org/ws/2005/02/sc", NULL },
        { "wsse", "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd", "http://docs.oasis-open.org/wss/oasis-wss-wssecurity-secext-1.1.xsd", NULL },
        { "wsdd10", "http://tempuri.org/wsdd10.xsd", NULL, NULL },
        { "wsa5", "http://www.w3.org/2005/08/addressing", "http://schemas.xmlsoap.org/ws/2004/08/addressing", NULL },
        { "ns1", "http://www.onvif.org/ver20/analytics/humanface", NULL, NULL },
        { "ns2", "http://www.onvif.org/ver20/analytics/humanbody", NULL, NULL },
        { "ns4", "http://www.onvif.org/ver10/pacs", NULL, NULL },
        { "xmime", "http://tempuri.org/xmime.xsd", NULL, NULL },
        { "xop", "http://www.w3.org/2004/08/xop/include", NULL, NULL },
        { "tt", "http://www.onvif.org/ver10/schema", NULL, NULL },
        { "wsrfbf", "http://docs.oasis-open.org/wsrf/bf-2", NULL, NULL },
        { "wstop", "http://docs.oasis-open.org/wsn/t-1", NULL, NULL },
        { "wsrfr", "http://docs.oasis-open.org/wsrf/r-2", NULL, NULL },
        { "ns3", "http://www.onvif.org/ver10/schedule/wsdl", NULL, NULL },
        { "ns5", "http://www.onvif.org/ver10/credential/wsdl", NULL, NULL },
        { "tan", "http://www.onvif.org/ver20/analytics/wsdl", NULL, NULL },
        { "tas", "http://www.onvif.org/ver10/advancedsecurity/wsdl", NULL, NULL },
        { "tdn", "http://www.onvif.org/ver10/network/wsdl", NULL, NULL },
        { "tds", "http://www.onvif.org/ver10/device/wsdl", NULL, NULL },
        { "tev", "http://www.onvif.org/ver10/events/wsdl", NULL, NULL },
        { "wsnt", "http://docs.oasis-open.org/wsn/b-2", NULL, NULL },
        { "timg", "http://www.onvif.org/ver20/imaging/wsdl", NULL, NULL },
        { "tmd", "http://www.onvif.org/ver10/deviceIO/wsdl", NULL, NULL },
        { "tptz", "http://www.onvif.org/ver20/ptz/wsdl", NULL, NULL },
        { "trc", "http://www.onvif.org/ver10/recording/wsdl", NULL, NULL },
        { "trp", "http://www.onvif.org/ver10/replay/wsdl", NULL, NULL },
        { "trt", "http://www.onvif.org/ver10/media/wsdl", NULL, NULL },
        { "trv", "http://www.onvif.org/ver10/receiver/wsdl", NULL, NULL },
        { NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this->soap, namespaces);
}

RemoteDiscoveryBindingProxy *RemoteDiscoveryBindingProxy::copy()
{	RemoteDiscoveryBindingProxy *dup = SOAP_NEW_UNMANAGED(RemoteDiscoveryBindingProxy);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}

RemoteDiscoveryBindingProxy& RemoteDiscoveryBindingProxy::operator=(const RemoteDiscoveryBindingProxy& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
		this->soap_endpoint = rhs.soap_endpoint;
	}
	return *this;
}

void RemoteDiscoveryBindingProxy::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void RemoteDiscoveryBindingProxy::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	RemoteDiscoveryBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void RemoteDiscoveryBindingProxy::soap_noheader()
{	this->soap->header = NULL;
}

void RemoteDiscoveryBindingProxy::soap_header(char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance, struct wsdd__AppSequenceType *wsdd__AppSequence, struct _wsse__Security *wsse__Security)
{
	::soap_header(this->soap);
	this->soap->header->wsa5__MessageID = wsa5__MessageID;
	this->soap->header->wsa5__RelatesTo = wsa5__RelatesTo;
	this->soap->header->wsa5__From = wsa5__From;
	this->soap->header->wsa5__ReplyTo = wsa5__ReplyTo;
	this->soap->header->wsa5__FaultTo = wsa5__FaultTo;
	this->soap->header->wsa5__To = wsa5__To;
	this->soap->header->wsa5__Action = wsa5__Action;
	this->soap->header->chan__ChannelInstance = chan__ChannelInstance;
	this->soap->header->wsdd__AppSequence = wsdd__AppSequence;
	this->soap->header->wsse__Security = wsse__Security;
}

::SOAP_ENV__Header *RemoteDiscoveryBindingProxy::soap_header()
{	return this->soap->header;
}

::SOAP_ENV__Fault *RemoteDiscoveryBindingProxy::soap_fault()
{	return this->soap->fault;
}

const char *RemoteDiscoveryBindingProxy::soap_fault_subcode()
{	return ::soap_fault_subcode(this->soap);
}

const char *RemoteDiscoveryBindingProxy::soap_fault_string()
{	return ::soap_fault_string(this->soap);
}

const char *RemoteDiscoveryBindingProxy::soap_fault_detail()
{	return ::soap_fault_detail(this->soap);
}

int RemoteDiscoveryBindingProxy::soap_close_socket()
{	return ::soap_closesock(this->soap);
}

int RemoteDiscoveryBindingProxy::soap_force_close_socket()
{	return ::soap_force_closesock(this->soap);
}

void RemoteDiscoveryBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void RemoteDiscoveryBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *RemoteDiscoveryBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

int RemoteDiscoveryBindingProxy::send_Hello(const char *soap_endpoint_url, const char *soap_action, const struct wsdd__HelloType& tdn__Hello)
{
	struct __tdn__Hello soap_tmp___tdn__Hello;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/network/wsdl/Hello";
	soap_tmp___tdn__Hello.tdn__Hello = tdn__Hello;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___tdn__Hello(soap, &soap_tmp___tdn__Hello);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___tdn__Hello(soap, &soap_tmp___tdn__Hello, "-tdn:Hello", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___tdn__Hello(soap, &soap_tmp___tdn__Hello, "-tdn:Hello", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int RemoteDiscoveryBindingProxy::recv_Hello(struct wsdd__ResolveType &tdn__HelloResponse)
{
	soap_default_wsdd__ResolveType(soap, &tdn__HelloResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_wsdd__ResolveType(soap, &tdn__HelloResponse, "tdn:HelloResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int RemoteDiscoveryBindingProxy::send_Bye(const char *soap_endpoint_url, const char *soap_action, const struct wsdd__ByeType& tdn__Bye)
{
	struct __tdn__Bye soap_tmp___tdn__Bye;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/network/wsdl/Bye";
	soap_tmp___tdn__Bye.tdn__Bye = tdn__Bye;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___tdn__Bye(soap, &soap_tmp___tdn__Bye);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___tdn__Bye(soap, &soap_tmp___tdn__Bye, "-tdn:Bye", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___tdn__Bye(soap, &soap_tmp___tdn__Bye, "-tdn:Bye", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int RemoteDiscoveryBindingProxy::recv_Bye(struct wsdd__ResolveType &tdn__ByeResponse)
{
	soap_default_wsdd__ResolveType(soap, &tdn__ByeResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_wsdd__ResolveType(soap, &tdn__ByeResponse, "tdn:ByeResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int RemoteDiscoveryBindingProxy::send_Probe(const char *soap_endpoint_url, const char *soap_action, const struct wsdd__ProbeType& tdn__Probe)
{
	struct __tdn__Probe soap_tmp___tdn__Probe;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_action == NULL)
		soap_action = "http://www.onvif.org/ver10/network/wsdl/Probe";
	soap_tmp___tdn__Probe.tdn__Probe = tdn__Probe;
	soap_begin(soap);
	soap_set_version(soap, 2); /* use SOAP1.2 */
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___tdn__Probe(soap, &soap_tmp___tdn__Probe);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___tdn__Probe(soap, &soap_tmp___tdn__Probe, "-tdn:Probe", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___tdn__Probe(soap, &soap_tmp___tdn__Probe, "-tdn:Probe", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int RemoteDiscoveryBindingProxy::recv_Probe(struct wsdd__ProbeMatchesType &tdn__ProbeResponse)
{
	soap_default_wsdd__ProbeMatchesType(soap, &tdn__ProbeResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_wsdd__ProbeMatchesType(soap, &tdn__ProbeResponse, "tdn:ProbeResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
