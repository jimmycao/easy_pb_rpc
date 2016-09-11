INCLUDES=-I../../src -I/home/jimmy/usr/local/libevent-2.0.22/include -I/home/jimmy/usr/local/protobuf-2.4.1/include
LDFLAGS=-lpthread -lprotobuf -levent -L/usr/local/lib -L/home/jimmy/usr/local/libevent-2.0.22/lib -L/home/jimmy/usr/local/protobuf-2.4.1/lib
CFLAGS=-g

COMMON = Common.h RpcController.h ServiceName2Id.h

all: protoc_run AddClient_main AddServer_main

protoc_run: Add.proto
	protoc --cpp_out=./ Add.proto

Add.pb.o:Add.pb.cc
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

%.o:%.cpp
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

AddClient_main: protoc_run Add.pb.o AddClient.o
	c++ $(INCLUDES) -o AddClient_main AddClient.o Add.pb.o -L../../src -lrpcclient $(LDFLAGS) 

AddServer_main: protoc_run Add.pb.o AddServer.o
	c++ $(INCLUDES) -o AddServer_main AddServer.o Add.pb.o  -L../../src -lrpcserver $(LDFLAGS)

clean:
	-rm *_main *.o *.pb.h *.pb.cc
