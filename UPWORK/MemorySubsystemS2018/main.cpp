/*
 * COMP3361 Operating Systems 
 * Lab 2 Sample Solution
 * 
 * File:   main.cpp
 * Author: Mike Goss <mikegoss@cs.du.edu>
 *
 */

#include <inttypes.h>
#include "Process.h"
#include <cstdlib>
#include <iostream>

/*
 * 
 */
int main(int argc, char** argv) {
  // Use command line argument as file name
  if (argc != 2) {
    std::cerr << "usage: Lab2 trace_file\n";
    exit(1);
  }
  
  Process trace(argv[1]);
  trace.Run();
  return 0;
}

