//
//  CommonHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/28.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_CommonHeader_h
#define ALLDemos_CommonHeader_h

/*
 if (NSFoundationVersionNumber > NSFoundationVersionNumber_iOS_6_1) { 1
 _imageView.image = [UIImage imageNamed:@"background640x960.png"]; 2 }
 
 上述代码第1行是判断当前操作系统的版本号是否大于iOS 6.1,即是否为iOS 7操作系统,其中 NSFoundationVersionNumber是一个系统全局变量,NSFoundationVersionNumber_iOS_6_1是一个宏。判 断操作系统版本的还有[[UIDevice currentDevice] systemVersion]语句,通过该语句我们可以获得一个 字符串,如果是iOS 6.1则返回6.1。
 
 
 
 -(void)viewWillAppear:(BOOL)animated
 {
 [super viewWillAppear:YES];
 //设置状态栏风格
 [[UIApplication sharedApplication] setStatusBarHidden:NO];
 [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleDefault];
 }
 
 
 然后再选择TARGETS→HelloWorld (你自己的Target)→Build Setting→Apple LLVM 5.0 - Language - Objective C→Objective-C Automatic Reference
 Counting,如图16-15所示,选择为NO。
 
 出现这些编译错误是由于ASIHTTPRequest框架本身不支持 ARC技术,它的源代码中使用了MRC,解决方法是为 ASIHTTPRequest框架中的这些源程序文件,设置为不采用ARC 编译,编译参数是-fno-objc-arc,如图16-17所示,选择 TARGETS→MyNote(s 你自己的Target)→Build Phases→Compile Sources,然后再选择ASIHTTPRequest中的源文件,敲击回车键 弹出对话框,在对话框中输入“-fno-objc-arc”。
 
 
 - (BOOL)application:(UIApplication *)application
 didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
 CGSize iOSDeviceScreenSize = [[UIScreen mainScreen] bounds].size; 1 UIStoryboard *mainStoryboard = nil;
 if ([UIDevice currentDevice].userInterfaceIdiom
 == UIUserInterfaceIdiomPhone) { 2 if (iOSDeviceScreenSize.height == 568) { 3
 mainStoryboard
 = [UIStoryboard storyboardWithName:@"MainiPhone5" bundle:nil]; 4 } else {
 mainStoryboard = self.window.rootViewController.storyboard; 5 }
 }
 self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]]; self.window.rootViewController
 = [mainStoryboard instantiateInitialViewController]; 6 [self.window makeKeyAndVisible]; 7
 return YES; }
 
 我们在该方法中添加了1~8行代码,其中第1行代码是会的屏幕的大小,CGSize是一个结构体,具有高 (height)和宽(width)两个成员。第2行代码是判断是否为iPhone设备,如果是iPhone设备我们继续判断。第3 行代码是判断屏幕的高度是否等于568点,如果是说明这是iPhone 5设备,否则就是iPhone 4设备。第4行代码是 通过故事板文件MainiPhone5创建故事板对象。第5行代码是从window.rootViewController中获得故事板对 象,注意不要通过storyboardWithName:方法新建故事板对象,因为我们这个工程本身就设置了默认创建
 Main.storyboard的故事板对象了,再创建会浪费内存。
 
 
 if ([ADBannerView instancesRespondToSelector:@selector(initWithAdType:)]) { self.bannerView = [[ADBannerView alloc] initWithAdType:ADAdTypeBanner]; //设定iOS 6广告栏自动调整宽度
 self.bannerView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
 } else {
 self.bannerView = [[ADBannerView alloc] init]; self.bannerView.delegate = self;
 [self.view insertSubview:self.bannerView aboveSubview:self.scrollView];
 */


#endif
