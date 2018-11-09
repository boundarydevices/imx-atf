#!/bin/sh
touch plat/freescale/imx8mq/ddr/lpddr4_ddrc_cfg.c
make PLAT=imx8mq CONFIG_DDR_MB=2048 all
cp -v build/imx8mq/release/bl31.bin ../imx-mkimage/iMX8M/bl31_2g.bin

touch plat/freescale/imx8mq/ddr/lpddr4_ddrc_cfg.c
make PLAT=imx8mq CONFIG_DDR_MB=3072 all
cp -v build/imx8mq/release/bl31.bin ../imx-mkimage/iMX8M/bl31_3g.bin

touch plat/freescale/imx8mq/ddr/lpddr4_ddrc_cfg.c
make PLAT=imx8mq CONFIG_DDR_MB=4096 all
cp -v build/imx8mq/release/bl31.bin ../imx-mkimage/iMX8M/bl31_4g.bin

