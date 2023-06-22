/* soapScheduleBindingProxy.h
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

#ifndef soapScheduleBindingProxy_H
#define soapScheduleBindingProxy_H
#include "soapH.h"

    class SOAP_CMAC ScheduleBindingProxy {
      public:
        /// Context to manage proxy IO and data
        struct soap *soap;
        /// flag indicating that this context is owned by this proxy and should be deleted by the destructor
        bool soap_own;
        /// Endpoint URL of service 'ScheduleBindingProxy' (change as needed)
        const char *soap_endpoint;
        /// Variables globally declared in onvif.h, if any
        /// Construct a proxy with new managing context
        ScheduleBindingProxy();
        /// Copy constructor
        ScheduleBindingProxy(const ScheduleBindingProxy& rhs);
        /// Construct proxy given a shared managing context
        ScheduleBindingProxy(struct soap*);
        /// Construct proxy given a shared managing context and endpoint URL
        ScheduleBindingProxy(struct soap*, const char *soap_endpoint_url);
        /// Constructor taking an endpoint URL
        ScheduleBindingProxy(const char *soap_endpoint_url);
        /// Constructor taking input and output mode flags for the new managing context
        ScheduleBindingProxy(soap_mode iomode);
        /// Constructor taking endpoint URL and input and output mode flags for the new managing context
        ScheduleBindingProxy(const char *soap_endpoint_url, soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        ScheduleBindingProxy(soap_mode imode, soap_mode omode);
        /// Destructor deletes deserialized data and its managing context, when the context was allocated by the constructor
        virtual ~ScheduleBindingProxy();
        /// Initializer used by constructors
        virtual void ScheduleBindingProxy_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual ScheduleBindingProxy *copy();
        /// Copy assignment
        ScheduleBindingProxy& operator=(const ScheduleBindingProxy&);
        /// Delete all deserialized data (uses soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to default
        virtual void reset();
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Add SOAP Header to message
        virtual void soap_header(char *wsa5__MessageID, struct wsa5__RelatesToType *wsa5__RelatesTo, struct wsa5__EndpointReferenceType *wsa5__From, struct wsa5__EndpointReferenceType *wsa5__ReplyTo, struct wsa5__EndpointReferenceType *wsa5__FaultTo, char *wsa5__To, char *wsa5__Action, struct chan__ChannelInstanceType *chan__ChannelInstance, struct wsdd__AppSequenceType *wsdd__AppSequence, struct _wsse__Security *wsse__Security);
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
        /// Get SOAP Fault structure (i.e. soap->fault, which is NULL when absent)
        virtual ::SOAP_ENV__Fault *soap_fault();
        /// Get SOAP Fault subcode QName string (NULL when absent)
        virtual const char *soap_fault_subcode();
        /// Get SOAP Fault string/reason (NULL when absent)
        virtual const char *soap_fault_string();
        /// Get SOAP Fault detail XML string (NULL when absent)
        virtual const char *soap_fault_detail();
        /// Close connection (normally automatic, except for send_X ops)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        //
        /// Web service synchronous operation 'GetServiceCapabilities' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetServiceCapabilities(_ns3__GetServiceCapabilities *ns3__GetServiceCapabilities, _ns3__GetServiceCapabilitiesResponse &ns3__GetServiceCapabilitiesResponse) { return this->GetServiceCapabilities(NULL, NULL, ns3__GetServiceCapabilities, ns3__GetServiceCapabilitiesResponse); }
        /// Web service synchronous operation 'GetServiceCapabilities' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetServiceCapabilities(const char *soap_endpoint_url, const char *soap_action, _ns3__GetServiceCapabilities *ns3__GetServiceCapabilities, _ns3__GetServiceCapabilitiesResponse &ns3__GetServiceCapabilitiesResponse) { return this->send_GetServiceCapabilities(soap_endpoint_url, soap_action, ns3__GetServiceCapabilities) || this->recv_GetServiceCapabilities(ns3__GetServiceCapabilitiesResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetServiceCapabilities' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetServiceCapabilities(const char *soap_endpoint_url, const char *soap_action, _ns3__GetServiceCapabilities *ns3__GetServiceCapabilities);
        /// Web service asynchronous operation 'recv_GetServiceCapabilities' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetServiceCapabilities(_ns3__GetServiceCapabilitiesResponse &ns3__GetServiceCapabilitiesResponse);
        //
        /// Web service synchronous operation 'GetScheduleState' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleState(_ns3__GetScheduleState *ns3__GetScheduleState, _ns3__GetScheduleStateResponse &ns3__GetScheduleStateResponse) { return this->GetScheduleState(NULL, NULL, ns3__GetScheduleState, ns3__GetScheduleStateResponse); }
        /// Web service synchronous operation 'GetScheduleState' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleState(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleState *ns3__GetScheduleState, _ns3__GetScheduleStateResponse &ns3__GetScheduleStateResponse) { return this->send_GetScheduleState(soap_endpoint_url, soap_action, ns3__GetScheduleState) || this->recv_GetScheduleState(ns3__GetScheduleStateResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetScheduleState' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetScheduleState(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleState *ns3__GetScheduleState);
        /// Web service asynchronous operation 'recv_GetScheduleState' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetScheduleState(_ns3__GetScheduleStateResponse &ns3__GetScheduleStateResponse);
        //
        /// Web service synchronous operation 'GetScheduleInfo' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleInfo(_ns3__GetScheduleInfo *ns3__GetScheduleInfo, _ns3__GetScheduleInfoResponse &ns3__GetScheduleInfoResponse) { return this->GetScheduleInfo(NULL, NULL, ns3__GetScheduleInfo, ns3__GetScheduleInfoResponse); }
        /// Web service synchronous operation 'GetScheduleInfo' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleInfo(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleInfo *ns3__GetScheduleInfo, _ns3__GetScheduleInfoResponse &ns3__GetScheduleInfoResponse) { return this->send_GetScheduleInfo(soap_endpoint_url, soap_action, ns3__GetScheduleInfo) || this->recv_GetScheduleInfo(ns3__GetScheduleInfoResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetScheduleInfo' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetScheduleInfo(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleInfo *ns3__GetScheduleInfo);
        /// Web service asynchronous operation 'recv_GetScheduleInfo' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetScheduleInfo(_ns3__GetScheduleInfoResponse &ns3__GetScheduleInfoResponse);
        //
        /// Web service synchronous operation 'GetScheduleInfoList' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleInfoList(_ns3__GetScheduleInfoList *ns3__GetScheduleInfoList, _ns3__GetScheduleInfoListResponse &ns3__GetScheduleInfoListResponse) { return this->GetScheduleInfoList(NULL, NULL, ns3__GetScheduleInfoList, ns3__GetScheduleInfoListResponse); }
        /// Web service synchronous operation 'GetScheduleInfoList' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleInfoList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleInfoList *ns3__GetScheduleInfoList, _ns3__GetScheduleInfoListResponse &ns3__GetScheduleInfoListResponse) { return this->send_GetScheduleInfoList(soap_endpoint_url, soap_action, ns3__GetScheduleInfoList) || this->recv_GetScheduleInfoList(ns3__GetScheduleInfoListResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetScheduleInfoList' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetScheduleInfoList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleInfoList *ns3__GetScheduleInfoList);
        /// Web service asynchronous operation 'recv_GetScheduleInfoList' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetScheduleInfoList(_ns3__GetScheduleInfoListResponse &ns3__GetScheduleInfoListResponse);
        //
        /// Web service synchronous operation 'GetSchedules' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetSchedules(_ns3__GetSchedules *ns3__GetSchedules, _ns3__GetSchedulesResponse &ns3__GetSchedulesResponse) { return this->GetSchedules(NULL, NULL, ns3__GetSchedules, ns3__GetSchedulesResponse); }
        /// Web service synchronous operation 'GetSchedules' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetSchedules(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSchedules *ns3__GetSchedules, _ns3__GetSchedulesResponse &ns3__GetSchedulesResponse) { return this->send_GetSchedules(soap_endpoint_url, soap_action, ns3__GetSchedules) || this->recv_GetSchedules(ns3__GetSchedulesResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetSchedules' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetSchedules(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSchedules *ns3__GetSchedules);
        /// Web service asynchronous operation 'recv_GetSchedules' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetSchedules(_ns3__GetSchedulesResponse &ns3__GetSchedulesResponse);
        //
        /// Web service synchronous operation 'GetScheduleList' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleList(_ns3__GetScheduleList *ns3__GetScheduleList, _ns3__GetScheduleListResponse &ns3__GetScheduleListResponse) { return this->GetScheduleList(NULL, NULL, ns3__GetScheduleList, ns3__GetScheduleListResponse); }
        /// Web service synchronous operation 'GetScheduleList' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetScheduleList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleList *ns3__GetScheduleList, _ns3__GetScheduleListResponse &ns3__GetScheduleListResponse) { return this->send_GetScheduleList(soap_endpoint_url, soap_action, ns3__GetScheduleList) || this->recv_GetScheduleList(ns3__GetScheduleListResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetScheduleList' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetScheduleList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetScheduleList *ns3__GetScheduleList);
        /// Web service asynchronous operation 'recv_GetScheduleList' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetScheduleList(_ns3__GetScheduleListResponse &ns3__GetScheduleListResponse);
        //
        /// Web service synchronous operation 'CreateSchedule' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int CreateSchedule(_ns3__CreateSchedule *ns3__CreateSchedule, _ns3__CreateScheduleResponse &ns3__CreateScheduleResponse) { return this->CreateSchedule(NULL, NULL, ns3__CreateSchedule, ns3__CreateScheduleResponse); }
        /// Web service synchronous operation 'CreateSchedule' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int CreateSchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__CreateSchedule *ns3__CreateSchedule, _ns3__CreateScheduleResponse &ns3__CreateScheduleResponse) { return this->send_CreateSchedule(soap_endpoint_url, soap_action, ns3__CreateSchedule) || this->recv_CreateSchedule(ns3__CreateScheduleResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_CreateSchedule' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_CreateSchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__CreateSchedule *ns3__CreateSchedule);
        /// Web service asynchronous operation 'recv_CreateSchedule' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_CreateSchedule(_ns3__CreateScheduleResponse &ns3__CreateScheduleResponse);
        //
        /// Web service synchronous operation 'SetSchedule' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int SetSchedule(_ns3__SetSchedule *ns3__SetSchedule, _ns3__SetScheduleResponse &ns3__SetScheduleResponse) { return this->SetSchedule(NULL, NULL, ns3__SetSchedule, ns3__SetScheduleResponse); }
        /// Web service synchronous operation 'SetSchedule' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int SetSchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__SetSchedule *ns3__SetSchedule, _ns3__SetScheduleResponse &ns3__SetScheduleResponse) { return this->send_SetSchedule(soap_endpoint_url, soap_action, ns3__SetSchedule) || this->recv_SetSchedule(ns3__SetScheduleResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_SetSchedule' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_SetSchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__SetSchedule *ns3__SetSchedule);
        /// Web service asynchronous operation 'recv_SetSchedule' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_SetSchedule(_ns3__SetScheduleResponse &ns3__SetScheduleResponse);
        //
        /// Web service synchronous operation 'ModifySchedule' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int ModifySchedule(_ns3__ModifySchedule *ns3__ModifySchedule, _ns3__ModifyScheduleResponse &ns3__ModifyScheduleResponse) { return this->ModifySchedule(NULL, NULL, ns3__ModifySchedule, ns3__ModifyScheduleResponse); }
        /// Web service synchronous operation 'ModifySchedule' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int ModifySchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__ModifySchedule *ns3__ModifySchedule, _ns3__ModifyScheduleResponse &ns3__ModifyScheduleResponse) { return this->send_ModifySchedule(soap_endpoint_url, soap_action, ns3__ModifySchedule) || this->recv_ModifySchedule(ns3__ModifyScheduleResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_ModifySchedule' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_ModifySchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__ModifySchedule *ns3__ModifySchedule);
        /// Web service asynchronous operation 'recv_ModifySchedule' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_ModifySchedule(_ns3__ModifyScheduleResponse &ns3__ModifyScheduleResponse);
        //
        /// Web service synchronous operation 'DeleteSchedule' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int DeleteSchedule(_ns3__DeleteSchedule *ns3__DeleteSchedule, _ns3__DeleteScheduleResponse &ns3__DeleteScheduleResponse) { return this->DeleteSchedule(NULL, NULL, ns3__DeleteSchedule, ns3__DeleteScheduleResponse); }
        /// Web service synchronous operation 'DeleteSchedule' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int DeleteSchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__DeleteSchedule *ns3__DeleteSchedule, _ns3__DeleteScheduleResponse &ns3__DeleteScheduleResponse) { return this->send_DeleteSchedule(soap_endpoint_url, soap_action, ns3__DeleteSchedule) || this->recv_DeleteSchedule(ns3__DeleteScheduleResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_DeleteSchedule' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_DeleteSchedule(const char *soap_endpoint_url, const char *soap_action, _ns3__DeleteSchedule *ns3__DeleteSchedule);
        /// Web service asynchronous operation 'recv_DeleteSchedule' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_DeleteSchedule(_ns3__DeleteScheduleResponse &ns3__DeleteScheduleResponse);
        //
        /// Web service synchronous operation 'GetSpecialDayGroupInfo' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroupInfo(_ns3__GetSpecialDayGroupInfo *ns3__GetSpecialDayGroupInfo, _ns3__GetSpecialDayGroupInfoResponse &ns3__GetSpecialDayGroupInfoResponse) { return this->GetSpecialDayGroupInfo(NULL, NULL, ns3__GetSpecialDayGroupInfo, ns3__GetSpecialDayGroupInfoResponse); }
        /// Web service synchronous operation 'GetSpecialDayGroupInfo' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroupInfo(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroupInfo *ns3__GetSpecialDayGroupInfo, _ns3__GetSpecialDayGroupInfoResponse &ns3__GetSpecialDayGroupInfoResponse) { return this->send_GetSpecialDayGroupInfo(soap_endpoint_url, soap_action, ns3__GetSpecialDayGroupInfo) || this->recv_GetSpecialDayGroupInfo(ns3__GetSpecialDayGroupInfoResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetSpecialDayGroupInfo' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetSpecialDayGroupInfo(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroupInfo *ns3__GetSpecialDayGroupInfo);
        /// Web service asynchronous operation 'recv_GetSpecialDayGroupInfo' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetSpecialDayGroupInfo(_ns3__GetSpecialDayGroupInfoResponse &ns3__GetSpecialDayGroupInfoResponse);
        //
        /// Web service synchronous operation 'GetSpecialDayGroupInfoList' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroupInfoList(_ns3__GetSpecialDayGroupInfoList *ns3__GetSpecialDayGroupInfoList, _ns3__GetSpecialDayGroupInfoListResponse &ns3__GetSpecialDayGroupInfoListResponse) { return this->GetSpecialDayGroupInfoList(NULL, NULL, ns3__GetSpecialDayGroupInfoList, ns3__GetSpecialDayGroupInfoListResponse); }
        /// Web service synchronous operation 'GetSpecialDayGroupInfoList' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroupInfoList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroupInfoList *ns3__GetSpecialDayGroupInfoList, _ns3__GetSpecialDayGroupInfoListResponse &ns3__GetSpecialDayGroupInfoListResponse) { return this->send_GetSpecialDayGroupInfoList(soap_endpoint_url, soap_action, ns3__GetSpecialDayGroupInfoList) || this->recv_GetSpecialDayGroupInfoList(ns3__GetSpecialDayGroupInfoListResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetSpecialDayGroupInfoList' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetSpecialDayGroupInfoList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroupInfoList *ns3__GetSpecialDayGroupInfoList);
        /// Web service asynchronous operation 'recv_GetSpecialDayGroupInfoList' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetSpecialDayGroupInfoList(_ns3__GetSpecialDayGroupInfoListResponse &ns3__GetSpecialDayGroupInfoListResponse);
        //
        /// Web service synchronous operation 'GetSpecialDayGroups' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroups(_ns3__GetSpecialDayGroups *ns3__GetSpecialDayGroups, _ns3__GetSpecialDayGroupsResponse &ns3__GetSpecialDayGroupsResponse) { return this->GetSpecialDayGroups(NULL, NULL, ns3__GetSpecialDayGroups, ns3__GetSpecialDayGroupsResponse); }
        /// Web service synchronous operation 'GetSpecialDayGroups' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroups(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroups *ns3__GetSpecialDayGroups, _ns3__GetSpecialDayGroupsResponse &ns3__GetSpecialDayGroupsResponse) { return this->send_GetSpecialDayGroups(soap_endpoint_url, soap_action, ns3__GetSpecialDayGroups) || this->recv_GetSpecialDayGroups(ns3__GetSpecialDayGroupsResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetSpecialDayGroups' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetSpecialDayGroups(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroups *ns3__GetSpecialDayGroups);
        /// Web service asynchronous operation 'recv_GetSpecialDayGroups' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetSpecialDayGroups(_ns3__GetSpecialDayGroupsResponse &ns3__GetSpecialDayGroupsResponse);
        //
        /// Web service synchronous operation 'GetSpecialDayGroupList' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroupList(_ns3__GetSpecialDayGroupList *ns3__GetSpecialDayGroupList, _ns3__GetSpecialDayGroupListResponse &ns3__GetSpecialDayGroupListResponse) { return this->GetSpecialDayGroupList(NULL, NULL, ns3__GetSpecialDayGroupList, ns3__GetSpecialDayGroupListResponse); }
        /// Web service synchronous operation 'GetSpecialDayGroupList' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int GetSpecialDayGroupList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroupList *ns3__GetSpecialDayGroupList, _ns3__GetSpecialDayGroupListResponse &ns3__GetSpecialDayGroupListResponse) { return this->send_GetSpecialDayGroupList(soap_endpoint_url, soap_action, ns3__GetSpecialDayGroupList) || this->recv_GetSpecialDayGroupList(ns3__GetSpecialDayGroupListResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_GetSpecialDayGroupList' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_GetSpecialDayGroupList(const char *soap_endpoint_url, const char *soap_action, _ns3__GetSpecialDayGroupList *ns3__GetSpecialDayGroupList);
        /// Web service asynchronous operation 'recv_GetSpecialDayGroupList' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_GetSpecialDayGroupList(_ns3__GetSpecialDayGroupListResponse &ns3__GetSpecialDayGroupListResponse);
        //
        /// Web service synchronous operation 'CreateSpecialDayGroup' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int CreateSpecialDayGroup(_ns3__CreateSpecialDayGroup *ns3__CreateSpecialDayGroup, _ns3__CreateSpecialDayGroupResponse &ns3__CreateSpecialDayGroupResponse) { return this->CreateSpecialDayGroup(NULL, NULL, ns3__CreateSpecialDayGroup, ns3__CreateSpecialDayGroupResponse); }
        /// Web service synchronous operation 'CreateSpecialDayGroup' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int CreateSpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__CreateSpecialDayGroup *ns3__CreateSpecialDayGroup, _ns3__CreateSpecialDayGroupResponse &ns3__CreateSpecialDayGroupResponse) { return this->send_CreateSpecialDayGroup(soap_endpoint_url, soap_action, ns3__CreateSpecialDayGroup) || this->recv_CreateSpecialDayGroup(ns3__CreateSpecialDayGroupResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_CreateSpecialDayGroup' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_CreateSpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__CreateSpecialDayGroup *ns3__CreateSpecialDayGroup);
        /// Web service asynchronous operation 'recv_CreateSpecialDayGroup' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_CreateSpecialDayGroup(_ns3__CreateSpecialDayGroupResponse &ns3__CreateSpecialDayGroupResponse);
        //
        /// Web service synchronous operation 'SetSpecialDayGroup' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int SetSpecialDayGroup(_ns3__SetSpecialDayGroup *ns3__SetSpecialDayGroup, _ns3__SetSpecialDayGroupResponse &ns3__SetSpecialDayGroupResponse) { return this->SetSpecialDayGroup(NULL, NULL, ns3__SetSpecialDayGroup, ns3__SetSpecialDayGroupResponse); }
        /// Web service synchronous operation 'SetSpecialDayGroup' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int SetSpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__SetSpecialDayGroup *ns3__SetSpecialDayGroup, _ns3__SetSpecialDayGroupResponse &ns3__SetSpecialDayGroupResponse) { return this->send_SetSpecialDayGroup(soap_endpoint_url, soap_action, ns3__SetSpecialDayGroup) || this->recv_SetSpecialDayGroup(ns3__SetSpecialDayGroupResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_SetSpecialDayGroup' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_SetSpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__SetSpecialDayGroup *ns3__SetSpecialDayGroup);
        /// Web service asynchronous operation 'recv_SetSpecialDayGroup' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_SetSpecialDayGroup(_ns3__SetSpecialDayGroupResponse &ns3__SetSpecialDayGroupResponse);
        //
        /// Web service synchronous operation 'ModifySpecialDayGroup' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int ModifySpecialDayGroup(_ns3__ModifySpecialDayGroup *ns3__ModifySpecialDayGroup, _ns3__ModifySpecialDayGroupResponse &ns3__ModifySpecialDayGroupResponse) { return this->ModifySpecialDayGroup(NULL, NULL, ns3__ModifySpecialDayGroup, ns3__ModifySpecialDayGroupResponse); }
        /// Web service synchronous operation 'ModifySpecialDayGroup' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int ModifySpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__ModifySpecialDayGroup *ns3__ModifySpecialDayGroup, _ns3__ModifySpecialDayGroupResponse &ns3__ModifySpecialDayGroupResponse) { return this->send_ModifySpecialDayGroup(soap_endpoint_url, soap_action, ns3__ModifySpecialDayGroup) || this->recv_ModifySpecialDayGroup(ns3__ModifySpecialDayGroupResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_ModifySpecialDayGroup' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_ModifySpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__ModifySpecialDayGroup *ns3__ModifySpecialDayGroup);
        /// Web service asynchronous operation 'recv_ModifySpecialDayGroup' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_ModifySpecialDayGroup(_ns3__ModifySpecialDayGroupResponse &ns3__ModifySpecialDayGroupResponse);
        //
        /// Web service synchronous operation 'DeleteSpecialDayGroup' with default endpoint and default SOAP Action header, returns SOAP_OK or error code
        virtual int DeleteSpecialDayGroup(_ns3__DeleteSpecialDayGroup *ns3__DeleteSpecialDayGroup, _ns3__DeleteSpecialDayGroupResponse &ns3__DeleteSpecialDayGroupResponse) { return this->DeleteSpecialDayGroup(NULL, NULL, ns3__DeleteSpecialDayGroup, ns3__DeleteSpecialDayGroupResponse); }
        /// Web service synchronous operation 'DeleteSpecialDayGroup' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int DeleteSpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__DeleteSpecialDayGroup *ns3__DeleteSpecialDayGroup, _ns3__DeleteSpecialDayGroupResponse &ns3__DeleteSpecialDayGroupResponse) { return this->send_DeleteSpecialDayGroup(soap_endpoint_url, soap_action, ns3__DeleteSpecialDayGroup) || this->recv_DeleteSpecialDayGroup(ns3__DeleteSpecialDayGroupResponse) ? this->soap->error : SOAP_OK; }
        /// Web service asynchronous operation 'send_DeleteSpecialDayGroup' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code
        virtual int send_DeleteSpecialDayGroup(const char *soap_endpoint_url, const char *soap_action, _ns3__DeleteSpecialDayGroup *ns3__DeleteSpecialDayGroup);
        /// Web service asynchronous operation 'recv_DeleteSpecialDayGroup' to receive a response message from the connected endpoint, returns SOAP_OK or error code
        virtual int recv_DeleteSpecialDayGroup(_ns3__DeleteSpecialDayGroupResponse &ns3__DeleteSpecialDayGroupResponse);
    };
#endif