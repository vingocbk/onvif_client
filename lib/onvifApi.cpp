#include "onvifApi.h"
#include "wsdd.nsmap"


onvifApi::onvifApi(std::string ip, int port)
{
    this->ip = ip;
    this->port = port;
    this->username.erase();
    this->password.erase();
    this->endpoint_device = "http://" + ip + ":" + std::to_string(port) + "/onvif/device_service";
    this->getEndpoint();
    this->getProfileToken();
}

onvifApi::onvifApi(std::string ip, int port, std::string username, std::string password)
{
    struct soap *soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
    this->soap = soap;
    this->ip = ip;
    this->port = port;
    this->endpoint_device = "http://" + ip + ":" + std::to_string(port) + "/onvif/device_service";
    this->username = username;
    this->password = password;
    this->getEndpoint();
    this->getProfileToken();
}

onvifApi::onvifApi(struct soap *soap, std::string ip, int port, std::string username, std::string password)
{
    this->soap = soap;
    this->ip = ip;
    this->port = port;
    this->endpoint_device = "http://" + ip + ":" + std::to_string(port) + "/onvif/device_service";
    this->username = username;
    this->password = password;
    this->getEndpoint();
    this->getProfileToken();
}

onvifApi::~onvifApi()
{
}

void onvifApi::getEndpoint()
{
    _tds__GetServices tds__GetServices;
    tds__GetServices.IncludeCapability = false;
    _tds__GetServicesResponse tds__GetServicesResponse;
    this->tdsGetServices(&tds__GetServices, tds__GetServicesResponse);
    for(unsigned int i = 0; i < tds__GetServicesResponse.Service.size(); i++)
    {
        if(tds__GetServicesResponse.Service[i]->Namespace.find("media") != -1)
        {
            std::size_t index = tds__GetServicesResponse.Service[i]->XAddr.find("/onvif");
            this->endpoint_media = "http://" + ip + ":" + std::to_string(port) + tds__GetServicesResponse.Service[i]->XAddr.erase(0, index);
        }
        else if(tds__GetServicesResponse.Service[i]->Namespace.find("imaging") != -1)
        {
            std::size_t index = tds__GetServicesResponse.Service[i]->XAddr.find("/onvif");
            this->endpoint_imaging = "http://" + ip + ":" + std::to_string(port) + tds__GetServicesResponse.Service[i]->XAddr.erase(0, index);
        }
        else if(tds__GetServicesResponse.Service[i]->Namespace.find("ptz") != -1)
        {
            std::size_t index = tds__GetServicesResponse.Service[i]->XAddr.find("/onvif");
            this->endpoint_ptz = "http://" + ip + ":" + std::to_string(port) + tds__GetServicesResponse.Service[i]->XAddr.erase(0, index);
        }
        else if(tds__GetServicesResponse.Service[i]->Namespace.find("events") != -1)
        {
            std::size_t index = tds__GetServicesResponse.Service[i]->XAddr.find("/onvif");
            this->endpoint_events = "http://" + ip + ":" + std::to_string(port) + tds__GetServicesResponse.Service[i]->XAddr.erase(0, index);
        }
    }

    // _tds__GetCapabilities tds__GetCapabilities;
    // tds__GetCapabilities.Category.push_back(tt__CapabilityCategory__All);
    // _tds__GetCapabilitiesResponse tds__GetCapabilitiesResponse;
    // this->tdsGetCapabilities(&tds__GetCapabilities, tds__GetCapabilitiesResponse);
    // tds__GetCapabilitiesResponse.Capabilities->Analytics
}

void onvifApi::getProfileToken()
{
    _trt__GetProfiles trt__GetProfiles;
    _trt__GetProfilesResponse trt__GetProfilesResponse;
    this->trtGetProfiles(&trt__GetProfiles, trt__GetProfilesResponse);
    this->profile_token.clear();
    for(unsigned int i = 0; i < trt__GetProfilesResponse.Profiles.size(); i++)
    {
        this->profile_token.push_back(trt__GetProfilesResponse.Profiles[i]->token);
    }
}


void onvifApi::set_credentials(struct soap *soap, std::string username, std::string password)
{
    if(username.empty() && password.empty())
    {
        return;
    }
    soap_wsse_delete_Security(soap);
    if (soap_wsse_add_Timestamp(soap, "Time", 10)
        || soap_wsse_add_UsernameTokenDigest(soap, NULL, username.c_str(), password.c_str()))
        // || soap_wsse_add_UsernameTokenText(soap, "Auth", username.c_str(), password.c_str()))
    {
        report_error(soap);
    }
        
}

void onvifApi::report_error(struct soap *soap)
{
    std::cerr << "Oops, something went wrong:" << std::endl;
    soap_stream_fault(soap, std::cerr);
    exit(EXIT_FAILURE);
}

void onvifApi::tdsGetCapabilities(_tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse &tds__GetCapabilitiesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetCapabilities(tds__GetCapabilities, tds__GetCapabilitiesResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetDeviceInformation(_tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse &tds__GetDeviceInformationResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetDeviceInformation(tds__GetDeviceInformation, tds__GetDeviceInformationResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetDNS(_tds__GetDNS *tds__GetDNS, _tds__GetDNSResponse &tds__GetDNSResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetDNS(tds__GetDNS, tds__GetDNSResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetDynamicDNS(_tds__GetDynamicDNS *tds__GetDynamicDNS, _tds__GetDynamicDNSResponse &tds__GetDynamicDNSResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetDynamicDNS(tds__GetDynamicDNS, tds__GetDynamicDNSResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetHostname(_tds__GetHostname *tds__GetHostname, _tds__GetHostnameResponse &tds__GetHostnameResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetHostname(tds__GetHostname, tds__GetHostnameResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetNetworkInterfaces(_tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, _tds__GetNetworkInterfacesResponse &tds__GetNetworkInterfacesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetNetworkInterfaces(tds__GetNetworkInterfaces, tds__GetNetworkInterfacesResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetNetworkProtocols(_tds__GetNetworkProtocols *tds__GetNetworkProtocols, _tds__GetNetworkProtocolsResponse &tds__GetNetworkProtocolsResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetNetworkProtocols(tds__GetNetworkProtocols, tds__GetNetworkProtocolsResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetScopes(_tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse &tds__GetScopesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetScopes(tds__GetScopes, tds__GetScopesResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetServices(_tds__GetServices *tds__GetServices, _tds__GetServicesResponse &tds__GetServicesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetServices(tds__GetServices, tds__GetServicesResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetSystemDateAndTime(_tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse &tds__GetSystemDateAndTimeResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetSystemDateAndTime(tds__GetSystemDateAndTime, tds__GetSystemDateAndTimeResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsGetUsers(_tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse &tds__GetUsersResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetUsers(tds__GetUsers, tds__GetUsersResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tdsSetScopes(_tds__SetScopes *tds__SetScopes, _tds__SetScopesResponse &tds__SetScopesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.SetScopes(tds__SetScopes, tds__SetScopesResponse))
    {
        report_error(this->soap);
    }
}

// For Onvif Media Service
void onvifApi::trtGetProfiles(_trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse)
{
    MediaBindingProxy proxyMedia(this->soap);
    proxyMedia.soap_endpoint = this->endpoint_media.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyMedia.GetProfiles(trt__GetProfiles, trt__GetProfilesResponse))
    {
        report_error(this->soap);
    }
}


// For Onvif Ptz Service
//Get
void onvifApi::tptzGetNodes(_tptz__GetNodes *tptz__GetNodes, _tptz__GetNodesResponse &tptz__GetNodesResponse)
{
    PTZBindingProxy proxyPTZ(this->soap);
    proxyPTZ.soap_endpoint = this->endpoint_ptz.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyPTZ.GetNodes(tptz__GetNodes, tptz__GetNodesResponse))
    {
        report_error(this->soap);
    }
}

//Set
void onvifApi::tptzContinuousMove(_tptz__ContinuousMove *tptz__ContinuousMove, _tptz__ContinuousMoveResponse &tptz__ContinuousMoveResponse)
{
    PTZBindingProxy proxyPTZ(this->soap);
    proxyPTZ.soap_endpoint = this->endpoint_ptz.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyPTZ.ContinuousMove(tptz__ContinuousMove, tptz__ContinuousMoveResponse))
    {
        report_error(this->soap);
    }
}

void onvifApi::tptzStop(_tptz__Stop *tptz__Stop, _tptz__StopResponse &tptz__StopResponse)
{
    PTZBindingProxy proxyPTZ(this->soap);
    proxyPTZ.soap_endpoint = this->endpoint_ptz.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyPTZ.Stop(tptz__Stop, tptz__StopResponse))
    {
        report_error(this->soap);
    }
}


























/******************************************************************************\
 *
 *	WS-Discovery event handlers must be defined, even when not used
 *
\******************************************************************************/

void wsdd_event_Hello(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int MetadataVersion)
{ }

void wsdd_event_Bye(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int *MetadataVersion)
{ }

soap_wsdd_mode wsdd_event_Probe(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *Types, const char *Scopes, const char *MatchBy, struct wsdd__ProbeMatchesType *ProbeMatches)
{
  	return SOAP_WSDD_ADHOC;
}

void wsdd_event_ProbeMatches(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, struct wsdd__ProbeMatchesType *ProbeMatches)
{ }

soap_wsdd_mode wsdd_event_Resolve(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *EndpointReference, struct wsdd__ResolveMatchType *match)
{
  	return SOAP_WSDD_ADHOC;
}

void wsdd_event_ResolveMatches(struct soap *soap, unsigned int InstanceId, const char * SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, struct wsdd__ResolveMatchType *match)
{ }

int SOAP_ENV__Fault(struct soap *soap, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail)
{
	// populate the fault struct from the operation arguments to print it
	soap_fault(soap);
	// SOAP 1.1
	soap->fault->faultcode = faultcode;
	soap->fault->faultstring = faultstring;
	soap->fault->faultactor = faultactor;
	soap->fault->detail = detail;
	// SOAP 1.2
	soap->fault->SOAP_ENV__Code = SOAP_ENV__Code;
	soap->fault->SOAP_ENV__Reason = SOAP_ENV__Reason;
	soap->fault->SOAP_ENV__Node = SOAP_ENV__Node;
	soap->fault->SOAP_ENV__Role = SOAP_ENV__Role;
	soap->fault->SOAP_ENV__Detail = SOAP_ENV__Detail;
	// set error
	soap->error = SOAP_FAULT;
	// handle or display the fault here with soap_stream_fault(soap, std::cerr);
	// return HTTP 202 Accepted
	return soap_send_empty_response(soap, SOAP_OK);
}