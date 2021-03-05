#include <room.h>
inherit ROOM;

void create()
{
  set("short","汉柏亭");
  set("long",@LONG
院北是炳灵殿旧址，现建汉柏亭。亭四周镶嵌着历代名碑，较著名的有西晋文
学家陆机和南朝宋诗人谢灵运所赋《泰山吟》。第二层台基上还有清乾隆四十九年
泰安知府何人麟草书杜甫诗《秋兴八首》。其余均为乾隆诗碑及竹兰图和颂岱诗等，
多残缺不全。
LONG
  );
  	set("exits",([
        	 "north":__DIR__"chuihua",
         	"south":  __DIR__"hanbai",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-35);
	set("coor/z",0);
	setup();
  	
}
