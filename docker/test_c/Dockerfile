FROM alpine:3.17.0 AS build
WORKDIR /my_dir
COPY code /my_dir/ 
#instalare ce este necesar pt compilatorul gcc
RUN apk add build-base 
#instalare utilitar make
RUN apk add make 
RUN make