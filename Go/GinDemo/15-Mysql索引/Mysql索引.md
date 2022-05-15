## Mysql索引

### 1.查询表索引

```mysql
show index from table_name \G
```



### 2.创建索引

```mysql
create index index_name on table_name(name)
create unique index index_name on table_name(name)
```

```mysql
alter table table_name add index index_name(name)
alter table table_name add unique index_name(name)
```





### 3.删除索引

```mysql
drop index index_name on table_name
```

```mysql
alter table table_name drop index index_name
```

