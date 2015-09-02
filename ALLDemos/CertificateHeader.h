//
//  CertificateHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/31.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_CertificateHeader_h
#define ALLDemos_CertificateHeader_h

/*
 创建开发者证书
 
 创建证书的过程分成两步。
 (1) 生成证书签名公钥。    在安装有Mac OS X操作系统的苹果电脑中打开“应用程序”→“实用工具”→“钥匙串访问”,得到的界面
 选择“钥匙串访问”→“证书助理”→“从证书颁发机构请求证书”菜单项,此时弹出的对话框如图18-48 所示,在“用户电子邮件地址”中输入eorient@sina.com,在“常用名称”中输入“eorient”,然后在“请求是” 中选择“存储到磁盘”单选按钮。
 (2) 提交证书公钥文件到配置门户网站。
 2. 提交证书公钥文件到配置门户网站
 生成CertificateSigningRequest.certSigningRequest公钥文件后,重新回到配置门户网站提交证书公钥文件。在 图18-46所示的页面右上角的添加按钮 ,打开如图18-50所示的证书类型选择页面,在这个页面中我们可以选择 需要创建的证书。
 
 
 设备注册
 点击页面右上角的添加按钮 ￼ ,会打开如图18-54所示的页面,如果是单个iOS设备,我们可以在Register Deviced中输入设备名(Device Name)和设备ID(Device ID)。
 如果要获得设备的UDID,我们要把设备连接到iTunes。如图18-55所示,设备信息默认显示的是序列号。
 点击序列号,它就会变成标识符(UDID)显示,右键可以拷贝UDID。
 
 创建App ID
 
 创建配置概要文件
 配置概要文件(Provisioning Profiles)是应用在设备上编译时使用的,分为开发配置概要文件和发布配置概
 要文件,分别用于开发(调试)和发布。
 为了能够实现设备调试,我们需要将配置概要文件导入到Xcode中,双击下载的配置概要文件 MyNotes_Profile.mobileprovision就可以将文件导入Xcode。我们可以通过Xcode的菜单Window→Organizer打开 Xcode设备管理工具,如图18-69所示,在这里可以管理这些配置概要文件。
 
 
 为了在设备上运行
 工程中TARGETS下的PresentationLayer,依次点击Build Settings→Code Signing→Code Signing Identity,如图18-70所示,把Debug和Release的代码签名标识选择为identities in Keychain→ iPhone Developer:jia yunlong(XG3Y2ZN8PG)。
 
 $ sqlite3 NotesList.sqlite3
 SQLite version 3.7.12 2012-04-03 19:43:07
 Enter ".help" for instructions
 Enter SQL statements terminated with a ";"
 sqlite> .tables
 Note
 sqlite> select * from Note;
 2012-10-18 17:05:39|abc
 2012-10-18 17:13:07|xyz
 sqlite>
 
 sqlite> insert into Note (cdate,content) values ('2012-10-28 10:13:07','我的iOS'); sqlite> insert into Note (cdate,content) values ('2012-10-20 1:13:07','我的Java'); sqlite>
 
 */

#endif
