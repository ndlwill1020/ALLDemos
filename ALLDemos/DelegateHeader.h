//
//  DelegateHeader.h
//  ALLDemos
//
//  Created by macuser on 15/9/2.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_DelegateHeader_h
#define ALLDemos_DelegateHeader_h

/*
 委托模式类图如图23-2所示,􏰛有两种角􏲃:框架类和委托对象。框架类所􏳮的是通用的与业务无关的处理 工作,委托对象所􏳮的是与业务相关的处理工作。委托对象需要实现委托协􏵚。框架类一􏲑􏱃有一个委托对象的 引用,在需要的时􏱱,框架类会回调委托对象,并􏵬􏽃参数给委托对象。
 
 
 viewController (findAllNotes)需要实现NoteBLDelegate NoteBL* bl;
 -> NoteBL(findALL)需要实现NoteDAODelegate  id<NoteBLDelegate> delegate  NoteDAO *dao;协议里面是查询成功和失败的回调
 ->NoteDAO id<NoteDAODelegate> delegate协议里面是查询成功和失败的回调
 ＃＃＃
 我们使用􏳀􏳁级网络请求框架MKNetworkKit重构
 
 以上删除操作是在表视图数据源的tableView:commitEditingStyle:forRowAtIndexPath:方法中实现 的。
 [error localizedDescription];

 //###############################
 观察者模式的具体应用有两个——通知(notification)机制和KVO(Key-Value Observing,􏴐值观察)机制, 这里我们重点使用通知机制。通知机制与委托机制不同的地方是:通知是一对多的对象之间的通信,而委托是一 对一的对象之间的通信。
 
 每一个工程􏰖有一个<工程􏴣>-Prefix.pch文件,􏰒的作用􏴦是整个工程。因此,在这个文件中定􏰸的􏴧可以 在整个工程中使用,􏲍是不能􏴨工程。因此,需要在每个工程􏴤编译􏳆文件,重复定􏰸这些􏴧。
 */

#endif
