生成证书
``` bash
keytool -genkey -alias keyname -keyalg RSA -keysize 2048 -keypass keypasswd -validity 1095 -keystore client_cert.ks -storepass storepasswd
keytool -genkey -alias {desired alias certificate} -keystore {path to keystore.pfx} -storepass {password} -validity 365 -keyalg RSA -keysize 2048 -storetype pkcs12 -sigalg {SHA1WithRSA/SHA256withRSA}
```

导出证书
``` bash
keytool -export -alias keyname -keystore client_cert.ks -file xxx.cer -storepass storepasswd
```
