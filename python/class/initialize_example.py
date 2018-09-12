#! /bin/env python

class D:
    def __init__(cls, name, age):
        print("=========__INIT__================>{}".format(__name__))
        cls.name = name
        cls.age = age

    def __new__(cls, name, age):
        print("=========__NEW__==============>{}".format(__name__))
        """
            如果 __new__ 不创建或 不返回对象 __init__ 方法不会被调用
        """
        self = object.__new__(cls)
        return self


d = D("aa", 10)
