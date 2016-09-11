#include <stdio.h>
#include <stdlib.h>

#include "RpcChannel.h"
#include "RpcController.h"

#include "Add.pb.h"

using namespace PBRPC;

int main(int argc, char *argv[]) {
	RpcClient client;
	RpcChannel channel(&client, "127.0.0.1:18669");
	AddService::Stub stub(&channel);

	AddRequest request;
	request.set_input(1);

	AddResponse response;
	RpcController controller;
	stub.add(&controller, &request, &response, NULL);

	if (controller.Failed()) {
		printf("failed,  %s\n", controller.ErrorText().c_str());
	} else {
		printf("Response is %d\n", response.result());
    }

	return 0;
}
