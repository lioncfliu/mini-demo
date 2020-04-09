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

class udp_server 
{
public:
	udp_server(boost::asio::io_context &io_ctx)
		:socket_(io_ctx, udp::endpoint(udp::v4(), 13)) {
		start_receive();
	}
	
private:
	void start_receive() {
		socket_.async_receive_from(
			boost::asio::buffer(receive_buffer_), remote_endpoint_,
			boost::bind(&udp_server::handle_receive, this, 
                boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}
	
	void handle_receive(const boost::system::error_code & error, 
		std::size_t /*bytes_transferred*/) {
		if (! error) {
			boost::shared_ptr<std::string> message(
				new std::string(make_daytime_string()));
			socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
				boost::bind(&udp_server::handle_send, this, message, 
					boost::asio::placeholders::error, 
					boost::asio::placeholders::bytes_transferred));
		
			start_receive();
		}
	}

	void handle_send(boost::shared_ptr<std::string> /*message*/, 
		const boost::system::error_code & /*error*/, 
		size_t /*bytes_transferred*/) {}

	

private:
	udp::socket socket_;
	udp::endpoint remote_endpoint_;
	boost::array<char, 1> receive_buffer_;
};

int main(int argc, char* argv[])
{
    try {
        boost::asio::io_context io_ctx;
		udp_server server(io_ctx);
		io_ctx.run();
	    
    } catch (std::exception& e) {
        std::cerr<< e.what() <<std::endl;
    }
    
    return 0;
}
