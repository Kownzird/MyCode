package admin

import (
	"fmt"
	"gindemo11/models"
	"net/http"
	"os"
	"path"
	"strconv"

	"github.com/gin-gonic/gin"
)

type UserController struct {
	//继承控制器
	BaseController
}

func (con UserController) Index(c *gin.Context) {
	// c.String(200, "用户列表--")
	con.Success(c)
}

func (con UserController) Add(c *gin.Context) {
	c.HTML(200, "admin/useradd.html", gin.H{})
}

func (con UserController) Edit(c *gin.Context) {
	c.HTML(200, "admin/useredit.html", gin.H{})
}

func (conn UserController) Edit2(c *gin.Context) {
	c.HTML(200, "admin/useredit2.html", gin.H{})
}

//按日期存储图片
func (con UserController) DoUpload(c *gin.Context) {
	username := c.PostForm("username")

	//1、获取上传的文件
	file, err := c.FormFile("face")

	if err == nil {
		//2、获取后缀名，判断类型是否正确 .jpg .png .gif .jpeg
		extName := path.Ext(file.Filename)

		allowExtName := map[string]bool{
			".jpg":  true,
			".png":  true,
			".gif":  true,
			".jpeg": true,
		}

		if _, ok := allowExtName[extName]; !ok {
			c.String(200, "上传文件类型不合法")
			return
		}

		//3、创建图片保存目录 static/upload/20220503
		day := models.GetDay()
		dir := "./static/upload/" + day
		err := os.MkdirAll(dir, 0666)
		if err != nil {
			fmt.Println(err)
			c.String(200, "MkdirAll失败")
			return
		}

		//4、生成图片名称和文件保存目录
		fileName := strconv.FormatInt(models.GetUnix(), 10) + extName

		//5、执行上传
		dst := path.Join(dir, fileName) //path的Join方法会添加'/'
		c.SaveUploadedFile(file, dst)
	}
	// c.String(200, "执行上传")
	c.JSON(http.StatusOK, gin.H{
		"success":  true,
		"username": username,
	})
}

func (conn UserController) DoEdit(c *gin.Context) {
	username := c.PostForm("username")

	face1, err1 := c.FormFile("face1")
	dst1 := path.Join("./static/upload", face1.Filename)
	if err1 == nil {
		c.SaveUploadedFile(face1, dst1)
	}

	face2, err2 := c.FormFile("face2")
	dst2 := path.Join("./static/upload", face2.Filename)
	if err2 == nil {
		c.SaveUploadedFile(face2, dst2)
	}

	c.JSON(http.StatusOK, gin.H{
		"success":  true,
		"username": username,
		"dst1":     dst1,
		"dst2":     dst2,
	})
}

func (conn UserController) DoEdit2(c *gin.Context) {
	username := c.PostForm("username")

	form, _ := c.MultipartForm()
	files := form.File["face[]"]

	for _, file := range files {
		dst := path.Join("./static/upload", file.Filename)
		c.SaveUploadedFile(file, dst)
	}

	c.JSON(http.StatusOK, gin.H{
		"success":  true,
		"username": username,
	})
}
