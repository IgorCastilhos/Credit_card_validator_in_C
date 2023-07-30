cmake_minimum_required(VERSION 3.26)
project(credit_card_validator_program)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(credit_card_validator_program
        credit_card_validator.cpp)
