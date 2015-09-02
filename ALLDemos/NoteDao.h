//
//  NoteDao.h
//  ALLDemos
//
//  Created by macuser on 15/8/20.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Note.h"

@interface NoteDao : NSObject

//类似中间层 为对数据的操作提供方法（business－persistence通讯）
@property (nonatomic,strong) NSMutableArray* listData;


//@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
//@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
//@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

- (NSString *)applicationDocumentsDirectoryFile;

+ (NoteDao*)sharedManager;
//插入备忘录的方法
-(int) create:(Note*)model;
//删除备忘录的方法
-(int) remove:(Note*)model;
//修改备忘录的方法
-(int) modify:(Note*)model;
//查询所有数据的方法
-(NSMutableArray*) findAll;
//按照主键查询数据的方法
-(Note*) findById:(Note*)model;



@end

