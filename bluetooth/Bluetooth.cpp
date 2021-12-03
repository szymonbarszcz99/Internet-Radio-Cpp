#include "Bluetooth.h"

void Bluetooth::scan() {
    int sockId, devId;
    devId = hci_get_route(NULL);
    sockId = hci_open_dev(devId);

    if(sockId < 0 || devId < 0){
        std::cout<<"Error opening socket on bluetooth adapter"<<std::endl;
        std::cout<<"Exiting..."<<std::endl;
        return;
    }

    inquiry_info *ii = NULL;
    ii = (inquiry_info*)malloc(255 * sizeof(inquiry_info));
    int numDev = hci_inquiry(devId, 8, 255, NULL, &ii, IREQ_CACHE_FLUSH);
    if(numDev < 0){
        std::cout<<"Inquiry error. Exiting..."<<std::endl;
        return;
    }
    std::cout<<"Found "<<numDev<<" devices. Asking them for names..."<<std::endl;

    char addr[19] = { 0 };
    char name[248] = { 0 };
    for (int i = 0; i < numDev; i++) {
        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));
        if (hci_read_remote_name(sockId, &(ii+i)->bdaddr, sizeof(name),
                                 name, 0) < 0)
            strcpy(name, "[unknown]");
        printf("%s  %s\n", addr, name);
    }

    free( ii );
    close( sockId );
    return;

}
