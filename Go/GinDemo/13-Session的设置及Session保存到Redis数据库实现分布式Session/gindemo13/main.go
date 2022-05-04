package main

import (
	"gindemo13/models"
	"gindemo13/routers"
	"html/template"

	"github.com/gin-contrib/sessions"
	"github.com/gin-contrib/sessions/redis"
	"github.com/gin-gonic/gin"
)

type Article struct {
	Title   string
	Content string
}

func main() {
	r := gin.Default()

	r.SetFuncMap(template.FuncMap{
		"UnixToTime": models.UnixToTime,
	})

	r.LoadHTMLGlob("templates/**/*")

	r.Static("/static", "./static")

	//配置session中间件
	store, _ := redis.NewStore(10, "tcp", "localhost:6379", "123456", []byte("secret111"))
	r.Use(sessions.Sessions("mysession", store))

	//路由分组
	routers.DefaultRoutersInit(r)
	routers.ApiRoutersInit(r)
	routers.AdminRoutersInit(r)

	r.Run()
}
