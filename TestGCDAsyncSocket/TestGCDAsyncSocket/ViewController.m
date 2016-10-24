//
//  ViewController.m
//  TestGCDAsyncSocket
//
//  Created by 陈志超 on 2016/10/24.
//  Copyright © 2016年 huaban. All rights reserved.
//

#import "ViewController.h"
#import "RHSocketConnection.h"

@interface ViewController () <RHSocketConnectionDelegate>
{
    NSString *_serverHost;
    int _serverPort;
    RHSocketConnection *_connection;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _serverHost = @"www.baidu.com";
    _serverPort = 80;
    [self openConnection];
}

#pragma mark -
#pragma mark RHSocketConnection method

- (void)openConnection
{
    [self closeConnection];
    _connection = [[RHSocketConnection alloc] init];
    _connection.delegate = self;
    [_connection connectWithHost:_serverHost port:_serverPort];
}

- (void)closeConnection
{
    if (_connection) {
        _connection.delegate = nil;
        [_connection disconnect];
        _connection = nil;
    }
}

#pragma mark -
#pragma mark RHSocketConnectionDelegate method

- (void)didDisconnectWithError:(NSError *)error
{
    RHSocketLog(@"didDisconnectWithError...");
}

- (void)didConnectToHost:(NSString *)host port:(UInt16)port
{
    RHSocketLog(@"didConnectToHost...");
}

- (void)didReceiveData:(NSData *)data tag:(long)tag
{
    RHSocketLog(@"didReceiveData...");
}

@end
