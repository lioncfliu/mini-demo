#pragma once
#include <memory>

class View
{
public:
    View();
    ~View();
    View(View&& v);
    View& operator=(View&& v);
    void display();
private:
    class Impl;
    std::unique_ptr<Impl> pimpl; 
};
