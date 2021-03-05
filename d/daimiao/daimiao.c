
#include <room.h>
inherit ROOM;
void create()
{
  set("short","岱庙坊");
  set("long",@LONG
遥参亭与岱庙之间是岱庙坊，又名玲珑坊。坊顶是歇山式仿木结构，螭吻凌空，
斗拱层叠，檐角飞翘，脊兽欲驰。正脊之中竖立着宝瓶，两侧有四大金刚拽引加固。
中柱小额枋上透雕着二龙戏珠，龙门枋上浮雕着丹凤朝阳。坊下奠立方形石座，座
上均竖立双柱，柱下侧是滚墩石，石上前后有立雕蹲狮两对：雄者戏耍绣球，雌者
嬉闹幼狮，姿态各异，生动可爱。
LONG
  );
  	set("exits",([
        	"north":__DIR__"zhengyan.c",
         	"south":__DIR__"yaocan.c",
         	"northwest": __DIR__"w_yemen",
         	"northeast": __DIR__"e_yemen",
        ]));
        set("objects", ([
        
       	]) );

	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
  
}
