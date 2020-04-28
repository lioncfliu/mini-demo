#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string() 
{
    std::time_t now = std::time(0);
    return std::ctime(&now);

}

int main(int argc, char* argv[])
{
    try {
        
        boost::asio::io_context io_ctx;
        tcp::acceptor acceptor(io_ctx, tcp::endpoint(tcp::v4(), 13));
        
        for (;;) {
            tcp::socket socket(io_ctx);
            acceptor.accept(socket);

            std::string message = make_daytime_string();
            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    } catch (std::exception& e) {
        std::cerr<< e.what() <<std::endl;
    }
    
    return 0;
}
