set(onvifApi onvifApi.cpp onvifApi.h soapStub.h)
set(soapC soapC.cpp soapH.h)
set(wsddClient wsddClient.cpp wsddH.h)
set(wsddServer wsddServer.cpp wsddH.h)
set(soapAdvancedSecurityServiceBindingProxy soapAdvancedSecurityServiceBindingProxy.cpp soapAdvancedSecurityServiceBindingProxy.h)
set(soapDeviceBindingProxy soapDeviceBindingProxy.cpp soapDeviceBindingProxy.h)
set(soapImagingBindingProxy soapImagingBindingProxy.cpp soapImagingBindingProxy.h)
set(soapMediaBindingProxy soapMediaBindingProxy.cpp soapMediaBindingProxy.h)
set(soapPTZBindingProxy soapPTZBindingProxy.cpp soapPTZBindingProxy.h)
set(soapPullPointSubscriptionBindingProxy soapPullPointSubscriptionBindingProxy.cpp soapPullPointSubscriptionBindingProxy.h)
set(soapwsddProxy soapwsddProxy.cpp soapwsddProxy.h)
set(soapRemoteDiscoveryBindingProxy soapRemoteDiscoveryBindingProxy.cpp soapRemoteDiscoveryBindingProxy.h)
set(stdsoap2 stdsoap2.cpp stdsoap2.h)
set(dom dom.cpp stdsoap2.h)
set(smdevp smdevp.c smdevp.h)
set(mecevp mecevp.c mecevp.h)
set(wsaapi wsaapi.c wsaapi.h)
set(wsseapi wsseapi.c wsseapi.h threads.c threads.h wsaapi.h)
set(wsddapi wsddapi.c wsddapi.h)
set(struct_timeval struct_timeval.c struct_timeval.h)

# target_sources(app PUBLIC ${onvifApi}
# ${soapC}
# ${wsddClient}
# ${wsddServer}
# ${soapAdvancedSecurityServiceBindingProxy}
# ${soapDeviceBindingProxy}
# ${soapImagingBindingProxy}
# ${soapMediaBindingProxy}
# ${soapPTZBindingProxy}
# ${soapPullPointSubscriptionBindingProxy}
# ${soapwsddProxy}
# ${soapRemoteDiscoveryBindingProxy}
# ${stdsoap2}
# ${dom}
# ${smdevp}
# ${mecevp}
# ${wsaapi}
# ${wsseapi}
# ${wsddapi}
# ${struct_timeval})

add_library(onvif ${onvifApi}
${soapC}
${wsddClient}
${wsddServer}
${soapAdvancedSecurityServiceBindingProxy}
${soapDeviceBindingProxy}
${soapImagingBindingProxy}
${soapMediaBindingProxy}
${soapPTZBindingProxy}
${soapPullPointSubscriptionBindingProxy}
${soapwsddProxy}
${soapRemoteDiscoveryBindingProxy}
${stdsoap2}
${dom}
${smdevp}
${mecevp}
${wsaapi}
${wsseapi}
${wsddapi}
${struct_timeval})
include_directories(app PUBLIC 
                                "${PROJECT_SOURCE_DIR}"
                                "${PROJECT_SOURCE_DIR}/libOnvif"
                                "${PROJECT_SOURCE_DIR}/include")
set(CXXFLAGS  "-DWITH_OPENSSL -Wall -g -DWITH_DOM -DWITH_ZLIB -I. -lcrypto -lssl -lz -ljsoncpp -lpthread -std=c++11")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")