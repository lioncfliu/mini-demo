#include <iostream>
#include <boost/asio.hpp>


void print(const boost::system::error_code & /*e*/) 
{	
    std::cout<<"print was called: Hellow World !" <<std::endl;
}

int main(int argc, char* argv[])
{
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    
    t.async_wait(&print);
    io.run();
    
    std::cout<<"timer has expired here!"<<std::endl;
    return 0;
}
