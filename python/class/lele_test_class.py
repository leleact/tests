#!/usr/bin/env python
#-*- coding:utf-8 -*-

class TestClass:
    def __init__(self, m, n):
        self.m = m
        self.n = n

    def show(self):
        print ('m={}, n={}'.format(self.m, self.n))



if __name__ == '__main__':
    c = TestClass(1, 2)
    c.show();
