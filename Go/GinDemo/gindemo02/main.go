package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

type Article struct {
	Title   string `json:"title"`
	Desc    string `json:"desc"`
	Content string `json:"content"`
}

func main() {
	r := gin.Default()
	r.LoadHTMLGlob("templates/*")

	//返回字符串
	r.GET("/", func(c *gin.Context) {
		c.String(200, "值:%v", "首页")
	})

	//返回json数据
	r.GET("/json1", func(c *gin.Context) {
		c.JSON(200, map[string]interface{}{
			"success": true,
			"msg":     "你好gin",
		})
	})

	r.GET("/json2", func(c *gin.Context) {
		c.JSON(200, gin.H{
			"success": true,
			"msg":     "你好gin-2",
		})
	})

	r.GET("/json3", func(c *gin.Context) {
		a := &Article{
			Title:   "我是一个标题",
			Desc:    "描述",
			Content: "内容",
		}
		c.JSON(200, a)
	})

	//响应jsonp请求
	//http://localhost:8080/jsonp?callback=xxxx
	//xxxx({"title":"我是一个标题-jsonp",...})
	r.GET("/jsonp", func(c *gin.Context) {
		a := &Article{
			Title:   "我是一个标题-jsonp",
			Desc:    "描述",
			Content: "内容",
		}
		c.JSONP(200, a)
	})

	//返回xml数据
	r.GET("/xml", func(c *gin.Context) {
		c.XML(http.StatusOK, gin.H{
			"success": true,
			"msg":     "你好gin,我是一个xml",
		})
	})

	//返回html数据
	r.GET("/news", func(c *gin.Context) {
		c.HTML(http.StatusOK, "news.html", gin.H{
			"title": "我是后台数据",
		})
	})

	r.Run()
}
