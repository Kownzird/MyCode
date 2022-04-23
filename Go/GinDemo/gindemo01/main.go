package main

import (
	"github.com/gin-gonic/gin"
)

func main() {
	//创建一个默认的路由环境
	r := gin.Default()

	//配置路由
	r.GET("/", func(c *gin.Context) {
		c.String(200, "值：%v", "你好gin")
	})

	r.GET("/news", func(c *gin.Context) {
		c.JSON(200, gin.H{
			"message": "我是新闻页面",
		})
	})

	r.POST("/add", func(c *gin.Context) {
		c.String(200, "这是一个POST请求,主要用于增加数据")
	})

	r.PUT("/edit", func(c *gin.Context) {
		c.String(200, "这是一个PUT请求,主要用于编辑数据")
	})

	r.DELETE("/delete", func(c *gin.Context) {
		c.String(200, "这是一个DELETE请求,主要用于删除数据")
	})

	//路由里获取Get传值
	//域名/news?aid=20
	r.GET("/get", func(c *gin.Context) {
		aid := c.Query("aid")
		c.String(200, "aid=%s", aid)
	})

	//动态路由
	//域名/user/20
	r.GET("/user/:uid", func(c *gin.Context) {
		uid := c.Param("uid")
		c.String(200, "uid=%s", uid)
	})

	//启动HTTP服务，默认在0.0.0.0:8080启动服务
	r.Run(":8000")

}
