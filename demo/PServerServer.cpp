#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>

#include "rpc_server.h"
#include "PServer.pb.h"

using namespace PBRPC;

class PServerServiceImpl : public PServerService {
public:
	PServerServiceImpl() {
	}

	virtual void pull(::google::protobuf::RpcController* controller,
					  const ::PullRequest* request,
					  ::PullResponse* response, ::google::protobuf::Closure* done) {
		::google::protobuf::uint32 key = request->key();
		std::cout << "server, key from client:" << key << std::endl;


        
		::FeatureValue* fv = response->mutable_fv();
		fv->set_slot(12345);
		fv->set_silent_days(100);
		fv->set_delta_score(0.01);
		fv->set_cvm_show(1.0);
        
		fv->set_cvm_clk(1.0);
		fv->set_basic_lr_w(0.1);
		fv->set_basic_lr_g2sum(0.1);
		fv->set_lr_w(0.1);
		fv->set_lr_g2sum(0.1);

		fv->add_mf_w(0.1);
		fv->add_mf_w(0.2);

		fv->set_mf_g2sum(0.1);
		fv->set_version(1);
	}
};

int main(int argc, char *argv[]) {
	PServerServiceImpl *impl = new PServerServiceImpl();
	RpcServer rpc_server;
	rpc_server.RegisterService(impl);
	rpc_server.Start();
	return 0;
}


