#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "rpc_channel.h"
#include "rpc_controller.h"

#include "PServer.pb.h"

using namespace PBRPC;


/*
void FooDone(PullResponse *response, RpcController *controller) {
	if (controller->Failed()) {
		printf("test 2 Rpc Failed : %s\n", controller->ErrorText().c_str());
	} else {
		printf("++++++ test 2 Rpc Response is %s\n", response->text().c_str());
	}

	delete response;
	delete controller;
}
*/

int main(int argc, char *argv[]) {
	RpcClient client;
	RpcChannel channel(&client, "127.0.0.1:18669");
	PServerService::Stub stub(&channel);

	PullResponse response;
	RpcController controller;

	PullRequest request;
	request.set_key(123);

	stub.pull(&controller, &request, &response, NULL);

	if (controller.Failed()) {
		printf("1 Rpc Call Failed : %s\n", controller.ErrorText().c_str());
	} else {
		const ::FeatureValue& fv = response.fv();
		std::cout << "slot:" << fv.slot() << "\n";
		std::cout << "silent_days:" << fv.silent_days() << "\n";
		std::cout << "delta_score:" << fv.delta_score() << "\n";
		std::cout << "cvm_show:" << fv.cvm_show() << "\n";
		std::cout << "cvm_clk:" << fv.cvm_clk() << "\n";
		std::cout << "basic_lr_w:" << fv.basic_lr_w() << "\n";
		std::cout << "basic_lr_g2sum:" << fv.basic_lr_g2sum() << "\n";
		std::cout << "lr_w:" << fv.lr_w() << "\n";
		std::cout << "lr_g2sum:" << fv.lr_g2sum() << "\n";
		const ::google::protobuf::RepeatedField< float >& mf_w_s = fv.mf_w();
		std::cout << "mf_w.size():" << mf_w_s.size() << "\n"; 
		std::cout << "mf_g2sum:" << fv.mf_g2sum() << "\n";
		std::cout << "version:" << fv.version() << "\n";												
	}
	sleep(3);
	return 0;
}
