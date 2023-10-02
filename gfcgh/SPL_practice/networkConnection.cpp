#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Structure to store network connection information
struct NetworkConnection {
    std::string protocol;
    std::string localAddress;
    std::string remoteAddress;
    std::string state;
};

// Function to parse network connections
std::vector<NetworkConnection> parse_network_connections() {
    std::vector<NetworkConnection> connections;
    std::ifstream netstat_output("/proc/net/tcp");

    if (!netstat_output) {
        std::cerr << "Failed to open /proc/net/tcp" << std::endl;
        return connections;
    }

    // Skip the header line
    std::string line;
    std::getline(netstat_output, line);

    while (std::getline(netstat_output, line)) {
        std::istringstream iss(line);
        NetworkConnection connection;
        std::string protocol, local, remote, state;

        // Extract protocol, local and remote addresses, and connection state
        iss >> protocol >> local >> remote >> state;

        connection.protocol = protocol;
        connection.localAddress = local;
        connection.remoteAddress = remote;
        connection.state = state;

        // Filter established connections
        if (state == "01") { // 01 corresponds to ESTABLISHED state
            connections.push_back(connection);
        }
    }

    netstat_output.close();
    return connections;
}

// Function to log network connections to a file
void log_network_connections(const std::vector<NetworkConnection>& connections, const std::string& filename) {
    std::ofstream logfile(filename);

    if (!logfile) {
        std::cerr << "Failed to open the log file for writing" << std::endl;
        return;
    }

    logfile << "Network Connections:" << std::endl;
    for (const NetworkConnection& connection : connections) {
        logfile << "Protocol: " << connection.protocol << std::endl;
        logfile << "Local Address: " << connection.localAddress << std::endl;
        logfile << "Remote Address: " << connection.remoteAddress << std::endl;
        logfile << "State: " << connection.state << std::endl << std::endl;
    }

    logfile.close();
    std::cout << "Network connections logged to " << filename << std::endl;
}

int main() {
    const std::string filename = "network_connections_log.txt";

    // Parse network connections
    std::vector<NetworkConnection> currentConnections = parse_network_connections();

    // Log network connections to the file
    log_network_connections(currentConnections, filename);

    return 0;
}
