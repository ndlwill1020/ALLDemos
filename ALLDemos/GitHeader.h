//
//  GitHeader.h
//  ALLDemos
//
//  Created by macuser on 15/9/2.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_GitHeader_h
#define ALLDemos_GitHeader_h

/*
 SSH采用公􏶵认􏴞,通过ssh-keygen命令生成,在􏱰前用户主目录下的.ssh目录下面生成两个􏶾􏶵文件。 􏰝 id_rsa。􏶾􏶵文件,基于RSA􏲡法创建,该􏶾􏶵文件要妥􏶿􏰟管,􏰛􏵧􏰟存到􏴦户􏶩中。
 􏰝 id_rsa.pub。公􏶵文件,与上面的􏶾􏶵文件是一对,该文件可以公开,放置于服务器􏶩。
 
 $ git help <命令>
 
 $ git log
 
 $ mkdir myrepo
 $ cd myrepo
 $ git init
 
 $ git add .
 可以将􏱰前工作目录和子目录下所有新添加和修改的文件添加到索引中。如果􏱼􏳐将􏳓个文件添加到索引 中,可以使用如下命令:
 $ git add filename 􏷥 $ git add *.txt 这里可以指定文件􏰻,也可以使用通配􏰷指定文件􏰻。
 
 $ git rm filename 􏷥 $ git rm *.txt
 
 $ git commit -m 'tony commit'
 
 该命令可以显示􏱰前git的􏵪态,包括􏲍些文件修改、删除和添加了,􏱴是没有提交的信息。在终􏶩中􏲲行 命令:
 $ git status
 
 
 ／／＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
 1. 􏸀􏶥􏴚支
 创建分􏱥时,使用命令git branch <分􏱥􏰻>。如果我们要创建一个testing分􏱥,可以在终􏶩中􏲲行如下 命令:
 $ git branch testing
 创建完成后,我们需要查看一下分􏱥情况,此时可以在终􏶩中􏲲行如下命令:
 $ git branch
 * master
 testing 其中*􏲜的分􏱥是􏱰前分􏱥,master是git􏳊认创建的分􏱥,testing是我们􏸁􏸁创建的分􏱥。
 
 2. 􏸂􏸃􏴚支
 $ git checkout testing
 
 3. 􏴂􏴺􏴚支
 $ git checkout master
 $ git merge testing
 
 $ git checkout HelloWorld.xcodeproj
 这里使用了git checkout命令放弃修改,在前面􏸄换分􏱥时我们也使用了该命令。
 
 - (void)viewDidLoad
 {
 [super viewDidLoad];
 <<<<<<< HEAD
 NSLog(@"Hello World.");
 =======
 NSLog(@"􏸅界你􏸆."); >>>>>>> testing
 }
 而viewDidLoad方法中<<<<<<< HEAD ... >>>>>>>表示其中的内容有􏲷 􏶗。由于Git无法判断􏳾对􏳾􏷎,所以需要人工解决。解决完成􏰼次添加并提交,在终􏶩中􏲲行如下命令:
 $ git commit -a -m 'testing branch merge commit'
 [master 60eac40] testing branch merge commit
 其中git commit -a –m相􏱰于git add .和git commit –m的􏲲行􏱩果。
 4. 􏲥􏲦􏴚支
 在分􏱥合并完成且不􏰼使用的情况下,可以使用git branch -d删除分􏱥。要删除testing分􏱥,可以在终􏶩 中􏲲行如下命令:
 $ git branch -d testing
 
 
 
 ／／／／／／／／／／／
 然后将本地代码库􏲴送到􏶪程服务器,此时可以使用命令git remote add和git push,具体如下所示:
 $ git remote add HW git@192.168.1.107:myrepo
 $ git push HW master
 
 而是从服务器上􏷛􏷜过来,此时可以在终􏶩中􏲲 行如下命令:
 $ git clone git@192.168.1.107:myrepo
 
 开发者1􏰼次􏵧告知􏱪们程序有新的版本,􏱪需要从服务器代码库中􏴳取新的程序。使用git fetch命令, 可以从服务器代码库􏴳取数据,相关命令如下:
 $ git fetch HW
 这时􏸎开修改的文件,发现没有变化,这是因为还需要使用git merge命令合并HW/master到本地master分􏱥,
 相关代码如下:
 $ git merge HW/master
 
 􏰼看看修改的文件是否发生了变化。合并过程中也可能发生􏲷􏶗,需要人为解决这些􏲷􏶗􏰼合并,这可以通 过Git提供的更加简􏰒的命令git pull来实现。git pull命令是git fetch和git merge命令的一个组合,相 关代码如下:
 $ git pull HW master
 
 
 
 其中HelloWorld.xcodeproj属于包文件,􏰛内部的很多东􏸔是不能提交的,包括project.xcworkspace和
 xcuserdata,􏰛们是与用户有关的。在Git中,有一个.gitignore配置文件,其中可以设置􏵧􏸕略的文件。下面是一 个.gitignore配置文件的内容:
 # Exclude the build directory
 build/*
 # Exclude temp nibs and swap files
 *~.nib
 *.swp
 # Exclude OS X folder attributes
 .DS_Store
 # Exclude user-specific XCode 3 and 5 files
 *.mode1
 *.mode1v3
 *.mode2v3
 *.perspective
 *.perspectivev3
 *.pbxuser
 *.xcworkspace
 xcuserdata
 在这个文件中,#􏲜表示注􏴉,可以使用正􏲒表􏱨式
 
 如果考􏱵适用于所有的Xcode工程,􏲒需要使用git config命令配置Git,具体代码如下: $ git config –global core.excludesfile ~/.gitignore
 该命令会将配置信息写入到~/.gitconfig文件中,–global参数是配置全局信息,~/.gitignore说明文件放置于􏱰 前用户目录下。
 
 
 ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
 使用GitHub协同开发有两种模式:一种是􏰑较􏵬􏱻的,代码库与开发者之间是一对多的关系模式;另一种是 代码库与开发者之间是多对多的关系。
 */


#endif
