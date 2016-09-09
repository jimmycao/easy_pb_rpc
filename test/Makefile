INCLUDES=-I../ -I/home/jimmy/usr/local/libevent-2.0.22/include -I/home/jimmy/usr/local/protobuf-2.4.1/include
LDFLAGS=-lpthread -lprotobuf -levent -L/usr/local/lib -L/home/jimmy/usr/local/libevent-2.0.22/lib -L/home/jimmy/usr/local/protobuf-2.4.1/lib
CFLAGS=-g

COMMON = Common.h RpcController.h ServiceName2Id.h

all: protoc_run EchoClient_main EchoServer_main

protoc_run: Echo.proto
	protoc --cpp_out=./ Echo.proto

Echo.pb.o:Echo.pb.cc
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

%.o:%.cpp
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

EchoClient_main: protoc_run Echo.pb.o EchoClient.o
	c++ $(INCLUDES) -o EchoClient_main EchoClient.o Echo.pb.o -L../ -lrpcclient $(LDFLAGS) 

EchoServer_main: protoc_run Echo.pb.o EchoServer.o
	c++ $(INCLUDES) -o EchoServer_main EchoServer.o Echo.pb.o  -L../ -lrpcserver $(LDFLAGS)

clean:
	-rm *_main *.o *.pb.h *.pb.cc
