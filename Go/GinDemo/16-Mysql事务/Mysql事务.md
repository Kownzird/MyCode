## Mysql 事务和锁

### 1.事务

事务的处理可以维护数据库的完整性，要么成批的执行Mysql语句，要么全不执行

格式：

```mysql
begin; #开启一个事务
update users set balance=balance-100 where id=1;
update users set balance=balance+100 where id=2;
commit; #事务确认
```

在提交之前表格内容的改变只发生在内存当中，一旦遇到异常情况，可执行回滚操作

```mysql
rollback; #事务回滚
```



### 2.锁

分类：**表级锁**和**行级锁**

#### 2.1 添加读锁

可以并发读，不能并发写，读锁期间，没有放锁之前不能进行写操作

```mysql
lock table table_name read;
unlock tables;
```



#### 2.2 添加写锁

只有锁表的用户可以读写操作，其他用户不行

```mysql
lock table table_name write;
unlock tables;
```



