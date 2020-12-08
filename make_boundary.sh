#!/bin/sh
if [ -z "$UBOOT_PATH" ]; then UBOOT_PATH=~/u-boot-imx6; fi

buildatf() {
	rm -fr build*
	make PLAT=$1 BUILD_BASE=$2 bl31 -j$(nproc)
	cp -v $2/$1/release/bl31.bin $UBOOT_PATH/$3
}

buildatf imx8mm build bl31-iMX8MM.bin
buildatf imx8mn build bl31-iMX8MQ.bin
buildatf imx8mp build bl31-iMX8MP.bin
buildatf imx8mq build bl31-iMX8MQ.bin
buildatf imx8mm build-optee bl31-tee-iMX8MM.bin
buildatf imx8mn build-optee bl31-tee-iMX8MQ.bin
buildatf imx8mp build-optee bl31-tee-iMX8MP.bin
buildatf imx8mq build-optee bl31-tee-iMX8MQ.bin
chmod a-x $UBOOT_PATH/bl31-*.bin
