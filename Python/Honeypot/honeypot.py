#blackbox.ai generated

#https://learn.microsoft.com/en-us/windows/win32/winsock/sio-rcvall
#https://learn.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-inet_ntoa
#https://en.wikipedia.org/wiki/Internet_Protocol_version_4#Header
#https://docs.python.org/3/library/struct.html

#permission issue? cannot run though

'''
//struct ipheader {
 unsigned char ip_hl:4, ip_v:4; /* this means that each member is 4 bits */
 unsigned char ip_tos;
 unsigned short int ip_len;
 unsigned short int ip_id;
 unsigned short int ip_off;
 unsigned char ip_ttl;
 unsigned char ip_p;
 unsigned short int ip_sum;
 unsigned int ip_src;
 unsigned int ip_dst;
}; 
'''

'''
!: This specifies that the byte order is big-endian. Network byte order is always big-endian, which means the most significant byte is stored first. This is important for interpreting multi-byte numbers correctly across different systems that may use different byte orders natively.

B: Unsigned char (1 byte). The first B is for the version and IHL (Internet Header Length) fields, which are packed into a single byte. The version is the first 4 bits, and the IHL is the last 4 bits of this byte.

B: Unsigned char (1 byte). This represents the Type of Service (ToS) field, which is used to specify how an IP packet should be handled.

H: Unsigned short (2 bytes). This is for the Total Length field, indicating the entire packet size, including header and data, in bytes.

H: Unsigned short (2 bytes). This represents the Identification field, used in fragmentation.

H: Unsigned short (2 bytes). This is for the Flags and Fragment Offset fields. The Flags are the first 3 bits, and the Fragment Offset occupies the remaining 13 bits. Together, they are used to manage packet fragmentation.

B: Unsigned char (1 byte). This is the Time To Live (TTL) field, which limits the lifespan of a packet in the network to prevent it from circulating indefinitely.

B: Unsigned char (1 byte). This represents the Protocol field, which indicates the next level protocol used in the data portion of the IP packet.

H: Unsigned short (2 bytes). This is for the Header Checksum, a checksum used for error-checking the header.

4s: Four-byte string. This represents the Source IP Address. It's treated as a string of 4 bytes, which matches the size of an IPv4 address.

4s: Four-byte string. This is for the Destination IP Address, formatted the same way as the Source IP Address.
'''


import socket
import datetime
import struct

def log_nmap_scan(source_ip):
    with open("nmap_scans.log", "a") as log_file:
        log_file.write(f"Nmap scan detected from {source_ip} at {datetime.datetime.now()}\n")

def monitor_network():
    sock = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_IP)
    sock.bind(("", 0))
    sock.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)
    sock.ioctl(socket.SIO_RCVALL, socket.RCVALL_ON)

    try:
        while True:
            packet = sock.recvfrom(65565)[0]
            ip_header = packet[0:20]
            iph = struct.unpack("!BBHHHBBH4s4s", ip_header)

            version_ihl = iph[0]
            version = version_ihl >> 4
            ihl = version_ihl & 0xF

            iph_length = ihl * 4
            total_length = iph[2]
            identification = iph[3]
            flags_fo = iph[4]
            fragment_offset = flags_fo & 0x1FFF
            ttl = iph[5]
            protocol = iph[6]
            checksum = iph[7]
            source_ip = socket.inet_ntoa(iph[8])
            destination_ip = socket.inet_ntoa(iph[9])

            if protocol == 17: # Protocol 17 is UDP, which Nmap often uses
                udp_header = packet[iph_length:iph_length+8]
                udph = struct.unpack("!HHHH", udp_header)

                source_port = udph[0]
                destination_port = udph[1]

                if destination_port == 11211: # Nmap often scans for port 11211 (Memcached)
                    log_nmap_scan(source_ip)

    finally:
        sock.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)

if __name__ == "__main__":
    monitor_network()
