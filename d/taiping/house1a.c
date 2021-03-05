// seaside.c
inherit ROOM;
void create()
{
        set("short", "内宅");
        set("long", @LONG
虽然外面看上去很气派，西宅里面已经是很破旧了，墙上东一块西一块的裂缝，
像老人脸上的皱纹，怎么也遮不住岁月的痕迹。家具虽然质地一流，棱角处都磨得
看不出原来的颜色，唯一像样的只有西角六尺宽的大床，屋内有两个大汉一蹲一坐，
正用怀疑的眼光打量着你。
LONG
        );
        set("exits", ([ 
		"down":  __DIR__"house1",
	]));
        set("objects", ([
        	__DIR__"npc/tan2" : 1,
        	__DIR__"npc/tan3" : 1,
        ]) );
        set("item_desc", ([
	
	 ]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",10);
	set("map","taiping");
	setup();
}
