#!/bin/env python
# -*- coding: utf-8 -*-

if __name__ == '__main__':
    name = "乐乐"
    age = 18
    print "My name is {}, my age is {}\n".format(name, age)
    print "My name is {var1}, my age is {var2}\n".format(var1=name, var2=age)
    print "My name is %s, my age is %d\n" % (name, age)
    print ( "My name is {}, my age is {}\n".format(name, age) )
