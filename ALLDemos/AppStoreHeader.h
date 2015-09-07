//
//  AppStoreHeader.h
//  ALLDemos
//
//  Created by macuser on 15/9/2.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_AppStoreHeader_h
#define ALLDemos_AppStoreHeader_h

/*
应用图标
 
 􏷨动界面
 
 这些􏳉􏹊属性主要是TARGETS 中的 Identity和Deployment Info属性 
  所有 的􏳉􏹊属性􏱃在工程属性􏰹述文件HelloWorld-Info.plist(工程􏰻+Info.plist)中
 如果在发布时这里设定的版本􏲜(图22-11中的 Version)与iTunes Connect中设置的应用的版本􏲜(图22-13中的Version)不一􏵭,在􏸎包上􏵬到App Store 时􏰜会失􏶸。
 
 发布编译
 先􏷀录iOS开发中心的配置门户网站,选择􏸠􏵀的导航􏸟单Provisioning Profiles,然后选择Distribution标签,
 在图22-16所示的界面中,点􏵩页面􏴿上角的添加按钮 ,进入创建配置概要文件选择页面(如图22-17所示), 这里的备选项目􏱁􏰿可以参考18.5.1一节,选择类􏰵为􏰇App Store􏰉,点􏵩下面Continue按钮进入如图22-18所示的 页面,这个页面中我们选择前面创建好的App ID。
 选择工程的TARGETS,选择Build Settings→Code Signing→Code Signing Identity,选择Release的代码 签􏰻标识􏰷为Automatic →iOS Distribution
 -output之后􏰜是应用编译之后的位置了
 */

#endif
