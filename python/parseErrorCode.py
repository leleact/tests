#! /usr/bin/env python
#-*- coding:UTF-8 -*-
filename = "errorcode.txt"
fileout = "retcd.txt"
filestat = "stat.txt"
filequery = "query.txt"
fw = open(fileout, "w+")
fs = open(filestat, "w+")
fq = open(filequery, "w+")
with open(filename, "r+") as fr:
    for line in fr:
        line = line.strip('\n')
        strings = line.split(',')
        if len(strings) != 5:
            raise Exception("column number syntax error")
        fw.write("<entry key=\""+ strings[0] +"\" value=\"" + strings[2] +"\" />\n")
        fs.write("<entry key=\""+ strings[0] +"\" value=\"" + strings[3] +"\" />\n")
        fq.write("<entry key=\""+ strings[0] +"\" value=\"" + strings[4] +"\" />\n")
    # 不需要close
    fr.close
fw.close
fs.close
fq.close
