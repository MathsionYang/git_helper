# git_helper
git使用指南
# 1.使用ssh
## （1）打开 git 命令窗口
## （2）配置用户名（填自己的姓名）
git config --global user.name “姓名”
## （3）配置用户邮箱（填自己的邮箱）
git config --global user.email “linjiaxiaozhu@qq.com.cn”
## （4）生成公钥、秘钥（填自己的邮箱，执行后需要按几次 enter 直到结束）
ssh-keygen -t rsa -C “github邮箱”
## （5）配置 ssh 变量
git config --global ssh.variant ssh
# 1-1 gitlab 配置公钥
## （1）打开生成公钥的文件夹
windows:C:\Users%username%.ssh比如我的文件地址是 C:\Users\admin.ssh
## （2）复制公钥文件内容，公钥文件名
id_rsa.pub


# 2.如何上传代码到github 仓库
## 初始化本地仓库 
git init 
## 关联 远端仓库 
git remote add origin "地址"
## 拉取远程代码
git pull origin "分支"
## 更新信息
gir commit -m "上传信息"
## 开始上传
git push -u origin "分支"
 
## 强制拉取 覆盖本地

```git
git fetch --all
git reset --hard master
git pull
```

## 放弃此次合并

```git
git merge --abort
```

## 已经被纳入了版本管理 修改.gitignore无效

```git
git rm -r --cached .
git add .
git commit -m '更新 .gitignore'
```

## 同步github仓库 更新到最新的库（与github上的远程库同步）

```git
git fetch --all
git reset --hard origin/master
```
git rm -r --cached .
git add .
git commit -m '更新 .gitignore'

