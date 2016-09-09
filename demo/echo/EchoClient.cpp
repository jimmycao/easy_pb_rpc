#include <stdio.h>
#include <stdlib.h>

#include "RpcChannel.h"
#include "RpcController.h"

#include "Echo.pb.h"

using namespace PBRPC;

void echo_response_process_cb(EchoResponse *response, RpcController *controller) {
	if (controller->Failed()) {
		printf("test 2 Rpc Failed : %s\n", controller->ErrorText().c_str());
	} else {
		printf("test 2 Rpc Response is %s\n", response->text().c_str());
	}

	delete response;
	delete controller;
}

int main(int argc, char *argv[]) {
	RpcClient client;
	RpcChannel channel(&client, "127.0.0.1:18669");
	EchoService::Stub stub(&channel);

	EchoRequest request;
	request.set_text("hello");
	request.set_times(1);

	EchoResponse response;
	RpcController controller;
	stub.echo(&controller, &request, &response, NULL);

	if (controller.Failed()) {
		printf("hello 1 Failed : %s\n", controller.ErrorText().c_str());
	} else {
		printf("hello 1 Rpc Response is %s\n", response.text().c_str());
    }


    //------------------------------------------------------
	request.set_text("hello2");
	request.set_times(2);
	EchoResponse *response2 = new EchoResponse;
	RpcController *controller2 = new RpcController;
	stub.echo(controller2, 
            &request, 
            response2, 
            google::protobuf::NewCallback(&echo_response_process_cb, response2, controller2));

	

    //------------------------------------------------------
	request.set_text("hello3");
	request.set_times(3);

	controller.Reset();
	RpcChannel channel2(&client, "127.0.0.1:18669");

	EchoService::Stub stub2(&channel2);
	stub2.echo(&controller, &request, &response, NULL);

	if (controller.Failed()) {
		printf("echo 3 Rpc Call Failed : %s\n", controller.ErrorText().c_str());
	} else {
		printf("echo 3 Rpc Response is %s\n", response.text().c_str());
	}

	sleep(1);

	return 0;
}
