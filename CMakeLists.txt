cmake_minimum_required(VERSION 3.3)
project(Projet_Azza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

        main.cpp
        CPU.cpp
        CPU.h
        Customer.cpp
        Customer.h
        Database.cpp
        Database.h
        Disk.cpp
        Disk.h
        Graphics.cpp
        Graphics.h
        Laptop.cpp
        Laptop.h
        Memory.cpp
        Memory.h
        Product.cpp
        Product.h
        Seller.cpp
        Seller.h
        Shipper.cpp
        Shipper.h
        Shoes.h
        Shoes.cpp
        Smartwatch.cpp
        Smartwatch.h
        Tshirt.cpp
        Tshirt.h
        )


add_executable(PMM_KAB ${SOURCE_FILES})