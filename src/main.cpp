#include "libOnvif/onvifApi.h"
#include "include/httplib.h"
#include <jsoncpp/json/json.h>
#include "libOnvif/wsdd.nsmap"
#include <unistd.h>

#define MOVE_CALIB 1

OnvifApi onvifApi;
//device
void device_CreateUsers(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_DeleteUsers(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetDiscoveryMode(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetDeviceInformation(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetHostname(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetNetworkDefaultGateway(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetNetworkInterfaces(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetNetworkProtocols(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetNTP(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetScopes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetSystemDateAndTime(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetSystemLog(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetUsers(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetWsdlUrl(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_RemoveScopes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetDiscoveryMode(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetHostname(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetIPAddressFilter(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetNetworkDefaultGateway(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetNetworkInterfaces(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetNetworkProtocols(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetNTP(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetScopes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetSystemDateAndTime(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SetUser(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_SystemReboot(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetServices(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void device_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
//media
void media_GetCompatibleMetadataConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetCompatibleVideoAnalyticsConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetCompatibleVideoEncoderConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetCompatibleVideoSourceConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetMetadataConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetMetadataConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetMetadataConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetProfile(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetProfiles(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetSnapshotUri(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetStreamUri(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoAnalyticsConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoAnalyticsConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoEncoderConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoEncoderConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoEncoderConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoSourceConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoSourceConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoSourceConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetVideoSources(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_SetMetadataConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_SetSynchronizationPoint(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_SetVideoAnalyticsConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_SetVideoEncoderConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_SetVideoSourceConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void media_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
//imaging
void imaging_GetImagingSettings(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void imaging_GetMoveOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void imaging_GetOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void imaging_GetStatus(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void imaging_Move(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void imaging_SetImagingSettings(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void imaging_Stop(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void imaging_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
//ptz
void ptz_AbsoluteMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_ContinuousMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetNode(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetNodes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetPresets(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetStatus(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GotoHomePosition(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GotoPreset(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_RelativeMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_RemovePreset(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_SetConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_SetHomePosition(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_SetPreset(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_Stop(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetPresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetPresetTours(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetPresetTourOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_CreatePresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_ModifyPresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_OperatePresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_RemovePresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);
void ptz_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader);

int main(int argc, char **argv)
{
  httplib::Server svr;
  //device
  svr.Post("/onvif/v1.0/CreateUsers", device_CreateUsers);
  svr.Post("/onvif/v1.0/DeleteUsers", device_DeleteUsers);
  svr.Post("/onvif/v1.0/GetCapabilities", device_GetCapabilities);
  svr.Post("/onvif/v1.0/GetDeviceInformation", device_GetDeviceInformation);
  svr.Post("/onvif/v1.0/GetDiscoveryMode", device_GetDiscoveryMode);
  svr.Post("/onvif/v1.0/GetHostname", device_GetHostname);
  svr.Post("/onvif/v1.0/GetNetworkDefaultGateway", device_GetNetworkDefaultGateway);
  svr.Post("/onvif/v1.0/GetNetworkInterfaces", device_GetNetworkInterfaces);
  svr.Post("/onvif/v1.0/GetNetworkProtocols", device_GetNetworkProtocols);
  svr.Post("/onvif/v1.0/GetNTP", device_GetNTP);
  svr.Post("/onvif/v1.0/GetScopes", device_GetScopes);
  svr.Post("/onvif/v1.0/GetSystemDateAndTime", device_GetSystemDateAndTime);
  svr.Post("/onvif/v1.0/GetSystemLog", device_GetSystemLog);
  svr.Post("/onvif/v1.0/GetUsers", device_GetUsers);
  svr.Post("/onvif/v1.0/GetWsdlUrl", device_GetWsdlUrl);
  svr.Post("/onvif/v1.0/RemoveScopes", device_RemoveScopes);
  svr.Post("/onvif/v1.0/SetDiscoveryMode", device_SetDiscoveryMode);
  svr.Post("/onvif/v1.0/SetHostname", device_SetHostname);
  svr.Post("/onvif/v1.0/SetIPAddressFilter", device_SetIPAddressFilter);
  svr.Post("/onvif/v1.0/SetNetworkDefaultGateway", device_SetNetworkDefaultGateway);
  svr.Post("/onvif/v1.0/SetNetworkInterfaces", device_SetNetworkInterfaces);
  svr.Post("/onvif/v1.0/SetNetworkProtocols", device_SetNetworkProtocols);
  svr.Post("/onvif/v1.0/SetNTP", device_SetNTP);
  svr.Post("/onvif/v1.0/SetScopes", device_SetScopes);
  svr.Post("/onvif/v1.0/SetSystemDateAndTime", device_SetSystemDateAndTime);
  svr.Post("/onvif/v1.0/SetUser", device_SetUser);
  svr.Post("/onvif/v1.0/SystemReboot", device_SystemReboot);
  svr.Post("/onvif/v1.0/GetServices", device_GetServices);
  svr.Post("/onvif/v1.0/DeviceGetServiceCapabilities", device_GetServiceCapabilities);
  //media
  svr.Post("/onvif/v1.0/GetCompatibleMetadataConfigurations", media_GetCompatibleMetadataConfigurations);
  svr.Post("/onvif/v1.0/GetCompatibleVideoAnalyticsConfigurations", media_GetCompatibleVideoAnalyticsConfigurations);
  svr.Post("/onvif/v1.0/GetCompatibleVideoEncoderConfigurations", media_GetCompatibleVideoEncoderConfigurations);
  svr.Post("/onvif/v1.0/GetCompatibleVideoSourceConfigurations", media_GetCompatibleVideoSourceConfigurations);
  svr.Post("/onvif/v1.0/GetMetadataConfiguration", media_GetMetadataConfiguration);
  svr.Post("/onvif/v1.0/GetMetadataConfigurationOptions", media_GetMetadataConfigurationOptions);
  svr.Post("/onvif/v1.0/GetMetadataConfigurations", media_GetMetadataConfigurations);
  svr.Post("/onvif/v1.0/GetProfile", media_GetProfile);
  svr.Post("/onvif/v1.0/GetProfiles", media_GetProfiles);
  svr.Post("/onvif/v1.0/GetSnapshotUri", media_GetSnapshotUri);
  svr.Post("/onvif/v1.0/GetStreamUri", media_GetStreamUri);
  svr.Post("/onvif/v1.0/GetVideoAnalyticsConfiguration", media_GetVideoAnalyticsConfiguration);
  svr.Post("/onvif/v1.0/GetVideoAnalyticsConfigurations", media_GetVideoAnalyticsConfigurations);
  svr.Post("/onvif/v1.0/GetVideoEncoderConfiguration", media_GetVideoEncoderConfiguration);
  svr.Post("/onvif/v1.0/GetVideoEncoderConfigurationOptions", media_GetVideoEncoderConfigurationOptions);
  svr.Post("/onvif/v1.0/GetVideoEncoderConfigurations", media_GetVideoEncoderConfigurations);
  svr.Post("/onvif/v1.0/GetVideoSourceConfiguration", media_GetVideoSourceConfiguration);
  svr.Post("/onvif/v1.0/GetVideoSourceConfigurationOptions", media_GetVideoSourceConfigurationOptions);
  svr.Post("/onvif/v1.0/GetVideoSourceConfigurations", media_GetVideoSourceConfigurations);
  svr.Post("/onvif/v1.0/GetVideoSources", media_GetVideoSources);
  svr.Post("/onvif/v1.0/SetMetadataConfiguration", media_SetMetadataConfiguration);
  svr.Post("/onvif/v1.0/SetSynchronizationPoint", media_SetSynchronizationPoint);
  svr.Post("/onvif/v1.0/SetVideoAnalyticsConfiguration", media_SetVideoAnalyticsConfiguration);
  svr.Post("/onvif/v1.0/SetVideoEncoderConfiguration", media_SetVideoEncoderConfiguration);
  svr.Post("/onvif/v1.0/SetVideoSourceConfiguration", media_SetVideoSourceConfiguration);
  svr.Post("/onvif/v1.0/MediaGetServiceCapabilities", media_GetServiceCapabilities);
  //imaging
  svr.Post("/onvif/v1.0/GetImagingSettings", imaging_GetImagingSettings);
  svr.Post("/onvif/v1.0/GetMoveOptions", imaging_GetMoveOptions);
  svr.Post("/onvif/v1.0/GetOptions", imaging_GetOptions);
  svr.Post("/onvif/v1.0/ImagingGetStatus", imaging_GetStatus);
  svr.Post("/onvif/v1.0/Move", imaging_Move);
  svr.Post("/onvif/v1.0/SetImagingSettings", imaging_SetImagingSettings);
  svr.Post("/onvif/v1.0/ImagingStop", imaging_Stop);
  svr.Post("/onvif/v1.0/ImagingGetServiceCapabilities", imaging_GetServiceCapabilities);
  //ptz
  svr.Post("/onvif/v1.0/AbsoluteMove", ptz_AbsoluteMove);
  svr.Post("/onvif/v1.0/ContinuousMove", ptz_ContinuousMove);
  svr.Post("/onvif/v1.0/GetConfiguration", ptz_GetConfiguration);
  svr.Post("/onvif/v1.0/GetConfigurationOptions", ptz_GetConfigurationOptions);
  svr.Post("/onvif/v1.0/GetConfigurations", ptz_GetConfigurations);
  svr.Post("/onvif/v1.0/GetNode", ptz_GetNode);
  svr.Post("/onvif/v1.0/GetNodes", ptz_GetNodes);
  svr.Post("/onvif/v1.0/GetPresets", ptz_GetPresets);
  svr.Post("/onvif/v1.0/PtzGetStatus", ptz_GetStatus);
  svr.Post("/onvif/v1.0/GotoHomePosition", ptz_GotoHomePosition);
  svr.Post("/onvif/v1.0/GotoPreset", ptz_GotoPreset);
  svr.Post("/onvif/v1.0/RelativeMove", ptz_RelativeMove);
  svr.Post("/onvif/v1.0/RemovePreset", ptz_RemovePreset);
  svr.Post("/onvif/v1.0/SetConfiguration", ptz_SetConfiguration);
  svr.Post("/onvif/v1.0/SetHomePosition", ptz_SetHomePosition);
  svr.Post("/onvif/v1.0/SetPreset", ptz_SetPreset);
  svr.Post("/onvif/v1.0/PtzStop", ptz_Stop);
  svr.Post("/onvif/v1.0/GetPresetTour", ptz_GetPresetTour);
  svr.Post("/onvif/v1.0/GetPresetTours", ptz_GetPresetTours);
  svr.Post("/onvif/v1.0/GetPresetTourOptions", ptz_GetPresetTourOptions);
  svr.Post("/onvif/v1.0/CreatePresetTour", ptz_CreatePresetTour);
  svr.Post("/onvif/v1.0/ModifyPresetTour", ptz_ModifyPresetTour);
  svr.Post("/onvif/v1.0/OperatePresetTour", ptz_OperatePresetTour);
  svr.Post("/onvif/v1.0/RemovePresetTour", ptz_RemovePresetTour);
  svr.Post("/onvif/v1.0/PtzGetServiceCapabilities", ptz_GetServiceCapabilities);
  svr.listen("0.0.0.0", 8081);
  return 0;
}

void device_CreateUsers(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  if(root_dataResponse["User"].isNull()){
    res.set_content("{\"status\":\"Error, not have field: User\"}", "text/plain");
    return;
  }
  _tds__CreateUsers CreateUsers;
  _tds__CreateUsersResponse CreateUsersResponse;
  Json::Value arrayUser = root_dataResponse["User"]; // array of User
  for(unsigned int i = 0; i < arrayUser.size(); i++){
    tt__User *user;
    user = soap_new_tt__User(onvifApi.soap);
    user->Username = arrayUser[i]["Username"].asString();
    if(!arrayUser[i]["Password"].isNull()){
      std::string Password = arrayUser[i]["Password"].asString();
      user->Password = &Password;
    }
    if(arrayUser[i]["UserLevel"].asString() == "Administrator"){
      user->UserLevel = tt__UserLevel__Administrator;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "Operator"){
      user->UserLevel = tt__UserLevel__Operator;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "User"){
      user->UserLevel = tt__UserLevel__User;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "Anonymous"){
      user->UserLevel = tt__UserLevel__Anonymous;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "Extended"){
      user->UserLevel = tt__UserLevel__Extended;
    }
    else{
      user->UserLevel = tt__UserLevel__User;
    }
    CreateUsers.User.push_back(user);
  }
  if(onvifApi.device_CreateUsers(clientInfo, &CreateUsers, CreateUsersResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }


}

void device_DeleteUsers(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  if(root_dataResponse["User"].isNull()){
    res.set_content("{\"status\":\"Error, not have field: User\"}", "text/plain");
    return;
  }

  _tds__DeleteUsers DeleteUsers;
  _tds__DeleteUsersResponse DeleteUsersResponse;
  Json::Value arrayUser = root_dataResponse["User"]; // array of User
  for(unsigned int i = 0; i < arrayUser.size(); i++){
    DeleteUsers.Username.push_back(arrayUser[i]["Username"].asString());
  }
  if(onvifApi.device_DeleteUsers(clientInfo, &DeleteUsers, DeleteUsersResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  if(root_dataResponse["Category"].isNull()){
    res.set_content("{\"status\":\"Error, not have field: Category\"}", "text/plain");
    return;
  }
  _tds__GetCapabilities GetCapabilities;
  _tds__GetCapabilitiesResponse GetCapabilitiesResponse;
  std::string Category = root_dataResponse["Category"].asString();
  if(Category == "All"){
    GetCapabilities.Category.push_back(tt__CapabilityCategory__All);
  }else if(Category == "Analytics"){
    GetCapabilities.Category.push_back(tt__CapabilityCategory__Analytics);
  }
  else if(Category == "Device"){
    GetCapabilities.Category.push_back(tt__CapabilityCategory__Device);
  }
  else if(Category == "Events"){
    GetCapabilities.Category.push_back(tt__CapabilityCategory__Events);
  }
  else if(Category == "Imaging"){
    GetCapabilities.Category.push_back(tt__CapabilityCategory__Imaging);
  }
  else if(Category == "Media"){
    GetCapabilities.Category.push_back(tt__CapabilityCategory__Media);
  }
  else if(Category == "PTZ"){
    GetCapabilities.Category.push_back(tt__CapabilityCategory__PTZ);
  }
  if(onvifApi.device_GetCapabilities(clientInfo, &GetCapabilities, GetCapabilitiesResponse)){
    Json::Value dataJson;
    if(Category == "All" || Category == "Device"){
      if(GetCapabilitiesResponse.Capabilities->Device){
        dataJson["Capabilities"]["Device"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Device->XAddr;
        dataJson["Capabilities"]["Device"]["Network"]["IPFilter"] = GetCapabilitiesResponse.Capabilities->Device->Network->IPFilter;
        dataJson["Capabilities"]["Device"]["Network"]["ZeroConfiguration"] = GetCapabilitiesResponse.Capabilities->Device->Network->ZeroConfiguration;
        dataJson["Capabilities"]["Device"]["Network"]["IPVersion6"] = GetCapabilitiesResponse.Capabilities->Device->Network->IPVersion6;
        dataJson["Capabilities"]["Device"]["Network"]["DynDNS"] = GetCapabilitiesResponse.Capabilities->Device->Network->DynDNS;
        dataJson["Capabilities"]["Device"]["System"]["DiscoveryResolve"] = GetCapabilitiesResponse.Capabilities->Device->System->DiscoveryResolve;
        dataJson["Capabilities"]["Device"]["System"]["DiscoveryBye"] = GetCapabilitiesResponse.Capabilities->Device->System->DiscoveryBye;
        dataJson["Capabilities"]["Device"]["System"]["RemoteDiscovery"] = GetCapabilitiesResponse.Capabilities->Device->System->RemoteDiscovery;
        dataJson["Capabilities"]["Device"]["System"]["SystemBackup"] = GetCapabilitiesResponse.Capabilities->Device->System->SystemBackup;
        dataJson["Capabilities"]["Device"]["System"]["SystemLogging"] = GetCapabilitiesResponse.Capabilities->Device->System->SystemLogging;
        dataJson["Capabilities"]["Device"]["System"]["FirmwareUpgrade"] = GetCapabilitiesResponse.Capabilities->Device->System->FirmwareUpgrade;
        if(!GetCapabilitiesResponse.Capabilities->Device->System->SupportedVersions.empty()){
          dataJson["Capabilities"]["Device"]["System"]["SupportedVersions"]["Major"] = GetCapabilitiesResponse.Capabilities->Device->System->SupportedVersions.back()->Major;
          dataJson["Capabilities"]["Device"]["System"]["SupportedVersions"]["Minor"] = GetCapabilitiesResponse.Capabilities->Device->System->SupportedVersions.back()->Minor;
        }
        dataJson["Capabilities"]["Device"]["IO"]["InputConnectors"] = GetCapabilitiesResponse.Capabilities->Device->IO->InputConnectors;
        dataJson["Capabilities"]["Device"]["IO"]["RelayOutputs"] = GetCapabilitiesResponse.Capabilities->Device->IO->RelayOutputs;
        dataJson["Capabilities"]["Device"]["Security"]["TLS1.1"] = GetCapabilitiesResponse.Capabilities->Device->Security->TLS1_x002e1;
        dataJson["Capabilities"]["Device"]["Security"]["TLS1.2"] = GetCapabilitiesResponse.Capabilities->Device->Security->TLS1_x002e2;
        dataJson["Capabilities"]["Device"]["Security"]["OnboardKeyGeneration"] = GetCapabilitiesResponse.Capabilities->Device->Security->OnboardKeyGeneration;
        dataJson["Capabilities"]["Device"]["Security"]["AccessPolicyConfig"] = GetCapabilitiesResponse.Capabilities->Device->Security->AccessPolicyConfig;
        dataJson["Capabilities"]["Device"]["Security"]["X.509Token"] = GetCapabilitiesResponse.Capabilities->Device->Security->X_x002e509Token;
        dataJson["Capabilities"]["Device"]["Security"]["SAMLToken"] = GetCapabilitiesResponse.Capabilities->Device->Security->SAMLToken;
        dataJson["Capabilities"]["Device"]["Security"]["KerberosToken"] = GetCapabilitiesResponse.Capabilities->Device->Security->KerberosToken;
        dataJson["Capabilities"]["Device"]["Security"]["RELToken"] = GetCapabilitiesResponse.Capabilities->Device->Security->RELToken;
      }
    }
    if(Category == "All" || Category == "Analytics"){
      if(GetCapabilitiesResponse.Capabilities->Analytics){
        dataJson["Capabilities"]["Analytics"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Analytics->XAddr;
        dataJson["Capabilities"]["Analytics"]["RuleSupport"] = GetCapabilitiesResponse.Capabilities->Analytics->RuleSupport;
        dataJson["Capabilities"]["Analytics"]["AnalyticsModuleSupport"] = GetCapabilitiesResponse.Capabilities->Analytics->AnalyticsModuleSupport;
      }
    }
    if(Category == "All" || Category == "Events"){
      if(GetCapabilitiesResponse.Capabilities->Events){
        dataJson["Capabilities"]["Events"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Events->XAddr;
        dataJson["Capabilities"]["Events"]["WSSubscriptionPolicySupport"] = GetCapabilitiesResponse.Capabilities->Events->WSSubscriptionPolicySupport;
        dataJson["Capabilities"]["Events"]["WSPullPointSupport"] = GetCapabilitiesResponse.Capabilities->Events->WSPullPointSupport;
        dataJson["Capabilities"]["Events"]["WSPausableSubscriptionManagerInterfaceSupport"] = GetCapabilitiesResponse.Capabilities->Events->WSPausableSubscriptionManagerInterfaceSupport;
      }
    }
    if(Category == "All" || Category == "Imaging"){
      if(GetCapabilitiesResponse.Capabilities->Imaging){
        dataJson["Capabilities"]["Imaging"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Imaging->XAddr;
      }
    }
    if(Category == "All" || Category == "Media"){
      if(GetCapabilitiesResponse.Capabilities->Media){
        dataJson["Capabilities"]["Media"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Media->XAddr;
        if(GetCapabilitiesResponse.Capabilities->Media->StreamingCapabilities){
          dataJson["Capabilities"]["Media"]["StreamingCapabilities"]["RTPMulticast"] = GetCapabilitiesResponse.Capabilities->Media->StreamingCapabilities->RTPMulticast;
          dataJson["Capabilities"]["Media"]["StreamingCapabilities"]["RTP_TCP"] = GetCapabilitiesResponse.Capabilities->Media->StreamingCapabilities->RTP_USCORETCP;
          dataJson["Capabilities"]["Media"]["StreamingCapabilities"]["RTP_RTSP_TCP"] = GetCapabilitiesResponse.Capabilities->Media->StreamingCapabilities->RTP_USCORERTSP_USCORETCP;
        }
      }
    }
    if(Category == "All" || Category == "PTZ"){
      if(GetCapabilitiesResponse.Capabilities->PTZ){
        dataJson["Capabilities"]["PTZ"]["XAddr"] = GetCapabilitiesResponse.Capabilities->PTZ->XAddr;
      }
    }
    if(Category == "All"){
      if(GetCapabilitiesResponse.Capabilities->Extension){
        if(GetCapabilitiesResponse.Capabilities->Extension->DeviceIO){
          dataJson["Capabilities"]["Extension"]["DeviceIO"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Extension->DeviceIO->XAddr;
          dataJson["Capabilities"]["Extension"]["DeviceIO"]["VideoSources"] = GetCapabilitiesResponse.Capabilities->Extension->DeviceIO->VideoSources;
          dataJson["Capabilities"]["Extension"]["DeviceIO"]["VideoOutputs"] = GetCapabilitiesResponse.Capabilities->Extension->DeviceIO->VideoOutputs;
          dataJson["Capabilities"]["Extension"]["DeviceIO"]["AudioSources"] = GetCapabilitiesResponse.Capabilities->Extension->DeviceIO->AudioSources;
          dataJson["Capabilities"]["Extension"]["DeviceIO"]["AudioOutputs"] = GetCapabilitiesResponse.Capabilities->Extension->DeviceIO->AudioOutputs;
          dataJson["Capabilities"]["Extension"]["DeviceIO"]["RelayOutputs"] = GetCapabilitiesResponse.Capabilities->Extension->DeviceIO->RelayOutputs;
        }
        if(GetCapabilitiesResponse.Capabilities->Extension->Display){
          dataJson["Capabilities"]["Extension"]["Display"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Extension->Display->XAddr;
          dataJson["Capabilities"]["Extension"]["Display"]["FixedLayout"] = GetCapabilitiesResponse.Capabilities->Extension->Display->FixedLayout;
        }
        if(GetCapabilitiesResponse.Capabilities->Extension->Recording){
          dataJson["Capabilities"]["Extension"]["Recording"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Extension->Recording->XAddr;
          dataJson["Capabilities"]["Extension"]["Recording"]["ReceiverSource"] = GetCapabilitiesResponse.Capabilities->Extension->Recording->ReceiverSource;
          dataJson["Capabilities"]["Extension"]["Recording"]["MediaProfileSource"] = GetCapabilitiesResponse.Capabilities->Extension->Recording->MediaProfileSource;
          dataJson["Capabilities"]["Extension"]["Recording"]["DynamicRecordings"] = GetCapabilitiesResponse.Capabilities->Extension->Recording->DynamicRecordings;
          dataJson["Capabilities"]["Extension"]["Recording"]["DynamicTracks"] = GetCapabilitiesResponse.Capabilities->Extension->Recording->DynamicTracks;
          dataJson["Capabilities"]["Extension"]["Recording"]["MaxStringLength"] = GetCapabilitiesResponse.Capabilities->Extension->Recording->MaxStringLength;
        }
        if(GetCapabilitiesResponse.Capabilities->Extension->Search){
          dataJson["Capabilities"]["Extension"]["Search"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Extension->Search->XAddr;
          dataJson["Capabilities"]["Extension"]["Search"]["MetadataSearch"] = GetCapabilitiesResponse.Capabilities->Extension->Search->MetadataSearch;
        }
        if(GetCapabilitiesResponse.Capabilities->Extension->Replay){
          dataJson["Capabilities"]["Extension"]["Replay"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Extension->Replay->XAddr;
        }
        if(GetCapabilitiesResponse.Capabilities->Extension->Receiver){
          dataJson["Capabilities"]["Extension"]["Receiver"]["XAddr"] = GetCapabilitiesResponse.Capabilities->Extension->Receiver->XAddr;
          dataJson["Capabilities"]["Extension"]["Receiver"]["RTP_Multicast"] = GetCapabilitiesResponse.Capabilities->Extension->Receiver->RTP_USCOREMulticast;
          dataJson["Capabilities"]["Extension"]["Receiver"]["RTP_TCP"] = GetCapabilitiesResponse.Capabilities->Extension->Receiver->RTP_USCORETCP;
          dataJson["Capabilities"]["Extension"]["Receiver"]["RTP_RTSP_TCP"] = GetCapabilitiesResponse.Capabilities->Extension->Receiver->RTP_USCORERTSP_USCORETCP;
          dataJson["Capabilities"]["Extension"]["Receiver"]["SupportedReceivers"] = GetCapabilitiesResponse.Capabilities->Extension->Receiver->SupportedReceivers;
          dataJson["Capabilities"]["Extension"]["Receiver"]["MaximumRTSPURILength"] = GetCapabilitiesResponse.Capabilities->Extension->Receiver->MaximumRTSPURILength;
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetDeviceInformation(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }

  _tds__GetDeviceInformation GetDeviceInformation;
  _tds__GetDeviceInformationResponse GetDeviceInformationResponse;
  if(onvifApi.device_GetDeviceInformation(clientInfo, &GetDeviceInformation, GetDeviceInformationResponse)){
    Json::Value dataJson;
    dataJson["Manufacturer"] = GetDeviceInformationResponse.Manufacturer;
    dataJson["Model"] = GetDeviceInformationResponse.Model;
    dataJson["FirmwareVersion"] = GetDeviceInformationResponse.FirmwareVersion;
    dataJson["SerialNumber"] = GetDeviceInformationResponse.SerialNumber;
    dataJson["HardwareId"] = GetDeviceInformationResponse.HardwareId;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetDiscoveryMode(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetDiscoveryMode GetDiscoveryMode;
  _tds__GetDiscoveryModeResponse GetDiscoveryModeResponse;
  if(onvifApi.device_GetDiscoveryMode(clientInfo, &GetDiscoveryMode, GetDiscoveryModeResponse)){
    Json::Value dataJson;
    switch (GetDiscoveryModeResponse.DiscoveryMode)
    {
    case tt__DiscoveryMode__Discoverable:
      dataJson["DiscoveryMode"] = "Discoverable";
      break;
    case tt__DiscoveryMode__NonDiscoverable:
      dataJson["DiscoveryMode"] = "NonDiscoverable";
      break;
    default:
      break;
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }


}

void device_GetHostname(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetHostname GetHostname;
  _tds__GetHostnameResponse GetHostnameResponse;
  if(onvifApi.device_GetHostname(clientInfo, &GetHostname, GetHostnameResponse)){
    Json::Value dataJson;
    dataJson["HostnameInformation"]["FromDHCP"] = GetHostnameResponse.HostnameInformation->FromDHCP;
    dataJson["HostnameInformation"]["Name"] = GetHostnameResponse.HostnameInformation->Name;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetNetworkDefaultGateway(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetNetworkDefaultGateway GetNetworkDefaultGateway;
  _tds__GetNetworkDefaultGatewayResponse GetNetworkDefaultGatewayResponse;
  if(onvifApi.device_GetNetworkDefaultGateway(clientInfo, &GetNetworkDefaultGateway, GetNetworkDefaultGatewayResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetNetworkDefaultGatewayResponse.NetworkGateway->IPv4Address.size(); i++){
      dataJson["NetworkGateway"]["IPv4Address"].append(GetNetworkDefaultGatewayResponse.NetworkGateway->IPv4Address[i]);
    }
    for(size_t i = 0; i < GetNetworkDefaultGatewayResponse.NetworkGateway->IPv6Address.size(); i++){
      dataJson["NetworkGateway"]["IPv6Address"].append(GetNetworkDefaultGatewayResponse.NetworkGateway->IPv6Address[i]);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetNetworkInterfaces(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetNetworkInterfaces GetNetworkInterfaces;
  _tds__GetNetworkInterfacesResponse GetNetworkInterfacesResponse;
  if(onvifApi.device_GetNetworkInterfaces(clientInfo, &GetNetworkInterfaces, GetNetworkInterfacesResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetNetworkInterfacesResponse.NetworkInterfaces.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->token;
      jsonArr["Enabled"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->Enabled;
      if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->Info){
        if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->Info->Name){
          jsonArr["Info"]["Name"] = *GetNetworkInterfacesResponse.NetworkInterfaces[i]->Info->Name;
        }
        jsonArr["Info"]["HwAddress"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->Info->HwAddress;
        if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->Info->Name){
          jsonArr["Info"]["MTU"] = *GetNetworkInterfacesResponse.NetworkInterfaces[i]->Info->MTU;
        }
      }
      if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link){
        if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->AdminSettings){
          jsonArr["Link"]["AdminSettings"]["AutoNegotiation"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->AdminSettings->AutoNegotiation;
          jsonArr["Link"]["AdminSettings"]["Speed"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->AdminSettings->Speed;
          switch (GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->AdminSettings->Duplex)
          {
          case tt__Duplex__Full:
            jsonArr["Link"]["AdminSettings"]["Duplex"] = "Full";
            break;
          case tt__Duplex__Half:
            jsonArr["Link"]["AdminSettings"]["Duplex"] = "Half";
            break;
          default:
            break;
          }
        }
        if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->OperSettings){
          jsonArr["Link"]["OperSettings"]["AutoNegotiation"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->OperSettings->AutoNegotiation;
          jsonArr["Link"]["OperSettings"]["Speed"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->OperSettings->Speed;
          switch (GetNetworkInterfacesResponse.NetworkInterfaces[i]->Link->OperSettings->Duplex)
          {
          case tt__Duplex__Full:
            jsonArr["Link"]["OperSettings"]["Duplex"] = "Full";
            break;
          case tt__Duplex__Half:
            jsonArr["Link"]["OperSettings"]["Duplex"] = "Half";
            break;
          default:
            break;
          }
        }
      }
      if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4){
        jsonArr["IPv4"]["Enabled"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Enabled;
        if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config){
          if(!GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->Manual.empty()){
            for(size_t j = 0; j < GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->Manual.size(); j++){
              Json::Value jsonArrManual;
              jsonArrManual["Address"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->Manual[j]->Address;
              jsonArrManual["PrefixLength"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->Manual[j]->PrefixLength;
              jsonArr["IPv4"]["Config"]["Manual"].append(jsonArrManual);
            }
          }
          if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->LinkLocal){
            jsonArr["IPv4"]["Config"]["LinkLocal"]["Address"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->LinkLocal->Address;
            jsonArr["IPv4"]["Config"]["LinkLocal"]["PrefixLength"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->LinkLocal->PrefixLength;
          }
          if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->FromDHCP){
            jsonArr["IPv4"]["Config"]["FromDHCP"]["Address"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->FromDHCP->Address;
            jsonArr["IPv4"]["Config"]["FromDHCP"]["PrefixLength"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->FromDHCP->PrefixLength;
          }
          jsonArr["IPv4"]["Config"]["DHCP"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv4->Config->DHCP;
        }
      }

      if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6){
        jsonArr["IPv6"]["Enabled"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Enabled;
        if(GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config){
          jsonArr["IPv6"]["Config"]["AcceptRouterAdvert"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->AcceptRouterAdvert;
          jsonArr["IPv6"]["Config"]["DHCP"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->DHCP;
          if(!GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->Manual.empty()){
            for(size_t j = 0; j < GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->Manual.size(); j++){
              Json::Value jsonArrManual;
              jsonArrManual["Address"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->Manual[j]->Address;
              jsonArrManual["PrefixLength"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->Manual[j]->PrefixLength;
              jsonArr["IPv6"]["Config"]["Manual"].append(jsonArrManual);
            }
          }
          if(!GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->LinkLocal.empty()){
            for(size_t j = 0; j < GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->LinkLocal.size(); j++){
              Json::Value jsonArrLinkLocal;
              jsonArrLinkLocal["Address"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->LinkLocal[j]->Address;
              jsonArrLinkLocal["PrefixLength"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->LinkLocal[j]->PrefixLength;
              jsonArr["IPv6"]["Config"]["LinkLocal"].append(jsonArrLinkLocal);
            }
          }
          if(!GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromDHCP.empty()){
            for(size_t j = 0; j < GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromDHCP.size(); j++){
              Json::Value jsonArrFromDHCP;
              jsonArrFromDHCP["Address"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromDHCP[j]->Address;
              jsonArrFromDHCP["PrefixLength"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromDHCP[j]->PrefixLength;
              jsonArr["IPv6"]["Config"]["FromDHCP"].append(jsonArrFromDHCP);
            }
          }
          if(!GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromRA.empty()){
            for(size_t j = 0; j < GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromRA.size(); j++){
              Json::Value jsonArrFromRA;
              jsonArrFromRA["Address"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromRA[j]->Address;
              jsonArrFromRA["PrefixLength"] = GetNetworkInterfacesResponse.NetworkInterfaces[i]->IPv6->Config->FromRA[j]->PrefixLength;
              jsonArr["IPv6"]["Config"]["FromRA"].append(jsonArrFromRA);
            }
          }
          
        }
      }
      dataJson["NetworkInterfaces"].append(jsonArr);
    }


    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }

}

void device_GetNetworkProtocols(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }

  _tds__GetNetworkProtocols GetNetworkProtocols;
  _tds__GetNetworkProtocolsResponse GetNetworkProtocolsResponse;
  if(onvifApi.device_GetNetworkProtocols(clientInfo, &GetNetworkProtocols, GetNetworkProtocolsResponse)){
    Json::Value dataJson;
    if(!GetNetworkProtocolsResponse.NetworkProtocols.empty()){
      for(size_t i = 0; i < GetNetworkProtocolsResponse.NetworkProtocols.size(); i++){
        Json::Value jsonArr;
        switch(GetNetworkProtocolsResponse.NetworkProtocols[i]->Name){
        case tt__NetworkProtocolType__HTTP:
          jsonArr["Name"] = "HTTP";
          break;
        case tt__NetworkProtocolType__HTTPS:
          jsonArr["Name"] = "HTTPS";
          break;
        case tt__NetworkProtocolType__RTSP:
          jsonArr["Name"] = "RTSP";
          break;
        default:
          break;
        }
        jsonArr["Enabled"] = GetNetworkProtocolsResponse.NetworkProtocols[i]->Enabled;
        if(!GetNetworkProtocolsResponse.NetworkProtocols[i]->Port.empty()){
          for(size_t j = 0; j < GetNetworkProtocolsResponse.NetworkProtocols[i]->Port.size(); j++){
            jsonArr["Port"].append(GetNetworkProtocolsResponse.NetworkProtocols[i]->Port[j]);
          }
        }
        dataJson["NetworkProtocols"].append(jsonArr);
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }

}

void device_GetNTP(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }

  _tds__GetNTP GetNTP;
  _tds__GetNTPResponse GetNTPResponse;
  if(onvifApi.device_GetNTP(clientInfo, &GetNTP, GetNTPResponse)){
    Json::Value dataJson;
    dataJson["NTPInformation"]["FromDHCP"] = GetNTPResponse.NTPInformation->FromDHCP;
    for(size_t i = 0; i < GetNTPResponse.NTPInformation->NTPFromDHCP.size(); i++){
      Json::Value jsonArr;
      switch (GetNTPResponse.NTPInformation->NTPFromDHCP[i]->Type)
      {
      case tt__NetworkHostType__IPv4:
        jsonArr["Type"] = "IPv4";
        break;
      case tt__NetworkHostType__IPv6:
        jsonArr["Type"] = "IPv6";
        break;
      case tt__NetworkHostType__DNS:
        jsonArr["Type"] = "DNS";
        break;
      default:
        break;
      }
      if(GetNTPResponse.NTPInformation->NTPFromDHCP[i]->IPv4Address){
        jsonArr["IPv4Address"] = *GetNTPResponse.NTPInformation->NTPFromDHCP[i]->IPv4Address;
      }
      if(GetNTPResponse.NTPInformation->NTPFromDHCP[i]->IPv6Address){
        jsonArr["IPv6Address"] = *GetNTPResponse.NTPInformation->NTPFromDHCP[i]->IPv6Address;
      }
      if(GetNTPResponse.NTPInformation->NTPFromDHCP[i]->DNSname){
        jsonArr["DNSname"] = *GetNTPResponse.NTPInformation->NTPFromDHCP[i]->DNSname;
      }
      dataJson["NTPInformation"]["NTPFromDHCP"].append(jsonArr);
    }
    for(size_t i = 0; i < GetNTPResponse.NTPInformation->NTPManual.size(); i++){
      Json::Value jsonArr;
      switch (GetNTPResponse.NTPInformation->NTPManual[i]->Type)
      {
      case tt__NetworkHostType__IPv4:
        jsonArr["Type"] = "IPv4";
        break;
      case tt__NetworkHostType__IPv6:
        jsonArr["Type"] = "IPv6";
        break;
      case tt__NetworkHostType__DNS:
        jsonArr["Type"] = "DNS";
        break;
      default:
        break;
      }
      if(GetNTPResponse.NTPInformation->NTPManual[i]->IPv4Address){
        jsonArr["IPv4Address"] = *GetNTPResponse.NTPInformation->NTPManual[i]->IPv4Address;
      }
      if(GetNTPResponse.NTPInformation->NTPManual[i]->IPv6Address){
        jsonArr["IPv6Address"] = *GetNTPResponse.NTPInformation->NTPManual[i]->IPv6Address;
      }
      if(GetNTPResponse.NTPInformation->NTPManual[i]->DNSname){
        jsonArr["DNSname"] = *GetNTPResponse.NTPInformation->NTPManual[i]->DNSname;
      }
      dataJson["NTPInformation"]["NTPManual"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetScopes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetScopes GetScopes;
  _tds__GetScopesResponse GetScopesResponse;
  if(onvifApi.device_GetScopes(clientInfo, &GetScopes, GetScopesResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetScopesResponse.Scopes.size(); i++){
      Json::Value jsonArr;
      switch (GetScopesResponse.Scopes[i]->ScopeDef)
      {
      case tt__ScopeDefinition__Fixed:
        jsonArr["ScopeDef"] = "Fixed";
        break;
      case tt__ScopeDefinition__Configurable:
        jsonArr["ScopeDef"] = "Configurable";
        break;
      default:
        break;
      }
      jsonArr["ScopeItem"] = GetScopesResponse.Scopes[i]->ScopeItem;
      dataJson["Scopes"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetSystemDateAndTime(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetSystemDateAndTime GetSystemDateAndTime;
  _tds__GetSystemDateAndTimeResponse GetSystemDateAndTimeResponse;
  if(onvifApi.device_GetSystemDateAndTime(clientInfo, &GetSystemDateAndTime, GetSystemDateAndTimeResponse)){
    Json::Value dataJson;
    switch (GetSystemDateAndTimeResponse.SystemDateAndTime->DateTimeType)
    {
    case tt__SetDateTimeType__Manual:
      dataJson["SystemDateAndTime"]["DateTimeType"] = "Manual";
      break;
    case tt__SetDateTimeType__NTP:
      dataJson["SystemDateAndTime"]["DateTimeType"] = "NTP";
      break;
    default:
      break;
    }
    dataJson["SystemDateAndTime"]["DaylightSavings"] = GetSystemDateAndTimeResponse.SystemDateAndTime->DaylightSavings;
    if(GetSystemDateAndTimeResponse.SystemDateAndTime->TimeZone){
      dataJson["SystemDateAndTime"]["TimeZone"]["TZ"] = GetSystemDateAndTimeResponse.SystemDateAndTime->TimeZone->TZ;
    }
    if(GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime){
      dataJson["SystemDateAndTime"]["UTCDateTime"]["Time"]["Hour"] = GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime->Time->Hour;
      dataJson["SystemDateAndTime"]["UTCDateTime"]["Time"]["Minute"] = GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime->Time->Minute;
      dataJson["SystemDateAndTime"]["UTCDateTime"]["Time"]["Second"] = GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime->Time->Second;
      dataJson["SystemDateAndTime"]["UTCDateTime"]["Date"]["Year"] = GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime->Date->Year;
      dataJson["SystemDateAndTime"]["UTCDateTime"]["Date"]["Month"] = GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime->Date->Month;
      dataJson["SystemDateAndTime"]["UTCDateTime"]["Date"]["Day"] = GetSystemDateAndTimeResponse.SystemDateAndTime->UTCDateTime->Date->Day;
    }
    if(GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime){
      dataJson["SystemDateAndTime"]["LocalDateTime"]["Time"]["Hour"] = GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime->Time->Hour;
      dataJson["SystemDateAndTime"]["LocalDateTime"]["Time"]["Minute"] = GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime->Time->Minute;
      dataJson["SystemDateAndTime"]["LocalDateTime"]["Time"]["Second"] = GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime->Time->Second;
      dataJson["SystemDateAndTime"]["LocalDateTime"]["Date"]["Year"] = GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime->Date->Year;
      dataJson["SystemDateAndTime"]["LocalDateTime"]["Date"]["Month"] = GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime->Date->Month;
      dataJson["SystemDateAndTime"]["LocalDateTime"]["Date"]["Day"] = GetSystemDateAndTimeResponse.SystemDateAndTime->LocalDateTime->Date->Day;
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetSystemLog(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  if(root_dataResponse["LogType"].isNull()){
    res.set_content("{\"status\":\"Error, not have field: LogType\"}", "text/plain");
    return;
  }
  _tds__GetSystemLog GetSystemLog;
  _tds__GetSystemLogResponse GetSystemLogResponse;
  if(root_dataResponse["LogType"].asString() == "System"){
    GetSystemLog.LogType = tt__SystemLogType__System;
  }
  else if(root_dataResponse["LogType"].asString() == "Access"){
    GetSystemLog.LogType = tt__SystemLogType__Access;
  }
  if(onvifApi.device_GetSystemLog(clientInfo, &GetSystemLog, GetSystemLogResponse)){
    Json::Value dataJson;
    if(GetSystemLogResponse.SystemLog->String){
      dataJson["SystemLog"]["String"] = *GetSystemLogResponse.SystemLog->String;
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetUsers(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetUsers GetUsers;
  _tds__GetUsersResponse GetUsersResponse;
  if(onvifApi.device_GetUsers(clientInfo, &GetUsers, GetUsersResponse)){
    Json::Value dataJson;
    Json::Value JsonArr;
    for(size_t i = 0; i < GetUsersResponse.User.size(); i++){
      JsonArr["Username"] = GetUsersResponse.User[i]->Username;
      if(GetUsersResponse.User[i]->Password){
        JsonArr["Password"] = GetUsersResponse.User[i]->Password;
      }
      switch (GetUsersResponse.User[i]->UserLevel)
      {
      case tt__UserLevel__Administrator:
        JsonArr["UserLevel"] = "Administrator";
        break;
      case tt__UserLevel__Operator:
        JsonArr["UserLevel"] = "Operator";
        break;
      case tt__UserLevel__User:
        JsonArr["UserLevel"] = "User";
        break;
      case tt__UserLevel__Anonymous:
        JsonArr["UserLevel"] = "Anonymous";
        break;
      case tt__UserLevel__Extended:
        JsonArr["UserLevel"] = "Extended";
        break;
      default:
        break;
      }
      dataJson["User"].append(JsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetWsdlUrl(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetWsdlUrl GetWsdlUrl;
  _tds__GetWsdlUrlResponse GetWsdlUrlResponse;
  if(onvifApi.device_GetWsdlUrl(clientInfo, &GetWsdlUrl, GetWsdlUrlResponse)){
    Json::Value dataJson;
    dataJson["WsdlUrl"] = GetWsdlUrlResponse.WsdlUrl;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_RemoveScopes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }

  _tds__GetWsdlUrl GetWsdlUrl;
  _tds__GetWsdlUrlResponse GetWsdlUrlResponse;
  if(onvifApi.device_GetWsdlUrl(clientInfo, &GetWsdlUrl, GetWsdlUrlResponse)){
    Json::Value dataJson;
    dataJson["WsdlUrl"] = GetWsdlUrlResponse.WsdlUrl;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_SetDiscoveryMode(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  if(root_dataResponse["DiscoveryMode"].isNull()){
    res.set_content("{\"status\":\"Error, not have field: DiscoveryMode\"}", "text/plain");
    return;
  }

  _tds__SetDiscoveryMode SetDiscoveryMode;
  _tds__SetDiscoveryModeResponse SetDiscoveryModeResponse;
  if(root_dataResponse["DiscoveryMode"].asString() == "Discoverable"){
    SetDiscoveryMode.DiscoveryMode = tt__DiscoveryMode__Discoverable;
  }
  else if(root_dataResponse["DiscoveryMode"].asString() == "NonDiscoverable"){
    SetDiscoveryMode.DiscoveryMode = tt__DiscoveryMode__NonDiscoverable;
  }
  if(onvifApi.device_SetDiscoveryMode(clientInfo, &SetDiscoveryMode, SetDiscoveryModeResponse)){
    res.set_content("{\"status\":\"ok\"}", "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_SetHostname(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetIPAddressFilter(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetNetworkDefaultGateway(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetNetworkInterfaces(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetNetworkProtocols(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetNTP(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetScopes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetSystemDateAndTime(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
}

void device_SetUser(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  if(root_dataResponse["User"].isNull()){
    res.set_content("{\"status\":\"Error, not have field: User\"}", "text/plain");
    return;
  }
  _tds__SetUser SetUser;
  _tds__SetUserResponse SetUserResponse;
  Json::Value arrayUser = root_dataResponse["User"]; // array of User
  for(unsigned int i = 0; i < arrayUser.size(); i++){
    tt__User *user;
    user = soap_new_tt__User(onvifApi.soap);
    user->Username = arrayUser[i]["Username"].asString();
    if(!arrayUser[i]["Password"].isNull()){
      std::string Password = arrayUser[i]["Password"].asString();
      user->Password = &Password;
    }
    if(arrayUser[i]["UserLevel"].asString() == "Administrator"){
      user->UserLevel = tt__UserLevel__Administrator;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "Operator"){
      user->UserLevel = tt__UserLevel__Operator;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "User"){
      user->UserLevel = tt__UserLevel__User;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "Anonymous"){
      user->UserLevel = tt__UserLevel__Anonymous;
    }
    else if(arrayUser[i]["UserLevel"].asString() == "Extended"){
      user->UserLevel = tt__UserLevel__Extended;
    }
    else{
      user->UserLevel = tt__UserLevel__User;
    }
    SetUser.User.push_back(user);
  }
  if(onvifApi.device_SetUser(clientInfo, &SetUser, SetUserResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_SystemReboot(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }

  _tds__SystemReboot SystemReboot;
  _tds__SystemRebootResponse SystemRebootResponse;
  if(onvifApi.device_SystemReboot(clientInfo, &SystemReboot, SystemRebootResponse)){
    Json::Value dataJson;
    dataJson["Message"] = SystemRebootResponse.Message;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetServices(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  if(root_dataResponse["IncludeCapability"].isNull()){
    res.set_content("{\"status\":\"Error, not have field: IncludeCapability\"}", "text/plain");
    return;
  }
  _tds__GetServices GetServices;
  _tds__GetServicesResponse GetServicesResponse;
  GetServices.IncludeCapability = root_dataResponse["IncludeCapability"].asBool();
  if(onvifApi.device_GetServices(clientInfo, &GetServices, GetServicesResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetServicesResponse.Service.size(); i++){
      Json::Value jsonArr;
      jsonArr["Namespace"] = GetServicesResponse.Service[i]->Namespace;
      jsonArr["XAddr"] = GetServicesResponse.Service[i]->XAddr;
      if(GetServicesResponse.Service[i]->Capabilities){
        // for(size_t j = 0; j < GetServicesResponse.Service[i]->Capabilities->__any.size(); j++){
        //   jsonArr["Capabilities"].append(GetServicesResponse.Service[i]->Capabilities->__any[j]);
        // }
        jsonArr["Capabilities"] = GetServicesResponse.Service[i]->Capabilities->__any;
      }
      if(GetServicesResponse.Service[i]->Version){
        jsonArr["Version"]["Major"] = GetServicesResponse.Service[i]->Version->Major;
        jsonArr["Version"]["Minor"] = GetServicesResponse.Service[i]->Version->Minor;
      }
      dataJson["Service"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void device_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tds__GetServiceCapabilities GetServiceCapabilities;
  _tds__GetServiceCapabilitiesResponse GetServiceCapabilitiesResponse;
  if(onvifApi.device_GetServiceCapabilities(clientInfo, &GetServiceCapabilities, GetServiceCapabilitiesResponse)){
    Json::Value dataJson;
    if(GetServiceCapabilitiesResponse.Capabilities){
      if(GetServiceCapabilitiesResponse.Capabilities->Network){
        if(GetServiceCapabilitiesResponse.Capabilities->Network->IPFilter){
          dataJson["Capabilities"]["Network"]["IPFilter"] = *GetServiceCapabilitiesResponse.Capabilities->Network->IPFilter;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->ZeroConfiguration){
          dataJson["Capabilities"]["Network"]["ZeroConfiguration"] = *GetServiceCapabilitiesResponse.Capabilities->Network->ZeroConfiguration;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->IPVersion6){
          dataJson["Capabilities"]["Network"]["IPVersion6"] = *GetServiceCapabilitiesResponse.Capabilities->Network->IPVersion6;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->DynDNS){
          dataJson["Capabilities"]["Network"]["DynDNS"] = *GetServiceCapabilitiesResponse.Capabilities->Network->DynDNS;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->Dot11Configuration){
          dataJson["Capabilities"]["Network"]["Dot11Configuration"] = *GetServiceCapabilitiesResponse.Capabilities->Network->Dot11Configuration;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->Dot1XConfigurations){
          dataJson["Capabilities"]["Network"]["Dot1XConfigurations"] = *GetServiceCapabilitiesResponse.Capabilities->Network->Dot1XConfigurations;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->HostnameFromDHCP){
          dataJson["Capabilities"]["Network"]["HostnameFromDHCP"] = *GetServiceCapabilitiesResponse.Capabilities->Network->HostnameFromDHCP;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->NTP){
          dataJson["Capabilities"]["Network"]["NTP"] = *GetServiceCapabilitiesResponse.Capabilities->Network->NTP;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Network->DHCPv6){
          dataJson["Capabilities"]["Network"]["DHCPv6"] = *GetServiceCapabilitiesResponse.Capabilities->Network->DHCPv6;
        }
      }
      if(GetServiceCapabilitiesResponse.Capabilities->Security){
        if(GetServiceCapabilitiesResponse.Capabilities->Security->TLS1_x002e0){
          dataJson["Capabilities"]["Security"]["TLS1.0"] = *GetServiceCapabilitiesResponse.Capabilities->Security->TLS1_x002e0;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->TLS1_x002e1){
          dataJson["Capabilities"]["Security"]["TLS1.1"] = *GetServiceCapabilitiesResponse.Capabilities->Security->TLS1_x002e1;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->TLS1_x002e2){
          dataJson["Capabilities"]["Security"]["TLS1.2"] = *GetServiceCapabilitiesResponse.Capabilities->Security->TLS1_x002e2;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->OnboardKeyGeneration){
          dataJson["Capabilities"]["Security"]["OnboardKeyGeneration"] = *GetServiceCapabilitiesResponse.Capabilities->Security->OnboardKeyGeneration;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->AccessPolicyConfig){
          dataJson["Capabilities"]["Security"]["AccessPolicyConfig"] = *GetServiceCapabilitiesResponse.Capabilities->Security->AccessPolicyConfig;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->DefaultAccessPolicy){
          dataJson["Capabilities"]["Security"]["DefaultAccessPolicy"] = *GetServiceCapabilitiesResponse.Capabilities->Security->DefaultAccessPolicy;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->Dot1X){
          dataJson["Capabilities"]["Security"]["Dot1X"] = *GetServiceCapabilitiesResponse.Capabilities->Security->Dot1X;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->RemoteUserHandling){
          dataJson["Capabilities"]["Security"]["RemoteUserHandling"] = *GetServiceCapabilitiesResponse.Capabilities->Security->RemoteUserHandling;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->X_x002e509Token){
          dataJson["Capabilities"]["Security"]["X.509Token"] = *GetServiceCapabilitiesResponse.Capabilities->Security->X_x002e509Token;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->SAMLToken){
          dataJson["Capabilities"]["Security"]["SAMLToken"] = *GetServiceCapabilitiesResponse.Capabilities->Security->SAMLToken;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->KerberosToken){
          dataJson["Capabilities"]["Security"]["KerberosToken"] = *GetServiceCapabilitiesResponse.Capabilities->Security->KerberosToken;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->UsernameToken){
          dataJson["Capabilities"]["Security"]["UsernameToken"] = *GetServiceCapabilitiesResponse.Capabilities->Security->UsernameToken;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->HttpDigest){
          dataJson["Capabilities"]["Security"]["HttpDigest"] = *GetServiceCapabilitiesResponse.Capabilities->Security->HttpDigest;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->RELToken){
          dataJson["Capabilities"]["Security"]["RELToken"] = *GetServiceCapabilitiesResponse.Capabilities->Security->RELToken;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->SupportedEAPMethods){
          dataJson["Capabilities"]["Security"]["SupportedEAPMethods"] = *GetServiceCapabilitiesResponse.Capabilities->Security->SupportedEAPMethods;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->MaxUsers){
          dataJson["Capabilities"]["Security"]["MaxUsers"] = *GetServiceCapabilitiesResponse.Capabilities->Security->MaxUsers;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->MaxUserNameLength){
          dataJson["Capabilities"]["Security"]["MaxUserNameLength"] = *GetServiceCapabilitiesResponse.Capabilities->Security->MaxUserNameLength;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->MaxPasswordLength){
          dataJson["Capabilities"]["Security"]["MaxPasswordLength"] = *GetServiceCapabilitiesResponse.Capabilities->Security->MaxPasswordLength;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->SecurityPolicies){
          dataJson["Capabilities"]["Security"]["SecurityPolicies"] = *GetServiceCapabilitiesResponse.Capabilities->Security->SecurityPolicies;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->MaxPasswordHistory){
          dataJson["Capabilities"]["Security"]["MaxPasswordHistory"] = *GetServiceCapabilitiesResponse.Capabilities->Security->MaxPasswordHistory;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->Security->HashingAlgorithms){
          dataJson["Capabilities"]["Security"]["HashingAlgorithms"] = *GetServiceCapabilitiesResponse.Capabilities->Security->HashingAlgorithms;
        }
      }
      if(GetServiceCapabilitiesResponse.Capabilities->System){
        if(GetServiceCapabilitiesResponse.Capabilities->System->DiscoveryResolve){
          dataJson["Capabilities"]["System"]["DiscoveryResolve"] = *GetServiceCapabilitiesResponse.Capabilities->System->DiscoveryResolve;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->DiscoveryBye){
          dataJson["Capabilities"]["System"]["DiscoveryBye"] = *GetServiceCapabilitiesResponse.Capabilities->System->DiscoveryBye;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->RemoteDiscovery){
          dataJson["Capabilities"]["System"]["RemoteDiscovery"] = *GetServiceCapabilitiesResponse.Capabilities->System->RemoteDiscovery;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->SystemBackup){
          dataJson["Capabilities"]["System"]["SystemBackup"] = *GetServiceCapabilitiesResponse.Capabilities->System->SystemBackup;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->SystemLogging){
          dataJson["Capabilities"]["System"]["SystemLogging"] = *GetServiceCapabilitiesResponse.Capabilities->System->SystemLogging;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->FirmwareUpgrade){
          dataJson["Capabilities"]["System"]["FirmwareUpgrade"] = *GetServiceCapabilitiesResponse.Capabilities->System->FirmwareUpgrade;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->HttpFirmwareUpgrade){
          dataJson["Capabilities"]["System"]["HttpFirmwareUpgrade"] = *GetServiceCapabilitiesResponse.Capabilities->System->HttpFirmwareUpgrade;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->HttpSystemBackup){
          dataJson["Capabilities"]["System"]["HttpSystemBackup"] = *GetServiceCapabilitiesResponse.Capabilities->System->HttpSystemBackup;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->HttpSystemLogging){
          dataJson["Capabilities"]["System"]["HttpSystemLogging"] = *GetServiceCapabilitiesResponse.Capabilities->System->HttpSystemLogging;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->HttpSupportInformation){
          dataJson["Capabilities"]["System"]["HttpSupportInformation"] = *GetServiceCapabilitiesResponse.Capabilities->System->HttpSupportInformation;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->StorageConfiguration){
          dataJson["Capabilities"]["System"]["StorageConfiguration"] = *GetServiceCapabilitiesResponse.Capabilities->System->StorageConfiguration;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->MaxStorageConfigurations){
          dataJson["Capabilities"]["System"]["MaxStorageConfigurations"] = *GetServiceCapabilitiesResponse.Capabilities->System->MaxStorageConfigurations;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->GeoLocationEntries){
          dataJson["Capabilities"]["System"]["GeoLocationEntries"] = *GetServiceCapabilitiesResponse.Capabilities->System->GeoLocationEntries;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->AutoGeo){
          dataJson["Capabilities"]["System"]["AutoGeo"] = *GetServiceCapabilitiesResponse.Capabilities->System->AutoGeo;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->StorageTypesSupported){
          dataJson["Capabilities"]["System"]["StorageTypesSupported"] = *GetServiceCapabilitiesResponse.Capabilities->System->StorageTypesSupported;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->DiscoveryNotSupported){
          dataJson["Capabilities"]["System"]["DiscoveryNotSupported"] = *GetServiceCapabilitiesResponse.Capabilities->System->DiscoveryNotSupported;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->NetworkConfigNotSupported){
          dataJson["Capabilities"]["System"]["NetworkConfigNotSupported"] = *GetServiceCapabilitiesResponse.Capabilities->System->NetworkConfigNotSupported;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->UserConfigNotSupported){
          dataJson["Capabilities"]["System"]["UserConfigNotSupported"] = *GetServiceCapabilitiesResponse.Capabilities->System->UserConfigNotSupported;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->System->Addons){
          dataJson["Capabilities"]["System"]["Addons"] = *GetServiceCapabilitiesResponse.Capabilities->System->Addons;
        }
      }
      if(GetServiceCapabilitiesResponse.Capabilities->Misc){
        if(GetServiceCapabilitiesResponse.Capabilities->Misc->AuxiliaryCommands){
          dataJson["Capabilities"]["Misc"]["AuxiliaryCommands"] = *GetServiceCapabilitiesResponse.Capabilities->Misc->AuxiliaryCommands;
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetCompatibleMetadataConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetCompatibleMetadataConfigurations GetCompatibleMetadataConfigurations;
  _trt__GetCompatibleMetadataConfigurationsResponse GetCompatibleMetadataConfigurationsResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetCompatibleMetadataConfigurations.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetCompatibleMetadataConfigurations.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(onvifApi.media_GetCompatibleMetadataConfigurations(clientInfo, &GetCompatibleMetadataConfigurations, GetCompatibleMetadataConfigurationsResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetCompatibleMetadataConfigurationsResponse.Configurations.size(); i++){
      dataJson["Configurations"]["token"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->token;
      dataJson["Configurations"]["Name"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Name;
      dataJson["Configurations"]["UseCount"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->UseCount;
      if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->CompressionType){
        dataJson["Configurations"]["CompressionType"] = *GetCompatibleMetadataConfigurationsResponse.Configurations[i]->CompressionType;
      }
      if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->GeoLocation){
        dataJson["Configurations"]["GeoLocation"] = *GetCompatibleMetadataConfigurationsResponse.Configurations[i]->GeoLocation;
      }
      if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->ShapePolygon){
        dataJson["Configurations"]["ShapePolygon"] = *GetCompatibleMetadataConfigurationsResponse.Configurations[i]->ShapePolygon;
      }
      if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->PTZStatus){
        dataJson["Configurations"]["PTZStatus"]["Status"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->PTZStatus->Status;
        dataJson["Configurations"]["PTZStatus"]["Position"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->PTZStatus->Position;
      }
      if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Analytics){
        dataJson["Configurations"]["Analytics"] = *GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Analytics;
      }
      if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast){
        if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->Address){
          switch (GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->Address->Type)
          {
          case tt__IPType__IPv4:
            dataJson["Configurations"]["Multicast"]["Address"]["Type"] = "IPv4";
            break;
          case tt__IPType__IPv6:
            dataJson["Configurations"]["Multicast"]["Address"]["Type"] = "IPv6";
            break;
          default:
            break;
          }
          if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->Address->IPv4Address){
            dataJson["Configurations"]["Multicast"]["Address"]["IPv4Address"] = *GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->Address->IPv4Address;
          }
          if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->Address->IPv6Address){
            dataJson["Configurations"]["Multicast"]["Address"]["IPv6Address"] = *GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->Address->IPv6Address;
          }
        }
        dataJson["Configurations"]["Multicast"]["Port"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->Port;
        dataJson["Configurations"]["Multicast"]["TTL"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->TTL;
        dataJson["Configurations"]["Multicast"]["AutoStart"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->Multicast->AutoStart;
      }
      dataJson["Configurations"]["SessionTimeout"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->SessionTimeout;
      if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration){
        for(size_t j = 0; j < GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule.size(); j++){
          Json::Value jsonArr;
          jsonArr["Name"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Name;
          jsonArr["Type"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Type;
          if(GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
            for(size_t k = 0; k < GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem.size(); k++){
              Json::Value jsonArrSimpleItem;
              jsonArrSimpleItem["Name"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Name;
              jsonArrSimpleItem["Value"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Value;
              jsonArr["Parameters"]["SimpleItem"].append(jsonArrSimpleItem);
            }
            for(size_t k = 0; k < GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem.size(); k++){
              Json::Value jsonArrElementItem;
              jsonArrElementItem["Name"] = GetCompatibleMetadataConfigurationsResponse.Configurations[i]->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem[k].Name;
              jsonArr["Parameters"]["ElementItem"].append(jsonArrElementItem);
            }
          }
          dataJson["Configurations"]["AnalyticsEngineConfiguration"]["AnalyticsModule"].append(jsonArr);
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetCompatibleVideoAnalyticsConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetCompatibleVideoAnalyticsConfigurations GetCompatibleVideoAnalyticsConfigurations;
  _trt__GetCompatibleVideoAnalyticsConfigurationsResponse GetCompatibleVideoAnalyticsConfigurationsResponse;
  if(onvifApi.media_GetCompatibleVideoAnalyticsConfigurations(clientInfo, &GetCompatibleVideoAnalyticsConfigurations, GetCompatibleVideoAnalyticsConfigurationsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetCompatibleVideoEncoderConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetCompatibleVideoEncoderConfigurations GetCompatibleVideoEncoderConfigurations;
  _trt__GetCompatibleVideoEncoderConfigurationsResponse GetCompatibleVideoEncoderConfigurationsResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetCompatibleVideoEncoderConfigurations.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetCompatibleVideoEncoderConfigurations.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(onvifApi.media_GetCompatibleVideoEncoderConfigurations(clientInfo, &GetCompatibleVideoEncoderConfigurations, GetCompatibleVideoEncoderConfigurationsResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetCompatibleVideoEncoderConfigurationsResponse.Configurations.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->token;
      jsonArr["Name"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Name;
      jsonArr["UseCount"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->UseCount;
      if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->GuaranteedFrameRate){
        jsonArr["GuaranteedFrameRate"] = *GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->GuaranteedFrameRate;
      }
      switch (GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Encoding)
      {
      case tt__VideoEncoding__JPEG:
        jsonArr["Encoding"] = "JPEG";
        break;
      case tt__VideoEncoding__MPEG4:
        jsonArr["Encoding"] = "MPEG4";
        break;
      case tt__VideoEncoding__H264:
        jsonArr["Encoding"] = "H264";
        break;
      default:
        break;
      }
      if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Resolution){
        jsonArr["Resolution"]["Width"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Resolution->Width;
        jsonArr["Resolution"]["Height"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Resolution->Height;
      }
      jsonArr["Quality"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Quality;
      if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->RateControl){
        jsonArr["RateControl"]["FrameRateLimit"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->RateControl->FrameRateLimit;
        jsonArr["RateControl"]["EncodingInterval"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->RateControl->EncodingInterval;
        jsonArr["RateControl"]["BitrateLimit"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->RateControl->BitrateLimit;
      }
      if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->MPEG4){
        jsonArr["MPEG4"]["GovLength"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->MPEG4->GovLength;
        switch (GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->MPEG4->Mpeg4Profile)
        {
        case tt__Mpeg4Profile__SP:
          jsonArr["MPEG4"]["Mpeg4Profile"] = "SP";
          break;
        case tt__Mpeg4Profile__ASP:
          jsonArr["MPEG4"]["Mpeg4Profile"] = "ASP";
          break;
        default:
          break;
        }
      }
      if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->H264){
        jsonArr["H264"]["GovLength"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->H264->GovLength;
        switch (GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->H264->H264Profile)
        {
        case tt__H264Profile__Baseline:
          jsonArr["H264"]["H264Profile"] = "Baseline";
          break;
        case tt__H264Profile__Main:
          jsonArr["H264"]["H264Profile"] = "Main";
          break;
        case tt__H264Profile__Extended:
          jsonArr["H264"]["H264Profile"] = "Extended";
          break;
        case tt__H264Profile__High:
          jsonArr["H264"]["H264Profile"] = "High";
          break;
        default:
          break;
        }
      }
      if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast){
        if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address){
          switch (GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address->Type)
          {
          case tt__IPType__IPv4:
            jsonArr["Multicast"]["Address"]["Type"] = "IPv4";
            break;
          case tt__IPType__IPv6:
            jsonArr["Multicast"]["Address"]["Type"] = "IPv6";
            break;
          default:
            break;
          }
          if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address->IPv4Address){
            jsonArr["Multicast"]["Address"]["IPv4Address"] = *GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address->IPv4Address;
          }
          if(GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address->IPv6Address){
            jsonArr["Multicast"]["Address"]["IPv6Address"] = *GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address->IPv6Address;
          }
        }
        jsonArr["Multicast"]["Port"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Port;
        jsonArr["Multicast"]["TTL"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->TTL;
        jsonArr["Multicast"]["AutoStart"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->AutoStart;
      }
      jsonArr["SessionTimeout"] = GetCompatibleVideoEncoderConfigurationsResponse.Configurations[i]->SessionTimeout;
      dataJson["Configurations"].append(jsonArr);
    }
    
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetCompatibleVideoSourceConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetCompatibleVideoSourceConfigurations GetCompatibleVideoSourceConfigurations;
  _trt__GetCompatibleVideoSourceConfigurationsResponse GetCompatibleVideoSourceConfigurationsResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetCompatibleVideoSourceConfigurations.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetCompatibleVideoSourceConfigurations.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(onvifApi.media_GetCompatibleVideoSourceConfigurations(clientInfo, &GetCompatibleVideoSourceConfigurations, GetCompatibleVideoSourceConfigurationsResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetCompatibleVideoSourceConfigurationsResponse.Configurations.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->token;
      jsonArr["Name"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->Name;
      jsonArr["UseCount"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->UseCount;
      if(GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->ViewMode){
        jsonArr["ViewMode"] = *GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->ViewMode;
      }
      jsonArr["SourceToken"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->SourceToken;
      if(GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->Bounds){
        jsonArr["Bounds"]["x"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->Bounds->x;
        jsonArr["Bounds"]["y"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->Bounds->y;
        jsonArr["Bounds"]["width"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->Bounds->x;
        jsonArr["Bounds"]["height"] = GetCompatibleVideoSourceConfigurationsResponse.Configurations[i]->Bounds->height;
      }
      dataJson["Configurations"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetMetadataConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetMetadataConfiguration GetMetadataConfiguration;
  _trt__GetMetadataConfigurationResponse GetMetadataConfigurationResponse;
  if(onvifApi.media_GetMetadataConfiguration(clientInfo, &GetMetadataConfiguration, GetMetadataConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetMetadataConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetMetadataConfigurationOptions GetMetadataConfigurationOptions;
  _trt__GetMetadataConfigurationOptionsResponse GetMetadataConfigurationOptionsResponse;
  if(onvifApi.media_GetMetadataConfigurationOptions(clientInfo, &GetMetadataConfigurationOptions, GetMetadataConfigurationOptionsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetMetadataConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetMetadataConfigurations GetMetadataConfigurations;
  _trt__GetMetadataConfigurationsResponse GetMetadataConfigurationsResponse;
  if(onvifApi.media_GetMetadataConfigurations(clientInfo, &GetMetadataConfigurations, GetMetadataConfigurationsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetProfile(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetProfile GetProfile;
  _trt__GetProfileResponse GetProfileResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetProfile.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetProfile.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }

  if(onvifApi.media_GetProfile(clientInfo, &GetProfile, GetProfileResponse)){
    Json::Value dataJson;
    dataJson["token"] = GetProfileResponse.Profile->token;
    if(GetProfileResponse.Profile->fixed){
      dataJson["fixed"] = *GetProfileResponse.Profile->fixed;
    }
    dataJson["Name"] = GetProfileResponse.Profile->Name;
    if(GetProfileResponse.Profile->VideoSourceConfiguration){
      dataJson["VideoSourceConfiguration"]["token"] = GetProfileResponse.Profile->VideoSourceConfiguration->token;
      dataJson["VideoSourceConfiguration"]["Name"] = GetProfileResponse.Profile->VideoSourceConfiguration->Name;
      dataJson["VideoSourceConfiguration"]["UseCount"] = GetProfileResponse.Profile->VideoSourceConfiguration->UseCount;
      if(GetProfileResponse.Profile->VideoSourceConfiguration->ViewMode){
        dataJson["VideoSourceConfiguration"]["ViewMode"] = *GetProfileResponse.Profile->VideoSourceConfiguration->ViewMode;
      }
      dataJson["VideoSourceConfiguration"]["SourceToken"] = GetProfileResponse.Profile->VideoSourceConfiguration->SourceToken;
      if(GetProfileResponse.Profile->VideoSourceConfiguration->Bounds){
        dataJson["VideoSourceConfiguration"]["Bounds"]["x"] = GetProfileResponse.Profile->VideoSourceConfiguration->Bounds->x;
        dataJson["VideoSourceConfiguration"]["Bounds"]["y"] = GetProfileResponse.Profile->VideoSourceConfiguration->Bounds->y;
        dataJson["VideoSourceConfiguration"]["Bounds"]["width"] = GetProfileResponse.Profile->VideoSourceConfiguration->Bounds->width;
        dataJson["VideoSourceConfiguration"]["Bounds"]["height"] = GetProfileResponse.Profile->VideoSourceConfiguration->Bounds->height;
      }
    }
    if(GetProfileResponse.Profile->AudioSourceConfiguration){
      dataJson["AudioSourceConfiguration"]["token"] = GetProfileResponse.Profile->AudioSourceConfiguration->token;
      dataJson["AudioSourceConfiguration"]["Name"] = GetProfileResponse.Profile->AudioSourceConfiguration->Name;
      dataJson["AudioSourceConfiguration"]["UseCount"] = GetProfileResponse.Profile->AudioSourceConfiguration->UseCount;
      dataJson["AudioSourceConfiguration"]["SourceToken"] = GetProfileResponse.Profile->AudioSourceConfiguration->SourceToken;
    }
    if(GetProfileResponse.Profile->VideoEncoderConfiguration){
      dataJson["VideoEncoderConfiguration"]["token"] = GetProfileResponse.Profile->VideoEncoderConfiguration->token;
      dataJson["VideoEncoderConfiguration"]["Name"] = GetProfileResponse.Profile->VideoEncoderConfiguration->Name;
      dataJson["VideoEncoderConfiguration"]["UseCount"] = GetProfileResponse.Profile->VideoEncoderConfiguration->UseCount;
      if(GetProfileResponse.Profile->VideoEncoderConfiguration->GuaranteedFrameRate){
        dataJson["VideoEncoderConfiguration"]["GuaranteedFrameRate"] = *GetProfileResponse.Profile->VideoEncoderConfiguration->GuaranteedFrameRate;
      }
      switch(GetProfileResponse.Profile->VideoEncoderConfiguration->Encoding){
      case tt__VideoEncoding__JPEG:
        dataJson["VideoEncoderConfiguration"]["Encoding"] = "JPEG";
        break;
      case tt__VideoEncoding__MPEG4:
        dataJson["VideoEncoderConfiguration"]["Encoding"] = "MPEG4";
        break;
      case tt__VideoEncoding__H264:
        dataJson["VideoEncoderConfiguration"]["Encoding"] = "H264";
        break;
      default:
        break;
      }
      if(GetProfileResponse.Profile->VideoEncoderConfiguration->Resolution){
        dataJson["VideoEncoderConfiguration"]["Resolution"]["Width"] = GetProfileResponse.Profile->VideoEncoderConfiguration->Resolution->Width;
        dataJson["VideoEncoderConfiguration"]["Resolution"]["Height"] = GetProfileResponse.Profile->VideoEncoderConfiguration->Resolution->Height;
      }
      dataJson["VideoEncoderConfiguration"]["Quality"] = GetProfileResponse.Profile->VideoEncoderConfiguration->Quality;
      if(GetProfileResponse.Profile->VideoEncoderConfiguration->RateControl){
        dataJson["VideoEncoderConfiguration"]["RateControl"]["FrameRateLimit"] = GetProfileResponse.Profile->VideoEncoderConfiguration->RateControl->FrameRateLimit;
        dataJson["VideoEncoderConfiguration"]["RateControl"]["EncodingInterval"] = GetProfileResponse.Profile->VideoEncoderConfiguration->RateControl->EncodingInterval;
        dataJson["VideoEncoderConfiguration"]["RateControl"]["BitrateLimit"] = GetProfileResponse.Profile->VideoEncoderConfiguration->RateControl->BitrateLimit;
      }
      if(GetProfileResponse.Profile->VideoEncoderConfiguration->MPEG4){
        dataJson["VideoEncoderConfiguration"]["MPEG4"]["GovLength"] = GetProfileResponse.Profile->VideoEncoderConfiguration->MPEG4->GovLength;
        switch(GetProfileResponse.Profile->VideoEncoderConfiguration->MPEG4->Mpeg4Profile){
        case tt__Mpeg4Profile__SP:
          dataJson["VideoEncoderConfiguration"]["MPEG4"]["Mpeg4Profile"] = "SP";
          break;
        case tt__Mpeg4Profile__ASP:
          dataJson["VideoEncoderConfiguration"]["MPEG4"]["Mpeg4Profile"] = "ASP";
          break;
        default:
          break;
        }
      }
      if(GetProfileResponse.Profile->VideoEncoderConfiguration->H264){
        dataJson["VideoEncoderConfiguration"]["H264"]["GovLength"] = GetProfileResponse.Profile->VideoEncoderConfiguration->H264->GovLength;
        switch(GetProfileResponse.Profile->VideoEncoderConfiguration->H264->H264Profile){
        case tt__H264Profile__Baseline:
          dataJson["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "Baseline";
          break;
        case tt__H264Profile__Main:
          dataJson["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "Main";
          break;
        case tt__H264Profile__Extended:
          dataJson["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "Extended";
          break;
        case tt__H264Profile__High:
          dataJson["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "High";
          break;
        default:
          break;
        }
      }
      if(GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast){
        if(GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->Address){
          switch (GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->Address->Type)
          {
          case tt__IPType__IPv4:
            dataJson["VideoEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv4";
            break;
          case tt__IPType__IPv6:
            dataJson["VideoEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv6";
            break;
          default:
            break;
          }
          if(GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->Address->IPv4Address){
            dataJson["VideoEncoderConfiguration"]["Multicast"]["Address"]["IPv4Address"] = *GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->Address->IPv4Address;
          }
          if(GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->Address->IPv6Address){
            dataJson["VideoEncoderConfiguration"]["Multicast"]["Address"]["IPv6Address"] = *GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->Address->IPv6Address;
          }
        }
        dataJson["VideoEncoderConfiguration"]["Multicast"]["Port"] = GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->Port;
        dataJson["VideoEncoderConfiguration"]["Multicast"]["TTL"] = GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->TTL;
        dataJson["VideoEncoderConfiguration"]["Multicast"]["AutoStart"] = GetProfileResponse.Profile->VideoEncoderConfiguration->Multicast->AutoStart;
      }
      dataJson["VideoEncoderConfiguration"]["SessionTimeout"] = GetProfileResponse.Profile->VideoEncoderConfiguration->SessionTimeout;
    }
    if(GetProfileResponse.Profile->AudioEncoderConfiguration){
      dataJson["AudioEncoderConfiguration"]["token"] = GetProfileResponse.Profile->AudioEncoderConfiguration->token;
      dataJson["AudioEncoderConfiguration"]["Name"] = GetProfileResponse.Profile->AudioEncoderConfiguration->Name;
      dataJson["AudioEncoderConfiguration"]["UseCount"] = GetProfileResponse.Profile->AudioEncoderConfiguration->UseCount;
      switch(GetProfileResponse.Profile->AudioEncoderConfiguration->Encoding){
      case tt__AudioEncoding__G711:
        dataJson["AudioEncoderConfiguration"]["Encoding"] = "G711";
        break;
      case tt__AudioEncoding__G726:
        dataJson["AudioEncoderConfiguration"]["Encoding"] = "G726";
        break;
      case tt__AudioEncoding__AAC:
        dataJson["AudioEncoderConfiguration"]["Encoding"] = "AAC";
        break;
      default:
        break;
      }
      dataJson["AudioEncoderConfiguration"]["Bitrate"] = GetProfileResponse.Profile->AudioEncoderConfiguration->Bitrate;
      dataJson["AudioEncoderConfiguration"]["SampleRate"] = GetProfileResponse.Profile->AudioEncoderConfiguration->SampleRate;
      if(GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast){
        if(GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address){
          switch (GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address->Type)
          {
          case tt__IPType__IPv4:
            dataJson["AudioEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv4";
            break;
          case tt__IPType__IPv6:
            dataJson["AudioEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv6";
            break;
          default:
            break;
          }
          if(GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address->IPv4Address){
            dataJson["AudioEncoderConfiguration"]["Multicast"]["Address"]["IPv4Address"] = *GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address->IPv4Address;
          }
          if(GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address->IPv6Address){
            dataJson["AudioEncoderConfiguration"]["Multicast"]["Address"]["IPv6Address"] = *GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address->IPv6Address;
          }
        }
        dataJson["AudioEncoderConfiguration"]["Multicast"]["Port"] = GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Port;
        dataJson["AudioEncoderConfiguration"]["Multicast"]["TTL"] = GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->TTL;
        dataJson["AudioEncoderConfiguration"]["Multicast"]["AutoStart"] = GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->AutoStart;
      }
      dataJson["AudioEncoderConfiguration"]["SessionTimeout"] = GetProfileResponse.Profile->AudioEncoderConfiguration->SessionTimeout;
    }
    if(GetProfileResponse.Profile->VideoAnalyticsConfiguration){
      dataJson["VideoAnalyticsConfiguration"]["token"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->token;
      dataJson["VideoAnalyticsConfiguration"]["Name"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->Name;
      dataJson["VideoAnalyticsConfiguration"]["UseCount"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->UseCount;
      if(GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration){
        for(size_t j = 0; j < GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.size(); j++){
          Json::Value dataJsonAnalyticsModule;
          dataJsonAnalyticsModule["Name"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Name;
          dataJsonAnalyticsModule["Type"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Type;
          if(GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
            for(size_t k = 0; k < GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem.size(); k++){
              Json::Value dataJsonSimpleItem;
              dataJsonSimpleItem["Name"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Name;
              dataJsonSimpleItem["Value"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Value;
              dataJsonAnalyticsModule["Parameters"]["SimpleItem"].append(dataJsonSimpleItem);
            }
          }
          if(GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
            for(size_t k = 0; k < GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem.size(); k++){
              Json::Value dataJsonElementItem;
              dataJsonElementItem["Name"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem[k].Name;
              dataJsonAnalyticsModule["Parameters"]["ElementItem"].append(dataJsonElementItem);
            }
          }
          dataJson["VideoAnalyticsConfiguration"]["AnalyticsEngineConfiguration"]["AnalyticsModule"].append(dataJsonAnalyticsModule);
        }
      }
      if(GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration){
        for(size_t j = 0; j < GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule.size(); j++){
          Json::Value dataJsonRule;
          dataJsonRule["Name"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Name;
          dataJsonRule["Type"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Type;
          if(GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters){
            for(size_t k = 0; k < GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->SimpleItem.size(); k++){
              Json::Value dataJsonSimpleItem;
              dataJsonSimpleItem["Name"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->SimpleItem[k].Name;
              dataJsonSimpleItem["Value"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->SimpleItem[k].Value;
              dataJsonRule["Parameters"]["SimpleItem"].append(dataJsonSimpleItem);
            }
          }
          if(GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters){
            for(size_t k = 0; k < GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->ElementItem.size(); k++){
              Json::Value dataJsonElementItem;
              dataJsonElementItem["Name"] = GetProfileResponse.Profile->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->ElementItem[k].Name;
              dataJsonRule["Parameters"]["ElementItem"].append(dataJsonElementItem);
            }
          }
          dataJson["VideoAnalyticsConfiguration"]["RuleEngineConfiguration"]["Rule"].append(dataJsonRule);
        }
      }
    }
    if(GetProfileResponse.Profile->PTZConfiguration){
      dataJson["PTZConfiguration"]["token"] = GetProfileResponse.Profile->PTZConfiguration->token;
      dataJson["PTZConfiguration"]["Name"] = GetProfileResponse.Profile->PTZConfiguration->Name;
      dataJson["PTZConfiguration"]["UseCount"] = GetProfileResponse.Profile->PTZConfiguration->UseCount;
      if(GetProfileResponse.Profile->PTZConfiguration->MoveRamp){
        dataJson["PTZConfiguration"]["MoveRamp"] = *GetProfileResponse.Profile->PTZConfiguration->MoveRamp;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->PresetRamp){
        dataJson["PTZConfiguration"]["PresetRamp"] = *GetProfileResponse.Profile->PTZConfiguration->PresetRamp;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->PresetTourRamp){
        dataJson["PTZConfiguration"]["PresetTourRamp"] = *GetProfileResponse.Profile->PTZConfiguration->PresetTourRamp;
      }
      dataJson["PTZConfiguration"]["NodeToken"] = GetProfileResponse.Profile->PTZConfiguration->NodeToken;
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultAbsolutePantTiltPositionSpace){
        dataJson["PTZConfiguration"]["DefaultAbsolutePantTiltPositionSpace"] = *GetProfileResponse.Profile->PTZConfiguration->DefaultAbsolutePantTiltPositionSpace;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultAbsoluteZoomPositionSpace){
        dataJson["PTZConfiguration"]["DefaultAbsoluteZoomPositionSpace"] = *GetProfileResponse.Profile->PTZConfiguration->DefaultAbsoluteZoomPositionSpace;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultRelativePanTiltTranslationSpace){
        dataJson["PTZConfiguration"]["DefaultRelativePanTiltTranslationSpace"] = *GetProfileResponse.Profile->PTZConfiguration->DefaultRelativePanTiltTranslationSpace;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultRelativeZoomTranslationSpace){
        dataJson["PTZConfiguration"]["DefaultRelativeZoomTranslationSpace"] = *GetProfileResponse.Profile->PTZConfiguration->DefaultRelativeZoomTranslationSpace;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultContinuousPanTiltVelocitySpace){
        dataJson["PTZConfiguration"]["DefaultContinuousPanTiltVelocitySpace"] = *GetProfileResponse.Profile->PTZConfiguration->DefaultContinuousPanTiltVelocitySpace;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultContinuousZoomVelocitySpace){
        dataJson["PTZConfiguration"]["DefaultContinuousZoomVelocitySpace"] = *GetProfileResponse.Profile->PTZConfiguration->DefaultContinuousZoomVelocitySpace;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultPTZSpeed){
        if(GetProfileResponse.Profile->PTZConfiguration->DefaultPTZSpeed->PanTilt){
          dataJson["PTZConfiguration"]["DefaultPTZSpeed"]["PanTilt"]["x"] = GetProfileResponse.Profile->PTZConfiguration->DefaultPTZSpeed->PanTilt->x;
          dataJson["PTZConfiguration"]["DefaultPTZSpeed"]["PanTilt"]["y"] = GetProfileResponse.Profile->PTZConfiguration->DefaultPTZSpeed->PanTilt->y;
        }
        if(GetProfileResponse.Profile->PTZConfiguration->DefaultPTZSpeed->Zoom){
          dataJson["PTZConfiguration"]["DefaultPTZSpeed"]["Zoom"]["x"] = GetProfileResponse.Profile->PTZConfiguration->DefaultPTZSpeed->Zoom->x;
        }
      }
      if(GetProfileResponse.Profile->PTZConfiguration->DefaultPTZTimeout){
        dataJson["PTZConfiguration"]["DefaultPTZTimeout"] = *GetProfileResponse.Profile->PTZConfiguration->DefaultPTZTimeout;
      }
      if(GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits){
        if(GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range){
          dataJson["PTZConfiguration"]["PanTiltLimits"]["Range"]["URI"] = GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range->URI;
          if(GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range->XRange){
            dataJson["PTZConfiguration"]["PanTiltLimits"]["Range"]["XRange"]["Min"] = GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range->XRange->Min;
            dataJson["PTZConfiguration"]["PanTiltLimits"]["Range"]["XRange"]["Max"] = GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range->XRange->Max;
          }
          if(GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range->YRange){
            dataJson["PTZConfiguration"]["PanTiltLimits"]["Range"]["YRange"]["Min"] = GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range->YRange->Min;
            dataJson["PTZConfiguration"]["PanTiltLimits"]["Range"]["YRange"]["Max"] = GetProfileResponse.Profile->PTZConfiguration->PanTiltLimits->Range->YRange->Max;
          }
        }
      }
      if(GetProfileResponse.Profile->PTZConfiguration->ZoomLimits){
        if(GetProfileResponse.Profile->PTZConfiguration->ZoomLimits->Range){
          dataJson["PTZConfiguration"]["ZoomLimits"]["Range"]["URI"] = GetProfileResponse.Profile->PTZConfiguration->ZoomLimits->Range->URI;
          if(GetProfileResponse.Profile->PTZConfiguration->ZoomLimits->Range->XRange){
            dataJson["PTZConfiguration"]["ZoomLimits"]["Range"]["XRange"]["Min"] = GetProfileResponse.Profile->PTZConfiguration->ZoomLimits->Range->XRange->Min;
            dataJson["PTZConfiguration"]["ZoomLimits"]["Range"]["XRange"]["Max"] = GetProfileResponse.Profile->PTZConfiguration->ZoomLimits->Range->XRange->Max;
          }
        }
      }
    }
    if(GetProfileResponse.Profile->MetadataConfiguration){
      dataJson["MetadataConfiguration"]["token"] = GetProfileResponse.Profile->MetadataConfiguration->token;
      dataJson["MetadataConfiguration"]["Name"] = GetProfileResponse.Profile->MetadataConfiguration->Name;
      dataJson["MetadataConfiguration"]["UseCount"] = GetProfileResponse.Profile->MetadataConfiguration->UseCount;
      if(GetProfileResponse.Profile->MetadataConfiguration->CompressionType){
        dataJson["MetadataConfiguration"]["CompressionType"] = *GetProfileResponse.Profile->MetadataConfiguration->CompressionType;
      }
      if(GetProfileResponse.Profile->MetadataConfiguration->GeoLocation){
        dataJson["MetadataConfiguration"]["GeoLocation"] = *GetProfileResponse.Profile->MetadataConfiguration->GeoLocation;
      }
      if(GetProfileResponse.Profile->MetadataConfiguration->ShapePolygon){
        dataJson["MetadataConfiguration"]["ShapePolygon"] = *GetProfileResponse.Profile->MetadataConfiguration->ShapePolygon;
      }
      if(GetProfileResponse.Profile->MetadataConfiguration->PTZStatus){
        dataJson["MetadataConfiguration"]["PTZStatus"]["Status"] = GetProfileResponse.Profile->MetadataConfiguration->PTZStatus->Status;
        dataJson["MetadataConfiguration"]["PTZStatus"]["Position"] = GetProfileResponse.Profile->MetadataConfiguration->PTZStatus->Position;
      }
      if(GetProfileResponse.Profile->MetadataConfiguration->Analytics){
        dataJson["MetadataConfiguration"]["Analytics"] = *GetProfileResponse.Profile->MetadataConfiguration->Analytics;
      }
      if(GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast){
        if(GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address){
          switch (GetProfileResponse.Profile->AudioEncoderConfiguration->Multicast->Address->Type)
          {
          case tt__IPType__IPv4:
            dataJson["MetadataConfiguration"]["Multicast"]["Address"]["Type"] = "IPv4";
            break;
          case tt__IPType__IPv6:
            dataJson["MetadataConfiguration"]["Multicast"]["Address"]["Type"] = "IPv6";
            break;
          default:
            break;
          }
          if(GetProfileResponse.Profile->MetadataConfiguration->Multicast->Address->IPv4Address){
            dataJson["MetadataConfiguration"]["Multicast"]["Address"]["IPv4Address"] = *GetProfileResponse.Profile->MetadataConfiguration->Multicast->Address->IPv4Address;
          }
          if(GetProfileResponse.Profile->MetadataConfiguration->Multicast->Address->IPv6Address){
            dataJson["MetadataConfiguration"]["Multicast"]["Address"]["IPv6Address"] = *GetProfileResponse.Profile->MetadataConfiguration->Multicast->Address->IPv6Address;
          }
        }
        dataJson["MetadataConfiguration"]["Multicast"]["Port"] = GetProfileResponse.Profile->MetadataConfiguration->Multicast->Port;
        dataJson["MetadataConfiguration"]["Multicast"]["TTL"] = GetProfileResponse.Profile->MetadataConfiguration->Multicast->TTL;
        dataJson["MetadataConfiguration"]["Multicast"]["AutoStart"] = GetProfileResponse.Profile->MetadataConfiguration->Multicast->AutoStart;
      }
      dataJson["MetadataConfiguration"]["SessionTimeout"] = GetProfileResponse.Profile->MetadataConfiguration->SessionTimeout;
      if(GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration){
        for(size_t j = 0; j < GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.size(); j++){
          Json::Value dataJsonAnalyticsModule;
          dataJsonAnalyticsModule["Name"] = GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Name;
          dataJsonAnalyticsModule["Type"] = GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Type;
          if(GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
            for(size_t k = 0; k < GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem.size(); k++){
              Json::Value dataJsonSimpleItem;
              dataJsonSimpleItem["Name"] = GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Name;
              dataJsonSimpleItem["Value"] = GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Value;
              dataJsonAnalyticsModule["Parameters"]["SimpleItem"].append(dataJsonSimpleItem);
            }
          }
          if(GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
            for(size_t k = 0; k < GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem.size(); k++){
              Json::Value dataJsonElementItem;
              dataJsonElementItem["Name"] = GetProfileResponse.Profile->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem[k].Name;
              dataJsonAnalyticsModule["Parameters"]["ElementItem"].append(dataJsonElementItem);
            }
          }
          dataJson["MetadataConfiguration"]["AnalyticsEngineConfiguration"]["AnalyticsModule"].append(dataJsonAnalyticsModule);
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }


}

void media_GetProfiles(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetProfiles GetProfiles;
  _trt__GetProfilesResponse GetProfilesResponse;
  if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetProfilesResponse.Profiles.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetProfilesResponse.Profiles[i]->token;
      if(GetProfilesResponse.Profiles[i]->fixed){
        jsonArr["fixed"] = *GetProfilesResponse.Profiles[i]->fixed;
      }
      jsonArr["Name"] = GetProfilesResponse.Profiles[i]->Name;
      if(GetProfilesResponse.Profiles[i]->VideoSourceConfiguration){
        jsonArr["VideoSourceConfiguration"]["token"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->token;
        jsonArr["VideoSourceConfiguration"]["Name"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->Name;
        jsonArr["VideoSourceConfiguration"]["UseCount"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->UseCount;
        if(GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->ViewMode){
          jsonArr["VideoSourceConfiguration"]["ViewMode"] = *GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->ViewMode;
        }
        jsonArr["VideoSourceConfiguration"]["SourceToken"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->SourceToken;
        if(GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->Bounds){
          jsonArr["VideoSourceConfiguration"]["Bounds"]["x"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->Bounds->x;
          jsonArr["VideoSourceConfiguration"]["Bounds"]["y"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->Bounds->y;
          jsonArr["VideoSourceConfiguration"]["Bounds"]["width"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->Bounds->width;
          jsonArr["VideoSourceConfiguration"]["Bounds"]["height"] = GetProfilesResponse.Profiles[i]->VideoSourceConfiguration->Bounds->height;
        }
      }
      if(GetProfilesResponse.Profiles[i]->AudioSourceConfiguration){
        jsonArr["AudioSourceConfiguration"]["token"] = GetProfilesResponse.Profiles[i]->AudioSourceConfiguration->token;
        jsonArr["AudioSourceConfiguration"]["Name"] = GetProfilesResponse.Profiles[i]->AudioSourceConfiguration->Name;
        jsonArr["AudioSourceConfiguration"]["UseCount"] = GetProfilesResponse.Profiles[i]->AudioSourceConfiguration->UseCount;
        jsonArr["AudioSourceConfiguration"]["SourceToken"] = GetProfilesResponse.Profiles[i]->AudioSourceConfiguration->SourceToken;
      }
      if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration){
        jsonArr["VideoEncoderConfiguration"]["token"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->token;
        jsonArr["VideoEncoderConfiguration"]["Name"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Name;
        jsonArr["VideoEncoderConfiguration"]["UseCount"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->UseCount;
        if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->GuaranteedFrameRate){
          jsonArr["VideoEncoderConfiguration"]["GuaranteedFrameRate"] = *GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->GuaranteedFrameRate;
        }
        switch(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Encoding){
        case tt__VideoEncoding__JPEG:
          jsonArr["VideoEncoderConfiguration"]["Encoding"] = "JPEG";
          break;
        case tt__VideoEncoding__MPEG4:
          jsonArr["VideoEncoderConfiguration"]["Encoding"] = "MPEG4";
          break;
        case tt__VideoEncoding__H264:
          jsonArr["VideoEncoderConfiguration"]["Encoding"] = "H264";
          break;
        default:
          break;
        }
        if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Resolution){
          jsonArr["VideoEncoderConfiguration"]["Resolution"]["Width"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Resolution->Width;
          jsonArr["VideoEncoderConfiguration"]["Resolution"]["Height"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Resolution->Height;
        }
        jsonArr["VideoEncoderConfiguration"]["Quality"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Quality;
        if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->RateControl){
          jsonArr["VideoEncoderConfiguration"]["RateControl"]["FrameRateLimit"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->RateControl->FrameRateLimit;
          jsonArr["VideoEncoderConfiguration"]["RateControl"]["EncodingInterval"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->RateControl->EncodingInterval;
          jsonArr["VideoEncoderConfiguration"]["RateControl"]["BitrateLimit"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->RateControl->BitrateLimit;
        }
        if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->MPEG4){
          jsonArr["VideoEncoderConfiguration"]["MPEG4"]["GovLength"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->MPEG4->GovLength;
          switch(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->MPEG4->Mpeg4Profile){
          case tt__Mpeg4Profile__SP:
            jsonArr["VideoEncoderConfiguration"]["MPEG4"]["Mpeg4Profile"] = "SP";
            break;
          case tt__Mpeg4Profile__ASP:
            jsonArr["VideoEncoderConfiguration"]["MPEG4"]["Mpeg4Profile"] = "ASP";
            break;
          default:
            break;
          }
        }
        if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->H264){
          jsonArr["VideoEncoderConfiguration"]["H264"]["GovLength"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->H264->GovLength;
          switch(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->H264->H264Profile){
          case tt__H264Profile__Baseline:
            jsonArr["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "Baseline";
            break;
          case tt__H264Profile__Main:
            jsonArr["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "Main";
            break;
          case tt__H264Profile__Extended:
            jsonArr["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "Extended";
            break;
          case tt__H264Profile__High:
            jsonArr["VideoEncoderConfiguration"]["H264"]["H264Profile"] = "High";
            break;
          default:
            break;
          }
        }
        if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast){
          if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->Address){
            switch (GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->Address->Type)
            {
            case tt__IPType__IPv4:
              jsonArr["VideoEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv4";
              break;
            case tt__IPType__IPv6:
              jsonArr["VideoEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv6";
              break;
            default:
              break;
            }
            if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->Address->IPv4Address){
              jsonArr["VideoEncoderConfiguration"]["Multicast"]["Address"]["IPv4Address"] = *GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->Address->IPv4Address;
            }
            if(GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->Address->IPv6Address){
              jsonArr["VideoEncoderConfiguration"]["Multicast"]["Address"]["IPv6Address"] = *GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->Address->IPv6Address;
            }
          }
          jsonArr["VideoEncoderConfiguration"]["Multicast"]["Port"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->Port;
          jsonArr["VideoEncoderConfiguration"]["Multicast"]["TTL"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->TTL;
          jsonArr["VideoEncoderConfiguration"]["Multicast"]["AutoStart"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->Multicast->AutoStart;
        }
        jsonArr["VideoEncoderConfiguration"]["SessionTimeout"] = GetProfilesResponse.Profiles[i]->VideoEncoderConfiguration->SessionTimeout;
      }
      if(GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration){
        jsonArr["AudioEncoderConfiguration"]["token"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->token;
        jsonArr["AudioEncoderConfiguration"]["Name"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Name;
        jsonArr["AudioEncoderConfiguration"]["UseCount"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->UseCount;
        switch(GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Encoding){
        case tt__AudioEncoding__G711:
          jsonArr["AudioEncoderConfiguration"]["Encoding"] = "G711";
          break;
        case tt__AudioEncoding__G726:
          jsonArr["AudioEncoderConfiguration"]["Encoding"] = "G726";
          break;
        case tt__AudioEncoding__AAC:
          jsonArr["AudioEncoderConfiguration"]["Encoding"] = "AAC";
          break;
        default:
          break;
        }
        jsonArr["AudioEncoderConfiguration"]["Bitrate"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Bitrate;
        jsonArr["AudioEncoderConfiguration"]["SampleRate"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->SampleRate;
        if(GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast){
          if(GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->Address){
            switch (GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->Address->Type)
            {
            case tt__IPType__IPv4:
              jsonArr["AudioEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv4";
              break;
            case tt__IPType__IPv6:
              jsonArr["AudioEncoderConfiguration"]["Multicast"]["Address"]["Type"] = "IPv6";
              break;
            default:
              break;
            }
            if(GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->Address->IPv4Address){
              jsonArr["AudioEncoderConfiguration"]["Multicast"]["Address"]["IPv4Address"] = *GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->Address->IPv4Address;
            }
            if(GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->Address->IPv6Address){
              jsonArr["AudioEncoderConfiguration"]["Multicast"]["Address"]["IPv6Address"] = *GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->Address->IPv6Address;
            }
          }
          jsonArr["AudioEncoderConfiguration"]["Multicast"]["Port"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->Port;
          jsonArr["AudioEncoderConfiguration"]["Multicast"]["TTL"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->TTL;
          jsonArr["AudioEncoderConfiguration"]["Multicast"]["AutoStart"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->Multicast->AutoStart;
        }
        jsonArr["AudioEncoderConfiguration"]["SessionTimeout"] = GetProfilesResponse.Profiles[i]->AudioEncoderConfiguration->SessionTimeout;
      }
      if(GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration){
        jsonArr["VideoAnalyticsConfiguration"]["token"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->token;
        jsonArr["VideoAnalyticsConfiguration"]["Name"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->Name;
        jsonArr["VideoAnalyticsConfiguration"]["UseCount"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->UseCount;
        if(GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration){
          for(size_t j = 0; j < GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.size(); j++){
            Json::Value jsonArrAnalyticsModule;
            jsonArrAnalyticsModule["Name"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Name;
            jsonArrAnalyticsModule["Type"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Type;
            if(GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
              for(size_t k = 0; k < GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem.size(); k++){
                Json::Value jsonArrSimpleItem;
                jsonArrSimpleItem["Name"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Name;
                jsonArrSimpleItem["Value"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Value;
                jsonArrAnalyticsModule["Parameters"]["SimpleItem"].append(jsonArrSimpleItem);
              }
            }
            if(GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
              for(size_t k = 0; k < GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem.size(); k++){
                Json::Value jsonArrElementItem;
                jsonArrElementItem["Name"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem[k].Name;
                jsonArrAnalyticsModule["Parameters"]["ElementItem"].append(jsonArrElementItem);
              }
            }
            jsonArr["VideoAnalyticsConfiguration"]["AnalyticsEngineConfiguration"]["AnalyticsModule"].append(jsonArrAnalyticsModule);
          }
        }
        if(GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration){
          for(size_t j = 0; j < GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule.size(); j++){
            Json::Value jsonArrRule;
            jsonArrRule["Name"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Name;
            jsonArrRule["Type"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Type;
            if(GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters){
              for(size_t k = 0; k < GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->SimpleItem.size(); k++){
                Json::Value jsonArrSimpleItem;
                jsonArrSimpleItem["Name"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->SimpleItem[k].Name;
                jsonArrSimpleItem["Value"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->SimpleItem[k].Value;
                jsonArrRule["Parameters"]["SimpleItem"].append(jsonArrSimpleItem);
              }
            }
            if(GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters){
              for(size_t k = 0; k < GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->ElementItem.size(); k++){
                Json::Value jsonArrElementItem;
                jsonArrElementItem["Name"] = GetProfilesResponse.Profiles[i]->VideoAnalyticsConfiguration->RuleEngineConfiguration->Rule[j]->Parameters->ElementItem[k].Name;
                jsonArrRule["Parameters"]["ElementItem"].append(jsonArrElementItem);
              }
            }
            jsonArr["VideoAnalyticsConfiguration"]["RuleEngineConfiguration"]["Rule"].append(jsonArrRule);
          }
        }
      }
      if(GetProfilesResponse.Profiles[i]->PTZConfiguration){
        jsonArr["PTZConfiguration"]["token"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->token;
        jsonArr["PTZConfiguration"]["Name"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->Name;
        jsonArr["PTZConfiguration"]["UseCount"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->UseCount;
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->MoveRamp){
          jsonArr["PTZConfiguration"]["MoveRamp"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->MoveRamp;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->PresetRamp){
          jsonArr["PTZConfiguration"]["PresetRamp"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->PresetRamp;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->PresetTourRamp){
          jsonArr["PTZConfiguration"]["PresetTourRamp"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->PresetTourRamp;
        }
        jsonArr["PTZConfiguration"]["NodeToken"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->NodeToken;
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultAbsolutePantTiltPositionSpace){
          jsonArr["PTZConfiguration"]["DefaultAbsolutePantTiltPositionSpace"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultAbsolutePantTiltPositionSpace;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultAbsoluteZoomPositionSpace){
          jsonArr["PTZConfiguration"]["DefaultAbsoluteZoomPositionSpace"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultAbsoluteZoomPositionSpace;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultRelativePanTiltTranslationSpace){
          jsonArr["PTZConfiguration"]["DefaultRelativePanTiltTranslationSpace"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultRelativePanTiltTranslationSpace;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultRelativeZoomTranslationSpace){
          jsonArr["PTZConfiguration"]["DefaultRelativeZoomTranslationSpace"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultRelativeZoomTranslationSpace;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultContinuousPanTiltVelocitySpace){
          jsonArr["PTZConfiguration"]["DefaultContinuousPanTiltVelocitySpace"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultContinuousPanTiltVelocitySpace;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultContinuousZoomVelocitySpace){
          jsonArr["PTZConfiguration"]["DefaultContinuousZoomVelocitySpace"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultContinuousZoomVelocitySpace;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZSpeed){
          if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZSpeed->PanTilt){
            jsonArr["PTZConfiguration"]["DefaultPTZSpeed"]["PanTilt"]["x"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZSpeed->PanTilt->x;
            jsonArr["PTZConfiguration"]["DefaultPTZSpeed"]["PanTilt"]["y"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZSpeed->PanTilt->y;
          }
          if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZSpeed->Zoom){
            jsonArr["PTZConfiguration"]["DefaultPTZSpeed"]["Zoom"]["x"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZSpeed->Zoom->x;
          }
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZTimeout){
          jsonArr["PTZConfiguration"]["DefaultPTZTimeout"] = *GetProfilesResponse.Profiles[i]->PTZConfiguration->DefaultPTZTimeout;
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits){
          if(GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range){
            jsonArr["PTZConfiguration"]["PanTiltLimits"]["Range"]["URI"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range->URI;
            if(GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range->XRange){
              jsonArr["PTZConfiguration"]["PanTiltLimits"]["Range"]["XRange"]["Min"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range->XRange->Min;
              jsonArr["PTZConfiguration"]["PanTiltLimits"]["Range"]["XRange"]["Max"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range->XRange->Max;
            }
            if(GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range->YRange){
              jsonArr["PTZConfiguration"]["PanTiltLimits"]["Range"]["YRange"]["Min"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range->YRange->Min;
              jsonArr["PTZConfiguration"]["PanTiltLimits"]["Range"]["YRange"]["Max"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->PanTiltLimits->Range->YRange->Max;
            }
          }
        }
        if(GetProfilesResponse.Profiles[i]->PTZConfiguration->ZoomLimits){
          if(GetProfilesResponse.Profiles[i]->PTZConfiguration->ZoomLimits->Range){
            jsonArr["PTZConfiguration"]["ZoomLimits"]["Range"]["URI"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->ZoomLimits->Range->URI;
            if(GetProfilesResponse.Profiles[i]->PTZConfiguration->ZoomLimits->Range->XRange){
              jsonArr["PTZConfiguration"]["ZoomLimits"]["Range"]["XRange"]["Min"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->ZoomLimits->Range->XRange->Min;
              jsonArr["PTZConfiguration"]["ZoomLimits"]["Range"]["XRange"]["Max"] = GetProfilesResponse.Profiles[i]->PTZConfiguration->ZoomLimits->Range->XRange->Max;
            }
          }
        }
      }
      if(GetProfilesResponse.Profiles[i]->MetadataConfiguration){
        jsonArr["MetadataConfiguration"]["token"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->token;
        jsonArr["MetadataConfiguration"]["Name"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->Name;
        jsonArr["MetadataConfiguration"]["UseCount"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->UseCount;
        if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->CompressionType){
          jsonArr["MetadataConfiguration"]["CompressionType"] = *GetProfilesResponse.Profiles[i]->MetadataConfiguration->CompressionType;
        }
        if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->GeoLocation){
          jsonArr["MetadataConfiguration"]["GeoLocation"] = *GetProfilesResponse.Profiles[i]->MetadataConfiguration->GeoLocation;
        }
        if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->ShapePolygon){
          jsonArr["MetadataConfiguration"]["ShapePolygon"] = *GetProfilesResponse.Profiles[i]->MetadataConfiguration->ShapePolygon;
        }
        if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->PTZStatus){
          jsonArr["MetadataConfiguration"]["PTZStatus"]["Status"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->PTZStatus->Status;
          jsonArr["MetadataConfiguration"]["PTZStatus"]["Position"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->PTZStatus->Position;
        }
        if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->Analytics){
          jsonArr["MetadataConfiguration"]["Analytics"] = *GetProfilesResponse.Profiles[i]->MetadataConfiguration->Analytics;
        }
        if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast){
          if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->Address){
            switch (GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->Address->Type)
            {
            case tt__IPType__IPv4:
              jsonArr["MetadataConfiguration"]["Multicast"]["Address"]["Type"] = "IPv4";
              break;
            case tt__IPType__IPv6:
              jsonArr["MetadataConfiguration"]["Multicast"]["Address"]["Type"] = "IPv6";
              break;
            default:
              break;
            }
            if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->Address->IPv4Address){
              jsonArr["MetadataConfiguration"]["Multicast"]["Address"]["IPv4Address"] = *GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->Address->IPv4Address;
            }
            if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->Address->IPv6Address){
              jsonArr["MetadataConfiguration"]["Multicast"]["Address"]["IPv6Address"] = *GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->Address->IPv6Address;
            }
          }
          jsonArr["MetadataConfiguration"]["Multicast"]["Port"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->Port;
          jsonArr["MetadataConfiguration"]["Multicast"]["TTL"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->TTL;
          jsonArr["MetadataConfiguration"]["Multicast"]["AutoStart"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->Multicast->AutoStart;
        }
        jsonArr["MetadataConfiguration"]["SessionTimeout"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->SessionTimeout;
        if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration){
          for(size_t j = 0; j < GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule.size(); j++){
            Json::Value jsonArrAnalyticsModule;
            jsonArrAnalyticsModule["Name"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Name;
            jsonArrAnalyticsModule["Type"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Type;
            if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
              for(size_t k = 0; k < GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem.size(); k++){
                Json::Value jsonArrSimpleItem;
                jsonArrSimpleItem["Name"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Name;
                jsonArrSimpleItem["Value"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->SimpleItem[k].Value;
                jsonArrAnalyticsModule["Parameters"]["SimpleItem"].append(jsonArrSimpleItem);
              }
            }
            if(GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters){
              for(size_t k = 0; k < GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem.size(); k++){
                Json::Value jsonArrElementItem;
                jsonArrElementItem["Name"] = GetProfilesResponse.Profiles[i]->MetadataConfiguration->AnalyticsEngineConfiguration->AnalyticsModule[j]->Parameters->ElementItem[k].Name;
                jsonArrAnalyticsModule["Parameters"]["ElementItem"].append(jsonArrElementItem);
              }
            }
            jsonArr["MetadataConfiguration"]["AnalyticsEngineConfiguration"]["AnalyticsModule"].append(jsonArrAnalyticsModule);
          }
        }
      }
      dataJson["Profiles"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetSnapshotUri(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetSnapshotUri GetSnapshotUri;
  _trt__GetSnapshotUriResponse GetSnapshotUriResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetSnapshotUri.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetSnapshotUri.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }

  if(onvifApi.media_GetSnapshotUri(clientInfo, &GetSnapshotUri, GetSnapshotUriResponse)){
    Json::Value dataJson;
    dataJson["MediaUri"]["Uri"] = GetSnapshotUriResponse.MediaUri->Uri;
    dataJson["MediaUri"]["InvalidAfterConnect"] = GetSnapshotUriResponse.MediaUri->InvalidAfterConnect;
    dataJson["MediaUri"]["InvalidAfterReboot"] = GetSnapshotUriResponse.MediaUri->InvalidAfterReboot;
    dataJson["MediaUri"]["Timeout"] = GetSnapshotUriResponse.MediaUri->Timeout;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetStreamUri(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetStreamUri GetStreamUri;
  _trt__GetStreamUriResponse GetStreamUriResponse;
  GetStreamUri.StreamSetup = soap_new_tt__StreamSetup(onvifApi.soap);
  GetStreamUri.StreamSetup->Transport = soap_new_tt__Transport(onvifApi.soap);
  if(root_dataResponse["StreamSetup"].isNull() || root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetStreamUri.StreamSetup->Stream = tt__StreamType__RTP_Unicast;
      GetStreamUri.StreamSetup->Transport->Protocol = tt__TransportProtocol__RTSP;
      GetStreamUri.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    if(root_dataResponse["StreamSetup"]["Stream"].asString() == "RTP-Unicast"){
      GetStreamUri.StreamSetup->Stream = tt__StreamType__RTP_Unicast;
    }
    else if(root_dataResponse["StreamSetup"]["Stream"].asString() == "RTP-Multicast"){
      GetStreamUri.StreamSetup->Stream = tt__StreamType__RTP_Multicast;
    }
    if(root_dataResponse["StreamSetup"]["Transport"]["Protocol"].asString() == "UDP"){
      GetStreamUri.StreamSetup->Transport->Protocol = tt__TransportProtocol__UDP;
    }
    else if(root_dataResponse["StreamSetup"]["Transport"]["Protocol"].asString() == "TCP"){
      GetStreamUri.StreamSetup->Transport->Protocol = tt__TransportProtocol__TCP;
    }
    else if(root_dataResponse["StreamSetup"]["Transport"]["Protocol"].asString() == "RTSP"){
      GetStreamUri.StreamSetup->Transport->Protocol = tt__TransportProtocol__RTSP;
    }
    else if(root_dataResponse["StreamSetup"]["Transport"]["Protocol"].asString() == "HTTP"){
      GetStreamUri.StreamSetup->Transport->Protocol = tt__TransportProtocol__HTTP;
    }
    GetStreamUri.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }

  if(onvifApi.media_GetStreamUri(clientInfo, &GetStreamUri, GetStreamUriResponse)){
    Json::Value dataJson;
    dataJson["MediaUri"]["Uri"] = GetStreamUriResponse.MediaUri->Uri;
    dataJson["MediaUri"]["InvalidAfterConnect"] = GetStreamUriResponse.MediaUri->InvalidAfterConnect;
    dataJson["MediaUri"]["InvalidAfterReboot"] = GetStreamUriResponse.MediaUri->InvalidAfterReboot;
    dataJson["MediaUri"]["Timeout"] = GetStreamUriResponse.MediaUri->Timeout;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoAnalyticsConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoAnalyticsConfiguration GetVideoAnalyticsConfiguration;
  _trt__GetVideoAnalyticsConfigurationResponse GetVideoAnalyticsConfigurationResponse;
  if(onvifApi.media_GetVideoAnalyticsConfiguration(clientInfo, &GetVideoAnalyticsConfiguration, GetVideoAnalyticsConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoAnalyticsConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoAnalyticsConfigurations GetVideoAnalyticsConfigurations;
  _trt__GetVideoAnalyticsConfigurationsResponse GetVideoAnalyticsConfigurationsResponse;
  if(onvifApi.media_GetVideoAnalyticsConfigurations(clientInfo, &GetVideoAnalyticsConfigurations, GetVideoAnalyticsConfigurationsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoEncoderConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoEncoderConfiguration GetVideoEncoderConfiguration;
  _trt__GetVideoEncoderConfigurationResponse GetVideoEncoderConfigurationResponse;
  if(root_dataResponse["ConfigurationToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      if(GetProfilesResponse.Profiles.front()->VideoEncoderConfiguration){
        GetVideoEncoderConfiguration.ConfigurationToken = GetProfilesResponse.Profiles.front()->VideoEncoderConfiguration->token;
      }
    }
  }
  else{
    GetVideoEncoderConfiguration.ConfigurationToken = root_dataResponse["ConfigurationToken"].asString();
  }
  if(onvifApi.media_GetVideoEncoderConfiguration(clientInfo, &GetVideoEncoderConfiguration, GetVideoEncoderConfigurationResponse)){
    Json::Value dataJson;
    if(GetVideoEncoderConfigurationResponse.Configuration){
      dataJson["Configuration"]["token"] = GetVideoEncoderConfigurationResponse.Configuration->token;
      dataJson["Configuration"]["Name"] = GetVideoEncoderConfigurationResponse.Configuration->Name;
      dataJson["Configuration"]["UseCount"] = GetVideoEncoderConfigurationResponse.Configuration->UseCount;
      if(GetVideoEncoderConfigurationResponse.Configuration->GuaranteedFrameRate){
        dataJson["Configuration"]["GuaranteedFrameRate"] = *GetVideoEncoderConfigurationResponse.Configuration->GuaranteedFrameRate;
      }
      switch (GetVideoEncoderConfigurationResponse.Configuration->Encoding)
      {
      case tt__VideoEncoding__JPEG:
        dataJson["Configuration"]["Encoding"] = "JPEG";
        break;
      case tt__VideoEncoding__MPEG4:
        dataJson["Configuration"]["Encoding"] = "MPEG4";
        break;
      case tt__VideoEncoding__H264:
        dataJson["Configuration"]["Encoding"] = "H264";
        break;
      default:
        break;
      }
      if(GetVideoEncoderConfigurationResponse.Configuration->Resolution){
        dataJson["Configuration"]["Resolution"]["Width"] = GetVideoEncoderConfigurationResponse.Configuration->Resolution->Width;
        dataJson["Configuration"]["Resolution"]["Height"] = GetVideoEncoderConfigurationResponse.Configuration->Resolution->Height;
      }
      dataJson["Configuration"]["Quality"] = GetVideoEncoderConfigurationResponse.Configuration->Quality;
      if(GetVideoEncoderConfigurationResponse.Configuration->RateControl){
        dataJson["Configuration"]["RateControl"]["FrameRateLimit"] = GetVideoEncoderConfigurationResponse.Configuration->RateControl->FrameRateLimit;
        dataJson["Configuration"]["RateControl"]["EncodingInterval"] = GetVideoEncoderConfigurationResponse.Configuration->RateControl->EncodingInterval;
        dataJson["Configuration"]["RateControl"]["BitrateLimit"] = GetVideoEncoderConfigurationResponse.Configuration->RateControl->BitrateLimit;
      }
      if(GetVideoEncoderConfigurationResponse.Configuration->MPEG4){
        dataJson["Configuration"]["MPEG4"]["GovLength"] = GetVideoEncoderConfigurationResponse.Configuration->MPEG4->GovLength;
        switch (GetVideoEncoderConfigurationResponse.Configuration->MPEG4->Mpeg4Profile)
        {
        case tt__Mpeg4Profile__SP:
          dataJson["Configuration"]["MPEG4"]["Mpeg4Profile"] = "SP";
          break;
        case tt__Mpeg4Profile__ASP:
          dataJson["Configuration"]["MPEG4"]["Mpeg4Profile"] = "ASP";
          break;
        default:
          break;
        }
      }
      if(GetVideoEncoderConfigurationResponse.Configuration->H264){
        dataJson["Configuration"]["H264"]["GovLength"] = GetVideoEncoderConfigurationResponse.Configuration->H264->GovLength;
        switch (GetVideoEncoderConfigurationResponse.Configuration->H264->H264Profile)
        {
        case tt__H264Profile__Baseline:
          dataJson["Configuration"]["H264"]["H264Profile"] = "Baseline";
          break;
        case tt__H264Profile__Main:
          dataJson["Configuration"]["H264"]["H264Profile"] = "Main";
          break;
        case tt__H264Profile__Extended:
          dataJson["Configuration"]["H264"]["H264Profile"] = "Extended";
          break;
        case tt__H264Profile__High:
          dataJson["Configuration"]["H264"]["H264Profile"] = "High";
          break;
        default:
          break;
        }
      }
      if(GetVideoEncoderConfigurationResponse.Configuration->Multicast){
        if(GetVideoEncoderConfigurationResponse.Configuration->Multicast->Address){
          switch (GetVideoEncoderConfigurationResponse.Configuration->Multicast->Address->Type)
          {
          case tt__IPType__IPv4:
            dataJson["Configuration"]["Multicast"]["Address"]["Type"] = "IPv4";
            break;
          case tt__IPType__IPv6:
            dataJson["Configuration"]["Multicast"]["Address"]["Type"] = "IPv6";
            break;
          default:
            break;
          }
          if(GetVideoEncoderConfigurationResponse.Configuration->Multicast->Address->IPv4Address){
            dataJson["Configuration"]["Multicast"]["Address"]["IPv4Address"] = *GetVideoEncoderConfigurationResponse.Configuration->Multicast->Address->IPv4Address;
          }
          if(GetVideoEncoderConfigurationResponse.Configuration->Multicast->Address->IPv6Address){
            dataJson["Configuration"]["Multicast"]["Address"]["IPv6Address"] = *GetVideoEncoderConfigurationResponse.Configuration->Multicast->Address->IPv6Address;
          }
        }
        dataJson["Configuration"]["Multicast"]["Port"] = GetVideoEncoderConfigurationResponse.Configuration->Multicast->Port;
        dataJson["Configuration"]["Multicast"]["TTL"] = GetVideoEncoderConfigurationResponse.Configuration->Multicast->TTL;
        dataJson["Configuration"]["Multicast"]["AutoStart"] = GetVideoEncoderConfigurationResponse.Configuration->Multicast->AutoStart;
      }
      dataJson["Configuration"]["SessionTimeout"] = GetVideoEncoderConfigurationResponse.Configuration->SessionTimeout;
    }
    
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoEncoderConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoEncoderConfigurationOptions GetVideoEncoderConfigurationOptions;
  _trt__GetVideoEncoderConfigurationOptionsResponse GetVideoEncoderConfigurationOptionsResponse;
  if(root_dataResponse["ConfigurationToken"].isNull() || root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      if(GetProfilesResponse.Profiles.front()->VideoEncoderConfiguration){
        GetVideoEncoderConfigurationOptions.ConfigurationToken = &GetProfilesResponse.Profiles.front()->VideoEncoderConfiguration->token;
      }
      GetVideoEncoderConfigurationOptions.ProfileToken = &GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    std::string ConfigurationToken = root_dataResponse["ConfigurationToken"].asString();
    std::string ProfileToken = root_dataResponse["ProfileToken"].asString();
    GetVideoEncoderConfigurationOptions.ConfigurationToken = &ConfigurationToken;
    GetVideoEncoderConfigurationOptions.ProfileToken = &ProfileToken;
  }
  if(onvifApi.media_GetVideoEncoderConfigurationOptions(clientInfo, &GetVideoEncoderConfigurationOptions, GetVideoEncoderConfigurationOptionsResponse)){
    Json::Value dataJson;
    if(GetVideoEncoderConfigurationOptionsResponse.Options){
      if(GetVideoEncoderConfigurationOptionsResponse.Options->GuaranteedFrameRateSupported){
        dataJson["Options"]["GuaranteedFrameRateSupported"] = *GetVideoEncoderConfigurationOptionsResponse.Options->GuaranteedFrameRateSupported;
      }
      if(GetVideoEncoderConfigurationOptionsResponse.Options->QualityRange){
        dataJson["Options"]["QualityRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->QualityRange->Min;
        dataJson["Options"]["QualityRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->QualityRange->Max;
      }
      if(GetVideoEncoderConfigurationOptionsResponse.Options->JPEG){
        for(size_t i = 0; i < GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->ResolutionsAvailable.size(); i++){
          Json::Value jsonArr;
          jsonArr["Width"] = GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->ResolutionsAvailable[i]->Width;
          jsonArr["Height"] = GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->ResolutionsAvailable[i]->Height;
          dataJson["Options"]["JPEG"]["ResolutionsAvailable"].append(jsonArr);
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->FrameRateRange){
          dataJson["Options"]["JPEG"]["FrameRateRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->FrameRateRange->Min;
          dataJson["Options"]["JPEG"]["FrameRateRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->FrameRateRange->Max;
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->EncodingIntervalRange){
          dataJson["Options"]["JPEG"]["EncodingIntervalRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->EncodingIntervalRange->Min;
          dataJson["Options"]["JPEG"]["EncodingIntervalRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->JPEG->EncodingIntervalRange->Max;
        }
      }
      if(GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4){
        for(size_t i = 0; i < GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->ResolutionsAvailable.size(); i++){
          Json::Value jsonArr;
          jsonArr["Width"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->ResolutionsAvailable[i]->Width;
          jsonArr["Height"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->ResolutionsAvailable[i]->Height;
          dataJson["Options"]["MPEG4"]["ResolutionsAvailable"].append(jsonArr);
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->GovLengthRange){
          dataJson["Options"]["MPEG4"]["GovLengthRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->GovLengthRange->Min;
          dataJson["Options"]["MPEG4"]["GovLengthRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->GovLengthRange->Max;
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->FrameRateRange){
          dataJson["Options"]["MPEG4"]["FrameRateRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->FrameRateRange->Min;
          dataJson["Options"]["MPEG4"]["FrameRateRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->FrameRateRange->Max;
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->EncodingIntervalRange){
          dataJson["Options"]["MPEG4"]["EncodingIntervalRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->EncodingIntervalRange->Min;
          dataJson["Options"]["MPEG4"]["EncodingIntervalRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->EncodingIntervalRange->Max;
        }
        for(size_t j = 0; j < GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->Mpeg4ProfilesSupported.size(); j++){
          switch (GetVideoEncoderConfigurationOptionsResponse.Options->MPEG4->Mpeg4ProfilesSupported[j])
          {
          case tt__Mpeg4Profile__SP:
            dataJson["Options"]["MPEG4"]["Mpeg4ProfilesSupported"].append("SP");
            break;
          case tt__Mpeg4Profile__ASP:
            dataJson["Options"]["MPEG4"]["Mpeg4ProfilesSupported"].append("ASP");
            break;
          default:
            break;
          }
        }
        
      }
      if(GetVideoEncoderConfigurationOptionsResponse.Options->H264){
        for(size_t i = 0; i < GetVideoEncoderConfigurationOptionsResponse.Options->H264->ResolutionsAvailable.size(); i++){
          Json::Value jsonArr;
          jsonArr["Width"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->ResolutionsAvailable[i]->Width;
          jsonArr["Height"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->ResolutionsAvailable[i]->Height;
          dataJson["Options"]["H264"]["ResolutionsAvailable"].append(jsonArr);
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->H264->GovLengthRange){
          dataJson["Options"]["H264"]["GovLengthRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->GovLengthRange->Min;
          dataJson["Options"]["H264"]["GovLengthRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->GovLengthRange->Max;
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->H264->FrameRateRange){
          dataJson["Options"]["H264"]["FrameRateRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->FrameRateRange->Min;
          dataJson["Options"]["H264"]["FrameRateRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->FrameRateRange->Max;
        }
        if(GetVideoEncoderConfigurationOptionsResponse.Options->H264->EncodingIntervalRange){
          dataJson["Options"]["H264"]["EncodingIntervalRange"]["Min"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->EncodingIntervalRange->Min;
          dataJson["Options"]["H264"]["EncodingIntervalRange"]["Max"] = GetVideoEncoderConfigurationOptionsResponse.Options->H264->EncodingIntervalRange->Max;
        }
        for(size_t j = 0; j < GetVideoEncoderConfigurationOptionsResponse.Options->H264->H264ProfilesSupported.size(); j++){
          switch (GetVideoEncoderConfigurationOptionsResponse.Options->H264->H264ProfilesSupported[j])
          {
          case tt__H264Profile__Baseline:
            dataJson["Options"]["H264"]["H264ProfilesSupported"].append("Baseline");
            break;
          case tt__H264Profile__Main:
            dataJson["Options"]["H264"]["H264ProfilesSupported"].append("Main");
            break;
          case tt__H264Profile__Extended:
            dataJson["Options"]["H264"]["H264ProfilesSupported"].append("Extended");
            break;
          case tt__H264Profile__High:
            dataJson["Options"]["H264"]["H264ProfilesSupported"].append("High");
            break;
          default:
            break;
          }
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoEncoderConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoEncoderConfigurations GetVideoEncoderConfigurations;
  _trt__GetVideoEncoderConfigurationsResponse GetVideoEncoderConfigurationsResponse;
  if(onvifApi.media_GetVideoEncoderConfigurations(clientInfo, &GetVideoEncoderConfigurations, GetVideoEncoderConfigurationsResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetVideoEncoderConfigurationsResponse.Configurations.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->token;
      jsonArr["Name"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->Name;
      jsonArr["UseCount"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->UseCount;
      if(GetVideoEncoderConfigurationsResponse.Configurations[i]->GuaranteedFrameRate){
        jsonArr["GuaranteedFrameRate"] = *GetVideoEncoderConfigurationsResponse.Configurations[i]->GuaranteedFrameRate;
      }
      switch (GetVideoEncoderConfigurationsResponse.Configurations[i]->Encoding)
      {
      case tt__VideoEncoding__JPEG:
        jsonArr["Encoding"] = "JPEG";
        break;
      case tt__VideoEncoding__MPEG4:
        jsonArr["Encoding"] = "MPEG4";
      case tt__VideoEncoding__H264:
        jsonArr["Encoding"] = "H264";
      default:
        break;
      }
      if(GetVideoEncoderConfigurationsResponse.Configurations[i]->Resolution){
        jsonArr["Resolution"]["Width"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->Resolution->Width;
        jsonArr["Resolution"]["Height"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->Resolution->Height;
      }
      jsonArr["Quality"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->Quality;
      if(GetVideoEncoderConfigurationsResponse.Configurations[i]->RateControl){
        jsonArr["RateControl"]["FrameRateLimit"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->RateControl->FrameRateLimit;
        jsonArr["RateControl"]["EncodingInterval"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->RateControl->EncodingInterval;
        jsonArr["RateControl"]["BitrateLimit"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->RateControl->BitrateLimit;
      }
      if(GetVideoEncoderConfigurationsResponse.Configurations[i]->MPEG4){
        jsonArr["MPEG4"]["GovLength"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->MPEG4->GovLength;
        switch (GetVideoEncoderConfigurationsResponse.Configurations[i]->MPEG4->Mpeg4Profile)
        {
        case tt__Mpeg4Profile__SP:
          jsonArr["MPEG4"]["Mpeg4Profile"] = "SP";
          break;
        case tt__Mpeg4Profile__ASP:
          jsonArr["MPEG4"]["Mpeg4Profile"] = "ASP";
          break;
        default:
          break;
        }
      }
      if(GetVideoEncoderConfigurationsResponse.Configurations[i]->H264){
        jsonArr["H264"]["GovLength"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->H264->GovLength;
        switch (GetVideoEncoderConfigurationsResponse.Configurations[i]->H264->H264Profile)
        {
        case tt__H264Profile__Baseline:
          jsonArr["H264"]["H264Profile"] = "Baseline";
          break;
        case tt__H264Profile__Main:
          jsonArr["H264"]["H264Profile"] = "Main";
          break;
        case tt__H264Profile__Extended:
          jsonArr["H264"]["H264Profile"] = "Extended";
          break;
        case tt__H264Profile__High:
          jsonArr["H264"]["H264Profile"] = "High";
          break;
        default:
          break;
        }
      }
      if(GetVideoEncoderConfigurationsResponse.Configurations[i]->Multicast){
        if(GetVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address){
          switch (GetVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Address->Type)
          {
          case tt__IPType__IPv4:
            jsonArr["Multicast"]["Address"]["Type"] = "IPv4";
            break;
          case tt__IPType__IPv6:
            jsonArr["Multicast"]["Address"]["Type"] = "IPv6";
            break;
          default:
            break;
          }
        }
        jsonArr["Multicast"]["Port"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->Port;
        jsonArr["Multicast"]["TTL"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->TTL;
        jsonArr["Multicast"]["AutoStart"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->Multicast->AutoStart;
      }
      jsonArr["SessionTimeout"] = GetVideoEncoderConfigurationsResponse.Configurations[i]->SessionTimeout;
      dataJson["Configurations"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoSourceConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoSourceConfiguration GetVideoSourceConfiguration;
  _trt__GetVideoSourceConfigurationResponse GetVideoSourceConfigurationResponse;
  if(root_dataResponse["ConfigurationToken"].isNull()){
    _trt__GetVideoSourceConfigurations GetVideoSourceConfigurations;
    _trt__GetVideoSourceConfigurationsResponse GetVideoSourceConfigurationsResponse;
    if(onvifApi.media_GetVideoSourceConfigurations(clientInfo, &GetVideoSourceConfigurations, GetVideoSourceConfigurationsResponse)){
      GetVideoSourceConfiguration.ConfigurationToken = GetVideoSourceConfigurationsResponse.Configurations.front()->token;
    }
  }
  else{
    GetVideoSourceConfiguration.ConfigurationToken = root_dataResponse["ConfigurationToken"].asString();
  }
  if(onvifApi.media_GetVideoSourceConfiguration(clientInfo, &GetVideoSourceConfiguration, GetVideoSourceConfigurationResponse)){
    Json::Value dataJson;
    dataJson["Configurations"]["token"] = GetVideoSourceConfigurationResponse.Configuration->token;
    dataJson["Configurations"]["Name"] = GetVideoSourceConfigurationResponse.Configuration->Name;
    dataJson["Configurations"]["UseCount"] = GetVideoSourceConfigurationResponse.Configuration->UseCount;
    if(GetVideoSourceConfigurationResponse.Configuration->ViewMode){
      dataJson["Configurations"]["ViewMode"] = *GetVideoSourceConfigurationResponse.Configuration->ViewMode;
    }
    dataJson["Configurations"]["SourceToken"] = GetVideoSourceConfigurationResponse.Configuration->SourceToken;
    if(GetVideoSourceConfigurationResponse.Configuration->Bounds){
      dataJson["Configurations"]["Bounds"]["x"] = GetVideoSourceConfigurationResponse.Configuration->Bounds->x;
      dataJson["Configurations"]["Bounds"]["y"] = GetVideoSourceConfigurationResponse.Configuration->Bounds->y;
      dataJson["Configurations"]["Bounds"]["width"] = GetVideoSourceConfigurationResponse.Configuration->Bounds->width;
      dataJson["Configurations"]["Bounds"]["height"] = GetVideoSourceConfigurationResponse.Configuration->Bounds->height;
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoSourceConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoSourceConfigurationOptions GetVideoSourceConfigurationOptions;
  _trt__GetVideoSourceConfigurationOptionsResponse GetVideoSourceConfigurationOptionsResponse;
  if(root_dataResponse["ConfigurationToken"].isNull() || root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      if(GetProfilesResponse.Profiles.front()->VideoEncoderConfiguration){
        GetVideoSourceConfigurationOptions.ConfigurationToken = &GetProfilesResponse.Profiles.front()->VideoSourceConfiguration->token;
      }
      GetVideoSourceConfigurationOptions.ProfileToken = &GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    std::string ConfigurationToken = root_dataResponse["ConfigurationToken"].asString();
    std::string ProfileToken = root_dataResponse["ProfileToken"].asString();
    GetVideoSourceConfigurationOptions.ConfigurationToken = &ConfigurationToken;
    GetVideoSourceConfigurationOptions.ProfileToken = &ProfileToken;
  }
  if(onvifApi.media_GetVideoSourceConfigurationOptions(clientInfo, &GetVideoSourceConfigurationOptions, GetVideoSourceConfigurationOptionsResponse)){
    Json::Value dataJson;
    if(GetVideoSourceConfigurationOptionsResponse.Options){
      if(GetVideoSourceConfigurationOptionsResponse.Options->MaximumNumberOfProfiles){
        dataJson["Options"]["MaximumNumberOfProfiles"] = *GetVideoSourceConfigurationOptionsResponse.Options->MaximumNumberOfProfiles;
      }
      if(GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange){
        if(GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->XRange){
          dataJson["Options"]["BoundsRange"]["XRange"]["Min"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->XRange->Min;
          dataJson["Options"]["BoundsRange"]["XRange"]["Max"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->XRange->Max;
        }
        if(GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->YRange){
          dataJson["Options"]["BoundsRange"]["YRange"]["Min"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->YRange->Min;
          dataJson["Options"]["BoundsRange"]["YRange"]["Max"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->YRange->Max;
        }
        if(GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->WidthRange){
          dataJson["Options"]["BoundsRange"]["WidthRange"]["Min"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->WidthRange->Min;
          dataJson["Options"]["BoundsRange"]["WidthRange"]["Max"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->WidthRange->Max;
        }
        if(GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->HeightRange){
          dataJson["Options"]["BoundsRange"]["HeightRange"]["Min"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->HeightRange->Min;
          dataJson["Options"]["BoundsRange"]["HeightRange"]["Max"] = GetVideoSourceConfigurationOptionsResponse.Options->BoundsRange->HeightRange->Max;
        }
      }
    }
    for(size_t j = 0; j < GetVideoSourceConfigurationOptionsResponse.Options->VideoSourceTokensAvailable.size(); j++){
      dataJson["Options"]["VideoSourceTokensAvailable"].append(GetVideoSourceConfigurationOptionsResponse.Options->VideoSourceTokensAvailable[j]);
    }
    
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoSourceConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoSourceConfigurations GetVideoSourceConfigurations;
  _trt__GetVideoSourceConfigurationsResponse GetVideoSourceConfigurationsResponse;
  if(onvifApi.media_GetVideoSourceConfigurations(clientInfo, &GetVideoSourceConfigurations, GetVideoSourceConfigurationsResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetVideoSourceConfigurationsResponse.Configurations.size(); i ++){
      Json::Value jsonArr;
      jsonArr["token"] = GetVideoSourceConfigurationsResponse.Configurations[i]->token;
      jsonArr["Name"] = GetVideoSourceConfigurationsResponse.Configurations[i]->Name;
      jsonArr["UseCount"] = GetVideoSourceConfigurationsResponse.Configurations[i]->UseCount;
      if(GetVideoSourceConfigurationsResponse.Configurations[i]->ViewMode){
        jsonArr["ViewMode"] = *GetVideoSourceConfigurationsResponse.Configurations[i]->ViewMode;
      }
      jsonArr["SourceToken"] = GetVideoSourceConfigurationsResponse.Configurations[i]->SourceToken;
      if(GetVideoSourceConfigurationsResponse.Configurations[i]->Bounds){
        jsonArr["Bounds"]["x"] = GetVideoSourceConfigurationsResponse.Configurations[i]->Bounds->x;
        jsonArr["Bounds"]["y"] = GetVideoSourceConfigurationsResponse.Configurations[i]->Bounds->y;
        jsonArr["Bounds"]["width"] = GetVideoSourceConfigurationsResponse.Configurations[i]->Bounds->width;
        jsonArr["Bounds"]["height"] = GetVideoSourceConfigurationsResponse.Configurations[i]->Bounds->height;
      }
      dataJson["Configurations"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetVideoSources(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetVideoSources GetVideoSources;
  _trt__GetVideoSourcesResponse GetVideoSourcesResponse;
  if(onvifApi.media_GetVideoSources(clientInfo, &GetVideoSources, GetVideoSourcesResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetVideoSourcesResponse.VideoSources.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetVideoSourcesResponse.VideoSources[i]->token;
      jsonArr["Framerate"] = GetVideoSourcesResponse.VideoSources[i]->Framerate;
      if(GetVideoSourcesResponse.VideoSources[i]->Resolution){
        jsonArr["Resolution"]["Width"] = GetVideoSourcesResponse.VideoSources[i]->Resolution->Width;
        jsonArr["Resolution"]["Height"] = GetVideoSourcesResponse.VideoSources[i]->Resolution->Height;
      }
      if(GetVideoSourcesResponse.VideoSources[i]->Imaging){
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->BacklightCompensation){
          switch (GetVideoSourcesResponse.VideoSources[i]->Imaging->BacklightCompensation->Mode)
          {
          case tt__BacklightCompensationMode__OFF:
            jsonArr["Imaging"]["BacklightCompensation"]["Mode"] = "OFF";
            break;
          case tt__BacklightCompensationMode__ON:
            jsonArr["Imaging"]["BacklightCompensation"]["Mode"] = "ON";
            break;
          default:
            break;
          }
          jsonArr["Imaging"]["BacklightCompensation"]["Level"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->BacklightCompensation->Level;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Brightness){
          jsonArr["Imaging"]["Brightness"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->Brightness;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->ColorSaturation){
          jsonArr["Imaging"]["ColorSaturation"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->ColorSaturation;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Contrast){
          jsonArr["Imaging"]["Contrast"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->Contrast;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure){
          switch (GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Mode)
          {
          case tt__ExposureMode__AUTO:
            jsonArr["Imaging"]["Exposure"]["Mode"] = "AUTO";
            break;
          case tt__ExposureMode__MANUAL:
            jsonArr["Imaging"]["Exposure"]["Mode"] = "MANUAL";
            break;
          default:
            break;
          }
          switch (GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Priority)
          {
          case tt__ExposurePriority__LowNoise:
            jsonArr["Imaging"]["Exposure"]["Priority"] = "LowNoise";
            break;
          case tt__ExposurePriority__FrameRate:
            jsonArr["Imaging"]["Exposure"]["Priority"] = "FrameRate";
            break;
          default:
            break;
          }
          if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window){
            if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->bottom){
              jsonArr["Imaging"]["Exposure"]["Window"]["bottom"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->bottom;
            }
            if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->top){
              jsonArr["Imaging"]["Exposure"]["Window"]["top"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->top;
            }
            if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->right){
              jsonArr["Imaging"]["Exposure"]["Window"]["right"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->right;
            }
            if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->left){
              jsonArr["Imaging"]["Exposure"]["Window"]["left"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Window->left;
            }
          }
          jsonArr["Imaging"]["Exposure"]["MinExposureTime"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->MinExposureTime;
          jsonArr["Imaging"]["Exposure"]["MaxExposureTime"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->MaxExposureTime;
          jsonArr["Imaging"]["Exposure"]["MinGain"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->MinGain;
          jsonArr["Imaging"]["Exposure"]["MaxGain"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->MaxGain;
          jsonArr["Imaging"]["Exposure"]["MinIris"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->MinIris;
          jsonArr["Imaging"]["Exposure"]["MaxIris"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->MaxIris;
          jsonArr["Imaging"]["Exposure"]["ExposureTime"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->ExposureTime;
          jsonArr["Imaging"]["Exposure"]["Gain"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Gain;
          jsonArr["Imaging"]["Exposure"]["Iris"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Exposure->Iris;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Focus){
          switch (GetVideoSourcesResponse.VideoSources[i]->Imaging->Focus->AutoFocusMode)
          {
          case tt__AutoFocusMode__AUTO:
            jsonArr["Imaging"]["Focus"]["AutoFocusMode"] = "AUTO";
            break;
          case tt__AutoFocusMode__MANUAL:
            jsonArr["Imaging"]["Focus"]["AutoFocusMode"] = "MANUAL";
            break;
          default:
            break;
          }
          jsonArr["Imaging"]["Focus"]["DefaultSpeed"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Focus->DefaultSpeed;
          jsonArr["Imaging"]["Focus"]["NearLimit"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Focus->NearLimit;
          jsonArr["Imaging"]["Focus"]["FarLimit"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->Focus->FarLimit;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->IrCutFilter){
          switch (*GetVideoSourcesResponse.VideoSources[i]->Imaging->IrCutFilter)
          {
          case tt__IrCutFilterMode__AUTO:
            jsonArr["Imaging"]["IrCutFilterMode"] = "AUTO";
            break;
          case tt__IrCutFilterMode__ON:
            jsonArr["Imaging"]["IrCutFilterMode"] = "ON";
            break;
          case tt__IrCutFilterMode__OFF:
            jsonArr["Imaging"]["IrCutFilterMode"] = "OFF";
            break;
          default:
            break;
          }
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->Sharpness){
          jsonArr["Imaging"]["Sharpness"] = *GetVideoSourcesResponse.VideoSources[i]->Imaging->Sharpness;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->WideDynamicRange){
          switch (GetVideoSourcesResponse.VideoSources[i]->Imaging->WideDynamicRange->Mode)
          {
          case tt__WideDynamicMode__OFF:
            jsonArr["Imaging"]["WideDynamicRange"]["Mode"] = "OFF";
            break;
            case tt__WideDynamicMode__ON:
            jsonArr["Imaging"]["WideDynamicRange"]["Mode"] = "ON";
            break;
          default:
            break;
          }
          jsonArr["Imaging"]["WideDynamicRange"]["Level"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->WideDynamicRange->Level;
        }
        if(GetVideoSourcesResponse.VideoSources[i]->Imaging->WhiteBalance){
          switch (GetVideoSourcesResponse.VideoSources[i]->Imaging->WhiteBalance->Mode)
          {
          case tt__WhiteBalanceMode__AUTO:
            jsonArr["Imaging"]["WhiteBalance"]["Mode"] = "AUTO";
            break;
            case tt__WhiteBalanceMode__MANUAL:
            jsonArr["Imaging"]["WhiteBalance"]["Mode"] = "MANUAL";
            break;
          default:
            break;
          }
          jsonArr["Imaging"]["WhiteBalance"]["CrGain"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->WhiteBalance->CrGain;
          jsonArr["Imaging"]["WhiteBalance"]["CbGain"] = GetVideoSourcesResponse.VideoSources[i]->Imaging->WhiteBalance->CbGain;
        }
      }

      dataJson["VideoSources"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_SetMetadataConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__SetMetadataConfiguration SetMetadataConfiguration;
  _trt__SetMetadataConfigurationResponse SetMetadataConfigurationResponse;
  if(onvifApi.media_SetMetadataConfiguration(clientInfo, &SetMetadataConfiguration, SetMetadataConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_SetSynchronizationPoint(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__SetSynchronizationPoint SetSynchronizationPoint;
  _trt__SetSynchronizationPointResponse SetSynchronizationPointResponse;
  if(onvifApi.media_SetSynchronizationPoint(clientInfo, &SetSynchronizationPoint, SetSynchronizationPointResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_SetVideoAnalyticsConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__SetVideoAnalyticsConfiguration SetVideoAnalyticsConfiguration;
  _trt__SetVideoAnalyticsConfigurationResponse SetVideoAnalyticsConfigurationResponse;
  if(onvifApi.media_SetVideoAnalyticsConfiguration(clientInfo, &SetVideoAnalyticsConfiguration, SetVideoAnalyticsConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_SetVideoEncoderConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__SetVideoEncoderConfiguration SetVideoEncoderConfiguration;
  _trt__SetVideoEncoderConfigurationResponse SetVideoEncoderConfigurationResponse;
  if(onvifApi.media_SetVideoEncoderConfiguration(clientInfo, &SetVideoEncoderConfiguration, SetVideoEncoderConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_SetVideoSourceConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__SetVideoSourceConfiguration SetVideoSourceConfiguration;
  _trt__SetVideoSourceConfigurationResponse SetVideoSourceConfigurationResponse;
  if(onvifApi.media_SetVideoSourceConfiguration(clientInfo, &SetVideoSourceConfiguration, SetVideoSourceConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void media_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _trt__GetServiceCapabilities GetServiceCapabilities;
  _trt__GetServiceCapabilitiesResponse GetServiceCapabilitiesResponse;
  if(onvifApi.media_GetServiceCapabilities(clientInfo, &GetServiceCapabilities, GetServiceCapabilitiesResponse)){
    Json::Value dataJson;
    if(GetServiceCapabilitiesResponse.Capabilities){
      if(GetServiceCapabilitiesResponse.Capabilities->SnapshotUri){
        dataJson["Capabilities"]["SnapshotUri"] = *GetServiceCapabilitiesResponse.Capabilities->SnapshotUri;
      }
      if(GetServiceCapabilitiesResponse.Capabilities->Rotation){
        dataJson["Capabilities"]["Rotation"] = *GetServiceCapabilitiesResponse.Capabilities->Rotation;
      }
      if(GetServiceCapabilitiesResponse.Capabilities->VideoSourceMode){
        dataJson["Capabilities"]["VideoSourceMode"] = *GetServiceCapabilitiesResponse.Capabilities->VideoSourceMode;
      }
      if(GetServiceCapabilitiesResponse.Capabilities->OSD){
        dataJson["Capabilities"]["OSD"] = *GetServiceCapabilitiesResponse.Capabilities->OSD;
      }
      if(GetServiceCapabilitiesResponse.Capabilities->TemporaryOSDText){
        dataJson["Capabilities"]["TemporaryOSDText"] = *GetServiceCapabilitiesResponse.Capabilities->TemporaryOSDText;
      }
      if(GetServiceCapabilitiesResponse.Capabilities->EXICompression){
        dataJson["Capabilities"]["EXICompression"] = *GetServiceCapabilitiesResponse.Capabilities->EXICompression;
      }
      if(GetServiceCapabilitiesResponse.Capabilities->ProfileCapabilities){
        if(GetServiceCapabilitiesResponse.Capabilities->ProfileCapabilities->MaximumNumberOfProfiles){
          dataJson["Capabilities"]["ProfileCapabilities"]["MaximumNumberOfProfiles"] = *GetServiceCapabilitiesResponse.Capabilities->ProfileCapabilities->MaximumNumberOfProfiles;
        }
      }
      if(GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities){
        if(GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->RTPMulticast){
          dataJson["Capabilities"]["StreamingCapabilities"]["RTPMulticast"] = *GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->RTPMulticast;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->RTP_USCORETCP){
          dataJson["Capabilities"]["StreamingCapabilities"]["RTP_TCP"] = *GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->RTP_USCORETCP;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->RTP_USCORERTSP_USCORETCP){
          dataJson["Capabilities"]["StreamingCapabilities"]["RTP_RTSP_TCP"] = *GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->RTP_USCORERTSP_USCORETCP;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->NonAggregateControl){
          dataJson["Capabilities"]["StreamingCapabilities"]["NonAggregateControl"] = *GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->NonAggregateControl;
        }
        if(GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->NoRTSPStreaming){
          dataJson["Capabilities"]["StreamingCapabilities"]["NoRTSPStreaming"] = *GetServiceCapabilitiesResponse.Capabilities->StreamingCapabilities->NoRTSPStreaming;
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_GetImagingSettings(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__GetImagingSettings GetImagingSettings;
  _timg__GetImagingSettingsResponse GetImagingSettingsResponse;
  if(root_dataResponse["VideoSourceToken"].isNull()){
    _trt__GetVideoSources GetVideoSources;
    _trt__GetVideoSourcesResponse GetVideoSourcesResponse;
    if(onvifApi.media_GetVideoSources(clientInfo, &GetVideoSources, GetVideoSourcesResponse)){
      GetImagingSettings.VideoSourceToken = GetVideoSourcesResponse.VideoSources.front()->token;
    }
  }
  else{
    GetImagingSettings.VideoSourceToken = root_dataResponse["VideoSourceToken"].asString();
  }
  if(onvifApi.imaging_GetImagingSettings(clientInfo, &GetImagingSettings, GetImagingSettingsResponse)){
    Json::Value dataJson;
    if(GetImagingSettingsResponse.ImagingSettings){
      if(GetImagingSettingsResponse.ImagingSettings->BacklightCompensation){
        switch (GetImagingSettingsResponse.ImagingSettings->BacklightCompensation->Mode)
        {
        case tt__BacklightCompensationMode__OFF:
          dataJson["ImagingSettings"]["BacklightCompensation"]["Mode"] = "OFF";
          break;
        case tt__BacklightCompensationMode__ON:
          dataJson["ImagingSettings"]["BacklightCompensation"]["Mode"] = "ON";
          break;
        default:
          break;
        }
        if(GetImagingSettingsResponse.ImagingSettings->BacklightCompensation->Level){
          dataJson["ImagingSettings"]["BacklightCompensation"]["Level"] = *GetImagingSettingsResponse.ImagingSettings->BacklightCompensation->Level;
        }
      }
      if(GetImagingSettingsResponse.ImagingSettings->Brightness){
        dataJson["ImagingSettings"]["Brightness"] = *GetImagingSettingsResponse.ImagingSettings->Brightness;
      }
      if(GetImagingSettingsResponse.ImagingSettings->ColorSaturation){
        dataJson["ImagingSettings"]["ColorSaturation"] = *GetImagingSettingsResponse.ImagingSettings->ColorSaturation;
      }
      if(GetImagingSettingsResponse.ImagingSettings->Contrast){
        dataJson["ImagingSettings"]["Contrast"] = *GetImagingSettingsResponse.ImagingSettings->Contrast;
      }
      if(GetImagingSettingsResponse.ImagingSettings->Exposure){
        switch (GetImagingSettingsResponse.ImagingSettings->Exposure->Mode)
        {
        case tt__ExposureMode__AUTO:
          dataJson["ImagingSettings"]["Exposure"]["Mode"] = "AUTO";
          break;
        case tt__ExposureMode__MANUAL:
          dataJson["ImagingSettings"]["Exposure"]["Mode"] = "MANUAL";
          break;
        default:
          break;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->Priority){
          switch (*GetImagingSettingsResponse.ImagingSettings->Exposure->Priority)
          {
          case tt__ExposurePriority__LowNoise:
            dataJson["ImagingSettings"]["Exposure"]["Priority"] = "LowNoise";
            break;
          case tt__ExposurePriority__FrameRate:
            dataJson["ImagingSettings"]["Exposure"]["Priority"] = "FrameRate";
            break;
          default:
            break;
          }
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->Window){
          if(GetImagingSettingsResponse.ImagingSettings->Exposure->Window->bottom){
            dataJson["ImagingSettings"]["Exposure"]["Window"]["bottom"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->Window->bottom;
          }
          if(GetImagingSettingsResponse.ImagingSettings->Exposure->Window->top){
            dataJson["ImagingSettings"]["Exposure"]["Window"]["top"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->Window->top;
          }
          if(GetImagingSettingsResponse.ImagingSettings->Exposure->Window->right){
            dataJson["ImagingSettings"]["Exposure"]["Window"]["right"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->Window->right;
          }
          if(GetImagingSettingsResponse.ImagingSettings->Exposure->Window->left){
            dataJson["ImagingSettings"]["Exposure"]["Window"]["left"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->Window->left;
          }
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->MinExposureTime){
          dataJson["ImagingSettings"]["Exposure"]["MinExposureTime"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->MinExposureTime;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->MaxExposureTime){
          dataJson["ImagingSettings"]["Exposure"]["MaxExposureTime"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->MaxExposureTime;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->MinGain){
          dataJson["ImagingSettings"]["Exposure"]["MinGain"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->MinGain;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->MaxGain){
          dataJson["ImagingSettings"]["Exposure"]["MaxGain"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->MaxGain;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->MinIris){
          dataJson["ImagingSettings"]["Exposure"]["MinIris"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->MinIris;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->MaxIris){
          dataJson["ImagingSettings"]["Exposure"]["MaxIris"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->MaxIris;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->ExposureTime){
          dataJson["ImagingSettings"]["Exposure"]["ExposureTime"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->ExposureTime;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->Gain){
          dataJson["ImagingSettings"]["Exposure"]["Gain"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->Gain;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Exposure->Iris){
          dataJson["ImagingSettings"]["Exposure"]["Iris"] = *GetImagingSettingsResponse.ImagingSettings->Exposure->Iris;
        }
      }
      if(GetImagingSettingsResponse.ImagingSettings->Focus){
        switch (GetImagingSettingsResponse.ImagingSettings->Focus->AutoFocusMode)
        {
        case tt__AutoFocusMode__AUTO:
          dataJson["ImagingSettings"]["Focus"]["AutoFocusMode"] = "AUTO";
          break;
        case tt__AutoFocusMode__MANUAL:
          dataJson["ImagingSettings"]["Focus"]["AutoFocusMode"] = "MANUAL";
          break;
        default:
          break;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Focus->DefaultSpeed){
          dataJson["ImagingSettings"]["Focus"]["DefaultSpeed"] = *GetImagingSettingsResponse.ImagingSettings->Focus->DefaultSpeed;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Focus->NearLimit){
          dataJson["ImagingSettings"]["Focus"]["NearLimit"] = *GetImagingSettingsResponse.ImagingSettings->Focus->NearLimit;
        }
        if(GetImagingSettingsResponse.ImagingSettings->Focus->FarLimit){
          dataJson["ImagingSettings"]["Focus"]["FarLimit"] = *GetImagingSettingsResponse.ImagingSettings->Focus->FarLimit;
        }
      }
      if(GetImagingSettingsResponse.ImagingSettings->IrCutFilter){
        switch (*GetImagingSettingsResponse.ImagingSettings->IrCutFilter)
        {
        case tt__IrCutFilterMode__AUTO:
          dataJson["ImagingSettings"]["IrCutFilterMode"] = "AUTO";
          break;
        case tt__IrCutFilterMode__ON:
          dataJson["ImagingSettings"]["IrCutFilterMode"] = "ON";
          break;
        case tt__IrCutFilterMode__OFF:
          dataJson["ImagingSettings"]["IrCutFilterMode"] = "OFF";
          break;
        default:
          break;
        }
      }
      if(GetImagingSettingsResponse.ImagingSettings->Sharpness){
        dataJson["ImagingSettings"]["Sharpness"] = *GetImagingSettingsResponse.ImagingSettings->Sharpness;
      }
      if(GetImagingSettingsResponse.ImagingSettings->WideDynamicRange){
        switch (GetImagingSettingsResponse.ImagingSettings->WideDynamicRange->Mode)
        {
        case tt__WideDynamicMode__OFF:
          dataJson["ImagingSettings"]["WideDynamicRange"]["Mode"] = "OFF";
          break;
          case tt__WideDynamicMode__ON:
          dataJson["ImagingSettings"]["WideDynamicRange"]["Mode"] = "ON";
          break;
        default:
          break;
        }
        if(GetImagingSettingsResponse.ImagingSettings->WideDynamicRange->Level){
          dataJson["ImagingSettings"]["WideDynamicRange"]["Level"] = *GetImagingSettingsResponse.ImagingSettings->WideDynamicRange->Level;
        }
      }
      if(GetImagingSettingsResponse.ImagingSettings->WhiteBalance){
        switch (GetImagingSettingsResponse.ImagingSettings->WhiteBalance->Mode)
        {
        case tt__WhiteBalanceMode__AUTO:
          dataJson["ImagingSettings"]["WhiteBalance"]["Mode"] = "AUTO";
          break;
          case tt__WhiteBalanceMode__MANUAL:
          dataJson["ImagingSettings"]["WhiteBalance"]["Mode"] = "MANUAL";
          break;
        default:
          break;
        }
        if(GetImagingSettingsResponse.ImagingSettings->WhiteBalance->CrGain){
          dataJson["ImagingSettings"]["WhiteBalance"]["CrGain"] = *GetImagingSettingsResponse.ImagingSettings->WhiteBalance->CrGain;
        }
        if(GetImagingSettingsResponse.ImagingSettings->WhiteBalance->CbGain){
          dataJson["ImagingSettings"]["WhiteBalance"]["CbGain"] = *GetImagingSettingsResponse.ImagingSettings->WhiteBalance->CbGain;
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_GetMoveOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__GetMoveOptions GetMoveOptions;
  _timg__GetMoveOptionsResponse GetMoveOptionsResponse;
  if(onvifApi.imaging_GetMoveOptions(clientInfo, &GetMoveOptions, GetMoveOptionsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_GetOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__GetOptions GetOptions;
  _timg__GetOptionsResponse GetOptionsResponse;
  if(root_dataResponse["VideoSourceToken"].isNull()){
    _trt__GetVideoSources GetVideoSources;
    _trt__GetVideoSourcesResponse GetVideoSourcesResponse;
    if(onvifApi.media_GetVideoSources(clientInfo, &GetVideoSources, GetVideoSourcesResponse)){
      GetOptions.VideoSourceToken = GetVideoSourcesResponse.VideoSources.front()->token;
    }
  }
  else{
    GetOptions.VideoSourceToken = root_dataResponse["VideoSourceToken"].asString();
  }
  if(onvifApi.imaging_GetOptions(clientInfo, &GetOptions, GetOptionsResponse)){
    Json::Value dataJson;
    if(GetOptionsResponse.ImagingOptions){
      if(GetOptionsResponse.ImagingOptions->BacklightCompensation){
        for(size_t j = 0; j < GetOptionsResponse.ImagingOptions->BacklightCompensation->Mode.size(); j++){
          switch(GetOptionsResponse.ImagingOptions->BacklightCompensation->Mode[j]){
          case tt__BacklightCompensationMode__ON:
            dataJson["ImagingOptions"]["BacklightCompensation"]["Mode"].append("ON");
            break;
          case tt__BacklightCompensationMode__OFF:
            dataJson["ImagingOptions"]["BacklightCompensation"]["Mode"].append("OFF");
            break;
          default:
            break;
          }
        }
        if(GetOptionsResponse.ImagingOptions->BacklightCompensation->Level){
          dataJson["ImagingOptions"]["BacklightCompensation"]["Level"]["Min"] = GetOptionsResponse.ImagingOptions->BacklightCompensation->Level->Min;
          dataJson["ImagingOptions"]["BacklightCompensation"]["Level"]["Max"] = GetOptionsResponse.ImagingOptions->BacklightCompensation->Level->Max;
        }
      }
      if(GetOptionsResponse.ImagingOptions->Brightness){
        dataJson["ImagingOptions"]["Brightness"]["Min"] = GetOptionsResponse.ImagingOptions->Brightness->Min;
        dataJson["ImagingOptions"]["Brightness"]["Max"] = GetOptionsResponse.ImagingOptions->Brightness->Max;
      }
      if(GetOptionsResponse.ImagingOptions->ColorSaturation){
        dataJson["ImagingOptions"]["ColorSaturation"]["Min"] = GetOptionsResponse.ImagingOptions->ColorSaturation->Min;
        dataJson["ImagingOptions"]["ColorSaturation"]["Max"] = GetOptionsResponse.ImagingOptions->ColorSaturation->Max;
      }
      if(GetOptionsResponse.ImagingOptions->Contrast){
        dataJson["ImagingOptions"]["Contrast"]["Min"] = GetOptionsResponse.ImagingOptions->Contrast->Min;
        dataJson["ImagingOptions"]["Contrast"]["Max"] = GetOptionsResponse.ImagingOptions->Contrast->Max;
      }
      if(GetOptionsResponse.ImagingOptions->Exposure){
        for(size_t j = 0; j < GetOptionsResponse.ImagingOptions->Exposure->Mode.size(); j++){
          switch(GetOptionsResponse.ImagingOptions->Exposure->Mode[j]){
          case tt__ExposureMode__MANUAL:
            dataJson["ImagingOptions"]["Exposure"]["Mode"].append("MANUAL");
            break;
          case tt__ExposureMode__AUTO:
            dataJson["ImagingOptions"]["Exposure"]["Mode"].append("AUTO");
            break;
          default:
            break;
          }
        }
        for(size_t j = 0; j < GetOptionsResponse.ImagingOptions->Exposure->Priority.size(); j++){
          switch(GetOptionsResponse.ImagingOptions->Exposure->Priority[j]){
          case tt__ExposurePriority__LowNoise:
            dataJson["ImagingOptions"]["Exposure"]["Priority"].append("LowNoise");
            break;
          case tt__ExposurePriority__FrameRate:
            dataJson["ImagingOptions"]["Exposure"]["Priority"].append("FrameRate");
            break;
          default:
            break;
          }
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->MinExposureTime){
          dataJson["ImagingOptions"]["Exposure"]["MinExposureTime"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->MinExposureTime->Min;
          dataJson["ImagingOptions"]["Exposure"]["MinExposureTime"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->MinExposureTime->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->MaxExposureTime){
          dataJson["ImagingOptions"]["Exposure"]["MaxExposureTime"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->MaxExposureTime->Min;
          dataJson["ImagingOptions"]["Exposure"]["MaxExposureTime"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->MaxExposureTime->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->MinGain){
          dataJson["ImagingOptions"]["Exposure"]["MinGain"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->MinGain->Min;
          dataJson["ImagingOptions"]["Exposure"]["MinGain"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->MinGain->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->MaxGain){
          dataJson["ImagingOptions"]["Exposure"]["MaxGain"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->MaxGain->Min;
          dataJson["ImagingOptions"]["Exposure"]["MaxGain"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->MaxGain->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->MinIris){
          dataJson["ImagingOptions"]["Exposure"]["MinIris"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->MinIris->Min;
          dataJson["ImagingOptions"]["Exposure"]["MinIris"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->MinIris->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->MaxIris){
          dataJson["ImagingOptions"]["Exposure"]["MaxIris"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->MaxIris->Min;
          dataJson["ImagingOptions"]["Exposure"]["MaxIris"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->MaxIris->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->ExposureTime){
          dataJson["ImagingOptions"]["Exposure"]["ExposureTime"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->ExposureTime->Min;
          dataJson["ImagingOptions"]["Exposure"]["ExposureTime"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->ExposureTime->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->Gain){
          dataJson["ImagingOptions"]["Exposure"]["Gain"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->Gain->Min;
          dataJson["ImagingOptions"]["Exposure"]["Gain"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->Gain->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Exposure->Iris){
          dataJson["ImagingOptions"]["Exposure"]["Iris"]["Min"] = GetOptionsResponse.ImagingOptions->Exposure->Iris->Min;
          dataJson["ImagingOptions"]["Exposure"]["Iris"]["Max"] = GetOptionsResponse.ImagingOptions->Exposure->Iris->Max;
        }
      }
      if(GetOptionsResponse.ImagingOptions->Focus){
        for(size_t j = 0; j < GetOptionsResponse.ImagingOptions->Focus->AutoFocusModes.size(); j++){
          switch(GetOptionsResponse.ImagingOptions->Focus->AutoFocusModes[j]){
          case tt__AutoFocusMode__MANUAL:
            dataJson["ImagingOptions"]["Focus"]["Mode"].append("MANUAL");
            break;
          case tt__AutoFocusMode__AUTO:
            dataJson["ImagingOptions"]["Focus"]["Mode"].append("AUTO");
            break;
          default:
            break;
          }
        }
        if(GetOptionsResponse.ImagingOptions->Focus->DefaultSpeed){
          dataJson["ImagingOptions"]["Focus"]["DefaultSpeed"]["Min"] = GetOptionsResponse.ImagingOptions->Focus->DefaultSpeed->Min;
          dataJson["ImagingOptions"]["Focus"]["DefaultSpeed"]["Max"] = GetOptionsResponse.ImagingOptions->Focus->DefaultSpeed->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Focus->NearLimit){
          dataJson["ImagingOptions"]["Focus"]["NearLimit"]["Min"] = GetOptionsResponse.ImagingOptions->Focus->NearLimit->Min;
          dataJson["ImagingOptions"]["Focus"]["NearLimit"]["Max"] = GetOptionsResponse.ImagingOptions->Focus->NearLimit->Max;
        }
        if(GetOptionsResponse.ImagingOptions->Focus->FarLimit){
          dataJson["ImagingOptions"]["Focus"]["FarLimit"]["Min"] = GetOptionsResponse.ImagingOptions->Focus->FarLimit->Min;
          dataJson["ImagingOptions"]["Focus"]["FarLimit"]["Max"] = GetOptionsResponse.ImagingOptions->Focus->FarLimit->Max;
        }
      }
      for(size_t j = 0; j < GetOptionsResponse.ImagingOptions->IrCutFilterModes.size(); j++){
        switch(GetOptionsResponse.ImagingOptions->IrCutFilterModes[j]){
        case tt__IrCutFilterMode__ON:
          dataJson["ImagingOptions"]["IrCutFilterModes"].append("ON");
          break;
        case tt__IrCutFilterMode__OFF:
          dataJson["ImagingOptions"]["IrCutFilterModes"].append("OFF");
          break;
        case tt__IrCutFilterMode__AUTO:
          dataJson["ImagingOptions"]["IrCutFilterModes"].append("AUTO");
          break;
        default:
          break;
        }
      }
      if(GetOptionsResponse.ImagingOptions->Sharpness){
        dataJson["ImagingOptions"]["Sharpness"]["Min"] = GetOptionsResponse.ImagingOptions->Sharpness->Min;
        dataJson["ImagingOptions"]["Sharpness"]["Max"] = GetOptionsResponse.ImagingOptions->Sharpness->Max;
      }
      if(GetOptionsResponse.ImagingOptions->WideDynamicRange){
        for(size_t j = 0; j < GetOptionsResponse.ImagingOptions->WideDynamicRange->Mode.size(); j++){
          switch(GetOptionsResponse.ImagingOptions->WideDynamicRange->Mode[j]){
          case tt__WideDynamicMode__OFF:
            dataJson["ImagingOptions"]["WideDynamicRange"]["Mode"].append("OFF");
            break;
          case tt__WideDynamicMode__ON:
            dataJson["ImagingOptions"]["WideDynamicRange"]["Mode"].append("ON");
            break;
          default:
            break;
          }
        }
        if(GetOptionsResponse.ImagingOptions->WideDynamicRange->Level){
          dataJson["ImagingOptions"]["WideDynamicRange"]["Level"]["Min"] = GetOptionsResponse.ImagingOptions->WideDynamicRange->Level->Min;
          dataJson["ImagingOptions"]["WideDynamicRange"]["Level"]["Max"] = GetOptionsResponse.ImagingOptions->WideDynamicRange->Level->Max;
        }
      }
      if(GetOptionsResponse.ImagingOptions->WhiteBalance){
        for(size_t j = 0; j < GetOptionsResponse.ImagingOptions->WhiteBalance->Mode.size(); j++){
          switch(GetOptionsResponse.ImagingOptions->WhiteBalance->Mode[j]){
          case tt__WhiteBalanceMode__AUTO:
            dataJson["ImagingOptions"]["WhiteBalance"]["Mode"].append("AUTO");
            break;
          case tt__WhiteBalanceMode__MANUAL:
            dataJson["ImagingOptions"]["WhiteBalance"]["Mode"].append("MANUAL");
            break;
          default:
            break;
          }
        }
        if(GetOptionsResponse.ImagingOptions->WhiteBalance->YrGain){
          dataJson["ImagingOptions"]["WhiteBalance"]["YrGain"]["Min"] = GetOptionsResponse.ImagingOptions->WhiteBalance->YrGain->Min;
          dataJson["ImagingOptions"]["WhiteBalance"]["YrGain"]["Max"] = GetOptionsResponse.ImagingOptions->WhiteBalance->YrGain->Max;
        }
        if(GetOptionsResponse.ImagingOptions->WhiteBalance->YbGain){
          dataJson["ImagingOptions"]["WhiteBalance"]["YbGain"]["Min"] = GetOptionsResponse.ImagingOptions->WhiteBalance->YbGain->Min;
          dataJson["ImagingOptions"]["WhiteBalance"]["YbGain"]["Max"] = GetOptionsResponse.ImagingOptions->WhiteBalance->YbGain->Max;
        }
      }
      
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_GetStatus(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__GetStatus GetStatus;
  _timg__GetStatusResponse GetStatusResponse;
  if(root_dataResponse["VideoSourceToken"].isNull()){
    _trt__GetVideoSources GetVideoSources;
    _trt__GetVideoSourcesResponse GetVideoSourcesResponse;
    if(onvifApi.media_GetVideoSources(clientInfo, &GetVideoSources, GetVideoSourcesResponse)){
      GetStatus.VideoSourceToken = GetVideoSourcesResponse.VideoSources.front()->token;
    }
  }
  else{
    GetStatus.VideoSourceToken = root_dataResponse["VideoSourceToken"].asString();
  }
  if(onvifApi.imaging_GetStatus(clientInfo, &GetStatus, GetStatusResponse)){
    Json::Value dataJson;
    if(GetStatusResponse.Status){
      if(GetStatusResponse.Status->FocusStatus20){
        dataJson["Status"]["FocusStatus20"]["Position"] = GetStatusResponse.Status->FocusStatus20->Position;
        dataJson["Status"]["FocusStatus20"]["Position"] = GetStatusResponse.Status->FocusStatus20->Position;
        if(GetStatusResponse.Status->FocusStatus20->Error){
          dataJson["Status"]["FocusStatus20"]["Error"] = *GetStatusResponse.Status->FocusStatus20->Error;
        }
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_Move(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__Move Move;
  _timg__MoveResponse MoveResponse;
  if(onvifApi.imaging_Move(clientInfo, &Move, MoveResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_SetImagingSettings(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__SetImagingSettings SetImagingSettings;
  _timg__SetImagingSettingsResponse SetImagingSettingsResponse;
  if(onvifApi.imaging_SetImagingSettings(clientInfo, &SetImagingSettings, SetImagingSettingsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_Stop(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__Stop Stop;
  _timg__StopResponse StopResponse;
  if(onvifApi.imaging_Stop(clientInfo, &Stop, StopResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void imaging_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _timg__GetServiceCapabilities GetServiceCapabilities;
  _timg__GetServiceCapabilitiesResponse GetServiceCapabilitiesResponse;
  if(onvifApi.imaging_GetServiceCapabilities(clientInfo, &GetServiceCapabilities, GetServiceCapabilitiesResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_AbsoluteMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__AbsoluteMove AbsoluteMove;
  _tptz__AbsoluteMoveResponse AbsoluteMoveResponse;
  float PanTiltLimitsXMin = 0;
  float PanTiltLimitsXMax = 0;
  float PanTiltLimitsYMin = 0;
  float PanTiltLimitsYMax = 0;
  float ZoomLimitsXMin = 0;
  float ZoomLimitsXMax = 0;
  _tptz__GetNodes GetNodes;
  _tptz__GetNodesResponse GetNodesResponse;
  _tptz__GetConfigurations GetConfigurations;
  _tptz__GetConfigurationsResponse GetConfigurationsResponse;
  if(onvifApi.ptz_GetConfigurations(clientInfo, &GetConfigurations, GetConfigurationsResponse)){
    PanTiltLimitsXMin = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->XRange->Min;
    PanTiltLimitsXMax = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->XRange->Max;
    PanTiltLimitsYMin = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->YRange->Min;
    PanTiltLimitsYMax = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->YRange->Max;
    ZoomLimitsXMin = GetConfigurationsResponse.PTZConfiguration.front()->ZoomLimits->Range->XRange->Min;
    ZoomLimitsXMax = GetConfigurationsResponse.PTZConfiguration.front()->ZoomLimits->Range->XRange->Max;
  }
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      AbsoluteMove.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    AbsoluteMove.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(root_dataResponse["Position"].isNull()){
    res.set_content("{\"status\":\"Error no have field: Position\"}", "text/plain");
    return;
  }
  else{
    AbsoluteMove.Position = soap_new_tt__PTZVector(onvifApi.soap);
    AbsoluteMove.Position->PanTilt = soap_new_tt__Vector2D(onvifApi.soap);
    AbsoluteMove.Position->Zoom = soap_new_tt__Vector1D(onvifApi.soap);
    float PanTiltX = root_dataResponse["Position"]["PanTilt"]["x"].asFloat();
    float PanTiltY = root_dataResponse["Position"]["PanTilt"]["y"].asFloat();
    float ZoomX = root_dataResponse["Position"]["Zoom"]["x"].asFloat();
    if(PanTiltX >= 0){
      PanTiltX = PanTiltLimitsXMax*PanTiltX/MOVE_CALIB;
    }else{
      PanTiltX = -PanTiltLimitsXMin*PanTiltX/MOVE_CALIB;
    }
    if(PanTiltY >= 0){
      PanTiltY = PanTiltLimitsYMax*PanTiltY/MOVE_CALIB;
    }else{
      PanTiltY = -PanTiltLimitsYMin*PanTiltY/MOVE_CALIB;
    }
    if(ZoomX >= 0){
      ZoomX = ZoomLimitsXMax*ZoomX/MOVE_CALIB;
    }else{
      ZoomX = -ZoomLimitsXMin*ZoomX/MOVE_CALIB;
    }
    AbsoluteMove.Position->PanTilt->x = PanTiltX;
    AbsoluteMove.Position->PanTilt->y = PanTiltY;
    AbsoluteMove.Position->Zoom->x = ZoomX;
    std::cout << "Position PanTilt X: " << AbsoluteMove.Position->PanTilt->x << std::endl;
    std::cout << "Position PanTilt Y: " << AbsoluteMove.Position->PanTilt->y << std::endl;
    std::cout << "Position Zoom X: " << AbsoluteMove.Position->Zoom->x << std::endl;
  }
  if(!root_dataResponse["Speed"].isNull()){
    AbsoluteMove.Speed = soap_new_tt__PTZSpeed(onvifApi.soap);
    AbsoluteMove.Speed->PanTilt = soap_new_tt__Vector2D(onvifApi.soap);
    AbsoluteMove.Speed->Zoom = soap_new_tt__Vector1D(onvifApi.soap);
    float PanTiltX = root_dataResponse["Speed"]["PanTilt"]["x"].asFloat();
    float PanTiltY = root_dataResponse["Speed"]["PanTilt"]["y"].asFloat();
    float ZoomX = root_dataResponse["Speed"]["Zoom"]["x"].asFloat();
    if(PanTiltX >= 0){
      PanTiltX = PanTiltLimitsXMax*PanTiltX/MOVE_CALIB;
    }else{
      PanTiltX = -PanTiltLimitsXMin*PanTiltX/MOVE_CALIB;
    }
    if(PanTiltY >= 0){
      PanTiltY = PanTiltLimitsYMax*PanTiltY/MOVE_CALIB;
    }else{
      PanTiltY = -PanTiltLimitsYMin*PanTiltY/MOVE_CALIB;
    }
    if(ZoomX >= 0){
      ZoomX = ZoomLimitsXMax*ZoomX/MOVE_CALIB;
    }else{
      ZoomX = -ZoomLimitsXMin*ZoomX/MOVE_CALIB;
    }
    AbsoluteMove.Speed->PanTilt->x = PanTiltX;
    AbsoluteMove.Speed->PanTilt->y = PanTiltY;
    AbsoluteMove.Speed->Zoom->x = ZoomX;
    std::cout << "Speed PanTilt X: " << AbsoluteMove.Speed->PanTilt->x << std::endl;
    std::cout << "Speed PanTilt Y: " << AbsoluteMove.Speed->PanTilt->y << std::endl;
    std::cout << "Speed Zoom X: " << AbsoluteMove.Speed->Zoom->x << std::endl;
  }
  if(onvifApi.ptz_AbsoluteMove(clientInfo, &AbsoluteMove, AbsoluteMoveResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_ContinuousMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__ContinuousMove ContinuousMove;
  _tptz__ContinuousMoveResponse ContinuousMoveResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      ContinuousMove.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    ContinuousMove.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(!root_dataResponse["Velocity"].isNull()){
    ContinuousMove.Velocity = soap_new_tt__PTZSpeed(onvifApi.soap);
    ContinuousMove.Velocity->PanTilt = soap_new_tt__Vector2D(onvifApi.soap);
    ContinuousMove.Velocity->Zoom = soap_new_tt__Vector1D(onvifApi.soap);
    _tptz__GetConfigurations GetConfigurations;
    _tptz__GetConfigurationsResponse GetConfigurationsResponse;
    if(onvifApi.ptz_GetConfigurations(clientInfo, &GetConfigurations, GetConfigurationsResponse)){
      float PanTiltX = root_dataResponse["Velocity"]["PanTilt"]["x"].asFloat();
      float PanTiltY = root_dataResponse["Velocity"]["PanTilt"]["y"].asFloat();
      float ZoomX = root_dataResponse["Velocity"]["Zoom"]["x"].asFloat();
      if(PanTiltX >= 0){
        PanTiltX = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->XRange->Max*PanTiltX/MOVE_CALIB;
      }else{
        PanTiltX = -GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->XRange->Min*PanTiltX/MOVE_CALIB;
      }
      if(PanTiltY >= 0){
        PanTiltY = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->YRange->Max*PanTiltY/MOVE_CALIB;
      }else{
        PanTiltY = -GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->YRange->Min*PanTiltY/MOVE_CALIB;
      }
      if(ZoomX >= 0){
        ZoomX = GetConfigurationsResponse.PTZConfiguration.front()->ZoomLimits->Range->XRange->Max*ZoomX/MOVE_CALIB;
      }else{
        ZoomX = -GetConfigurationsResponse.PTZConfiguration.front()->ZoomLimits->Range->XRange->Min*ZoomX/MOVE_CALIB;
      }
      ContinuousMove.Velocity->PanTilt->x = PanTiltX;
      ContinuousMove.Velocity->PanTilt->y = PanTiltY;
      ContinuousMove.Velocity->Zoom->x = ZoomX;
    }
    else{
      ContinuousMove.Velocity->PanTilt->x = root_dataResponse["Velocity"]["PanTilt"]["x"].asFloat();
      ContinuousMove.Velocity->PanTilt->y = root_dataResponse["Velocity"]["PanTilt"]["y"].asFloat();
      ContinuousMove.Velocity->Zoom->x = root_dataResponse["Velocity"]["Zoom"]["x"].asFloat();
    }
    // std::cout << "PanTilt X: " << ContinuousMove.Velocity->PanTilt->x << std::endl;
    // std::cout << "PanTilt Y: " << ContinuousMove.Velocity->PanTilt->y << std::endl;
    // std::cout << "Zoom X: " << ContinuousMove.Velocity->Zoom->x << std::endl;
  }
  else{
    res.set_content("{\"status\":\"Error, dont have field: Velocity\"}", "text/plain");
    return;
  }
  if(onvifApi.ptz_ContinuousMove(clientInfo, &ContinuousMove, ContinuousMoveResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetConfiguration GetConfiguration;
  _tptz__GetConfigurationResponse GetConfigurationResponse;
  if(onvifApi.ptz_GetConfiguration(clientInfo, &GetConfiguration, GetConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetConfigurationOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetConfigurationOptions GetConfigurationOptions;
  _tptz__GetConfigurationOptionsResponse GetConfigurationOptionsResponse;
  if(onvifApi.ptz_GetConfigurationOptions(clientInfo, &GetConfigurationOptions, GetConfigurationOptionsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetConfigurations(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetConfigurations GetConfigurations;
  _tptz__GetConfigurationsResponse GetConfigurationsResponse;
  if(onvifApi.ptz_GetConfigurations(clientInfo, &GetConfigurations, GetConfigurationsResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetConfigurationsResponse.PTZConfiguration.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetConfigurationsResponse.PTZConfiguration[i]->token;
      jsonArr["Name"] = GetConfigurationsResponse.PTZConfiguration[i]->Name;
      jsonArr["UseCount"] = GetConfigurationsResponse.PTZConfiguration[i]->UseCount;
      if(GetConfigurationsResponse.PTZConfiguration[i]->MoveRamp){
        jsonArr["MoveRamp"] = *GetConfigurationsResponse.PTZConfiguration[i]->MoveRamp;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->PresetRamp){
        jsonArr["PresetRamp"] = *GetConfigurationsResponse.PTZConfiguration[i]->PresetRamp;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->PresetTourRamp){
        jsonArr["PresetTourRamp"] = *GetConfigurationsResponse.PTZConfiguration[i]->PresetTourRamp;
      }
      jsonArr["NodeToken"] = GetConfigurationsResponse.PTZConfiguration[i]->NodeToken;
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultAbsolutePantTiltPositionSpace){
        jsonArr["DefaultAbsolutePantTiltPositionSpace"] = *GetConfigurationsResponse.PTZConfiguration[i]->DefaultAbsolutePantTiltPositionSpace;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultAbsoluteZoomPositionSpace){
        jsonArr["DefaultAbsoluteZoomPositionSpace"] = *GetConfigurationsResponse.PTZConfiguration[i]->DefaultAbsoluteZoomPositionSpace;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultRelativePanTiltTranslationSpace){
        jsonArr["DefaultRelativePanTiltTranslationSpace"] = *GetConfigurationsResponse.PTZConfiguration[i]->DefaultRelativePanTiltTranslationSpace;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultRelativeZoomTranslationSpace){
        jsonArr["DefaultRelativeZoomTranslationSpace"] = *GetConfigurationsResponse.PTZConfiguration[i]->DefaultRelativeZoomTranslationSpace;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultContinuousPanTiltVelocitySpace){
        jsonArr["DefaultContinuousPanTiltVelocitySpace"] = *GetConfigurationsResponse.PTZConfiguration[i]->DefaultContinuousPanTiltVelocitySpace;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultContinuousZoomVelocitySpace){
        jsonArr["DefaultContinuousZoomVelocitySpace"] = *GetConfigurationsResponse.PTZConfiguration[i]->DefaultContinuousZoomVelocitySpace;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZSpeed){
        if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZSpeed->PanTilt){
          jsonArr["DefaultPTZSpeed"]["PanTilt"]["x"] = GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZSpeed->PanTilt->x;
          jsonArr["DefaultPTZSpeed"]["PanTilt"]["y"] = GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZSpeed->PanTilt->y;
        }
        if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZSpeed->Zoom){
          jsonArr["DefaultPTZSpeed"]["Zoom"]["x"] = GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZSpeed->Zoom->x;
        }
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZTimeout){
        jsonArr["DefaultPTZTimeout"] = *GetConfigurationsResponse.PTZConfiguration[i]->DefaultPTZTimeout;
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits){
        if(GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range){
          jsonArr["PanTiltLimits"]["Range"]["URI"] = GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range->URI;
          if(GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range->XRange){
            jsonArr["PanTiltLimits"]["Range"]["XRange"]["Min"] = GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range->XRange->Min;
            jsonArr["PanTiltLimits"]["Range"]["XRange"]["Max"] = GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range->XRange->Max;
          }
          if(GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range->YRange){
            jsonArr["PanTiltLimits"]["Range"]["YRange"]["Min"] = GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range->YRange->Min;
            jsonArr["PanTiltLimits"]["Range"]["YRange"]["Max"] = GetConfigurationsResponse.PTZConfiguration[i]->PanTiltLimits->Range->YRange->Max;
          }
        }
      }
      if(GetConfigurationsResponse.PTZConfiguration[i]->ZoomLimits){
        if(GetConfigurationsResponse.PTZConfiguration[i]->ZoomLimits->Range){
          jsonArr["ZoomLimits"]["Range"]["URI"] = GetConfigurationsResponse.PTZConfiguration[i]->ZoomLimits->Range->URI;
          if(GetConfigurationsResponse.PTZConfiguration[i]->ZoomLimits->Range->XRange){
            jsonArr["ZoomLimits"]["Range"]["XRange"]["Min"] = GetConfigurationsResponse.PTZConfiguration[i]->ZoomLimits->Range->XRange->Min;
            jsonArr["ZoomLimits"]["Range"]["XRange"]["Max"] = GetConfigurationsResponse.PTZConfiguration[i]->ZoomLimits->Range->XRange->Max;
          }
        }
      }
      dataJson["PTZConfiguration"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetNode(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetNode GetNode;
  _tptz__GetNodeResponse GetNodeResponse;
  if(onvifApi.ptz_GetNode(clientInfo, &GetNode, GetNodeResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetNodes(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetNodes GetNodes;
  _tptz__GetNodesResponse GetNodesResponse;
  if(onvifApi.ptz_GetNodes(clientInfo, &GetNodes, GetNodesResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetNodesResponse.PTZNode.size(); i++){
      Json::Value jsonArr;
      jsonArr["token"] = GetNodesResponse.PTZNode[i]->token;
      if(GetNodesResponse.PTZNode[i]->FixedHomePosition){
        jsonArr["FixedHomePosition"] = *GetNodesResponse.PTZNode[i]->FixedHomePosition;
      }
      if(GetNodesResponse.PTZNode[i]->GeoMove){
        jsonArr["GeoMove"] = *GetNodesResponse.PTZNode[i]->GeoMove;
      }
      if(GetNodesResponse.PTZNode[i]->Name){
        jsonArr["Name"] = *GetNodesResponse.PTZNode[i]->Name;
      }
      if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces){
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace.size(); j++){
          Json::Value jsonArrAbsolutePanTiltPositionSpace;
          jsonArrAbsolutePanTiltPositionSpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[j]->XRange){
            jsonArrAbsolutePanTiltPositionSpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[j]->XRange->Min;
            jsonArrAbsolutePanTiltPositionSpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[j]->XRange->Max;
          }
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[j]->YRange){
            jsonArrAbsolutePanTiltPositionSpace["YRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[j]->YRange->Min;
            jsonArrAbsolutePanTiltPositionSpace["YRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsolutePanTiltPositionSpace[j]->YRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["AbsolutePanTiltPositionSpace"].append(jsonArrAbsolutePanTiltPositionSpace);
        }
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsoluteZoomPositionSpace.size(); j++){
          Json::Value jsonArrAbsoluteZoomPositionSpace;
          jsonArrAbsoluteZoomPositionSpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsoluteZoomPositionSpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsoluteZoomPositionSpace[j]->XRange){
            jsonArrAbsoluteZoomPositionSpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsoluteZoomPositionSpace[j]->XRange->Min;
            jsonArrAbsoluteZoomPositionSpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->AbsoluteZoomPositionSpace[j]->XRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["AbsoluteZoomPositionSpace"].append(jsonArrAbsoluteZoomPositionSpace);
        }
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace.size(); j++){
          Json::Value jsonArrRelativePanTiltTranslationSpace;
          jsonArrRelativePanTiltTranslationSpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace[j]->XRange){
            jsonArrRelativePanTiltTranslationSpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace[j]->XRange->Min;
            jsonArrRelativePanTiltTranslationSpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace[j]->XRange->Max;
          }
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace[j]->YRange){
            jsonArrRelativePanTiltTranslationSpace["YRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace[j]->YRange->Min;
            jsonArrRelativePanTiltTranslationSpace["YRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativePanTiltTranslationSpace[j]->YRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["RelativePanTiltTranslationSpace"].append(jsonArrRelativePanTiltTranslationSpace);
        }
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativeZoomTranslationSpace.size(); j++){
          Json::Value jsonArrRelativeZoomTranslationSpace;
          jsonArrRelativeZoomTranslationSpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativeZoomTranslationSpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativeZoomTranslationSpace[j]->XRange){
            jsonArrRelativeZoomTranslationSpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativeZoomTranslationSpace[j]->XRange->Min;
            jsonArrRelativeZoomTranslationSpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->RelativeZoomTranslationSpace[j]->XRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["RelativeZoomTranslationSpace"].append(jsonArrRelativeZoomTranslationSpace);
        }
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace.size(); j++){
          Json::Value jsonArrContinuousPanTiltVelocitySpace;
          jsonArrContinuousPanTiltVelocitySpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace[j]->XRange){
            jsonArrContinuousPanTiltVelocitySpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace[j]->XRange->Min;
            jsonArrContinuousPanTiltVelocitySpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace[j]->XRange->Max;
          }
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace[j]->YRange){
            jsonArrContinuousPanTiltVelocitySpace["YRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace[j]->YRange->Min;
            jsonArrContinuousPanTiltVelocitySpace["YRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousPanTiltVelocitySpace[j]->YRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["ContinuousPanTiltVelocitySpace"].append(jsonArrContinuousPanTiltVelocitySpace);
        }
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousZoomVelocitySpace.size(); j++){
          Json::Value jsonArrContinuousZoomVelocitySpace;
          jsonArrContinuousZoomVelocitySpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousZoomVelocitySpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousZoomVelocitySpace[j]->XRange){
            jsonArrContinuousZoomVelocitySpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousZoomVelocitySpace[j]->XRange->Min;
            jsonArrContinuousZoomVelocitySpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ContinuousZoomVelocitySpace[j]->XRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["ContinuousZoomVelocitySpace"].append(jsonArrContinuousZoomVelocitySpace);
        }
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->PanTiltSpeedSpace.size(); j++){
          Json::Value jsonArrPanTiltSpeedSpace;
          jsonArrPanTiltSpeedSpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->PanTiltSpeedSpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->PanTiltSpeedSpace[j]->XRange){
            jsonArrPanTiltSpeedSpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->PanTiltSpeedSpace[j]->XRange->Min;
            jsonArrPanTiltSpeedSpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->PanTiltSpeedSpace[j]->XRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["PanTiltSpeedSpace"].append(jsonArrPanTiltSpeedSpace);
        }
        for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ZoomSpeedSpace.size(); j++){
          Json::Value jsonArrZoomSpeedSpace;
          jsonArrZoomSpeedSpace["URI"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ZoomSpeedSpace[j]->URI;
          if(GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ZoomSpeedSpace[j]->XRange){
            jsonArrZoomSpeedSpace["XRange"]["Min"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ZoomSpeedSpace[j]->XRange->Min;
            jsonArrZoomSpeedSpace["XRange"]["Max"] = GetNodesResponse.PTZNode[i]->SupportedPTZSpaces->ZoomSpeedSpace[j]->XRange->Max;
          }
          jsonArr["SupportedPTZSpaces"]["ZoomSpeedSpace"].append(jsonArrZoomSpeedSpace);
        }
      }

      jsonArr["MaximumNumberOfPresets"] = GetNodesResponse.PTZNode[i]->MaximumNumberOfPresets;
      jsonArr["HomeSupported"] = GetNodesResponse.PTZNode[i]->HomeSupported;
      for(size_t j = 0; j < GetNodesResponse.PTZNode[i]->AuxiliaryCommands.size(); j++){
        jsonArr["AuxiliaryCommands"].append(GetNodesResponse.PTZNode[i]->AuxiliaryCommands[j]);
      }

      dataJson["PTZNode"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetPresets(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetPresets GetPresets;
  _tptz__GetPresetsResponse GetPresetsResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetPresets.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetPresets.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(onvifApi.ptz_GetPresets(clientInfo, &GetPresets, GetPresetsResponse)){
    Json::Value dataJson;
    for(size_t i = 0; i < GetPresetsResponse.Preset.size(); i++){
      Json::Value jsonArr;
      if(GetPresetsResponse.Preset[i]->token){
        jsonArr["token"] = *GetPresetsResponse.Preset[i]->token;
      }
      if(GetPresetsResponse.Preset[i]->Name){
        jsonArr["Name"] = *GetPresetsResponse.Preset[i]->Name;
      }
      if(GetPresetsResponse.Preset[i]->PTZPosition){
        if(GetPresetsResponse.Preset[i]->PTZPosition->PanTilt){
          jsonArr["PTZPosition"]["PanTilt"]["x"] = GetPresetsResponse.Preset[i]->PTZPosition->PanTilt->x;
          jsonArr["PTZPosition"]["PanTilt"]["y"] = GetPresetsResponse.Preset[i]->PTZPosition->PanTilt->y;
        }
        if(GetPresetsResponse.Preset[i]->PTZPosition->Zoom){
          jsonArr["PTZPosition"]["Zoom"]["x"] = GetPresetsResponse.Preset[i]->PTZPosition->Zoom->x;
        }
      }
      
      dataJson["Preset"].append(jsonArr);
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetStatus(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetStatus GetStatus;
  _tptz__GetStatusResponse GetStatusResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetStatus.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetStatus.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(onvifApi.ptz_GetStatus(clientInfo, &GetStatus, GetStatusResponse)){
    Json::Value dataJson;
    if(GetStatusResponse.PTZStatus){
      if(GetStatusResponse.PTZStatus->Position){
        if(GetStatusResponse.PTZStatus->Position->PanTilt){
          dataJson["PTZStatus"]["Position"]["PanTilt"]["x"] = GetStatusResponse.PTZStatus->Position->PanTilt->x;
          dataJson["PTZStatus"]["Position"]["PanTilt"]["y"] = GetStatusResponse.PTZStatus->Position->PanTilt->y;
        }
        if(GetStatusResponse.PTZStatus->Position->Zoom){
          dataJson["PTZStatus"]["Position"]["Zoom"]["x"] = GetStatusResponse.PTZStatus->Position->Zoom->x;
        }
      }
      if(GetStatusResponse.PTZStatus->MoveStatus){
        if(GetStatusResponse.PTZStatus->MoveStatus->PanTilt){
          switch(*GetStatusResponse.PTZStatus->MoveStatus->PanTilt){
          case tt__MoveStatus__IDLE:
            dataJson["PTZStatus"]["MoveStatus"]["PanTilt"] = "IDLE";
            break;
          case tt__MoveStatus__MOVING:
            dataJson["PTZStatus"]["MoveStatus"]["PanTilt"] = "MOVING";
            break;
          case tt__MoveStatus__UNKNOWN:
            dataJson["PTZStatus"]["MoveStatus"]["PanTilt"] = "UNKNOWN";
            break;
          default:
            break;
          }
        }
        if(GetStatusResponse.PTZStatus->MoveStatus->Zoom){
          switch(*GetStatusResponse.PTZStatus->MoveStatus->Zoom){
          case tt__MoveStatus__IDLE:
            dataJson["PTZStatus"]["MoveStatus"]["Zoom"] = "IDLE";
            break;
          case tt__MoveStatus__MOVING:
            dataJson["PTZStatus"]["MoveStatus"]["Zoom"] = "MOVING";
            break;
          case tt__MoveStatus__UNKNOWN:
            dataJson["PTZStatus"]["MoveStatus"]["Zoom"] = "UNKNOWN";
            break;
          default:
            break;
          }
        }
      }
      if(GetStatusResponse.PTZStatus->Error){
        dataJson["PTZStatus"]["Error"] = *GetStatusResponse.PTZStatus->Error;
      }
      if(GetStatusResponse.PTZStatus->UtcTime){
        std::stringstream ss;
        ss << GetStatusResponse.PTZStatus->UtcTime;
        std::string time = ss.str();
        dataJson["PTZStatus"]["UtcTime"] = time;
      }
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GotoHomePosition(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GotoHomePosition GotoHomePosition;
  _tptz__GotoHomePositionResponse GotoHomePositionResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GotoHomePosition.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GotoHomePosition.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(!root_dataResponse["Speed"].isNull()){
    GotoHomePosition.Speed = soap_new_tt__PTZSpeed(onvifApi.soap);
    GotoHomePosition.Speed->PanTilt = soap_new_tt__Vector2D(onvifApi.soap);
    GotoHomePosition.Speed->PanTilt->x = root_dataResponse["Speed"]["PanTilt"]["x"].asFloat();
    GotoHomePosition.Speed->PanTilt->y = root_dataResponse["Speed"]["PanTilt"]["y"].asFloat();
    GotoHomePosition.Speed->Zoom = soap_new_tt__Vector1D(onvifApi.soap);
    GotoHomePosition.Speed->Zoom->x = root_dataResponse["Speed"]["Zoom"]["x"].asFloat();
  }
  if(onvifApi.ptz_GotoHomePosition(clientInfo, &GotoHomePosition, GotoHomePositionResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GotoPreset(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GotoPreset GotoPreset;
  _tptz__GotoPresetResponse GotoPresetResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GotoPreset.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GotoPreset.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(root_dataResponse["PresetToken"].isNull()){
    res.set_content("{\"status\":\"Error no have field: PresetToken\"}", "text/plain");
    return;
  }
  else{
    GotoPreset.PresetToken = root_dataResponse["PresetToken"].asString();
  }
  if(!root_dataResponse["Speed"].isNull()){
    GotoPreset.Speed = soap_new_tt__PTZSpeed(onvifApi.soap);
    GotoPreset.Speed->PanTilt = soap_new_tt__Vector2D(onvifApi.soap);
    GotoPreset.Speed->PanTilt->x = root_dataResponse["Speed"]["PanTilt"]["x"].asFloat();
    GotoPreset.Speed->PanTilt->y = root_dataResponse["Speed"]["PanTilt"]["y"].asFloat();
    GotoPreset.Speed->Zoom = soap_new_tt__Vector1D(onvifApi.soap);
    GotoPreset.Speed->Zoom->x = root_dataResponse["Speed"]["Zoom"]["x"].asFloat();
  }
  if(onvifApi.ptz_GotoPreset(clientInfo, &GotoPreset, GotoPresetResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_RelativeMove(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__RelativeMove RelativeMove;
  _tptz__RelativeMoveResponse RelativeMoveResponse;
  float PanTiltLimitsXMin = 0;
  float PanTiltLimitsXMax = 0;
  float PanTiltLimitsYMin = 0;
  float PanTiltLimitsYMax = 0;
  float ZoomLimitsXMin = 0;
  float ZoomLimitsXMax = 0;
  _tptz__GetNodes GetNodes;
  _tptz__GetNodesResponse GetNodesResponse;
  _tptz__GetConfigurations GetConfigurations;
  _tptz__GetConfigurationsResponse GetConfigurationsResponse;
  if(onvifApi.ptz_GetConfigurations(clientInfo, &GetConfigurations, GetConfigurationsResponse)){
    PanTiltLimitsXMin = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->XRange->Min;
    PanTiltLimitsXMax = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->XRange->Max;
    PanTiltLimitsYMin = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->YRange->Min;
    PanTiltLimitsYMax = GetConfigurationsResponse.PTZConfiguration.front()->PanTiltLimits->Range->YRange->Max;
    ZoomLimitsXMin = GetConfigurationsResponse.PTZConfiguration.front()->ZoomLimits->Range->XRange->Min;
    ZoomLimitsXMax = GetConfigurationsResponse.PTZConfiguration.front()->ZoomLimits->Range->XRange->Max;
  }
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      RelativeMove.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    RelativeMove.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(root_dataResponse["Translation"].isNull()){
    res.set_content("{\"status\":\"Error no have field: Translation\"}", "text/plain");
    return;
  }
  else{
    RelativeMove.Translation = soap_new_tt__PTZVector(onvifApi.soap);
    RelativeMove.Translation->PanTilt = soap_new_tt__Vector2D(onvifApi.soap);
    RelativeMove.Translation->Zoom = soap_new_tt__Vector1D(onvifApi.soap);
    float PanTiltX = root_dataResponse["Translation"]["PanTilt"]["x"].asFloat();
    float PanTiltY = root_dataResponse["Translation"]["PanTilt"]["y"].asFloat();
    float ZoomX = root_dataResponse["Translation"]["Zoom"]["x"].asFloat();
    if(PanTiltX >= 0){
      PanTiltX = PanTiltLimitsXMax*PanTiltX/MOVE_CALIB;
    }else{
      PanTiltX = -PanTiltLimitsXMin*PanTiltX/MOVE_CALIB;
    }
    if(PanTiltY >= 0){
      PanTiltY = PanTiltLimitsYMax*PanTiltY/MOVE_CALIB;
    }else{
      PanTiltY = -PanTiltLimitsYMin*PanTiltY/MOVE_CALIB;
    }
    if(ZoomX >= 0){
      ZoomX = ZoomLimitsXMax*ZoomX/MOVE_CALIB;
    }else{
      ZoomX = -ZoomLimitsXMin*ZoomX/MOVE_CALIB;
    }
    RelativeMove.Translation->PanTilt->x = PanTiltX;
    RelativeMove.Translation->PanTilt->y = PanTiltY;
    RelativeMove.Translation->Zoom->x = ZoomX;
    std::cout << "Translation PanTilt X: " << RelativeMove.Translation->PanTilt->x << std::endl;
    std::cout << "Translation PanTilt Y: " << RelativeMove.Translation->PanTilt->y << std::endl;
    std::cout << "Translation Zoom X: " << RelativeMove.Translation->Zoom->x << std::endl;
  }
  if(!root_dataResponse["Speed"].isNull()){
    RelativeMove.Speed = soap_new_tt__PTZSpeed(onvifApi.soap);
    RelativeMove.Speed->PanTilt = soap_new_tt__Vector2D(onvifApi.soap);
    RelativeMove.Speed->Zoom = soap_new_tt__Vector1D(onvifApi.soap);
    float PanTiltX = root_dataResponse["Speed"]["PanTilt"]["x"].asFloat();
    float PanTiltY = root_dataResponse["Speed"]["PanTilt"]["y"].asFloat();
    float ZoomX = root_dataResponse["Speed"]["Zoom"]["x"].asFloat();
    if(PanTiltX >= 0){
      PanTiltX = PanTiltLimitsXMax*PanTiltX/MOVE_CALIB;
    }else{
      PanTiltX = -PanTiltLimitsXMin*PanTiltX/MOVE_CALIB;
    }
    if(PanTiltY >= 0){
      PanTiltY = PanTiltLimitsYMax*PanTiltY/MOVE_CALIB;
    }else{
      PanTiltY = -PanTiltLimitsYMin*PanTiltY/MOVE_CALIB;
    }
    if(ZoomX >= 0){
      ZoomX = ZoomLimitsXMax*ZoomX/MOVE_CALIB;
    }else{
      ZoomX = -ZoomLimitsXMin*ZoomX/MOVE_CALIB;
    }
    RelativeMove.Speed->PanTilt->x = PanTiltX;
    RelativeMove.Speed->PanTilt->y = PanTiltY;
    RelativeMove.Speed->Zoom->x = ZoomX;
    std::cout << "Speed PanTilt X: " << RelativeMove.Speed->PanTilt->x << std::endl;
    std::cout << "Speed PanTilt Y: " << RelativeMove.Speed->PanTilt->y << std::endl;
    std::cout << "Speed Zoom X: " << RelativeMove.Speed->Zoom->x << std::endl;
  }
  if(onvifApi.ptz_RelativeMove(clientInfo, &RelativeMove, RelativeMoveResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    _tptz__GetStatus GetStatus;
    _tptz__GetStatusResponse GetStatusResponse;
    GetStatus.ProfileToken = RelativeMove.ProfileToken;
    do{
      if(!onvifApi.ptz_GetStatus(clientInfo, &GetStatus, GetStatusResponse)){
        break;
      }
      usleep(500000);
    }
    while(*GetStatusResponse.PTZStatus->MoveStatus->PanTilt != tt__MoveStatus__IDLE
         || *GetStatusResponse.PTZStatus->MoveStatus->Zoom != tt__MoveStatus__IDLE);
    
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_RemovePreset(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__RemovePreset RemovePreset;
  _tptz__RemovePresetResponse RemovePresetResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      RemovePreset.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    RemovePreset.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(root_dataResponse["PresetToken"].isNull()){
    res.set_content("{\"status\":\"Error no have field: PresetToken\"}", "text/plain");
    return;
  }
  else{
    RemovePreset.PresetToken = root_dataResponse["PresetToken"].asString();
  }
  if(onvifApi.ptz_RemovePreset(clientInfo, &RemovePreset, RemovePresetResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_SetConfiguration(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__SetConfiguration SetConfiguration;
  _tptz__SetConfigurationResponse SetConfigurationResponse;
  if(onvifApi.ptz_SetConfiguration(clientInfo, &SetConfiguration, SetConfigurationResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_SetHomePosition(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__SetHomePosition SetHomePosition;
  _tptz__SetHomePositionResponse SetHomePositionResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      SetHomePosition.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    SetHomePosition.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(onvifApi.ptz_SetHomePosition(clientInfo, &SetHomePosition, SetHomePositionResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_SetPreset(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__SetPreset SetPreset;
  _tptz__SetPresetResponse SetPresetResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      SetPreset.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    SetPreset.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(!root_dataResponse["PresetName"].isNull()){
    SetPreset.PresetName = new std::string(root_dataResponse["PresetName"].asString());
  }
  if(!root_dataResponse["PresetToken"].isNull()){
    SetPreset.PresetToken = new std::string(root_dataResponse["PresetToken"].asString());
  }
  if(onvifApi.ptz_SetPreset(clientInfo, &SetPreset, SetPresetResponse)){
    Json::Value dataJson;
    dataJson["PresetToken"] = SetPresetResponse.PresetToken;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_Stop(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__Stop Stop;
  _tptz__StopResponse StopResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      Stop.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    Stop.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(!root_dataResponse["PanTilt"].isNull() 
    && !root_dataResponse["Zoom"].isNull()){
    bool PanTilt = root_dataResponse["PanTilt"].asBool();
    bool Zoom = root_dataResponse["Zoom"].asBool();
    Stop.PanTilt = &PanTilt;
    Stop.Zoom = &Zoom;
  }else{
    bool PanTilt = true;
    bool Zoom = true;
    Stop.PanTilt = &PanTilt;
    Stop.Zoom = &Zoom;
    // res.set_content("{\"status\":\"Error, not have field: PanTilt or Zoom\"}", "text/plain");
    // return;
  }
  if(onvifApi.ptz_Stop(clientInfo, &Stop, StopResponse)){
    Json::Value dataJson;
    dataJson["status"] = "ok";
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetPresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetPresetTour GetPresetTour;
  _tptz__GetPresetTourResponse GetPresetTourResponse;
  if(root_dataResponse["ProfileToken"].isNull()){
    _trt__GetProfiles GetProfiles;
    _trt__GetProfilesResponse GetProfilesResponse;
    if(onvifApi.media_GetProfiles(clientInfo, &GetProfiles, GetProfilesResponse)){
      GetPresetTour.ProfileToken = GetProfilesResponse.Profiles.front()->token;
    }
  }
  else{
    GetPresetTour.ProfileToken = root_dataResponse["ProfileToken"].asString();
  }
  if(onvifApi.ptz_GetPresetTour(clientInfo, &GetPresetTour, GetPresetTourResponse)){
    Json::Value dataJson;
    if(GetPresetTourResponse.PresetTour->token){
      dataJson["PresetTour"]["token"] = *GetPresetTourResponse.PresetTour->token;
    }
    if(GetPresetTourResponse.PresetTour->Name){
      dataJson["PresetTour"]["Name"] = *GetPresetTourResponse.PresetTour->Name;
    }
    if(GetPresetTourResponse.PresetTour->Status){
      switch(GetPresetTourResponse.PresetTour->Status->State){
      case tt__PTZPresetTourState__Idle:
        dataJson["PresetTour"]["Status"]["State"] = "Idle";
        break;
      case tt__PTZPresetTourState__Touring:
        dataJson["PresetTour"]["Status"]["State"] = "Touring";
        break;
      case tt__PTZPresetTourState__Paused:
        dataJson["PresetTour"]["Status"]["State"] = "Paused";
        break;
      case tt__PTZPresetTourState__Extended:
        dataJson["PresetTour"]["Status"]["State"] = "Extended";
        break;
      default:
        break;
      }
      if(GetPresetTourResponse.PresetTour->Status->CurrentTourSpot){
        if(GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->Speed){
          if(GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->Speed->PanTilt){
            dataJson["PresetTour"]["Status"]["CurrentTourSpot"]["Speed"]["PanTilt"]["x"] = GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->Speed->PanTilt->x;
            dataJson["PresetTour"]["Status"]["CurrentTourSpot"]["Speed"]["PanTilt"]["y"] = GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->Speed->PanTilt->y;
          }
          if(GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->Speed->Zoom){
            dataJson["PresetTour"]["Status"]["CurrentTourSpot"]["Speed"]["Zoom"]["x"] = GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->Speed->Zoom->x;
          }
        }
        if(GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->StayTime){
          dataJson["PresetTour"]["Status"]["CurrentTourSpot"]["StayTime"] = *GetPresetTourResponse.PresetTour->Status->CurrentTourSpot->StayTime;
        }
      }
    }
    dataJson["PresetTour"]["AutoStart"] = GetPresetTourResponse.PresetTour->AutoStart;
    if(GetPresetTourResponse.PresetTour->StartingCondition){
      if(GetPresetTourResponse.PresetTour->StartingCondition->RandomPresetOrder){
        dataJson["PresetTour"]["StartingCondition"]["RandomPresetOrder"] = *GetPresetTourResponse.PresetTour->StartingCondition->RandomPresetOrder;
      }
      if(GetPresetTourResponse.PresetTour->StartingCondition->RecurringTime){
        dataJson["PresetTour"]["StartingCondition"]["RecurringTime"] = *GetPresetTourResponse.PresetTour->StartingCondition->RecurringTime;
      }
      if(GetPresetTourResponse.PresetTour->StartingCondition->RecurringDuration){
        dataJson["PresetTour"]["StartingCondition"]["RecurringDuration"] = *GetPresetTourResponse.PresetTour->StartingCondition->RecurringDuration;
      }
      if(GetPresetTourResponse.PresetTour->StartingCondition->Direction){
        switch(*GetPresetTourResponse.PresetTour->StartingCondition->Direction){
        case tt__PTZPresetTourDirection__Forward:
          dataJson["PresetTour"]["StartingCondition"]["Direction"] = "Forward";
          break;
        case tt__PTZPresetTourDirection__Backward:
          dataJson["PresetTour"]["StartingCondition"]["Direction"] = "Backward";
          break;
        case tt__PTZPresetTourDirection__Extended:
          dataJson["PresetTour"]["StartingCondition"]["Direction"] = "Extended";
          break;
        default:
          break;
        }
      }
    }
    for(size_t i = 0; i < GetPresetTourResponse.PresetTour->TourSpot.size(); i++){
      Json::Value jsonArr;
      if(GetPresetTourResponse.PresetTour->TourSpot[i]->Speed){
        if(GetPresetTourResponse.PresetTour->TourSpot[i]->Speed->PanTilt){
          jsonArr["Speed"]["PanTilt"]["x"] = GetPresetTourResponse.PresetTour->TourSpot[i]->Speed->PanTilt->x;
          jsonArr["Speed"]["PanTilt"]["y"] = GetPresetTourResponse.PresetTour->TourSpot[i]->Speed->PanTilt->y;
        }
        if(GetPresetTourResponse.PresetTour->TourSpot[i]->Speed->Zoom){
          jsonArr["Speed"]["Zoom"]["x"] = GetPresetTourResponse.PresetTour->TourSpot[i]->Speed->Zoom->x;
        }
      }
      if(GetPresetTourResponse.PresetTour->TourSpot[i]->StayTime){
        jsonArr["StayTime"] = *GetPresetTourResponse.PresetTour->TourSpot[i]->StayTime;
      }
      dataJson["PresetTour"]["TourSpot"].append(jsonArr);
    }

    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetPresetTours(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetPresetTours GetPresetTours;
  _tptz__GetPresetToursResponse GetPresetToursResponse;
  if(onvifApi.ptz_GetPresetTours(clientInfo, &GetPresetTours, GetPresetToursResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetPresetTourOptions(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetPresetTourOptions GetPresetTourOptions;
  _tptz__GetPresetTourOptionsResponse GetPresetTourOptionsResponse;
  if(onvifApi.ptz_GetPresetTourOptions(clientInfo, &GetPresetTourOptions, GetPresetTourOptionsResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_CreatePresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__CreatePresetTour CreatePresetTour;
  _tptz__CreatePresetTourResponse CreatePresetTourResponse;
  if(onvifApi.ptz_CreatePresetTour(clientInfo, &CreatePresetTour, CreatePresetTourResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_ModifyPresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__ModifyPresetTour ModifyPresetTour;
  _tptz__ModifyPresetTourResponse ModifyPresetTourResponse;
  if(onvifApi.ptz_ModifyPresetTour(clientInfo, &ModifyPresetTour, ModifyPresetTourResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_OperatePresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__OperatePresetTour OperatePresetTour;
  _tptz__OperatePresetTourResponse OperatePresetTourResponse;
  if(onvifApi.ptz_OperatePresetTour(clientInfo, &OperatePresetTour, OperatePresetTourResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_RemovePresetTour(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__RemovePresetTour RemovePresetTour;
  _tptz__RemovePresetTourResponse RemovePresetTourResponse;
  if(onvifApi.ptz_RemovePresetTour(clientInfo, &RemovePresetTour, RemovePresetTourResponse)){
    Json::Value dataJson;
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}

void ptz_GetServiceCapabilities(const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader){
  std::cout << __FUNCTION__ << " - " << __LINE__ << std::endl;
  std::string body;
	content_reader([&](const char *data, size_t data_length) {
    body.append(data, data_length);
    return true;
  });
  std::cout << body << std::endl;
  ClientInfo clientInfo;
  Json::Value root_dataResponse;
  Json::Reader reader;
	reader.parse(body, root_dataResponse);
  if(!root_dataResponse["Ip"].isNull() 
    && !root_dataResponse["Port"].isNull()
    && !root_dataResponse["Username"].isNull()
    && !root_dataResponse["Password"].isNull()){
      clientInfo.ip = root_dataResponse["Ip"].asString();
      clientInfo.port = root_dataResponse["Port"].asInt();
      clientInfo.username = root_dataResponse["Username"].asString();
      clientInfo.password = root_dataResponse["Password"].asString();
  }else{
    res.set_content("{\"status\":\"Error Client Info\"}", "text/plain");
    return;
  }
  if(!root_dataResponse["UseHttps"].isNull()){
    clientInfo.useHttps = root_dataResponse["UseHttps"].asBool();
  }
  _tptz__GetServiceCapabilities GetServiceCapabilities;
  _tptz__GetServiceCapabilitiesResponse GetServiceCapabilitiesResponse;
  if(onvifApi.ptz_GetServiceCapabilities(clientInfo, &GetServiceCapabilities, GetServiceCapabilitiesResponse)){
    Json::Value dataJson;
    if(GetServiceCapabilitiesResponse.Capabilities->EFlip){
      dataJson["Capabilities"]["EFlip"] = *GetServiceCapabilitiesResponse.Capabilities->EFlip;
    }
    if(GetServiceCapabilitiesResponse.Capabilities->Reverse){
      dataJson["Capabilities"]["Reverse"] = *GetServiceCapabilitiesResponse.Capabilities->Reverse;
    }
    if(GetServiceCapabilitiesResponse.Capabilities->GetCompatibleConfigurations){
      dataJson["Capabilities"]["GetCompatibleConfigurations"] = *GetServiceCapabilitiesResponse.Capabilities->GetCompatibleConfigurations;
    }
    if(GetServiceCapabilitiesResponse.Capabilities->MoveStatus){
      dataJson["Capabilities"]["MoveStatus"] = *GetServiceCapabilitiesResponse.Capabilities->MoveStatus;
    }
    if(GetServiceCapabilitiesResponse.Capabilities->StatusPosition){
      dataJson["Capabilities"]["StatusPosition"] = *GetServiceCapabilitiesResponse.Capabilities->StatusPosition;
    }
    if(GetServiceCapabilitiesResponse.Capabilities->MoveAndTrack){
      dataJson["Capabilities"]["MoveAndTrack"] = *GetServiceCapabilitiesResponse.Capabilities->MoveAndTrack;
    }
    Json::StyledWriter StyledWriter;
    std::string data = StyledWriter.write(dataJson);
    res.set_content(data, "text/plain");
  }
  else{
    res.set_content("{\"status\":\"Error, Cant connect to Onvif Server\"}", "text/plain");
  }
}
