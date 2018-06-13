``` bash
openssl genrsa -aes256 -out private_key.key 4096
openssl rsa -pubout -in private_key.key -outform PEM -out public_key.pem
```
