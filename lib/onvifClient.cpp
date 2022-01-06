#include "onvifClient.h"


onvifClient::onvifClient(std::string ip, int port)
{
    onvifClientApi = new onvifApi(ip, port);
    this->soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
}

onvifClient::onvifClient(std::string ip, int port, std::string username, std::string password)
{
    onvifClientApi = new onvifApi(ip, port, username, password);
    this->soap = soap_new1(SOAP_XML_STRICT | SOAP_XML_CANONICAL);
}

onvifClient::onvifClient(struct soap *soap, std::string ip, int port, std::string username, std::string password)
{
    onvifClientApi = new onvifApi(soap, ip, port, username, password);
    this->soap = soap; 
}

onvifClient::~onvifClient()
{
}

void onvifClient::tdsOnvifGetDeviceInformation()
{
    
}

void onvifClient::cusGetIdentification(struct cus_onvif_Identification &onvif_IdentificationResponse)
{   
    _tds__GetScopes tds__GetScopes;
	_tds__GetScopesResponse tds__GetScopesResponse;
    onvifClientApi->tdsGetScopes(&tds__GetScopes, tds__GetScopesResponse);
    for(unsigned int i = 0; i < tds__GetScopesResponse.Scopes.size(); i++)
    {
        if(tds__GetScopesResponse.Scopes[i]->ScopeItem.find("name") != -1)
        {
            std::size_t index = tds__GetScopesResponse.Scopes[i]->ScopeItem.find("name") + 5;
            onvif_IdentificationResponse.Name = tds__GetScopesResponse.Scopes[i]->ScopeItem.erase(0, index);
        }
        else if(tds__GetScopesResponse.Scopes[i]->ScopeItem.find("location") != -1)
        {
            std::size_t index = tds__GetScopesResponse.Scopes[i]->ScopeItem.find("location") + 9;
            onvif_IdentificationResponse.Location = tds__GetScopesResponse.Scopes[i]->ScopeItem.erase(0, index);
        }
    }
    _tds__GetDeviceInformation tds__GetDeviceInformation;
	_tds__GetDeviceInformationResponse tds__GetDeviceInformationResponse;
	onvifClientApi->tdsGetDeviceInformation(&tds__GetDeviceInformation, tds__GetDeviceInformationResponse);
    onvif_IdentificationResponse.Manufacturer =  tds__GetDeviceInformationResponse.Manufacturer;
    onvif_IdentificationResponse.Model =  tds__GetDeviceInformationResponse.Model;
    onvif_IdentificationResponse.HardwareId =  tds__GetDeviceInformationResponse.HardwareId;
    onvif_IdentificationResponse.FirmwareVersion =  tds__GetDeviceInformationResponse.FirmwareVersion;
    onvif_IdentificationResponse.SerialNumber =  tds__GetDeviceInformationResponse.SerialNumber;
    onvif_IdentificationResponse.IP = onvifClientApi->ip;
    _tds__GetNetworkInterfaces tds__GetNetworkInterfaces;
	_tds__GetNetworkInterfacesResponse tds__GetNetworkInterfacesResponse;
    onvifClientApi->tdsGetNetworkInterfaces(&tds__GetNetworkInterfaces, tds__GetNetworkInterfacesResponse);
    onvif_IdentificationResponse.MAC = tds__GetNetworkInterfacesResponse.NetworkInterfaces.back()->Info->HwAddress;
    onvif_IdentificationResponse.URL = onvifClientApi->endpoint_device;
}

void onvifClient::cusSetIdentification(struct cus_onvif_Identification *onvif_Identification)
{
    _tds__SetScopes tds__SetScopes;
    if(!onvif_Identification->Name.empty())
    {
        std::string Name = "onvif://www.onvif.org/name/" + onvif_Identification->Name;
        tds__SetScopes.Scopes.push_back(Name);
    }
    if(!onvif_Identification->Location.empty())
    {
        std::string Location = "onvif://www.onvif.org/location/" + onvif_Identification->Location;
        tds__SetScopes.Scopes.push_back(Location);
    }
	_tds__SetScopesResponse tds__SetScopesResponse;
    onvifClientApi->tdsSetScopes(&tds__SetScopes, tds__SetScopesResponse);
}

void onvifClient::cusTptzContinuousMove(struct cus_onvif_tptz_ContinuousMove *onvif_tptz_ContinuousMove)
{
    float minXPantilt;
    float minYPantilt;
    float minXZoom;
    float maxXPantilt;
    float maxYPantilt;
    float maxXZoom;
    _tptz__GetNodes tptz__GetNodes;
    _tptz__GetNodesResponse tptz__GetNodesResponse;
    // tptz__StopResponse.PTZNode.back()->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace.
    onvifClientApi->tptzGetNodes(&tptz__GetNodes, tptz__GetNodesResponse);
    minXPantilt = tptz__GetNodesResponse.PTZNode.back()->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace.back()->XRange->Min;
    maxXPantilt = tptz__GetNodesResponse.PTZNode.back()->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace.back()->XRange->Max;
    minYPantilt = tptz__GetNodesResponse.PTZNode.back()->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace.back()->YRange->Min;
    maxYPantilt = tptz__GetNodesResponse.PTZNode.back()->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace.back()->YRange->Max;
    minXZoom = tptz__GetNodesResponse.PTZNode.back()->SupportedPTZSpaces->ContinuousZoomVelocitySpace.back()->XRange->Min;
    maxXZoom = tptz__GetNodesResponse.PTZNode.back()->SupportedPTZSpaces->ContinuousZoomVelocitySpace.back()->XRange->Max;
    // std::cout << "value : " << minXPantilt << maxXZoom << std::endl;
    _tptz__ContinuousMove tptz__ContinuousMove;
    tptz__ContinuousMove.ProfileToken = onvif_tptz_ContinuousMove->ProfileToken;
    // std::cout << "value : " << onvif_tptz_ContinuousMove->ProfileToken << std::endl;
    tptz__ContinuousMove.Velocity = soap_new_tt__PTZSpeed(soap);
    // std::cout << "value : " << minXPantilt << maxXZoom << std::endl;
    if(onvif_tptz_ContinuousMove->Velocity->PanTilt)
    {
        tptz__ContinuousMove.Velocity->PanTilt = soap_new_tt__Vector2D(soap);
        tptz__ContinuousMove.Velocity->PanTilt->x = onvif_tptz_ContinuousMove->Velocity->PanTilt->x*maxXPantilt;
        tptz__ContinuousMove.Velocity->PanTilt->y = onvif_tptz_ContinuousMove->Velocity->PanTilt->y*maxXPantilt;
        // std::cout << "value PanTilt x: " << tptz__ContinuousMove.Velocity->PanTilt->x << std::endl;
        // std::cout << "value PanTilt y: " << tptz__ContinuousMove.Velocity->PanTilt->y << std::endl;
    }
    if(onvif_tptz_ContinuousMove->Velocity->Zoom)
    {
        tptz__ContinuousMove.Velocity->Zoom = soap_new_tt__Vector1D(soap);
        tptz__ContinuousMove.Velocity->Zoom->x = onvif_tptz_ContinuousMove->Velocity->Zoom->x*maxXZoom;
    }
    _tptz__ContinuousMoveResponse tptz__ContinuousMoveResponse;
    onvifClientApi->tptzContinuousMove(&tptz__ContinuousMove, tptz__ContinuousMoveResponse);
}

void onvifClient::cusTptzStop(struct cus_onvif_tptz_Stop *onvif_tptz_Stop)
{
    _tptz__Stop tptz__Stop;
    _tptz__StopResponse tptz__StopResponse;
    tptz__Stop.ProfileToken = onvif_tptz_Stop->ProfileToken;
    tptz__Stop.PanTilt = onvif_tptz_Stop->PanTilt;
    tptz__Stop.Zoom = onvif_tptz_Stop->Zoom;
    onvifClientApi->tptzStop(&tptz__Stop, tptz__StopResponse);

}