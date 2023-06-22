#include "onvifApi.h"


OnvifApi::OnvifApi()
{
    struct soap *soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
    soap->connect_timeout = soap->recv_timeout = soap->send_timeout = 10; // 10 sec
    soap_register_plugin(soap, soap_wsse);
    this->soap = soap_copy(soap);
}

OnvifApi::OnvifApi(struct soap *soap)
{
    this->soap = soap_copy(soap);
}

OnvifApi::~OnvifApi()
{
    soap_destroy(this->soap);
    soap_end(this->soap);
    soap_free(this->soap);
}

void OnvifApi::init()
{
    struct soap *soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
    soap->connect_timeout = soap->recv_timeout = soap->send_timeout = 10; // 10 sec
    soap_register_plugin(soap, soap_wsse);
    this->soap = soap_copy(soap);
}


void OnvifApi::set_credentials(std::string username, std::string password)
{
    if(username.empty() && password.empty())
    {
        return;
    }
    soap_wsse_delete_Security(this->soap);
    if (soap_wsse_add_Timestamp(this->soap, "Time", 10)
        || soap_wsse_add_UsernameTokenDigest(this->soap, "Auth", username.c_str(), password.c_str()))
        // || soap_wsse_add_UsernameTokenText(this->soap, "Auth", username.c_str(), password.c_str()))
    {
        report_error();
    }
}

void OnvifApi::report_error()
{
    std::cerr << "Oops, something went wrong:" << std::endl;
    soap_stream_fault(soap, std::cerr);
    // exit(EXIT_FAILURE);
}

std::string OnvifApi::getEndpointDevice(ClientInfo clientInfo)
{
    std::string endpoint;
    if(clientInfo.useHttps){
        // enable https connections with server certificate verification using cacerts.pem
        if (soap_ssl_client_context(soap, SOAP_SSL_SKIP_HOST_CHECK, NULL, NULL, "libOnvif/cacerts.pem", NULL, NULL))
            report_error();
        endpoint = "https://" + clientInfo.ip + ":" + std::to_string(clientInfo.port) + "/onvif/device_service";
    }
    else{
        endpoint = "http://" + clientInfo.ip + ":" + std::to_string(clientInfo.port) + "/onvif/device_service";
    }
    
    return endpoint.c_str();
}

std::string OnvifApi::getEndpointMedia(ClientInfo clientInfo)
{
    std::string endpoint;
    _tds__GetServices GetServices;
    _tds__GetServicesResponse GetServicesResponse;
    GetServices.IncludeCapability = false;
    if(device_GetServices(clientInfo, &GetServices, GetServicesResponse)){
        for(size_t i = 0; i < GetServicesResponse.Service.size(); i++){
            std::string Namespace = GetServicesResponse.Service[i]->Namespace;
            if (Namespace.find("/media/wsdl") != std::string::npos) {
                // endpoint = GetServicesResponse.Service[i]->XAddr;
                std::string XAddr = GetServicesResponse.Service[i]->XAddr;
                endpoint = "http://" + clientInfo.ip + ":" + std::to_string(clientInfo.port);
                endpoint += XAddr.substr(XAddr.find("/onvif"), XAddr.length());
                // std::cout << "endpoint:-" <<  endpoint << "-" << std::endl;
                break;
            } 
        }
    }
    return endpoint.c_str();
}

std::string OnvifApi::getEndpointImaging(ClientInfo clientInfo)
{
    std::string endpoint;
    _tds__GetServices GetServices;
    _tds__GetServicesResponse GetServicesResponse;
    GetServices.IncludeCapability = false;
    if(device_GetServices(clientInfo, &GetServices, GetServicesResponse)){
        for(size_t i = 0; i < GetServicesResponse.Service.size(); i++){
            std::string Namespace = GetServicesResponse.Service[i]->Namespace;
            if (Namespace.find("/imaging/wsdl") != std::string::npos) {
                // endpoint = GetServicesResponse.Service[i]->XAddr;
                std::string XAddr = GetServicesResponse.Service[i]->XAddr;
                endpoint = "http://" + clientInfo.ip + ":" + std::to_string(clientInfo.port);
                endpoint += XAddr.substr(XAddr.find("/onvif"), XAddr.length());
                // std::cout << "endpoint:-" <<  endpoint << "-" << std::endl;
                break;
            } 
        }
    }
    return endpoint.c_str();
}

std::string OnvifApi::getEndpointPtz(ClientInfo clientInfo)
{
    std::string endpoint;
    _tds__GetServices GetServices;
    _tds__GetServicesResponse GetServicesResponse;
    GetServices.IncludeCapability = false;
    if(device_GetServices(clientInfo, &GetServices, GetServicesResponse)){
        for(size_t i = 0; i < GetServicesResponse.Service.size(); i++){
            std::string Namespace = GetServicesResponse.Service[i]->Namespace;
            if (Namespace.find("/ptz/wsdl") != std::string::npos) {
                // endpoint = GetServicesResponse.Service[i]->XAddr;
                std::string XAddr = GetServicesResponse.Service[i]->XAddr;
                endpoint = "http://" + clientInfo.ip + ":" + std::to_string(clientInfo.port);
                endpoint += XAddr.substr(XAddr.find("/onvif"), XAddr.length());
                // std::cout << "endpoint:-" <<  endpoint << "-" << std::endl;
                break;
            } 
        }
    }
    return endpoint.c_str();
}

bool OnvifApi::device_CreateUsers(ClientInfo clientInfo, _tds__CreateUsers *tds__CreateUsers, _tds__CreateUsersResponse &tds__CreateUsersResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.CreateUsers(tds__CreateUsers, tds__CreateUsersResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_DeleteUsers(ClientInfo clientInfo, _tds__DeleteUsers *tds__DeleteUsers, _tds__DeleteUsersResponse &tds__DeleteUsersResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.DeleteUsers(tds__DeleteUsers, tds__DeleteUsersResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetCapabilities(ClientInfo clientInfo, _tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse &tds__GetCapabilitiesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetCapabilities(tds__GetCapabilities, tds__GetCapabilitiesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetDeviceInformation(ClientInfo clientInfo, _tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse &tds__GetDeviceInformationResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetDeviceInformation(tds__GetDeviceInformation, tds__GetDeviceInformationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetDiscoveryMode(ClientInfo clientInfo, _tds__GetDiscoveryMode *tds__GetDiscoveryMode, _tds__GetDiscoveryModeResponse &tds__GetDiscoveryModeResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetDiscoveryMode(tds__GetDiscoveryMode, tds__GetDiscoveryModeResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetHostname(ClientInfo clientInfo, _tds__GetHostname *tds__GetHostname, _tds__GetHostnameResponse &tds__GetHostnameResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetHostname(tds__GetHostname, tds__GetHostnameResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetNetworkDefaultGateway(ClientInfo clientInfo, _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, _tds__GetNetworkDefaultGatewayResponse &tds__GetNetworkDefaultGatewayResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetNetworkDefaultGateway(tds__GetNetworkDefaultGateway, tds__GetNetworkDefaultGatewayResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetNetworkInterfaces(ClientInfo clientInfo, _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, _tds__GetNetworkInterfacesResponse &tds__GetNetworkInterfacesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetNetworkInterfaces(tds__GetNetworkInterfaces, tds__GetNetworkInterfacesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetNetworkProtocols(ClientInfo clientInfo, _tds__GetNetworkProtocols *tds__GetNetworkProtocols, _tds__GetNetworkProtocolsResponse &tds__GetNetworkProtocolsResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetNetworkProtocols(tds__GetNetworkProtocols, tds__GetNetworkProtocolsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetNTP(ClientInfo clientInfo, _tds__GetNTP *tds__GetNTP, _tds__GetNTPResponse &tds__GetNTPResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetNTP(tds__GetNTP, tds__GetNTPResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetScopes(ClientInfo clientInfo, _tds__GetScopes *tds__GetScopes, _tds__GetScopesResponse &tds__GetScopesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetScopes(tds__GetScopes, tds__GetScopesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetSystemDateAndTime(ClientInfo clientInfo, _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, _tds__GetSystemDateAndTimeResponse &tds__GetSystemDateAndTimeResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetSystemDateAndTime(tds__GetSystemDateAndTime, tds__GetSystemDateAndTimeResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetSystemLog(ClientInfo clientInfo, _tds__GetSystemLog *tds__GetSystemLog, _tds__GetSystemLogResponse &tds__GetSystemLogResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetSystemLog(tds__GetSystemLog, tds__GetSystemLogResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetUsers(ClientInfo clientInfo, _tds__GetUsers *tds__GetUsers, _tds__GetUsersResponse &tds__GetUsersResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetUsers(tds__GetUsers, tds__GetUsersResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetWsdlUrl(ClientInfo clientInfo, _tds__GetWsdlUrl *tds__GetWsdlUrl, _tds__GetWsdlUrlResponse &tds__GetWsdlUrlResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetWsdlUrl(tds__GetWsdlUrl, tds__GetWsdlUrlResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_RemoveScopes(ClientInfo clientInfo, _tds__RemoveScopes *tds__RemoveScopes, _tds__RemoveScopesResponse &tds__RemoveScopesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.RemoveScopes(tds__RemoveScopes, tds__RemoveScopesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetDiscoveryMode(ClientInfo clientInfo, _tds__SetDiscoveryMode *tds__SetDiscoveryMode, _tds__SetDiscoveryModeResponse &tds__SetDiscoveryModeResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetDiscoveryMode(tds__SetDiscoveryMode, tds__SetDiscoveryModeResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetHostname(ClientInfo clientInfo, _tds__SetHostname *tds__SetHostname, _tds__SetHostnameResponse &tds__SetHostnameResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetHostname(tds__SetHostname, tds__SetHostnameResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetIPAddressFilter(ClientInfo clientInfo, _tds__SetIPAddressFilter *tds__SetIPAddressFilter, _tds__SetIPAddressFilterResponse &tds__SetIPAddressFilterResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetIPAddressFilter(tds__SetIPAddressFilter, tds__SetIPAddressFilterResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetNetworkDefaultGateway(ClientInfo clientInfo, _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, _tds__SetNetworkDefaultGatewayResponse &tds__SetNetworkDefaultGatewayResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetNetworkDefaultGateway(tds__SetNetworkDefaultGateway, tds__SetNetworkDefaultGatewayResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetNetworkInterfaces(ClientInfo clientInfo, _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, _tds__SetNetworkInterfacesResponse &tds__SetNetworkInterfacesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetNetworkInterfaces(tds__SetNetworkInterfaces, tds__SetNetworkInterfacesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetNetworkProtocols(ClientInfo clientInfo, _tds__SetNetworkProtocols *tds__SetNetworkProtocols, _tds__SetNetworkProtocolsResponse &tds__SetNetworkProtocolsResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetNetworkProtocols(tds__SetNetworkProtocols, tds__SetNetworkProtocolsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetNTP(ClientInfo clientInfo, _tds__SetNTP *tds__SetNTP, _tds__SetNTPResponse &tds__SetNTPResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetNTP(tds__SetNTP, tds__SetNTPResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetScopes(ClientInfo clientInfo, _tds__SetScopes *tds__SetScopes, _tds__SetScopesResponse &tds__SetScopesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetScopes(tds__SetScopes, tds__SetScopesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetSystemDateAndTime(ClientInfo clientInfo, _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, _tds__SetSystemDateAndTimeResponse &tds__SetSystemDateAndTimeResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetSystemDateAndTime(tds__SetSystemDateAndTime, tds__SetSystemDateAndTimeResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SetUser(ClientInfo clientInfo, _tds__SetUser *tds__SetUser, _tds__SetUserResponse &tds__SetUserResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SetUser(tds__SetUser, tds__SetUserResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_SystemReboot(ClientInfo clientInfo, _tds__SystemReboot *tds__SystemReboot, _tds__SystemRebootResponse &tds__SystemRebootResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.SystemReboot(tds__SystemReboot, tds__SystemRebootResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetServices(ClientInfo clientInfo, _tds__GetServices *tds__GetServices, _tds__GetServicesResponse &tds__GetServicesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetServices(tds__GetServices, tds__GetServicesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::device_GetServiceCapabilities(ClientInfo clientInfo, _tds__GetServiceCapabilities *tds__GetServiceCapabilities, _tds__GetServiceCapabilitiesResponse &tds__GetServiceCapabilitiesResponse)
{
    DeviceBindingProxy proxyDevice(this->soap);
    std::string endpoint = getEndpointDevice(clientInfo);
    proxyDevice.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyDevice.GetServiceCapabilities(tds__GetServiceCapabilities, tds__GetServiceCapabilitiesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_CreateProfile(ClientInfo clientInfo, _trt__CreateProfile *trt__CreateProfile, _trt__CreateProfileResponse &trt__CreateProfileResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.CreateProfile(trt__CreateProfile, trt__CreateProfileResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_DeleteProfile(ClientInfo clientInfo, _trt__DeleteProfile *trt__DeleteProfile, _trt__DeleteProfileResponse &trt__DeleteProfileResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.DeleteProfile(trt__DeleteProfile, trt__DeleteProfileResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetCompatibleMetadataConfigurations(ClientInfo clientInfo, _trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, _trt__GetCompatibleMetadataConfigurationsResponse &trt__GetCompatibleMetadataConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetCompatibleMetadataConfigurations(trt__GetCompatibleMetadataConfigurations, trt__GetCompatibleMetadataConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetCompatibleVideoAnalyticsConfigurations(ClientInfo clientInfo, _trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, _trt__GetCompatibleVideoAnalyticsConfigurationsResponse &trt__GetCompatibleVideoAnalyticsConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetCompatibleVideoAnalyticsConfigurations(trt__GetCompatibleVideoAnalyticsConfigurations, trt__GetCompatibleVideoAnalyticsConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetCompatibleVideoEncoderConfigurations(ClientInfo clientInfo, _trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, _trt__GetCompatibleVideoEncoderConfigurationsResponse &trt__GetCompatibleVideoEncoderConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetCompatibleVideoEncoderConfigurations(trt__GetCompatibleVideoEncoderConfigurations, trt__GetCompatibleVideoEncoderConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetCompatibleVideoSourceConfigurations(ClientInfo clientInfo, _trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, _trt__GetCompatibleVideoSourceConfigurationsResponse &trt__GetCompatibleVideoSourceConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetCompatibleVideoSourceConfigurations(trt__GetCompatibleVideoSourceConfigurations, trt__GetCompatibleVideoSourceConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetMetadataConfiguration(ClientInfo clientInfo, _trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, _trt__GetMetadataConfigurationResponse &trt__GetMetadataConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetMetadataConfiguration(trt__GetMetadataConfiguration, trt__GetMetadataConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetMetadataConfigurationOptions(ClientInfo clientInfo, _trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, _trt__GetMetadataConfigurationOptionsResponse &trt__GetMetadataConfigurationOptionsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetMetadataConfigurationOptions(trt__GetMetadataConfigurationOptions, trt__GetMetadataConfigurationOptionsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetMetadataConfigurations(ClientInfo clientInfo, _trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, _trt__GetMetadataConfigurationsResponse &trt__GetMetadataConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetMetadataConfigurations(trt__GetMetadataConfigurations, trt__GetMetadataConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetProfile(ClientInfo clientInfo, _trt__GetProfile *trt__GetProfile, _trt__GetProfileResponse &trt__GetProfileResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetProfile(trt__GetProfile, trt__GetProfileResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetProfiles(ClientInfo clientInfo, _trt__GetProfiles *trt__GetProfiles, _trt__GetProfilesResponse &trt__GetProfilesResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetProfiles(trt__GetProfiles, trt__GetProfilesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetSnapshotUri(ClientInfo clientInfo, _trt__GetSnapshotUri *trt__GetSnapshotUri, _trt__GetSnapshotUriResponse &trt__GetSnapshotUriResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetSnapshotUri(trt__GetSnapshotUri, trt__GetSnapshotUriResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetStreamUri(ClientInfo clientInfo, _trt__GetStreamUri *trt__GetStreamUri, _trt__GetStreamUriResponse &trt__GetStreamUriResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetStreamUri(trt__GetStreamUri, trt__GetStreamUriResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoAnalyticsConfiguration(ClientInfo clientInfo, _trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, _trt__GetVideoAnalyticsConfigurationResponse &trt__GetVideoAnalyticsConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoAnalyticsConfiguration(trt__GetVideoAnalyticsConfiguration, trt__GetVideoAnalyticsConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoAnalyticsConfigurations(ClientInfo clientInfo, _trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, _trt__GetVideoAnalyticsConfigurationsResponse &trt__GetVideoAnalyticsConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoAnalyticsConfigurations(trt__GetVideoAnalyticsConfigurations, trt__GetVideoAnalyticsConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoEncoderConfiguration(ClientInfo clientInfo, _trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, _trt__GetVideoEncoderConfigurationResponse &trt__GetVideoEncoderConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoEncoderConfiguration(trt__GetVideoEncoderConfiguration, trt__GetVideoEncoderConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoEncoderConfigurationOptions(ClientInfo clientInfo, _trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, _trt__GetVideoEncoderConfigurationOptionsResponse &trt__GetVideoEncoderConfigurationOptionsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoEncoderConfigurationOptions(trt__GetVideoEncoderConfigurationOptions, trt__GetVideoEncoderConfigurationOptionsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoEncoderConfigurations(ClientInfo clientInfo, _trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, _trt__GetVideoEncoderConfigurationsResponse &trt__GetVideoEncoderConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoEncoderConfigurations(trt__GetVideoEncoderConfigurations, trt__GetVideoEncoderConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoSourceConfiguration(ClientInfo clientInfo, _trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, _trt__GetVideoSourceConfigurationResponse &trt__GetVideoSourceConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoSourceConfiguration(trt__GetVideoSourceConfiguration, trt__GetVideoSourceConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoSourceConfigurationOptions(ClientInfo clientInfo, _trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, _trt__GetVideoSourceConfigurationOptionsResponse &trt__GetVideoSourceConfigurationOptionsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoSourceConfigurationOptions(trt__GetVideoSourceConfigurationOptions, trt__GetVideoSourceConfigurationOptionsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoSourceConfigurations(ClientInfo clientInfo, _trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, _trt__GetVideoSourceConfigurationsResponse &trt__GetVideoSourceConfigurationsResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoSourceConfigurations(trt__GetVideoSourceConfigurations, trt__GetVideoSourceConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetVideoSources(ClientInfo clientInfo, _trt__GetVideoSources *trt__GetVideoSources, _trt__GetVideoSourcesResponse &trt__GetVideoSourcesResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetVideoSources(trt__GetVideoSources, trt__GetVideoSourcesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_SetMetadataConfiguration(ClientInfo clientInfo, _trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, _trt__SetMetadataConfigurationResponse &trt__SetMetadataConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.SetMetadataConfiguration(trt__SetMetadataConfiguration, trt__SetMetadataConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_SetSynchronizationPoint(ClientInfo clientInfo, _trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, _trt__SetSynchronizationPointResponse &trt__SetSynchronizationPointResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.SetSynchronizationPoint(trt__SetSynchronizationPoint, trt__SetSynchronizationPointResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_SetVideoAnalyticsConfiguration(ClientInfo clientInfo, _trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, _trt__SetVideoAnalyticsConfigurationResponse &trt__SetVideoAnalyticsConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.SetVideoAnalyticsConfiguration(trt__SetVideoAnalyticsConfiguration, trt__SetVideoAnalyticsConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_SetVideoEncoderConfiguration(ClientInfo clientInfo, _trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, _trt__SetVideoEncoderConfigurationResponse &trt__SetVideoEncoderConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.SetVideoEncoderConfiguration(trt__SetVideoEncoderConfiguration, trt__SetVideoEncoderConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_SetVideoSourceConfiguration(ClientInfo clientInfo, _trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, _trt__SetVideoSourceConfigurationResponse &trt__SetVideoSourceConfigurationResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.SetVideoSourceConfiguration(trt__SetVideoSourceConfiguration, trt__SetVideoSourceConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::media_GetServiceCapabilities(ClientInfo clientInfo, _trt__GetServiceCapabilities *trt__GetServiceCapabilities, _trt__GetServiceCapabilitiesResponse &trt__GetServiceCapabilitiesResponse){
    MediaBindingProxy proxyMedia(this->soap);
    std::string endpoint = getEndpointMedia(clientInfo);
    proxyMedia.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyMedia.GetServiceCapabilities(trt__GetServiceCapabilities, trt__GetServiceCapabilitiesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_GetImagingSettings(ClientInfo clientInfo, _timg__GetImagingSettings *timg__GetImagingSettings, _timg__GetImagingSettingsResponse &timg__GetImagingSettingsResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.GetImagingSettings(timg__GetImagingSettings, timg__GetImagingSettingsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_GetMoveOptions(ClientInfo clientInfo, _timg__GetMoveOptions *timg__GetMoveOptions, _timg__GetMoveOptionsResponse &timg__GetMoveOptionsResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.GetMoveOptions(timg__GetMoveOptions, timg__GetMoveOptionsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_GetOptions(ClientInfo clientInfo, _timg__GetOptions *timg__GetOptions, _timg__GetOptionsResponse &timg__GetOptionsResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.GetOptions(timg__GetOptions, timg__GetOptionsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_GetStatus(ClientInfo clientInfo, _timg__GetStatus *timg__GetStatus, _timg__GetStatusResponse &timg__GetStatusResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.GetStatus(timg__GetStatus, timg__GetStatusResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_Move(ClientInfo clientInfo, _timg__Move *timg__Move, _timg__MoveResponse &timg__MoveResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.Move(timg__Move, timg__MoveResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_SetImagingSettings(ClientInfo clientInfo, _timg__SetImagingSettings *timg__SetImagingSettings, _timg__SetImagingSettingsResponse &timg__SetImagingSettingsResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.SetImagingSettings(timg__SetImagingSettings, timg__SetImagingSettingsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_Stop(ClientInfo clientInfo, _timg__Stop *timg__Stop, _timg__StopResponse &timg__StopResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.Stop(timg__Stop, timg__StopResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::imaging_GetServiceCapabilities(ClientInfo clientInfo, _timg__GetServiceCapabilities *timg__GetServiceCapabilities, _timg__GetServiceCapabilitiesResponse &timg__GetServiceCapabilitiesResponse){
    ImagingBindingProxy proxyImaging(this->soap);
    std::string endpoint = getEndpointImaging(clientInfo);
    proxyImaging.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyImaging.GetServiceCapabilities(timg__GetServiceCapabilities, timg__GetServiceCapabilitiesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_AbsoluteMove(ClientInfo clientInfo, _tptz__AbsoluteMove *tptz__AbsoluteMove, _tptz__AbsoluteMoveResponse &tptz__AbsoluteMoveResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.AbsoluteMove(tptz__AbsoluteMove, tptz__AbsoluteMoveResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_ContinuousMove(ClientInfo clientInfo, _tptz__ContinuousMove *tptz__ContinuousMove, _tptz__ContinuousMoveResponse &tptz__ContinuousMoveResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.ContinuousMove(tptz__ContinuousMove, tptz__ContinuousMoveResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetConfiguration(ClientInfo clientInfo, _tptz__GetConfiguration *tptz__GetConfiguration, _tptz__GetConfigurationResponse &tptz__GetConfigurationResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetConfiguration(tptz__GetConfiguration, tptz__GetConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetConfigurationOptions(ClientInfo clientInfo, _tptz__GetConfigurationOptions *tptz__GetConfigurationOptions, _tptz__GetConfigurationOptionsResponse &tptz__GetConfigurationOptionsResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetConfigurationOptions(tptz__GetConfigurationOptions, tptz__GetConfigurationOptionsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetConfigurations(ClientInfo clientInfo, _tptz__GetConfigurations *tptz__GetConfigurations, _tptz__GetConfigurationsResponse &tptz__GetConfigurationsResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetConfigurations(tptz__GetConfigurations, tptz__GetConfigurationsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetNode(ClientInfo clientInfo, _tptz__GetNode *tptz__GetNode, _tptz__GetNodeResponse &tptz__GetNodeResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetNode(tptz__GetNode, tptz__GetNodeResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetNodes(ClientInfo clientInfo, _tptz__GetNodes *tptz__GetNodes, _tptz__GetNodesResponse &tptz__GetNodesResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetNodes(tptz__GetNodes, tptz__GetNodesResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetPresets(ClientInfo clientInfo, _tptz__GetPresets *tptz__GetPresets, _tptz__GetPresetsResponse &tptz__GetPresetsResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetPresets(tptz__GetPresets, tptz__GetPresetsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetStatus(ClientInfo clientInfo, _tptz__GetStatus *tptz__GetStatus, _tptz__GetStatusResponse &tptz__GetStatusResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetStatus(tptz__GetStatus, tptz__GetStatusResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GotoHomePosition(ClientInfo clientInfo, _tptz__GotoHomePosition *tptz__GotoHomePosition, _tptz__GotoHomePositionResponse &tptz__GotoHomePositionResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GotoHomePosition(tptz__GotoHomePosition, tptz__GotoHomePositionResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GotoPreset(ClientInfo clientInfo, _tptz__GotoPreset *tptz__GotoPreset, _tptz__GotoPresetResponse &tptz__GotoPresetResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GotoPreset(tptz__GotoPreset, tptz__GotoPresetResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_RelativeMove(ClientInfo clientInfo, _tptz__RelativeMove *tptz__RelativeMove, _tptz__RelativeMoveResponse &tptz__RelativeMoveResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.RelativeMove(tptz__RelativeMove, tptz__RelativeMoveResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_RemovePreset(ClientInfo clientInfo, _tptz__RemovePreset *tptz__RemovePreset, _tptz__RemovePresetResponse &tptz__RemovePresetResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.RemovePreset(tptz__RemovePreset, tptz__RemovePresetResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_SetConfiguration(ClientInfo clientInfo, _tptz__SetConfiguration *tptz__SetConfiguration, _tptz__SetConfigurationResponse &tptz__SetConfigurationResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.SetConfiguration(tptz__SetConfiguration, tptz__SetConfigurationResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_SetHomePosition(ClientInfo clientInfo, _tptz__SetHomePosition *tptz__SetHomePosition, _tptz__SetHomePositionResponse &tptz__SetHomePositionResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.SetHomePosition(tptz__SetHomePosition, tptz__SetHomePositionResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_SetPreset(ClientInfo clientInfo, _tptz__SetPreset *tptz__SetPreset, _tptz__SetPresetResponse &tptz__SetPresetResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.SetPreset(tptz__SetPreset, tptz__SetPresetResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_Stop(ClientInfo clientInfo, _tptz__Stop *tptz__Stop, _tptz__StopResponse &tptz__StopResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.Stop(tptz__Stop, tptz__StopResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetPresetTour(ClientInfo clientInfo, _tptz__GetPresetTour *tptz__GetPresetTour, _tptz__GetPresetTourResponse &tptz__GetPresetTourResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetPresetTour(tptz__GetPresetTour, tptz__GetPresetTourResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetPresetTours(ClientInfo clientInfo, _tptz__GetPresetTours *tptz__GetPresetTours, _tptz__GetPresetToursResponse &tptz__GetPresetToursResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetPresetTours(tptz__GetPresetTours, tptz__GetPresetToursResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetPresetTourOptions(ClientInfo clientInfo, _tptz__GetPresetTourOptions *tptz__GetPresetTourOptions, _tptz__GetPresetTourOptionsResponse &tptz__GetPresetTourOptionsResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetPresetTourOptions(tptz__GetPresetTourOptions, tptz__GetPresetTourOptionsResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_CreatePresetTour(ClientInfo clientInfo, _tptz__CreatePresetTour *tptz__CreatePresetTour, _tptz__CreatePresetTourResponse &tptz__CreatePresetTourResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.CreatePresetTour(tptz__CreatePresetTour, tptz__CreatePresetTourResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_ModifyPresetTour(ClientInfo clientInfo, _tptz__ModifyPresetTour *tptz__ModifyPresetTour, _tptz__ModifyPresetTourResponse &tptz__ModifyPresetTourResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.ModifyPresetTour(tptz__ModifyPresetTour, tptz__ModifyPresetTourResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_OperatePresetTour(ClientInfo clientInfo, _tptz__OperatePresetTour *tptz__OperatePresetTour, _tptz__OperatePresetTourResponse &tptz__OperatePresetTourResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.OperatePresetTour(tptz__OperatePresetTour, tptz__OperatePresetTourResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_RemovePresetTour(ClientInfo clientInfo, _tptz__RemovePresetTour *tptz__RemovePresetTour, _tptz__RemovePresetTourResponse &tptz__RemovePresetTourResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.RemovePresetTour(tptz__RemovePresetTour, tptz__RemovePresetTourResponse))
    {
        report_error();
        return false;
    }
    return true;
}

bool OnvifApi::ptz_GetServiceCapabilities(ClientInfo clientInfo, _tptz__GetServiceCapabilities *tptz__GetServiceCapabilities, _tptz__GetServiceCapabilitiesResponse &tptz__GetServiceCapabilitiesResponse){
    PTZBindingProxy proxyPTZ(this->soap);
    std::string endpoint = getEndpointPtz(clientInfo);
    proxyPTZ.soap_endpoint = endpoint.c_str();
    set_credentials(clientInfo.username, clientInfo.password);
    if (proxyPTZ.GetServiceCapabilities(tptz__GetServiceCapabilities, tptz__GetServiceCapabilitiesResponse))
    {
        report_error();
        return false;
    }
    return true;
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