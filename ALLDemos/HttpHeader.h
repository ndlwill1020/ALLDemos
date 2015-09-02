//
//  HttpHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/25.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_HttpHeader_h
#define ALLDemos_HttpHeader_h

/*
 HTTP是Hypertext Transfer Protocol的缩写,即超文本传输协议。
 HTTP协议支持C/S网络结构,是无连接协议,即每一次请求时建立连接,服务器处理完客户端的请求后, 应答给客户端然后断开连接,不会一直占用网络资源。
 GET方法是向指定的资源发出请求,发送的信息“显式”地跟在URL后面。GET方法应该只用在读取数据, 例如静态图片等。GET方法有点像使用明信片给别人写信,“信内容”写在外面,接触到的人都可以看到,因此 是不安全的。
 POST方法是向指定资源提交数据,请求服务器进行处理,例如提交表单或者上传文件等。数据被包含在请 求体中。POST方法像是把“信内容”装入信封中,接触到的人都看不到,因此是安全的。
 
 HTTPS是Hypertext Transfer Protocol Secure,即超文本传输安全协议,是超文本传输协议和SSL的组合,用以 提供加密通信及对网络服务器身份的鉴定。
 
 -(void)startRequest
 {
 NSString *strURL = [[NSString alloc] initWithFormat:@"http://iosbook1.com/service/mynotes/webservice.php?email=
 %@&type=%@&action=%@",@"<你的iosbook1.com用户邮箱>",@"JSON",@"query"];
 NSURL *url = [NSURL URLWithString:[strURL URLEncodedString]];
 NSURLRequest *request = [[NSURLRequest alloc] initWithURL:url];
 NSData *data  = [NSURLConnection sendSynchronousRequest:request
 returningResponse:nil error:nil];
 NSLog(@"请求完成...");
 NSDictionary *resDict = [NSJSONSerialization JSONObjectWithData:
 data options:NSJSONReadingAllowFragments error:nil];
 [self reloadView:resDict];
 }
 
 
 email。它是http://iOSBook1.com网站的注册用户邮箱。如果用户使用这些Web Service,首先需要到这个 网站注册成为会员,然后提供自己的注册邮箱。
  type。它是数据交互类型。Web Service提供了3种方式的数据:JSON、XML和SOAP。
  action。它指定调用Web Service的一些方法,这些方法有add、remove、modify和query,分别代表插
 入、删除、修改和查询处理。
 
 
 我们在前面还提到了一个分类NSString (URLEncoding),它的作用是编码和解码URL,它的代码 如下:
 @interface NSString (URLEncoding)
 -(NSString *)URLEncodedString;
 -(NSString *)URLDecodedString;
 @end
 @implementation NSString (URLEncoding)
 - (NSString *)URLEncodedString
 {
 NSString *result = (NSString *) CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes
 (kCFAllocatorDefault, 1 (CFStringRef)self,
 NULL, 2 CFSTR("+$,#[] "), 3 kCFStringEncodingUTF8));
 return result;
 }
 - (NSString*)URLDecodedString
 {
 NSString *result = (NSString *) CFBridgingRelease(CFURLCreateStringByReplacingPercentEscapesUsingEncoding
 (kCFAllocatorDefault, 4 (CFStringRef)self,
 CFSTR(""), 5
 kCFStringEncodingUTF8));
 return result;
 } @end
 
 调用方法 type参数 action参数 id参数 date参数 content参数 email参数
 ￼￼￼add
 modify
 remove
 需要 需要 不需要 需要 需要 需要 
 需要 需要 需要 需要 需要 需要 
 需要 需要 需要 不需要 不需要 不需要
  type。同“查询”调用,是数据交互类型。
  action。同“查询”调用,指定调用Web Service的哪些方法。
  id。备忘录信息中的主键,隐藏在界面之后。当删除和修改时,需要把它传给Web Service。
  date。备忘录信息中的日期字段数据。
  content。备忘录信息中的内容字段数据。
  email。备忘录信息中的用户邮箱字段,通过它可以查询与当前邮箱关联的用户数据。
 
 ／／插入
 -(void)startRequest
 {
 //准备参数
 NSDate *date = [NSDate new];
 NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init]; [dateFormatter setDateFormat:@"yyyy-MM-dd"];
 NSString *dateStr = [dateFormatter stringFromDate:date]; //设置参数
 NSString *post = [NSString stringWithFormat:@"email=%@&type=%
 @&action=%@&date=%@&content=%@", @"<你的iosbook1.com用户邮箱>",@"JSON",@"add",dateStr,_textView.text];
 NSString *strURL = [[NSString alloc] initWithFormat:@"http://
 iosbook1.com/service/mynotes/webservice.php"];
 NSURL *url = [NSURL URLWithString:[strURL URLEncodedString]]; NSData *postData = [post dataUsingEncoding:NSUTF8StringEncoding];
 NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url]; [request setHTTPMethod:@"POST"];
 [request setHTTPBody:postData];
 NSURLConnection *connection = [[NSURLConnection alloc]
 initWithRequest:request delegate:self];
 if (connection) {
 _datas = [NSMutableData new];
 }
 }
 
 因此本节我们介绍由第三方提供的网络,目前主要有三种框架:
 ASIHTTPRequest、AFNetworking和MKNetworkKit。
 
 
 ／／MKNetworkKit
 - (IBAction)onClick:(id)sender {
 NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask,
 YES);
 NSString *cachesDirectory = paths[0];
 NSString *downloadPath = [cachesDirectory stringByAppendingPathComponent:@"test1.jpg"];
 NSString *path = [[NSString alloc] initWithFormat:@"/service/download.php?email=%@&FileName= test1.jpg",@"<你的iosbook1.com用户邮箱>"];
 MKNetworkEngine *engine = [[MKNetworkEngine alloc] initWithHostName:@"iosbook1.com" customHeaderFields:nil];
 MKNetworkOperation *downloadOperation = [engine operationWithPath:path params:nil httpMethod:@"POST"];
 [downloadOperation addDownloadStream:[NSOutputStream outputStreamToFileAtPath:downloadPath append:YES]]; 2
 [downloadOperation onDownloadProgressChanged:^(double progress) { 3 NSLog(@"download progress: %.2f", progress*100.0); 4
 _progressView.progress = progress;
 }];
 [downloadOperation addCompletionHandler:^(MKNetworkOperation *operation) {
 NSLog(@"download file finished!");
 NSData *data = [operation responseData];
 if (data) { 5 //返回数据失败
 NSError *eror;
 NSDictionary *resDict = [NSJSONSerialization JSONObjectWithData:data
 options:NSJSONReadingAllowFragments error:&eror];
 if (!resDict) {
 NSNumber *resultCodeObj = [resDict objectForKey:@"ResultCode"];
 NSString *errorStr = [resultCodeObj errorMessage];
 UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"错误信息"
 } else { 6 //返回数据成功
 UIImage *img = [UIImage imageWithContentsOfFile:downloadPath]; 7
 _imageView1.image = img;
 }
 } errorHandler:^(MKNetworkOperation *errorOp, NSError* err) {
 NSLog(@"MKNetwork请求错误 : %@", [err localizedDescription]); }];
 [engine enqueueOperation:downloadOperation];
 }
 */

#endif
