#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

using boost::asio::ip::udp;

std::string make_daytime_string() 
{
    std::time_t now = std::time(0);
    return std::ctime(&now);

}

int main(int argc, char* argv[])
{
    try {
        boost::asio::io_context io_ctx;
	    udp::socket socket(io_ctx, udp::endpoint(udp::v4(), 13));
	    for (;;) {
            boost::array<char, 1>  receive_buffer;
            udp::endpoint remote_endpoint;
            boost::system::error_code error;
            socket.receive_from(boost::asio::buffer(receive_buffer), remote_endpoint);
            
            std::string message =  ::make_daytime_string();
            boost::system::error_code ignored_error;
            socket.send_to(boost::asio::buffer(message), 
                remote_endpoint, 0, ignored_error);
	    }
    } catch (std::exception& e) {
        std::cerr<< e.what() <<std::endl;
    }
    
    return 0;
}
