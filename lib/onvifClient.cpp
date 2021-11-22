#include "onvifClient.h"
#include "wsdd.nsmap"

onvifClient::onvifClient()
{
    struct soap *soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
    this->soap = soap;
    this->endpoint_device = "http://localhost:8000/onvif/device_service";
    this->endpoint_media = "http://localhost:8000/onvif/media_service";
    this->endpoint_event = "http://localhost:8000/onvif/event_service";
    this->endpoint_ptz = "http://localhost:8000/onvif/ptz_service";
    this->ip = "localhost";
    this->port = 8000;
    this->username = "admin";
    this->password = "123456";
}

onvifClient::onvifClient(std::string username, std::string password)
{
    struct soap *soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
    this->soap = soap;
    this->endpoint_device = "http://localhost:8000/onvif/device_service";
    this->endpoint_media = "http://localhost:8000/onvif/media_service";
    this->endpoint_event = "http://localhost:8000/onvif/event_service";
    this->endpoint_ptz = "http://localhost:8000/onvif/ptz_service";
    this->ip = "localhost";
    this->port = 8000;
    this->username = username;
    this->password = password;

}

onvifClient::onvifClient(std::string ip, int port, std::string username, std::string password)
{
    struct soap *soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
    this->soap = soap;
    this->ip = ip;
    this->port = port;
    this->endpoint_device = "http://" + ip + ":" + std::to_string(port) + "/onvif/device_service";
    this->endpoint_media = "http://" + ip + ":" + std::to_string(port) + "/onvif/media_service";
    this->endpoint_event = "http://" + ip + ":" + std::to_string(port) + "/onvif/event_service";
    this->endpoint_ptz = "http://" + ip + ":" + std::to_string(port) + "/onvif/ptz_service";
    this->username = username;
    this->password = password;
}

onvifClient::onvifClient(struct soap *soap, std::string ip, int port, std::string username, std::string password)
{
    this->soap = soap;
    this->ip = ip;
    this->port = port;
    this->endpoint_device = "http://" + ip + ":" + std::to_string(port) + "/onvif/device_service";
    this->endpoint_media = "http://" + ip + ":" + std::to_string(port) + "/onvif/media_service";
    this->endpoint_event = "http://" + ip + ":" + std::to_string(port) + "/onvif/event_service";
    this->endpoint_ptz = "http://" + ip + ":" + std::to_string(port) + "/onvif/ptz_service";
    this->username = username;
    this->password = password;
}

onvifClient::~onvifClient()
{

}

void onvifClient::set_credentials(struct soap *soap, std::string username, std::string password)
{
    soap_wsse_delete_Security(soap);
    if (soap_wsse_add_Timestamp(soap, "Time", 10)
    //  || soap_wsse_add_UsernameTokenDigest(soap, NULL, username, password))
    || soap_wsse_add_UsernameTokenText(soap, "Auth", username.c_str(), password.c_str()))
        report_error(soap);
}

void onvifClient::report_error(struct soap *soap)
{
    std::cerr << "Oops, something went wrong:" << std::endl;
    soap_stream_fault(soap, std::cerr);
    exit(EXIT_FAILURE);
}

void onvifClient::tdsGetCapabilities(_tds__GetCapabilities *tds__GetCapabilities, _tds__GetCapabilitiesResponse &tds__GetCapabilitiesResponse)
{
    DeviceBindingProxy proxyDevice(soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetCapabilities(tds__GetCapabilities, tds__GetCapabilitiesResponse))
    {
        report_error(soap);
    }
}

void onvifClient::tdsGetDeviceInformation(_tds__GetDeviceInformation *tds__GetDeviceInformation, _tds__GetDeviceInformationResponse &tds__GetDeviceInformationResponse)
{
    DeviceBindingProxy proxyDevice(soap);
    proxyDevice.soap_endpoint = this->endpoint_device.c_str();
    set_credentials(this->soap, this->username, this->password);
    if (proxyDevice.GetDeviceInformation(tds__GetDeviceInformation, tds__GetDeviceInformationResponse))
    {
        report_error(soap);
    }
}