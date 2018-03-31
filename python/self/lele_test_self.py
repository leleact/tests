#!/usr/bin/env python
#-*- coding:utf-8 -*-

class T_Self:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):
        print("name:{}, age:{}".format(self.name, self.age))

    @staticmethod
    def show1():
        print("xx")


if __name__ == '__main__':
    t = T_Self("中", 18)
    t.show()
    t.show1()
