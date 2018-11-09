/*
 * Copyright (c) 2013-2017, ARM Limited and Contributors. All rights reserved.
 * Copyright 2017-2018 NXP.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <arch_helpers.h>
#include <debug.h>
#include <ddrc.h>
#include <mmio.h>
#include <platform_def.h>
#include <spinlock.h>
#include <soc.h>

#define WR_POST_EXT_3200

#if CONFIG_DDR_MB == 2048
#define VAL_DDRC_RFSHTMG		0x00610090
#define VAL_DDRC_DRAMTMG14		0x00000096
#define VAL_DDRC_FREQ1_RFSHTMG		0x0014001F
#define VAL_DDRC_FREQ1_DRAMTMG14	0x00000020
#define VAL_DDRC_FREQ2_RFSHTMG		0x00030005
#define VAL_DDRC_FREQ2_DRAMTMG14	0x00000005
	/* Address map is from MSB 28: cs, r14, r13-r0, b2-b0, c9-c0 */
#define VAL_DDRC_ADDRMAP0		0x00000016
#define VAL_DDRC_ADDRMAP6		0x0f070707
#elif CONFIG_DDR_MB == 3072
#define VAL_DDRC_RFSHTMG		0x006100E0
#define VAL_DDRC_DRAMTMG14		0x000000E6
#define VAL_DDRC_FREQ1_RFSHTMG		0x0014002F
#define VAL_DDRC_FREQ1_DRAMTMG14	0x00000031
#define VAL_DDRC_FREQ2_RFSHTMG		0x00030007
#define VAL_DDRC_FREQ2_DRAMTMG14	0x00000008
	/* Address map is from MSB 29: r15, r14, cs, r13-r0, b2-b0, c9-c0 */
#define VAL_DDRC_ADDRMAP0		0x00000015
#define VAL_DDRC_ADDRMAP6		0x48080707
#elif CONFIG_DDR_MB == 4096
#define VAL_DDRC_RFSHTMG		0x006100E0
#define VAL_DDRC_DRAMTMG14		0x000000E6
#define VAL_DDRC_FREQ1_RFSHTMG		0x0014002F
#define VAL_DDRC_FREQ1_DRAMTMG14	0x00000031
#define VAL_DDRC_FREQ2_RFSHTMG		0x00030007
#define VAL_DDRC_FREQ2_DRAMTMG14	0x00000008
	/* Address map is from MSB 29: cs, r15, r14, r13-r0, b2-b0, c9-c0 */
#define VAL_DDRC_ADDRMAP0		0x00000017
#define VAL_DDRC_ADDRMAP6		0x07070707
#else
#error unsupported memory size
#endif

static inline void umctl2_addrmap(void)
{
	/* Address mapping */
	/* need be refined for DDR vender */
	mmio_write_32(DDRC_ADDRMAP0(0), VAL_DDRC_ADDRMAP0);
	mmio_write_32(DDRC_ADDRMAP3(0), 0x00000000);
	mmio_write_32(DDRC_ADDRMAP4(0), 0x00001F1F);
	/* bank interleave */
	mmio_write_32(DDRC_ADDRMAP1(0), 0x00080808);
	mmio_write_32(DDRC_ADDRMAP5(0), 0x07070707);
	mmio_write_32(DDRC_ADDRMAP6(0), VAL_DDRC_ADDRMAP6);
}

static inline void umctl2_perf(void)
{
	mmio_write_32(DDRC_ODTCFG(0), 0x0b060908);
	mmio_write_32(DDRC_ODTMAP(0), 0x00000000);
	mmio_write_32(DDRC_SCHED(0), 0x29001505);
	mmio_write_32(DDRC_SCHED1(0), 0x0000002c);
	mmio_write_32(DDRC_PERFHPR1(0), 0x5900575b);
	mmio_write_32(DDRC_PERFLPR1(0), 0x90000096);
	mmio_write_32(DDRC_PERFWR1(0), 0x1000012C);
	mmio_write_32(DDRC_DBG0(0), 0x00000016);
	mmio_write_32(DDRC_DBG1(0), 0x00000000);
	mmio_write_32(DDRC_DBGCMD(0), 0x00000000);
	mmio_write_32(DDRC_SWCTL(0), 0x00000001);
	mmio_write_32(DDRC_POISONCFG(0), 0x00000011);
	mmio_write_32(DDRC_PCCFG(0), 0x00000111);
	mmio_write_32(DDRC_PCFGR_0(0), 0x000010f3);
	mmio_write_32(DDRC_PCFGW_0(0), 0x000072ff);
	mmio_write_32(DDRC_PCTRL_0(0), 0x00000001);
	mmio_write_32(DDRC_PCFGQOS0_0(0), 0x00000E00);
	mmio_write_32(DDRC_PCFGQOS1_0(0), 0x0062FFFF);
	mmio_write_32(DDRC_PCFGWQOS0_0(0), 0x00000E00);
	mmio_write_32(DDRC_PCFGWQOS1_0(0), 0x0000FFFF);
}

static inline void umctl2_freq1(void)
{
	mmio_write_32(DDRC_FREQ1_DERATEEN(0), 0x00000001);
	mmio_write_32(DDRC_FREQ1_DERATEINT(0), 0x00518B00);
	mmio_write_32(DDRC_FREQ1_RFSHCTL0(0), 0x0020D040);
	mmio_write_32(DDRC_FREQ1_RFSHTMG(0), VAL_DDRC_FREQ1_RFSHTMG);
	mmio_write_32(DDRC_FREQ1_INIT3(0), 0x00940009);
	mmio_write_32(DDRC_FREQ1_INIT4(0), 0x00310008);
	mmio_write_32(DDRC_FREQ1_INIT6(0), 0x0066004A);
	mmio_write_32(DDRC_FREQ1_INIT7(0), 0x0006004A);
	mmio_write_32(DDRC_FREQ1_DRAMTMG0(0), 0x0B070508);
	mmio_write_32(DDRC_FREQ1_DRAMTMG1(0), 0x0003040B);
	mmio_write_32(DDRC_FREQ1_DRAMTMG2(0), 0x0305090C);
	mmio_write_32(DDRC_FREQ1_DRAMTMG3(0), 0x00505000);
	mmio_write_32(DDRC_FREQ1_DRAMTMG4(0), 0x04040204);
	mmio_write_32(DDRC_FREQ1_DRAMTMG5(0), 0x02030303);
	mmio_write_32(DDRC_FREQ1_DRAMTMG6(0), 0x01010004);
	mmio_write_32(DDRC_FREQ1_DRAMTMG7(0), 0x00000301);
	mmio_write_32(DDRC_FREQ1_DRAMTMG12(0), 0x00020300);
	mmio_write_32(DDRC_FREQ1_DRAMTMG13(0), 0x0A100002);
	mmio_write_32(DDRC_FREQ1_DRAMTMG14(0), VAL_DDRC_FREQ1_DRAMTMG14);
	mmio_write_32(DDRC_FREQ1_DRAMTMG17(0), 0x00220011);
	mmio_write_32(DDRC_FREQ1_ZQCTL0(0), 0xC0A70006);
	mmio_write_32(DDRC_FREQ1_DFITMG0(0), 0x03858202);
	mmio_write_32(DDRC_FREQ1_DFITMG1(0), 0x00080303);
	mmio_write_32(DDRC_FREQ1_DFITMG2(0), 0x00000502);
}

static inline void umctl2_freq2(void)
{
	mmio_write_32(DDRC_FREQ2_DERATEEN(0), 0x00000001);
	mmio_write_32(DDRC_FREQ2_DERATEINT(0), 0x000C3500);
	mmio_write_32(DDRC_FREQ2_RFSHCTL0(0), 0x0020D040);
	mmio_write_32(DDRC_FREQ2_RFSHTMG(0), VAL_DDRC_FREQ2_RFSHTMG);
	mmio_write_32(DDRC_FREQ2_INIT3(0), 0x00D4002D);
	mmio_write_32(DDRC_FREQ2_INIT4(0), 0x00310008);
	mmio_write_32(DDRC_FREQ2_INIT6(0), 0x0066004a);
	mmio_write_32(DDRC_FREQ2_INIT7(0), 0x0006004A);
	mmio_write_32(DDRC_FREQ2_DRAMTMG0(0), 0x0A010102);
	mmio_write_32(DDRC_FREQ2_DRAMTMG1(0), 0x00030404);
	mmio_write_32(DDRC_FREQ2_DRAMTMG2(0), 0x0203060B);
	mmio_write_32(DDRC_FREQ2_DRAMTMG3(0), 0x00505000);
	mmio_write_32(DDRC_FREQ2_DRAMTMG4(0), 0x02040202);
	mmio_write_32(DDRC_FREQ2_DRAMTMG5(0), 0x02030202);
	mmio_write_32(DDRC_FREQ2_DRAMTMG6(0), 0x01010004);
	mmio_write_32(DDRC_FREQ2_DRAMTMG7(0), 0x00000301);
	mmio_write_32(DDRC_FREQ2_DRAMTMG12(0), 0x00020300);
	mmio_write_32(DDRC_FREQ2_DRAMTMG13(0), 0x0A100002);
	mmio_write_32(DDRC_FREQ2_DRAMTMG14(0), VAL_DDRC_FREQ2_DRAMTMG14);
	mmio_write_32(DDRC_FREQ2_DRAMTMG17(0), 0x00050003);
	mmio_write_32(DDRC_FREQ2_ZQCTL0(0), 0xC0190004);
	mmio_write_32(DDRC_FREQ2_DFITMG0(0), 0x03818200);
	mmio_write_32(DDRC_FREQ2_DFITMG1(0), 0x00080303);
	mmio_write_32(DDRC_FREQ2_DFITMG2(0), 0x00000100);
}

void lpddr4_cfg_umctl2(void)
{
	/* Start to config, default 3200mbps */
	mmio_write_32(DDRC_DBG1(0), 0x00000001);
	mmio_write_32(DDRC_PWRCTL(0), 0x00000001);
	mmio_write_32(DDRC_MSTR(0), 0xa3080020);
	mmio_write_32(DDRC_MSTR2(0), 0x00000000);
	mmio_write_32(DDRC_RFSHTMG(0), VAL_DDRC_RFSHTMG);
	mmio_write_32(DDRC_INIT0(0), 0xC003061C);
	mmio_write_32(DDRC_INIT1(0), 0x009E0000);
	mmio_write_32(DDRC_INIT3(0), 0x00D4002D);
#ifdef WR_POST_EXT_3200  /* recommened to define */
	mmio_write_32(DDRC_INIT4(0), 0x00330008);
#else
	mmio_write_32(DDRC_INIT4(0), 0x00310008);
#endif
	mmio_write_32(DDRC_INIT6(0), 0x0066004a);
	mmio_write_32(DDRC_INIT7(0), 0x0016004a);

	mmio_write_32(DDRC_DRAMTMG0(0), 0x1A201B22);
	mmio_write_32(DDRC_DRAMTMG1(0), 0x00060633);
	mmio_write_32(DDRC_DRAMTMG3(0), 0x00C0C000);
	mmio_write_32(DDRC_DRAMTMG4(0), 0x0F04080F);
	mmio_write_32(DDRC_DRAMTMG5(0), 0x02040C0C);
	mmio_write_32(DDRC_DRAMTMG6(0), 0x01010007);
	mmio_write_32(DDRC_DRAMTMG7(0), 0x00000401);
	mmio_write_32(DDRC_DRAMTMG12(0), 0x00020600);
	mmio_write_32(DDRC_DRAMTMG13(0), 0x0C100002);
	mmio_write_32(DDRC_DRAMTMG14(0), VAL_DDRC_DRAMTMG14);
	mmio_write_32(DDRC_DRAMTMG17(0), 0x00A00050);

	mmio_write_32(DDRC_ZQCTL0(0), 0xC3200018);
	mmio_write_32(DDRC_ZQCTL1(0), 0x028061A8);
	mmio_write_32(DDRC_ZQCTL2(0), 0x00000000);

	mmio_write_32(DDRC_DFITMG0(0), 0x0497820A);
	mmio_write_32(DDRC_DFITMG1(0), 0x00080303);
	mmio_write_32(DDRC_DFIUPD0(0), 0xE0400018);
	mmio_write_32(DDRC_DFIUPD1(0), 0x00DF00E4);
	mmio_write_32(DDRC_DFIUPD2(0), 0x80000000);
	mmio_write_32(DDRC_DFIMISC(0), 0x00000011);
	mmio_write_32(DDRC_DFITMG2(0), 0x0000170A);

	mmio_write_32(DDRC_DBICTL(0), 0x00000001);
	mmio_write_32(DDRC_DFIPHYMSTR(0), 0x00000001);

	mmio_write_32(DDRC_RANKCTL(0), 0x00000639);
	mmio_write_32(DDRC_DRAMTMG2(0), 0x070E1214);

	/* address mapping */
	umctl2_addrmap();

	/* performance setting */
	umctl2_perf();

	/* freq set point 1 setting */
	umctl2_freq1();
	umctl2_freq2();
}
