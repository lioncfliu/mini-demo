#include <iostream>
#include <string>
#include "View.h"


class View::Impl {
    std::string name;
public:
    Impl();
    void printName();
};

View::Impl::Impl(){
    name = "DefaultName";
}

void View::Impl::printName(){
    std::cout << "this is my name:" << name;
}


View::View():pimpl(std::make_unique<Impl>()){
}

View::~View() = default;
View::View(View&& v) = default;
View& View::operator = (View&& v) = default;

void View::display(){
    pimpl->printName();
}
