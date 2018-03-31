#include <iostream>
#include <fstream>
#include <memory>
#include <cstring>
#include <stdlib.h>
#include <getopt.h>
#include "socket.hpp"

void print_use(int argc, char *argv[]);

enum {
    STDOUT,
    FILEOUT
};

struct environment {

    std::string bind_addr = "0.0.0.0";
    int bind_port = 8080;
    int output_mode = STDOUT;
    std::string file_path = "./";
    std::string file_name = "outout.txt";

};

class output_wrapper {
    friend std::ostream& operator<<(std::ostream& , const output_wrapper& wrap) {
        return *wrap.m_os_Ptr;
    }
public:
    output_wrapper(const environment &env) : m_env(env) {
        if (env.output_mode == FILEOUT) {
            m_os_Ptr = new std::ofstream(env.file_path + env.file_name, std::ostream::app|std::ostream::out);
        } else {
            m_os_Ptr = &std::cout;
        }
    }

    ~output_wrapper() {
        if (m_env.output_mode == FILEOUT) {
            std::ofstream *fs_ptr = dynamic_cast<std::ofstream *>(m_os_Ptr);
            fs_ptr->close();
            delete fs_ptr;
        }
    }

private:
    const environment &m_env;
    std::ostream *m_os_Ptr;

    output_wrapper(const output_wrapper&) = delete;
    output_wrapper& operator=(const output_wrapper&) = delete;
};

int main(int argc, char **argv) {
    environment env;
    static struct option long_options[] = {
        {"bind-addr",   required_argument, 0,  0 },
        {"bind-port",   required_argument, 0,  0 },
        {"output-mode", required_argument, 0,  0 },
        {"file-path",   required_argument, 0,  0 },
        {"file-name",   required_argument, 0,  0 },
        {0,             0,                 0,  0 }
    };

    int option_index = 0;
    while (1) {
        char c = getopt_long(argc, argv, "", long_options, &option_index );
        if (c == -1) {
            break;
        }
        switch(c) {
            case  0:
                if (strcmp(long_options[option_index].name, "bind-addr") == 0) {
                    if (optarg) {
                        env.bind_addr =  (char *)optarg;
                    }
                } else if (strcmp(long_options[option_index].name, "bind-port") == 0) {
                    if (optarg) {
                        env.bind_port = atoi(optarg);
                    }
                } else if (strcmp(long_options[option_index].name, "output-mode") == 0) {
                    char * mode = (char *)optarg;
                    if (strcmp(mode, "STDOUT") == 0) {
                        env.output_mode = STDOUT;
                    } else if (strcmp(mode, "FILEOUT") == 0) {
                        env.output_mode = FILEOUT;
                    } else {

                    }
                } else if (strcmp(long_options[option_index].name, "file-path") == 0) {
                    if (optarg) {
                        env.file_path = (char *)optarg;
                    }
                } else if (strcmp(long_options[option_index].name, "file-name") == 0) {
                    if (optarg) {
                        env.file_name = (char *)optarg;
                    }
                }
                break;
            case '?' :
                break;
            default:
                printf("?? getopt returned character code 0%o ??\n", c);

        }
    }

    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while(optind < argc) {
            printf("%s ", argv[optind++]);
        }
        printf("\n");
    }

    // 准备socket
    varlib::socket sock;
    sock.bind(env.bind_addr, env.bind_port);
    output_wrapper wrap(env);

    while(1) {
        std::string data;
        std::string remote_addr;
        int remote_port;
        ssize_t n = sock.recvfrom(data, remote_addr, remote_port);
        if (n == -1) {
            std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") "
                << __PRETTY_FUNCTION__ << " recvfrom error, errno:[" << errno
                << "][" << strerror(errno) << "]" << std::endl;
        }

        std::cout << wrap << "(" << __FILE__ << ":" << __LINE__ << ") "
            << __PRETTY_FUNCTION__ << " recv [" << n << "] bytes ["
            << data << "] from [" << remote_addr << ":" << remote_port << "]"
            << std::endl;
        n = sock.sendto(data, remote_addr, remote_port);
        if (n == -1) {
            std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") "
                << __PRETTY_FUNCTION__ << " sendto error, errno[" << errno
                << "][" << strerror(errno) << "]" << std::endl;
        }
        std::cout << wrap << "(" << __FILE__ << ":" << __LINE__ << ") "
            << __PRETTY_FUNCTION__ << " send [" << n << "] bytes [" << data
            << "] to [" << remote_addr << ":" << remote_port << "]" << std::endl;
    }

    return 0;
}

void print_use(int argc, char *argv[]) {
    //std::cout << "Use " << argv[0] << " [listen-port]" << std::endl;
}
