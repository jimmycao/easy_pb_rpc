INCLUDES=-I../ -I/home/jimmy/usr/local/libevent-2.0.22/include -I/home/jimmy/usr/local/protobuf-2.4.1/include
LDFLAGS=-lpthread -lprotobuf -levent -L/usr/local/lib -L/home/jimmy/usr/local/libevent-2.0.22/lib -L/home/jimmy/usr/local/protobuf-2.4.1/lib
CFLAGS=-g

COMMON = common.h rpc_controller.h svc_name2id.h

all: client server protoc_middleman

%.o:%.cc
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

client: clt.o helloworld.pb.o
	c++ $(INCLUDES) -o client clt.o helloworld.pb.o -L../ -lrpcclt $(LDFLAGS) 

server: svr.o helloworld.pb.o
	c++ $(INCLUDES) -o server svr.o helloworld.pb.o  -L../ -lrpcsvr $(LDFLAGS)
protoc_middleman: helloworld.proto
	protoc --cpp_out=. helloworld.proto

clean:
	-rm *.o server client
