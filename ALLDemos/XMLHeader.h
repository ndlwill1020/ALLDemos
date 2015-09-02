//
//  XMLHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/25.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_XMLHeader_h
#define ALLDemos_XMLHeader_h
/*
 声明。在图14-3中,<?xml version="1.0" encoding="UTF-8"?>就是XML文件的声明,它定义了XML 文件的版本和使用的字符集,这里为1.0版,使用中文UTF-8字符。
  根元素。在图14-3中,note是XML文件的根元素,<note>是根元素的开始标签,</note>是根元素的结 束标签。根元素只有一个,开始标签和结束标签必须一致。
  子元素。在图14-3中,to、content、from和date是根元素note的子元素。所有元素都要有结束标签, 开始标签和结束标签必须一致。如果开始标签和结束标签之间没有内容,可以写成<from/>,这称为“空 标签”。
 属性。图14-4是具有属性的XML文档,而留言条的XML文档中没有属性。它定义在开始标签中。在开始 标签<Note id="1">中,id="1"是Note元素的一个属性,id是属性名,1是属性值,其中属性值必须放 置在双引号或单引号之间。一个元素不能有多个相同名字的属性。
  命名空间。用于为XML文档提供名字唯一的元素和属性。例如,在一个学籍信息的XML文档中,需要引 用到教师和学生,他们都有一个子元素id,这时直接引用id元素会造成名称冲突,但是如果将两个id元 素放到不同的命名空间中就会解决这个问题。图14-5中以xmlns:开头的内容都属于命名空间。
  限定名。它是由命名空间引出的概念,定义了元素和属性的合法标识符。限定名通常在XML文档中用作 特定元素或属性引用。图14-5中的标签<soap:Body>就是合法的限定名,前缀soap是由命名空间定义的。
 
 解析XML文档时,目前有两种流行的模式:SAX和DOM。SAX是一种基于事件驱动的解析模式。解析XML 文档时,程序从上到下读取XML文档,如果遇到开始标签、结束标签和属性等,就会触发相应的事件。但是这种 解析XML文件的方式有一个弊端,那就是只能读取XML文档,不能写入XML文档,它的优点是解析速度快。iOS 重点推荐使用SAX模式解析。
 DOM模式将XML文档作为一棵树状结构进行分析,获取节点的内容以及相关属性,或是新增、删除和修改 节点的内容。XML解析器在加载XML文件以后,DOM模式将XML文件的元素视为一个树状结构的节点,一次性 读入到内存中。如果文档比较大,解析速度就会变慢。但是在DOM模式中,有一点是SAX无法取代的,那就是 DOM能够修改XML文档。
 
 NSXML
 parserDidStartDocument:。在文档开始的时候触发。
  parser:didStartElement:namespaceURI:qualifiedName:attributes:。遇到一个开始标签时触发,
 其中namespaceURI部分是命名空间,qualifiedName是限定名,attributes是字典类型的属性集合。
  parser:foundCharacters:。遇到字符串时触发。
  parser:didEndElement:namespaceURI:qualifiedName:。遇到结束标签时触发。
  parserDidEndDocument:。在文档结束时触发。
 
 -(void)start
 {
 NSString* path = [[NSBundle mainBundle] pathForResource:@"Notes" ofType:@"xml"];
 NSURL *url = [NSURL fileURLWithPath:path];
 //开始解析XML
 NSXMLParser *parser = [[NSXMLParser alloc] initWithContentsOfURL:url]; parser.delegate = self;
 [parser parse];
 }
 */

#endif
