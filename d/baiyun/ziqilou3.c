//Created by justdoit at May 2001 
//All Rights Reserved ^_^

inherit ROOM;
void create()
{
        set("short", "紫气东来楼");
        set("long", @LONG
此间是白云城招待贵宾的楼宇，一栋三明两暗的花轩，朱栏回廊，建筑得极华美
精致。楼内雕梁画栋，金壁辉煌，但凡贵宾至此，无不心醉其间，远在千里外的紫禁
城大概也不过如此。而楼内摆设的奇珍异宝，海外诸国的古玩佳肴更是琳琅满目。
LONG
           );
        set("exits", 
           ([ 
       "west" : __DIR__"skystreet",
	    ]));
	set("objects", 
	   ([ 
       __DIR__"npc/yexingshi" : 1,
	    ]));
        set("indoors", "baiyun");
	set("coor/x",0);
	set("coor/y",-1030);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
