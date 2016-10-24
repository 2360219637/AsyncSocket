//
//  RHSocketConnection.h
//  TestGCDAsyncSocket
//
//  Created by 陈志超 on 2016/10/24.
//  Copyright © 2016年 huaban. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RHSocketConfig.h"

@protocol RHSocketConnectionDelegate <NSObject>

- (void)didDisconnectWithError:(NSError *)error;
- (void)didConnectToHost:(NSString *)host port:(UInt16)port;
- (void)didReceiveData:(NSData *)data tag:(long)tag;

@end

@interface RHSocketConnection : NSObject

@property (nonatomic, weak) id<RHSocketConnectionDelegate> delegate;

- (void)connectWithHost:(NSString *)hostName port:(int)port;
- (void)disconnect;

- (BOOL)isConnected;
- (void)readDataWithTimeout:(NSTimeInterval)timeout tag:(long)tag;
- (void)writeData:(NSData *)data timeout:(NSTimeInterval)timeout tag:(long)tag;

@end
