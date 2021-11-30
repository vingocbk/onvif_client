#ifndef onvifStub_H
#define onvifStub_H

#include <vector>
#include "soapStub.h"

struct tds_onvif_Capabilities;
struct tds_onvif_DeviceCapabilities;
struct tds_onvif_ImagingCapabilities;
struct tds_onvif_MediaCapabilities;
struct tds_onvif_PTZCapabilities;
struct tds_onvif_Service;
struct tds_onvif_DeviceInformation;
struct tds_onvif_HostnameInformation;
struct tds_onvif_NetworkInterfaces;
struct tds_onvif_NetworkInterfaceInfo;
struct tds_onvif_IPv4NetworkInterface;
struct tds_onvif_IPv4Configuration;
struct tds_onvif_PrefixedIPv4Address;
struct tds_onvif_NetworkProtocols;
struct tds_onvif_Scopes;
struct tds_onvif_SystemDateTime;
struct tds_onvif_TimeZone;
struct tds_onvif_DateTime;
struct tds_onvif_Time;
struct tds_onvif_Date;
struct tds_onvif_User;

struct trt_onvif_Profile;
struct trt_onvif_VideoSourceConfiguration;
struct trt_onvif_AudioSourceConfiguration;
struct trt_onvif_VideoEncoderConfiguration;
struct trt_onvif_AudioEncoderConfiguration;
struct trt_onvif_PTZConfiguration;
struct trt_onvif_VideoResolution;
struct trt_onvif_VideoRateControl;
struct trt_onvif_ConfigurationEntity;
struct trt_onvif_VideoSource;

struct cus_onvif_Identification;
struct cus_onvif_tptz_ContinuousMove;
struct cus_onvif_tptz_PTZSpeed;
struct cus_onvif_tptz_Vector2D;
struct cus_onvif_tptz_Vector1D;
struct cus_onvif_tptz_Stop;

struct tds_onvif_Capabilities
{
    /* data */
    tds_onvif_DeviceCapabilities *DeviceCapabilities;
    tds_onvif_ImagingCapabilities *ImagingCapabilities;
    tds_onvif_MediaCapabilities *MediaCapabilities;
    tds_onvif_PTZCapabilities *PTZCapabilities;
};

struct tds_onvif_DeviceCapabilities
{
    /* data */
    std::string XAddr;
};

struct tds_onvif_ImagingCapabilities
{
    /* data */
    std::string XAddr;
};

struct tds_onvif_MediaCapabilities
{
    /* data */
    std::string XAddr;
};

struct tds_onvif_PTZCapabilities
{
    /* data */
    std::string XAddr;
};

struct tds_onvif_Service
{
    /* data */
    std::string Namespace;
    std::string XAddr;
};

struct tds_onvif_DeviceInformation
{
    /* data */
    std::string Manufacturer;
    std::string Model;
    std::string FirmwareVersion;
    std::string SerialNumber;
    std::string HardwareId;
};

struct tds_onvif_HostnameInformation
{
    /* data */
    bool FromDHCP;
    std::string Name;
};

struct tds_onvif_NetworkInterfaces
{
    /* data */
    bool Enabled;
    std::string Name;
};

struct tds_onvif_NetworkInterfaceInfo
{
    /* data */
    std::string Name;
    std::string HwAddress;
};

struct tds_onvif_IPv4NetworkInterface
{
    /* data */
    bool Enabled;
    tds_onvif_IPv4Configuration *Config;
};

struct tds_onvif_IPv4Configuration
{
    /* data */
    std::vector<tds_onvif_PrefixedIPv4Address *> Manual;
    tds_onvif_PrefixedIPv4Address *FromDHCP;
    bool DHCP;
};

struct tds_onvif_PrefixedIPv4Address
{
    /* data */
    std::string Address;
    int PrefixLength;
};

struct tds_onvif_NetworkProtocols
{
    /* data */
    enum tt__NetworkProtocolType Name;
    bool Enabled;
    std::vector<int> Port;
};

struct tds_onvif_Scopes
{
    /* data */
    enum tt__ScopeDefinition ScopeDef;
    std::string ScopeItem;
};

struct tds_onvif_SystemDateTime
{
    /* data */
    enum tt__SetDateTimeType DateTimeType;
    bool DaylightSavings;
    tds_onvif_TimeZone *TimeZone;
    tds_onvif_DateTime *UTCDateTime;
    tds_onvif_DateTime *LocalDateTime;
};

struct tds_onvif_TimeZone
{
    /* data */
    std::string TZ;
};

struct tds_onvif_DateTime
{
    /* data */
    tds_onvif_Time *Time;
    tds_onvif_Date *Date;
};

struct tds_onvif_Time
{
    /* data */
    int Hour;
    int Minute;
    int Second;
};

struct tds_onvif_Date
{
    /* data */
    int Year;
    int Month;
    int Day;
};

struct tds_onvif_User
{
    /* data */
    std::string Username;
    std::string *Password;
    enum tt__UserLevel UserLevel;
};

struct trt_onvif_Profile
{
    /* data */
    std::string token;
    bool *fixed;
    std::string Name;
    tt__VideoSourceConfiguration *VideoSourceConfiguration;
};

struct trt_onvif_ConfigurationEntity
{
    /* data */
    std::string Name;
    int UseCount;
    std::string token;
};

struct trt_onvif_VideoSourceConfiguration : trt_onvif_ConfigurationEntity
{
    /* data */
    std::string SourceToken;
    std::string *ViewMode;
};

struct trt_onvif_AudioSourceConfiguration : trt_onvif_ConfigurationEntity
{
    /* data */
    std::string SourceToken;
};

struct trt_onvif_VideoEncoderConfiguration : trt_onvif_ConfigurationEntity
{
    /* data */
    enum tt__VideoEncoding Encoding;
    trt_onvif_VideoResolution *Resolution;
    float Quality;
    trt_onvif_VideoRateControl *RateControl;
};

struct trt_onvif_VideoResolution
{
    /* data */
    int Width;
    int Height;
};

struct trt_onvif_VideoRateControl
{
    /* data */
    int FrameRateLimit;
    int EncodingInterval;
    int BitrateLimit;
};

struct trt_onvif_AudioEncoderConfiguration : trt_onvif_ConfigurationEntity
{
    /* data */
    enum tt__AudioEncoding Encoding;
    int Bitrate;
    int SampleRate;
};

struct trt_onvif_VideoSource
{
    /* data */
    std::string token;
    float Framerate;
    trt_onvif_VideoResolution *Resolution;
};

struct cus_onvif_Identification
{
    std::string Name;
    std::string Location;
    std::string Manufacturer;
    std::string Model;
    std::string HardwareId;
    std::string FirmwareVersion;
    std::string SerialNumber;
    std::string IP;
    std::string MAC;
    std::string URL;
};

struct cus_onvif_tptz_ContinuousMove
{
    std::string ProfileToken;
    cus_onvif_tptz_PTZSpeed *Velocity;
};

struct cus_onvif_tptz_PTZSpeed
{
    cus_onvif_tptz_Vector2D *PanTilt;
    cus_onvif_tptz_Vector1D *Zoom;
};

struct cus_onvif_tptz_Vector2D
{
    float x;
    float y;
};

struct cus_onvif_tptz_Vector1D
{
    float x;
};

struct cus_onvif_tptz_Stop
{
    std::string ProfileToken;
    bool *PanTilt;
    bool *Zoom;
};




#endif