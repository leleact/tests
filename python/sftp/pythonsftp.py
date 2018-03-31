#!/usr/bin/env python
#-*- coding:utf-8 -*-

import paramiko
paramiko.util.log_to_file('/tmp/paramiko.log')

# Open a transport

host = "11.8.44.25"
port = 9080
transport = paramiko.Transport((host, port))

# Auth

password = "0000100000"
username = "0000100000"
transport.connect(username = username, password = password)

# Go!

sftp = paramiko.SFTPClient.from_transport(transport)

# Download

filepath = '/eod/AUTH20161113'
localpath = '/tmp/AUTH20161113'
sftp.get(filepath, localpath)

# Upload

#filepath = '/home/foo.jpg'
#localpath = '/home/pony.jpg'
#sftp.put(localpath, filepath)

# Close

sftp.close()
transport.close()
