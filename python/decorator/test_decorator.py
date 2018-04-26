#!/usr/bin/env python
#-*- coding:UTF-8 -*-

"""
calc 为装饰器, 接受一个函数作为参数, print 相当于拦截了函数, 可以在不改变
原有的函数 Func逻辑的前提下, 对函数扩展
"""

def calc(func):
    def deco_in(*arg, **kw):
        print ('call %s():' % func.__name__)
        return func(*arg, **kw)
    return deco_in

@calc
def Func(num):
    if num == 0:
        return 1
    return num * Func(num - 1)


print ('0!=%d' % Func(0))
print ('1!=%d' % Func(1))
print ('2!=%d' % Func(2))
print ('10!=%d' % Func(10))
