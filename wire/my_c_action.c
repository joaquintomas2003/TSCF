#include <pif_plugin.h>
#include <stdio.h>  // optional, for debug print

int pif_plugin_my_c_action(EXTRACTED_HEADERS_T *headers, MATCH_DATA_T *data) {
    // Access Ethernet header
    PIF_PLUGIN_ethernet_T *eth;

    if (!pif_plugin_hdr_ethernet_present(headers)) {
        return PIF_PLUGIN_RETURN_DROP;
    }

    eth = pif_plugin_hdr_get_ethernet(headers);

    // Very basic operation: set the least significant bit of dst MAC
    eth->dstAddr[5] |= 0x01;

    // Optional debug
    // printf("Extern: modified dst MAC LSB.\n");

    return PIF_PLUGIN_RETURN_FORWARD;
}
