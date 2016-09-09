COMMON = Common.h RpcController.h ServiceName2Id.h
RPCSVRLIB=librpcserver.a
RPCCLTLIB=librpcclient.a

INCLUDES=-I/usr/local/include -I/home/jimmy/usr/local/libevent-2.0.22/include -I/home/jimmy/usr/local/protobuf-2.4.1/include
CCFLAGS=-g

all: Proto $(RPCSVRLIB) $(RPCCLTLIB)

Proto: Rpc.proto
	protoc --cpp_out=./ Rpc.proto

Rpc.pb.o:Rpc.pb.cc
	c++ $(CCFLAGS) $(INCLUDES) -o $@ -c $<

%.o:%.cpp
	c++ $(CCFLAGS) $(INCLUDES) -o $@ -c $<


$(RPCSVRLIB): Proto RpcServer.o ServiceMgr.o Common.o Rpc.pb.o
	ar cru $(RPCSVRLIB) RpcServer.o ServiceMgr.o Common.o Rpc.pb.o

$(RPCCLTLIB): Proto RpcClient.o RpcChannel.o Common.o
	ar cru $(RPCCLTLIB) RpcClient.o RpcChannel.o Common.o Rpc.pb.o

clean:
	-rm *.o $(RPCCLTLIB) $(RPCSVRLIB) *.pb.h *.pb.cc *.a
