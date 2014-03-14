// EXFacebookManager.h
//
// Copyright (c) 2014 Shintaro Kaneko (http://kaneshinth.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

@class FBSession;
@protocol EXFacebookManagerConfiguration;

@interface EXFacebookManager : NSObject
@property (nonatomic, assign) id <EXFacebookManagerConfiguration> configuration;
@property (readonly, nonatomic, strong) NSArray *permissions;
@property (readonly, nonatomic, strong) NSString *facebookAppID;
@property (nonatomic, strong) FBSession *session;
+ (instancetype)sharedManager;
- (NSString *)URLScheme;
- (void)refreshSession;
- (void)refreshSessionWithPermission;
- (void)applicationDidBecomeActive;
- (void)applicationWillTerminate;
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
- (void)sessionCloseAndClearTokenInformation;
@end

@protocol EXFacebookManagerConfiguration <NSObject>
@optional
- (NSString *)facebookAppIDForFacebookManager:(EXFacebookManager *)manager;
- (NSArray *)permissionsForFacebookManager:(EXFacebookManager *)manager;
- (BOOL)defaultFBSessionTokenCachingStrategyForFacebookManager:(EXFacebookManager *)manager;
@end
