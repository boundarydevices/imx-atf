#!/bin/sh
rm -fr build
make PLAT=imx8mm BUILD_BASE=build bl31
cp -v build/imx8mm/release/bl31.bin ~/u-boot-imx6/bl31-iMX8MM.bin

rm -fr build
make PLAT=imx8mn BUILD_BASE=build bl31
cp -v build/imx8mn/release/bl31.bin ~/u-boot-imx6/bl31-iMX8MN.bin

rm -fr build
make PLAT=imx8mp BUILD_BASE=build bl31
cp -v build/imx8mp/release/bl31.bin ~/u-boot-imx6/bl31-iMX8MP.bin

rm -fr build
make PLAT=imx8mq BUILD_BASE=build bl31
cp -v build/imx8mq/release/bl31.bin ~/u-boot-imx6/bl31-iMX8MQ.bin

rm -fr build-optee
make PLAT=imx8mm BUILD_BASE=build-optee SPD=opteed bl31
cp -v build-optee/imx8mm/release/bl31.bin ~/u-boot-imx6/bl31-tee-iMX8MM.bin

rm -fr build-optee
make PLAT=imx8mn BUILD_BASE=build-optee SPD=opteed bl31
cp -v build-optee/imx8mn/release/bl31.bin ~/u-boot-imx6/bl31-tee-iMX8MN.bin

rm -fr build-optee
make PLAT=imx8mp BUILD_BASE=build-optee SPD=opteed bl31
cp -v build-optee/imx8mp/release/bl31.bin ~/u-boot-imx6/bl31-tee-iMX8MP.bin

rm -fr build-optee
make PLAT=imx8mq BUILD_BASE=build-optee SPD=opteed bl31
cp -v build-optee/imx8mq/release/bl31.bin ~/u-boot-imx6/bl31-tee-iMX8MQ.bin

chmod a-x ~/u-boot-imx6/bl31-*.bin
