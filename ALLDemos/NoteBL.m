//
//  NoteBL.m
//  ALLDemos
//
//  Created by macuser on 15/8/20.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "NoteBL.h"
#import "NoteDao.h"
@implementation NoteBL
//插入备忘录的方法
-(NSMutableArray*) createNote:(Note*)model
{
    NoteDao *dao = [NoteDao sharedManager];
    [dao create:model];
    return [dao findAll];
}
//删除备忘录的方法
-(NSMutableArray*) remove:(Note*)model
{
    NoteDao *dao = [NoteDao sharedManager];
    [dao remove:model];
    return [dao findAll];
}
//查询所有数据的方法
-(NSMutableArray*) findAll
{
    NoteDao *dao = [NoteDao sharedManager];
    return [dao findAll];
}
@end
