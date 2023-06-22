#ifndef OnvifApi_H
#define OnvifApi_H

#include "soapDeviceBindingProxy.h"
#include "soapAdvancedSecurityServiceBindingProxy.h"
// #include "soapCredentialBindingProxy.h"
// #include "soapDeviceIOBindingProxy.h"
// #include "soapReceiverBindingProxy.h"
// #include "soapRecordingBindingProxy.h"
// #include "soapReplayBindingProxy.h"
// #include "soapRuleEngineBindingProxy.h"
// #include "soapScheduleBindingProxy.h"
#include "soapMediaBindingProxy.h"
#include "soapImagingBindingProxy.h"
#include "soapPTZBindingProxy.h"
#include "soapPullPointSubscriptionBindingProxy.h"
#include "soapRemoteDiscoveryBindingProxy.h" 
#include "wsddapi.h"
#include "wsseapi.h"


struct ClientInfo
{
    std::string ip;
    int port;
    std::string username;
    std::string password;
    bool useHttps = false;
};


class OnvifApi
{
public:
    /* data */
    struct soap *soap;

    OnvifApi();
    OnvifApi(struct soap *soap);
    ~OnvifApi();
    void init();
    //add username and password before login
    void set_credentials(std::string username, std::string password);
    //report error
    void report_error();
    std::string getEndpointDevice(ClientInfo clientInfo);
    std::string getEndpointMedia(ClientInfo clientInfo);
    std::string getEndpointImaging(ClientInfo clientInfo);
    std::string getEndpointPtz(ClientInfo clientInfo);
    
    // For Onvif Device Service
    bool device_CreateUsers(ClientInfo clientInfo, _tds__CreateUsers *tds__CreateUsers, _tds__CreateUsersResponse &tds__CreateUsersResponse);
    bool device_DeleteUsers(ClientInfo clientInfo, _tds__DeleteUsers *tds__DeleteUsers, _tds__DeleteUsersResponse &tds__DeleteUsersResponse);
    bool device_GetCapabilities(ClientInfo clientInfo, _tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse &tds__GetCapabilitiesResponse);
    bool device_GetDeviceInformation(ClientInfo clientInfo, _tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse &tds__GetDeviceInformationResponse);
    bool device_GetDiscoveryMode(ClientInfo clientInfo, _tds__GetDiscoveryMode *tds__GetDiscoveryMode, _tds__GetDiscoveryModeResponse &tds__GetDiscoveryModeResponse);
    bool device_GetHostname(ClientInfo clientInfo, _tds__GetHostname *tds__GetHostname, _tds__GetHostnameResponse &tds__GetHostnameResponse);
    bool device_GetNetworkDefaultGateway(ClientInfo clientInfo, _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, _tds__GetNetworkDefaultGatewayResponse &tds__GetNetworkDefaultGatewayResponse);
    bool device_GetNetworkInterfaces(ClientInfo clientInfo, _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, _tds__GetNetworkInterfacesResponse &tds__GetNetworkInterfacesResponse);
    bool device_GetNetworkProtocols(ClientInfo clientInfo, _tds__GetNetworkProtocols *tds__GetNetworkProtocols, _tds__GetNetworkProtocolsResponse &tds__GetNetworkProtocolsResponse);
    bool device_GetNTP(ClientInfo clientInfo, _tds__GetNTP *tds__GetNTP, _tds__GetNTPResponse &tds__GetNTPResponse);
    bool device_GetScopes(ClientInfo clientInfo, _tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse &tds__GetScopesResponse);
    bool device_GetSystemDateAndTime(ClientInfo clientInfo, _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse &tds__GetSystemDateAndTimeResponse);
    bool device_GetSystemLog(ClientInfo clientInfo, _tds__GetSystemLog *tds__GetSystemLog, _tds__GetSystemLogResponse &tds__GetSystemLogResponse);
    bool device_GetUsers(ClientInfo clientInfo, _tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse &tds__GetUsersResponse);
    bool device_GetWsdlUrl(ClientInfo clientInfo, _tds__GetWsdlUrl *tds__GetWsdlUrl, _tds__GetWsdlUrlResponse &tds__GetWsdlUrlResponse);
    bool device_RemoveScopes(ClientInfo clientInfo, _tds__RemoveScopes *tds__RemoveScopes, _tds__RemoveScopesResponse &tds__RemoveScopesResponse);
    bool device_SetDiscoveryMode(ClientInfo clientInfo, _tds__SetDiscoveryMode *tds__SetDiscoveryMode, _tds__SetDiscoveryModeResponse &tds__SetDiscoveryModeResponse);
    bool device_SetHostname(ClientInfo clientInfo, _tds__SetHostname *tds__SetHostname, _tds__SetHostnameResponse &tds__SetHostnameResponse);
    bool device_SetIPAddressFilter(ClientInfo clientInfo, _tds__SetIPAddressFilter *tds__SetIPAddressFilter, _tds__SetIPAddressFilterResponse &tds__SetIPAddressFilterResponse);
    bool device_SetNetworkDefaultGateway(ClientInfo clientInfo, _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, _tds__SetNetworkDefaultGatewayResponse &tds__SetNetworkDefaultGatewayResponse);
    bool device_SetNetworkInterfaces(ClientInfo clientInfo, _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, _tds__SetNetworkInterfacesResponse &tds__SetNetworkInterfacesResponse);
    bool device_SetNetworkProtocols(ClientInfo clientInfo, _tds__SetNetworkProtocols *tds__SetNetworkProtocols, _tds__SetNetworkProtocolsResponse &tds__SetNetworkProtocolsResponse);
    bool device_SetNTP(ClientInfo clientInfo, _tds__SetNTP *tds__SetNTP, _tds__SetNTPResponse &tds__SetNTPResponse);
    bool device_SetScopes(ClientInfo clientInfo, _tds__SetScopes *tds__SetScopes, _tds__SetScopesResponse &tds__SetScopesResponse);
    bool device_SetSystemDateAndTime(ClientInfo clientInfo, _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, _tds__SetSystemDateAndTimeResponse &tds__SetSystemDateAndTimeResponse);
    bool device_SetUser(ClientInfo clientInfo, _tds__SetUser *tds__SetUser, _tds__SetUserResponse &tds__SetUserResponse);
    bool device_SystemReboot(ClientInfo clientInfo, _tds__SystemReboot *tds__SystemReboot, _tds__SystemRebootResponse &tds__SystemRebootResponse);
    bool device_GetServices(ClientInfo clientInfo, _tds__GetServices *tds__GetServices, _tds__GetServicesResponse &tds__GetServicesResponse);
    bool device_GetServiceCapabilities(ClientInfo clientInfo, _tds__GetServiceCapabilities *tds__GetServiceCapabilities, _tds__GetServiceCapabilitiesResponse &tds__GetServiceCapabilitiesResponse);

    bool media_CreateProfile(ClientInfo clientInfo, _trt__CreateProfile *trt__CreateProfile, _trt__CreateProfileResponse &trt__CreateProfileResponse);
    bool media_DeleteProfile(ClientInfo clientInfo, _trt__DeleteProfile *trt__DeleteProfile, _trt__DeleteProfileResponse &trt__DeleteProfileResponse);
    bool media_GetCompatibleMetadataConfigurations(ClientInfo clientInfo, _trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, _trt__GetCompatibleMetadataConfigurationsResponse &trt__GetCompatibleMetadataConfigurationsResponse);
    bool media_GetCompatibleVideoAnalyticsConfigurations(ClientInfo clientInfo, _trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, _trt__GetCompatibleVideoAnalyticsConfigurationsResponse &trt__GetCompatibleVideoAnalyticsConfigurationsResponse);
    bool media_GetCompatibleVideoEncoderConfigurations(ClientInfo clientInfo, _trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, _trt__GetCompatibleVideoEncoderConfigurationsResponse &trt__GetCompatibleVideoEncoderConfigurationsResponse);
    bool media_GetCompatibleVideoSourceConfigurations(ClientInfo clientInfo, _trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, _trt__GetCompatibleVideoSourceConfigurationsResponse &trt__GetCompatibleVideoSourceConfigurationsResponse);
    bool media_GetMetadataConfiguration(ClientInfo clientInfo, _trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, _trt__GetMetadataConfigurationResponse &trt__GetMetadataConfigurationResponse);
    bool media_GetMetadataConfigurationOptions(ClientInfo clientInfo, _trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, _trt__GetMetadataConfigurationOptionsResponse &trt__GetMetadataConfigurationOptionsResponse);
    bool media_GetMetadataConfigurations(ClientInfo clientInfo, _trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, _trt__GetMetadataConfigurationsResponse &trt__GetMetadataConfigurationsResponse);
    bool media_GetProfile(ClientInfo clientInfo, _trt__GetProfile *trt__GetProfile, _trt__GetProfileResponse &trt__GetProfileResponse);
    bool media_GetProfiles(ClientInfo clientInfo, _trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse);
    bool media_GetSnapshotUri(ClientInfo clientInfo, _trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse);
    bool media_GetStreamUri(ClientInfo clientInfo, _trt__GetStreamUri *trt__GetStreamUri, _trt__GetStreamUriResponse &trt__GetStreamUriResponse);
    bool media_GetVideoAnalyticsConfiguration(ClientInfo clientInfo, _trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, _trt__GetVideoAnalyticsConfigurationResponse &trt__GetVideoAnalyticsConfigurationResponse);
    bool media_GetVideoAnalyticsConfigurations(ClientInfo clientInfo, _trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, _trt__GetVideoAnalyticsConfigurationsResponse &trt__GetVideoAnalyticsConfigurationsResponse);
    bool media_GetVideoEncoderConfiguration(ClientInfo clientInfo, _trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, _trt__GetVideoEncoderConfigurationResponse &trt__GetVideoEncoderConfigurationResponse);
    bool media_GetVideoEncoderConfigurationOptions(ClientInfo clientInfo, _trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, _trt__GetVideoEncoderConfigurationOptionsResponse &trt__GetVideoEncoderConfigurationOptionsResponse);
    bool media_GetVideoEncoderConfigurations(ClientInfo clientInfo, _trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, _trt__GetVideoEncoderConfigurationsResponse &trt__GetVideoEncoderConfigurationsResponse);
    bool media_GetVideoSourceConfiguration(ClientInfo clientInfo, _trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, _trt__GetVideoSourceConfigurationResponse &trt__GetVideoSourceConfigurationResponse);
    bool media_GetVideoSourceConfigurationOptions(ClientInfo clientInfo, _trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, _trt__GetVideoSourceConfigurationOptionsResponse &trt__GetVideoSourceConfigurationOptionsResponse);
    bool media_GetVideoSourceConfigurations(ClientInfo clientInfo, _trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, _trt__GetVideoSourceConfigurationsResponse &trt__GetVideoSourceConfigurationsResponse);
    bool media_GetVideoSources(ClientInfo clientInfo, _trt__GetVideoSources *trt__GetVideoSources, _trt__GetVideoSourcesResponse &trt__GetVideoSourcesResponse);
    bool media_SetMetadataConfiguration(ClientInfo clientInfo, _trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, _trt__SetMetadataConfigurationResponse &trt__SetMetadataConfigurationResponse);
    bool media_SetSynchronizationPoint(ClientInfo clientInfo, _trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, _trt__SetSynchronizationPointResponse &trt__SetSynchronizationPointResponse);
    bool media_SetVideoAnalyticsConfiguration(ClientInfo clientInfo, _trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, _trt__SetVideoAnalyticsConfigurationResponse &trt__SetVideoAnalyticsConfigurationResponse);
    bool media_SetVideoEncoderConfiguration(ClientInfo clientInfo, _trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, _trt__SetVideoEncoderConfigurationResponse &trt__SetVideoEncoderConfigurationResponse);
    bool media_SetVideoSourceConfiguration(ClientInfo clientInfo, _trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, _trt__SetVideoSourceConfigurationResponse &trt__SetVideoSourceConfigurationResponse);
    bool media_GetServiceCapabilities(ClientInfo clientInfo, _trt__GetServiceCapabilities *trt__GetServiceCapabilities, _trt__GetServiceCapabilitiesResponse &trt__GetServiceCapabilitiesResponse);

    bool imaging_GetImagingSettings(ClientInfo clientInfo, _timg__GetImagingSettings *timg__GetImagingSettings, _timg__GetImagingSettingsResponse &timg__GetImagingSettingsResponse);
    bool imaging_GetMoveOptions(ClientInfo clientInfo, _timg__GetMoveOptions *timg__GetMoveOptions, _timg__GetMoveOptionsResponse &timg__GetMoveOptionsResponse);
    bool imaging_GetOptions(ClientInfo clientInfo, _timg__GetOptions *timg__GetOptions, _timg__GetOptionsResponse &timg__GetOptionsResponse);
    bool imaging_GetStatus(ClientInfo clientInfo, _timg__GetStatus *timg__GetStatus, _timg__GetStatusResponse &timg__GetStatusResponse);
    bool imaging_Move(ClientInfo clientInfo, _timg__Move *timg__Move, _timg__MoveResponse &timg__MoveResponse);
    bool imaging_SetImagingSettings(ClientInfo clientInfo, _timg__SetImagingSettings *timg__SetImagingSettings, _timg__SetImagingSettingsResponse &timg__SetImagingSettingsResponse);
    bool imaging_Stop(ClientInfo clientInfo, _timg__Stop *timg__Stop, _timg__StopResponse &timg__StopResponse);
    bool imaging_GetServiceCapabilities(ClientInfo clientInfo, _timg__GetServiceCapabilities *timg__GetServiceCapabilities, _timg__GetServiceCapabilitiesResponse &timg__GetServiceCapabilitiesResponse);

    bool ptz_AbsoluteMove(ClientInfo clientInfo, _tptz__AbsoluteMove *tptz__AbsoluteMove, _tptz__AbsoluteMoveResponse &tptz__AbsoluteMoveResponse);
    bool ptz_ContinuousMove(ClientInfo clientInfo, _tptz__ContinuousMove *tptz__ContinuousMove, _tptz__ContinuousMoveResponse &tptz__ContinuousMoveResponse);
    bool ptz_GetConfiguration(ClientInfo clientInfo, _tptz__GetConfiguration *tptz__GetConfiguration, _tptz__GetConfigurationResponse &tptz__GetConfigurationResponse);
    bool ptz_GetConfigurationOptions(ClientInfo clientInfo, _tptz__GetConfigurationOptions *tptz__GetConfigurationOptions, _tptz__GetConfigurationOptionsResponse &tptz__GetConfigurationOptionsResponse);
    bool ptz_GetConfigurations(ClientInfo clientInfo, _tptz__GetConfigurations *tptz__GetConfigurations, _tptz__GetConfigurationsResponse &tptz__GetConfigurationsResponse);
    bool ptz_GetNode(ClientInfo clientInfo, _tptz__GetNode *tptz__GetNode, _tptz__GetNodeResponse &tptz__GetNodeResponse);
    bool ptz_GetNodes(ClientInfo clientInfo, _tptz__GetNodes *tptz__GetNodes, _tptz__GetNodesResponse &tptz__GetNodesResponse);
    bool ptz_GetPresets(ClientInfo clientInfo, _tptz__GetPresets *tptz__GetPresets, _tptz__GetPresetsResponse &tptz__GetPresetsResponse);
    bool ptz_GetStatus(ClientInfo clientInfo, _tptz__GetStatus *tptz__GetStatus, _tptz__GetStatusResponse &tptz__GetStatusResponse);
    bool ptz_GotoHomePosition(ClientInfo clientInfo, _tptz__GotoHomePosition *tptz__GotoHomePosition, _tptz__GotoHomePositionResponse &tptz__GotoHomePositionResponse);
    bool ptz_GotoPreset(ClientInfo clientInfo, _tptz__GotoPreset *tptz__GotoPreset, _tptz__GotoPresetResponse &tptz__GotoPresetResponse);
    bool ptz_RelativeMove(ClientInfo clientInfo, _tptz__RelativeMove *tptz__RelativeMove, _tptz__RelativeMoveResponse &tptz__RelativeMoveResponse);
    bool ptz_RemovePreset(ClientInfo clientInfo, _tptz__RemovePreset *tptz__RemovePreset, _tptz__RemovePresetResponse &tptz__RemovePresetResponse);
    bool ptz_SetConfiguration(ClientInfo clientInfo, _tptz__SetConfiguration *tptz__SetConfiguration, _tptz__SetConfigurationResponse &tptz__SetConfigurationResponse);
    bool ptz_SetHomePosition(ClientInfo clientInfo, _tptz__SetHomePosition *tptz__SetHomePosition, _tptz__SetHomePositionResponse &tptz__SetHomePositionResponse);
    bool ptz_SetPreset(ClientInfo clientInfo, _tptz__SetPreset *tptz__SetPreset, _tptz__SetPresetResponse &tptz__SetPresetResponse);
    bool ptz_Stop(ClientInfo clientInfo, _tptz__Stop *tptz__Stop, _tptz__StopResponse &tptz__StopResponse);
    bool ptz_GetPresetTour(ClientInfo clientInfo, _tptz__GetPresetTour *tptz__GetPresetTour, _tptz__GetPresetTourResponse &tptz__GetPresetTourResponse);
    bool ptz_GetPresetTours(ClientInfo clientInfo, _tptz__GetPresetTours *tptz__GetPresetTours, _tptz__GetPresetToursResponse &tptz__GetPresetToursResponse);
    bool ptz_GetPresetTourOptions(ClientInfo clientInfo, _tptz__GetPresetTourOptions *tptz__GetPresetTourOptions, _tptz__GetPresetTourOptionsResponse &tptz__GetPresetTourOptionsResponse);
    bool ptz_CreatePresetTour(ClientInfo clientInfo, _tptz__CreatePresetTour *tptz__CreatePresetTour, _tptz__CreatePresetTourResponse &tptz__CreatePresetTourResponse);
    bool ptz_ModifyPresetTour(ClientInfo clientInfo, _tptz__ModifyPresetTour *tptz__ModifyPresetTour, _tptz__ModifyPresetTourResponse &tptz__ModifyPresetTourResponse);
    bool ptz_OperatePresetTour(ClientInfo clientInfo, _tptz__OperatePresetTour *tptz__OperatePresetTour, _tptz__OperatePresetTourResponse &tptz__OperatePresetTourResponse);
    bool ptz_RemovePresetTour(ClientInfo clientInfo, _tptz__RemovePresetTour *tptz__RemovePresetTour, _tptz__RemovePresetTourResponse &tptz__RemovePresetTourResponse);
    bool ptz_GetServiceCapabilities(ClientInfo clientInfo, _tptz__GetServiceCapabilities *tptz__GetServiceCapabilities, _tptz__GetServiceCapabilitiesResponse &tptz__GetServiceCapabilitiesResponse);
};



#endif  //OnvifApi_H