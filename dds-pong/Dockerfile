#                                                                                                                                                                                                                  
# Licensed under Apache License v2. See LICENSE for more information.
#

# 
# dds-ping (OpenSplice) docker image 

FROM ubuntu:14.04
MAINTAINER Pepijn Noltes <pepijnnoltes@gmail.com> 

# Generic update & tooling
ENV DEBIAN_FRONTEND noninteractive
ENV http_proxy=http://10.160.64.104:8080
ENV https_proxy=http://10.160.64.104:8080
RUN apt-get update && apt-get upgrade -yq && apt-get install -yq --no-install-recommends \
  build-essential \
  curl \
  make \
  gdb  \
  git \
  gawk \ 
  postfix \
  && apt-get clean

# Node agent resources
COPY resources /tmp/resources

RUN chmod +wr /tmp/resources/opensplice/x86_64.linux/release.com

RUN cd /tmp/resources && chmod +x opensplice.sh && /tmp/resources/opensplice.sh
RUN cd /tmp/resources && chmod +x pong.sh && /tmp/resources/pong.sh
RUN cd /tmp/resources && . opensplice/x86_64.linux/release.com
RUN cd /tmp/resources && . opensplice/x86_64.linux/release.com && . /tmp/resources/pong/release.com && cd pong/bld && make -f Makefile 

ENTRYPOINT ["/bin/bash", "/tmp/resources/start.sh"]
 

