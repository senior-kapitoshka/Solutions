#include <iomanip>
#include <cstring>

unsigned char crc8(const unsigned char *pc_block, unsigned int len);

int compose_packet(
          unsigned char*         packet,
    const unsigned int           id_number,
    const unsigned char          state,
    const unsigned long long int scenario_mask,
    const unsigned int           volume,
    const unsigned int           status
) {
    std::ostringstream oss;
    
    oss << static_cast<char>(0x2);
    
    if(id_number > 0xffff) return -1;
    oss 
        << std::setfill('0')
        << std::hex 
        << std::uppercase
        << std::setw(4)
        << id_number;
    
    if(state > 0x7f) return -1;
    oss 
        << std::setfill('0')
        << std::hex
        << std::uppercase
        << std::setw(2)
        << static_cast<int>(state);
        
    if(scenario_mask > 0xffffffffffff) return -1;
    oss
        << std::setfill('0')
        << std::hex
        << std::uppercase
        << std::setw(12)
        << scenario_mask;
    
    if(volume > 999999) return -1;
    oss
        << std::setfill('0')
        << std::dec
        << std::setw(6)
        << volume;
    
    if(0xff > status || status > 0xffff) return -1;
    oss
        << std::setfill('0')
        << std::hex
        << std::uppercase
        << std::setw(4)
        << status;
    
    oss << static_cast<char>(0x3);
    oss << static_cast<char>(crc8(
        reinterpret_cast<const unsigned char*>(oss.str().c_str()) + 1,
        28
    ));
        
    memcpy(packet, reinterpret_cast<const unsigned char*>(oss.str().c_str()), 31);
    
    return 1;
}

/////////////////

#include <iomanip>
#include <cstring>

unsigned char crc8(const unsigned char *pc_block, unsigned int len);

int compose_packet(unsigned char* packet, const unsigned int id_number, const unsigned char state,
                   const unsigned long long int scenario_mask, const unsigned int volume, 
                   const unsigned int status) {
  
    if (id_number > 0xffff || state > 0x7f || scenario_mask > 0xffffffffffff || volume > 999999 || 
        0xff > status || status > 0xffff) return -1;

    std::ostringstream ss;
    
    ss << static_cast<char>(0x2);
    ss << std::setfill('0') << std::hex << std::uppercase << std::setw(4) << id_number;
    ss << std::setw(2) << static_cast<int>(state);
    ss << std::setw(12) << scenario_mask;
    ss << std::dec << std::setw(6) << volume;
    ss << std::hex << std::setw(4) << status;
    ss << static_cast<char>(0x3);
    ss << static_cast<char>(crc8(reinterpret_cast<const unsigned char*>(ss.str().c_str()) + 1, 28));
        
    memcpy(packet, reinterpret_cast<const unsigned char*>(ss.str().c_str()), 31);
    
    return 1;
}

/////////////////////
unsigned char crc8(const unsigned char *pc_block, unsigned int len); // this function is already implemented, use it

int compose_packet(unsigned char *packet, unsigned int id_number, unsigned char state, unsigned long long int scenario_mask,
                   unsigned int volume, unsigned int status) {
    if (id_number > 0xffff || state > 0x7f || scenario_mask > 0xffffffffffff || volume > 999999 || status > 0xffff ||
        status < 0xff)
        return -1;
    packet[0] = 0x02;
    sprintf((char *)(packet + 1), "%04X", id_number);
    sprintf((char *)(packet + 5), "%02X", state);
    sprintf((char *)(packet + 7), "%012llX", scenario_mask);
    sprintf((char *)(packet + 19), "%06d", volume);
    sprintf((char *)(packet + 25), "%04X", status);
    packet[29] = 0x03;
    packet[30] = crc8(packet+1, 28);
    return 1;
}

///////////////////////////
using namespace std;
#include <cstdio>

unsigned char crc8(const unsigned char *pc_block, unsigned int len);

int compose_packet(unsigned char *packet, unsigned int id_number, unsigned char state,
                   unsigned long long int scenario_mask, unsigned int volume, unsigned int status)
{
    if (id_number>0xffff || state>0x7f || scenario_mask>0xffffffffffff || volume>999999 || status<0xff || status>0xffff) return -1;
    snprintf((char *)packet,31,"\x2%04X%02X%012llX%06d%04X\x3",id_number,state,scenario_mask,volume,status);
    packet[30] = crc8(packet+1,28);
    return 1;
}