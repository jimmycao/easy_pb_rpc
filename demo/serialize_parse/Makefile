INCLUDES=-I../../src -I/home/jimmy/usr/local/libevent-2.0.22/include -I/home/jimmy/usr/local/protobuf-2.4.1/include
LDFLAGS=-lpthread -lprotobuf -levent -L/usr/local/lib -L/home/jimmy/usr/local/libevent-2.0.22/lib -L/home/jimmy/usr/local/protobuf-2.4.1/lib
CFLAGS=-g


all: protoc_run ctrx_main 

protoc_run: ctrx_weight_item.proto
	protoc --cpp_out=./ ctrx_weight_item.proto

ctrx_weight_item.pb.o:ctrx_weight_item.pb.cc
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

%.o:%.cpp
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

ctrx_main: protoc_run ctrx_weight_item.pb.o ctrx_main.o
	c++ $(INCLUDES) -o ctrx_main ctrx_main.o ctrx_weight_item.pb.o $(LDFLAGS) 


clean:
	-rm *_main *.o *.pb.h *.pb.cc
