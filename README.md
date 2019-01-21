# JavaTest5
首先`git clone`本项目
```shell
git clone https://github.com/toonine/JavaTest5.git
```

然后在`Exam1`根目录依次执行命令
```shell
./build.sh
./start.sh
./curl.sh
./stop.sh
```

**注意**: 在执行完`start.sh`之后，可以立即执行`curl.sh`，但需要等待近20s的时间才会返回结果, 而且脚本执行curl去ping端口所以会有curl的报错信息显示

#### 2018-08-14 更新

[FIX] 修改内置容器undertow（漏做了）
[FIX] 将数据库的账号和密码使用spring默认设置