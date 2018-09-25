#!/bin/python
import argparse

parser = argparse.ArgumentParser(description="Maps field names from one file to another")

parser.add_argument("old_fields_file")
parser.add_argument("new_fields_file")

args = parser.parse_args()
old_fields = open(args.old_fields_file, "r").read().splitlines()
new_fields = open(args.new_fields_file, "r").read().splitlines()

mapping = {}

for old_field in old_fields:
    mapping[old_field] = "N/A"
    for new_field in new_fields:
        if new_field.find(old_field) != -1:
            mapping[old_field] = new_field
            break

#print(mapping)


for k,v in mapping.items():
    print(k + ", " + v)









