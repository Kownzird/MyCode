package main

import (
	"fmt"
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

func initMiddleware(c *gin.Context) {
	fmt.Println("aaa")
}

func main() {
	r := gin.Default()

	r.SetFuncMap(template.FuncMap{
		"UnixToTime": UnixToTime,
	})

	r.LoadHTMLGlob("templates/**/*")

	r.Static("/static", "./static")

	r.GET("/", initMiddleware, func(c *gin.Context) {
		c.String(200, "首页")
	})

	r.GET("/login", initMiddleware, func(c *gin.Context) {
		c.String(200, "login")
	})

	r.GET("/news", initMiddleware, func(c *gin.Context) {
		c.String(200, "新闻首页")
	})

	r.Run()
}
