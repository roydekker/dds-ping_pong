# dds-daemon

## Creating docker image

- Download the latest OpenSplice community edition from www.prismtech.com
- Move OpenSplice tar ball to resources/OpenSpliceDDS-src.tar.gz (NOTE: registration and manual license agreement needed.)
- Build docker image -> `docker build -t dds-pong .`

## Known Issues

 - Still heavily work in progress. Currently the OpenSplice ./configure step fails
 - Seems that git & postfix is needed for ./configure. postfix for cleanup command
