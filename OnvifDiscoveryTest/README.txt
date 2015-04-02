使用的是WS-Discovery 2005标准(虽然已失效, 但是ONVIF依然指定, 参考ws-discovery.wsdl文件)

生成命令参考如下

wsdl2h -cg -o wsdiscovery.h -t %GSOAP%/WS/WS-typemap.dat ws-discovery.wsdl
生成文件: wsdiscovery.h
注意:此文件仅用于soapcpp2生成代码用, 因此vs工程中并不包含它

soapcpp2 -L -c -pdiscoWS -I%GSOAP%/import -I%GOAP% -d wsdiscovery.h
生成文件:discoWSH.h discoWSC.c discoWSStub.h discoWSClient.c DiscoWSServer.c wsdd.nsmap

stdsoap.* threads.* wsaapi.* wsddapi.*来源于gsoap中的源代码
wsaapi.h更改了原先引用的头文件, 现引用的是discoWSH.h;同时将原先的usleep调用替换为windows下的Sleep调用

wsdd.nsmap变更了如下代码行
{"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://www.w3.org/*/soap-envelope", NULL}
{"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://www.w3.org/*/soap-encoding", NULL}
并添加了如下元素
{"tdn", "http://www.onvif.org/ver10/network/wsdl", NULL, NULL}
{"tds", "http://www.onvif.org/ver10/device/wsdl", NULL, NULL}

版本信息:gsoap2.8.21, Visual Studio 2012 update 4
