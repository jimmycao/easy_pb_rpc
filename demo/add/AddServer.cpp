#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <iostream>

#include "RpcServer.h"

#include "Add.pb.h"

using namespace PBRPC;

class AddServiceImpl : public AddService {
public:
	AddServiceImpl() {
    }

	virtual void add(::google::protobuf::RpcController* controller,
                       const ::AddRequest* request,
                       ::AddResponse* response,
                       ::google::protobuf::Closure* done) {
        int input = request->input();
		int result = input + 1;
		response->set_result(result);
	}
};
  


int main(int argc, char *argv[]) {
	AddServiceImpl *impl = new AddServiceImpl();
	RpcServer rpc_server;
	rpc_server.RegisterService(impl);
	rpc_server.Start();
	return 0;
}


