/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#include <sys/types.h>
#include <sys/sysctl.h>

#import <Cordova/CDV.h>
#import "CDVBarcodeDevice.h"
#import "KDCReader.h"

KDCReader *kdcReader;


@interface CDVBarcodeDevice () {}
@end

@implementation CDVBarcodeDevice

@synthesize callbackId;

- (void)initBarcode:(CDVInvokedUrlCommand*)command
{
    self.callbackId = command.callbackId;
    kdcReader = [[KDCReader alloc] init];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(kdcConnectionChanged:) name:kdcConnectionChangedNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(kdcDataArrived:) name:kdcDataArrivedNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(kdcBarcodeDataArrived:) name:kdcBarcodeDataArrivedNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(kdcMSRDataArrived:) name:kdcMSRDataArrivedNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(kdcNFCDataArrived:) name:kdcNFCDataArrivedNotification object:nil];
    
    [kdcReader Connect];   // Connect to KDC

    //[self.commandDelegate runInBackground:^{
        
        //On exécute en background
        
    //}];
    
    
}

- (void)scan:(CDVInvokedUrlCommand*)command
{
    [kdcReader SoftwareTrigger];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}



//************************************************************************
//
//  Notification from KDCReader when connection has been changed
//
//************************************************************************
- (void)kdcConnectionChanged:(NSNotification *)notification
{
    NSLog(@"%s",__FUNCTION__);
    
    KDCReader *kReader = (KDCReader *)[notification object];
    
    NSMutableDictionary* devProps = [NSMutableDictionary dictionaryWithCapacity:2];
    
    [devProps setObject:@"connectionChanged" forKey:@"event"];
    [devProps setObject:[[self class] cordovaVersion] forKey:@"cordova"];
    
    
    if ( [kReader IsKDCConnected] ) {
        [devProps setObject:@"true" forKey:@"value"];
    }
    else {
        [devProps setObject:@"false" forKey:@"value"];
    }
    NSDictionary* devReturn = [NSDictionary dictionaryWithDictionary:devProps];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:devReturn];
    [pluginResult setKeepCallbackAsBool:YES];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.callbackId];
    
}
//************************************************************************
//
//  Notification from KDCReader when data has been arrived from KDC
//
//************************************************************************
- (void)kdcDataArrived:(NSNotification *)notification
{
    NSLog(@"%s",__FUNCTION__);
    
    KDCReader *kReader = (KDCReader *)[notification object];
    
    [self DisplayMessage:[kReader GetData]];
    
}
//************************************************************************
//
//  Notification from KDCReader when barcode data has been arrived from KDC
//
//************************************************************************
- (void)kdcBarcodeDataArrived:(NSNotification *)notification
{
    NSLog(@"Borecode : %s",__FUNCTION__);
    
    

    KDCReader *kReader = (KDCReader *)[notification object];
    
    [self DisplayMessage:[kReader GetBarcodeData]];

    NSMutableDictionary* devProps = [NSMutableDictionary dictionaryWithCapacity:2];
    
    [devProps setObject:@"barcodeDataArrived" forKey:@"event"];
    [devProps setObject:[[self class] cordovaVersion] forKey:@"cordova"];
    
    
    [devProps setObject:[kReader GetBarcodeData] forKey:@"value"];
    
    NSDictionary* devReturn = [NSDictionary dictionaryWithDictionary:devProps];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:devReturn];
    [pluginResult setKeepCallbackAsBool:YES];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.callbackId];

}
//************************************************************************
//
//  Notification from KDCReader when NFC data has been arrived from KDC
//
//************************************************************************
- (void)kdcNFCDataArrived:(NSNotification *)notification
{
    NSLog(@"%s",__FUNCTION__);
    
    KDCReader *kReader = (KDCReader *)[notification object];
    
    [self DisplayMessage:[kReader GetNFCUIDReversed]];
    
}
//************************************************************************
//
//  Notification from KDCReader when MSR data has been arrived from KDC
//
//************************************************************************
- (void)kdcMSRDataArrived:(NSNotification *)notification
{
    NSLog(@"%s",__FUNCTION__);
    
    KDCReader *kReader = (KDCReader *)[notification object];
    
    [self DisplayMessage:[kReader GetMSRData]];
    
}

- (void) DisplayMessage:(NSString *)message
{
    NSLog(@"%@", message);
}


+ (NSString*)cordovaVersion
{
    return CDV_VERSION;
}

@end
