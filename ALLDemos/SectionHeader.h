//
//  SectionHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/14.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_SectionHeader_h
#define ALLDemos_SectionHeader_h

/*
 上面这几个方法􏰴实现了分节。分节只是添加索引的前提,数据源的sectionIndexTitles- ForTableView: 方法􏱈与索引􏰗接相关。我们在该方法的listGroupname集合中存放的数据是A组,B组,C组,D组,E组,F组,G 组,H组,这些数据在索引列中显示的结果是A,B,C,D,E,F,G,H,将后面的􏰸组􏰺􏳾取掉:
 -(NSArray *) sectionIndexTitlesForTableView: (UITableView *) tableView
 {
 NSMutableArray *listTitles = [[NSMutableArray alloc]
 initWithCapacity:[self.listGroupname count]]; //􏳿“A组”改为“A”
 for (NSString *item in self.listGroupname) {
 NSString *title = [item  substringToIndex:1];
 [listTitles  addObject:title];
 }
 return listTitles;
 }
 */
#endif
