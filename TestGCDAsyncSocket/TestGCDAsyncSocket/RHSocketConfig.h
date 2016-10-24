//
//  RHSocketConfig.h
//  TestGCDAsyncSocket
//
//  Created by 陈志超 on 2016/10/24.
//  Copyright © 2016年 huaban. All rights reserved.
//

#ifndef RHSocketDemo_RHSocketConfig_h
#define RHSocketDemo_RHSocketConfig_h

#ifdef DEBUG
#define RHSocketDebug
#endif

#ifdef RHSocketDebug
#define RHSocketLog(format, ...) NSLog(format, ## __VA_ARGS__)
#else
#define RHSocketLog(format, ...)
#endif

#endif
