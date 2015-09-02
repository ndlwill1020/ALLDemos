//
//  NoteBL.h
//  ALLDemos
//
//  Created by macuser on 15/8/20.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Note.h"
@interface NoteBL : NSObject
//插入备忘录的方法
-(NSMutableArray*) createNote:(Note*)model;
//删除备忘录的方法
-(NSMutableArray*) remove:(Note*)model;
//查询所有数据的方法
-(NSMutableArray*) findAll;
@end
