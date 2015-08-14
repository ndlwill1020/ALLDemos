//
//  TableView_Header.h
//  ALLDemos
//
//  Created by macuser on 15/8/13.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_TableView_Header_h
#define ALLDemos_TableView_Header_h

/*
 typedef NS_ENUM(NSInteger, UITableViewCellAccessoryType) {
 UITableViewCellAccessoryNone,                   // don't show any accessory view
 UITableViewCellAccessoryDisclosureIndicator,    // regular chevron. doesn't track
 UITableViewCellAccessoryDetailDisclosureButton, // info button w/ chevron. tracks
 UITableViewCellAccessoryCheckmark,              // checkmark. doesn't track
 UITableViewCellAccessoryDetailButton NS_ENUM_AVAILABLE_IOS(7_0) // info button. tracks
 };
 
 
 如果采用了索引列表视图 一般久不再使用扩展视图
 
 - (void)viewDidLoad
 {
 [super viewDidLoad];
 NSBundle *bundle = [NSBundle mainBundle];
 NSString *plistPath = [bundle pathForResource:@"team_dictionary"
 ofType:@"plist"];
 self.dictData = [[NSDictionary alloc] initWithContentsOfFile:plistPath];
 NSArray* tempList = [self.dictData allKeys];
 //对key进行􏴫序
 self.listGroupname = [tempList sortedArrayUsingSelector:@selector(compare:)];
 }
 */

#endif
