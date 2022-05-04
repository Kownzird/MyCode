package main

import (
	"fmt"
	"gindemo06/routers"
	"html/template"
	"time"

	"github.com/gin-gonic/gin"
)

type Article struct {
	Title   string
	Content string
}

// 时间戳转换为日期
func UnixToTime(timestamp int) string {
	fmt.Println(timestamp)
	t := time.Unix(int64(timestamp), 0)
	return t.Format("2006-01-02 15:04:05")
}

func main() {
	r := gin.Default()

	r.SetFuncMap(template.FuncMap{
		"UnixToTime": UnixToTime,
	})

	r.LoadHTMLGlob("templates/**/*")

	r.Static("/static", "./static")

	//路由分组
	routers.DefaultRoutersInit(r)
	routers.ApiRoutersInit(r)
	routers.AdminRoutersInit(r)

	r.Run()
}
