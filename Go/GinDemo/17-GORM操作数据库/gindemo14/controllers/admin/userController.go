package admin

import (
	"fmt"
	"gindemo14/models"
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

	//查询数据库
	// userList := []models.User{}
	// models.DB.Find(&userList)

	//查询age大于20的用户
	userList := []models.User{}
	// models.DB.Where("age>20").Find(&userList)
	models.DB.Where("age > ?", 20).Find(&userList)

	c.JSON(http.StatusOK, gin.H{
		"result": userList,
	})
}

func (con UserController) Add(c *gin.Context) {

	//添加数据库数据
	user := models.User{
		Username: "zhe.gao2",
		Age:      24,
		Email:    "zhe.gao2@gmail.com",
		AddTime:  int(models.GetUnix()),
	}
	models.DB.Create(&user)

	fmt.Println(user)
	c.String(200, "增加数据成功")
}

func (con UserController) Edit(c *gin.Context) {
	//保存所有的字段
	// //查询id=5的数据
	// user := models.User{Id: 5}
	// models.DB.Find(&user)
	// //更新数据
	// user.Username = "Kownzird"
	// user.AddTime = int(models.GetUnix())
	// models.DB.Save(&user)

	//更新单个列
	// user := models.User{}
	// models.DB.Model(&user).Where("id = ?", 5).Update("username", "zhe.gao")
	user := models.User{}
	models.DB.Where("id = 5").Find(&user)
	user.Username = "zhe.gao"
	user.Email = "zhe.gao@gmail.com"
	models.DB.Save(&user)

	c.String(200, "修改用户成功")
}

func (conn UserController) Delete(c *gin.Context) {

	//删除数据
	// user := models.User{Id: 6}
	// models.DB.Delete(&user)

	user := models.User{}
	models.DB.Where("id = ?", 6).Delete(&user)

	c.String(200, "删除用户成功")
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
