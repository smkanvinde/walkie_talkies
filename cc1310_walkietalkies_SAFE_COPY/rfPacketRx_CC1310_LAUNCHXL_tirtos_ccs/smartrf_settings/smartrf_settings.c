

//*********************************************************************************
// Generated by SmartRF Studio version 2.6.0 (build #8)
// Tested for SimpleLink SDK version: CC13x0 SDK 1.30.xx.xx
// Device: CC1350 Rev. 2.1 (Rev. B)
//
//*********************************************************************************


//*********************************************************************************
// Parameter summary
// Address: off
// Address0: 0xAA
// Address1: 0xBB
// Frequency: 915.00000 MHz
// Data Format: Serial mode disable
// Deviation: 175.000 kHz
// Packet Length Config: Variable
// Max Packet Length: 128
// Packet Length: 20
// RX Filter BW: 1243 kHz
// Symbol Rate: 500.00000 kBaud
// Sync Word Length: 32 Bits
// TX Power: 14 dBm (requires define CCFG_FORCE_VDDR_HH = 1 in ccfg.c, see CC13xx/CC26xx Technical Reference Manual)
// Whitening: No whitening

#define DEVICE_FAMILY cc13x0

#ifdef DEVICE_FAMILY
    #undef DEVICE_FAMILY_PATH
    #define DEVICE_FAMILY_PATH(x) <ti/devices/DEVICE_FAMILY/x>
#else
    #error "You must define DEVICE_FAMILY at the project level as one of cc26x0, cc26x0r2, cc13x0, etc."
#endif


#include DEVICE_FAMILY_PATH(driverlib/rf_mailbox.h)
#include DEVICE_FAMILY_PATH(driverlib/rf_common_cmd.h)
#include DEVICE_FAMILY_PATH(driverlib/rf_prop_cmd.h)
#include <ti/drivers/rf/RF.h>
#include DEVICE_FAMILY_PATH(rf_patches/rf_patch_cpe_genfsk.h)
#include DEVICE_FAMILY_PATH(rf_patches/rf_patch_rfe_genfsk.h)
#include "smartrf_settings.h"


// TI-RTOS RF Mode Object
RF_Mode RF_prop =
{
    .rfMode = RF_MODE_PROPRIETARY_SUB_1,
    .cpePatchFxn = &rf_patch_cpe_genfsk,
    .mcePatchFxn = 0,
    .rfePatchFxn = &rf_patch_rfe_genfsk,
};

// Overrides for CMD_PROP_RADIO_DIV_SETUP
static uint32_t pOverrides[] =
{
    // override_use_patch_prop_genfsk.xml
    // PHY: Use MCE ROM bank 4, RFE RAM patch
    MCE_RFE_OVERRIDE(0,4,0,1,0,0),
    // override_synth_prop_863_930_div5.xml
    // Synth: Set recommended RTRIM to 7
    HW_REG_OVERRIDE(0x4038,0x0037),
    // Synth: Set Fref to 4 MHz
    (uint32_t)0x000684A3,
    // Synth: Configure fine calibration setting
    HW_REG_OVERRIDE(0x4020,0x7F00),
    // Synth: Configure fine calibration setting
    HW_REG_OVERRIDE(0x4064,0x0040),
    // Synth: Configure fine calibration setting
    (uint32_t)0xB1070503,
    // Synth: Configure fine calibration setting
    (uint32_t)0x05330523,
    // Synth: Set loop bandwidth after lock to 20 kHz
    (uint32_t)0x0A480583,
    // Synth: Set loop bandwidth after lock to 20 kHz
    (uint32_t)0x7AB80603,
    // Synth: Configure VCO LDO (in ADI1, set VCOLDOCFG=0x9F to use voltage input reference)
    ADI_REG_OVERRIDE(1,4,0x9F),
    // Synth: Configure synth LDO (in ADI1, set SLDOCTL0.COMP_CAP=1)
    ADI_HALFREG_OVERRIDE(1,7,0x4,0x4),
    // Synth: Use 24 MHz XOSC as synth clock, enable extra PLL filtering
    (uint32_t)0x02010403,
    // Synth: Configure extra PLL filtering
    (uint32_t)0x00108463,
    // Synth: Increase synth programming timeout (0x04B0 RAT ticks = 300 us)
    (uint32_t)0x04B00243,
    // override_synth_disable_bias_div5.xml
    // Synth: Set divider bias to disabled
    HW32_ARRAY_OVERRIDE(0x405C,1),
    // Synth: Set divider bias to disabled (specific for loDivider=5)
    (uint32_t)0x18000200,
    // override_phy_rx_aaf_bw_0x0.xml
    // Rx: Set anti-aliasing filter bandwidth to 0x0 (in ADI0, set IFAMPCTL3[7:4]=0x0)
    ADI_HALFREG_OVERRIDE(0,61,0xF,0x0),
    // override_phy_gfsk_rx.xml
    // Rx: Set LNA bias current trim offset to 3
    (uint32_t)0x00038883,
    // Rx: Freeze RSSI on sync found event
    HW_REG_OVERRIDE(0x6084,0x35F1),
    // override_phy_gfsk_pa_ramp_5us_agc_reflevel_0x24.xml
    // Tx: Configure PA ramping setting (0x10) for approximately 5 us PA ramp time. Rx: Set AGC reference level to 0x24.
    HW_REG_OVERRIDE(0x6088,0x1024),
    // Tx: Configure PA ramping setting (0x08) for approximately 5 us PA ramp time
    HW_REG_OVERRIDE(0x608C,0x0813),
    // override_phy_rx_rssi_offset_5db.xml
    // Rx: Set RSSI offset to adjust reported RSSI by +5 dB
    (uint32_t)0x00FB88A3,
    // TX power override
    // Tx: Set PA trim to max (in ADI0, set PACTL0=0xF8)
    ADI_REG_OVERRIDE(0,12,0xF8),
    (uint32_t)0xFFFFFFFF,
};


// CMD_PROP_RADIO_DIV_SETUP
// Proprietary Mode Radio Setup Command for All Frequency Bands
rfc_CMD_PROP_RADIO_DIV_SETUP_t RF_cmdPropRadioDivSetup =
{
    .commandNo = 0x3807,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .modulation.modType = 0x1,
    .modulation.deviation = 0x2BC,
    .symbolRate.preScale = 0x6,
    .symbolRate.rateWord = 0x20000,
    .rxBw = 0x2F,
    .preamConf.nPreamBytes = 0x4,
    .preamConf.preamMode = 0x0,
    .formatConf.nSwBits = 0x20,
    .formatConf.bBitReversal = 0x0,
    .formatConf.bMsbFirst = 0x1,
    .formatConf.fecMode = 0x0,
    .formatConf.whitenMode = 0x0,
    .config.frontEndMode = 0x0,
    .config.biasMode = 0x1,
    .config.analogCfgMode = 0x0,
    .config.bNoFsPowerUp = 0x0,
    .txPower = 0xA73F,
    .pRegOverride = pOverrides,
    .centerFreq = 0x0393,
    .intFreq = 0x8000,
    .loDivider = 0x05,
};

// CMD_FS
// Frequency Synthesizer Programming Command
rfc_CMD_FS_t RF_cmdFs =
{
    .commandNo = 0x0803,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .frequency = 0x0393,
    .fractFreq = 0x0000,
    .synthConf.bTxMode = 0x0,
    .synthConf.refFreq = 0x0,
    .__dummy0 = 0x00,
    .__dummy1 = 0x00,
    .__dummy2 = 0x00,
    .__dummy3 = 0x0000,
};

// CMD_PROP_TX
// Proprietary Mode Transmit Command
rfc_CMD_PROP_TX_t RF_cmdPropTx =
{
    .commandNo = 0x3801,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .pktConf.bFsOff = 0x0,
    .pktConf.bUseCrc = 0x1,
    .pktConf.bVarLen = 0x1,
    .pktLen = 0x14, // SET APPLICATION PAYLOAD LENGTH
    .syncWord = 0x930B51DE,
    .pPkt = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
};

// CMD_PROP_RX
// Proprietary Mode Receive Command
rfc_CMD_PROP_RX_t RF_cmdPropRx =
{
    .commandNo = 0x3802,
    .status = 0x0000,
    .pNextOp = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
    .startTime = 0x00000000,
    .startTrigger.triggerType = 0x0,
    .startTrigger.bEnaCmd = 0x0,
    .startTrigger.triggerNo = 0x0,
    .startTrigger.pastTrig = 0x0,
    .condition.rule = 0x1,
    .condition.nSkip = 0x0,
    .pktConf.bFsOff = 0x0,
    .pktConf.bRepeatOk = 0x0,
    .pktConf.bRepeatNok = 0x0,
    .pktConf.bUseCrc = 0x1,
    .pktConf.bVarLen = 0x1,
    .pktConf.bChkAddress = 0x0,
    .pktConf.endType = 0x0,
    .pktConf.filterOp = 0x0,
    .rxConf.bAutoFlushIgnored = 0x0,
    .rxConf.bAutoFlushCrcErr = 0x0,
    .rxConf.bIncludeHdr = 0x1,
    .rxConf.bIncludeCrc = 0x0,
    .rxConf.bAppendRssi = 0x0,
    .rxConf.bAppendTimestamp = 0x0,
    .rxConf.bAppendStatus = 0x1,
    .syncWord = 0x930B51DE,
    .maxPktLen = 0x80, // MAKE SURE DATA ENTRY IS LARGE ENOUGH
    .address0 = 0xAA,
    .address1 = 0xBB,
    .endTrigger.triggerType = 0x1,
    .endTrigger.bEnaCmd = 0x0,
    .endTrigger.triggerNo = 0x0,
    .endTrigger.pastTrig = 0x0,
    .endTime = 0x00000000,
    .pQueue = 0, // INSERT APPLICABLE POINTER: (dataQueue_t*)&xxx
    .pOutput = 0, // INSERT APPLICABLE POINTER: (uint8_t*)&xxx
};

