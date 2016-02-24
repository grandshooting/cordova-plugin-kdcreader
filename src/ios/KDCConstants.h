//
//  KDCConstants.h
//  KDCReader
//
//  Created by KoamTac on 10/18/14.
//  Copyright (c) 2014 AISolution. All rights reserved.
//

#ifndef KDCReader_KDCConstants_h
#define KDCReader_KDCConstants_h

enum EnableDisable
{
    DISABLE = 0,
    ENABLE
};

enum KDCMode
{
    NORMAL = 0,
    APPLICATION
};

enum DataDelimiter
{
    NONE = 0,
    TAB,
    SPACE,
    COMMA,
    SEMICOLON
};

enum RecordDelimiter
{
    RECORD_NONE = 0,
    RECORD_LF,
    RECORD_CR,
    RECORD_TAB,
    RECORD_CRnLF
};

enum NFCDataFormat
{
    NFC_PACKET_FORMAT = 0,
    NFC_DATA_ONLY
};

enum AESKeyLength
{
    AES_KEY_128 = 0,
    AES_KEY_192,
    AES_KEY_256
};

enum WedgeMode
{
    WEDGE_ONLY = 0,
    WEDGE_STORE,
    STORE_ONLY,
    STORE_IF_SENT,
    STORE_IF_NOT_SENT
};

enum AIMID
{
    AIMID_NONE = 0,
    IN_PREFIX,
    IN_SUFFIX
};

enum DataTerminator
{
    TERMINATOR_NONE = 0,
    TERMINATOR_CR,
    TERMINATOR_LF,
    TERMINATOR_CRnLF,
    TERMINATOR_TAB,
    RIHGT_ARROW,
    LEFT_ARROW,
    DOWN_ARROW,
    UP_ARROW
};

enum PowerOnTime
{
    POWERON_DISABLED = 0,
    POWERON_1_SECOND,
    POWERON_2_SECONDS,
    POWERON_3_SECONDS,
    POWERON_4_SECONDS,
    POWERON_5_SECONDS,
    POWERON_6_SECONDS,
    POWERON_7_SECONDS,
    POWERON_8_SECONDS,
    POWERON_9_SECONDS,
    POWERON_10_SECONDS
};

enum SleepTimeout
{
    SLEEP_TIMEOUT_DISABLED = 0,
    SLEEP_TIMEOUT_1_SECOND = 1,
    SLEEP_TIMEOUT_2_SECONDS = 2,
    SLEEP_TIMEOUT_3_SECONDS = 3,
    SLEEP_TIMEOUT_4_SECONDS = 4 ,
    SLEEP_TIMEOUT_5_SECONDS = 5,
    SLEEP_TIMEOUT_10_SECONDS = 10,
    SLEEP_TIMEOUT_20_SECONDS = 20,
    SLEEP_TIMEOUT_30_SECONDS = 30,
    SLEEP_TIMEOUT_60_SECONDS = 60,
    SLEEP_TIMEOUT_120_SECONDS = 120,
    SLEEP_TIMEOUT_300_SECONDS = 300,
    SLEEP_TIMEOUT_600_SECONDS = 600
};

enum DisplayFormat
{
    TIME_BATTERY = 0,
    DISPLAY_FORMAT_TYPE_TIME,
    DISPLAY_FORMAT_TYPE_BATTERY,
    DISPLAY_FORMAT_MEMORY_STATUS,
    DISPLAY_FORMAT_GPS_DATA,
    DISPLAY_FORMAT_BARCODE_ONLY
};

enum AutoPowerOffTimeout
{
    POWEROFF_DISABLE = 0,
    POWEROFF_5_MINUTES = 5,
    POWEROFF_10_MINUTES = 10,
    POWEROFF_20_MINUTES = 20,
    POWEROFF_30_MINUTES = 30,
    POWEROFF_60_MINUTES = 60,
    POWEROFF_120_MINUTES = 120
};

struct DateTime
{
    uint8_t     Year;
    uint8_t     Month;
    uint8_t     Day;
    uint8_t     Hour;
    uint8_t     Minute;
    uint8_t     Second;
};

enum MemoryConfiguration
{
    MEMORY_0p5M_3p5M = 0,
    MEMORY_1M_3M,
    MEMORY_2M_2M,
    MEMORY_3M_1M,
    MEMORY_4M_0M
};

enum GPSPowerSaveMode
{
    GPS_NORMAL = 0,
    GPS_POWER_SAVE
};

struct BarcodeSymbolSettings
{
    uint32_t    FirstSymbols;
    uint32_t    SecondSymbols;
} CurrentBarcodeSymbols;

struct BarcodeOptionSettings
{
    uint32_t    FirstOptions;
    uint32_t    SecondOptions;
} CurrentBarcodeOptions;

enum ScanTimeout
{
    SCANTIMEOUT_500_MS = 500,
    SCANTIMEOUT_1_SECOND = 1000,
    SCANTIMEOUT_2_SECONDS = 2000,
    SCANTIMEOUT_3_SECONDS = 3000,
    SCANTIMEOUT_4_SECONDS = 4000,
    SCANTIMEOUT_5_SECONDS = 5000,
    SCANTIMEOUT_6_SECONDS = 6000,
    SCANTIMEOUT_7_SECONDS = 7000,
    SCANTIMEOUT_8_SECONDS = 8000,
    SCANTIMEOUT_9_SECONDS = 9000,
    SCANTIMEOUT_10_SECONDS = 10000
};

enum AutoTriggerRereadDelay
{
    REREAD_CONTINUOUS = 0,
    REREAD_SHORT,
    REREAD_MEDIUM,
    REREAD_LONG,
    REREAD_EXTRA_LONG
};

enum PartialAction
{
    ERASE = 0,
    SELECT
};

enum DataFormat
{
    BARCODE_ONLY = 0,
    PACKET_DATA
};

enum MessageFontSize
{
    FONT_8x8 = 0,
    FONT_8x16,
    FONT_16x16,
    FONT_16x24,
    FONT_16x32,
    FONT_24x24,
    FONT_24x32,
    FONT_32x32
};

#endif
