#! /bin/env python
# -*- coding:utf-8 -*-

import datetime

now = datetime.datetime.now()
delta = datetime.timedelta(15)

print("{}".format(now - delta))
