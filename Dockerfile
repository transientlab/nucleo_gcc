# parent image
FROM debian:stable-slim AS arm-dev

SHELL ["/bin/bash", "-c"]

# update apt
RUN apt update -qy
RUN apt upgrade -qy

# install tools
RUN apt install build-essential gcc-arm-none-eabi python3 make git -qy

# copy source
RUN mkdir /root/nucleo_gcc
COPY ./ /root/nucleo_gcc
RUN cd /root/nucleo_gcc

# make source
RUN make /root/nucleo_gcc
# RUN sh debug.sh
