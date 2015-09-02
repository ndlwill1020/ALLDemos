//
//  NoteDao.m
//  ALLDemos
//
//  Created by macuser on 15/8/20.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "NoteDao.h"
#import "sqlite3.h"

@interface NoteDao (){
    sqlite3* db;
}

@end

@implementation NoteDao
//sqlite3
//CREATE TABLE IF NOT EXISTS Note (cdate TEXT PRIMARY KEY, content TEXT)  如果表Note存在,则不用创建


/*
 //查询数据
 (1) 使用sqlite3_open函数打开数据库。
 (2) 使用sqlite3_prepare_v2函数预处理SQL语句。
 (3) 使用sqlite3_bind_text函数绑定参数。
 (4) 使用sqlite3_step函数执行SQL语句,遍历结果集。
 (5) 使用sqlite3_column_text等函数提取字段数据。
 (6) 使用sqlite3_finalize和sqlite3_close函数释放资源。
 
 修改数据
 (1) 使用sqlite3_open函数打开数据库。
 (2) 使用sqlite3_prepare_v2函数预处理SQL语句。
 (3) 使用sqlite3_bind_text函数绑定参数。
 (4) 使用sqlite3_step函数执行SQL语句。
 (5) 使用sqlite3_finalize和sqlite3_close函数释放资源。
 */



static NoteDao *sharedManager = nil;

+ (NoteDao*)sharedManager
{
    
    static dispatch_once_t once;
    dispatch_once(&once,^{
        NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
        NSDate *date1 = [dateFormatter dateFromString:@"2010-08-04 16:01:03"];
        Note* note1 = [[Note alloc] init];
        note1.date = date1;
        note1.content = @"Welcome to MyNotes.";
        NSDate *date2 = [dateFormatter dateFromString:@"2011-12-04 16:01:03"];
        Note* note2 = [[Note alloc] init];
        note2.date = date2;
        note2.content = @"欢迎使用MyNotes。";
        sharedManager = [[self alloc] init];
        sharedManager.listData = [[NSMutableArray alloc] init];
        [sharedManager.listData addObject:note1];
        [sharedManager.listData addObject:note2];
    });
    return sharedManager;
}



-(int) create:(Note*)model{
//    [self.listData addObject:model];
//    return 0;
    NSString *path = [self applicationDocumentsDirectoryFile];
    if (sqlite3_open([path UTF8String], &db) != SQLITE_OK) {
        sqlite3_close(db);
        NSAssert(NO,@"数据库打开失败。");
    } else {
            
            NSString *sqlStr = @"INSERT OR REPLACE INTO note (cdate,content) VALUES (?,?)";
            sqlite3_stmt *statement;
            //预处理过程
            if (sqlite3_prepare_v2(db, [sqlStr UTF8String], -1, &statement,
                                   NULL) == SQLITE_OK) {
                NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
                [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
                NSString *nsdate = [dateFormatter stringFromDate:model.date];
                //绑定参数开始
                sqlite3_bind_text(statement, 1, [nsdate UTF8String], -1, NULL);
                sqlite3_bind_text(statement, 2, [model.content UTF8String], -1, NULL);
                //执行插入
                if (sqlite3_step(statement) != SQLITE_DONE) {//常量SQLITE_DONE表示执行完成
                    NSAssert(NO, @"插入数据失败。"); }
            }
            sqlite3_finalize(statement);
            sqlite3_close(db);
        }
    return 0;
}

-(int) remove:(Note*)model{
//    for (Note* note in self.listData) {
//        if ([note.date isEqualToDate:model.date]) {
//            [self.listData removeObject:note];
//            break;
//        }
//    }
//    return 0;
    NSString *path = [self applicationDocumentsDirectoryFile];
    if (sqlite3_open([path UTF8String], &db) != SQLITE_OK) { sqlite3_close(db);
        NSAssert(NO,@"数据库打开失败。");
    } else {
        NSString *sqlStr = @"DELETE  from note where cdate =?";
        sqlite3_stmt *statement;
        //预处理过程
        if (sqlite3_prepare_v2(db, [sqlStr UTF8String], -1, &statement,
                               NULL) == SQLITE_OK) {
            NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
            [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
            NSString *nsdate = [dateFormatter stringFromDate:model.date];
            //绑定参数开始
            sqlite3_bind_text(statement, 1, [nsdate UTF8String], -1, NULL); //执行插入
            if (sqlite3_step(statement) != SQLITE_DONE) {
                NSAssert(NO, @"删除数据失败。 "); }
        }
        sqlite3_finalize(statement);
        sqlite3_close(db);
    }
    return 0;
}

-(int) modify:(Note*)model{
//    for (Note* note in self.listData) {
//        if ([note.date isEqualToDate:model.date]) {
//            note.content = model.content;
//            break;
//        }
//    }
//    return 0;
    NSString *path = [self applicationDocumentsDirectoryFile];
    if (sqlite3_open([path UTF8String], &db) != SQLITE_OK) { sqlite3_close(db);
        NSAssert(NO,@"数据库打开失败。");
    } else {
        NSString *sqlStr = @"UPDATE note set content=? where cdate =?";
        sqlite3_stmt *statement;
        //预处理过程
        if (sqlite3_prepare_v2(db, [sqlStr UTF8String], -1, &statement,
                               NULL) == SQLITE_OK) {
            NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
            [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
            NSString *nsdate = [dateFormatter stringFromDate:model.date];
            //绑定参数开始
            sqlite3_bind_text(statement, 1, [model.content UTF8String], -1, NULL);
            sqlite3_bind_text(statement, 2, [nsdate UTF8String], -1, NULL); //执行插入
            if (sqlite3_step(statement) != SQLITE_DONE) {
                NSAssert(NO, @"修改数据失败。"); }
        }
        sqlite3_finalize(statement);
        sqlite3_close(db);
    }
    return 0;
}

-(NSMutableArray*) findAll{
    //return self.listData;
    
    NSString *path = [self applicationDocumentsDirectoryFile];
    NSMutableArray *listData = [[NSMutableArray alloc] init];
    if (sqlite3_open([path UTF8String], &db) != SQLITE_OK) { sqlite3_close(db);
        NSAssert(NO,@"数据库打开失败。");
    } else {
        NSString *qsql = @"SELECT cdate,content FROM Note";
        sqlite3_stmt *statement;
        //预处理过程
        if (sqlite3_prepare_v2(db, [qsql UTF8String], -1, &statement,
                               NULL) == SQLITE_OK) {
            NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
            [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
            //执行
            while (sqlite3_step(statement) == SQLITE_ROW) {
                char *cdate = (char *) sqlite3_column_text(statement, 0);
                NSString *nscdate = [[NSString alloc] initWithUTF8String: cdate];
                char *content = (char *) sqlite3_column_text(statement, 1);
                NSString * nscontent = [[NSString alloc]
                                        initWithUTF8String: content];
                Note* note = [[Note alloc] init];
                note.date = [dateFormatter dateFromString:nscdate];
                note.content = nscontent;
                [listData addObject:note];
            }
        }
        sqlite3_finalize(statement);
        sqlite3_close(db);
    }
    return listData;
}

-(Note*) findById:(Note*)model{
//    for (Note* note in self.listData) {
//        if ([note.date isEqualToDate:model.date]) {
//            return note;
//        }
//    }
    
    //sqlite3
    NSString* path = [self applicationDocumentsDirectoryFile];
    if (sqlite3_open([path UTF8String], &db) != SQLITE_OK) {
        sqlite3_close(db);
    } else {
        NSString *qsql = @"SELECT cdate,content FROM Note where cdate =?";//这个问号(它 是占位符)就是要绑定的参数
        sqlite3_stmt *statement;
        //预处理过程 预处理的目的是将SQL编译成二进制代码,提高SQL语句的执行速度
        if (sqlite3_prepare_v2(db, [qsql UTF8String], -1, &statement, NULL) == SQLITE_OK) {//第三个参数代表全部SQL字符串的长度
            //准备参数
            NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
            [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
            NSString *nsdate = [dateFormatter stringFromDate:model.date];
            //绑定参数开始
            sqlite3_bind_text(statement, 1, [nsdate UTF8String], -1, NULL);//第二个参数为序号(从1开始)
            //执行
            if (sqlite3_step(statement) == SQLITE_ROW) {
                /*
                 sqlite3_column_blob()
                  sqlite3_column_double()
                  sqlite3_column_int()
                  sqlite3_column_int64()
                  sqlite3_column_text()
                  sqlite3_column_text16()
                 */
                char *cdate = (char *) sqlite3_column_text(statement, 0);//sqlite3_column_text函数的第二个参数用于指定select字段的索引(从 0开始)。
                NSString *nscdate = [[NSString alloc] initWithUTF8String: cdate];
                char *content = (char *) sqlite3_column_text(statement, 1);
                NSString * nscontent = [[NSString alloc] initWithUTF8String: content];
                Note* note = [[Note alloc] init];
                note.date = [dateFormatter dateFromString:nscdate];
                note.content = nscontent;
                sqlite3_finalize(statement);
                sqlite3_close(db);
                return note;
            }
        }
        sqlite3_finalize(statement);
        sqlite3_close(db);
    }
    
    return nil;
}

- (NSString *)applicationDocumentsDirectoryFile
{
    NSString* docPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    NSString* path = [docPath stringByAppendingPathComponent:@"Notes.db"];
    return  path;
}

- (NSURL *)applicationDocumentsDirectory
{
    return [[[NSFileManager defaultManager]
             URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject];
}

@end
