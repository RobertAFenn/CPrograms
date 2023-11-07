//
// Buffered IO Example
//
// This program first defines struct pirate and then declares two variables of
// that type. The program initializes one of the variables and subsequently
// writes it out to disk via an output stream to the file data. Via a different
// stream, the program reads the data back
// in from data directly to the other instance of struct pirate.
// Finally, the program writes the contents of the structure to standard out
//
// Created by Rodney Ulrich on 10/3/16.
// Copyright © 2016 Rodney Ulrich. All rights reserved.
//
//
#include <stdio.h>

int main(void) {
  FILE *in, *out;

  // ! Define a structure named pirate
  struct pirate {
    char name[100];         // real name
    unsigned long booty;    // in pounds sterling
    unsigned int beard_len; // in inches
  } p, blackbeard = {
           "Edward Teach", 950,
           48}; // Declare variables p and blackbeard of the pirate structure

  // Open a file named "data" for writing
  out = fopen("data", "w");

  // * Check for errors

  // Check if the file opening operation was successful
  if (!out) {
    perror("fopen");
    return 1; // Exit the program with an error code
  }

  // Write the contents of blackbeard structure to the file
  if (!fwrite(&blackbeard, sizeof(struct pirate), 1, out)) {
    perror("fwrite");
    return 1; // Exit the program with an error code
  }

  // Close the file
  if (fclose(out)) {
    perror("fclose");
    return 1; // Exit the program with an error code
  }

  // Open the "data" file for reading
  in = fopen("data", "r");

  // Check if the file opening operation was successful
  if (!in) {
    perror("fopen");
    return 1; // Exit the program with an error code
  }

  // Read the contents of the file into the p structure
  if (!fread(&p, sizeof(struct pirate), 1, in)) {
    perror("fread");
    return 1; // Exit the program with an error code
  }

  // Close the file
  if (fclose(in)) {
    perror("fclose");
    return 1; // Exit the program with an error code
  }

  // * No more errors to check

  // Print the values from the p structure
  printf("name=\"%s\" booty=%lu beard_len=%u\n", p.name, p.booty, p.beard_len);

  return 0; // Exit the program with a success code
}
