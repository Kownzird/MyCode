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

//中间件
func initMiddleware(c *gin.Context) {
	start := time.Now().UnixNano()
	fmt.Println("1-我是一个中间件")

	//调用该请求的剩余处理程序
	// c.Next()
	c.Abort() //不会执行处理函数

	fmt.Println("2-我是一个中间件")
	end := time.Now().UnixNano()
	fmt.Println(end - start)
}

func initMiddlewareOne(c *gin.Context) {
	fmt.Println("1-我是一个中间件-initMiddlewareOne")
	c.Next()
	fmt.Println("2-我是一个中间件-initMiddlewareOne")
}

func initMiddlewareTwo(c *gin.Context) {
	fmt.Println("1-我是一个中间件-initMiddlewareTwo")
	c.Next()
	fmt.Println("2-我是一个中间件-initMiddlewareTwo")
}

func main() {
	r := gin.Default()

	r.SetFuncMap(template.FuncMap{
		"UnixToTime": UnixToTime,
	})

	r.LoadHTMLGlob("templates/**/*")

	r.Static("/static", "./static")

	//全局中间件
	r.Use(initMiddlewareOne, initMiddlewareTwo)

	r.GET("/", initMiddlewareOne, initMiddlewareTwo, func(c *gin.Context) {
		fmt.Println("我是首页")
		time.Sleep(time.Second)
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
