#!/bin/python
import sys 
import argparse

parser = argparse.ArgumentParser(description="Maps field names from one from file to the other")

parser.add_argument("old-fields-file", type=file)
parser.add_argument("new-fields-file", type=file)

parser.parse_args()



