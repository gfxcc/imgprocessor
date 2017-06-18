# imgprocessor - img processor for connectplus

imgprocess can extract and analyze information from images

# Require
* [cppan](https://cppan.org)

```
// Ubuntu 16.04:
sudo apt install cmake
wget https://cppan.org/client/cppan-master-Linux-client.deb
sudo dpkg -i cppan-master-Linux-client.deb
```

* [cmake](https://cmake.org)

```
sudo apt-get install cmake
```

* [libev](http://pod.tst.eu/http://cvs.schmorp.de/libev/ev.pod)  
libev - a high performance full-featured event loop written in C  

```
sudo apt-get install libev-dev
```
* [amqpcpp](https://github.com/CopernicaMarketingSoftware/AMQP-CPP)  
AMQP-CPP is a C++ library for communicating with a RabbitMQ message broker.


# Build

```
git clone https://github.com/gfxcc/imgprocessor.git
cd imgprocessor
cppan
mkdir build; cd build
cmake ..
make
```

# Usage
...



