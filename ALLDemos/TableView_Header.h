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
 UITableViewDataSource协议
 tableView:cellForRowAtIndexPath:
 tableView:numberOfRowsInSection:
 tableView:titleForHeaderInSection:
 tableView:titleForFooterInSection:
 numberOfSectionsInTableView:
 sectionIndexTitlesForTableView:
 tableView:commitEditingStyle:forRowAtIndexPath:
 
 UITableViewCell*
 NSInteger
 NSString
 NSString
 NSInteger
 NSArray*
 void
 
 为表视图单元格提供数据,该方法是必 须实现的方法
 返回某个节中的行数
 返回节头的标题
 返回节脚的标题
 返回节的个数
 提供表视图节索引标题
 为删除或修改提供数据
 
 
 UITableViewDelegate协议
 tableView:viewForHeaderInSection: UIView *
 tableView:viewForFooterInSection: UIView *
 tableView:didEndDisplayingHeaderView:forSection: void
 tableView:didEndDisplayingFooterView:forSection: void 
 tableView:didEndDisplayingCell:forRowAtIndexPath: void 
 tableView:didSelectRowAtIndexPath: void
 为节头准备自定义视图,iOS 6之后可以使用 UITableViewHeaderFooterView
 为节脚准备自定义视图,iOS 6之后可以使用 UITableViewHeaderFooterView
 该方法在节头从屏幕中消失时触发(iOS 6之后 的方法)
 当节脚从屏幕中消失时触发(iOS 6之后的方法) 
 当单元格从屏幕中消失时触发(iOS 6之后的方法) 
 响应选择表视图单元格时调用的方法
 
 
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
