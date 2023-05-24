cmake_minimum_required(VERSION 3.20)
project(loggerc LANGUAGES C)
add_library(${PROJECT_NAME} SHARED logger.c)
add_library(${PROJECT_NAME}_static STATIC logger.c)