inherit ROOM;
void create()
{
 set("short", "海边");
 set("long", @LONG
东边是一望无际的大海，海上翻腾着白色的浪花，一群群的海鸥在空中盘旋着，
时而不时地俯冲向海面，在浪涛中掠食。离海边不远的浪涛中停泊着一艘高桅大帆
船。这是一条巨大的海船，坚固、轻捷、光滑、华丽、甲板上也洗刷得一尘不染，
就像是面镜子，映出了天光。
LONG);
 	set("outdoors", "bat");
  	set("exits", ([ 
  		"south" : __DIR__"fchuan",
  	]));
 	set("objects", ([
  		AREA_BAT"npc/dingfeng": 1,
 	]) );
 	set("item_desc", ([
 	"boat": @TEXT
这是一条巨大的海船，坚固、轻捷、光滑、华丽、甲板上也洗刷得一尘不染，就像
是面镜子，映出了天光。好船就正和美人与名马一样，就算停泊在那里不动，也自
有一种动人的风姿神采，令人不饮自醉。 
TEXT
        ]) );
	set("coor/x",1020);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
