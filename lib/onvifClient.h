#ifndef onvifClient_H
#define onvifClient_H

#include "soapDeviceBindingProxy.h"
#include "soapMediaBindingProxy.h"
#include "soapPTZBindingProxy.h"
#include "soapPullPointSubscriptionBindingProxy.h"
#include "soapRemoteDiscoveryBindingProxy.h" 
#include "wsddapi.h"
#include "wsseapi.h"
#include "httpget.h"
// #include "wsdd.nsmap"


class onvifClient
{
public:
    /* data */
    std::string endpoint_device;
    std::string endpoint_media;
    std::string endpoint_event;
    std::string endpoint_ptz;
    std::string ip;
    int port;
    std::string username;
    std::string password;
    onvifClient();
    onvifClient(std::string username, std::string password);
    onvifClient(std::string ip, int port, std::string username, std::string password);
    onvifClient(struct soap *soap, std::string ip, int port, std::string username, std::string password);
    ~onvifClient();

    struct soap *soap;
    void set_credentials(struct soap *soap, std::string username, std::string password);
    void report_error(struct soap *soap);
    // for onvif device service
    void tdsGetCapabilities(_tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse &tds__GetCapabilitiesResponse);
    void tdsGetDeviceInformation(_tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse &tds__GetDeviceInformationResponse);

};



#endif  //onvifClient_H