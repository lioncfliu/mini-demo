#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

int main(int argc, char* argv[])
{
    try {
        if (argc !=2) {

            std::cerr<< "Usage: client <host>" <<std::endl;
            return 1;
        }
        
        boost::asio::io_context io_ctx;
        udp::resolver resolver(io_ctx);
        udp::endpoint receiver_endpoint = 
            *resolver.resolve(udp::v4(), argv[1], "daytime").begin();
        
        udp::socket socket(io_ctx);
        socket.open(udp::v4());
        
        boost::array<char ,1> send_buffer = {{0}};
        socket.send_to(boost::asio::buffer(send_buffer), receiver_endpoint);
        
        boost::array<char, 128> receive_buffer;
        udp::endpoint sender_point;
        size_t len = socket.receive_from(boost::asio::buffer(receive_buffer), sender_point);
        std::cout.write(receive_buffer.data(), len);
    } catch (std::exception& e) {
        std::cerr<< e.what() <<std::endl;
    }
    
    return 0;
}
