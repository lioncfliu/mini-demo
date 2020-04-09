#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string() 
{
    std::time_t now = std::time(0);
    return std::ctime(&now);

}

class tcp_connection
    :public boost::enable_shared_from_this<tcp_connection>
{
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_context& io_ctx) {
        return pointer(new tcp_connection(io_ctx));
    }

    tcp::socket& socket() { return socket_; }
    
    void start() {
        message_ = ::make_daytime_string();
        boost::asio::async_write(socket_, boost::asio::buffer(message_),
            boost::bind(&tcp_connection::handle_write, shared_from_this(),
                boost::asio::placeholders::error, 
                boost::asio::placeholders::bytes_transferred));
    }

    ~tcp_connection() {}
    
private:
    tcp_connection(boost::asio::io_context& io_ctx)
        :socket_(io_ctx) {}
    
    
    void handle_write(const boost::system::error_code & /*error*/,
        size_t /*bytes_transferred*/) {}

private:
    tcp::socket socket_;
    std::string message_;
};


class tcp_server 
{
public:
    tcp_server(boost::asio::io_context &io_ctx)
        :io_ctx_(io_ctx)
        ,acceptor_(io_ctx, tcp::endpoint(tcp::v4(), 13)) {
        start_accept();
    }

    ~tcp_server() {}
   
private:
    void start_accept() {

        tcp_connection::pointer new_conn = tcp_connection::create(io_ctx_);
        acceptor_.async_accept(new_conn->socket(), 
            boost::bind(&tcp_server::handle_accept, this, new_conn, 
                boost::asio::placeholders::error));
    } 
    
    void handle_accept(tcp_connection::pointer new_conn, 
         const boost::system::error_code & error) {
        if (! error) new_conn->start();
        start_accept();
    }
    
private:
    boost::asio::io_context &io_ctx_;
    tcp::acceptor acceptor_; 
    
};




int main(int argc, char* argv[])
{
    try {
        
        boost::asio::io_context io_ctx;
        tcp_server server(io_ctx);
        io_ctx.run();
    } catch (std::exception& e) {
        std::cerr<< e.what() <<std::endl;
    }
    
    return 0;
}
