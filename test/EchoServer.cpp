#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <iostream>

#include "rpc_server.h"

#include "Echo.pb.h"

using namespace PBRPC;

class EchoServiceImpl : public EchoService {
public:
	EchoServiceImpl() {
    }

	virtual void echo(::google::protobuf::RpcController* controller,
                       const ::EchoRequest* request,
                       ::EchoResponse* response,
                       ::google::protobuf::Closure* done) {

		std::string result = "";
        std::string tmp = request->text();

		for (int i = 0; i < request->times(); i++)
			result += (" " + tmp);
		response->set_text(result);
		response->set_result(true);
	}
};
  


int main(int argc, char *argv[]) {
	EchoServiceImpl *impl = new EchoServiceImpl();
	RpcServer rpc_server;
	rpc_server.RegisterService(impl);
	rpc_server.Start();
	return 0;
}


