# NetPractice - Network Configuration

## 📖 Description

NetPractice is a network administration exercise where you configure small-scale networks. You'll work with TCP/IP addressing, subnetting, routing, and network troubleshooting. This project teaches essential networking concepts and practical network configuration skills.

## 🎯 Objectives

- Understand TCP/IP networking fundamentals
- Learn subnetting and CIDR notation
- Master routing table configuration
- Practice network troubleshooting
- Apply networking concepts to real-world scenarios

## 🌐 Network Concepts Covered

### IP Addressing
- **IPv4 Addressing**: Understanding 32-bit addressing
- **Address Classes**: Class A, B, C networks
- **Private vs Public**: RFC 1918 private address ranges
- **Broadcast Addresses**: Network and broadcast calculations

### Subnetting
- **Subnet Masks**: Understanding network and host portions
- **CIDR Notation**: Classless Inter-Domain Routing
- **Variable Length Subnet Masking (VLSM)**: Efficient IP allocation
- **Subnet Calculations**: Network size and host count

### Routing
- **Default Gateway**: Route to external networks
- **Routing Tables**: Path determination
- **Static Routes**: Manual route configuration
- **Route Priority**: Metric and administrative distance

## 🏗 Project Structure

```
NetPractice/
├── level1.json            # Basic IP configuration
├── level2.json            # Subnet masks
├── level3.json            # Multiple subnets
├── level4.json            # Routing introduction
├── level5.json            # Complex routing
├── level6.json            # VLSM exercises
├── level7.json            # Advanced subnetting
├── level8.json            # Multi-router scenarios
├── level9.json            # Complex network topologies
└── level10.json           # Advanced troubleshooting
```

## 📊 Level Progression

### Levels 1-3: Basic Networking
- **Level 1**: Simple point-to-point connections
- **Level 2**: Basic subnet configuration
- **Level 3**: Multiple devices on same subnet

### Levels 4-6: Routing Fundamentals
- **Level 4**: Introduction to routing between subnets
- **Level 5**: Multi-hop routing scenarios
- **Level 6**: VLSM and efficient IP allocation

### Levels 7-10: Advanced Concepts
- **Level 7**: Complex subnet hierarchies
- **Level 8**: Multiple router configurations
- **Level 9**: Network troubleshooting scenarios
- **Level 10**: Enterprise-level network design

## 🔧 Key Networking Concepts

### IP Address Structure
```
192.168.1.1/24
│││││││││└─ Host part (8 bits)
│││││││└── Network part (24 bits)
└─────── IP Address (32 bits total)
```

### Subnet Mask Formats
| CIDR | Decimal Notation | Binary | Hosts |
|------|------------------|--------|-------|
| /24  | 255.255.255.0    | 11111111.11111111.11111111.00000000 | 254 |
| /25  | 255.255.255.128  | 11111111.11111111.11111111.10000000 | 126 |
| /26  | 255.255.255.192  | 11111111.11111111.11111111.11000000 | 62 |
| /27  | 255.255.255.224  | 11111111.11111111.11111111.11100000 | 30 |
| /28  | 255.255.255.240  | 11111111.11111111.11111111.11110000 | 14 |
| /30  | 255.255.255.252  | 11111111.11111111.11111111.11111100 | 2 |

### Private IP Address Ranges
- **Class A**: 10.0.0.0/8 (10.0.0.0 - 10.255.255.255)
- **Class B**: 172.16.0.0/12 (172.16.0.0 - 172.31.255.255)
- **Class C**: 192.168.0.0/16 (192.168.0.0 - 192.168.255.255)

## 🧮 Network Calculations

### Subnet Calculation Examples

#### Example 1: Basic Subnetting
```
Network: 192.168.1.0/24
Required subnets: 4
Required hosts per subnet: 50

Solution:
- Borrow 2 bits for subnetting (2² = 4 subnets)
- New subnet mask: /26 (255.255.255.192)
- Subnets:
  * 192.168.1.0/26 (192.168.1.1 - 192.168.1.62)
  * 192.168.1.64/26 (192.168.1.65 - 192.168.1.126)
  * 192.168.1.128/26 (192.168.1.129 - 192.168.1.190)
  * 192.168.1.192/26 (192.168.1.193 - 192.168.1.254)
```

#### Example 2: VLSM
```
Network: 10.0.0.0/8
Requirements:
- Subnet A: 1000 hosts
- Subnet B: 500 hosts
- Subnet C: 100 hosts
- Subnet D: 50 hosts

Solution:
- Subnet A: 10.0.0.0/22 (1022 hosts)
- Subnet B: 10.0.4.0/23 (510 hosts)
- Subnet C: 10.0.6.0/25 (126 hosts)
- Subnet D: 10.0.6.128/26 (62 hosts)
```

## 🛠 Network Troubleshooting

### Common Issues
1. **Incorrect Subnet Mask**: Host isolation
2. **Missing Default Gateway**: No external connectivity
3. **Overlapping Subnets**: IP conflicts
4. **Incorrect Routing**: Unreachable destinations

### Troubleshooting Steps
1. **Verify IP Configuration**: Check address, mask, gateway
2. **Test Local Connectivity**: Ping devices on same subnet
3. **Test Gateway**: Ping default gateway
4. **Check Routing**: Verify routing table entries
5. **Trace Path**: Use traceroute for multi-hop issues

## 📋 Solution Strategies

### General Approach
1. **Analyze Topology**: Understand network layout
2. **Identify Requirements**: Determine what needs to be configured
3. **Calculate Subnets**: Plan IP allocation efficiently
4. **Configure Interfaces**: Set IP addresses and masks
5. **Set Routes**: Configure routing for connectivity
6. **Verify Connectivity**: Test all required paths

### Common Patterns
- **Point-to-Point Links**: Use /30 subnets (2 hosts)
- **LAN Segments**: Use appropriate subnet size
- **Default Routes**: 0.0.0.0/0 for internet connectivity
- **Static Routes**: Specific destination networks

## 🧪 Practice Exercises

### Exercise 1: Basic Configuration
```
Configure PC1 and PC2 to communicate:
PC1: Interface A1
PC2: Interface B1
Network: 192.168.1.0/24

Solution:
PC1 A1: 192.168.1.1/24
PC2 B1: 192.168.1.2/24
```

### Exercise 2: Router Configuration
```
Network Layout:
PC1 -- Router1 -- Router2 -- PC2

Requirements:
- PC1 subnet: 10.0.1.0/24
- PC2 subnet: 10.0.2.0/24
- Router link: 10.0.0.0/30

Solution:
PC1: 10.0.1.10/24, Gateway: 10.0.1.1
Router1 A1: 10.0.1.1/24
Router1 R1: 10.0.0.1/30
Router2 R2: 10.0.0.2/30
Router2 A1: 10.0.2.1/24
PC2: 10.0.2.10/24, Gateway: 10.0.2.1

Routing:
Router1: 10.0.2.0/24 via 10.0.0.2
Router2: 10.0.1.0/24 via 10.0.0.1
```

## 💡 Key Learning Points

1. **IP Addressing**: Understanding binary and decimal representations
2. **Subnetting**: Efficient network segmentation
3. **Routing**: Path determination and configuration
4. **Network Design**: Scalable and efficient topologies
5. **Troubleshooting**: Systematic problem-solving approach
6. **Real-World Application**: Practical networking skills

## 🔗 Related Technologies

### Network Tools
- **ping**: Test basic connectivity
- **traceroute**: Trace network path
- **netstat**: Display network connections
- **ipconfig/ifconfig**: Interface configuration
- **route**: Routing table management

### Advanced Concepts
- **VLANs**: Virtual network segmentation
- **NAT**: Network Address Translation
- **DHCP**: Dynamic IP allocation
- **DNS**: Domain name resolution
- **Firewalls**: Network security

## 📚 Study Resources

### Books and References
- TCP/IP Illustrated by W. Richard Stevens
- Network+ Certification guides
- Cisco CCNA documentation
- RFC specifications (especially RFC 1918, 1812)

### Online Tools
- Subnet calculators
- Network simulators
- Practice labs
- Cisco Packet Tracer

---

*This project provides essential networking knowledge that forms the foundation for system administration, cybersecurity, and network engineering careers.*
