INCLUDES=-I../ -I/home/jimmy/usr/local/libevent-2.0.22/include -I/home/jimmy/usr/local/protobuf-2.4.1/include
LDFLAGS=-lpthread -lprotobuf -levent -L/usr/local/lib -L/home/jimmy/usr/local/libevent-2.0.22/lib -L/home/jimmy/usr/local/protobuf-2.4.1/lib
CFLAGS=-g

COMMON = Common.h RpcController.h ServiceName2Id.h

all: protoc_run PServerClient_main PServerServer_main

protoc_run: PServer.proto
	protoc --cpp_out=. PServer.proto

PServer.pb.o:PServer.pb.cc
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

%.o:%.cpp
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

PServerClient_main: PServerClient.o PServer.pb.o protoc_run
	c++ $(INCLUDES) -o PServerClient_main PServerClient.o PServer.pb.o -L../ -lrpcclient $(LDFLAGS) 

PServerServer_main: PServerServer.o PServer.pb.o protoc_run
	c++ $(INCLUDES) -o PServerServer_main PServerServer.o PServer.pb.o  -L../ -lrpcserver $(LDFLAGS)

clean:
	-rm *.o PServerServer_main PServerClient_main *.pb.h *.pb.cc
