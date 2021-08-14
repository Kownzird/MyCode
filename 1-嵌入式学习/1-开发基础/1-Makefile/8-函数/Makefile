name := a b c d
print:
	
#$(subst <from>,<to>,<text>)
	@echo $(subst zhe.gao,ZHE.GAO,my name is zhe.gao)

#$(patsubst <pattern>,<replacement>,<text>)
	@echo $(patsubst %.c,%.o,a.c b.c c.c)

#$(dir <names…>)
	@echo $(dir <Makefile>)

#$(foreach <var>, <list>,<text>)
	
	@echo $(foreach n,$(name),$(n).o)

#$(wildcard PATTERN…)
#$(wildcard *.c)用来获取当前目录下所有的.c 文件，类似“%”。
	@echo $(patsubst %.c,%.o,$(wildcard *.c))