# Onvif Clinet using C++

## How to generate with gsoap 2.8

### Create file onvif.h using wsdl2h
```
wsdl2h -o onvif.h \
  http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl \
  http://www.onvif.org/onvif/ver10/events/wsdl/event.wsdl \
  http://www.onvif.org/onvif/ver10/deviceio.wsdl \
  http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl \
  http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl \
  http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl \
  http://www.onvif.org/ver20/analytics/wsdl/analytics.wsdl  \
  http://www.onvif.org/onvif/ver10/network/wsdl/remotediscovery.wsdl \
  http://www.onvif.org/ver10/advancedsecurity/wsdl/advancedsecurity.wsdl \
  http://www.onvif.org/ver10/recording.wsdl \
  http://www.onvif.org/ver10/replay.wsdl \
  http://www.onvif.org/ver10/schedule/wsdl/schedule.wsdl \
  http://www.onvif.org/ver10/receiver.wsdl \
  http://www.onvif.org/ver10/credential/wsdl/credential.wsdl
  
```
After create onvif.h. Change `#import "wsdd10.h"` to `#import "wsdd5.h"`. Add `#import "wsse.h"`

### Generate code using soapcpp2
```
soapcpp2 -2 -C -r -I ~/gsoap-2.8/gsoap/import -I ~/gsoap-2.8/gsoap -j -x onvif.h
```
`-T` for generate testing code

### Link

Link guide install gsoap [Install gsoap](https://www.genivia.com/downloads.html).

Link how to use gsoap onvif [Onvif examples](https://www.genivia.com/examples/onvif/index.html).

### Install dependencies 
```
sudo apt-get update
```
```
sudo apt-get install libjsoncpp-dev
```

### Build code
```
make
```

### Clean code
```
make clean
```

### How to run
Example:
```
./onvif_client 8001
```
Note:

`8001` port http server

access token: Qtf_7g5AX_7zuVeQo8NZ