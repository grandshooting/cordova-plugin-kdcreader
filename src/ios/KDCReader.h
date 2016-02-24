//
//  KDCReader.h
//  KDCReader
//
//  Created by SeungWoo Han on 9/14/14.
//  Copyright (c) 2014 AISolution. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>
#import "KDCConstants.h"

extern  NSString *kdcConnectionChangedNotification;
extern  NSString *kdcDataArrivedNotification;
extern  NSString *kdcBarcodeDataArrivedNotification;
extern  NSString *kdcMSRDataArrivedNotification;
extern  NSString *kdcGPSDataArrivedNotification;
extern  NSString *kdcNFCDataArrivedNotification;

@interface KDCReader : NSObject {
    
}

- (NSString *)GetSDKRevisionHistory;
- (BOOL)Connect;
- (BOOL) IsKDCConnected;

- (void )SoftwareTrigger;

//Device features
- (uint8_t *)GetSerialNumber;
- (uint8_t *)GetFirmwareVersion;
- (uint8_t *)GetModelName;
- (BOOL) Is2DSupported;
- (BOOL) IsMSRSupported;
- (BOOL) IsGPSSupported;
- (BOOL) IsNFCSupported;
- (BOOL) IsKeyPadSupported;
- (BOOL) IsFlashSupported;
- (BOOL) IsVibratorSupported;
- (BOOL) IsPOSSupported;
- (BOOL) IsBarcodeSupported;

//KDC Mode
- (BOOL) SetKDCMode:(enum KDCMode)mode;
- (enum KDCMode) GetKDCMode;

//Data related

- (NSString *)GetData;
- (NSString *)GetNFCUID;
- (NSString *)GetNFCUIDReversed;
- (NSString *)GetNFCData;
- (NSString *)GetBarcodeData;
- (NSString *)GetMSRData;
- (NSString *)GetGPSData;
- (NSString *)GetRecordData;
- (void) EnableAttachType:(BOOL)enabled;
- (void) EnableAttachTimestamp:(BOOL)enabled;
- (void) EnableAttachSerialNumber:(BOOL)enabled;
- (void) EnableAttachLocation:(BOOL)enabled;
- (void) SetDataDelimiter:(enum DataDelimiter)delimiter;
- (void) SetRecordDelimiter:(enum RecordDelimiter)delimiter;

//NFC related
- (enum NFCDataFormat) GetNFCDataFormat;
- (BOOL) SetNFCDataFormat:(enum NFCDataFormat)format;
- (BOOL) EnableNFCUIDOnly:(enum EnableDisable)enabled;
- (BOOL) IsNFCUIDOnlyEnabled;
- (BOOL) EnableNFCExtendedFormat:(enum EnableDisable)enabled;
- (BOOL) IsNFCExtendedFormatEnabled;

//Bluetooth related
- (uint8_t *)GetBluetoothMacAddress;
- (uint8_t *)GetBluetoothFirmwareVersion;
- (BOOL) EnableAutoConnect:(enum EnableDisable)setting;
- (enum EnableDisable) IsAutoConnectEnabled;
- (BOOL) EnableAutoReconnect:(enum EnableDisable)setting;
- (enum EnableDisable) IsAutoReconnectEnabled;
- (BOOL) EnableAutoPowerOn:(enum EnableDisable)setting;
- (enum EnableDisable) IsAutoPowerOnEnabled;
- (BOOL) EnablePowerOffMessage:(enum EnableDisable)setting;
- (enum EnableDisable) IsPowerOffMessageEnabled;
- (BOOL) EnableWakeupNulls:(enum EnableDisable)setting;
- (enum EnableDisable) IsWakeupNullsEnabled;
- (BOOL) EnableBluetoothToggle:(enum EnableDisable)setting;
- (enum EnableDisable) IsBluetoothToggleEnabled;
- (BOOL) EnableBluetoothDisconnectButton:(enum EnableDisable)setting;
- (enum EnableDisable) IsBluetoothDisconnectButtonEnabled;
- (BOOL) SetBluetoothPowerOnTime:(enum PowerOnTime)powerontime;
- (enum PowerOnTime) GetBluetoothPowerOnTime;
- (BOOL) EnableBluetoothBeepWarning:(enum EnableDisable)setting;
- (BOOL) SetBluetoothAutoPowerOffTimeout:(enum AutoPowerOffTimeout)powerofftimeout;
- (enum AutoPowerOffTimeout) GetBluetoothAutoPowerOffTimeout;

//Barcode related
- (BOOL) IsAllSymbologiesEnabled;
- (BOOL) DisableAllSymbologies;
- (BOOL) EnableAllSymbologies;
- (BOOL) IsAllOptionsEnabled;
- (BOOL) DisableAllOptions;
- (BOOL) EnableAllOptions;

- (struct BarcodeSymbolSettings) GetCurrentBarcodeSymbolSettings;
- (BOOL) SetCurrentBarcodeSymbolSettings:(struct BarcodeSymbolSettings) settings;

- (BOOL) EnableDisableEAN13:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13Enabled;
- (BOOL) EnableDisableEAN8:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN8Enabled;
- (BOOL) EnableDisableUPCA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCAEnabled;
- (BOOL) EnableDisableUPCE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCEEnabled;
- (BOOL) EnableDisableUPCE0:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE0Enabled;
- (BOOL) EnableDisableUPCE1:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE1Enabled;
- (BOOL) EnableDisableCODE39:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE39Enabled;
- (BOOL) EnableDisableITF14:(enum EnableDisable)enabled;
- (enum EnableDisable) IsITF14Enabled;
- (BOOL) EnableDisableI2OF5:(enum EnableDisable)enabled;
- (enum EnableDisable) IsI2OF5Enabled;
- (BOOL) EnableDisableCODABAR:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODABAREnabled;
- (BOOL) EnableDisableCODE128:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE128Enabled;
- (BOOL) EnableDisableGS1128:(enum EnableDisable)enabled;
- (enum EnableDisable) IsGS1128Enabled;
- (BOOL) EnableDisableCODE93:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE93Enabled;
- (BOOL) EnableDisableCODE35:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE35Enabled;
- (BOOL) EnableDisableBOOKLAND:(enum EnableDisable)enabled;
- (enum EnableDisable) IsBOOKLANDEnabled;
- (BOOL) EnableDisableEAN13_ADDON:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13_ADDONEnabled;
- (BOOL) EnableDisableEAN8_ADDON:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN8_ADDONEnabled;
- (BOOL) EnableDisableUPCA_ADDON:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_ADDONEnabled;
- (BOOL) EnableDisableUPCE_ADDON:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_ADDONEnabled;
- (BOOL) EnableDisableCODE11:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE11Enabled;
- (BOOL) EnableDisableCODE32:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE32Enabled;
- (BOOL) EnableDisableMATRIX2OF5:(enum EnableDisable)enabled;
- (enum EnableDisable) IsMATRIX2OF5Enabled;
- (BOOL) EnableDisableMSI:(enum EnableDisable)enabled;
- (enum EnableDisable) IsMSIEnabled;
- (BOOL) EnableDisablePLESSY:(enum EnableDisable)enabled;
- (enum EnableDisable) IsPLESSYEnabled;
- (BOOL) EnableDisablePOSICODE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsPOSICODEEnabled;
- (BOOL) EnableDisableGS1OMNI:(enum EnableDisable)enabled;
- (enum EnableDisable) IsGS1OMNIEnabled;
- (BOOL) EnableDisableGS1LIMITED:(enum EnableDisable)enabled;
- (enum EnableDisable) IsGS1LIMITEDEnabled;
- (BOOL) EnableDisableGS1EXPANDED:(enum EnableDisable)enabled;
- (enum EnableDisable) IsGS1EXPANDEDEnabled;
- (BOOL) EnableDisableS2OF5IND:(enum EnableDisable)enabled;
- (enum EnableDisable) IsS2OF5INDEnabled;
- (BOOL) EnableDisableS2OF5IATA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsS2OF5IATAEnabled;
- (BOOL) EnableDisableTLC39:(enum EnableDisable)enabled;
- (enum EnableDisable) IsTLC39Enabled;
- (BOOL) EnableDisableTELEPEN:(enum EnableDisable)enabled;
- (enum EnableDisable) IsTELEPENEnabled;
- (BOOL) EnableDisableTRIOPTIC:(enum EnableDisable)enabled;
- (enum EnableDisable) IsTRIOPTICEnabled;
- (BOOL) EnableDisableAZTEC:(enum EnableDisable)enabled;
- (enum EnableDisable) IsAZTECEnabled;
- (BOOL) EnableDisableAZTECRUNES:(enum EnableDisable)enabled;
- (enum EnableDisable) IsAZTECRUNESEnabled;
- (BOOL) EnableDisableCODABLOCKF:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODABLOCKFEnabled;
- (BOOL) EnableDisableCODE16K:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE16KEnabled;
- (BOOL) EnableDisableCODE49:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE49Enabled;
- (BOOL) EnableDisableDATAMATRIX:(enum EnableDisable)enabled;
- (enum EnableDisable) IsDATAMATRIXEnabled;
- (BOOL) EnableDisableMAXICODE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsMAXICODEEnabled;
- (BOOL) EnableDisableMICROPDF:(enum EnableDisable)enabled;
- (enum EnableDisable) IsMICROPDFEnabled;
- (BOOL) EnableDisablePDF417:(enum EnableDisable)enabled;
- (enum EnableDisable) IsPDF417Enabled;
- (BOOL) EnableDisableQRCODE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsQRCODEEnabled;
- (BOOL) EnableDisableHANXIN:(enum EnableDisable)enabled;
- (enum EnableDisable) IsHANXINEnabled;
- (BOOL) DisableOCR;
- (enum EnableDisable) IsOCREnabled;
- (BOOL) EnableOCRA;
- (enum EnableDisable) IsOCRAEnabled;
- (BOOL) EnableOCRB;
- (enum EnableDisable) IsOCRBEnabled;
- (BOOL) EnableOCRUSC;
- (enum EnableDisable) IsOCRUSCEnabled;
- (BOOL) EnableOCRMICR;
- (enum EnableDisable) IsOCRMICREnabled;
- (BOOL) EnableOCRSEMI;
- (enum EnableDisable) IsOCRSEMIEnabled;

//Barcode options
- (struct BarcodeOptionSettings) GetCurrentBarcodeOptionSettings;
- (BOOL) SetCurrentBarcodeOptionSettings:(struct BarcodeOptionSettings) settings;

- (BOOL) EnableDisableCODABAR_TX_STARTSTOP:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODABAR_TX_STARTSTOPEnabled;
- (BOOL) EnableDisableLASER_UPCE_AS_UPCA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_UPCE_AS_UPCAEnabled;

- (BOOL) EnableDisablePOSTNET_TX_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsPOSTNET_TX_CHECKDIGITEnabled;
- (BOOL) EnableDisablePLANET_TX_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsPLANET_TX_CHECKDIGITEnabled;
- (BOOL) EnableDisableMSI_TX_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsMSI_TX_CHECKDIGITEnabled;
- (BOOL) EnableDisableCODE128_CONCATENATE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE128_CONCATENATEEnabled;
- (BOOL) EnableDisableCODE39_TX_STARTSTOP:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE39_TX_STARTSTOPEnabled;
- (BOOL) EnableDisableCODE39_APPEND:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE39_APPENDEnabled;
- (BOOL) EnableDisableCODE39_FULLASCII:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE39_FULLASCIIEnabled;
- (BOOL) EnableDisableUPCA_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_CHECKDIGITEnabled;
- (BOOL) EnableDisableUPCA_NUMBERSYS:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_NUMBERSYSEnabled;
- (BOOL) EnableDisableUPCA_2DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_2DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableUPCA_5DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_5DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableUPCA_REQ_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_REQ_ADDENDAEnabled;
- (BOOL) EnableDisableUPCA_SEP_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_SEP_ADDENDAEnabled;
- (BOOL) EnableDisableUPCA_COUPONCODE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCA_COUPONCODEEnabled;
- (BOOL) EnableDisableUPCE_EXPAND:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_EXPANDEnabled;
- (BOOL) EnableDisableUPCE_REQADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_REQADDENDAEnabled;
- (BOOL) EnableDisableUPCE_ADDENDASEP:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_ADDENDASEPEnabled;
- (BOOL) EnableDisableUPCE_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_CHECKDIGITEnabled;
- (BOOL) EnableDisableUPCE_NUMBERSYS:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_NUMBERSYSEnabled;
- (BOOL) EnableDisableUPCE_2DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_2DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableUPCE_5DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsUPCE_5DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableEAN13_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13_CHECKDIGITEnabled;
- (BOOL) EnableDisableEAN13_2DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13_2DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableEAN13_5DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13_5DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableEAN13_REQADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13_REQADDENDAEnabled;
- (BOOL) EnableDisableEAN13_SEPADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13_SEPADDENDAEnabled;
- (BOOL) EnableDisableEAN13_ISBNTRANS:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN13_ISBNTRANSEnabled;
- (BOOL) EnableDisableEAN8_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN8_CHECKDIGITEnabled;
- (BOOL) EnableDisableEAN8_2DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN8_2DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableEAN8_5DIGIT_ADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN8_5DIGIT_ADDENDAEnabled;
- (BOOL) EnableDisableEAN8_REQADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN8_REQADDENDAEnabled;
- (BOOL) EnableDisableEAN8_SEPADDENDA:(enum EnableDisable)enabled;
- (enum EnableDisable) IsEAN8_SEPADDENDAEnabled;
- (BOOL) EnableDisableGS1128_UPCEAN_VERSION:(enum EnableDisable)enabled;
- (enum EnableDisable) IsGS1128_UPCEAN_VERSIONEnabled;
//Codabar
- (BOOL) EnableCODABAR_DONOT_VERIFY;
- (enum EnableDisable) IsCODABAR_DONOT_VERIFYEnabled;
- (BOOL) EnableCODABAR_VERIFY_DONOT_TX;
- (enum EnableDisable) IsCODABAR_VERIFY_DONOT_TXEnabled;
- (BOOL) EnableCODABAR_VERIFY_DO_TX;
- (enum EnableDisable) IsCODABAR_VERIFY_DO_TXEnabled;
- (BOOL) EnableCODABAR_CONCATENATE_DISABLE;
- (enum EnableDisable) IsCODABAR_CONCATENATE_DISABLEEnabled;
- (BOOL) EnableCODABAR_CONCATENATE_ENABLE;
- (enum EnableDisable) IsCODABAR_CONCATENATE_ENABLEEnabled;
- (BOOL) EnableCODABAR_CONCATENATE_REQUIRED;
- (enum EnableDisable) IsCODABAR_CONCATENATE_REQUIREDEnabled;
//Code39
- (BOOL) EnableCODE39_DONOT_VERIFY;
- (enum EnableDisable) IsCODE39_DONOT_VERIFYEnabled;
- (BOOL) EnableCODE39_VERIFY_DONOT_TX;
- (enum EnableDisable) IsCODE39_VERIFY_DONOT_TXEnabled;
- (BOOL) EnableCODE39_VERIFY_DO_TX;
- (enum EnableDisable) IsCODE39_VERIFY_DO_TXEnabled;
//I2of5
- (BOOL) EnableI2OF5_DONOT_VERIFY;
- (enum EnableDisable) IsI2OF5_DONOT_VERIFYEnabled;
- (BOOL) EnableI2OF5_VERIFY_DONOT_TX;
- (enum EnableDisable) IsI2OF5_VERIFY_DONOT_TXEnabled;
- (BOOL) EnableI2OF5_VERIFY_DO_TX;
- (enum EnableDisable) IsI2OF5_VERIFY_DO_TXEnabled;
//CODE11
- (BOOL) EnableDisableCODE11_2_CHECKDIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsCODE11_2_CHECKDIGITEnabled;
//TELEPEN
- (BOOL) EnableDisableTELEPEN_OUTPUT_ORIGINAL:(enum EnableDisable)enabled;
- (enum EnableDisable) IsTELEPEN_OUTPUT_ORIGINALEnabled;
//Posicode
- (BOOL) EnablePOSICODE_AB_MASK;
- (enum EnableDisable) IsPOSICODE_AB_MASKEnabled;
- (BOOL) EnablePOSICODE_AB_LIMITEDA_MASK;
- (enum EnableDisable) IsPOSICODE_AB_LIMITEDA_MASKEnabled;
- (BOOL) EnablePOSICODE_AB_LIMITEDB_MASK;
- (enum EnableDisable) IsPOSICODE_AB_LIMITEDB_MASKEnabled;
//GS1-128
- (BOOL) EnableGS1128_NO_EMULATION;
- (enum EnableDisable) IsGS1128_NO_EMULATIONEnabled;
- (BOOL) EnableGS1128_128_EMULATION;
- (enum EnableDisable) IsGS1128_128_EMULATIONEnabled;
- (BOOL) EnableGS1128_RSS_EMULATION;
- (enum EnableDisable) IsGS1128_RSS_EMULATIONEnabled;
//Laser
- (BOOL) EnableDisableLASER_EAN8_AS_EAN13:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_EAN8_AS_EAN13Enabled;
- (BOOL) EnableDisableLASER_UPCE_AS_EAN13:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_UPCE_AS_EAN13Enabled;
- (BOOL) EnableDisableLASER_RETURN_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_RETURN_CHECK_DIGITEnabled;
- (BOOL) EnableDisableLASER_VERIFY_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_VERIFY_CHECK_DIGITEnabled;
- (BOOL) EnableDisableLASER_WIDE_SCAN_ANGLE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_WIDE_SCAN_ANGLEEnabled;
- (BOOL) EnableDisableLASER_HIGH_FILTER_MODE:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_HIGH_FILTER_MODEEnabled;
- (BOOL) EnableDisableLASER_UPCA_AS_EAN13:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_UPCA_AS_EAN13Enabled;
- (BOOL) EnableDisableLASER_I2OF5_VERIFY_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_I2OF5_VERIFY_CHECK_DIGITEnabled;
- (BOOL) EnableDisableLASER_CODE39_VERIFY_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_CODE39_VERIFY_CHECK_DIGITEnabled;
- (BOOL) EnableDisableLASER_UPCE_RETURN_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_UPCE_RETURN_CHECK_DIGITEnabled;
- (BOOL) EnableDisableLASER_UPCA_RETURN_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_UPCA_RETURN_CHECK_DIGITEnabled;
- (BOOL) EnableDisableLASER_EAN8_RETURN_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_EAN8_RETURN_CHECK_DIGITEnabled;
- (BOOL) EnableDisableLASER_EAN13_RETURN_CHECK_DIGIT:(enum EnableDisable)enabled;
- (enum EnableDisable) IsLASER_EAN13_RETURN_CHECK_DIGITEnabled;

//Scan Option
- (BOOL) SetScanTimeout:(enum ScanTimeout)timeout;
- (enum ScanTimeout) GetScanTimeout;
- (BOOL) SetMinimumBarcodeLength:(int)minlength;
- (int) GetMinimumBarcodeLength;
- (BOOL) EnableAutoTriggerMode:(enum EnableDisable)setting;
- (enum EnableDisable) IsAutoTriggerModeEnabled;
- (BOOL) SetAutoTriggerRereadDelay:(enum AutoTriggerRereadDelay)delay;
- (int) GetAutoTriggerRereadDelay;
- (BOOL) SetPartialDisplayStartPosition:(int)position;
- (BOOL) SetPartialDisplayLength:(int)length;
- (BOOL) SetPartialDisplayAction:(enum PartialAction)action;
- (enum PartialAction) GetPartialDisplayAction;

//Data process
- (BOOL)SetDataFormat:(int)format;
- (BOOL) SetWedgeStoreMode:(enum WedgeMode)wedgemode;
- (enum WedgeMode) GetWedgeStoreMode;
- (char *) GetPrefix;
- (BOOL) SetPrefix:(char *)prefix;
- (char *) GetSuffix;
- (BOOL) SetSuffix:(char *)suffix;
- (enum AIMID) GetAIMIDSetting;
- (BOOL) SetAIMIDSetting:(enum AIMID)aimid;
- (BOOL) SetPartialDataStartPosition:(int)position;
- (int) GetPartialDataStartPosition;
- (BOOL) SetPartialDataLength:(int)length;
- (int) GetPartialDataLength;
- (BOOL) SetPartialDataAction:(enum PartialAction)action;
- (enum PartialAction) GetPartialDataAction;
- (BOOL) SetDataTerminator:(enum DataTerminator)terminator;
- (enum DataTerminator) GetDataTerminator;
- (BOOL) EnableDuplicateCheck:(enum EnableDisable)duplicateCheckOn;
- (enum EnableDisable) IsDuplicateCheckEnabled;
- (BOOL) EnableEnterKeyFunction:(enum EnableDisable)enterkey;
- (enum EnableDisable) IsEnterKeyFunctionEnabled;
- (BOOL) EnableExtendKeypad:(enum EnableDisable)extendkey;
- (enum EnableDisable) IsExtendKeypadEnabled;

//GPS config
- (BOOL) SetGPSPower:(enum EnableDisable)power;
- (BOOL) SetGPSBypassMode:(enum EnableDisable)setting;
- (BOOL) ResetGPSModule;
- (BOOL) GPSAcquireTest;
- (BOOL) SetGPSPowerSaveMode:(enum GPSPowerSaveMode)mode;
- (enum GPSPowerSaveMode) GetGPSPowerSaveMode;

//System Config
- (BOOL) SetMemoryConfiguration:(enum MemoryConfiguration)memoryconfig;
- (enum MemoryConfiguration) GetMemoryConfiguration;
- (BOOL) EraseSystemMemory;
- (int) GetStoredBarcodeNumber;
- (int) GetMemoryLeft;
- (int) GetBatteryCapacity;
- (NSString *) GetSystemRTC;
- (BOOL) SetSystemRTC:(struct DateTime)datetime;
- (BOOL) SyncSystemRTC;
- (BOOL) ResetSystemRTC;
- (BOOL) EnableAutoErase:(enum EnableDisable)setting;
- (enum EnableDisable) IsAutoEraseEnabled;
- (BOOL) EnableBluetoothAutoPowerOff:(enum EnableDisable)setting;
- (enum EnableDisable) IsBluetoothAutoPowerOffEnabled;
- (BOOL) EnableGPSAutoPowerOff:(enum EnableDisable)setting;
- (BOOL) EnableButtonLock:(enum EnableDisable)setting;
- (BOOL) EnableBeepSound:(enum EnableDisable)setting;
- (enum EnableDisable) IsBeepSoundEnabled;
- (BOOL) EnableBeepOnScan:(enum EnableDisable)setting;
- (enum EnableDisable) IsBeepOnScanEnabled;
- (BOOL) EnableVibrator:(enum EnableDisable)setting;
- (enum EnableDisable) IsVibratorEnabled;
- (BOOL) EnableMenuAutoExit:(enum EnableDisable)setting;
- (BOOL) EnableMenuBarcode:(enum EnableDisable)setting;
- (enum EnableDisable) IsMenuBarcodeEnabled;
- (BOOL) EnableScrolling:(enum EnableDisable)setting;
- (enum EnableDisable) IsScrollingEnabled;
- (BOOL) SetSleepTimeout:(enum SleepTimeout)sleeptimeout;
- (enum SleepTimeout) GetSleepTimeout;
- (BOOL) SetDisplayFormat:(enum DisplayFormat)displayformat;
- (BOOL) SetAutoPowerOffTimeout:(enum AutoPowerOffTimeout)powerofftimeout;
- (enum AutoPowerOffTimeout) GetAutoPowerOffTimeout;
- (BOOL) EnableDisplayPortStatus:(enum EnableDisable)setting;
- (BOOL) EnableHighBeepVolume:(enum EnableDisable)setting;
- (BOOL) SetFactoryDefault;
- (BOOL) LockDateTimeSetting:(enum EnableDisable)setting;


//Host message
- (BOOL)SetDisplayPosition:(int)row :(int)col;
- (BOOL)ClearDisplay;
- (BOOL)DisplayTextMessageOnKDC:(char *)text;
- (BOOL)SetDisplayDuration:(int)seconds;
- (BOOL)SetDisplayTextFontSize:(enum MessageFontSize)fontsize;
- (BOOL)BeepSuccess;
- (BOOL)BeepFailure;
- (BOOL)MakeCustomBeep:(int)ontime :(int)offtime :(int)repeat;

//Stored data
- (void)GetStoredDataSingle;

@end

