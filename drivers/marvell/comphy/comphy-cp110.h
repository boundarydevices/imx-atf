/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

/* Marvell CP110 SoC COMPHY unit driver */

#ifndef _PHY_COMPHY_CP110_H
#define _PHY_COMPHY_CP110_H

#define SD_ADDR(base, lane)			(base + 0x1000 * lane)
#define HPIPE_ADDR(base, lane)			(SD_ADDR(base, lane) + 0x800)
#define COMPHY_ADDR(base, lane)			(base + 0x28 * lane)

#define MAX_NUM_OF_FFE				8
#define RX_TRAINING_TIMEOUT			500

/* Comphy registers */
#define COMMON_PHY_CFG1_REG			0x0
#define COMMON_PHY_CFG1_PWR_UP_OFFSET		1
#define COMMON_PHY_CFG1_PWR_UP_MASK		\
				(0x1 << COMMON_PHY_CFG1_PWR_UP_OFFSET)
#define COMMON_PHY_CFG1_PIPE_SELECT_OFFSET	2
#define COMMON_PHY_CFG1_PIPE_SELECT_MASK	\
				(0x1 << COMMON_PHY_CFG1_PIPE_SELECT_OFFSET)
#define COMMON_PHY_CFG1_CORE_RSTN_OFFSET	13
#define COMMON_PHY_CFG1_CORE_RSTN_MASK		\
				(0x1 << COMMON_PHY_CFG1_CORE_RSTN_OFFSET)
#define COMMON_PHY_CFG1_PWR_ON_RESET_OFFSET	14
#define COMMON_PHY_CFG1_PWR_ON_RESET_MASK	\
				(0x1 << COMMON_PHY_CFG1_PWR_ON_RESET_OFFSET)
#define COMMON_PHY_PHY_MODE_OFFSET		15
#define COMMON_PHY_PHY_MODE_MASK		\
				(0x1 << COMMON_PHY_PHY_MODE_OFFSET)

#define COMMON_PHY_CFG6_REG			0x14
#define COMMON_PHY_CFG6_IF_40_SEL_OFFSET	18
#define COMMON_PHY_CFG6_IF_40_SEL_MASK		\
				(0x1 << COMMON_PHY_CFG6_IF_40_SEL_OFFSET)

#define COMMON_PHY_CFG6_REG			0x14
#define COMMON_PHY_CFG6_IF_40_SEL_OFFSET	18
#define COMMON_PHY_CFG6_IF_40_SEL_MASK		\
				(0x1 << COMMON_PHY_CFG6_IF_40_SEL_OFFSET)

#define COMMON_SELECTOR_PHY_REG_OFFSET		0x140
#define COMMON_SELECTOR_PIPE_REG_OFFSET		0x144
#define COMMON_SELECTOR_COMPHY_MASK		0xf
#define COMMON_SELECTOR_COMPHYN_FIELD_WIDTH	4
#define COMMON_SELECTOR_COMPHYN_SATA		0x4
#define COMMON_SELECTOR_PIPE_COMPHY_PCIE	0x4
#define COMMON_SELECTOR_PIPE_COMPHY_USBH	0x1
#define COMMON_SELECTOR_PIPE_COMPHY_USBD	0x2

/* SGMII/HS-SGMII/SFI/RXAUI */
#define COMMON_SELECTOR_COMPHY0_1_2_NETWORK	0x1
#define COMMON_SELECTOR_COMPHY3_RXAUI		0x1
#define COMMON_SELECTOR_COMPHY3_SGMII		0x2
#define COMMON_SELECTOR_COMPHY4_PORT1		0x1
#define COMMON_SELECTOR_COMPHY4_ALL_OTHERS	0x2
#define COMMON_SELECTOR_COMPHY5_RXAUI		0x2
#define COMMON_SELECTOR_COMPHY5_SGMII		0x1

#define COMMON_PHY_SD_CTRL1			0x148
#define COMMON_PHY_SD_CTRL1_COMPHY_0_PORT_OFFSET	0
#define COMMON_PHY_SD_CTRL1_COMPHY_1_PORT_OFFSET	4
#define COMMON_PHY_SD_CTRL1_COMPHY_2_PORT_OFFSET	8
#define COMMON_PHY_SD_CTRL1_COMPHY_3_PORT_OFFSET	12
#define COMMON_PHY_SD_CTRL1_COMPHY_0_3_PORT_MASK	0xFFFF
#define COMMON_PHY_SD_CTRL1_COMPHY_0_1_PORT_MASK	0xFF
#define COMMON_PHY_SD_CTRL1_PCIE_X4_EN_OFFSET	24
#define COMMON_PHY_SD_CTRL1_PCIE_X4_EN_MASK	\
				(0x1 << COMMON_PHY_SD_CTRL1_PCIE_X4_EN_OFFSET)
#define COMMON_PHY_SD_CTRL1_PCIE_X2_EN_OFFSET	25
#define COMMON_PHY_SD_CTRL1_PCIE_X2_EN_MASK	\
				(0x1 << COMMON_PHY_SD_CTRL1_PCIE_X2_EN_OFFSET)
#define COMMON_PHY_SD_CTRL1_RXAUI1_OFFSET	26
#define COMMON_PHY_SD_CTRL1_RXAUI1_MASK		\
				(0x1 << COMMON_PHY_SD_CTRL1_RXAUI1_OFFSET)
#define COMMON_PHY_SD_CTRL1_RXAUI0_OFFSET	27
#define COMMON_PHY_SD_CTRL1_RXAUI0_MASK		\
				(0x1 << COMMON_PHY_SD_CTRL1_RXAUI0_OFFSET)

/* DFX register */
#define DFX_BASE				(0x400000)
#define DFX_DEV_GEN_CTRL12_REG			(0x280)
#define DFX_DEV_GEN_PCIE_CLK_SRC_MUX		(0x3)
#define DFX_DEV_GEN_PCIE_CLK_SRC_OFFSET		7
#define DFX_DEV_GEN_PCIE_CLK_SRC_MASK		\
				(0x3 << DFX_DEV_GEN_PCIE_CLK_SRC_OFFSET)

/* SerDes IP registers */
#define SD_EXTERNAL_CONFIG0_REG				0
#define SD_EXTERNAL_CONFIG0_SD_PU_PLL_OFFSET		1
#define SD_EXTERNAL_CONFIG0_SD_PU_PLL_MASK		\
			(1 << SD_EXTERNAL_CONFIG0_SD_PU_PLL_OFFSET)
#define SD_EXTERNAL_CONFIG0_SD_PHY_GEN_RX_OFFSET	3
#define SD_EXTERNAL_CONFIG0_SD_PHY_GEN_RX_MASK		\
			(0xf << SD_EXTERNAL_CONFIG0_SD_PHY_GEN_RX_OFFSET)
#define SD_EXTERNAL_CONFIG0_SD_PHY_GEN_TX_OFFSET	7
#define SD_EXTERNAL_CONFIG0_SD_PHY_GEN_TX_MASK		\
			(0xf << SD_EXTERNAL_CONFIG0_SD_PHY_GEN_TX_OFFSET)
#define SD_EXTERNAL_CONFIG0_SD_PU_RX_OFFSET		11
#define SD_EXTERNAL_CONFIG0_SD_PU_RX_MASK		\
			(1 << SD_EXTERNAL_CONFIG0_SD_PU_RX_OFFSET)
#define SD_EXTERNAL_CONFIG0_SD_PU_TX_OFFSET		12
#define SD_EXTERNAL_CONFIG0_SD_PU_TX_MASK		\
			(1 << SD_EXTERNAL_CONFIG0_SD_PU_TX_OFFSET)
#define SD_EXTERNAL_CONFIG0_HALF_BUS_MODE_OFFSET	14
#define SD_EXTERNAL_CONFIG0_HALF_BUS_MODE_MASK		\
			(1 << SD_EXTERNAL_CONFIG0_HALF_BUS_MODE_OFFSET)
#define SD_EXTERNAL_CONFIG0_MEDIA_MODE_OFFSET		15
#define SD_EXTERNAL_CONFIG0_MEDIA_MODE_MASK		\
			(0x1 << SD_EXTERNAL_CONFIG0_MEDIA_MODE_OFFSET)

#define SD_EXTERNAL_CONFIG1_REG			0x4
#define SD_EXTERNAL_CONFIG1_RESET_IN_OFFSET	3
#define SD_EXTERNAL_CONFIG1_RESET_IN_MASK	\
			(0x1 << SD_EXTERNAL_CONFIG1_RESET_IN_OFFSET)
#define SD_EXTERNAL_CONFIG1_RX_INIT_OFFSET	4
#define SD_EXTERNAL_CONFIG1_RX_INIT_MASK	\
			(0x1 << SD_EXTERNAL_CONFIG1_RX_INIT_OFFSET)
#define SD_EXTERNAL_CONFIG1_RESET_CORE_OFFSET	5
#define SD_EXTERNAL_CONFIG1_RESET_CORE_MASK	\
			(0x1 << SD_EXTERNAL_CONFIG1_RESET_CORE_OFFSET)
#define SD_EXTERNAL_CONFIG1_RF_RESET_IN_OFFSET	6
#define SD_EXTERNAL_CONFIG1_RF_RESET_IN_MASK	\
			(0x1 << SD_EXTERNAL_CONFIG1_RF_RESET_IN_OFFSET)

#define SD_EXTERNAL_CONFIG2_REG			0x8
#define SD_EXTERNAL_CONFIG2_PIN_DFE_EN_OFFSET	4
#define SD_EXTERNAL_CONFIG2_PIN_DFE_EN_MASK	\
			(0x1 << SD_EXTERNAL_CONFIG2_PIN_DFE_EN_OFFSET)
#define SD_EXTERNAL_CONFIG2_SSC_ENABLE_OFFSET	7
#define SD_EXTERNAL_CONFIG2_SSC_ENABLE_MASK	\
			(0x1 << SD_EXTERNAL_CONFIG2_SSC_ENABLE_OFFSET)

#define SD_EXTERNAL_STATUS_REG				0xc
#define SD_EXTERNAL_STATUS_START_RX_TRAINING_OFFSET	7
#define SD_EXTERNAL_STATUS_START_RX_TRAINING_MASK	\
			(1 << SD_EXTERNAL_STATUS_START_RX_TRAINING_OFFSET)

#define SD_EXTERNAL_STATUS0_REG			0x18
#define SD_EXTERNAL_STATUS0_PLL_TX_OFFSET	2
#define SD_EXTERNAL_STATUS0_PLL_TX_MASK		\
			(0x1 << SD_EXTERNAL_STATUS0_PLL_TX_OFFSET)
#define SD_EXTERNAL_STATUS0_PLL_RX_OFFSET	3
#define SD_EXTERNAL_STATUS0_PLL_RX_MASK		\
			(0x1 << SD_EXTERNAL_STATUS0_PLL_RX_OFFSET)
#define SD_EXTERNAL_STATUS0_RX_INIT_OFFSET	4
#define SD_EXTERNAL_STATUS0_RX_INIT_MASK	\
			(0x1 << SD_EXTERNAL_STATUS0_RX_INIT_OFFSET)

#define SD_EXTERNAL_STATAUS1_REG			0x1c
#define SD_EXTERNAL_STATAUS1_REG_RX_TRAIN_COMP_OFFSET	0
#define SD_EXTERNAL_STATAUS1_REG_RX_TRAIN_COMP_MASK	\
	(1 << SD_EXTERNAL_STATAUS1_REG_RX_TRAIN_COMP_OFFSET)
#define SD_EXTERNAL_STATAUS1_REG_RX_TRAIN_FAILED_OFFSET	1
#define SD_EXTERNAL_STATAUS1_REG_RX_TRAIN_FAILED_MASK	\
	(1 << SD_EXTERNAL_STATAUS1_REG_RX_TRAIN_FAILED_OFFSET)

/* HPIPE registers */
#define HPIPE_PWR_PLL_REG			0x4
#define HPIPE_PWR_PLL_REF_FREQ_OFFSET		0
#define HPIPE_PWR_PLL_REF_FREQ_MASK		\
			(0x1f << HPIPE_PWR_PLL_REF_FREQ_OFFSET)
#define HPIPE_PWR_PLL_PHY_MODE_OFFSET		5
#define HPIPE_PWR_PLL_PHY_MODE_MASK		\
			(0x7 << HPIPE_PWR_PLL_PHY_MODE_OFFSET)

#define HPIPE_CAL_REG1_REG			0xc
#define HPIPE_CAL_REG_1_EXT_TXIMP_OFFSET	10
#define HPIPE_CAL_REG_1_EXT_TXIMP_MASK		\
			(0x1f << HPIPE_CAL_REG_1_EXT_TXIMP_OFFSET)
#define HPIPE_CAL_REG_1_EXT_TXIMP_EN_OFFSET	15
#define HPIPE_CAL_REG_1_EXT_TXIMP_EN_MASK	\
			(0x1 << HPIPE_CAL_REG_1_EXT_TXIMP_EN_OFFSET)

#define HPIPE_SQUELCH_FFE_SETTING_REG		0x18
#define HPIPE_SQUELCH_THRESH_IN_OFFSET		8
#define HPIPE_SQUELCH_THRESH_IN_MASK		\
			(0xf << HPIPE_SQUELCH_THRESH_IN_OFFSET)
#define HPIPE_SQUELCH_DETECTED_OFFSET		14
#define HPIPE_SQUELCH_DETECTED_MASK		\
			(0x1 << HPIPE_SQUELCH_DETECTED_OFFSET)

#define HPIPE_DFE_REG0				0x1c
#define HPIPE_DFE_RES_FORCE_OFFSET		15
#define HPIPE_DFE_RES_FORCE_MASK		\
			(0x1 << HPIPE_DFE_RES_FORCE_OFFSET)

#define HPIPE_DFE_F3_F5_REG			0x28
#define HPIPE_DFE_F3_F5_DFE_EN_OFFSET		14
#define HPIPE_DFE_F3_F5_DFE_EN_MASK		\
			(0x1 << HPIPE_DFE_F3_F5_DFE_EN_OFFSET)
#define HPIPE_DFE_F3_F5_DFE_CTRL_OFFSET		15
#define HPIPE_DFE_F3_F5_DFE_CTRL_MASK		\
			(0x1 << HPIPE_DFE_F3_F5_DFE_CTRL_OFFSET)

#define HPIPE_ADAPTED_DFE_COEFFICIENT_1_REG	0x30
#define HPIPE_ADAPTED_DFE_RES_OFFSET		13
#define HPIPE_ADAPTED_DFE_RES_MASK		\
			(0x3 << HPIPE_ADAPTED_DFE_RES_OFFSET)

#define HPIPE_G1_SET_0_REG			0x34
#define HPIPE_G1_SET_0_G1_TX_AMP_OFFSET		1
#define HPIPE_G1_SET_0_G1_TX_AMP_MASK		\
			(0x1f << HPIPE_G1_SET_0_G1_TX_AMP_OFFSET)
#define HPIPE_G1_SET_0_G1_TX_AMP_ADJ_OFFSET	6
#define HPIPE_G1_SET_0_G1_TX_AMP_ADJ_MASK	\
			(0x1 << HPIPE_G1_SET_0_G1_TX_AMP_ADJ_OFFSET)
#define HPIPE_G1_SET_0_G1_TX_EMPH1_OFFSET	7
#define HPIPE_G1_SET_0_G1_TX_EMPH1_MASK		\
			(0xf << HPIPE_G1_SET_0_G1_TX_EMPH1_OFFSET)
#define HPIPE_G1_SET_0_G1_TX_EMPH1_EN_OFFSET	11
#define HPIPE_G1_SET_0_G1_TX_EMPH1_EN_MASK	\
			(0x1 << HPIPE_G1_SET_0_G1_TX_EMPH1_EN_OFFSET)

#define HPIPE_G1_SET_1_REG			0x38
#define HPIPE_G1_SET_1_G1_RX_SELMUPI_OFFSET	0
#define HPIPE_G1_SET_1_G1_RX_SELMUPI_MASK	\
			(0x7 << HPIPE_G1_SET_1_G1_RX_SELMUPI_OFFSET)
#define HPIPE_G1_SET_1_G1_RX_SELMUPF_OFFSET	3
#define HPIPE_G1_SET_1_G1_RX_SELMUPF_MASK	\
			(0x7 << HPIPE_G1_SET_1_G1_RX_SELMUPF_OFFSET)
#define HPIPE_G1_SET_1_G1_RX_SELMUFI_OFFSET	6
#define HPIPE_G1_SET_1_G1_RX_SELMUFI_MASK	\
			(0x3 << HPIPE_G1_SET_1_G1_RX_SELMUFI_OFFSET)
#define HPIPE_G1_SET_1_G1_RX_SELMUFF_OFFSET	8
#define HPIPE_G1_SET_1_G1_RX_SELMUFF_MASK	\
			(0x3 << HPIPE_G1_SET_1_G1_RX_SELMUFF_OFFSET)
#define HPIPE_G1_SET_1_G1_RX_DFE_EN_OFFSET	10
#define HPIPE_G1_SET_1_G1_RX_DFE_EN_MASK	\
			(0x1 << HPIPE_G1_SET_1_G1_RX_DFE_EN_OFFSET)
#define HPIPE_G1_SET_1_G1_RX_DIGCK_DIV_OFFSET	11
#define HPIPE_G1_SET_1_G1_RX_DIGCK_DIV_MASK	\
			(0x3 << HPIPE_G1_SET_1_G1_RX_DIGCK_DIV_OFFSET)

#define HPIPE_G2_SET_0_REG			0x3c
#define HPIPE_G2_SET_0_G2_TX_AMP_OFFSET		1
#define HPIPE_G2_SET_0_G2_TX_AMP_MASK		\
			(0x1f << HPIPE_G2_SET_0_G2_TX_AMP_OFFSET)
#define HPIPE_G2_SET_0_G2_TX_AMP_ADJ_OFFSET	6
#define HPIPE_G2_SET_0_G2_TX_AMP_ADJ_MASK	\
			(0x1 << HPIPE_G2_SET_0_G2_TX_AMP_ADJ_OFFSET)
#define HPIPE_G2_SET_0_G2_TX_EMPH1_OFFSET	7
#define HPIPE_G2_SET_0_G2_TX_EMPH1_MASK		\
			(0xf << HPIPE_G2_SET_0_G2_TX_EMPH1_OFFSET)
#define HPIPE_G2_SET_0_G2_TX_EMPH1_EN_OFFSET	11
#define HPIPE_G2_SET_0_G2_TX_EMPH1_EN_MASK	\
			(0x1 << HPIPE_G2_SET_0_G2_TX_EMPH1_EN_OFFSET)

#define HPIPE_G2_SET_1_REG			0x40
#define HPIPE_G2_SET_1_G2_RX_SELMUPI_OFFSET	0
#define HPIPE_G2_SET_1_G2_RX_SELMUPI_MASK	\
			(0x7 << HPIPE_G2_SET_1_G2_RX_SELMUPI_OFFSET)
#define HPIPE_G2_SET_1_G2_RX_SELMUPF_OFFSET	3
#define HPIPE_G2_SET_1_G2_RX_SELMUPF_MASK	\
			(0x7 << HPIPE_G2_SET_1_G2_RX_SELMUPF_OFFSET)
#define HPIPE_G2_SET_1_G2_RX_SELMUFI_OFFSET	6
#define HPIPE_G2_SET_1_G2_RX_SELMUFI_MASK	\
			(0x3 << HPIPE_G2_SET_1_G2_RX_SELMUFI_OFFSET)
#define HPIPE_G2_SET_1_G2_RX_SELMUFF_OFFSET	8
#define HPIPE_G2_SET_1_G2_RX_SELMUFF_MASK	\
			(0x3 << HPIPE_G2_SET_1_G2_RX_SELMUFF_OFFSET)
#define HPIPE_G2_SET_1_G2_RX_DFE_EN_OFFSET	10
#define HPIPE_G2_SET_1_G2_RX_DFE_EN_MASK	\
			(0x1 << HPIPE_G2_SET_1_G2_RX_DFE_EN_OFFSET)
#define HPIPE_G2_SET_1_G2_RX_DIGCK_DIV_OFFSET	11
#define HPIPE_G2_SET_1_G2_RX_DIGCK_DIV_MASK	\
			(0x3 << HPIPE_G2_SET_1_G2_RX_DIGCK_DIV_OFFSET)

#define HPIPE_G3_SET_0_REG			0x44
#define HPIPE_G3_SET_0_G3_TX_AMP_OFFSET		1
#define HPIPE_G3_SET_0_G3_TX_AMP_MASK		\
			(0x1f << HPIPE_G3_SET_0_G3_TX_AMP_OFFSET)
#define HPIPE_G3_SET_0_G3_TX_AMP_ADJ_OFFSET	6
#define HPIPE_G3_SET_0_G3_TX_AMP_ADJ_MASK	\
			(0x1 << HPIPE_G3_SET_0_G3_TX_AMP_ADJ_OFFSET)
#define HPIPE_G3_SET_0_G3_TX_EMPH1_OFFSET	7
#define HPIPE_G3_SET_0_G3_TX_EMPH1_MASK		\
			(0xf << HPIPE_G3_SET_0_G3_TX_EMPH1_OFFSET)
#define HPIPE_G3_SET_0_G3_TX_EMPH1_EN_OFFSET	11
#define HPIPE_G3_SET_0_G3_TX_EMPH1_EN_MASK	\
			(0x1 << HPIPE_G3_SET_0_G3_TX_EMPH1_EN_OFFSET)
#define HPIPE_G3_SET_0_G3_TX_SLEW_RATE_SEL_OFFSET 12
#define HPIPE_G3_SET_0_G3_TX_SLEW_RATE_SEL_MASK	\
			(0x7 << HPIPE_G3_SET_0_G3_TX_SLEW_RATE_SEL_OFFSET)
#define HPIPE_G3_SET_0_G3_TX_SLEW_CTRL_EN_OFFSET 15
#define HPIPE_G3_SET_0_G3_TX_SLEW_CTRL_EN_MASK	\
			(0x1 << HPIPE_G3_SET_0_G3_TX_SLEW_CTRL_EN_OFFSET)

#define HPIPE_G3_SET_1_REG				0x48
#define HPIPE_G3_SET_1_G3_RX_SELMUPI_OFFSET		0
#define HPIPE_G3_SET_1_G3_RX_SELMUPI_MASK		\
			(0x7 << HPIPE_G3_SET_1_G3_RX_SELMUPI_OFFSET)
#define HPIPE_G3_SET_1_G3_RX_SELMUPF_OFFSET		3
#define HPIPE_G3_SET_1_G3_RX_SELMUPF_MASK		\
			(0x7 << HPIPE_G3_SET_1_G3_RX_SELMUPF_OFFSET)
#define HPIPE_G3_SET_1_G3_RX_SELMUFI_OFFSET		6
#define HPIPE_G3_SET_1_G3_RX_SELMUFI_MASK		\
			(0x3 << HPIPE_G3_SET_1_G3_RX_SELMUFI_OFFSET)
#define HPIPE_G3_SET_1_G3_RX_SELMUFF_OFFSET		8
#define HPIPE_G3_SET_1_G3_RX_SELMUFF_MASK		\
			(0x3 << HPIPE_G3_SET_1_G3_RX_SELMUFF_OFFSET)
#define HPIPE_G3_SET_1_G3_RX_DFE_EN_OFFSET		10
#define HPIPE_G3_SET_1_G3_RX_DFE_EN_MASK		\
			(0x1 << HPIPE_G3_SET_1_G3_RX_DFE_EN_OFFSET)
#define HPIPE_G3_SET_1_G3_RX_DIGCK_DIV_OFFSET		11
#define HPIPE_G3_SET_1_G3_RX_DIGCK_DIV_MASK		\
			(0x3 << HPIPE_G3_SET_1_G3_RX_DIGCK_DIV_OFFSET)
#define HPIPE_G3_SET_1_G3_SAMPLER_INPAIRX2_EN_OFFSET	13
#define HPIPE_G3_SET_1_G3_SAMPLER_INPAIRX2_EN_MASK	\
			(0x1 << HPIPE_G3_SET_1_G3_SAMPLER_INPAIRX2_EN_OFFSET)

#define HPIPE_PHY_TEST_CONTROL_REG		0x54
#define HPIPE_PHY_TEST_PATTERN_SEL_OFFSET	4
#define HPIPE_PHY_TEST_PATTERN_SEL_MASK		\
			(0xf << HPIPE_PHY_TEST_PATTERN_SEL_OFFSET)
#define HPIPE_PHY_TEST_RESET_OFFSET		14
#define HPIPE_PHY_TEST_RESET_MASK		\
			(0x1 << HPIPE_PHY_TEST_RESET_OFFSET)
#define HPIPE_PHY_TEST_EN_OFFSET		15
#define HPIPE_PHY_TEST_EN_MASK			\
			(0x1 << HPIPE_PHY_TEST_EN_OFFSET)

#define HPIPE_PHY_TEST_DATA_REG			0x6c
#define HPIPE_PHY_TEST_DATA_OFFSET		0
#define HPIPE_PHY_TEST_DATA_MASK		\
			(0xffff << HPIPE_PHY_TEST_DATA_OFFSET)

#define HPIPE_PHY_TEST_PRBS_ERROR_COUNTER_1_REG	0x80

#define HPIPE_PHY_TEST_OOB_0_REGISTER		0x84
#define HPIPE_PHY_PT_OOB_EN_OFFSET		14
#define HPIPE_PHY_PT_OOB_EN_MASK		\
			(0x1 << HPIPE_PHY_PT_OOB_EN_OFFSET)
#define HPIPE_PHY_TEST_PT_TESTMODE_OFFSET	12
#define HPIPE_PHY_TEST_PT_TESTMODE_MASK		\
			(0x3 << HPIPE_PHY_TEST_PT_TESTMODE_OFFSET)

#define HPIPE_LOOPBACK_REG			0x8c
#define HPIPE_LOOPBACK_SEL_OFFSET		1
#define HPIPE_LOOPBACK_SEL_MASK			\
			(0x7 << HPIPE_LOOPBACK_SEL_OFFSET)
#define HPIPE_CDR_LOCK_OFFSET			7
#define HPIPE_CDR_LOCK_MASK			\
			(0x1 << HPIPE_CDR_LOCK_OFFSET)
#define HPIPE_CDR_LOCK_DET_EN_OFFSET		8
#define HPIPE_CDR_LOCK_DET_EN_MASK		\
			(0x1 << HPIPE_CDR_LOCK_DET_EN_OFFSET)

#define HPIPE_INTERFACE_REG			0x94
#define HPIPE_INTERFACE_GEN_MAX_OFFSET		10
#define HPIPE_INTERFACE_GEN_MAX_MASK		\
			(0x3 << HPIPE_INTERFACE_GEN_MAX_OFFSET)
#define HPIPE_INTERFACE_DET_BYPASS_OFFSET	12
#define HPIPE_INTERFACE_DET_BYPASS_MASK		\
			(0x1 << HPIPE_INTERFACE_DET_BYPASS_OFFSET)
#define HPIPE_INTERFACE_LINK_TRAIN_OFFSET	14
#define HPIPE_INTERFACE_LINK_TRAIN_MASK		\
			(0x1 << HPIPE_INTERFACE_LINK_TRAIN_OFFSET)

#define HPIPE_G1_SET_2_REG			0xf4
#define HPIPE_G1_SET_2_G1_TX_EMPH0_OFFSET	0
#define HPIPE_G1_SET_2_G1_TX_EMPH0_MASK		\
			(0xf << HPIPE_G1_SET_2_G1_TX_EMPH0_OFFSET)
#define HPIPE_G1_SET_2_G1_TX_EMPH0_EN_OFFSET	4
#define HPIPE_G1_SET_2_G1_TX_EMPH0_EN_MASK	\
			(0x1 << HPIPE_G1_SET_2_G1_TX_EMPH0_EN_OFFSET)

#define HPIPE_G2_SET_2_REG			0xf8
#define HPIPE_G2_SET_2_G2_TX_EMPH0_OFFSET	0
#define HPIPE_G2_SET_2_G2_TX_EMPH0_MASK		\
			(0xf << HPIPE_G2_SET_2_G2_TX_EMPH0_OFFSET)
#define HPIPE_G2_SET_2_G2_TX_EMPH0_EN_OFFSET	4
#define HPIPE_G2_SET_2_G2_TX_EMPH0_EN_MASK	\
			(0x1 << HPIPE_G2_SET_2_G2_TX_EMPH0_EN_OFFSET)
#define HPIPE_G2_TX_SSC_AMP_OFFSET		9
#define HPIPE_G2_TX_SSC_AMP_MASK		\
			(0x7f << HPIPE_G2_TX_SSC_AMP_OFFSET)

#define HPIPE_G3_SET_2_REG			0xfc
#define HPIPE_G3_SET_2_G3_TX_EMPH0_OFFSET	0
#define HPIPE_G3_SET_2_G3_TX_EMPH0_MASK		\
			(0xf << HPIPE_G3_SET_2_G3_TX_EMPH0_OFFSET)
#define HPIPE_G3_SET_2_G3_TX_EMPH0_EN_OFFSET	4
#define HPIPE_G3_SET_2_G3_TX_EMPH0_EN_MASK	\
			(0x1 << HPIPE_G3_SET_2_G3_TX_EMPH0_EN_OFFSET)
#define HPIPE_G3_TX_SSC_AMP_OFFSET		9
#define HPIPE_G3_TX_SSC_AMP_MASK		\
			(0x7f << HPIPE_G3_TX_SSC_AMP_OFFSET)

#define HPIPE_VDD_CAL_0_REG			0x108
#define HPIPE_CAL_VDD_CONT_MODE_OFFSET		15
#define HPIPE_CAL_VDD_CONT_MODE_MASK		\
			(0x1 << HPIPE_CAL_VDD_CONT_MODE_OFFSET)

#define HPIPE_VDD_CAL_CTRL_REG			0x114
#define HPIPE_EXT_SELLV_RXSAMPL_OFFSET		5
#define HPIPE_EXT_SELLV_RXSAMPL_MASK		\
			(0x1f << HPIPE_EXT_SELLV_RXSAMPL_OFFSET)

#define HPIPE_PCIE_REG0				0x120
#define HPIPE_PCIE_IDLE_SYNC_OFFSET		12
#define HPIPE_PCIE_IDLE_SYNC_MASK		\
			(0x1 << HPIPE_PCIE_IDLE_SYNC_OFFSET)
#define HPIPE_PCIE_SEL_BITS_OFFSET		13
#define HPIPE_PCIE_SEL_BITS_MASK		\
			(0x3 << HPIPE_PCIE_SEL_BITS_OFFSET)

#define HPIPE_LANE_ALIGN_REG			0x124
#define HPIPE_LANE_ALIGN_OFF_OFFSET		12
#define HPIPE_LANE_ALIGN_OFF_MASK		\
			(0x1 << HPIPE_LANE_ALIGN_OFF_OFFSET)

#define HPIPE_MISC_REG				0x13C
#define HPIPE_MISC_CLK100M_125M_OFFSET		4
#define HPIPE_MISC_CLK100M_125M_MASK		\
			(0x1 << HPIPE_MISC_CLK100M_125M_OFFSET)
#define HPIPE_MISC_ICP_FORCE_OFFSET		5
#define HPIPE_MISC_ICP_FORCE_MASK		\
			(0x1 << HPIPE_MISC_ICP_FORCE_OFFSET)
#define HPIPE_MISC_TXDCLK_2X_OFFSET		6
#define HPIPE_MISC_TXDCLK_2X_MASK		\
			(0x1 << HPIPE_MISC_TXDCLK_2X_OFFSET)
#define HPIPE_MISC_CLK500_EN_OFFSET		7
#define HPIPE_MISC_CLK500_EN_MASK		\
			(0x1 << HPIPE_MISC_CLK500_EN_OFFSET)
#define HPIPE_MISC_REFCLK_SEL_OFFSET		10
#define HPIPE_MISC_REFCLK_SEL_MASK		\
			(0x1 << HPIPE_MISC_REFCLK_SEL_OFFSET)

#define HPIPE_RX_CONTROL_1_REG			0x140
#define HPIPE_RX_CONTROL_1_RXCLK2X_SEL_OFFSET	11
#define HPIPE_RX_CONTROL_1_RXCLK2X_SEL_MASK	\
			(0x1 << HPIPE_RX_CONTROL_1_RXCLK2X_SEL_OFFSET)
#define HPIPE_RX_CONTROL_1_CLK8T_EN_OFFSET	12
#define HPIPE_RX_CONTROL_1_CLK8T_EN_MASK	\
			(0x1 << HPIPE_RX_CONTROL_1_CLK8T_EN_OFFSET)

#define HPIPE_PWR_CTR_REG			0x148
#define HPIPE_PWR_CTR_RST_DFE_OFFSET		0
#define HPIPE_PWR_CTR_RST_DFE_MASK		\
			(0x1 << HPIPE_PWR_CTR_RST_DFE_OFFSET)
#define HPIPE_PWR_CTR_SFT_RST_OFFSET		10
#define HPIPE_PWR_CTR_SFT_RST_MASK		\
			(0x1 << HPIPE_PWR_CTR_SFT_RST_OFFSET)

#define HPIPE_SPD_DIV_FORCE_REG				0x154
#define HPIPE_TXDIGCK_DIV_FORCE_OFFSET			7
#define HPIPE_TXDIGCK_DIV_FORCE_MASK			\
			(0x1 << HPIPE_TXDIGCK_DIV_FORCE_OFFSET)
#define HPIPE_SPD_DIV_FORCE_RX_SPD_DIV_OFFSET		8
#define HPIPE_SPD_DIV_FORCE_RX_SPD_DIV_MASK		\
			(0x3 << HPIPE_SPD_DIV_FORCE_RX_SPD_DIV_OFFSET)
#define HPIPE_SPD_DIV_FORCE_RX_SPD_DIV_FORCE_OFFSET	10
#define HPIPE_SPD_DIV_FORCE_RX_SPD_DIV_FORCE_MASK	\
			(0x1 << HPIPE_SPD_DIV_FORCE_RX_SPD_DIV_FORCE_OFFSET)
#define HPIPE_SPD_DIV_FORCE_TX_SPD_DIV_OFFSET		13
#define HPIPE_SPD_DIV_FORCE_TX_SPD_DIV_MASK		\
			(0x3 << HPIPE_SPD_DIV_FORCE_TX_SPD_DIV_OFFSET)
#define HPIPE_SPD_DIV_FORCE_TX_SPD_DIV_FORCE_OFFSET	15
#define HPIPE_SPD_DIV_FORCE_TX_SPD_DIV_FORCE_MASK	\
			(0x1 << HPIPE_SPD_DIV_FORCE_TX_SPD_DIV_FORCE_OFFSET)

/* HPIPE_RX_CLK_ALIGN90_AND_TX_IDLE_CALIBRATION_CTRL_REG */
#define HPIPE_RX_CLK_ALIGN90_AND_TX_IDLE_CALIB_CTRL_REG	0x168
#define HPIPE_CAL_RXCLKALIGN_90_EXT_EN_OFFSET		15
#define HPIPE_CAL_RXCLKALIGN_90_EXT_EN_MASK		\
			(0x1 << HPIPE_CAL_RXCLKALIGN_90_EXT_EN_OFFSET)
#define HPIPE_CAL_OS_PH_EXT_OFFSET			8
#define HPIPE_CAL_OS_PH_EXT_MASK			\
			(0x7f << HPIPE_CAL_OS_PH_EXT_OFFSET)

#define HPIPE_SAMPLER_N_PROC_CALIB_CTRL_REG	0x16C
#define HPIPE_RX_SAMPLER_OS_GAIN_OFFSET		6
#define HPIPE_RX_SAMPLER_OS_GAIN_MASK		\
			(0x3 << HPIPE_RX_SAMPLER_OS_GAIN_OFFSET)
#define HPIPE_SMAPLER_OFFSET			12
#define HPIPE_SMAPLER_MASK			\
			(0x1 << HPIPE_SMAPLER_OFFSET)

#define HPIPE_TX_REG1_REG			0x174
#define HPIPE_TX_REG1_TX_EMPH_RES_OFFSET	5
#define HPIPE_TX_REG1_TX_EMPH_RES_MASK		\
			(0x3 << HPIPE_TX_REG1_TX_EMPH_RES_OFFSET)
#define HPIPE_TX_REG1_SLC_EN_OFFSET		10
#define HPIPE_TX_REG1_SLC_EN_MASK		\
			(0x3f << HPIPE_TX_REG1_SLC_EN_OFFSET)

#define HPIPE_PWR_CTR_DTL_REG				0x184
#define HPIPE_PWR_CTR_DTL_SQ_DET_EN_OFFSET		0
#define HPIPE_PWR_CTR_DTL_SQ_DET_EN_MASK		\
			(0x1 << HPIPE_PWR_CTR_DTL_SQ_DET_EN_OFFSET)
#define HPIPE_PWR_CTR_DTL_SQ_PLOOP_EN_OFFSET		1
#define HPIPE_PWR_CTR_DTL_SQ_PLOOP_EN_MASK		\
			(0x1 << HPIPE_PWR_CTR_DTL_SQ_PLOOP_EN_OFFSET)
#define HPIPE_PWR_CTR_DTL_FLOOP_EN_OFFSET		2
#define HPIPE_PWR_CTR_DTL_FLOOP_EN_MASK			\
			(0x1 << HPIPE_PWR_CTR_DTL_FLOOP_EN_OFFSET)
#define HPIPE_PWR_CTR_DTL_CLAMPING_SEL_OFFSET		4
#define HPIPE_PWR_CTR_DTL_CLAMPING_SEL_MASK		\
			(0x7 << HPIPE_PWR_CTR_DTL_CLAMPING_SEL_OFFSET)
#define HPIPE_PWR_CTR_DTL_INTPCLK_DIV_FORCE_OFFSET	10
#define HPIPE_PWR_CTR_DTL_INTPCLK_DIV_FORCE_MASK	\
			(0x1 << HPIPE_PWR_CTR_DTL_INTPCLK_DIV_FORCE_OFFSET)
#define HPIPE_PWR_CTR_DTL_CLK_MODE_OFFSET		12
#define HPIPE_PWR_CTR_DTL_CLK_MODE_MASK			\
			(0x3 << HPIPE_PWR_CTR_DTL_CLK_MODE_OFFSET)
#define HPIPE_PWR_CTR_DTL_CLK_MODE_FORCE_OFFSET		14
#define HPIPE_PWR_CTR_DTL_CLK_MODE_FORCE_MASK		\
			(1 << HPIPE_PWR_CTR_DTL_CLK_MODE_FORCE_OFFSET)

#define HPIPE_PHASE_CONTROL_REG			0x188
#define HPIPE_OS_PH_OFFSET_OFFSET		0
#define HPIPE_OS_PH_OFFSET_MASK			\
			(0x7f << HPIPE_OS_PH_OFFSET_OFFSET)
#define HPIPE_OS_PH_OFFSET_FORCE_OFFSET		7
#define HPIPE_OS_PH_OFFSET_FORCE_MASK		\
			(0x1 << HPIPE_OS_PH_OFFSET_FORCE_OFFSET)
#define HPIPE_OS_PH_VALID_OFFSET		8
#define HPIPE_OS_PH_VALID_MASK			\
			(0x1 << HPIPE_OS_PH_VALID_OFFSET)

#define HPIPE_DATA_PHASE_OFF_CTRL_REG			0x1A0
#define HPIPE_DATA_PHASE_ADAPTED_OS_PH_OFFSET		9
#define HPIPE_DATA_PHASE_ADAPTED_OS_PH_MASK		\
			(0x7f << HPIPE_DATA_PHASE_ADAPTED_OS_PH_OFFSET)

#define HPIPE_ADAPTED_FFE_CAPACITOR_COUNTER_CTRL_REG	0x1A4
#define HPIPE_ADAPTED_FFE_ADAPTED_FFE_RES_OFFSET	12
#define HPIPE_ADAPTED_FFE_ADAPTED_FFE_RES_MASK		\
			(0x3 << HPIPE_ADAPTED_FFE_ADAPTED_FFE_RES_OFFSET)
#define HPIPE_ADAPTED_FFE_ADAPTED_FFE_CAP_OFFSET	8
#define HPIPE_ADAPTED_FFE_ADAPTED_FFE_CAP_MASK		\
			(0xf << HPIPE_ADAPTED_FFE_ADAPTED_FFE_CAP_OFFSET)

#define HPIPE_SQ_GLITCH_FILTER_CTRL		0x1c8
#define HPIPE_SQ_DEGLITCH_WIDTH_P_OFFSET	0
#define HPIPE_SQ_DEGLITCH_WIDTH_P_MASK		\
			(0xf << HPIPE_SQ_DEGLITCH_WIDTH_P_OFFSET)
#define HPIPE_SQ_DEGLITCH_WIDTH_N_OFFSET	4
#define HPIPE_SQ_DEGLITCH_WIDTH_N_MASK		\
			(0xf << HPIPE_SQ_DEGLITCH_WIDTH_N_OFFSET)
#define HPIPE_SQ_DEGLITCH_EN_OFFSET		8
#define HPIPE_SQ_DEGLITCH_EN_MASK		\
			(0x1 << HPIPE_SQ_DEGLITCH_EN_OFFSET)

#define HPIPE_FRAME_DETECT_CTRL_0_REG		0x214
#define HPIPE_TRAIN_PAT_NUM_OFFSET		0x7
#define HPIPE_TRAIN_PAT_NUM_MASK		\
			(0x1FF << HPIPE_TRAIN_PAT_NUM_OFFSET)

#define HPIPE_FRAME_DETECT_CTRL_3_REG			0x220
#define HPIPE_PATTERN_LOCK_LOST_TIMEOUT_EN_OFFSET	12
#define HPIPE_PATTERN_LOCK_LOST_TIMEOUT_EN_MASK		\
			(0x1 << HPIPE_PATTERN_LOCK_LOST_TIMEOUT_EN_OFFSET)

#define HPIPE_DME_REG				0x228
#define HPIPE_DME_ETHERNET_MODE_OFFSET		7
#define HPIPE_DME_ETHERNET_MODE_MASK		\
			(0x1 << HPIPE_DME_ETHERNET_MODE_OFFSET)

#define HPIPE_TRX_TRAIN_CTRL_0_REG		0x22c
#define HPIPE_TRX_TX_F0T_EO_BASED_OFFSET	14
#define HPIPE_TRX_TX_F0T_EO_BASED_MASK		\
			(1 << HPIPE_TRX_TX_F0T_EO_BASED_OFFSET)
#define HPIPE_TRX_UPDATE_THEN_HOLD_OFFSET	6
#define HPIPE_TRX_UPDATE_THEN_HOLD_MASK		\
			(1 << HPIPE_TRX_UPDATE_THEN_HOLD_OFFSET)
#define HPIPE_TRX_TX_CTRL_CLK_EN_OFFSET		5
#define HPIPE_TRX_TX_CTRL_CLK_EN_MASK		\
			(1 << HPIPE_TRX_TX_CTRL_CLK_EN_OFFSET)
#define HPIPE_TRX_RX_ANA_IF_CLK_ENE_OFFSET	4
#define HPIPE_TRX_RX_ANA_IF_CLK_ENE_MASK	\
			(1 << HPIPE_TRX_RX_ANA_IF_CLK_ENE_OFFSET)
#define HPIPE_TRX_TX_TRAIN_EN_OFFSET		1
#define HPIPE_TRX_TX_TRAIN_EN_MASK		\
			(1 << HPIPE_TRX_TX_TRAIN_EN_OFFSET)
#define HPIPE_TRX_RX_TRAIN_EN_OFFSET		0
#define HPIPE_TRX_RX_TRAIN_EN_MASK		\
			(1 << HPIPE_TRX_RX_TRAIN_EN_OFFSET)

#define HPIPE_TX_TRAIN_CTRL_0_REG		0x268
#define HPIPE_TX_TRAIN_P2P_HOLD_OFFSET		15
#define HPIPE_TX_TRAIN_P2P_HOLD_MASK		\
			(0x1 << HPIPE_TX_TRAIN_P2P_HOLD_OFFSET)

#define HPIPE_TX_TRAIN_CTRL_REG			0x26C
#define HPIPE_TX_TRAIN_CTRL_G1_OFFSET		0
#define HPIPE_TX_TRAIN_CTRL_G1_MASK		\
			(0x1 << HPIPE_TX_TRAIN_CTRL_G1_OFFSET)
#define HPIPE_TX_TRAIN_CTRL_GN1_OFFSET		1
#define HPIPE_TX_TRAIN_CTRL_GN1_MASK		\
			(0x1 << HPIPE_TX_TRAIN_CTRL_GN1_OFFSET)
#define HPIPE_TX_TRAIN_CTRL_G0_OFFSET		2
#define HPIPE_TX_TRAIN_CTRL_G0_MASK		\
			(0x1 << HPIPE_TX_TRAIN_CTRL_G0_OFFSET)

#define HPIPE_TX_TRAIN_CTRL_4_REG		0x278
#define HPIPE_TRX_TRAIN_TIMER_OFFSET		0
#define HPIPE_TRX_TRAIN_TIMER_MASK		\
			(0x3FF << HPIPE_TRX_TRAIN_TIMER_OFFSET)

#define HPIPE_TX_TRAIN_CTRL_5_REG		0x2A4
#define HPIPE_RX_TRAIN_TIMER_OFFSET		0
#define HPIPE_RX_TRAIN_TIMER_MASK		\
			(0x3ff << HPIPE_RX_TRAIN_TIMER_OFFSET)
#define HPIPE_TX_TRAIN_START_SQ_EN_OFFSET	11
#define HPIPE_TX_TRAIN_START_SQ_EN_MASK		\
			(0x1 << HPIPE_TX_TRAIN_START_SQ_EN_OFFSET)
#define HPIPE_TX_TRAIN_START_FRM_DET_EN_OFFSET	12
#define HPIPE_TX_TRAIN_START_FRM_DET_EN_MASK	\
			(0x1 << HPIPE_TX_TRAIN_START_FRM_DET_EN_OFFSET)
#define HPIPE_TX_TRAIN_START_FRM_LOCK_EN_OFFSET	13
#define HPIPE_TX_TRAIN_START_FRM_LOCK_EN_MASK	\
			(0x1 << HPIPE_TX_TRAIN_START_FRM_LOCK_EN_OFFSET)
#define HPIPE_TX_TRAIN_WAIT_TIME_EN_OFFSET	14
#define HPIPE_TX_TRAIN_WAIT_TIME_EN_MASK	\
			(0x1 << HPIPE_TX_TRAIN_WAIT_TIME_EN_OFFSET)

#define HPIPE_INTERRUPT_1_REGISTER		0x2AC
#define HPIPE_TRX_TRAIN_FAILED_OFFSET		6
#define HPIPE_TRX_TRAIN_FAILED_MASK		\
			(1 << HPIPE_TRX_TRAIN_FAILED_OFFSET)
#define HPIPE_TRX_TRAIN_TIME_OUT_INT_OFFSET	5
#define HPIPE_TRX_TRAIN_TIME_OUT_INT_MASK	\
			(1 << HPIPE_TRX_TRAIN_TIME_OUT_INT_OFFSET)
#define HPIPE_INTERRUPT_TRX_TRAIN_DONE_OFFSET	4
#define HPIPE_INTERRUPT_TRX_TRAIN_DONE_MASK	\
			(1 << HPIPE_INTERRUPT_TRX_TRAIN_DONE_OFFSET)
#define HPIPE_INTERRUPT_DFE_DONE_INT_OFFSET	3
#define HPIPE_INTERRUPT_DFE_DONE_INT_MASK	\
			(1 << HPIPE_INTERRUPT_DFE_DONE_INT_OFFSET)
#define HPIPE_INTERRUPT_RX_TRAIN_COMPLETE_INT_OFFSET	1
#define HPIPE_INTERRUPT_RX_TRAIN_COMPLETE_INT_MASK	\
			(1 << HPIPE_INTERRUPT_RX_TRAIN_COMPLETE_INT_OFFSET)

#define HPIPE_TX_TRAIN_REG			0x31C
#define HPIPE_TX_TRAIN_CHK_INIT_OFFSET		4
#define HPIPE_TX_TRAIN_CHK_INIT_MASK		\
			(0x1 << HPIPE_TX_TRAIN_CHK_INIT_OFFSET)
#define HPIPE_TX_TRAIN_COE_FM_PIN_PCIE3_OFFSET	7
#define HPIPE_TX_TRAIN_COE_FM_PIN_PCIE3_MASK	\
			(0x1 << HPIPE_TX_TRAIN_COE_FM_PIN_PCIE3_OFFSET)
#define HPIPE_TX_TRAIN_16BIT_AUTO_EN_OFFSET	8
#define HPIPE_TX_TRAIN_16BIT_AUTO_EN_MASK	\
			(0x1 << HPIPE_TX_TRAIN_16BIT_AUTO_EN_OFFSET)
#define HPIPE_TX_TRAIN_PAT_SEL_OFFSET		9
#define HPIPE_TX_TRAIN_PAT_SEL_MASK		\
			(0x1 << HPIPE_TX_TRAIN_PAT_SEL_OFFSET)

#define HPIPE_SAVED_DFE_VALUES_REG		0x328
#define HPIPE_SAVED_DFE_VALUES_SAV_F0D_OFFSET	10
#define HPIPE_SAVED_DFE_VALUES_SAV_F0D_MASK	\
			(0x3f << HPIPE_SAVED_DFE_VALUES_SAV_F0D_OFFSET)

#define HPIPE_CDR_CONTROL_REG			0x418
#define HPIPE_CDR_RX_MAX_DFE_ADAPT_0_OFFSET	14
#define HPIPE_CDR_RX_MAX_DFE_ADAPT_0_MASK	\
			(0x3 << HPIPE_CDR_RX_MAX_DFE_ADAPT_0_OFFSET)
#define HPIPE_CDR_RX_MAX_DFE_ADAPT_1_OFFSET	12
#define HPIPE_CDR_RX_MAX_DFE_ADAPT_1_MASK	\
			(0x3 << HPIPE_CDR_RX_MAX_DFE_ADAPT_1_OFFSET)
#define HPIPE_CDR_MAX_DFE_ADAPT_0_OFFSET	9
#define HPIPE_CDR_MAX_DFE_ADAPT_0_MASK		\
			(0x7 << HPIPE_CDR_MAX_DFE_ADAPT_0_OFFSET)
#define HPIPE_CDR_MAX_DFE_ADAPT_1_OFFSET	6
#define HPIPE_CDR_MAX_DFE_ADAPT_1_MASK		\
			(0x7 << HPIPE_CDR_MAX_DFE_ADAPT_1_OFFSET)

#define HPIPE_TX_TRAIN_CTRL_11_REG		0x438
#define HPIPE_TX_STATUS_CHECK_MODE_OFFSET	6
#define HPIPE_TX_TX_STATUS_CHECK_MODE_MASK	\
			(0x1 << HPIPE_TX_STATUS_CHECK_MODE_OFFSET)
#define HPIPE_TX_NUM_OF_PRESET_OFFSET		10
#define HPIPE_TX_NUM_OF_PRESET_MASK		\
			(0x7 << HPIPE_TX_NUM_OF_PRESET_OFFSET)
#define HPIPE_TX_SWEEP_PRESET_EN_OFFSET		15
#define HPIPE_TX_SWEEP_PRESET_EN_MASK		\
			(0x1 << HPIPE_TX_SWEEP_PRESET_EN_OFFSET)

#define HPIPE_G1_SETTINGS_3_REG				0x440
#define HPIPE_G1_SETTINGS_3_G1_FFE_CAP_SEL_OFFSET	0
#define HPIPE_G1_SETTINGS_3_G1_FFE_CAP_SEL_MASK		\
			(0xf << HPIPE_G1_SETTINGS_3_G1_FFE_CAP_SEL_OFFSET)
#define HPIPE_G1_SETTINGS_3_G1_FFE_RES_SEL_OFFSET	4
#define HPIPE_G1_SETTINGS_3_G1_FFE_RES_SEL_MASK		\
			(0x7 << HPIPE_G1_SETTINGS_3_G1_FFE_RES_SEL_OFFSET)
#define HPIPE_G1_SETTINGS_3_G1_FFE_SETTING_FORCE_OFFSET	7
#define HPIPE_G1_SETTINGS_3_G1_FFE_SETTING_FORCE_MASK	\
			(0x1 << HPIPE_G1_SETTINGS_3_G1_FFE_SETTING_FORCE_OFFSET)
#define HPIPE_G1_SETTINGS_3_G1_FBCK_SEL_OFFSET		9
#define HPIPE_G1_SETTINGS_3_G1_FBCK_SEL_MASK		\
			(0x1 << HPIPE_G1_SETTINGS_3_G1_FBCK_SEL_OFFSET)
#define HPIPE_G1_SETTINGS_3_G1_FFE_DEG_RES_LEVEL_OFFSET	12
#define HPIPE_G1_SETTINGS_3_G1_FFE_DEG_RES_LEVEL_MASK	\
			(0x3 << HPIPE_G1_SETTINGS_3_G1_FFE_DEG_RES_LEVEL_OFFSET)
#define HPIPE_G1_SETTINGS_3_G1_FFE_LOAD_RES_LEVEL_OFFSET	14
#define HPIPE_G1_SETTINGS_3_G1_FFE_LOAD_RES_LEVEL_MASK	\
		(0x3 << HPIPE_G1_SETTINGS_3_G1_FFE_LOAD_RES_LEVEL_OFFSET)

#define HPIPE_G1_SETTINGS_4_REG			0x444
#define HPIPE_G1_SETTINGS_4_G1_DFE_RES_OFFSET	8
#define HPIPE_G1_SETTINGS_4_G1_DFE_RES_MASK	\
			(0x3 << HPIPE_G1_SETTINGS_4_G1_DFE_RES_OFFSET)

#define HPIPE_G2_SETTINGS_4_REG			0x44c
#define HPIPE_G2_DFE_RES_OFFSET			8
#define HPIPE_G2_DFE_RES_MASK			\
			(0x3 << HPIPE_G2_DFE_RES_OFFSET)

#define HPIPE_G3_SETTING_3_REG			0x450
#define HPIPE_G3_FFE_CAP_SEL_OFFSET		0
#define HPIPE_G3_FFE_CAP_SEL_MASK		\
			(0xf << HPIPE_G3_FFE_CAP_SEL_OFFSET)
#define HPIPE_G3_FFE_RES_SEL_OFFSET		4
#define HPIPE_G3_FFE_RES_SEL_MASK		\
			(0x7 << HPIPE_G3_FFE_RES_SEL_OFFSET)
#define HPIPE_G3_FFE_SETTING_FORCE_OFFSET	7
#define HPIPE_G3_FFE_SETTING_FORCE_MASK		\
			(0x1 << HPIPE_G3_FFE_SETTING_FORCE_OFFSET)
#define HPIPE_G3_FFE_DEG_RES_LEVEL_OFFSET	12
#define HPIPE_G3_FFE_DEG_RES_LEVEL_MASK		\
			(0x3 << HPIPE_G3_FFE_DEG_RES_LEVEL_OFFSET)
#define HPIPE_G3_FFE_LOAD_RES_LEVEL_OFFSET	14
#define HPIPE_G3_FFE_LOAD_RES_LEVEL_MASK	\
			(0x3 << HPIPE_G3_FFE_LOAD_RES_LEVEL_OFFSET)

#define HPIPE_G3_SETTING_4_REG			0x454
#define HPIPE_G3_DFE_RES_OFFSET			8
#define HPIPE_G3_DFE_RES_MASK			(0x3 << HPIPE_G3_DFE_RES_OFFSET)

#define HPIPE_TX_PRESET_INDEX_REG		0x468
#define HPIPE_TX_PRESET_INDEX_OFFSET		0
#define HPIPE_TX_PRESET_INDEX_MASK		\
			(0xf << HPIPE_TX_PRESET_INDEX_OFFSET)

#define HPIPE_DFE_CONTROL_REG			0x470
#define HPIPE_DFE_TX_MAX_DFE_ADAPT_OFFSET	14
#define HPIPE_DFE_TX_MAX_DFE_ADAPT_MASK		\
			(0x3 << HPIPE_DFE_TX_MAX_DFE_ADAPT_OFFSET)

#define HPIPE_DFE_CTRL_28_REG			0x49C
#define HPIPE_DFE_CTRL_28_PIPE4_OFFSET		7
#define HPIPE_DFE_CTRL_28_PIPE4_MASK		\
			(0x1 << HPIPE_DFE_CTRL_28_PIPE4_OFFSET)

#define HPIPE_G1_SETTING_5_REG			0x538
#define HPIPE_G1_SETTING_5_G1_ICP_OFFSET	0
#define HPIPE_G1_SETTING_5_G1_ICP_MASK		\
			(0xf << HPIPE_G1_SETTING_5_G1_ICP_OFFSET)

#define HPIPE_G3_SETTING_5_REG			0x548
#define HPIPE_G3_SETTING_5_G3_ICP_OFFSET	0
#define HPIPE_G3_SETTING_5_G3_ICP_MASK		\
			(0xf << HPIPE_G3_SETTING_5_G3_ICP_OFFSET)

#define HPIPE_LANE_CONFIG0_REG			0x600
#define HPIPE_LANE_CONFIG0_TXDEEMPH0_OFFSET	0
#define HPIPE_LANE_CONFIG0_TXDEEMPH0_MASK	\
			(0x1 << HPIPE_LANE_CONFIG0_TXDEEMPH0_OFFSET)

#define HPIPE_LANE_STATUS1_REG			0x60C
#define HPIPE_LANE_STATUS1_PCLK_EN_OFFSET	0
#define HPIPE_LANE_STATUS1_PCLK_EN_MASK		\
			(0x1 << HPIPE_LANE_STATUS1_PCLK_EN_OFFSET)

#define HPIPE_LANE_CFG4_REG			0x620
#define HPIPE_LANE_CFG4_DFE_CTRL_OFFSET		0
#define HPIPE_LANE_CFG4_DFE_CTRL_MASK		\
			(0x7 << HPIPE_LANE_CFG4_DFE_CTRL_OFFSET)
#define HPIPE_LANE_CFG4_DFE_EN_SEL_OFFSET	3
#define HPIPE_LANE_CFG4_DFE_EN_SEL_MASK		\
			(0x1 << HPIPE_LANE_CFG4_DFE_EN_SEL_OFFSET)
#define HPIPE_LANE_CFG4_DFE_OVER_OFFSET		6
#define HPIPE_LANE_CFG4_DFE_OVER_MASK		\
			(0x1 << HPIPE_LANE_CFG4_DFE_OVER_OFFSET)
#define HPIPE_LANE_CFG4_SSC_CTRL_OFFSET		7
#define HPIPE_LANE_CFG4_SSC_CTRL_MASK		\
			(0x1 << HPIPE_LANE_CFG4_SSC_CTRL_OFFSET)

#define HPIPE_LANE_EQ_REMOTE_SETTING_REG	0x6f8
#define HPIPE_LANE_CFG_FOM_DIRN_OVERRIDE_OFFSET	0
#define HPIPE_LANE_CFG_FOM_DIRN_OVERRIDE_MASK	\
			(0x1 << HPIPE_LANE_CFG_FOM_DIRN_OVERRIDE_OFFSET)
#define HPIPE_LANE_CFG_FOM_ONLY_MODE_OFFFSET	1
#define HPIPE_LANE_CFG_FOM_ONLY_MODE_MASK	\
			(0x1 << HPIPE_LANE_CFG_FOM_ONLY_MODE_OFFFSET)
#define HPIPE_LANE_CFG_FOM_PRESET_VECTOR_OFFSET	2
#define HPIPE_LANE_CFG_FOM_PRESET_VECTOR_MASK	\
			(0xf << HPIPE_LANE_CFG_FOM_PRESET_VECTOR_OFFSET)

#define HPIPE_LANE_EQU_CONFIG_0_REG		0x69C
#define HPIPE_CFG_PHY_RC_EP_OFFSET		12
#define HPIPE_CFG_PHY_RC_EP_MASK		\
			(0x1 << HPIPE_CFG_PHY_RC_EP_OFFSET)

#define HPIPE_LANE_EQ_CFG1_REG			0x6a0
#define HPIPE_CFG_UPDATE_POLARITY_OFFSET	12
#define HPIPE_CFG_UPDATE_POLARITY_MASK		\
			(0x1 << HPIPE_CFG_UPDATE_POLARITY_OFFSET)

#define HPIPE_LANE_EQ_CFG2_REG			0x6a4
#define HPIPE_CFG_EQ_BUNDLE_DIS_OFFSET		14
#define HPIPE_CFG_EQ_BUNDLE_DIS_MASK		\
			(0x1 << HPIPE_CFG_EQ_BUNDLE_DIS_OFFSET)

#define HPIPE_RST_CLK_CTRL_REG			0x704
#define HPIPE_RST_CLK_CTRL_PIPE_RST_OFFSET	0
#define HPIPE_RST_CLK_CTRL_PIPE_RST_MASK	\
			(0x1 << HPIPE_RST_CLK_CTRL_PIPE_RST_OFFSET)
#define HPIPE_RST_CLK_CTRL_FIXED_PCLK_OFFSET	2
#define HPIPE_RST_CLK_CTRL_FIXED_PCLK_MASK	\
			(0x1 << HPIPE_RST_CLK_CTRL_FIXED_PCLK_OFFSET)
#define HPIPE_RST_CLK_CTRL_PIPE_WIDTH_OFFSET	3
#define HPIPE_RST_CLK_CTRL_PIPE_WIDTH_MASK	\
			(0x1 << HPIPE_RST_CLK_CTRL_PIPE_WIDTH_OFFSET)
#define HPIPE_RST_CLK_CTRL_CORE_FREQ_SEL_OFFSET	9
#define HPIPE_RST_CLK_CTRL_CORE_FREQ_SEL_MASK	\
			(0x1 << HPIPE_RST_CLK_CTRL_CORE_FREQ_SEL_OFFSET)

#define HPIPE_TST_MODE_CTRL_REG			0x708
#define HPIPE_TST_MODE_CTRL_MODE_MARGIN_OFFSET	2
#define HPIPE_TST_MODE_CTRL_MODE_MARGIN_MASK	\
			(0x1 << HPIPE_TST_MODE_CTRL_MODE_MARGIN_OFFSET)

#define HPIPE_CLK_SRC_LO_REG				0x70c
#define HPIPE_CLK_SRC_LO_BUNDLE_PERIOD_SEL_OFFSET	1
#define HPIPE_CLK_SRC_LO_BUNDLE_PERIOD_SEL_MASK		\
			(0x1 << HPIPE_CLK_SRC_LO_BUNDLE_PERIOD_SEL_OFFSET)
#define HPIPE_CLK_SRC_LO_BUNDLE_PERIOD_SCALE_OFFSET	2
#define HPIPE_CLK_SRC_LO_BUNDLE_PERIOD_SCALE_MASK	\
			(0x3 << HPIPE_CLK_SRC_LO_BUNDLE_PERIOD_SCALE_OFFSET)
#define HPIPE_CLK_SRC_LO_PLL_RDY_DL_OFFSET		5
#define HPIPE_CLK_SRC_LO_PLL_RDY_DL_MASK		\
			(0x7 << HPIPE_CLK_SRC_LO_PLL_RDY_DL_OFFSET)

#define HPIPE_CLK_SRC_HI_REG			0x710
#define HPIPE_CLK_SRC_HI_LANE_STRT_OFFSET	0
#define HPIPE_CLK_SRC_HI_LANE_STRT_MASK		\
			(0x1 << HPIPE_CLK_SRC_HI_LANE_STRT_OFFSET)
#define HPIPE_CLK_SRC_HI_LANE_BREAK_OFFSET	1
#define HPIPE_CLK_SRC_HI_LANE_BREAK_MASK	\
			(0x1 << HPIPE_CLK_SRC_HI_LANE_BREAK_OFFSET)
#define HPIPE_CLK_SRC_HI_LANE_MASTER_OFFSET	2
#define HPIPE_CLK_SRC_HI_LANE_MASTER_MASK	\
			(0x1 << HPIPE_CLK_SRC_HI_LANE_MASTER_OFFSET)
#define HPIPE_CLK_SRC_HI_MODE_PIPE_OFFSET	7
#define HPIPE_CLK_SRC_HI_MODE_PIPE_MASK		\
			(0x1 << HPIPE_CLK_SRC_HI_MODE_PIPE_OFFSET)

#define HPIPE_GLOBAL_MISC_CTRL			0x718
#define HPIPE_GLOBAL_PM_CTRL			0x740
#define HPIPE_GLOBAL_PM_RXDLOZ_WAIT_OFFSET	0
#define HPIPE_GLOBAL_PM_RXDLOZ_WAIT_MASK	\
			(0xFF << HPIPE_GLOBAL_PM_RXDLOZ_WAIT_OFFSET)

/* General defines */
#define PLL_LOCK_TIMEOUT			15000

#endif /* _PHY_COMPHY_CP110_H */

