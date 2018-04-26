#! /usr/bin/env python

#-*- coding:UTF-8 -*-

filename = "meta-data.txt"

with open(filename, "r+") as fr:
    for line in fr:
        line = line.strip('\n')
        strings = line.split()
        print strings
