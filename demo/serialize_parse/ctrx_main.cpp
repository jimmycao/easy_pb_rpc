#include "ctrx_weight_item.pb.h"

#include <iostream>

using namespace im::ctrx;

int main() {

    CtrXReserved ctrx_reserved;
    CtrXReserved ctrx_reserved_des;

    ctrx_reserved.add_weight_item(1.0);
    ctrx_reserved.add_weight_item(2.0);
    std::cout << "size:" << ctrx_reserved.weight_item_size() <<  std::endl;

    //serialize to array
    size_t len = sizeof(float) * ctrx_reserved.weight_item_size();
    size_t len = ctrx_reserved.ByteSize();
    char* buf = new char[len];
    ctrx_reserved.SerializeToArray(buf, len);
    std::cout << "byte_size:" << len << std::endl;

    //parse from buf
    char* buf2 = new char[len];
    memcpy(buf2, buf, len);
    ctrx_reserved_des.ParseFromArray(buf2, len);

    std::cout << "size:" << ctrx_reserved_des.weight_item_size() <<  std::endl;
    for (int i = 0; i < ctrx_reserved_des.weight_item_size(); ++i) {
        std::cout << ctrx_reserved_des.weight_item(i) << std::endl;
    }

    delete buf;
    delete buf2;
}
