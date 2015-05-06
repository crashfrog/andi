FROM phusion/baseimage:0.9.12
MAINTAINER Justin Payne, justin.payne@fda.hhs.gov

WORKDIR /tmp/
RUN apt-get update -y \
	&& apt-get install -y \
	wget \
	gcc \
	make \
	cmake \
	g++ \
	git 
	
RUN git clone https://github.com/y-256/libdivsufsort.git \
	&& cd libdivsufort \
	&& mkdir build \
	&& cd build \
	&& cmake -DCMAKE_BUILD_TYPE="RELEASE" \
			 -DCMAKE_INSTALL_PREFIX="/usr/local" .. \
	&& make \
	&& make install \
	&& cd /tmp/
	
RUN git clone https://github.com/crashfrog/andi.git \
	&& cd andi \
	&& ./configure \
	&& make \
	&& make install \
	&& make installcheck
	
ENTRYPOINT /usr/local/bin/andi
	