ʹ�õ���WS-Discovery 2005��׼(��Ȼ��ʧЧ, ����ONVIF��Ȼָ��, �ο�ws-discovery.wsdl�ļ�)

��������ο�����

wsdl2h -cg -o wsdiscovery.h -t %GSOAP%/WS/WS-typemap.dat ws-discovery.wsdl
�����ļ�: wsdiscovery.h
ע��:���ļ�������soapcpp2���ɴ�����, ���vs�����в���������

soapcpp2 -L -c -pdiscoWS -I%GSOAP%/import -I%GOAP% -d wsdiscovery.h
�����ļ�:discoWSH.h discoWSC.c discoWSStub.h discoWSClient.c DiscoWSServer.c wsdd.nsmap

stdsoap.* threads.* wsaapi.* wsddapi.*��Դ��gsoap�е�Դ����
wsaapi.h������ԭ�����õ�ͷ�ļ�, �����õ���discoWSH.h;ͬʱ��ԭ�ȵ�usleep�����滻Ϊwindows�µ�Sleep����

wsdd.nsmap��������´�����
{"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://www.w3.org/*/soap-envelope", NULL}
{"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://www.w3.org/*/soap-encoding", NULL}
�����������Ԫ��
{"tdn", "http://www.onvif.org/ver10/network/wsdl", NULL, NULL}
{"tds", "http://www.onvif.org/ver10/device/wsdl", NULL, NULL}

�汾��Ϣ:gsoap2.8.21, Visual Studio 2012 update 4
