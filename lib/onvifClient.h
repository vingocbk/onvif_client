#ifndef onvifClient_H
#define onvifClient_H

#include "onvifApi.h"

class onvifClient
{
public:
    onvifClient(std::string ip, int port);
    onvifClient(std::string ip, int port, std::string username, std::string password);
    onvifClient(struct soap *soap, std::string ip, int port, std::string username, std::string password);
    ~onvifClient();

    onvifApi *onvifClientApi;
    struct soap *soap;

    struct tds_onvif_Capabilities *Capabilities;
    struct tds_onvif_DeviceInformation *DeviceInformation;
    struct tds_onvif_HostnameInformation *HostnameInformation;
    struct tds_onvif_NetworkInterfaces *NetworkInterfaces;
    struct tds_onvif_NetworkProtocols *NetworkProtocols;
    struct tds_onvif_SystemDateTime *SystemDateTime;

    struct trt_onvif_Profile *Profile;
    struct trt_onvif_VideoSource *VideoSource;

    void tdsOnvifGetDeviceInformation();
    void cusGetIdentification(struct cus_onvif_Identification &onvif_IdentificationResponse);
    void cusSetIdentification(struct cus_onvif_Identification *onvif_Identification);
    
    void cusTptzContinuousMove(struct cus_onvif_tptz_ContinuousMove *onvif_tptz_ContinuousMove);
    void cusTptzStop(struct cus_onvif_tptz_Stop *onvif_tptz_Stop);
    // void 
};



#endif