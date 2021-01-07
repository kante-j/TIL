# 커맨드로만 Laravel과 Oracle 연결
도커로 Laravel에다가 Oracle을 연결해야할 일이 생겼다. 도커로 하려면 커맨드로만 해결해야 하는데 어떻게 했나 보자.
---
#### 먼저 도커 이미지는 php7.4-fpm을 사용했다.
instantclient는 19.9 버전이다.
```dockerfile
FROM phpdockerio/php74-fpm # 도커허브에서 사용
#
# 이부분에서 php 관련 설치를 마친다.
#

WORKDIR /opt/oracle
RUN wget https://download.oracle.com/otn_software/linux/instantclient/199000/instantclient-basic-linux.x64-19.9.0.0.0dbru.zip --no-check-certificate
RUN wget https://download.oracle.com/otn_software/linux/instantclient/199000/instantclient-sqlplus-linux.x64-19.9.0.0.0dbru.zip --no-check-certificate
RUN wget https://download.oracle.com/otn_software/linux/instantclient/199000/instantclient-sdk-linux.x64-19.9.0.0.0dbru.zip --no-check-certificate

RUN unzip instantclient-basic-linux.x64-19.9.0.0.0dbru.zip
RUN unzip instantclient-sdk-linux.x64-19.9.0.0.0dbru.zip
RUN unzip instantclient-sqlplus-linux.x64-19.9.0.0.0dbru.zip

RUN echo /opt/oracle/instantclient_19_9 > /etc/ld.so.conf.d/oracle-instantclient
RUN ldconfig

ENV LD_LIBRARY_PATH=/opt/oracle/instantclient_19_9

RUN pecl channel-update pecl.php.net
RUN echo "instantclient,/opt/oracle/instantclient_19_9" | pecl install oci8-2.2.0

RUN echo "extension =oci8.so" >> /etc/php/7.4/apache2/php.ini
RUN echo "extension =oci8.so" >> /etc/php/7.4/cli/php.ini
RUN echo "extension =oci8.so" >> /etc/php/7.4/fpm/php.ini

RUN echo "export LD_LIBRARY_PATH=/opt/oracle/instantclient_19_9" >> /etc/apache2/envvars
RUN echo "export ORACLE_HOME=/opt/oracle/instantclient_19_9" >> /etc/apache2/envvars

RUN echo "LD_LIBRARY_PATH=/opt/oracle/instantclient_19_9:$LD_LIBRARY_PATH" >> /etc/environment

RUN service php7.4-fpm restart
RUN php -m | grep 'oci8'
```

이렇게 해 주면 성공적으로 설치가 된다.
마지막에 php -m 으로 어떤 모듈이 설치되었는지 확인이 가능한데, oci8이 성공적으로 설치되어 있음을 볼 수 있다.
도커로 설정하는 사람들에게도 도움이 될 것이고, 리눅스 cli에서 설정하는 사람도 도움이 될 것이다.